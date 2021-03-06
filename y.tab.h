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
    VOID = 266,
    IF = 267,
    FOR = 268,
    WHILE = 269,
    ELSE = 270,
    EVAL = 271,
    PRINT = 272,
    ASSIGN = 273,
    RELATIONAL_OPERATOR = 274,
    BOOL_OPERATOR = 275,
    ARITHMETIC_OPERATOR = 276,
    VAR_TABLE = 277,
    ARRAY_TABLE = 278,
    FUNCTION_TABLE = 279,
    ARRAY_ID = 280,
    ARRAY_PARAM_ID = 281,
    CONST = 282
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
#define VOID 266
#define IF 267
#define FOR 268
#define WHILE 269
#define ELSE 270
#define EVAL 271
#define PRINT 272
#define ASSIGN 273
#define RELATIONAL_OPERATOR 274
#define BOOL_OPERATOR 275
#define ARITHMETIC_OPERATOR 276
#define VAR_TABLE 277
#define ARRAY_TABLE 278
#define FUNCTION_TABLE 279
#define ARRAY_ID 280
#define ARRAY_PARAM_ID 281
#define CONST 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "syntax.y"

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



   

#line 131 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
