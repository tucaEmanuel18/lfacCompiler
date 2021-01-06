%{
#include <stdio.h>
#include <string.h>
#include "symbolTable.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern void yyerror();
extern int yylex();

extern char DataType[50];
extern char AuxBuffer[50];
extern char Scope[50];
void printList();
extern void storeDataType(char* data_type);
#define StringValue(nrArg){\
			if(strcmp(nrArg.type, "int") == 0)\
			{\
				intToString(nrArg.intVal);\
			}\
			else if (strcmp(nrArg.type, "float") == 0)\
			{\
				floatToString(nrArg.floatVal);\
			}\
			else if (strcmp(nrArg.type, "bool") == 0)\
			{\
				intToString(nrArg.intVal);\
			}\
			else if (strcmp(nrArg.type, "char") == 0)\
			{\
				charToString(nrArg.charVal);\
			}\
			else if (strcmp(nrArg.type, "string") == 0)\
			{\
				bzero(AuxBuffer, 50);\
				strcpy(AuxBuffer, nrArg.strVal);\
			}\
		}

 struct expressionInfo{
	    char *type;

	    int intVal;
	    float floatVal;
	    char charVal;
	    char *strVal;
  }varInfo, parameterList[10];
int parameterListCounter = 0;


struct parameter FunctionParameters[5];
int nrOfFunctionParameters = 0;

//
char arrayValueType[10];
char arrayValues[20][20];
int arrayValuesCounter = 0;
bool firstArrayType = true;


//eval
char evalInfo[20][20];
int evalCounter = 0;

%}

%union {
  char* dataType;
  int intVal;
  char* strVal;
  float floatVal;
  char charVal;
  struct expressionI
  {char *type;

    int intVal;
    float floatVal;
    char charVal;
    char *strVal;
	}info;



   
}

%token <dataType> DATA_TYPE
%token <strVal> USR_DATA_TYPE

%token <strVal> STRING_VALUE 
%token <charVal> CHARACTER_VALUE 
%token <intVal> INTEGER_VALUE 
%token <floatVal> FLOAT_VALUE 
%token <intVal> BOOL_VALUE
%token <strVal> IDENTIFIER
%token <dataType> VOID
%token IF FOR WHILE ELSE EVAL
%token <dataType> PRINT
%token ASSIGN  RELATIONAL_OPERATOR BOOL_OPERATOR ARITHMETIC_OPERATOR
%token VAR_TABLE ARRAY_TABLE FUNCTION_TABLE 
%token <strVal> ARRAY_ID 
%token <strVal> ARRAY_PARAM_ID
%token CONST  


%type<intVal> EVAL_EXP;
%type<infoArray> LIST_OF_VALUES;
%type<info> VALUE ;
%type<info> BLOCK_EXPRESSION;
%type<info> FUNCTION_CALL;
%start CODE
%left '+' 
%left '-' 
%left '*'
%left '/'
%left '%'
%left RELATIONAL_OPERATOR 
%left BOOL_OPERATOR 
%left ARITHMETIC_OPERATOR
%%
CODE : DECLARATIONS BLOCK {printf("program corect sintactic\n");
							
								for(int i = 0; i < evalCounter; i++)
									printf("eval %d : valoarea expresiei : %s\n", i, evalInfo[i]);
							}
     ;
DECLARATIONS : DECLARATION ';'				
            | DECLARATIONS  DECLARATION ';'
            ;

DECLARATION : EXPRESSION
            ;

EXPRESSION : DATA_TYPE  IDENTIFIER { 
									if(!lookupVar($2))
									{
										insertVar($1, $2, "\0", Scope, false, false); 
									}
									else
									{
										DuplicateIdentifierError($2);
									}
								}
		  |  DATA_TYPE IDENTIFIER ASSIGN VALUE { 
		  											if(!lookupVar($2))
		  											{
		  												if(strcmp($1, $4.type) == 0)
		  												{
			  												StringValue($4);
				  											insertVar($1, $2, AuxBuffer, Scope, true, false);
		  												}
		  												else
		  												{
		  													AssignementError($2, $1, $4.type);
		  												}
												
			  										}
			  										else
			  										{
			  											DuplicateIdentifierError($2);
			  										}
					  								
		  										}
          | CONST DATA_TYPE IDENTIFIER ASSIGN VALUE {
          													if(!lookupVar($3))
				  											{
				  												if(strcmp($2, $5.type) == 0)
				  												{
					  												StringValue($5);
						  											insertVar($2, $3, AuxBuffer, Scope, true, true);
				  												}
				  												else
				  												{
				  													AssignementError($3, $2, $5.type);
				  												}
														
					  										}
					  										else
					  										{
					  											DuplicateIdentifierError($3);
					  										}

          											}
          |  DATA_TYPE ARRAY_ID {

          							char name[50];
          							strcpy(name, extractName($2));
          							if(!lookupArray(name))
          							{
          								int maxSize =extractMaxSize($2);
          								insertArray($1, name, maxSize, 0, arrayValues, Scope, false);
          							}
          							else
          							{
          								DuplicateIdentifierError($2);
          							}
          						}
          |  DATA_TYPE ARRAY_ID ASSIGN '{' LIST_OF_VALUES '}' {
          															if(!lookupArray($2))
								          							{
								          								if(strcmp(arrayValueType, $1) == 0)
								          								{
									          								char name[50];
									          								strcpy(name, extractName($2));

									          								int maxSize =extractMaxSize($2);
									          								insertArray($1, name, maxSize, arrayValuesCounter, arrayValues, Scope, false);

									          								// curatare structuri de date alterate
									          								for(int i = 0; i < arrayValuesCounter; i++)
									          								{
									          									bzero(arrayValues[i], 20);
									          								}
									          								bzero(arrayValueType, 10);
									          								arrayValuesCounter = 0;
																			firstArrayType = true;

								          								}
								          								else
								          								{
								          									AssignementError($2, $1, arrayValueType);
								          								}
								          							}
								          							else
								          							{
								          								DuplicateIdentifierError($2);
								          							}		
          													  }

          | USR_DATA_TYPE IDENTIFIER '{' DECLARATIONS '}'
          | IDENTIFIER IDENTIFIER                                                         {/*conditie: primul identifier sa fie de tip caps*/}
          | IDENTIFIER IDENTIFIER ASSIGN '{' LIST_OF_VALUES '}'                           {/*conditie: primul identifier sa fie de tip caps*/}
          | DATA_TYPE IDENTIFIER '(' LIST_OF_PARAMETERS ')'{

          													 if(!lookupFunction($2, true))
          													 {

          													 	insertFunction($1, $2, nrOfFunctionParameters, FunctionParameters, Scope, true);

          													 	//curatam structurile de date alterate
          													 	for(int i = 0; i < 5; i++)
          													 	{
          													 		bzero(FunctionParameters[i].type, 10);
          													 		bzero(FunctionParameters[i].identifier, 10);
          													 	}
          													 	nrOfFunctionParameters = 0;
          													 }
          													 else
          													 {
          													 	DuplicateIdentifierError($2);
          													 }
          												   }
           | DATA_TYPE IDENTIFIER '(' ')' {

											 if(!lookupFunction($2, true))
											 {

											 	insertFunction($1, $2, nrOfFunctionParameters, FunctionParameters, Scope, true);

											 	//curatam structurile de date alterate
											 	for(int i = 0; i < 5; i++)
											 	{
											 		bzero(FunctionParameters[i].type, 10);
											 		bzero(FunctionParameters[i].identifier, 10);
											 	}
											 	nrOfFunctionParameters = 0;
											 }
											 else
											 {
											 	DuplicateIdentifierError($2);
											 }
		  								 }

          | DATA_TYPE IDENTIFIER '(' LIST_OF_PARAMETERS ')' '{' CODE_FUNCTION '}' 	{
	      																				if(!lookupFunction($2, false))
							          													 {


							          													 	insertFunction($1, $2, nrOfFunctionParameters, FunctionParameters, Scope, false);
							          													 	//curatam structurile de date alterate
							          													 	for(int i = 0; i < 5; i++)
							          													 	{
							          													 		bzero(FunctionParameters[i].type, 10);
							          													 		bzero(FunctionParameters[i].identifier, 10);
							          													 	}
							          													 	nrOfFunctionParameters = 0;
							          													 }
							          													 else
							          													 {
							          													 	DuplicateIdentifierError($2);
							          													 }
								          												}
		  | DATA_TYPE IDENTIFIER '(' ')' '{' CODE_FUNCTION '}' {
		  															if(!lookupFunction($2, false))
		          													 {


		          													 	insertFunction($1, $2, nrOfFunctionParameters, FunctionParameters, Scope, false);
		          													 	//curatam structurile de date alterate
		          													 	for(int i = 0; i < 5; i++)
		          													 	{
		          													 		bzero(FunctionParameters[i].type, 10);
		          													 		bzero(FunctionParameters[i].identifier, 10);
		          													 	}
		          													 	nrOfFunctionParameters = 0;
		          													 }
		          													 else
		          													 {
		          													 	DuplicateIdentifierError($2);
		          													 }
		  														}
          | VOID IDENTIFIER '(' LIST_OF_PARAMETERS ')' {
          													if(!lookupFunction($2, true))
															 {

															 	insertFunction($1, $2, nrOfFunctionParameters, FunctionParameters, Scope, true);

															 	//curatam structurile de date alterate
															 	for(int i = 0; i < 5; i++)
															 	{
															 		bzero(FunctionParameters[i].type, 10);
															 		bzero(FunctionParameters[i].identifier, 10);
															 	}
															 	nrOfFunctionParameters = 0;
															 }
															 else
															 {
															 	DuplicateIdentifierError($2);
															 }

          												}
          | VOID IDENTIFIER '(' LIST_OF_PARAMETERS ')' '{' CODE_FUNCTION '}' {
          																		if(!lookupFunction($2, false))
						          													 {


						          													 	insertFunction($1, $2, nrOfFunctionParameters, FunctionParameters, Scope, false);
						          													 	//curatam structurile de date alterate
						          													 	for(int i = 0; i < 5; i++)
						          													 	{
						          													 		bzero(FunctionParameters[i].type, 10);
						          													 		bzero(FunctionParameters[i].identifier, 10);
						          													 	}
						          													 	nrOfFunctionParameters = 0;
						          													 }
						          													 else
						          													 {
						          													 	DuplicateIdentifierError($2);
						          													 }
          																		}
          | VOID IDENTIFIER '(' ')'{
          								 if(!lookupFunction($2, true))
											 {

											 	insertFunction($1, $2, nrOfFunctionParameters, FunctionParameters, Scope, true);

											 	//curatam structurile de date alterate
											 	for(int i = 0; i < 5; i++)
											 	{
											 		bzero(FunctionParameters[i].type, 10);
											 		bzero(FunctionParameters[i].identifier, 10);
											 	}
											 	nrOfFunctionParameters = 0;
											 }
											 else
											 {
											 	DuplicateIdentifierError($2);
											 }
          						   }
          | VOID IDENTIFIER '(' ')' '{' CODE_FUNCTION '}'	{
          														if(!lookupFunction($2, false))
		          													 {


		          													 	insertFunction($1, $2, nrOfFunctionParameters, FunctionParameters, Scope, false);
		          													 	//curatam structurile de date alterate
		          													 	for(int i = 0; i < 5; i++)
		          													 	{
		          													 		bzero(FunctionParameters[i].type, 10);
		          													 		bzero(FunctionParameters[i].identifier, 10);
		          													 	}
		          													 	nrOfFunctionParameters = 0;
		          													 }
		          													 else
		          													 {
		          													 	DuplicateIdentifierError($2);
		          													 }
          													}
          | IDENTIFIER IDENTIFIER '(' LIST_OF_PARAMETERS ')'		{/*conditie: primul identifier sa fie de tip caps*/}
          | IDENTIFIER IDENTIFIER '(' LIST_OF_PARAMETERS ')' '{' CODE_FUNCTION '}'        {/*conditie: primul identifier sa fie de tip caps*/}
          ;  

LIST_OF_VALUES : VALUE  {
							bzero(arrayValueType, 10);
							strcpy(arrayValueType, $1.type);
							StringValue($1);
							strcpy(arrayValues[arrayValuesCounter++], AuxBuffer);
						}
			   |LIST_OF_VALUES ',' VALUE
			   			{
			   				if(firstArrayType)
			   				{
			   					bzero(arrayValueType, 10);
								strcpy(arrayValueType, $3.type);
								firstArrayType = false;

								StringValue($3);
								strcpy(arrayValues[arrayValuesCounter++], AuxBuffer);
			   				}
			   				else
			   				{
			   					if(strcmp(arrayValueType, $3.type) == 0)
			   					{
			   						StringValue($3);
									strcpy(arrayValues[arrayValuesCounter++], AuxBuffer);
			   					}
			   					else
			   					{
			   						ListTypesError();
			   					}
			   				}
			   			}
              ;

VALUE : INTEGER_VALUE     {$$.type="int", $$.intVal=$1;}                   
     | FLOAT_VALUE		  {$$.type="float", $$.floatVal=$1;}
     | CHARACTER_VALUE	  {$$.type="char", $$.charVal=$1;}
     | STRING_VALUE		  {$$.type="string", $$.strVal=$1;}
     | BOOL_VALUE		  {$$.type="bool", $$.intVal=$1;}
     ; 

LIST_OF_PARAMETERS : DATA_TYPE IDENTIFIER {
										 	strcpy(FunctionParameters[nrOfFunctionParameters].type, $1);
										 	strcpy(FunctionParameters[nrOfFunctionParameters++].identifier, $2);
										  }
                   | LIST_OF_PARAMETERS ',' DATA_TYPE IDENTIFIER
                   							{
                   								strcpy(FunctionParameters[nrOfFunctionParameters].type, $3);
										 		strcpy(FunctionParameters[nrOfFunctionParameters++].identifier, $4);
                   							}

                   | DATA_TYPE ARRAY_PARAM_ID
                   | LIST_OF_PARAMETERS ',' DATA_TYPE ARRAY_PARAM_ID
                   | CONST DATA_TYPE IDENTIFIER
                   | LIST_OF_PARAMETERS ',' CONST DATA_TYPE IDENTIFIER
                   | CONST DATA_TYPE ARRAY_PARAM_ID
                   | LIST_OF_PARAMETERS ',' CONST DATA_TYPE ARRAY_PARAM_ID
                   | IDENTIFIER IDENTIFIER                                                  {/*conditie: primul identifier sa fie de tip caps*/}
                   | LIST_OF_PARAMETERS ',' IDENTIFIER IDENTIFIER                            {/*conditie: primul identifier sa fie de tip caps*/}
                   ;

CODE_FUNCTION : DECLARATIONS
              | DECLARATIONS BLOCK
              ;

BLOCK : '{' STATEMENT_LIST '}'
      ;

STATEMENT_LIST : STATEMENT ';'
               | STATEMENT_LIST STATEMENT ';'
               ;

STATEMENT : ASSIGNEMENT
          | FUNCTION_CALL
          | CONTROL_STATEMENT
          | EVAL '(' EVAL_EXP ')' { 
          							intToString($3);
          							strcpy(evalInfo[evalCounter++], AuxBuffer);
          						 }
          | PRINT '(' IDENTIFIER ')' { 
          								if(lookupVar($3))
          								{
          									var* nod = getVar($3);
          									printf("LINE: %d: type = %s | name = %s | value = %s | scope = %s| set = %d | used = %d | constant = %d\n" ,
													yylineno, nod->type, nod->name, nod->value, nod->scope, nod->set, nod->used, nod->constant);
          								}
          								else
          								{
          									UndeclaredVariableError($3);
          								}
          							 }
         | PRINT '(' ARRAY_PARAM_ID ')' {
         									char name[10];
         									strcpy(name, extractName($3));
         									if(lookupArray(name))
         									{
         										array* nod = getArray(name);
         										printf("LINE: %d : type = %s | name = %s | maxSize = %d | actualSize = %d | scope = %s | used = %d\n" ,
														yylineno, nod->type, nod->name, nod->maxSize, nod->actualSize, nod->scope, nod->used);
		

												if(nod->actualSize != 0)
												{
													printf("Values: ");
													for(int i = 0; i < nod->actualSize; i++)
													{
														printf("%s, ", nod->values[i]);
													}
													printf("\n");
												}
         									}
         									else
         									{
         										UndeclaredVariableError($3);
         									}
         								}
      	 | PRINT '(' VAR_TABLE ')'  	{printVarList();}
      	 | PRINT '(' ARRAY_TABLE ')'    {printArrayList();}
      	 | PRINT '(' FUNCTION_TABLE ')' {printFunctionList();}
          ;


ASSIGNEMENT : IDENTIFIER ASSIGN BLOCK_EXPRESSION    {
														if(lookupVar($1))
														{
															var* actualVar = getVar($1);
															char varType[10];
															strcpy(varType, actualVar->type);

															if(strcmp(actualVar->type, $3.type) == 0)
															{
																if(actualVar->constant != true)
																{
																	StringValue($3);
				  													strcpy(actualVar->value, AuxBuffer);
				  													actualVar->set = true;
																}
																else
																	ConstAsignementError($1);
															}
															else
															{
																AssignementError($1, actualVar->type, $3.type);
															}
														}
														else
														{
															UndeclaredVariableError($1);
														}
												    }
            | ARRAY_ID ASSIGN BLOCK_EXPRESSION {
            										char name[50];
				          							strcpy(name, extractName($1));
				          							if(lookupArray(name))
				          							{
				          								int index = extractMaxSize($1);
				          								array * nod = getArray(name);
				          								if(nod->actualSize <= index)
				          								{
				          									OutOfBoundError();
				          								}

				          								if(strcmp(nod->type, $3.type) == 0)
				          								{
				          									StringValue($3);
				          									strcpy(nod->values[index], AuxBuffer);
				          								}
				          								else
				          								{
				          									AssignementError($1, nod->type, $3.type);
				          								}

				          									
				          							}
				          							else
				          							{
				          								UndeclaredVariableError(name);
				          							}
            								   }

            | CAPS_ID ASSIGN BLOCK_EXPRESSION

BLOCK_EXPRESSION : VALUE {
								$$.type = $1.type;
								if(strcmp($1.type, "int") == 0)
								{
									$$.intVal = $1.intVal;
								}
								else if (strcmp($1.type, "float") == 0)
								{
									$$.intVal = $1.floatVal;
								}
								else if (strcmp($1.type, "bool") == 0)
								{
									$$.intVal = $1.intVal;
								}
								else if (strcmp($1.type, "char") == 0)
								{
									$$.charVal = $1.charVal;
								}
								else if (strcmp($1.type, "string") == 0)
								{
									$$.strVal = $1.strVal;
								}
						 }
                  | IDENTIFIER {
                  					if(lookupVar($1))
									{
										var* actualVar = getVar($1);
										if(actualVar->set == true)
										{
											$$.type = actualVar->type;
											if(strcmp(actualVar->type, "int") == 0)
											{
												$$.intVal = atoi(actualVar->value);
											}
											else if (strcmp(actualVar->type, "float") == 0)
											{
												$$.floatVal = atof(actualVar->value);
											}
											else if (strcmp(actualVar->type, "bool") == 0)
											{
												$$.intVal = atoi(actualVar->value);
											}
											else if (strcmp(actualVar->type, "char") == 0)
											{
												$$.charVal = actualVar->value[0];
											}
											else if (strcmp(actualVar->type, "string") == 0)
											{

												$$.strVal = actualVar->value;
											}
										}
										else
										{
											UsedButNotSetError($1);
										}
										
												
									}
									else
									{
										UndeclaredVariableError($1);
									}
                  			   }
                  | CAPS_ID			{ ;}
                  | ARRAY_ID  		{ 
                  						char name[50];
	          							strcpy(name, extractName($1));
	          							if(lookupArray(name))
	          							{
	          								int index = extractMaxSize($1);
	          								array * nod = getArray(name);
	          								if(nod->actualSize <= index)
	          								{
	          									OutOfBoundError();
	          								}

	          								$$.type = nod->type;

	          								if(strcmp(nod->type, "int") == 0)
	          									$$.intVal = atoi(nod->values[index]);
	          								else if (strcmp(nod->type, "float") == 0)
	          								{
	          									$$.floatVal = atof(nod->values[index]);
	          								}else if (strcmp(nod->type, "bool") == 0)
	          								{
	          									$$.intVal = atoi(nod->values[index]);
	          								}
	          								else if (strcmp(nod->type, "char") == 0)
	          								{
	          									$$.charVal = nod->values[index][0];
	          								}else if (strcmp(nod->type, "string") == 0)
	          								{
	          									$$.strVal = nod->values[index];
	          								}	
	          							}
	          							else
	          							{
	          								UndeclaredVariableError(name);
	          							}
                   					}
                  | FUNCTION_CALL 	{ 
                  						$$.type = $1.type;
                  						if(strcmp($$.type, "int") == 0)
          									$$.intVal = 0;
          								else if (strcmp($$.type, "float") == 0)
          								{
          									$$.floatVal = 0;
          								}else if (strcmp($$.type, "bool") == 0)
          								{
          									$$.intVal = 0;
          								}
          								else if (strcmp($$.type, "char") == 0)
          								{
          									$$.charVal = '\0';
          								}else if (strcmp($$.type, "string") == 0)
          								{
          									strcpy($$.strVal, "\0");
          								}

                  					}
                  | '(' BLOCK_EXPRESSION ')'  	{ 
                  									$$.type = $2.type;
			          								if(strcmp($2.type, "int") == 0)
			          									$$.intVal = $2.intVal;
			          								else if (strcmp($2.type, "float") == 0)
			          								{
			          									$$.floatVal = $2.floatVal;
			          								}else if (strcmp($2.type, "bool") == 0)
			          								{
			          									$$.intVal = $2.intVal;
			          								}
			          								else if (strcmp($2.type, "char") == 0)
			          								{
			          									$$.charVal = $2.charVal;
			          								}else if (strcmp($2.type, "string") == 0)
			          								{
			          									$$.strVal = $2.strVal;
			          								}

			          								
;
                  								}
               	  | BLOCK_EXPRESSION '+' BLOCK_EXPRESSION { 
               	  												if(strcmp($1.type, $3.type)== 0)
               	  												{
               	  													if(strcmp($1.type, "int") == 0)
               	  													{
               	  														$$.intVal = $1.intVal + $3.intVal;
               	  														$$.type = $1.type;
               	  													}else if(strcmp($1.type, "float") == 0)
               	  													{
               	  														$$.floatVal = $1.floatVal + $3.floatVal;
               	  														$$.type = $1.type;
               	  													}else if (strcmp($1.type, "string") == 0)
               	  													{
               	  														$$.strVal = $1.strVal;
               	  														int length = strlen($$.strVal);
               	  														$$.strVal[length - 1] = '\0';
               	  														strcat($$.strVal, $3.strVal + 1);
               	  														$$.type = $1.type;
               	  													}
               	  													else
               	  													{
               	  														OperatorError($1.type);
               	  													}
               	  												}
               	  												else
               	  												{
               	  													OperationError();
               	  												}

               	  											} 
               	  | BLOCK_EXPRESSION '-' BLOCK_EXPRESSION
               	  											{
               	  												if(strcmp($1.type, $3.type)== 0)
               	  												{
               	  													if(strcmp($1.type, "int") == 0)
               	  													{
               	  														$$.intVal = $1.intVal - $3.intVal;
               	  														$$.type = $1.type;
               	  													}else if(strcmp($1.type, "float") == 0)
               	  													{
               	  														$$.floatVal = $1.floatVal - $3.floatVal;
               	  														$$.type = $1.type;
               	  													}
               	  													else
               	  													{
               	  														OperatorError($1.type);
               	  													}
               	  												}
               	  												else
               	  												{
               	  													OperationError();
               	  												}

               	  											}
               	  | BLOCK_EXPRESSION '*' BLOCK_EXPRESSION 	{
               	  												if(strcmp($1.type, $3.type)== 0)
               	  												{
               	  													if(strcmp($1.type, "int") == 0)
               	  													{
               	  														$$.intVal = $1.intVal * $3.intVal;
               	  														$$.type = $1.type;
               	  													}else if(strcmp($1.type, "float") == 0)
               	  													{
               	  														$$.floatVal = $1.floatVal * $3.floatVal;
               	  														$$.type = $1.type;
               	  													}
               	  													else
               	  													{
               	  														OperatorError($1.type);
               	  													}
               	  												}
               	  												else
               	  												{
               	  													OperationError();
               	  												}

               	  											}
               	  | BLOCK_EXPRESSION '/' BLOCK_EXPRESSION	{
               	  												if(strcmp($1.type, $3.type)== 0)
               	  												{
               	  													if(strcmp($1.type, "int") == 0)
               	  													{
               	  														if($3.intVal != 0){
               	  															$$.intVal = (int)($1.intVal / $3.intVal);
               	  															$$.type = $1.type;
               	  														}
               	  														else
               	  														{
               	  															DivideZeroError();
               	  														}
               	  														
               	  													}else if(strcmp($1.type, "float") == 0)
               	  													{
               	  														if($3.floatVal != 0){
               	  															$$.floatVal = $1.floatVal / $3.floatVal;
               	  															$$.type = $1.type;
               	  														}
               	  														else
               	  														{
               	  															DivideZeroError();
               	  														}
               	  														
               	  													}
               	  													else
               	  													{
               	  														OperatorError($1.type);
               	  													}
               	  												}
               	  												else
               	  												{
               	  													OperationError();
               	  												}

               	  											}

               	  | BLOCK_EXPRESSION '%' BLOCK_EXPRESSION	{
	           	  												if(strcmp($1.type, $3.type)== 0)
	           	  												{
	           	  													if(strcmp($1.type, "int") == 0)
	           	  													{
	           	  														$$.intVal = $1.intVal % $3.intVal;
	           	  														$$.type = $1.type;
	           	  													}
	           	  													else
	           	  													{
	           	  														OperatorError($1.type);
	           	  													}
	           	  												}
	           	  												else
	           	  												{
	           	  													OperationError();
	           	  												}
               	  											}
               	  											;

CAPS_ID : ID '.' ID
       | CAPS_ID '.' ID
       ;

ID : IDENTIFIER
   | ARRAY_ID
   ;

FUNCTION_CALL : IDENTIFIER '(' LIST_OF_CALL_PARAMETERS ')'	{
																if(lookupFunction($1, false))
																{
																	

																	function* nod = getFunction($1, false);

																	if(nod->nrOfParameters == parameterListCounter)
																	{

																		for(int i = 0; i < parameterListCounter; i++)
																		{
																			if(strcmp(parameterList[i].type, nod->parameters[i].type) != 0)
																			{
																				ParameterWrongTypeError($1, i, parameterList[i].type, nod->parameters[i].type);
																			}																		
																		}
																		$$.type = nod->returnType;

																		if(strcmp($$.type, "int") == 0)
								          									$$.intVal = 0;
								          								else if (strcmp($$.type, "float") == 0)
								          								{
								          									$$.floatVal = 0;
								          								}else if (strcmp($$.type, "bool") == 0)
								          								{
								          									$$.intVal = 0;
								          								}
								          								else if (strcmp($$.type, "char") == 0)
								          								{
								          									$$.charVal = '\0';
								          								}else if (strcmp($$.type, "string") == 0)
								          								{
								          									strcpy($$.strVal, "\0");
								          								}

																		for(int i = 0; i < parameterListCounter; i++)
																		{
																			bzero(parameterList[i].type, 10);
																		}
																		parameterListCounter = 0;
																	}
																	else
																	{
																		ParameterNumberError($1);
																	}
																}
																else
																{
																	UndefinedFunction($1);
																}
															}
              | IDENTIFIER '(' ')'{
              						if(lookupFunction($1, false))
									{
																	

										function* nod = getFunction($1, false);

										if(nod->nrOfParameters == parameterListCounter)
										{

											for(int i = 0; i < parameterListCounter; i++)
											{
												if(strcmp(parameterList[i].type, nod->parameters[i].type) != 0)
												{
													ParameterWrongTypeError($1, i, parameterList[i].type, nod->parameters[i].type);
												}
											}

											$$.type = nod->returnType;

											if(strcmp($$.type, "int") == 0)
	          									$$.intVal = 0;
	          								else if (strcmp($$.type, "float") == 0)
	          								{
	          									$$.floatVal = 0;
	          								}else if (strcmp($$.type, "bool") == 0)
	          								{
	          									$$.intVal = 0;
	          								}
	          								else if (strcmp($$.type, "char") == 0)
	          								{
	          									$$.charVal = '\0';
	          								}else if (strcmp($$.type, "string") == 0)
	          								{
	          									strcpy($$.strVal, "\0");
	          								}


											for(int i = 0; i < parameterListCounter; i++)
											{
												bzero(parameterList[i].type, 10);
											}
											parameterListCounter = 0;
										}
										else
										{
											ParameterNumberError($1);
										}
									}
									else
									{
										UndefinedFunction($1);
									}	
              					  }


              | CAPS_ID '(' LIST_OF_CALL_PARAMETERS ')' {;}
              | CAPS_ID '(' ')'							{;}
              ;

LIST_OF_CALL_PARAMETERS : BLOCK_EXPRESSION      {
													parameterList[parameterListCounter].type = $1.type;

													if(strcmp($1.type, "int") == 0)
			          									parameterList[parameterListCounter++].intVal = $1.intVal;
			          								else if (strcmp($1.type, "float") == 0)
			          								{
			          									parameterList[parameterListCounter++].floatVal = $1.floatVal;
			          								}else if (strcmp($1.type, "bool") == 0)
			          								{
			          									parameterList[parameterListCounter++].intVal = $1.intVal;
			          								}
			          								else if (strcmp($1.type, "char") == 0)
			          								{
			          									parameterList[parameterListCounter++].charVal = $1.charVal;
			          								}else if (strcmp($1.type, "string") == 0)
			          								{
			          									parameterList[parameterListCounter++].strVal = $1.strVal;
			          								}
												}  
                        | LIST_OF_CALL_PARAMETERS ',' BLOCK_EXPRESSION { 
					                        							parameterList[parameterListCounter].type = $3.type;

																		if(strcmp($3.type, "int") == 0)
								          									parameterList[parameterListCounter++].intVal = $3.intVal;
								          								else if (strcmp($3.type, "float") == 0)
								          								{
								          									parameterList[parameterListCounter++].floatVal = $3.floatVal;
								          								}else if (strcmp($3.type, "bool") == 0)
								          								{
								          									parameterList[parameterListCounter++].intVal = $3.intVal;
								          								}
								          								else if (strcmp($3.type, "char") == 0)
								          								{
								          									parameterList[parameterListCounter++].charVal = $3.charVal;
								          								}else if (strcmp($3.type, "string") == 0)
								          								{
								          									parameterList[parameterListCounter++].strVal = $3.strVal;
								          								}
								          							}
                        ;


CONTROL_STATEMENT : IF '(' CONDITION ')' BLOCK
                  | IF '(' CONDITION ')' BLOCK ELSE BLOCK 
                  | WHILE '(' CONDITION ')' BLOCK
                  | FOR '(' ASSIGNEMENT ';' CONDITION ';' ASSIGNEMENT ')' BLOCK
                  ;

CONDITION :  SMALL_CONDITION
          | '!' '(' CONDITION ')'
          | '(' CONDITION ')'
          | CONDITION BOOL_OPERATOR CONDITION
          ;

SMALL_CONDITION : BLOCK_EXPRESSION RELATIONAL_OPERATOR BLOCK_EXPRESSION
                ;

EVAL_EXP : EVAL_EXP '+' EVAL_EXP	{$$=$1+$3; }
          | EVAL_EXP '-' EVAL_EXP	{$$=$1-$3; }
          | EVAL_EXP '*' EVAL_EXP	{$$=$1*$3; }
          | EVAL_EXP '/' EVAL_EXP	{$$=$1/$3; }
          | '(' EVAL_EXP ')'		{$$= $2;}
          | INTEGER_VALUE				{$$=$1;}
          ;

%%
void yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 