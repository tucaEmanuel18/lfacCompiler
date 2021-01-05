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

char arrayValueType[10];
char arrayValues[20][20];
int arrayValuesCounter = 0;
bool firstArrayType = true;

// struct identifierList
// {
// 	char* name;
// 	char* value;
// 	char set;
// };


#line 124 "y.tab.c"

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



   

#line 242 "y.tab.c"

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
#define YYLAST   285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

#define YYUNDEFTOK  2
#define YYMAXUTOK   278


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
       2,     2,     2,    36,     2,     2,     2,    28,     2,     2,
      32,    33,    26,    24,    34,    25,    35,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   105,   105,   107,   108,   111,   114,   124,   144,   164,
     177,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   221,   227,   253,   254,   255,   256,   257,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   272,   273,
     276,   279,   280,   283,   284,   285,   286,   290,   291,   292,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   308,   309,   312,   313,   316,   317,   318,   319,   322,
     323,   327,   328,   329,   330,   333,   334,   335,   336,   339,
     342,   343,   344,   345,   346,   347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATA_TYPE", "USR_DATA_TYPE",
  "STRING_VALUE", "CHARACTER_VALUE", "INTEGER_VALUE", "FLOAT_VALUE",
  "BOOL_VALUE", "IDENTIFIER", "IF", "FOR", "WHILE", "ELSE", "EVAL",
  "ASSIGN", "RELATIONAL_OPERATOR", "BOOL_OPERATOR", "ARITHMETIC_OPERATOR",
  "ARRAY_ID", "ARRAY_PARAM_ID", "VOID", "CONST", "'+'", "'-'", "'*'",
  "'/'", "'%'", "';'", "'{'", "'}'", "'('", "')'", "','", "'.'", "'!'",
  "$accept", "CODE", "DECLARATIONS", "DECLARATION", "EXPRESSION",
  "LIST_OF_VALUES", "VALUE", "LIST_OF_PARAMETERS", "CODE_FUNCTION",
  "BLOCK", "STATEMENT_LIST", "STATEMENT", "ASSIGNEMENT",
  "BLOCK_EXPRESSION", "CAPS_ID", "ID", "FUNCTION_CALL",
  "LIST_OF_CALL_PARAMETERS", "CONTROL_STATEMENT", "CONDITION",
  "SMALL_CONDITION", "EVAL_EXP", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    42,    47,    37,    59,
     123,   125,    40,    41,    44,    46,    33
};
# endif

#define YYPACT_NINF (-139)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     131,    10,    38,    57,    61,    59,    75,   110,   107,  -139,
      34,   122,   125,    40,   152,   154,  -139,   170,   157,  -139,
    -139,   208,    71,   161,   131,   201,    71,    71,   217,   237,
      52,   222,   223,   224,   225,   242,   132,   230,  -139,     0,
     189,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
      97,   250,   258,    72,   208,    42,   208,    78,   204,   208,
     232,   119,    83,    19,   167,    19,     1,   119,  -139,   234,
    -139,   119,    90,   168,   168,  -139,  -139,  -139,   127,   235,
      98,   158,  -139,  -139,   192,   236,   238,  -139,   208,   193,
     229,   119,  -139,   194,   195,  -139,  -139,   194,   206,    19,
     239,   145,    36,  -139,   251,   240,    -4,    84,  -139,     1,
     174,   194,  -139,   194,  -139,   210,  -139,  -139,  -139,  -139,
    -139,  -139,   131,   146,   260,   269,  -139,   208,  -139,   131,
     131,   198,   169,   119,   119,   119,   119,   119,  -139,   119,
     133,    86,    19,   119,    19,   243,    19,   243,   179,     1,
       1,     1,     1,  -139,  -139,   110,   244,  -139,  -139,  -139,
     155,  -139,   245,   246,  -139,  -139,   183,    -5,   214,   252,
    -139,   194,  -139,   113,   194,  -139,   264,   150,  -139,  -139,
     209,   219,   247,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,   243,   167,  -139,   248,   243,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     9,     0,    13,     0,     0,     1,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,    64,     0,     0,    43,     0,
       0,    44,    45,     4,    26,    25,    23,    24,    27,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    40,     0,
      41,     0,     0,     0,     0,    28,    30,    36,     0,    15,
       0,     0,    21,    12,     0,    19,    17,     8,     0,    51,
      53,     0,    50,    47,    52,    54,    66,    69,     0,     0,
       0,     0,     0,    75,    63,     0,     0,     0,    85,     0,
       0,    48,    42,    49,    68,     0,    63,    64,    62,    61,
      32,    34,     0,     0,     0,     0,    10,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    67,    38,     0,    29,    31,    37,
       0,    22,     0,     0,    11,    55,    56,    57,    58,    59,
      60,    70,    77,     0,    79,    78,    71,     0,    73,    84,
      80,    81,    82,    83,    39,    16,    33,    35,    20,    18,
      76,     0,     0,    72,     0,     0,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,    13,    -6,  -139,   -45,   -18,   221,   120,  -138,
    -139,   249,   -62,   -57,   -17,   178,    27,   207,  -139,   -59,
    -139,   -91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,   155,     8,     9,    81,    92,    53,   156,    19,
      36,    37,    38,   101,    94,    40,    95,    98,    42,   102,
     103,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    18,   105,    49,    93,    97,   107,   176,   108,   178,
     111,    84,    71,     7,   113,    97,    71,   184,   148,    39,
      10,   135,   136,   137,    44,    45,    46,    47,    48,    89,
      11,    73,    72,   109,   132,    73,    82,    55,    82,    90,
     141,    87,   140,   131,    41,     1,     2,   106,    12,    18,
      21,    99,     3,   193,   144,   100,    25,   196,   180,   181,
     182,   183,    15,    41,     4,     5,    22,    13,    61,   145,
      82,    14,    26,    83,    50,    16,   166,   167,   168,   169,
     170,    51,   171,   173,    62,   175,   174,   177,    44,    45,
      46,    47,    48,    89,    52,    44,    45,    46,    47,    48,
      89,   123,   144,    90,   144,    79,    80,    75,   124,   161,
      90,    85,    80,     1,     2,    91,    96,   147,    76,   172,
       3,   125,    91,   114,    44,    45,    46,    47,    48,    89,
     194,   144,     4,     5,     1,     2,    20,   120,    23,    90,
      17,     3,    30,    31,    32,    33,   190,    34,   121,    18,
     143,    91,    35,     4,     5,    24,   157,   133,   134,   135,
     136,   137,   143,    68,    28,   186,   165,   158,   144,   133,
     134,   135,   136,   137,    29,   106,   187,   104,   116,   192,
      30,    31,    32,    33,    27,    34,    43,    35,   117,   126,
      35,    54,   127,   133,   134,   135,   136,   137,   149,   150,
     151,   152,   165,   149,   150,   151,   152,   153,   134,   135,
     136,   137,   179,    44,    45,    46,    47,    48,   133,   134,
     135,   136,   137,   128,    74,    62,   127,    72,   -63,   164,
      73,    56,   127,    59,   150,   151,   152,    86,    80,   138,
     139,   136,   137,   154,   139,   151,   152,    57,    58,   162,
     163,   118,   119,    60,    63,    64,    65,    66,    67,    70,
      77,    78,    88,   112,   -64,   122,   129,    61,   130,   146,
     159,   142,   160,    17,   152,   185,   188,   189,   191,   115,
     137,   195,     0,     0,     0,    69
};

static const yytype_int16 yycheck[] =
{
      17,     7,    64,    21,    61,    62,    65,   145,     7,   147,
      67,    56,    16,     0,    71,    72,    16,   155,   109,    36,
      10,    26,    27,    28,     5,     6,     7,     8,     9,    10,
      20,    35,    32,    32,    91,    35,    54,    24,    56,    20,
      99,    59,    99,    88,    17,     3,     4,    64,    10,    55,
      16,    32,    10,   191,    18,    36,    16,   195,   149,   150,
     151,   152,     3,    36,    22,    23,    32,    10,    16,    33,
      88,    10,    32,    31,     3,     0,   133,   134,   135,   136,
     137,    10,   139,   142,    32,   144,   143,   146,     5,     6,
       7,     8,     9,    10,    23,     5,     6,     7,     8,     9,
      10,     3,    18,    20,    18,    33,    34,    10,    10,   127,
      20,    33,    34,     3,     4,    32,    33,    33,    21,    33,
      10,    23,    32,    33,     5,     6,     7,     8,     9,    10,
     192,    18,    22,    23,     3,     4,    29,    10,    16,    20,
      30,    10,    10,    11,    12,    13,    33,    15,    21,   155,
      17,    32,    20,    22,    23,    30,    10,    24,    25,    26,
      27,    28,    17,    31,    10,    10,    33,    21,    18,    24,
      25,    26,    27,    28,    20,   192,    21,    10,    10,    29,
      10,    11,    12,    13,    32,    15,    29,    20,    20,    31,
      20,    30,    34,    24,    25,    26,    27,    28,    24,    25,
      26,    27,    33,    24,    25,    26,    27,    33,    25,    26,
      27,    28,    33,     5,     6,     7,     8,     9,    24,    25,
      26,    27,    28,    31,    35,    32,    34,    32,    35,    31,
      35,    30,    34,    16,    25,    26,    27,    33,    34,    33,
      34,    27,    28,    33,    34,    26,    27,    26,    27,   129,
     130,    73,    74,    16,    32,    32,    32,    32,    16,    29,
      10,     3,    30,    29,    35,    30,    30,    16,    30,    29,
      10,    32,     3,    30,    27,    31,    31,    31,    14,    72,
      28,    33,    -1,    -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    10,    22,    23,    38,    39,    40,    41,
      10,    20,    10,    10,    10,     3,     0,    30,    40,    46,
      29,    16,    32,    16,    30,    16,    32,    32,    10,    20,
      10,    11,    12,    13,    15,    20,    47,    48,    49,    51,
      52,    53,    55,    29,     5,     6,     7,     8,     9,    43,
       3,    10,    23,    44,    30,    39,    30,    44,    44,    16,
      16,    16,    32,    32,    32,    32,    32,    16,    31,    48,
      29,    16,    32,    35,    35,    10,    21,    10,     3,    33,
      34,    42,    43,    31,    42,    33,    33,    43,    30,    10,
      20,    32,    43,    50,    51,    53,    33,    50,    54,    32,
      36,    50,    56,    57,    10,    49,    51,    56,     7,    32,
      58,    50,    29,    50,    33,    54,    10,    20,    52,    52,
      10,    21,    30,     3,    10,    23,    31,    34,    31,    30,
      30,    42,    50,    24,    25,    26,    27,    28,    33,    34,
      50,    56,    32,    17,    18,    33,    29,    33,    58,    24,
      25,    26,    27,    33,    33,    39,    45,    10,    21,    10,
       3,    43,    45,    45,    31,    33,    50,    50,    50,    50,
      50,    50,    33,    56,    50,    56,    46,    56,    46,    33,
      58,    58,    58,    58,    46,    31,    10,    21,    31,    31,
      33,    14,    29,    46,    49,    33,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    42,    42,    43,    43,    43,    43,    43,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    45,    45,
      46,    47,    47,    48,    48,    48,    48,    49,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    55,    55,    55,    55,    56,    56,    56,    56,    57,
      58,    58,    58,    58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     3,     1,     2,     4,     5,     2,
       6,     7,     5,     2,     6,     5,     8,     5,     8,     5,
       8,     1,     3,     1,     1,     1,     1,     1,     2,     4,
       2,     4,     3,     5,     3,     5,     2,     4,     1,     2,
       3,     2,     3,     1,     1,     1,     4,     3,     3,     3,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     4,     3,     4,     3,     1,
       3,     5,     7,     5,     9,     1,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     1
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
#line 105 "syntax.y"
                          {printf("program corect sintactic\n"); printVarList(); printArrayList();}
#line 1560 "y.tab.c"
    break;

  case 6:
#line 114 "syntax.y"
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
#line 1575 "y.tab.c"
    break;

  case 7:
#line 124 "syntax.y"
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
#line 1600 "y.tab.c"
    break;

  case 8:
#line 144 "syntax.y"
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
#line 1625 "y.tab.c"
    break;

  case 9:
#line 164 "syntax.y"
                                {
          							if(!lookupArray((yyvsp[0].strVal)))
          							{
          								char name[50];
          								strcpy(name, extractName((yyvsp[0].strVal)));
          								int maxSize =extractMaxSize((yyvsp[0].strVal));
          								insertArray((yyvsp[-1].dataType), name, maxSize, 0, arrayValues, Scope, false);
          							}
          							else
          							{
          								DuplicateIdentifierError((yyvsp[0].strVal));
          							}
          						}
#line 1643 "y.tab.c"
    break;

  case 10:
#line 177 "syntax.y"
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
#line 1679 "y.tab.c"
    break;

  case 13:
#line 211 "syntax.y"
                                                                                          {/*conditie: primul identifier sa fie de tip caps*/}
#line 1685 "y.tab.c"
    break;

  case 14:
#line 212 "syntax.y"
                                                                                          {/*conditie: primul identifier sa fie de tip caps*/}
#line 1691 "y.tab.c"
    break;

  case 19:
#line 217 "syntax.y"
                                                                                          {/*conditie: primul identifier sa fie de tip caps*/}
#line 1697 "y.tab.c"
    break;

  case 20:
#line 218 "syntax.y"
                                                                                          {/*conditie: primul identifier sa fie de tip caps*/}
#line 1703 "y.tab.c"
    break;

  case 21:
#line 221 "syntax.y"
                        {
							bzero(arrayValueType, 10);
							strcpy(arrayValueType, (yyvsp[0].info).type);
							StringValue((yyvsp[0].info));
							strcpy(arrayValues[arrayValuesCounter++], AuxBuffer);
						}
#line 1714 "y.tab.c"
    break;

  case 22:
#line 228 "syntax.y"
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
#line 1742 "y.tab.c"
    break;

  case 23:
#line 253 "syntax.y"
                          {(yyval.info).type="int", (yyval.info).intVal=(yyvsp[0].intVal);}
#line 1748 "y.tab.c"
    break;

  case 24:
#line 254 "syntax.y"
                                  {(yyval.info).type="float", (yyval.info).floatVal=(yyvsp[0].floatVal);}
#line 1754 "y.tab.c"
    break;

  case 25:
#line 255 "syntax.y"
                          {(yyval.info).type="char", (yyval.info).charVal=(yyvsp[0].charVal);}
#line 1760 "y.tab.c"
    break;

  case 26:
#line 256 "syntax.y"
                                  {(yyval.info).type="string", (yyval.info).strVal=(yyvsp[0].strVal);}
#line 1766 "y.tab.c"
    break;

  case 27:
#line 257 "syntax.y"
                                  {(yyval.info).type="bool", (yyval.info).intVal=(yyvsp[0].intVal);}
#line 1772 "y.tab.c"
    break;

  case 36:
#line 268 "syntax.y"
                                                                                            {/*conditie: primul identifier sa fie de tip caps*/}
#line 1778 "y.tab.c"
    break;

  case 37:
#line 269 "syntax.y"
                                                                                             {/*conditie: primul identifier sa fie de tip caps*/}
#line 1784 "y.tab.c"
    break;

  case 46:
#line 286 "syntax.y"
                                  {printf("valoarea expresiei: %d\n", (yyvsp[-1].intVal));}
#line 1790 "y.tab.c"
    break;

  case 80:
#line 342 "syntax.y"
                                        {(yyval.intVal)=(yyvsp[-2].intVal)+(yyvsp[0].intVal); printf("e->e+e | %d + %d = %d ", (yyvsp[-2].intVal), (yyvsp[0].intVal), (yyval.intVal));}
#line 1796 "y.tab.c"
    break;

  case 81:
#line 343 "syntax.y"
                                        {(yyval.intVal)=(yyvsp[-2].intVal)-(yyvsp[0].intVal); printf("e->e-e | %d - %d = %d ", (yyvsp[-2].intVal), (yyvsp[0].intVal), (yyval.intVal));}
#line 1802 "y.tab.c"
    break;

  case 82:
#line 344 "syntax.y"
                                        {(yyval.intVal)=(yyvsp[-2].intVal)*(yyvsp[0].intVal); printf("e->e*e | %d * %d = %d ", (yyvsp[-2].intVal), (yyvsp[0].intVal), (yyval.intVal));}
#line 1808 "y.tab.c"
    break;

  case 83:
#line 345 "syntax.y"
                                        {(yyval.intVal)=(yyvsp[-2].intVal)/(yyvsp[0].intVal); printf("e->e/e | %d / %d = %d ", (yyvsp[-2].intVal), (yyvsp[0].intVal), (yyval.intVal));}
#line 1814 "y.tab.c"
    break;

  case 84:
#line 346 "syntax.y"
                                        {(yyval.intVal)= (yyvsp[-1].intVal);}
#line 1820 "y.tab.c"
    break;

  case 85:
#line 347 "syntax.y"
                                                        {(yyval.intVal)=(yyvsp[0].intVal);}
#line 1826 "y.tab.c"
    break;


#line 1830 "y.tab.c"

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
#line 350 "syntax.y"

void yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
