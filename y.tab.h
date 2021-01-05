/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DATA_TYPE = 258,
    USR_DATA_TYPE = 259,
    STRING_VALUE = 260,
    CHARACTER_VALUE = 261,
    INTEGER_VALUE = 262,
    FLOAT_VALUE = 263,
    BOOL_VALUE = 264,
    IDENTIFIER = 265,
    IF = 266,
    FOR = 267,
    WHILE = 268,
    ELSE = 269,
    EVAL = 270,
    ASSIGN = 271,
    RELATIONAL_OPERATOR = 272,
    BOOL_OPERATOR = 273,
    ARITHMETIC_OPERATOR = 274,
    ARRAY_ID = 275,
    ARRAY_PARAM_ID = 276,
    VOID = 277,
    CONST = 278
  };
#endif
/* Tokens.  */
#define DATA_TYPE 258
#define USR_DATA_TYPE 259
#define STRING_VALUE 260
#define CHARACTER_VALUE 261
#define INTEGER_VALUE 262
#define FLOAT_VALUE 263
#define BOOL_VALUE 264
#define IDENTIFIER 265
#define IF 266
#define FOR 267
#define WHILE 268
#define ELSE 269
#define EVAL 270
#define ASSIGN 271
#define RELATIONAL_OPERATOR 272
#define BOOL_OPERATOR 273
#define ARITHMETIC_OPERATOR 274
#define ARRAY_ID 275
#define ARRAY_PARAM_ID 276
#define VOID 277
#define CONST 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "syntax.y"

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
	    char *strVal;
  }info;



   

#line 123 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
