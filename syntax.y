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
  }varInfo;



struct parameter FunctionParameters[5];
int nrOfFunctionParameters = 0;

//
char arrayValueType[10];
char arrayValues[20][20];
int arrayValuesCounter = 0;
bool firstArrayType = true;


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

%token IF FOR WHILE ELSE EVAL
%token ASSIGN  RELATIONAL_OPERATOR BOOL_OPERATOR ARITHMETIC_OPERATOR
%token <strVal> ARRAY_ID ARRAY_PARAM_ID
%token VOID CONST  


%type<intVal> EVAL_EXP;
%type<infoArray> LIST_OF_VALUES;
%type<info> VALUE ;
%type<info> BLOCK_EXPRESSION;
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
CODE : DECLARATIONS BLOCK {printf("program corect sintactic\n"); printVarList(); printArrayList(); printFunctionList();}
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

          | DATA_TYPE IDENTIFIER '(' LIST_OF_PARAMETERS ')' '{' CODE_FUNCTION '}' 	{
	      																				if(!lookupFunction($2, true))
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
          | VOID IDENTIFIER '(' LIST_OF_PARAMETERS ')' 
          | VOID IDENTIFIER '(' LIST_OF_PARAMETERS ')' '{' CODE_FUNCTION '}'
          | IDENTIFIER IDENTIFIER '(' LIST_OF_PARAMETERS ')'                              {/*conditie: primul identifier sa fie de tip caps*/}
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
          | EVAL '(' EVAL_EXP ')' {printf("valoarea expresiei: %d\n", $3);}
          ;


ASSIGNEMENT : IDENTIFIER ASSIGN BLOCK_EXPRESSION    {  if(lookupVar($1))
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
            | ARRAY_ID ASSIGN BLOCK_EXPRESSION
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
										strcpy($$.type, actualVar->type);
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
											printf("\nFALG\n");
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
	          								}else if (strcmp(nod->type, "float") == 0)
	          								{
	          									$$.strVal = nod->values[index];
	          								}	
	          							}
	          							else
	          							{
	          								UndeclaredVariableError(name);
	          							}
                   					}
                  | FUNCTION_CALL 	{ ;}
                  | '(' BLOCK_EXPRESSION ')'  	{;}
               	  | BLOCK_EXPRESSION '+' BLOCK_EXPRESSION { 
               	  												if(strcmp($1.type, $3.type)== 0)
               	  												{
               	  													if(strcmp($1.type, "int") == 0)
               	  													{
               	  														$$.intVal = $1.intVal + $3.intVal;
               	  														strcpy($$.type, $1.type);
               	  													}else if(strcmp($1.type, "float") == 0)
               	  													{
               	  														$$.floatVal = $1.floatVal + $3.floatVal;
               	  														strcpy($$.type, $1.type);
               	  													}else if (strcmp($1.type, "string") == 0)
               	  													{
               	  														strcpy($$.strVal, $1.strVal);
               	  														int length = strlen($$.strVal);
               	  														$$.strVal[length - 1] = '\0';
               	  														strcat($$.strVal, $3.strVal + 1);
               	  														printf("\n%s\n",$$.strVal);
               	  														strcpy($$.type, $1.type);
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

FUNCTION_CALL : IDENTIFIER '(' LIST_OF_CALL_PARAMETERS ')'
              | IDENTIFIER '(' ')'
              | CAPS_ID '(' LIST_OF_CALL_PARAMETERS ')'
              | CAPS_ID '(' ')'
              ;

LIST_OF_CALL_PARAMETERS : BLOCK_EXPRESSION        
                        | LIST_OF_CALL_PARAMETERS ',' BLOCK_EXPRESSION
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

EVAL_EXP : EVAL_EXP '+' EVAL_EXP	{$$=$1+$3; printf("e->e+e | %d + %d = %d ", $1, $3, $$);}
          | EVAL_EXP '-' EVAL_EXP	{$$=$1-$3; printf("e->e-e | %d - %d = %d ", $1, $3, $$);}
          | EVAL_EXP '*' EVAL_EXP	{$$=$1*$3; printf("e->e*e | %d * %d = %d ", $1, $3, $$);}
          | EVAL_EXP '/' EVAL_EXP	{$$=$1/$3; printf("e->e/e | %d / %d = %d ", $1, $3, $$);}
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