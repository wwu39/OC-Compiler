/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"


#include <assert.h>
#include <stdlib.h>
#include <string>
#include <cstring>

#include "astree.h"
#include "auxlib.h"
#include "lyutils.h"
#include "emit.h"

/* Line 371 of yacc.c  */
#line 81 "yyparse.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_VOID = 258,
     TOK_BOOL = 259,
     TOK_CHAR = 260,
     TOK_INT = 261,
     TOK_STRING = 262,
     TOK_IF = 263,
     TOK_ELSE = 264,
     TOK_WHILE = 265,
     TOK_RETURN = 266,
     TOK_STRUCT = 267,
     TOK_FALSE = 268,
     TOK_TRUE = 269,
     TOK_NULL = 270,
     TOK_NEW = 271,
     TOK_EQ = 272,
     TOK_NE = 273,
     TOK_LE = 274,
     TOK_GE = 275,
     TOK_ARRAY = 276,
     TOK_IDENT = 277,
     TOK_INTCON = 278,
     TOK_CHARCON = 279,
     TOK_STRINGCON = 280,
     TOK_ROOT = 281,
     TOK_BLOCK = 282,
     TOK_PARAMLIST = 283,
     TOK_DECLID = 284,
     TOK_FUNCTION = 285,
     TOK_TYPEID = 286,
     TOK_FIELD = 287,
     TOK_VARDECL = 288,
     TOK_IFELSE = 289,
     TOK_RETURNVOID = 290,
     TOK_NEWSTRING = 291,
     TOK_NEWARRAY = 292,
     TOK_INDEX = 293,
     TOK_PROTOTYPE = 294,
     TOK_CALL = 295,
     TOK_POS = 296,
     TOK_NEG = 297,
     TOK_CHR = 298,
     TOK_ORD = 299,
     PREC_UMINUS = 300,
     PREC_UPLUS = 301,
     PREC_CALL = 302,
     PREC_FIELD = 303,
     PREC_INDEX = 304,
     PREC_PAREN = 305
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 197 "yyparse.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   624

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    50,     2,     2,
      62,    63,    48,    46,    65,    47,    68,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
      45,    43,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    60,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    52,    53,
      54,    55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    23,
      26,    28,    30,    32,    34,    36,    40,    43,    49,    57,
      63,    68,    71,    73,    76,    78,    81,    85,    89,    93,
      97,   101,   105,   109,   113,   117,   121,   125,   129,   132,
     135,   138,   142,   144,   146,   148,   150,   154,   157,   161,
     165,   170,   176,   182,   184,   189,   193,   195,   197,   199,
     201,   203,   205,   210,   215,   219,   222,   225,   229,   231,
     233,   235,   237,   239,   241,   244,   248,   252,   255
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    71,    -1,    71,    72,    -1,    71,    85,
      -1,    71,    89,    -1,    71,     1,    60,    -1,    71,     1,
      61,    -1,    -1,    79,    61,    -1,    77,    -1,    76,    -1,
      75,    -1,    74,    -1,    73,    -1,    11,    79,    61,    -1,
      11,    61,    -1,     8,    62,    79,    63,    72,    -1,     8,
      62,    79,    63,    72,     9,    72,    -1,    10,    62,    79,
      63,    72,    -1,    87,    43,    79,    61,    -1,    78,    60,
      -1,    61,    -1,    78,    72,    -1,    64,    -1,    64,    72,
      -1,    79,    46,    79,    -1,    79,    47,    79,    -1,    79,
      48,    79,    -1,    79,    49,    79,    -1,    79,    50,    79,
      -1,    79,    17,    79,    -1,    79,    18,    79,    -1,    79,
      19,    79,    -1,    79,    20,    79,    -1,    79,    44,    79,
      -1,    79,    45,    79,    -1,    79,    43,    79,    -1,    47,
      79,    -1,    46,    79,    -1,    51,    79,    -1,    62,    79,
      63,    -1,    84,    -1,    83,    -1,    82,    -1,    80,    -1,
      22,    62,    63,    -1,    81,    63,    -1,    81,    65,    79,
      -1,    22,    62,    79,    -1,    16,    22,    62,    63,    -1,
      16,     7,    62,    79,    63,    -1,    16,    88,    66,    79,
      67,    -1,    22,    -1,    79,    66,    79,    67,    -1,    79,
      68,    22,    -1,    23,    -1,    25,    -1,    24,    -1,    14,
      -1,    13,    -1,    15,    -1,    87,    86,    63,    77,    -1,
      87,    62,    63,    77,    -1,    86,    65,    87,    -1,    62,
      87,    -1,    88,    22,    -1,    88,    21,    22,    -1,     3,
      -1,     4,    -1,     6,    -1,     5,    -1,     7,    -1,    22,
      -1,    90,    60,    -1,    90,    91,    61,    -1,    12,    22,
      64,    -1,    88,    22,    -1,    88,    21,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    48,    49,    50,    51,    52,    53,    57,
      58,    59,    60,    61,    62,    65,    67,    71,    73,    77,
      81,    86,    88,    92,    93,    95,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   113,
     115,   116,   117,   118,   119,   120,   123,   125,   128,   130,
     134,   136,   138,   142,   143,   145,   149,   150,   152,   153,
     154,   155,   158,   160,   165,   167,   172,   174,   178,   179,
     180,   181,   182,   183,   186,   189,   191,   195,   197
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_BOOL", "TOK_CHAR",
  "TOK_INT", "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_RETURN",
  "TOK_STRUCT", "TOK_FALSE", "TOK_TRUE", "TOK_NULL", "TOK_NEW", "TOK_EQ",
  "TOK_NE", "TOK_LE", "TOK_GE", "TOK_ARRAY", "TOK_IDENT", "TOK_INTCON",
  "TOK_CHARCON", "TOK_STRINGCON", "TOK_ROOT", "TOK_BLOCK", "TOK_PARAMLIST",
  "TOK_DECLID", "TOK_FUNCTION", "TOK_TYPEID", "TOK_FIELD", "TOK_VARDECL",
  "TOK_IFELSE", "TOK_RETURNVOID", "TOK_NEWSTRING", "TOK_NEWARRAY",
  "TOK_INDEX", "TOK_PROTOTYPE", "TOK_CALL", "TOK_POS", "TOK_NEG", "'='",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "TOK_CHR",
  "TOK_ORD", "PREC_UMINUS", "PREC_UPLUS", "PREC_CALL", "PREC_FIELD",
  "PREC_INDEX", "PREC_PAREN", "'}'", "';'", "'('", "')'", "'{'", "','",
  "'['", "']'", "'.'", "$accept", "start", "program", "statement",
  "returnstate", "ifelse", "whileloop", "vardecl", "block",
  "blockcontents", "expr", "call", "callargs", "allocator", "variable",
  "constant", "function", "funcargs", "identdecl", "basetype", "structdef",
  "structcont", "fielddecl", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    61,    62,    60,    43,    45,    42,    47,
      37,    33,   298,   299,   300,   301,   302,   303,   304,   305,
     125,    59,    40,    41,   123,    44,    91,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      76,    77,    77,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    89,    90,    90,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     2,
       1,     1,     1,     1,     1,     3,     2,     5,     7,     5,
       4,     2,     1,     2,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     1,     1,     1,     1,     3,     2,     3,     3,
       4,     5,     5,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     4,     4,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    68,    69,    71,    70,    72,
       0,     0,     0,     0,    60,    59,    61,     0,    53,    56,
      58,    57,     0,     0,     0,    22,     0,    24,     3,    14,
      13,    12,    11,    10,     0,     0,    45,     0,    44,    43,
      42,     4,     0,     0,     5,     0,     6,     7,     0,     0,
      53,    16,     0,     0,    72,    73,     0,     0,    39,    38,
      40,     0,    25,     0,    21,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,    47,     0,     0,     0,     0,     0,    66,    73,    74,
       0,     0,     0,     0,    15,    76,     0,     0,     0,    46,
      49,    41,    31,    32,    33,    34,    37,    35,    36,    26,
      27,    28,    29,    30,     0,    55,    48,     0,     0,    65,
       0,     0,    67,     0,    77,    75,     0,     0,     0,    50,
       0,    54,    20,    63,    62,    64,    78,    17,    19,    51,
      52,     0,    18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    85,    63,    43,
      44,    45,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
     -58,    32,   117,   -58,    23,   -58,   -58,   -58,   -58,   -58,
     -25,   -22,   521,    27,   -58,   -58,   -58,   104,   -16,   -58,
     -58,   -58,   562,   562,   562,   -58,   562,   241,   -58,   -58,
     -58,   -58,   -58,   -58,   179,   250,   -58,   -35,   -58,   -58,
     -58,   -58,   -28,    68,   -58,    19,   -58,   -58,   562,   562,
      -7,   -58,   289,     7,    12,    16,    15,    29,   -33,   -33,
     -33,   323,   -58,    42,   -58,   -58,   562,   562,   562,   562,
     562,   562,   562,   562,   562,   562,   562,   562,   -58,   562,
      65,   -58,   562,   562,    14,   -15,    71,   -58,   -58,   -58,
      81,    38,   334,   375,   -58,   -58,   562,    41,   562,   -58,
     513,   -58,    48,    48,    48,    48,   513,    48,    48,   -39,
     -39,   -33,   -33,   -33,   386,   -58,   513,   427,   -57,   -58,
     -57,   131,   -58,    83,   -58,   -58,   241,   241,   461,   -58,
     472,   -58,   -58,   -58,   -58,   -58,   -58,    97,   -58,   -58,
     -58,   241,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   -26,   -58,   -58,   -58,   -58,   -50,   -58,
     -10,   -58,   -58,   -58,   -58,   -58,   -58,   -58,    -2,   -14,
     -58,   -58,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -74
static const yytype_int16 yytable[] =
{
      42,    62,    52,    56,    25,   -73,   -73,    27,    65,    75,
      76,    77,    58,    59,    60,    83,    61,     5,     6,     7,
       8,     9,     5,     6,     7,     8,     9,    79,    81,    80,
      82,    90,     3,    79,    84,    80,    88,    48,    92,    93,
      49,    88,    14,    15,    16,    17,    57,   100,   120,    53,
     121,    50,    19,    20,    21,    57,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   133,   114,
     134,    95,   116,   117,    96,    22,    23,   118,    97,    89,
      24,    98,   119,    46,    47,    83,   128,   115,   130,    86,
      87,    26,    99,   122,    73,    74,    75,    76,    77,   125,
     137,   138,   123,   124,   129,   136,   141,     5,     6,     7,
       8,    54,     0,     0,    79,   142,    80,    -2,     4,   135,
       5,     6,     7,     8,     9,    10,    55,    11,    12,    13,
      14,    15,    16,    17,     5,     6,     7,     8,     9,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,    27,     5,     6,     7,     8,     9,    10,     0,    11,
      12,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      25,    26,     0,    27,     5,     6,     7,     8,     9,    10,
       0,    11,    12,     0,    14,    15,    16,    17,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,     0,
       0,     0,    24,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    25,    26,     0,    27,    66,    67,    68,    69,
       0,    78,     0,     0,     0,     0,    79,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
      94,    66,    67,    68,    69,    79,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,     0,   101,     0,     0,    79,
       0,    80,    66,    67,    68,    69,     0,   126,     0,     0,
      79,     0,    80,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,     0,   127,     0,
       0,    79,     0,    80,    66,    67,    68,    69,     0,     0,
       0,     0,    79,   131,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    66,    67,
      68,    69,     0,     0,     0,     0,     0,     0,   132,    66,
      67,    68,    69,    79,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,     0,   139,     0,     0,    79,     0,    80,
      66,    67,    68,    69,    14,    15,    16,    17,    79,   140,
      80,     0,     0,    50,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,     0,    22,    23,     0,
       0,     0,    24,     0,     0,    14,    15,    16,    17,    79,
       0,    80,    51,    26,    50,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       2,    27,    12,    17,    61,    21,    22,    64,    34,    48,
      49,    50,    22,    23,    24,    43,    26,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,    66,    63,    68,
      65,    45,     0,    66,    62,    68,    22,    62,    48,    49,
      62,    22,    13,    14,    15,    16,    62,    57,    63,    22,
      65,    22,    23,    24,    25,    62,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   118,    79,
     120,    64,    82,    83,    62,    46,    47,    63,    62,    60,
      51,    66,    84,    60,    61,    43,    96,    22,    98,    21,
      22,    62,    63,    22,    46,    47,    48,    49,    50,    61,
     126,   127,    21,    22,    63,    22,     9,     3,     4,     5,
       6,     7,    -1,    -1,    66,   141,    68,     0,     1,   121,
       3,     4,     5,     6,     7,     8,    22,    10,    11,    12,
      13,    14,    15,    16,     3,     4,     5,     6,     7,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    64,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    64,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    61,    62,    -1,    64,    17,    18,    19,    20,
      -1,    61,    -1,    -1,    -1,    -1,    66,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    17,    18,    19,    20,    66,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    63,    -1,    -1,    66,
      -1,    68,    17,    18,    19,    20,    -1,    63,    -1,    -1,
      66,    -1,    68,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    63,    -1,
      -1,    66,    -1,    68,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    61,    17,
      18,    19,    20,    66,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    63,    -1,    -1,    66,    -1,    68,
      17,    18,    19,    20,    13,    14,    15,    16,    66,    67,
      68,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    13,    14,    15,    16,    66,
      -1,    68,    61,    62,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    71,     0,     1,     3,     4,     5,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    22,    23,
      24,    25,    46,    47,    51,    61,    62,    64,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    87,    88,    89,    90,    60,    61,    62,    62,
      22,    61,    79,    22,     7,    22,    88,    62,    79,    79,
      79,    79,    72,    87,    60,    72,    17,    18,    19,    20,
      43,    44,    45,    46,    47,    48,    49,    50,    61,    66,
      68,    63,    65,    43,    62,    86,    21,    22,    22,    60,
      88,    91,    79,    79,    61,    64,    62,    62,    66,    63,
      79,    63,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    22,    79,    79,    63,    87,
      63,    65,    22,    21,    22,    61,    63,    63,    79,    63,
      79,    67,    61,    77,    77,    87,    22,    72,    72,    63,
      67,     9,    72
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = YYLEX;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 45 "parser.y"
    { yyparse_astree = (yyvsp[(1) - (1)]); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 48 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 49 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 50 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 51 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 52 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 53 "parser.y"
    { (yyval) = new astree { TOK_ROOT, 
                                           {0,0,0}, "\0" }; }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 57 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 58 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 66 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)])); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 68 "parser.y"
    { (yyvsp[(1) - (2)])->symbol = TOK_RETURNVOID; (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 72 "parser.y"
    { (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    { (yyval) = (yyvsp[(1) - (7)])->adopt((yyvsp[(3) - (7)]), (yyvsp[(5) - (7)])); (yyvsp[(1) - (7)])->adopt_sym((yyvsp[(7) - (7)]), TOK_IFELSE);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 78 "parser.y"
    { (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 82 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_VARDECL; (yyval) = (yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 87 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 89 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    { (yyvsp[(1) - (1)])->symbol = TOK_BLOCK; (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt_sym((yyvsp[(2) - (2)]), TOK_BLOCK); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 99 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 101 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 102 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 103 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 104 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 106 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 107 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 108 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 109 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 112 "parser.y"
    { (yyvsp[(1) - (2)])->symbol = TOK_NEG; (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    { (yyvsp[(1) - (2)])->symbol = TOK_POS; (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 115 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 118 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 124 "parser.y"
    { (yyvsp[(2) - (3)])->symbol = TOK_CALL; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)])); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 125 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 129 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)])); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 131 "parser.y"
    { (yyvsp[(2) - (3)])->symbol = TOK_CALL; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_TYPEID; (yyval) = (yyvsp[(1) - (4)])->adopt((yyvsp[(2) - (4)])); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 137 "parser.y"
    { (yyvsp[(1) - (5)])->symbol = TOK_NEWSTRING; (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(4) - (5)])); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    { (yyvsp[(1) - (5)])->symbol = TOK_NEWARRAY; (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 144 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_INDEX; (yyval) = (yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    { (yyvsp[(3) - (3)])->symbol = TOK_FIELD; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 149 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); emitter_register_string((yyvsp[(1) - (1)])); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 153 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 154 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 155 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 159 "parser.y"
    { (yyval) = tree_function((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_PARAMLIST; 
                (yyval) = tree_function((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 166 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)])); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 168 "parser.y"
    { (yyvsp[(1) - (2)])->symbol = TOK_PARAMLIST; 
                (yyval) = (yyvsp[(2) - (2)]) ? (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])) : (yyvsp[(1) - (2)]); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    { (yyvsp[(2) - (2)])->symbol = TOK_DECLID; (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    { (yyvsp[(3) - (3)])->symbol = TOK_DECLID; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 179 "parser.y"
    { (yyvsp[(1) - (1)])->symbol = TOK_INT; (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 181 "parser.y"
    { (yyvsp[(1) - (1)])->symbol = TOK_INT; (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    { (yyvsp[(1) - (1)])->symbol = TOK_TYPEID; (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)])); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    { (yyvsp[(2) - (3)])->symbol = TOK_TYPEID; (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)])); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 196 "parser.y"
    { (yyvsp[(2) - (2)])->symbol = TOK_FIELD; (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 198 "parser.y"
    { (yyvsp[(3) - (3)])->symbol = TOK_FIELD; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;


/* Line 1792 of yacc.c  */
#line 2025 "yyparse.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 201 "parser.y"


const char *parser::get_tname (int symbol) {
   const char *tname = yytname [YYTRANSLATE (symbol)];
   if (strstr (tname, "TOK_") == tname) tname += 4;
   return tname;
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

