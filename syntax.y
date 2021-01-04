%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern void yyerror();
extern int yylex();

%}
%token DATA_TYPE USR_DATA_TYPE VOID CONST 
%token STRING_VALUE CHARACTER_VALUE INTEGER_VALUE FLOAT_VALUE BOOL_VALUE
%token IF FOR WHILE ELSE EVAL
%token ASSIGN  RELATIONAL_OPERATOR BOOL_OPERATOR ARITHMETIC_OPERATOR
%token IDENTIFIER ARRAY_ID ARRAY_PARAM_ID 
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
CODE : DECLARATIONS BLOCK {printf("program corect sintactic\n");}
     ;
DECLARATIONS : DECLARATION ';'
            | DECLARATIONS  DECLARATION ';'
            ;

DECLARATION : EXPRESSION
            ;

EXPRESSION : DATA_TYPE LIST_OF_IDENTIFIERS
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

                      
LIST_OF_IDENTIFIERS :  IDENTIFIER
                    | LIST_OF_IDENTIFIERS ','   IDENTIFIER
                    | IDENTIFIER ASSIGN VALUE
                    | LIST_OF_IDENTIFIERS ',' IDENTIFIER ASSIGN VALUE
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

VALUE : INTEGER_VALUE                           
     | FLOAT_VALUE
     | CHARACTER_VALUE
     | STRING_VALUE
     | BOOL_VALUE;
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
          | EVAL '(' EVAL_EXP ')' {$$=$3; printf("valoarea expresiei: %d\n", $$);}
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