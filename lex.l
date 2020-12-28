%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool"                         {printf("DATA_TYPE "); return DATA_TYPE;}
"const"                        {printf("CONST"); return CONST;}
"caps"                        {printf("USR_DATA_TYPE "); return USR_DATA_TYPE;}
"if"                                             {printf("IF "); return IF;}
"for"                                          {printf("FOR "); return FOR;}
"while"                                      {printf("WHILE "); return WHILE;}
"else"                                        {printf("ELSE "); return ELSE;}
"begin_prog"                  {printf("BEGIN "); return BEGIN_PROG;}
"end_prog"                     {printf("END "); return END_PROG;}
"true"|"false"                               {printf("BOOL_VALUE "); return BOOL_VALUE;}
":="                                             {printf("ASSIGN "); return ASSIGN;}
"+"|"-"|"*"|"/"|"%"                          {printf("ARITHEMTIC_OPERATOR "); return ARITHMETIC_OPERATOR;}      
">"|">="|"<"|"<="|"="|"!="            {printf("RELATIONAL_OPERATOR "); return RELATIONAL_OPERATOR;}
"||"|"&&"|"!"                                {printf("BOOL_OPERATOR"); return BOOL_OPERATOR;}
[a-zA-Z][_a-zA-Z0-9]*(\[[1-9][0-9]*\])+                           {printf("ARRAY_ID "); return ARRAY_ID;}
[a-zA-Z][_a-zA-Z0-9]*                         {printf("IDENTIFIER "); return IDENTIFIER;}
[\'].[\']                               {printf("CHARACTER_VALUE "); return CHARACTER_VALUE;}
[+-]?0|([1-9][0-9]*)                            {printf("INTEGER_NUMBER "); return INTEGER_VALUE;}
[+-]?[0-9]+\.[0-9]+                     {printf("FLOAT_NUMBER "); return FLOAT_VALUE;}
[\"][ a-zA-Z0-9]+[\"]                            {printf("STRING_VALUE "); return STRING_VALUE;}
[ \t] ;
\n {yylineno++;}
";"                                            {printf("\n"); return yytext[0]; }
"{"|"}"|","											{return yytext[0];}
. {return yytext[0];}
%%