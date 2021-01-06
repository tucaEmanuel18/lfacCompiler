%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool"                       {/*printf("DATA_TYPE ");*/ yylval.dataType=strdup(yytext); return DATA_TYPE;}
"void"														{/*printf("VOID ");*/ yylval.dataType=strdup(yytext); return VOID;}
"const"                        {/*printf("CONST ");*/ return CONST;}
"caps"                        {/*printf("USR_DATA_TYPE ");*/ return USR_DATA_TYPE;}
"if"                                             {/*printf("IF ");*/ return IF;}
"for"                                          {/*printf("FOR ");*/ return FOR;}
"while"                                      {/*printf("WHILE ");*/ return WHILE;}
"else"                                        {/*printf("ELSE ");*/ return ELSE;}
"true"										{/*printf("BOOL_VALUE");*/ yylval.intVal = 1; return BOOL_VALUE;}
"false"                              		{/*printf("BOOL_VALUE");*/ yylval.intVal = 0; return BOOL_VALUE;}
"eval"											{/*printf("EVAL ");*/ return EVAL;}
"print"                                         {/*printf("PRINT");*/ yylval.dataType=strdup(yytext); return PRINT;}
"varTable"										{return VAR_TABLE;}
"arrayTable"									{return ARRAY_TABLE;}
"functionTAble"									{return FUNCTION_TABLE;}		
":="                                             {/*printf("ASSIGN ");*/ return ASSIGN;}
"||"|"&&"                               {/*printf("BOOL_OPERATOR");*/ return BOOL_OPERATOR;}
[a-zA-Z][_a-zA-Z0-9]*(\[\])+				{/*printf("ARRAY_PARAM_ID");*/ yylval.strVal = strdup(yytext); return ARRAY_PARAM_ID;}
[a-zA-Z][_a-zA-Z0-9]*(\[((0|([1-9][0-9]*))|([a-zA-Z][_a-zA-Z0-9]*))\])    {/*printf("ARRAY_ID ");*/ yylval.strVal = strdup(yytext); return ARRAY_ID;}
[a-zA-Z][_a-zA-Z0-9]*                         {/*printf("IDENTIFIER ");*/ yylval.strVal=strdup(yytext); return IDENTIFIER;}
[\'].[\']                               {/*printf("CHARACTER_VALUE ");*/ yylval.charVal=yytext[1]; return CHARACTER_VALUE;}
([+-])?(0|([1-9][0-9]*))                            {/*printf("INTEGER_NUMBER ");*/ yylval.intVal=atoi(yytext); return INTEGER_VALUE;}
([+-])?[0-9]+\.[0-9]+                     {/*printf("FLOAT_NUMBER ");*/ yylval.floatVal=atof(yytext); return FLOAT_VALUE;}
[\"][ a-zA-Z0-9]+[\"]                            {/*printf("STRING_VALUE ");*/ yylval.strVal = strdup(yytext); return STRING_VALUE;}
[ \t] ;
\n {yylineno++;}   
">"|">="|"<"|"<="|"="|"!="            {/*printf("RELATIONAL_OPERATOR ");*/ return RELATIONAL_OPERATOR;}
";"                                            {/*printf("\n");*/ return yytext[0]; }
"+"|"-"|"*"|"/"|"%"|"{"|"}"|","|"("|")"|"!" 											{ return yytext[0]; }
. {return yytext[0];}
%%