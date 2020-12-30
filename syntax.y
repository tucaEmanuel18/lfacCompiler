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
%token IF FOR WHILE ELSE BEGIN_PROG END_PROG
%token ASSIGN ARITHMETIC_OPERATOR RELATIONAL_OPERATOR BOOL_OPERATOR 
%token IDENTIFIER ARRAY_ID ARRAY_PARAM_ID 
%start CODE
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

BLOCK : BEGIN_PROG STATEMENT_LIST END_PROG
      ;

STATEMENT_LIST : STATEMENT ';'
               | STATEMENT_LIST STATEMENT ';'
               ;

STATEMENT : ASSIGNEMENT
          | FUNCTION_CALL
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
                  | BLOCK_EXPRESSION ARITHMETIC_OPERATOR BLOCK_EXPRESSION
                  ;

CAPS_ID : ID '.' ID
       | CAPS_ID '.' ID
       ;

ID : IDENTIFIER
   | ARRAY_ID
   ;

FUNCTION_CALL : IDENTIFIER '(' LIST_OF_CALL_PARAMETERS ')'
              | CAPS_ID '(' LIST_OF_CALL_PARAMETERS ')'
              ;

LIST_OF_CALL_PARAMETERS : BLOCK_EXPRESSION        
                        | LIST_OF_CALL_PARAMETERS ',' BLOCK_EXPRESSION
                        ;

%%
void yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 