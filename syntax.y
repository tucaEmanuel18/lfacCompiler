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
void printList();
extern void storeDataType(char* data_type);

struct identifierList
{
	char* name;
	char* value;
	char set;
};

%}

%union {
  char* dataType;
  int intVal;
  char* strVal;
  float floatVal;
  char charVal;
  struct expressionInfo{
	    char *type;

	    int intVal;
	    float floatVal;
	    char charVal;
	    char *stringVal;
  }info;

   
}

%token <dataType> DATA_TYPE
%token <strVal> USR_DATA_TYPE

%token <strVal> STRING_VALUE 
%token <charVal> CHARACTER_VALUE 
%token <intVal> INTEGER_VALUE 
%token <floatVal> FLOAT_VALUE 
%token <intVal> BOOL_VALUE

%token IF FOR WHILE ELSE EVAL
%token ASSIGN  RELATIONAL_OPERATOR BOOL_OPERATOR ARITHMETIC_OPERATOR
%token <strVal> IDENTIFIER
%token ARRAY_ID ARRAY_PARAM_ID
%token VOID CONST  


%type<intVal> EVAL_EXP;
%type<info> VALUE;

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
CODE : DECLARATIONS BLOCK {printf("program corect sintactic\n"); printList();}
     ;
DECLARATIONS : DECLARATION ';'
            | DECLARATIONS  DECLARATION ';'
            ;

DECLARATION : EXPRESSION
            ;

EXPRESSION : DATA_TYPE  LIST_OF_IDENTIFIERS 	{ storeDataType($1); }
											

          | CONST DATA_TYPE LIST_OF_CONST_IDENTIFIERS
          | USR_DATA_TYPE IDENTIFIER '{' DECLARATIONS '}'
          | IDENTIFIER IDENTIFIER                                                         {/*conditie: primul identifier sa fie de tip caps*/}
          | IDENTIFIER IDENTIFIER ASSIGN '{' LIST_OF_VALUES '}'                           {/*conditie: primul identifier sa fie de tip caps*/}
          | DATA_TYPE IDENTIFIER '(' LIST_OF_PARAMETERS ')'
          | DATA_TYPE IDENTIFIER '(' LIST_OF_PARAMETERS ')' '{' CODE_FUNCTION '}'
          | VOID IDENTIFIER '(' LIST_OF_PARAMETERS ')' 
          | VOID IDENTIFIER '(' LIST_OF_PARAMETERS ')' '{' CODE_FUNCTION '}'
          | IDENTIFIER IDENTIFIER '(' LIST_OF_PARAMETERS ')'                              {/*conditie: primul identifier sa fie de tip caps*/}
          | IDENTIFIER IDENTIFIER '(' LIST_OF_PARAMETERS ')' '{' CODE_FUNCTION '}'        {/*conditie: primul identifier sa fie de tip caps*/}
          ;  
                      
LIST_OF_IDENTIFIERS :  IDENTIFIER { 
									if(!lookupVar($1))
									{
									  insertVar(DataType, $1, "\0", false);
									}
									else
									{
										DuplicateIdentifierError($1);
									}
								  }

                    | LIST_OF_IDENTIFIERS ','   IDENTIFIER 	{ 
									if(!lookupVar($3))
									{
									  insertVar(DataType, $3, "\0", false);
									}
									else
									{
										DuplicateIdentifierError($3);
									}
								  }


                    | IDENTIFIER ASSIGN VALUE { 
									if(!lookupVar($1))
									{
										if(strcmp($3.type, "int") == 0)
										{
											intToString($3.intVal);
										}
										else if (strcmp($3.type, "float") == 0)
										{
											floatToString($3.floatVal);
										}
										else if (strcmp($3.type, "bool") == 0)
										{
											//valueToString($3.intVal);
										}
										else if (strcmp($3.type, "char") == 0)
										{
											//valueToString($3.charVal);
										}
										else if (strcmp($3.type, "str") == 0)
										{
											/*bzero(AuxBuffer, 50);
											strcpy(AuxBuffer, $3.strVal);*/
										}
										
									}
									else
									{
										DuplicateIdentifierError($1);
									}

									insertVar(DataType, $1, AuxBuffer, true);
								  }


                    | LIST_OF_IDENTIFIERS ',' IDENTIFIER ASSIGN VALUE {
                    				if(!lookupVar($3))
									{
										if(strcmp($5.type, "int") == 0)
										{
											intToString($5.intVal);
										}
										else if (strcmp($5.type, "float") == 0)
										{
											//floatToString($5.floatVal);
											printf("\nFloatVAL = %f\n", $5.floatVal);
											fflush(stdout);
										}
										else if (strcmp($5.type, "bool") == 0)
										{
											;//valueToString($5.intVal);
										}
										else if (strcmp($5.type, "char") == 0)
										{
											;//valueToString($5.charVal);
										}
										else if (strcmp($5.type, "str") == 0)
										{
											;/*bzero(AuxBuffer, 50);
											strcpy(AuxBuffer, $5.strVal);*/
										}


									  printf("\nOut DataType  = %s\n", DataType);
									  fflush(stdout);
									  insertVar(DataType, $3, AuxBuffer, true);
									}
									else
									{
										DuplicateIdentifierError($3);
									}
								  }
                    | ARRAY_ID
                    | LIST_OF_IDENTIFIERS ',' ARRAY_ID
                    | ARRAY_ID ASSIGN '{' LIST_OF_VALUES '}'
                    | LIST_OF_IDENTIFIERS ',' ARRAY_ID ASSIGN '{' LIST_OF_VALUES '}'
                    ;
                    
LIST_OF_CONST_IDENTIFIERS : IDENTIFIER ASSIGN VALUE
                       | ARRAY_ID ASSIGN '{' LIST_OF_VALUES '}'
                       | LIST_OF_CONST_IDENTIFIERS ',' IDENTIFIER ASSIGN VALUE
                       | LIST_OF_CONST_IDENTIFIERS ',' ARRAY_ID ASSIGN '{' LIST_OF_VALUES '}'
                       ;  



LIST_OF_VALUES :  LIST_OF_VALUES ',' VALUE  
              | VALUE   
              ;

VALUE : INTEGER_VALUE     {$$.type="int", $$.intVal=$1;}                   
     | FLOAT_VALUE		  {$$.type="float", $$.floatVal=$1;}
     | CHARACTER_VALUE	  {$$.type="char", $$.charVal=$1;}
     | STRING_VALUE		  {$$.type="string", $$.stringVal=$1;}
     | BOOL_VALUE		  {$$.type="bool", $$.intVal=$1;}
     ; 

LIST_OF_PARAMETERS : DATA_TYPE IDENTIFIER
                   | LIST_OF_PARAMETERS ',' DATA_TYPE IDENTIFIER
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


ASSIGNEMENT : IDENTIFIER ASSIGN BLOCK_EXPRESSION
            | ARRAY_ID ASSIGN BLOCK_EXPRESSION
            | CAPS_ID ASSIGN BLOCK_EXPRESSION
            ;

BLOCK_EXPRESSION : VALUE
                  | IDENTIFIER
                  | CAPS_ID
                  | ARRAY_ID
                  | FUNCTION_CALL
                  | '(' BLOCK_EXPRESSION ')' 
               	  | BLOCK_EXPRESSION '+' BLOCK_EXPRESSION
               	  | BLOCK_EXPRESSION '-' BLOCK_EXPRESSION
               	  | BLOCK_EXPRESSION '*' BLOCK_EXPRESSION
               	  | BLOCK_EXPRESSION '/' BLOCK_EXPRESSION
               	  | BLOCK_EXPRESSION '%' BLOCK_EXPRESSION
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