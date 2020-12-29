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
    IF = 260,
    FOR = 261,
    WHILE = 262,
    ELSE = 263,
    BEGIN_PROG = 264,
    END_PROG = 265,
    BOOL_VALUE = 266,
    ASSIGN = 267,
    ARITHMETIC_OPERATOR = 268,
    RELATIONAL_OPERATOR = 269,
    ARRAY_ID = 270,
    IDENTIFIER = 271,
    CHARACTER_VALUE = 272,
    INTEGER_VALUE = 273,
    FLOAT_VALUE = 274,
    STRING_VALUE = 275,
    CONST = 276,
    BOOL_OPERATOR = 277,
    VOID = 278,
    ARRAY_PARAM_ID = 279
  };
#endif
/* Tokens.  */
#define DATA_TYPE 258
#define USR_DATA_TYPE 259
#define IF 260
#define FOR 261
#define WHILE 262
#define ELSE 263
#define BEGIN_PROG 264
#define END_PROG 265
#define BOOL_VALUE 266
#define ASSIGN 267
#define ARITHMETIC_OPERATOR 268
#define RELATIONAL_OPERATOR 269
#define ARRAY_ID 270
#define IDENTIFIER 271
#define CHARACTER_VALUE 272
#define INTEGER_VALUE 273
#define FLOAT_VALUE 274
#define STRING_VALUE 275
#define CONST 276
#define BOOL_OPERATOR 277
#define VOID 278
#define ARRAY_PARAM_ID 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
