/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

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


#line 137 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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



   

#line 263 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

#define YYUNDEFTOK  2
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,    32,     2,     2,
      36,    37,    30,    28,    38,    29,    39,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   122,   122,   128,   129,   132,   135,   145,   165,   185,
     199,   231,   232,   233,   234,   254,   275,   294,   313,   333,
     352,   371,   390,   391,   394,   400,   426,   427,   428,   429,
     430,   433,   437,   443,   444,   445,   446,   447,   448,   449,
     450,   453,   454,   457,   460,   461,   464,   465,   466,   467,
     471,   483,   508,   509,   510,   514,   542,   572,   574,   597,
     638,   639,   675,   695,   717,   747,   771,   794,   832,   852,
     853,   856,   857,   860,   912,   968,   969,   972,   992,  1015,
    1016,  1017,  1018,  1021,  1022,  1023,  1024,  1027,  1030,  1031,
    1032,  1033,  1034,  1035
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATA_TYPE", "USR_DATA_TYPE",
  "STRING_VALUE", "CHARACTER_VALUE", "INTEGER_VALUE", "FLOAT_VALUE",
  "BOOL_VALUE", "IDENTIFIER", "VOID", "IF", "FOR", "WHILE", "ELSE", "EVAL",
  "PRINT", "ASSIGN", "RELATIONAL_OPERATOR", "BOOL_OPERATOR",
  "ARITHMETIC_OPERATOR", "VAR_TABLE", "ARRAY_TABLE", "FUNCTION_TABLE",
  "ARRAY_ID", "ARRAY_PARAM_ID", "CONST", "'+'", "'-'", "'*'", "'/'", "'%'",
  "';'", "'{'", "'}'", "'('", "')'", "','", "'.'", "'!'", "$accept",
  "CODE", "DECLARATIONS", "DECLARATION", "EXPRESSION", "LIST_OF_VALUES",
  "VALUE", "LIST_OF_PARAMETERS", "CODE_FUNCTION", "BLOCK",
  "STATEMENT_LIST", "STATEMENT", "ASSIGNEMENT", "BLOCK_EXPRESSION",
  "CAPS_ID", "ID", "FUNCTION_CALL", "LIST_OF_CALL_PARAMETERS",
  "CONTROL_STATEMENT", "CONDITION", "SMALL_CONDITION", "EVAL_EXP", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    43,    45,
      42,    47,    37,    59,   123,   125,    40,    41,    44,    46,
      33
};
# endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,     4,    16,    44,    54,    15,    20,   117,    83,  -109,
      -1,   104,    90,    47,   118,   148,  -109,   185,   151,  -109,
    -109,   226,    18,   227,   135,   228,    66,    31,   182,    48,
     229,   230,   232,   233,   234,   245,   143,   238,  -109,    -6,
     235,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
     165,   254,   264,   239,   -13,   226,    96,   226,   171,   241,
     190,   226,   127,    72,    65,    42,    65,     2,   159,   127,
    -109,   243,  -109,   127,   105,    93,    93,  -109,  -109,  -109,
     166,   135,   244,   137,    91,  -109,  -109,   191,   246,   135,
     247,  -109,    17,   240,   127,  -109,   208,   205,  -109,  -109,
     208,   214,    65,   236,   175,     3,  -109,   259,   249,    -8,
     128,  -109,     2,   188,   248,   250,   251,   252,   253,   208,
    -109,   208,  -109,   216,  -109,  -109,  -109,  -109,  -109,  -109,
     117,   256,   135,   167,   273,   281,  -109,   226,  -109,   135,
     257,   135,   183,   127,   127,   127,   127,   127,  -109,   127,
     142,   129,    65,   127,    65,   260,    65,   260,   193,     2,
       2,     2,     2,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,   258,  -109,  -109,  -109,   170,  -109,   261,  -109,
     262,  -109,   157,   215,   211,   263,  -109,   208,  -109,   130,
     208,  -109,   271,    84,  -109,  -109,   219,   225,   267,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,   260,    42,  -109,   265,
     260,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     9,     0,    12,     0,     0,     1,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,    72,     0,     0,    46,     0,
       0,    47,    48,     4,    29,    28,    26,    27,    30,     7,
       0,     0,     0,    15,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,    44,     0,     0,     0,     0,    31,    33,    39,
       0,     0,    14,     0,     0,    24,    11,     0,    22,     0,
      18,     8,    59,    61,     0,    58,    55,    60,    62,    74,
      77,     0,     0,     0,     0,     0,    83,    71,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,    56,
      45,    57,    76,     0,    71,    72,    70,    69,    35,    37,
      41,     0,     0,     0,     0,     0,    10,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,    50,    52,    53,    54,    51,    75,
      42,    17,     0,    32,    34,    40,     0,    25,     0,    21,
       0,    63,    64,    65,    66,    67,    68,    78,    85,     0,
      87,    86,    79,     0,    81,    92,    88,    89,    90,    91,
      16,    36,    38,    23,    19,    84,     0,     0,    80,     0,
       0,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,     8,    -5,  -109,   242,   -18,   231,   -82,  -108,
    -109,   268,   -64,   -58,   -17,   184,    10,   237,  -109,   -60,
    -109,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,   130,     8,     9,    84,    95,    54,   131,    19,
      36,    37,    38,   104,    97,    40,    98,   101,    42,   105,
     106,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   108,    18,    49,    96,   100,   110,   140,     7,   111,
      73,   119,    73,   158,    10,   121,   100,    21,    15,    39,
      16,    50,   170,   154,    82,    83,    12,    41,    51,    11,
      74,    75,    56,    75,    50,    22,   142,    85,   112,    85,
     155,    51,   151,    91,   150,    52,    41,   192,   109,   194,
     172,    18,   107,    63,    13,    53,   -71,   178,    52,   180,
     196,   197,   198,   199,    14,    25,    62,    35,    59,    50,
      44,    45,    46,    47,    48,    92,    51,    44,    45,    46,
      47,    48,    92,    26,    63,   182,   183,   184,   185,   186,
      93,   187,   189,    52,   191,   190,   193,    93,   208,     1,
       2,   102,   211,   124,   154,   103,     3,     4,    94,    99,
      44,    45,    46,    47,    48,    92,    20,   207,   125,   177,
       1,     2,    23,     5,    24,    18,   136,     3,     4,   137,
      93,    86,    44,    45,    46,    47,    48,    92,     1,     2,
     133,    94,   122,   209,     5,     3,     4,   134,   154,   154,
     154,    17,    93,    29,    27,    30,    31,    32,    28,    33,
      34,   153,     5,    94,   135,   157,   188,   205,    35,   114,
     143,   144,   145,   146,   147,    77,   128,   173,    70,   181,
     201,   115,   116,   117,    43,   118,   144,   145,   146,   147,
     109,    78,   129,   174,   153,    29,   202,    30,    31,    32,
      61,    33,    34,   143,   144,   145,   146,   147,    88,    83,
      35,   143,   144,   145,   146,   147,   159,   160,   161,   162,
     181,   159,   160,   161,   162,   163,   138,    90,    83,   137,
     195,    44,    45,    46,    47,    48,   143,   144,   145,   146,
     147,    74,   146,   147,    75,   145,   146,   147,   160,   161,
     162,   148,   149,   169,   149,   161,   162,    58,    60,   126,
     127,    55,    57,    69,    79,    64,    65,    80,    66,    67,
      68,    72,   152,    81,    76,    89,   120,    62,   132,   -72,
     139,   141,   156,   175,   176,   164,   206,   165,   166,   167,
     168,   171,   179,   200,    17,   147,   203,   204,   162,    87,
       0,     0,   210,     0,    71,     0,     0,     0,     0,     0,
       0,   123
};

static const yytype_int16 yycheck[] =
{
      17,    65,     7,    21,    62,    63,    66,    89,     0,     7,
      18,    69,    18,   112,    10,    73,    74,    18,     3,    36,
       0,     3,   130,    20,    37,    38,    10,    17,    10,    25,
      36,    39,    24,    39,     3,    36,    94,    55,    36,    57,
      37,    10,   102,    61,   102,    27,    36,   155,    65,   157,
     132,    56,    10,    36,    10,    37,    39,   139,    27,   141,
     159,   160,   161,   162,    10,    18,    18,    25,    37,     3,
       5,     6,     7,     8,     9,    10,    10,     5,     6,     7,
       8,     9,    10,    36,    36,   143,   144,   145,   146,   147,
      25,   149,   152,    27,   154,   153,   156,    25,   206,     3,
       4,    36,   210,    10,    20,    40,    10,    11,    36,    37,
       5,     6,     7,     8,     9,    10,    33,    33,    25,   137,
       3,     4,    18,    27,    34,   130,    35,    10,    11,    38,
      25,    35,     5,     6,     7,     8,     9,    10,     3,     4,
       3,    36,    37,   207,    27,    10,    11,    10,    20,    20,
      20,    34,    25,    10,    36,    12,    13,    14,    10,    16,
      17,    19,    27,    36,    27,    37,    37,    37,    25,    10,
      28,    29,    30,    31,    32,    10,    10,    10,    35,    37,
      10,    22,    23,    24,    33,    26,    29,    30,    31,    32,
     207,    26,    26,    26,    19,    10,    26,    12,    13,    14,
      18,    16,    17,    28,    29,    30,    31,    32,    37,    38,
      25,    28,    29,    30,    31,    32,    28,    29,    30,    31,
      37,    28,    29,    30,    31,    37,    35,    37,    38,    38,
      37,     5,     6,     7,     8,     9,    28,    29,    30,    31,
      32,    36,    31,    32,    39,    30,    31,    32,    29,    30,
      31,    37,    38,    37,    38,    30,    31,    26,    27,    75,
      76,    34,    34,    18,    10,    36,    36,     3,    36,    36,
      36,    33,    36,    34,    39,    34,    33,    18,    34,    39,
      34,    34,    33,    10,     3,    37,    15,    37,    37,    37,
      37,    35,    35,    35,    34,    32,    35,    35,    31,    57,
      -1,    -1,    37,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    10,    11,    27,    42,    43,    44,    45,
      10,    25,    10,    10,    10,     3,     0,    34,    44,    50,
      33,    18,    36,    18,    34,    18,    36,    36,    10,    10,
      12,    13,    14,    16,    17,    25,    51,    52,    53,    55,
      56,    57,    59,    33,     5,     6,     7,     8,     9,    47,
       3,    10,    27,    37,    48,    34,    43,    34,    48,    37,
      48,    18,    18,    36,    36,    36,    36,    36,    36,    18,
      35,    52,    33,    18,    36,    39,    39,    10,    26,    10,
       3,    34,    37,    38,    46,    47,    35,    46,    37,    34,
      37,    47,    10,    25,    36,    47,    54,    55,    57,    37,
      54,    58,    36,    40,    54,    60,    61,    10,    53,    55,
      60,     7,    36,    62,    10,    22,    23,    24,    26,    54,
      33,    54,    37,    58,    10,    25,    56,    56,    10,    26,
      43,    49,    34,     3,    10,    27,    35,    38,    35,    34,
      49,    34,    54,    28,    29,    30,    31,    32,    37,    38,
      54,    60,    36,    19,    20,    37,    33,    37,    62,    28,
      29,    30,    31,    37,    37,    37,    37,    37,    37,    37,
      50,    35,    49,    10,    26,    10,     3,    47,    49,    35,
      49,    37,    54,    54,    54,    54,    54,    54,    37,    60,
      54,    60,    50,    60,    50,    37,    62,    62,    62,    62,
      35,    10,    26,    35,    35,    37,    15,    33,    50,    53,
      37,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    57,    57,    58,    58,    59,
      59,    59,    59,    60,    60,    60,    60,    61,    62,    62,
      62,    62,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     3,     1,     2,     4,     5,     2,
       6,     5,     2,     6,     5,     4,     8,     7,     5,     8,
       4,     7,     5,     8,     1,     3,     1,     1,     1,     1,
       1,     2,     4,     2,     4,     3,     5,     3,     5,     2,
       4,     1,     2,     3,     2,     3,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     4,     3,     4,     3,     1,     3,     5,
       7,     5,     9,     1,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 122 "syntax.y"
                          {printf("program corect sintactic\n");
							
								for(int i = 0; i < evalCounter; i++)
									printf("eval %d : valoarea expresiei : %s\n", i, evalInfo[i]);
							}
#line 1602 "y.tab.c"
    break;

  case 6:
#line 135 "syntax.y"
                                   { 
									if(!lookupVar((yyvsp[0].strVal)))
									{
										insertVar((yyvsp[-1].dataType), (yyvsp[0].strVal), "\0", Scope, false, false); 
									}
									else
									{
										DuplicateIdentifierError((yyvsp[0].strVal));
									}
								}
#line 1617 "y.tab.c"
    break;

  case 7:
#line 145 "syntax.y"
                                                       { 
		  											if(!lookupVar((yyvsp[-2].strVal)))
		  											{
		  												if(strcmp((yyvsp[-3].dataType), (yyvsp[0].info).type) == 0)
		  												{
			  												StringValue((yyvsp[0].info));
				  											insertVar((yyvsp[-3].dataType), (yyvsp[-2].strVal), AuxBuffer, Scope, true, false);
		  												}
		  												else
		  												{
		  													AssignementError((yyvsp[-2].strVal), (yyvsp[-3].dataType), (yyvsp[0].info).type);
		  												}
												
			  										}
			  										else
			  										{
			  											DuplicateIdentifierError((yyvsp[-2].strVal));
			  										}
					  								
		  										}
#line 1642 "y.tab.c"
    break;

  case 8:
#line 165 "syntax.y"
                                                    {
          													if(!lookupVar((yyvsp[-2].strVal)))
				  											{
				  												if(strcmp((yyvsp[-3].dataType), (yyvsp[0].info).type) == 0)
				  												{
					  												StringValue((yyvsp[0].info));
						  											insertVar((yyvsp[-3].dataType), (yyvsp[-2].strVal), AuxBuffer, Scope, true, true);
				  												}
				  												else
				  												{
				  													AssignementError((yyvsp[-2].strVal), (yyvsp[-3].dataType), (yyvsp[0].info).type);
				  												}
														
					  										}
					  										else
					  										{
					  											DuplicateIdentifierError((yyvsp[-2].strVal));
					  										}

          											}
#line 1667 "y.tab.c"
    break;

  case 9:
#line 185 "syntax.y"
                                {

          							char name[50];
          							strcpy(name, extractName((yyvsp[0].strVal)));
          							if(!lookupArray(name))
          							{
          								int maxSize =extractMaxSize((yyvsp[0].strVal));
          								insertArray((yyvsp[-1].dataType), name, maxSize, 0, arrayValues, Scope, false);
          							}
          							else
          							{
          								DuplicateIdentifierError((yyvsp[0].strVal));
          							}
          						}
#line 1686 "y.tab.c"
    break;

  case 10:
#line 199 "syntax.y"
                                                              {
          															if(!lookupArray((yyvsp[-4].strVal)))
								          							{
								          								if(strcmp(arrayValueType, (yyvsp[-5].dataType)) == 0)
								          								{
									          								char name[50];
									          								strcpy(name, extractName((yyvsp[-4].strVal)));

									          								int maxSize =extractMaxSize((yyvsp[-4].strVal));
									          								insertArray((yyvsp[-5].dataType), name, maxSize, arrayValuesCounter, arrayValues, Scope, false);

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
								          									AssignementError((yyvsp[-4].strVal), (yyvsp[-5].dataType), arrayValueType);
								          								}
								          							}
								          							else
								          							{
								          								DuplicateIdentifierError((yyvsp[-4].strVal));
								          							}		
          													  }
#line 1722 "y.tab.c"
    break;

  case 12:
#line 232 "syntax.y"
                                                                                          {/*conditie: primul identifier sa fie de tip caps*/}
#line 1728 "y.tab.c"
    break;

  case 13:
#line 233 "syntax.y"
                                                                                          {/*conditie: primul identifier sa fie de tip caps*/}
#line 1734 "y.tab.c"
    break;

  case 14:
#line 234 "syntax.y"
                                                           {

          													 if(!lookupFunction((yyvsp[-3].strVal), true))
          													 {

          													 	insertFunction((yyvsp[-4].dataType), (yyvsp[-3].strVal), nrOfFunctionParameters, FunctionParameters, Scope, true);

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
          													 	DuplicateIdentifierError((yyvsp[-3].strVal));
          													 }
          												   }
#line 1759 "y.tab.c"
    break;

  case 15:
#line 254 "syntax.y"
                                          {

											 if(!lookupFunction((yyvsp[-2].strVal), true))
											 {

											 	insertFunction((yyvsp[-3].dataType), (yyvsp[-2].strVal), nrOfFunctionParameters, FunctionParameters, Scope, true);

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
											 	DuplicateIdentifierError((yyvsp[-2].strVal));
											 }
		  								 }
#line 1784 "y.tab.c"
    break;

  case 16:
#line 275 "syntax.y"
                                                                                        {
	      																				if(!lookupFunction((yyvsp[-6].strVal), false))
							          													 {


							          													 	insertFunction((yyvsp[-7].dataType), (yyvsp[-6].strVal), nrOfFunctionParameters, FunctionParameters, Scope, false);
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
							          													 	DuplicateIdentifierError((yyvsp[-6].strVal));
							          													 }
								          												}
#line 1808 "y.tab.c"
    break;

  case 17:
#line 294 "syntax.y"
                                                                       {
		  															if(!lookupFunction((yyvsp[-5].strVal), false))
		          													 {


		          													 	insertFunction((yyvsp[-6].dataType), (yyvsp[-5].strVal), nrOfFunctionParameters, FunctionParameters, Scope, false);
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
		          													 	DuplicateIdentifierError((yyvsp[-5].strVal));
		          													 }
		  														}
#line 1832 "y.tab.c"
    break;

  case 18:
#line 313 "syntax.y"
                                                       {
          													if(!lookupFunction((yyvsp[-3].strVal), true))
															 {

															 	insertFunction((yyvsp[-4].dataType), (yyvsp[-3].strVal), nrOfFunctionParameters, FunctionParameters, Scope, true);

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
															 	DuplicateIdentifierError((yyvsp[-3].strVal));
															 }

          												}
#line 1857 "y.tab.c"
    break;

  case 19:
#line 333 "syntax.y"
                                                                             {
          																		if(!lookupFunction((yyvsp[-6].strVal), false))
						          													 {


						          													 	insertFunction((yyvsp[-7].dataType), (yyvsp[-6].strVal), nrOfFunctionParameters, FunctionParameters, Scope, false);
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
						          													 	DuplicateIdentifierError((yyvsp[-6].strVal));
						          													 }
          																		}
#line 1881 "y.tab.c"
    break;

  case 20:
#line 352 "syntax.y"
                                   {
          								 if(!lookupFunction((yyvsp[-2].strVal), true))
											 {

											 	insertFunction((yyvsp[-3].dataType), (yyvsp[-2].strVal), nrOfFunctionParameters, FunctionParameters, Scope, true);

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
											 	DuplicateIdentifierError((yyvsp[-2].strVal));
											 }
          						   }
#line 1905 "y.tab.c"
    break;

  case 21:
#line 371 "syntax.y"
                                                                {
          														if(!lookupFunction((yyvsp[-5].strVal), false))
		          													 {


		          													 	insertFunction((yyvsp[-6].dataType), (yyvsp[-5].strVal), nrOfFunctionParameters, FunctionParameters, Scope, false);
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
		          													 	DuplicateIdentifierError((yyvsp[-5].strVal));
		          													 }
          													}
#line 1929 "y.tab.c"
    break;

  case 22:
#line 390 "syntax.y"
                                                                        {/*conditie: primul identifier sa fie de tip caps*/}
#line 1935 "y.tab.c"
    break;

  case 23:
#line 391 "syntax.y"
                                                                                          {/*conditie: primul identifier sa fie de tip caps*/}
#line 1941 "y.tab.c"
    break;

  case 24:
#line 394 "syntax.y"
                        {
							bzero(arrayValueType, 10);
							strcpy(arrayValueType, (yyvsp[0].info).type);
							StringValue((yyvsp[0].info));
							strcpy(arrayValues[arrayValuesCounter++], AuxBuffer);
						}
#line 1952 "y.tab.c"
    break;

  case 25:
#line 401 "syntax.y"
                                                {
			   				if(firstArrayType)
			   				{
			   					bzero(arrayValueType, 10);
								strcpy(arrayValueType, (yyvsp[0].info).type);
								firstArrayType = false;

								StringValue((yyvsp[0].info));
								strcpy(arrayValues[arrayValuesCounter++], AuxBuffer);
			   				}
			   				else
			   				{
			   					if(strcmp(arrayValueType, (yyvsp[0].info).type) == 0)
			   					{
			   						StringValue((yyvsp[0].info));
									strcpy(arrayValues[arrayValuesCounter++], AuxBuffer);
			   					}
			   					else
			   					{
			   						ListTypesError();
			   					}
			   				}
			   			}
#line 1980 "y.tab.c"
    break;

  case 26:
#line 426 "syntax.y"
                          {(yyval.info).type="int", (yyval.info).intVal=(yyvsp[0].intVal);}
#line 1986 "y.tab.c"
    break;

  case 27:
#line 427 "syntax.y"
                                  {(yyval.info).type="float", (yyval.info).floatVal=(yyvsp[0].floatVal);}
#line 1992 "y.tab.c"
    break;

  case 28:
#line 428 "syntax.y"
                          {(yyval.info).type="char", (yyval.info).charVal=(yyvsp[0].charVal);}
#line 1998 "y.tab.c"
    break;

  case 29:
#line 429 "syntax.y"
                                  {(yyval.info).type="string", (yyval.info).strVal=(yyvsp[0].strVal);}
#line 2004 "y.tab.c"
    break;

  case 30:
#line 430 "syntax.y"
                                  {(yyval.info).type="bool", (yyval.info).intVal=(yyvsp[0].intVal);}
#line 2010 "y.tab.c"
    break;

  case 31:
#line 433 "syntax.y"
                                          {
										 	strcpy(FunctionParameters[nrOfFunctionParameters].type, (yyvsp[-1].dataType));
										 	strcpy(FunctionParameters[nrOfFunctionParameters++].identifier, (yyvsp[0].strVal));
										  }
#line 2019 "y.tab.c"
    break;

  case 32:
#line 438 "syntax.y"
                                                                        {
                   								strcpy(FunctionParameters[nrOfFunctionParameters].type, (yyvsp[-1].dataType));
										 		strcpy(FunctionParameters[nrOfFunctionParameters++].identifier, (yyvsp[0].strVal));
                   							}
#line 2028 "y.tab.c"
    break;

  case 39:
#line 449 "syntax.y"
                                                                                            {/*conditie: primul identifier sa fie de tip caps*/}
#line 2034 "y.tab.c"
    break;

  case 40:
#line 450 "syntax.y"
                                                                                             {/*conditie: primul identifier sa fie de tip caps*/}
#line 2040 "y.tab.c"
    break;

  case 49:
#line 467 "syntax.y"
                                  { 
          							intToString((yyvsp[-1].intVal));
          							strcpy(evalInfo[evalCounter++], AuxBuffer);
          						 }
#line 2049 "y.tab.c"
    break;

  case 50:
#line 471 "syntax.y"
                                     { 
          								if(lookupVar((yyvsp[-1].strVal)))
          								{
          									var* nod = getVar((yyvsp[-1].strVal));
          									printf("LINE: %d: type = %s | name = %s | value = %s | scope = %s| set = %d | used = %d | constant = %d\n" ,
													yylineno, nod->type, nod->name, nod->value, nod->scope, nod->set, nod->used, nod->constant);
          								}
          								else
          								{
          									UndeclaredVariableError((yyvsp[-1].strVal));
          								}
          							 }
#line 2066 "y.tab.c"
    break;

  case 51:
#line 483 "syntax.y"
                                        {
         									char name[10];
         									strcpy(name, extractName((yyvsp[-1].strVal)));
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
         										UndeclaredVariableError((yyvsp[-1].strVal));
         									}
         								}
#line 2096 "y.tab.c"
    break;

  case 52:
#line 508 "syntax.y"
                                        {printVarList();}
#line 2102 "y.tab.c"
    break;

  case 53:
#line 509 "syntax.y"
                                        {printArrayList();}
#line 2108 "y.tab.c"
    break;

  case 54:
#line 510 "syntax.y"
                                        {printFunctionList();}
#line 2114 "y.tab.c"
    break;

  case 55:
#line 514 "syntax.y"
                                                    {
														if(lookupVar((yyvsp[-2].strVal)))
														{
															var* actualVar = getVar((yyvsp[-2].strVal));
															char varType[10];
															strcpy(varType, actualVar->type);

															if(strcmp(actualVar->type, (yyvsp[0].info).type) == 0)
															{
																if(actualVar->constant != true)
																{
																	StringValue((yyvsp[0].info));
				  													strcpy(actualVar->value, AuxBuffer);
				  													actualVar->set = true;
																}
																else
																	ConstAsignementError((yyvsp[-2].strVal));
															}
															else
															{
																AssignementError((yyvsp[-2].strVal), actualVar->type, (yyvsp[0].info).type);
															}
														}
														else
														{
															UndeclaredVariableError((yyvsp[-2].strVal));
														}
												    }
#line 2147 "y.tab.c"
    break;

  case 56:
#line 542 "syntax.y"
                                               {
            										char name[50];
				          							strcpy(name, extractName((yyvsp[-2].strVal)));
				          							if(lookupArray(name))
				          							{
				          								int index = extractMaxSize((yyvsp[-2].strVal));
				          								array * nod = getArray(name);
				          								if(nod->actualSize <= index)
				          								{
				          									OutOfBoundError();
				          								}

				          								if(strcmp(nod->type, (yyvsp[0].info).type) == 0)
				          								{
				          									StringValue((yyvsp[0].info));
				          									strcpy(nod->values[index], AuxBuffer);
				          								}
				          								else
				          								{
				          									AssignementError((yyvsp[-2].strVal), nod->type, (yyvsp[0].info).type);
				          								}

				          									
				          							}
				          							else
				          							{
				          								UndeclaredVariableError(name);
				          							}
            								   }
#line 2181 "y.tab.c"
    break;

  case 58:
#line 574 "syntax.y"
                         {
								(yyval.info).type = (yyvsp[0].info).type;
								if(strcmp((yyvsp[0].info).type, "int") == 0)
								{
									(yyval.info).intVal = (yyvsp[0].info).intVal;
								}
								else if (strcmp((yyvsp[0].info).type, "float") == 0)
								{
									(yyval.info).intVal = (yyvsp[0].info).floatVal;
								}
								else if (strcmp((yyvsp[0].info).type, "bool") == 0)
								{
									(yyval.info).intVal = (yyvsp[0].info).intVal;
								}
								else if (strcmp((yyvsp[0].info).type, "char") == 0)
								{
									(yyval.info).charVal = (yyvsp[0].info).charVal;
								}
								else if (strcmp((yyvsp[0].info).type, "string") == 0)
								{
									(yyval.info).strVal = (yyvsp[0].info).strVal;
								}
						 }
#line 2209 "y.tab.c"
    break;

  case 59:
#line 597 "syntax.y"
                               {
                  					if(lookupVar((yyvsp[0].strVal)))
									{
										var* actualVar = getVar((yyvsp[0].strVal));
										if(actualVar->set == true)
										{
											(yyval.info).type = actualVar->type;
											if(strcmp(actualVar->type, "int") == 0)
											{
												(yyval.info).intVal = atoi(actualVar->value);
											}
											else if (strcmp(actualVar->type, "float") == 0)
											{
												(yyval.info).floatVal = atof(actualVar->value);
											}
											else if (strcmp(actualVar->type, "bool") == 0)
											{
												(yyval.info).intVal = atoi(actualVar->value);
											}
											else if (strcmp(actualVar->type, "char") == 0)
											{
												(yyval.info).charVal = actualVar->value[0];
											}
											else if (strcmp(actualVar->type, "string") == 0)
											{

												(yyval.info).strVal = actualVar->value;
											}
										}
										else
										{
											UsedButNotSetError((yyvsp[0].strVal));
										}
										
												
									}
									else
									{
										UndeclaredVariableError((yyvsp[0].strVal));
									}
                  			   }
#line 2255 "y.tab.c"
    break;

  case 60:
#line 638 "syntax.y"
                                                { ;}
#line 2261 "y.tab.c"
    break;

  case 61:
#line 639 "syntax.y"
                                        { 
                  						char name[50];
	          							strcpy(name, extractName((yyvsp[0].strVal)));
	          							if(lookupArray(name))
	          							{
	          								int index = extractMaxSize((yyvsp[0].strVal));
	          								array * nod = getArray(name);
	          								if(nod->actualSize <= index)
	          								{
	          									OutOfBoundError();
	          								}

	          								(yyval.info).type = nod->type;

	          								if(strcmp(nod->type, "int") == 0)
	          									(yyval.info).intVal = atoi(nod->values[index]);
	          								else if (strcmp(nod->type, "float") == 0)
	          								{
	          									(yyval.info).floatVal = atof(nod->values[index]);
	          								}else if (strcmp(nod->type, "bool") == 0)
	          								{
	          									(yyval.info).intVal = atoi(nod->values[index]);
	          								}
	          								else if (strcmp(nod->type, "char") == 0)
	          								{
	          									(yyval.info).charVal = nod->values[index][0];
	          								}else if (strcmp(nod->type, "string") == 0)
	          								{
	          									(yyval.info).strVal = nod->values[index];
	          								}	
	          							}
	          							else
	          							{
	          								UndeclaredVariableError(name);
	          							}
                   					}
#line 2302 "y.tab.c"
    break;

  case 62:
#line 675 "syntax.y"
                                        { 
                  						(yyval.info).type = (yyvsp[0].info).type;
                  						if(strcmp((yyval.info).type, "int") == 0)
          									(yyval.info).intVal = 0;
          								else if (strcmp((yyval.info).type, "float") == 0)
          								{
          									(yyval.info).floatVal = 0;
          								}else if (strcmp((yyval.info).type, "bool") == 0)
          								{
          									(yyval.info).intVal = 0;
          								}
          								else if (strcmp((yyval.info).type, "char") == 0)
          								{
          									(yyval.info).charVal = '\0';
          								}else if (strcmp((yyval.info).type, "string") == 0)
          								{
          									strcpy((yyval.info).strVal, "\0");
          								}

                  					}
#line 2327 "y.tab.c"
    break;

  case 63:
#line 695 "syntax.y"
                                                { 
                  									(yyval.info).type = (yyvsp[-1].info).type;
			          								if(strcmp((yyvsp[-1].info).type, "int") == 0)
			          									(yyval.info).intVal = (yyvsp[-1].info).intVal;
			          								else if (strcmp((yyvsp[-1].info).type, "float") == 0)
			          								{
			          									(yyval.info).floatVal = (yyvsp[-1].info).floatVal;
			          								}else if (strcmp((yyvsp[-1].info).type, "bool") == 0)
			          								{
			          									(yyval.info).intVal = (yyvsp[-1].info).intVal;
			          								}
			          								else if (strcmp((yyvsp[-1].info).type, "char") == 0)
			          								{
			          									(yyval.info).charVal = (yyvsp[-1].info).charVal;
			          								}else if (strcmp((yyvsp[-1].info).type, "string") == 0)
			          								{
			          									(yyval.info).strVal = (yyvsp[-1].info).strVal;
			          								}

			          								
;
                  								}
#line 2354 "y.tab.c"
    break;

  case 64:
#line 717 "syntax.y"
                                                          { 
               	  												if(strcmp((yyvsp[-2].info).type, (yyvsp[0].info).type)== 0)
               	  												{
               	  													if(strcmp((yyvsp[-2].info).type, "int") == 0)
               	  													{
               	  														(yyval.info).intVal = (yyvsp[-2].info).intVal + (yyvsp[0].info).intVal;
               	  														(yyval.info).type = (yyvsp[-2].info).type;
               	  													}else if(strcmp((yyvsp[-2].info).type, "float") == 0)
               	  													{
               	  														(yyval.info).floatVal = (yyvsp[-2].info).floatVal + (yyvsp[0].info).floatVal;
               	  														(yyval.info).type = (yyvsp[-2].info).type;
               	  													}else if (strcmp((yyvsp[-2].info).type, "string") == 0)
               	  													{
               	  														(yyval.info).strVal = (yyvsp[-2].info).strVal;
               	  														int length = strlen((yyval.info).strVal);
               	  														(yyval.info).strVal[length - 1] = '\0';
               	  														strcat((yyval.info).strVal, (yyvsp[0].info).strVal + 1);
               	  														(yyval.info).type = (yyvsp[-2].info).type;
               	  													}
               	  													else
               	  													{
               	  														OperatorError((yyvsp[-2].info).type);
               	  													}
               	  												}
               	  												else
               	  												{
               	  													OperationError();
               	  												}

               	  											}
#line 2389 "y.tab.c"
    break;

  case 65:
#line 748 "syntax.y"
                                                                                                        {
               	  												if(strcmp((yyvsp[-2].info).type, (yyvsp[0].info).type)== 0)
               	  												{
               	  													if(strcmp((yyvsp[-2].info).type, "int") == 0)
               	  													{
               	  														(yyval.info).intVal = (yyvsp[-2].info).intVal - (yyvsp[0].info).intVal;
               	  														(yyval.info).type = (yyvsp[-2].info).type;
               	  													}else if(strcmp((yyvsp[-2].info).type, "float") == 0)
               	  													{
               	  														(yyval.info).floatVal = (yyvsp[-2].info).floatVal - (yyvsp[0].info).floatVal;
               	  														(yyval.info).type = (yyvsp[-2].info).type;
               	  													}
               	  													else
               	  													{
               	  														OperatorError((yyvsp[-2].info).type);
               	  													}
               	  												}
               	  												else
               	  												{
               	  													OperationError();
               	  												}

               	  											}
#line 2417 "y.tab.c"
    break;

  case 66:
#line 771 "syntax.y"
                                                                {
               	  												if(strcmp((yyvsp[-2].info).type, (yyvsp[0].info).type)== 0)
               	  												{
               	  													if(strcmp((yyvsp[-2].info).type, "int") == 0)
               	  													{
               	  														(yyval.info).intVal = (yyvsp[-2].info).intVal * (yyvsp[0].info).intVal;
               	  														(yyval.info).type = (yyvsp[-2].info).type;
               	  													}else if(strcmp((yyvsp[-2].info).type, "float") == 0)
               	  													{
               	  														(yyval.info).floatVal = (yyvsp[-2].info).floatVal * (yyvsp[0].info).floatVal;
               	  														(yyval.info).type = (yyvsp[-2].info).type;
               	  													}
               	  													else
               	  													{
               	  														OperatorError((yyvsp[-2].info).type);
               	  													}
               	  												}
               	  												else
               	  												{
               	  													OperationError();
               	  												}

               	  											}
#line 2445 "y.tab.c"
    break;

  case 67:
#line 794 "syntax.y"
                                                                {
               	  												if(strcmp((yyvsp[-2].info).type, (yyvsp[0].info).type)== 0)
               	  												{
               	  													if(strcmp((yyvsp[-2].info).type, "int") == 0)
               	  													{
               	  														if((yyvsp[0].info).intVal != 0){
               	  															(yyval.info).intVal = (int)((yyvsp[-2].info).intVal / (yyvsp[0].info).intVal);
               	  															(yyval.info).type = (yyvsp[-2].info).type;
               	  														}
               	  														else
               	  														{
               	  															DivideZeroError();
               	  														}
               	  														
               	  													}else if(strcmp((yyvsp[-2].info).type, "float") == 0)
               	  													{
               	  														if((yyvsp[0].info).floatVal != 0){
               	  															(yyval.info).floatVal = (yyvsp[-2].info).floatVal / (yyvsp[0].info).floatVal;
               	  															(yyval.info).type = (yyvsp[-2].info).type;
               	  														}
               	  														else
               	  														{
               	  															DivideZeroError();
               	  														}
               	  														
               	  													}
               	  													else
               	  													{
               	  														OperatorError((yyvsp[-2].info).type);
               	  													}
               	  												}
               	  												else
               	  												{
               	  													OperationError();
               	  												}

               	  											}
#line 2487 "y.tab.c"
    break;

  case 68:
#line 832 "syntax.y"
                                                                {
	           	  												if(strcmp((yyvsp[-2].info).type, (yyvsp[0].info).type)== 0)
	           	  												{
	           	  													if(strcmp((yyvsp[-2].info).type, "int") == 0)
	           	  													{
	           	  														(yyval.info).intVal = (yyvsp[-2].info).intVal % (yyvsp[0].info).intVal;
	           	  														(yyval.info).type = (yyvsp[-2].info).type;
	           	  													}
	           	  													else
	           	  													{
	           	  														OperatorError((yyvsp[-2].info).type);
	           	  													}
	           	  												}
	           	  												else
	           	  												{
	           	  													OperationError();
	           	  												}
               	  											}
#line 2510 "y.tab.c"
    break;

  case 73:
#line 860 "syntax.y"
                                                                {
																if(lookupFunction((yyvsp[-3].strVal), false))
																{
																	

																	function* nod = getFunction((yyvsp[-3].strVal), false);

																	if(nod->nrOfParameters == parameterListCounter)
																	{

																		for(int i = 0; i < parameterListCounter; i++)
																		{
																			if(strcmp(parameterList[i].type, nod->parameters[i].type) != 0)
																			{
																				ParameterWrongTypeError((yyvsp[-3].strVal), i, parameterList[i].type, nod->parameters[i].type);
																			}																		
																		}
																		(yyval.info).type = nod->returnType;

																		if(strcmp((yyval.info).type, "int") == 0)
								          									(yyval.info).intVal = 0;
								          								else if (strcmp((yyval.info).type, "float") == 0)
								          								{
								          									(yyval.info).floatVal = 0;
								          								}else if (strcmp((yyval.info).type, "bool") == 0)
								          								{
								          									(yyval.info).intVal = 0;
								          								}
								          								else if (strcmp((yyval.info).type, "char") == 0)
								          								{
								          									(yyval.info).charVal = '\0';
								          								}else if (strcmp((yyval.info).type, "string") == 0)
								          								{
								          									strcpy((yyval.info).strVal, "\0");
								          								}

																		for(int i = 0; i < parameterListCounter; i++)
																		{
																			bzero(parameterList[i].type, 10);
																		}
																		parameterListCounter = 0;
																	}
																	else
																	{
																		ParameterNumberError((yyvsp[-3].strVal));
																	}
																}
																else
																{
																	UndefinedFunction((yyvsp[-3].strVal));
																}
															}
#line 2567 "y.tab.c"
    break;

  case 74:
#line 912 "syntax.y"
                                  {
              						if(lookupFunction((yyvsp[-2].strVal), false))
									{
																	

										function* nod = getFunction((yyvsp[-2].strVal), false);

										if(nod->nrOfParameters == parameterListCounter)
										{

											for(int i = 0; i < parameterListCounter; i++)
											{
												if(strcmp(parameterList[i].type, nod->parameters[i].type) != 0)
												{
													ParameterWrongTypeError((yyvsp[-2].strVal), i, parameterList[i].type, nod->parameters[i].type);
												}
											}

											(yyval.info).type = nod->returnType;

											if(strcmp((yyval.info).type, "int") == 0)
	          									(yyval.info).intVal = 0;
	          								else if (strcmp((yyval.info).type, "float") == 0)
	          								{
	          									(yyval.info).floatVal = 0;
	          								}else if (strcmp((yyval.info).type, "bool") == 0)
	          								{
	          									(yyval.info).intVal = 0;
	          								}
	          								else if (strcmp((yyval.info).type, "char") == 0)
	          								{
	          									(yyval.info).charVal = '\0';
	          								}else if (strcmp((yyval.info).type, "string") == 0)
	          								{
	          									strcpy((yyval.info).strVal, "\0");
	          								}


											for(int i = 0; i < parameterListCounter; i++)
											{
												bzero(parameterList[i].type, 10);
											}
											parameterListCounter = 0;
										}
										else
										{
											ParameterNumberError((yyvsp[-2].strVal));
										}
									}
									else
									{
										UndefinedFunction((yyvsp[-2].strVal));
									}	
              					  }
#line 2626 "y.tab.c"
    break;

  case 75:
#line 968 "syntax.y"
                                                        {;}
#line 2632 "y.tab.c"
    break;

  case 76:
#line 969 "syntax.y"
                                                                                {;}
#line 2638 "y.tab.c"
    break;

  case 77:
#line 972 "syntax.y"
                                                {
													parameterList[parameterListCounter].type = (yyvsp[0].info).type;

													if(strcmp((yyvsp[0].info).type, "int") == 0)
			          									parameterList[parameterListCounter++].intVal = (yyvsp[0].info).intVal;
			          								else if (strcmp((yyvsp[0].info).type, "float") == 0)
			          								{
			          									parameterList[parameterListCounter++].floatVal = (yyvsp[0].info).floatVal;
			          								}else if (strcmp((yyvsp[0].info).type, "bool") == 0)
			          								{
			          									parameterList[parameterListCounter++].intVal = (yyvsp[0].info).intVal;
			          								}
			          								else if (strcmp((yyvsp[0].info).type, "char") == 0)
			          								{
			          									parameterList[parameterListCounter++].charVal = (yyvsp[0].info).charVal;
			          								}else if (strcmp((yyvsp[0].info).type, "string") == 0)
			          								{
			          									parameterList[parameterListCounter++].strVal = (yyvsp[0].info).strVal;
			          								}
												}
#line 2663 "y.tab.c"
    break;

  case 78:
#line 992 "syntax.y"
                                                                       { 
					                        							parameterList[parameterListCounter].type = (yyvsp[0].info).type;

																		if(strcmp((yyvsp[0].info).type, "int") == 0)
								          									parameterList[parameterListCounter++].intVal = (yyvsp[0].info).intVal;
								          								else if (strcmp((yyvsp[0].info).type, "float") == 0)
								          								{
								          									parameterList[parameterListCounter++].floatVal = (yyvsp[0].info).floatVal;
								          								}else if (strcmp((yyvsp[0].info).type, "bool") == 0)
								          								{
								          									parameterList[parameterListCounter++].intVal = (yyvsp[0].info).intVal;
								          								}
								          								else if (strcmp((yyvsp[0].info).type, "char") == 0)
								          								{
								          									parameterList[parameterListCounter++].charVal = (yyvsp[0].info).charVal;
								          								}else if (strcmp((yyvsp[0].info).type, "string") == 0)
								          								{
								          									parameterList[parameterListCounter++].strVal = (yyvsp[0].info).strVal;
								          								}
								          							}
#line 2688 "y.tab.c"
    break;

  case 88:
#line 1030 "syntax.y"
                                        {(yyval.intVal)=(yyvsp[-2].intVal)+(yyvsp[0].intVal); }
#line 2694 "y.tab.c"
    break;

  case 89:
#line 1031 "syntax.y"
                                        {(yyval.intVal)=(yyvsp[-2].intVal)-(yyvsp[0].intVal); }
#line 2700 "y.tab.c"
    break;

  case 90:
#line 1032 "syntax.y"
                                        {(yyval.intVal)=(yyvsp[-2].intVal)*(yyvsp[0].intVal); }
#line 2706 "y.tab.c"
    break;

  case 91:
#line 1033 "syntax.y"
                                        {(yyval.intVal)=(yyvsp[-2].intVal)/(yyvsp[0].intVal); }
#line 2712 "y.tab.c"
    break;

  case 92:
#line 1034 "syntax.y"
                                        {(yyval.intVal)= (yyvsp[-1].intVal);}
#line 2718 "y.tab.c"
    break;

  case 93:
#line 1035 "syntax.y"
                                                        {(yyval.intVal)=(yyvsp[0].intVal);}
#line 2724 "y.tab.c"
    break;


#line 2728 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1038 "syntax.y"

void yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
