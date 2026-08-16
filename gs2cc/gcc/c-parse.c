/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     TYPENAME = 259,
     SCSPEC = 260,
     TYPESPEC = 261,
     TYPE_QUAL = 262,
     CONSTANT = 263,
     STRING = 264,
     ELLIPSIS = 265,
     SIZEOF = 266,
     ENUM = 267,
     STRUCT = 268,
     UNION = 269,
     IF = 270,
     ELSE = 271,
     WHILE = 272,
     DO = 273,
     FOR = 274,
     SWITCH = 275,
     CASE = 276,
     DEFAULT = 277,
     BREAK = 278,
     CONTINUE = 279,
     RETURN = 280,
     GOTO = 281,
     ASM_KEYWORD = 282,
     TYPEOF = 283,
     ALIGNOF = 284,
     ATTRIBUTE = 285,
     EXTENSION = 286,
     LABEL = 287,
     REALPART = 288,
     IMAGPART = 289,
     VA_ARG = 290,
     PTR_VALUE = 291,
     PTR_BASE = 292,
     PTR_EXTENT = 293,
     ASSIGN = 294,
     OROR = 295,
     ANDAND = 296,
     EQCOMPARE = 297,
     ARITHCOMPARE = 298,
     RSHIFT = 299,
     LSHIFT = 300,
     MINUSMINUS = 301,
     PLUSPLUS = 302,
     UNARY = 303,
     HYPERUNARY = 304,
     POINTSAT = 305,
     INTERFACE = 306,
     IMPLEMENTATION = 307,
     END = 308,
     SELECTOR = 309,
     DEFS = 310,
     ENCODE = 311,
     CLASSNAME = 312,
     PUBLIC = 313,
     PRIVATE = 314,
     PROTECTED = 315,
     PROTOCOL = 316,
     OBJECTNAME = 317,
     CLASS = 318,
     ALIAS = 319,
     OBJC_STRING = 320
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define TYPENAME 259
#define SCSPEC 260
#define TYPESPEC 261
#define TYPE_QUAL 262
#define CONSTANT 263
#define STRING 264
#define ELLIPSIS 265
#define SIZEOF 266
#define ENUM 267
#define STRUCT 268
#define UNION 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define DO 273
#define FOR 274
#define SWITCH 275
#define CASE 276
#define DEFAULT 277
#define BREAK 278
#define CONTINUE 279
#define RETURN 280
#define GOTO 281
#define ASM_KEYWORD 282
#define TYPEOF 283
#define ALIGNOF 284
#define ATTRIBUTE 285
#define EXTENSION 286
#define LABEL 287
#define REALPART 288
#define IMAGPART 289
#define VA_ARG 290
#define PTR_VALUE 291
#define PTR_BASE 292
#define PTR_EXTENT 293
#define ASSIGN 294
#define OROR 295
#define ANDAND 296
#define EQCOMPARE 297
#define ARITHCOMPARE 298
#define RSHIFT 299
#define LSHIFT 300
#define MINUSMINUS 301
#define PLUSPLUS 302
#define UNARY 303
#define HYPERUNARY 304
#define POINTSAT 305
#define INTERFACE 306
#define IMPLEMENTATION 307
#define END 308
#define SELECTOR 309
#define DEFS 310
#define ENCODE 311
#define CLASSNAME 312
#define PUBLIC 313
#define PRIVATE 314
#define PROTECTED 315
#define PROTOCOL 316
#define OBJECTNAME 317
#define CLASS 318
#define ALIAS 319
#define OBJC_STRING 320




/* Copy the first part of user declarations.  */
#line 34 "c-parse.y"

#include "config.h"
#include "system.h"
#include <setjmp.h>
#include "tree.h"
#include "input.h"
#include "cpplib.h"
#include "intl.h"
#include "timevar.h"
#include "c-lex.h"
#include "c-tree.h"
#include "c-pragma.h"
#include "flags.h"
#include "output.h"
#include "toplev.h"
#include "ggc.h"
  
#ifdef MULTIBYTE_CHARS
#include <locale.h>
#endif


/* Since parsers are distinct for each language, put the language string
   definition here.  */
const char * const language_string = "GNU C";

/* Like YYERROR but do call yyerror.  */
#define YYERROR1 { yyerror ("syntax error"); YYERROR; }

/* Cause the "yydebug" variable to be defined.  */
#define YYDEBUG 1

/* Rename the "yyparse" function so that we can override it elsewhere.  */
#define yyparse yyparse_1


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 72 "c-parse.y"
{long itype; tree ttype; enum tree_code code;
	const char *filename; int lineno; }
/* Line 193 of yacc.c.  */
#line 265 "c-p36620.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 192 "c-parse.y"

/* Number of statements (loosely speaking) and compound statements 
   seen so far.  */
static int stmt_count;
static int compstmt_count;
  
/* Input file and line number of the end of the body of last simple_if;
   used by the stmt-rule immediately after simple_if returns.  */
static const char *if_stmt_file;
static int if_stmt_line;

/* List of types and structure classes of the current declaration.  */
static tree current_declspecs = NULL_TREE;
static tree prefix_attributes = NULL_TREE;

/* Stack of saved values of current_declspecs and prefix_attributes.  */
static tree declspec_stack;

/* For __extension__, save/restore the warning flags which are
   controlled by __extension__.  */
#define SAVE_WARN_FLAGS()	\
	size_int (pedantic | (warn_pointer_arith << 1))
#define RESTORE_WARN_FLAGS(tval) \
  do {                                     \
    int val = tree_low_cst (tval, 0);      \
    pedantic = val & 1;                    \
    warn_pointer_arith = (val >> 1) & 1;   \
  } while (0)


/* Tell yyparse how to print a token's value, if yydebug is set.  */

#define YYPRINT(FILE,YYCHAR,YYLVAL) yyprint(FILE,YYCHAR,YYLVAL)

static void yyprint	  PARAMS ((FILE *, int, YYSTYPE));
static void yyerror	  PARAMS ((const char *));
static int yylexname	  PARAMS ((void));
static inline int _yylex  PARAMS ((void));
static int  yylex	  PARAMS ((void));
static void init_reswords PARAMS ((void));

/* Add GC roots for variables local to this file.  */
void
c_parse_init ()
{
  ggc_add_tree_root (&declspec_stack, 1);
  ggc_add_tree_root (&current_declspecs, 1);
  ggc_add_tree_root (&prefix_attributes, 1);
}



/* Line 216 of yacc.c.  */
#line 329 "c-p36620.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2563

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  167
/* YYNRULES -- Number of rules.  */
#define YYNRULES  426
/* YYNRULES -- Number of states.  */
#define YYNSTATES  729

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,     2,     2,     2,    56,    47,     2,
      62,    80,    54,    52,    85,    53,    61,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    81,
       2,    39,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    87,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,    45,    82,    83,     2,     2,     2,
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
      35,    36,    37,    38,    40,    43,    44,    48,    49,    50,
      51,    57,    58,    59,    60,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     7,    10,    11,    15,    17,
      19,    25,    28,    32,    37,    42,    45,    48,    51,    54,
      56,    57,    58,    68,    73,    74,    75,    85,    90,    91,
      92,   101,   105,   107,   109,   111,   113,   115,   117,   119,
     121,   123,   125,   126,   128,   130,   134,   136,   139,   142,
     145,   148,   151,   156,   159,   164,   167,   170,   172,   174,
     176,   181,   183,   187,   191,   195,   199,   203,   207,   211,
     215,   219,   223,   227,   231,   232,   237,   238,   243,   244,
     245,   253,   254,   260,   264,   268,   270,   272,   274,   275,
     283,   287,   291,   295,   299,   304,   311,   316,   320,   324,
     327,   330,   332,   335,   336,   338,   341,   345,   347,   349,
     352,   355,   360,   365,   368,   371,   375,   376,   377,   382,
     387,   391,   395,   398,   401,   404,   407,   411,   412,   415,
     418,   421,   424,   428,   429,   432,   435,   437,   439,   442,
     445,   447,   449,   452,   455,   458,   462,   463,   466,   468,
     470,   472,   477,   482,   484,   486,   488,   490,   494,   496,
     500,   501,   506,   507,   514,   518,   519,   526,   530,   531,
     533,   535,   538,   545,   547,   551,   552,   554,   559,   566,
     571,   573,   575,   577,   579,   581,   582,   587,   589,   590,
     593,   595,   599,   603,   606,   607,   612,   614,   615,   620,
     622,   624,   626,   629,   632,   638,   642,   643,   644,   652,
     653,   654,   662,   664,   666,   670,   674,   679,   683,   687,
     691,   693,   697,   702,   707,   711,   715,   719,   721,   725,
     729,   733,   738,   743,   747,   751,   753,   755,   758,   760,
     763,   765,   768,   769,   777,   783,   786,   787,   795,   801,
     804,   805,   814,   815,   823,   826,   827,   829,   830,   832,
     834,   837,   838,   842,   845,   849,   855,   859,   861,   863,
     866,   868,   872,   877,   884,   890,   892,   896,   898,   900,
     904,   905,   909,   912,   913,   915,   917,   920,   921,   924,
     928,   932,   935,   939,   944,   948,   951,   955,   958,   962,
     964,   966,   968,   970,   972,   975,   978,   981,   984,   986,
     989,   992,   995,   997,  1000,  1003,  1006,  1009,  1011,  1014,
    1016,  1018,  1020,  1022,  1025,  1026,  1027,  1028,  1029,  1030,
    1032,  1034,  1037,  1041,  1043,  1046,  1048,  1050,  1056,  1058,
    1060,  1063,  1066,  1069,  1072,  1077,  1078,  1083,  1084,  1085,
    1087,  1090,  1094,  1098,  1102,  1103,  1108,  1110,  1114,  1115,
    1116,  1124,  1130,  1133,  1134,  1135,  1136,  1137,  1150,  1151,
    1158,  1161,  1163,  1165,  1168,  1172,  1175,  1178,  1181,  1185,
    1192,  1201,  1212,  1225,  1229,  1234,  1236,  1240,  1246,  1249,
    1255,  1256,  1258,  1259,  1261,  1262,  1264,  1266,  1270,  1275,
    1277,  1281,  1282,  1285,  1288,  1289,  1294,  1297,  1298,  1300,
    1302,  1306,  1308,  1312,  1317,  1322,  1327,  1332,  1337,  1338,
    1341,  1343,  1346,  1348,  1352,  1354,  1358
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      89,     0,    -1,    -1,    90,    -1,    -1,    91,    93,    -1,
      -1,    90,    92,    93,    -1,    95,    -1,    94,    -1,    27,
      62,   104,    80,    81,    -1,   254,    93,    -1,   125,   139,
      81,    -1,   132,   125,   139,    81,    -1,   128,   125,   138,
      81,    -1,   132,    81,    -1,   128,    81,    -1,     1,    81,
      -1,     1,    82,    -1,    81,    -1,    -1,    -1,   128,   125,
     167,    96,   120,    97,   218,   219,   208,    -1,   128,   125,
     167,     1,    -1,    -1,    -1,   132,   125,   170,    98,   120,
      99,   218,   219,   208,    -1,   132,   125,   170,     1,    -1,
      -1,    -1,   125,   170,   100,   120,   101,   218,   219,   208,
      -1,   125,   170,     1,    -1,     3,    -1,     4,    -1,    47,
      -1,    53,    -1,    52,    -1,    58,    -1,    57,    -1,    83,
      -1,    84,    -1,   106,    -1,    -1,   106,    -1,   111,    -1,
     106,    85,   111,    -1,   117,    -1,    54,   110,    -1,   254,
     110,    -1,   103,   110,    -1,    44,   102,    -1,   108,   107,
      -1,   108,    62,   188,    80,    -1,   109,   107,    -1,   109,
      62,   188,    80,    -1,    33,   110,    -1,    34,   110,    -1,
      11,    -1,    29,    -1,   107,    -1,    62,   188,    80,   110,
      -1,   110,    -1,   111,    52,   111,    -1,   111,    53,   111,
      -1,   111,    54,   111,    -1,   111,    55,   111,    -1,   111,
      56,   111,    -1,   111,    51,   111,    -1,   111,    50,   111,
      -1,   111,    49,   111,    -1,   111,    48,   111,    -1,   111,
      47,   111,    -1,   111,    45,   111,    -1,   111,    46,   111,
      -1,    -1,   111,    44,   112,   111,    -1,    -1,   111,    43,
     113,   111,    -1,    -1,    -1,   111,    41,   114,   104,    42,
     115,   111,    -1,    -1,   111,    41,   116,    42,   111,    -1,
     111,    39,   111,    -1,   111,    40,   111,    -1,     3,    -1,
       8,    -1,   119,    -1,    -1,    62,   188,    80,    86,   118,
     153,    82,    -1,    62,   104,    80,    -1,    62,     1,    80,
      -1,   212,   210,    80,    -1,   212,     1,    80,    -1,   117,
      62,   105,    80,    -1,    35,    62,   111,    85,   188,    80,
      -1,   117,    63,   104,    87,    -1,   117,    61,   102,    -1,
     117,    64,   102,    -1,   117,    58,    -1,   117,    57,    -1,
       9,    -1,   119,     9,    -1,    -1,   122,    -1,   122,    10,
      -1,   218,   219,   123,    -1,   121,    -1,   200,    -1,   122,
     121,    -1,   121,   200,    -1,   130,   125,   138,    81,    -1,
     133,   125,   139,    81,    -1,   130,    81,    -1,   133,    81,
      -1,   218,   219,   127,    -1,    -1,    -1,   128,   125,   138,
      81,    -1,   132,   125,   139,    81,    -1,   128,   125,   161,
      -1,   132,   125,   164,    -1,   128,    81,    -1,   132,    81,
      -1,   254,   127,    -1,   136,   129,    -1,   132,   136,   129,
      -1,    -1,   129,   137,    -1,   129,     5,    -1,   129,   146,
      -1,   136,   131,    -1,   133,   136,   131,    -1,    -1,   131,
     137,    -1,   131,     5,    -1,   133,    -1,   146,    -1,   132,
     133,    -1,   132,   146,    -1,     7,    -1,     5,    -1,   133,
       7,    -1,   133,     5,    -1,   136,   135,    -1,   191,   136,
     135,    -1,    -1,   135,   137,    -1,     6,    -1,   174,    -1,
       4,    -1,    28,    62,   104,    80,    -1,    28,    62,   188,
      80,    -1,     6,    -1,     7,    -1,   174,    -1,   141,    -1,
     138,    85,   141,    -1,   143,    -1,   139,    85,   141,    -1,
      -1,    27,    62,   119,    80,    -1,    -1,   167,   140,   145,
      39,   142,   151,    -1,   167,   140,   145,    -1,    -1,   170,
     140,   145,    39,   144,   151,    -1,   170,   140,   145,    -1,
      -1,   146,    -1,   147,    -1,   146,   147,    -1,    30,    62,
      62,   148,    80,    80,    -1,   149,    -1,   148,    85,   149,
      -1,    -1,   150,    -1,   150,    62,     3,    80,    -1,   150,
      62,     3,    85,   106,    80,    -1,   150,    62,   105,    80,
      -1,   102,    -1,     5,    -1,     6,    -1,     7,    -1,   111,
      -1,    -1,    86,   152,   153,    82,    -1,     1,    -1,    -1,
     154,   179,    -1,   155,    -1,   154,    85,   155,    -1,   159,
      39,   157,    -1,   160,   157,    -1,    -1,   102,    42,   156,
     157,    -1,   157,    -1,    -1,    86,   158,   153,    82,    -1,
     111,    -1,     1,    -1,   160,    -1,   159,   160,    -1,    61,
     102,    -1,    63,   111,    10,   111,    87,    -1,    63,   111,
      87,    -1,    -1,    -1,   167,   162,   120,   163,   218,   219,
     213,    -1,    -1,    -1,   170,   165,   120,   166,   218,   219,
     213,    -1,   168,    -1,   170,    -1,    62,   168,    80,    -1,
     168,    62,   249,    -1,   168,    63,   104,    87,    -1,   168,
      63,    87,    -1,    54,   192,   168,    -1,   146,   126,   168,
      -1,     4,    -1,   169,    62,   249,    -1,   169,    63,    54,
      87,    -1,   169,    63,   104,    87,    -1,   169,    63,    87,
      -1,    54,   192,   169,    -1,   146,   126,   169,    -1,     4,
      -1,   170,    62,   249,    -1,    62,   170,    80,    -1,    54,
     192,   170,    -1,   170,    63,    54,    87,    -1,   170,    63,
     104,    87,    -1,   170,    63,    87,    -1,   146,   126,   170,
      -1,     3,    -1,    13,    -1,    13,   146,    -1,    14,    -1,
      14,   146,    -1,    12,    -1,    12,   146,    -1,    -1,   171,
     102,    86,   175,   181,    82,   145,    -1,   171,    86,   181,
      82,   145,    -1,   171,   102,    -1,    -1,   172,   102,    86,
     176,   181,    82,   145,    -1,   172,    86,   181,    82,   145,
      -1,   172,   102,    -1,    -1,   173,   102,    86,   177,   186,
     180,    82,   145,    -1,    -1,   173,    86,   178,   186,   180,
      82,   145,    -1,   173,   102,    -1,    -1,    85,    -1,    -1,
      85,    -1,   182,    -1,   182,   183,    -1,    -1,   182,   183,
      81,    -1,   182,    81,    -1,   134,   125,   184,    -1,   134,
     125,   218,   219,   145,    -1,   191,   125,   184,    -1,   191,
      -1,     1,    -1,   254,   183,    -1,   185,    -1,   184,    85,
     185,    -1,   218,   219,   167,   145,    -1,   218,   219,   167,
      42,   111,   145,    -1,   218,   219,    42,   111,   145,    -1,
     187,    -1,   186,    85,   187,    -1,     1,    -1,   102,    -1,
     102,    39,   111,    -1,    -1,   134,   189,   190,    -1,   191,
     190,    -1,    -1,   193,    -1,     7,    -1,   191,     7,    -1,
      -1,   192,     7,    -1,    62,   193,    80,    -1,    54,   192,
     193,    -1,    54,   192,    -1,   193,    62,   242,    -1,   193,
      63,   104,    87,    -1,   193,    63,    87,    -1,    62,   242,
      -1,    63,   104,    87,    -1,    63,    87,    -1,   146,   126,
     193,    -1,   195,    -1,   196,    -1,   197,    -1,   198,    -1,
     222,    -1,   195,   222,    -1,   196,   222,    -1,   197,   222,
      -1,   198,   222,    -1,   124,    -1,   195,   124,    -1,   196,
     124,    -1,   198,   124,    -1,   223,    -1,   195,   223,    -1,
     196,   223,    -1,   197,   223,    -1,   198,   223,    -1,   200,
      -1,   199,   200,    -1,   195,    -1,   196,    -1,   197,    -1,
     198,    -1,     1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
     206,    -1,   207,    -1,   206,   207,    -1,    32,   253,    81,
      -1,   213,    -1,     1,   213,    -1,    86,    -1,    82,    -1,
     201,   205,   211,    82,   202,    -1,   194,    -1,     1,    -1,
      62,    86,    -1,   209,   210,    -1,   215,   221,    -1,   215,
       1,    -1,    15,    62,   104,    80,    -1,    -1,    18,   217,
     221,    17,    -1,    -1,    -1,   222,    -1,   223,   220,    -1,
     203,   220,   204,    -1,   218,   219,   234,    -1,   218,   219,
     235,    -1,    -1,   214,    16,   225,   221,    -1,   214,    -1,
     214,    16,     1,    -1,    -1,    -1,    17,   226,    62,   104,
      80,   227,   221,    -1,   216,    62,   104,    80,    81,    -1,
     216,     1,    -1,    -1,    -1,    -1,    -1,    19,   228,    62,
     233,   229,   237,    81,   230,   237,    80,   231,   221,    -1,
      -1,    20,    62,   104,    80,   232,   221,    -1,   237,    81,
      -1,   127,    -1,   213,    -1,   104,    81,    -1,   203,   224,
     204,    -1,    23,    81,    -1,    24,    81,    -1,    25,    81,
      -1,    25,   104,    81,    -1,    27,   236,    62,   104,    80,
      81,    -1,    27,   236,    62,   104,    42,   238,    80,    81,
      -1,    27,   236,    62,   104,    42,   238,    42,   238,    80,
      81,    -1,    27,   236,    62,   104,    42,   238,    42,   238,
      42,   241,    80,    81,    -1,    26,   102,    81,    -1,    26,
      54,   104,    81,    -1,    81,    -1,    21,   111,    42,    -1,
      21,   111,    10,   111,    42,    -1,    22,    42,    -1,   102,
     218,   219,    42,   145,    -1,    -1,     7,    -1,    -1,   104,
      -1,    -1,   239,    -1,   240,    -1,   239,    85,   240,    -1,
       9,    62,   104,    80,    -1,   119,    -1,   241,    85,   119,
      -1,    -1,   243,   244,    -1,   246,    80,    -1,    -1,   247,
      81,   245,   244,    -1,     1,    80,    -1,    -1,    10,    -1,
     247,    -1,   247,    85,    10,    -1,   248,    -1,   247,    85,
     248,    -1,   128,   125,   169,   145,    -1,   128,   125,   170,
     145,    -1,   128,   125,   190,   145,    -1,   132,   125,   170,
     145,    -1,   132,   125,   190,   145,    -1,    -1,   250,   251,
      -1,   244,    -1,   252,    80,    -1,     3,    -1,   252,    85,
       3,    -1,   102,    -1,   253,    85,   102,    -1,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   246,   246,   250,   265,   265,   266,   266,   270,   271,
     272,   280,   285,   294,   298,   302,   304,   306,   307,   308,
     315,   320,   314,   328,   333,   338,   332,   346,   351,   356,
     350,   364,   371,   372,   375,   377,   379,   384,   386,   388,
     390,   394,   400,   401,   405,   407,   412,   413,   416,   419,
     423,   451,   457,   460,   463,   466,   468,   473,   477,   481,
     482,   495,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   516,   518,   521,   520,   527,   526,   533,   536,
     532,   542,   541,   551,   559,   571,   577,   578,   581,   580,
     609,   615,   617,   633,   640,   642,   644,   646,   650,   656,
     658,   664,   665,   682,   684,   685,   696,   701,   702,   703,
     704,   712,   716,   720,   723,   732,   741,   751,   755,   759,
     763,   767,   771,   773,   775,   785,   787,   792,   793,   795,
     800,   805,   807,   813,   814,   816,   829,   831,   833,   835,
     840,   843,   845,   848,   862,   864,   869,   870,   878,   879,
     880,   884,   886,   892,   893,   894,   898,   899,   903,   904,
     909,   910,   918,   917,   925,   934,   933,   942,   951,   952,
     957,   959,   964,   969,   971,   977,   978,   980,   982,   984,
     992,   993,   994,   995,  1001,  1003,  1002,  1006,  1013,  1015,
    1019,  1020,  1026,  1029,  1033,  1032,  1037,  1042,  1041,  1045,
    1047,  1051,  1052,  1056,  1061,  1065,  1071,  1083,  1070,  1101,
    1113,  1100,  1133,  1134,  1140,  1142,  1147,  1149,  1151,  1158,
    1160,  1169,  1174,  1179,  1181,  1183,  1190,  1192,  1199,  1204,
    1206,  1208,  1213,  1215,  1222,  1224,  1228,  1230,  1235,  1237,
    1242,  1244,  1250,  1249,  1255,  1259,  1262,  1261,  1265,  1269,
    1272,  1271,  1277,  1276,  1281,  1289,  1291,  1294,  1296,  1302,
    1304,  1310,  1311,  1313,  1328,  1333,  1346,  1351,  1356,  1358,
    1364,  1365,  1370,  1373,  1377,  1388,  1389,  1394,  1400,  1402,
    1408,  1407,  1411,  1417,  1418,  1422,  1424,  1430,  1431,  1436,
    1439,  1441,  1443,  1445,  1447,  1449,  1451,  1453,  1457,  1468,
    1469,  1470,  1474,  1478,  1479,  1480,  1481,  1482,  1486,  1487,
    1490,  1491,  1495,  1496,  1497,  1498,  1499,  1503,  1504,  1508,
    1509,  1510,  1511,  1514,  1518,  1525,  1529,  1545,  1559,  1561,
    1567,  1568,  1572,  1586,  1588,  1591,  1594,  1596,  1604,  1605,
    1609,  1625,  1632,  1637,  1641,  1654,  1653,  1673,  1679,  1685,
    1686,  1691,  1697,  1711,  1721,  1720,  1728,  1740,  1743,  1745,
    1742,  1750,  1753,  1756,  1760,  1763,  1766,  1755,  1770,  1769,
    1777,  1779,  1785,  1787,  1790,  1794,  1797,  1800,  1803,  1806,
    1829,  1833,  1838,  1842,  1854,  1860,  1868,  1871,  1874,  1877,
    1894,  1896,  1902,  1903,  1909,  1910,  1914,  1915,  1920,  1925,
    1927,  1934,  1934,  1944,  1946,  1945,  1955,  1962,  1963,  1973,
    1975,  1980,  1982,  1989,  1997,  2005,  2013,  2022,  2036,  2036,
    2046,  2047,  2057,  2059,  2065,  2067,  2072
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "TYPENAME", "SCSPEC",
  "TYPESPEC", "TYPE_QUAL", "CONSTANT", "STRING", "ELLIPSIS", "SIZEOF",
  "ENUM", "STRUCT", "UNION", "IF", "ELSE", "WHILE", "DO", "FOR", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN", "GOTO", "ASM_KEYWORD",
  "TYPEOF", "ALIGNOF", "ATTRIBUTE", "EXTENSION", "LABEL", "REALPART",
  "IMAGPART", "VA_ARG", "PTR_VALUE", "PTR_BASE", "PTR_EXTENT", "'='",
  "ASSIGN", "'?'", "':'", "OROR", "ANDAND", "'|'", "'^'", "'&'",
  "EQCOMPARE", "ARITHCOMPARE", "RSHIFT", "LSHIFT", "'+'", "'-'", "'*'",
  "'/'", "'%'", "MINUSMINUS", "PLUSPLUS", "UNARY", "HYPERUNARY", "'.'",
  "'('", "'['", "POINTSAT", "INTERFACE", "IMPLEMENTATION", "END",
  "SELECTOR", "DEFS", "ENCODE", "CLASSNAME", "PUBLIC", "PRIVATE",
  "PROTECTED", "PROTOCOL", "OBJECTNAME", "CLASS", "ALIAS", "OBJC_STRING",
  "')'", "';'", "'}'", "'~'", "'!'", "','", "'{'", "']'", "$accept",
  "program", "extdefs", "@1", "@2", "extdef", "datadef", "fndef", "@3",
  "@4", "@5", "@6", "@7", "@8", "identifier", "unop", "expr", "exprlist",
  "nonnull_exprlist", "unary_expr", "sizeof", "alignof", "cast_expr",
  "expr_no_commas", "@9", "@10", "@11", "@12", "@13", "primary", "@14",
  "string", "old_style_parm_decls", "lineno_datadecl", "datadecls",
  "datadecl", "lineno_decl", "setspecs", "setattrs", "decl",
  "typed_declspecs", "reserved_declspecs",
  "typed_declspecs_no_prefix_attr", "reserved_declspecs_no_prefix_attr",
  "declmods", "declmods_no_prefix_attr", "typed_typespecs",
  "reserved_typespecquals", "typespec", "typespecqual_reserved",
  "initdecls", "notype_initdecls", "maybeasm", "initdcl", "@15",
  "notype_initdcl", "@16", "maybe_attribute", "attributes", "attribute",
  "attribute_list", "attrib", "any_word", "init", "@17",
  "initlist_maybe_comma", "initlist1", "initelt", "@18", "initval", "@19",
  "designator_list", "designator", "nested_function", "@20", "@21",
  "notype_nested_function", "@22", "@23", "declarator",
  "after_type_declarator", "parm_declarator", "notype_declarator",
  "struct_head", "union_head", "enum_head", "structsp", "@24", "@25",
  "@26", "@27", "maybecomma", "maybecomma_warn", "component_decl_list",
  "component_decl_list2", "component_decl", "components",
  "component_declarator", "enumlist", "enumerator", "typename", "@28",
  "absdcl", "nonempty_type_quals", "type_quals", "absdcl1",
  "stmts_and_decls", "lineno_stmt_decl_or_labels_ending_stmt",
  "lineno_stmt_decl_or_labels_ending_decl",
  "lineno_stmt_decl_or_labels_ending_label",
  "lineno_stmt_decl_or_labels_ending_error", "lineno_stmt_decl_or_labels",
  "errstmt", "pushlevel", "poplevel", "c99_block_start", "c99_block_end",
  "maybe_label_decls", "label_decls", "label_decl", "compstmt_or_error",
  "compstmt_start", "compstmt_nostart", "compstmt_contents_nonempty",
  "compstmt_primary_start", "compstmt", "simple_if", "if_prefix",
  "do_stmt_start", "@29", "save_filename", "save_lineno",
  "lineno_labeled_stmt", "c99_block_lineno_labeled_stmt", "lineno_stmt",
  "lineno_label", "select_or_iter_stmt", "@30", "@31", "@32", "@33", "@34",
  "@35", "@36", "@37", "for_init_stmt", "stmt", "label", "maybe_type_qual",
  "xexpr", "asm_operands", "nonnull_asm_operands", "asm_operand",
  "asm_clobbers", "parmlist", "@38", "parmlist_1", "@39", "parmlist_2",
  "parms", "parm", "parmlist_or_identifiers", "@40",
  "parmlist_or_identifiers_1", "identifiers", "identifiers_or_typenames",
  "extension", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    61,
     294,    63,    58,   295,   296,   124,    94,    38,   297,   298,
     299,   300,    43,    45,    42,    47,    37,   301,   302,   303,
     304,    46,    40,    91,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
      41,    59,   125,   126,    33,    44,   123,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    91,    90,    92,    90,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      96,    97,    95,    95,    98,    99,    95,    95,   100,   101,
      95,    95,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   104,   105,   105,   106,   106,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   108,   109,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   111,   113,   111,   114,   115,
     111,   116,   111,   111,   111,   117,   117,   117,   118,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   119,   119,   120,   120,   120,   121,   122,   122,   122,
     122,   123,   123,   123,   123,   124,   125,   126,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   129,   129,   129,
     129,   130,   130,   131,   131,   131,   132,   132,   132,   132,
     133,   133,   133,   133,   134,   134,   135,   135,   136,   136,
     136,   136,   136,   137,   137,   137,   138,   138,   139,   139,
     140,   140,   142,   141,   141,   144,   143,   143,   145,   145,
     146,   146,   147,   148,   148,   149,   149,   149,   149,   149,
     150,   150,   150,   150,   151,   152,   151,   151,   153,   153,
     154,   154,   155,   155,   156,   155,   155,   158,   157,   157,
     157,   159,   159,   160,   160,   160,   162,   163,   161,   165,
     166,   164,   167,   167,   168,   168,   168,   168,   168,   168,
     168,   169,   169,   169,   169,   169,   169,   169,   170,   170,
     170,   170,   170,   170,   170,   170,   171,   171,   172,   172,
     173,   173,   175,   174,   174,   174,   176,   174,   174,   174,
     177,   174,   178,   174,   174,   179,   179,   180,   180,   181,
     181,   182,   182,   182,   183,   183,   183,   183,   183,   183,
     184,   184,   185,   185,   185,   186,   186,   186,   187,   187,
     189,   188,   188,   190,   190,   191,   191,   192,   192,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   194,
     194,   194,   194,   195,   195,   195,   195,   195,   196,   196,
     196,   196,   197,   197,   197,   197,   197,   198,   198,   199,
     199,   199,   199,   200,   201,   202,   203,   204,   205,   205,
     206,   206,   207,   208,   208,   209,   210,   210,   211,   211,
     212,   213,   214,   214,   215,   217,   216,   218,   219,   220,
     220,   221,   222,   223,   225,   224,   224,   224,   226,   227,
     224,   224,   224,   228,   229,   230,   231,   224,   232,   224,
     233,   233,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   235,   235,   235,   235,
     236,   236,   237,   237,   238,   238,   239,   239,   240,   241,
     241,   243,   242,   244,   245,   244,   244,   246,   246,   246,
     246,   247,   247,   248,   248,   248,   248,   248,   250,   249,
     251,   251,   252,   252,   253,   253,   254
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     0,     2,     0,     3,     1,     1,
       5,     2,     3,     4,     4,     2,     2,     2,     2,     1,
       0,     0,     9,     4,     0,     0,     9,     4,     0,     0,
       8,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     3,     1,     2,     2,     2,
       2,     2,     4,     2,     4,     2,     2,     1,     1,     1,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     4,     0,     4,     0,     0,
       7,     0,     5,     3,     3,     1,     1,     1,     0,     7,
       3,     3,     3,     3,     4,     6,     4,     3,     3,     2,
       2,     1,     2,     0,     1,     2,     3,     1,     1,     2,
       2,     4,     4,     2,     2,     3,     0,     0,     4,     4,
       3,     3,     2,     2,     2,     2,     3,     0,     2,     2,
       2,     2,     3,     0,     2,     2,     1,     1,     2,     2,
       1,     1,     2,     2,     2,     3,     0,     2,     1,     1,
       1,     4,     4,     1,     1,     1,     1,     3,     1,     3,
       0,     4,     0,     6,     3,     0,     6,     3,     0,     1,
       1,     2,     6,     1,     3,     0,     1,     4,     6,     4,
       1,     1,     1,     1,     1,     0,     4,     1,     0,     2,
       1,     3,     3,     2,     0,     4,     1,     0,     4,     1,
       1,     1,     2,     2,     5,     3,     0,     0,     7,     0,
       0,     7,     1,     1,     3,     3,     4,     3,     3,     3,
       1,     3,     4,     4,     3,     3,     3,     1,     3,     3,
       3,     4,     4,     3,     3,     1,     1,     2,     1,     2,
       1,     2,     0,     7,     5,     2,     0,     7,     5,     2,
       0,     8,     0,     7,     2,     0,     1,     0,     1,     1,
       2,     0,     3,     2,     3,     5,     3,     1,     1,     2,
       1,     3,     4,     6,     5,     1,     3,     1,     1,     3,
       0,     3,     2,     0,     1,     1,     2,     0,     2,     3,
       3,     2,     3,     4,     3,     2,     3,     2,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     1,     2,     2,     2,     2,     1,     2,     1,
       1,     1,     1,     2,     0,     0,     0,     0,     0,     1,
       1,     2,     3,     1,     2,     1,     1,     5,     1,     1,
       2,     2,     2,     2,     4,     0,     4,     0,     0,     1,
       2,     3,     3,     3,     0,     4,     1,     3,     0,     0,
       7,     5,     2,     0,     0,     0,     0,    12,     0,     6,
       2,     1,     1,     2,     3,     2,     2,     2,     3,     6,
       8,    10,    12,     3,     4,     1,     3,     5,     2,     5,
       0,     1,     0,     1,     0,     1,     1,     3,     4,     1,
       3,     0,     2,     2,     0,     4,     2,     0,     1,     1,
       3,     1,     3,     4,     4,     4,     4,     4,     0,     2,
       1,     2,     1,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     6,     0,     1,     0,     0,   150,   141,   148,
     140,   240,   236,   238,     0,     0,     0,   426,    19,     5,
       9,     8,     0,   116,   116,   136,   127,   137,   170,     0,
       0,     0,   149,     0,     7,    17,    18,   241,   237,   239,
       0,     0,     0,   235,   287,     0,     0,   158,   117,     0,
      16,     0,    15,     0,   138,   127,   139,   143,   142,   125,
     171,    32,    33,   261,   245,   261,   249,   252,   254,    11,
      85,    86,   101,    57,    58,     0,     0,     0,     0,    34,
      36,    35,     0,    38,    37,     0,    39,    40,     0,     0,
      41,    59,     0,     0,    61,    44,    46,    87,     0,     0,
     285,     0,   280,   146,     0,   283,   175,     0,     0,    12,
       0,     0,    31,     0,   418,     0,     0,   168,   220,   287,
       0,     0,   156,   117,     0,   212,   213,     0,     0,   126,
     129,   153,   154,   128,   130,   155,     0,     0,   242,     0,
     246,     0,   250,    55,    56,     0,    50,    47,     0,   340,
       0,     0,    49,     0,     0,     0,    51,     0,    53,     0,
       0,    78,    76,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,    99,     0,    42,
       0,     0,   102,     0,   336,   328,     0,    48,   151,   283,
     144,   152,   286,   287,   401,     0,   146,   117,   282,   284,
     181,   182,   183,   180,     0,   173,   176,   288,   230,   229,
     159,   160,   234,     0,   228,     0,     0,   233,     0,     0,
      29,     0,   347,   108,   348,   167,   169,     0,     0,    14,
       0,     0,    23,     0,   168,   418,     0,    13,    27,     0,
     168,   268,   263,   116,   260,   116,     0,   261,   168,   261,
     277,   278,   257,   275,     0,     0,    91,    90,     0,    10,
      45,     0,     0,    83,    84,     0,     0,     0,     0,    72,
      73,    71,    70,    69,    68,    67,    62,    63,    64,    65,
      66,    97,     0,    43,     0,    98,    93,     0,     0,   329,
     330,    92,   281,   147,   291,     0,   295,     0,   297,     0,
     145,     0,   401,     0,     0,   175,    42,     0,     0,   422,
     408,   116,   116,   420,     0,   409,   411,   419,     0,   231,
     232,   323,   347,   110,   105,   109,     0,   165,   218,   214,
     157,   219,    21,   164,   215,   217,     0,    25,   244,   347,
     262,   347,   269,     0,   248,     0,     0,   258,     0,   257,
       0,    88,    60,    52,    54,     0,     0,    77,    75,    94,
      96,   424,     0,   339,   308,   338,   347,   347,   347,   347,
       0,   317,     0,   348,   303,   312,   331,   290,   289,   402,
     296,   298,   292,   294,     0,   172,   174,    85,     0,   161,
     406,   283,   283,   403,   404,     0,   421,     0,   348,   106,
     116,   116,   133,     0,   347,   162,   216,   347,   264,   270,
     348,   266,   348,   168,   168,   279,   276,   168,     0,     0,
       0,    79,    82,   332,     0,   309,   304,   313,   310,   305,
     314,   348,   306,   315,   311,   307,   316,   318,   325,   326,
     293,   177,     0,   179,   227,   287,   401,   117,   168,   168,
     168,   287,   117,   168,   168,     0,   410,   412,   423,     0,
     113,     0,   114,     0,   133,   131,   187,   185,   184,   166,
     348,     0,   348,   347,   168,     0,   243,   247,   253,   168,
      95,   200,    85,     0,     0,   197,     0,   199,     0,   255,
     190,   196,     0,     0,     0,   425,   326,   337,   150,     0,
       0,     0,     0,     0,     0,   390,   385,   335,   347,     0,
     115,   116,   116,     0,   324,   372,   352,   353,     0,     0,
     291,     0,   418,     0,   413,   414,   415,   291,     0,   416,
     417,   405,     0,    30,   333,     0,     0,   160,   132,   135,
     134,     0,     0,   163,     0,   271,     0,   265,   117,   168,
     251,   203,     0,     0,   194,    89,     0,   189,     0,   202,
     193,    80,     0,   388,   375,   376,   377,     0,     0,     0,
     391,     0,   348,   373,   122,     0,   123,     0,     0,   358,
     345,   363,     0,   356,     0,     0,   327,   341,   124,   178,
     225,   226,   221,     0,   224,     0,   334,   111,   112,     0,
      22,    26,   168,     0,   272,     0,   205,     0,     0,   191,
     192,     0,   386,   378,     0,   383,     0,     0,     0,   120,
     206,     0,   121,   209,     0,     0,   326,     0,     0,     0,
     343,   347,   342,   362,     0,   374,   222,   223,   186,   274,
     168,     0,   198,   195,     0,   384,     0,   168,   118,     0,
     119,     0,     0,     0,     0,   392,     0,   357,   326,   327,
     349,   347,     0,   273,   204,   387,   394,     0,   389,   207,
     210,   344,     0,   346,   393,   371,   364,     0,   368,   355,
     351,   350,     0,     0,     0,   395,   396,   379,   347,   347,
     359,   392,   370,   326,   361,     0,   394,     0,     0,   348,
     348,   326,     0,   369,     0,     0,   380,   397,     0,     0,
     360,   365,   398,     0,     0,   208,   211,   392,   399,     0,
     381,     0,     0,     0,   366,   382,   400,   326,   367
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,     5,    19,    20,    21,   233,   404,
     239,   407,   116,   322,   486,    88,   150,   282,    90,    91,
      92,    93,    94,    95,   268,   267,   265,   494,   266,    96,
     420,    97,   220,   221,   222,   399,   364,    22,   231,   510,
     311,    59,   400,   465,   312,    25,   102,   190,    26,   133,
     121,    46,   117,   122,   471,    47,   403,   225,   226,    28,
     204,   205,   206,   469,   541,   488,   489,   490,   608,   491,
     553,   492,   493,   619,   649,   688,   622,   651,   689,   211,
     125,   448,   126,    29,    30,    31,    32,   247,   249,   254,
     141,   557,   348,   136,   137,   244,   408,   409,   252,   253,
     104,   189,   198,   105,   107,   199,   365,   366,   367,   368,
     369,   370,   223,   185,   497,   631,   635,   288,   289,   290,
     533,   514,   186,   372,    98,   534,   583,   584,   585,   626,
     224,   326,   659,   632,   660,   661,   586,   658,   625,   701,
     627,   691,   717,   727,   693,   676,   516,   517,   571,   677,
     684,   685,   686,   719,   296,   297,   313,   455,   314,   315,
     316,   214,   215,   317,   318,   362,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -588
static const yytype_int16 yypact[] =
{
      87,    97,   120,  2373,  -588,  2373,    46,  -588,  -588,  -588,
    -588,    21,    21,    21,    84,   117,   154,  -588,  -588,  -588,
    -588,  -588,   206,    68,   756,   180,  -588,    21,  -588,    67,
      81,   108,  -588,  2373,  -588,  -588,  -588,    21,    21,    21,
    2211,  2121,   157,  -588,  -588,   206,    36,  -588,    21,  1378,
    -588,   291,  -588,   206,   180,  -588,    21,  -588,  -588,   760,
    -588,  -588,  -588,  -588,    78,  -588,    96,  -588,   158,  -588,
    -588,  -588,  -588,  -588,  -588,  2211,  2211,   185,   344,  -588,
    -588,  -588,  2211,  -588,  -588,  1117,  -588,  -588,  2211,   177,
     182,  -588,  2245,  2279,  -588,  2507,   569,   264,   801,  2211,
    -588,   202,  -588,  -588,   210,  1653,   615,   444,   127,  -588,
     291,   206,  -588,   214,  -588,  1473,   483,    21,  -588,  -588,
     291,   257,  -588,    21,  1461,   339,   450,   258,  1430,   760,
    -588,  -588,  -588,  -588,    21,  -588,   219,   706,  -588,   228,
    -588,   571,  -588,  -588,  -588,  2211,  -588,  -588,   223,  -588,
     237,   240,  -588,   242,  2211,  1117,  -588,  1117,  -588,  2211,
    2211,   290,  -588,  -588,  2211,  2211,  2211,  2211,  2211,  2211,
    2211,  2211,  2211,  2211,  2211,  2211,  -588,  -588,   344,  2211,
    2211,   344,  -588,   270,  -588,   323,   300,  -588,  -588,   361,
     540,  -588,  -588,  -588,   361,  1530,  -588,    21,  -588,   481,
    -588,  -588,  -588,  -588,   168,  -588,   320,  -588,   450,  -588,
    -588,   363,   450,   379,  -588,  1009,  1587,  -588,   309,   325,
    -588,   321,    72,  -588,  -588,   373,    21,   432,   307,  -588,
     291,   291,  -588,   483,    21,  -588,  1644,  -588,  -588,   483,
      21,  -588,  -588,  -588,   340,   372,   837,  -588,    21,  -588,
    -588,   392,   355,  -588,   571,  2442,  -588,  -588,  2004,  -588,
    2507,   370,   375,  2507,  2507,  2211,   401,  2211,  2211,  2090,
    1670,  2175,  1044,   727,  1080,  1080,   531,   531,  -588,  -588,
    -588,  -588,   385,   182,   365,  -588,  -588,   344,   889,   323,
    -588,  -588,  -588,  -588,   407,   354,  -588,  1596,  -588,   386,
     540,   361,  -588,  1701,   396,   615,  2313,    65,   402,  -588,
    -588,  -588,  1039,  -588,   405,   296,  -588,  -588,   186,  -588,
    -588,  -588,  -588,  -588,  -588,  -588,  1185,  -588,   339,  -588,
    -588,   339,  -588,   452,  -588,  -588,   406,  -588,  -588,  -588,
    -588,  -588,  -588,   436,  -588,   445,  2211,   344,   457,   355,
     860,  -588,  -588,   471,   471,   535,  2211,  1783,  1971,  -588,
    -588,  -588,   328,   325,  -588,  -588,    89,    94,    99,   101,
     558,  -588,   479,  -588,  -588,  -588,  -588,   481,  -588,  -588,
    -588,   481,  -588,  -588,   492,  -588,  -588,   226,   503,  -588,
    -588,   225,   221,  -588,  -588,   636,  -588,   586,  -588,  -588,
     512,   683,  -588,   670,  -588,  -588,  -588,  -588,   511,  -588,
    -588,   511,  -588,    21,    21,  2507,  -588,    21,   518,   521,
    1177,  -588,  1727,  -588,   344,  -588,  -588,  -588,  -588,  -588,
    -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  1882,
    -588,  -588,  2211,  -588,  -588,  -588,   221,    21,   142,   176,
      21,  -588,    21,   176,    21,  1596,  -588,  -588,  -588,    40,
    -588,   291,  -588,   206,  -588,   864,  -588,  -588,  2507,  -588,
    -588,   670,  -588,  -588,   282,   282,  -588,  -588,  -588,    21,
    -588,  -588,   563,   344,  2211,  -588,   564,  2507,   526,   525,
    -588,  -588,   217,  1303,  2211,  -588,  1948,  -588,   572,  2211,
     574,   530,   543,  2155,   144,   622,  -588,  -588,  -588,   557,
    -588,   566,   955,   517,   562,  -588,  -588,  -588,  2064,   229,
     207,   225,  -588,  1758,  -588,  -588,  -588,   519,   221,  -588,
    -588,  -588,   553,  -588,  -588,   337,   390,   159,   864,  -588,
    -588,  1177,    40,  -588,    40,  -588,  2211,  -588,    56,   222,
    -588,  -588,  2397,  1177,  -588,  -588,  1240,  -588,  1366,  -588,
    -588,  1727,  2418,  -588,  -588,  -588,  -588,   575,  2211,   578,
    -588,   583,  -588,  -588,  -588,   291,  -588,   206,   590,  -588,
    -588,  -588,   591,   644,   973,    77,  -588,  -588,  -588,  -588,
     488,   488,  -588,  1815,  -588,   580,  -588,  -588,  -588,   579,
    -588,  -588,  2469,  2211,  -588,  2211,  -588,   587,  1366,  -588,
    -588,  2211,  -588,  -588,   584,  -588,  2211,   626,   419,  -588,
     418,   429,  -588,   196,  2211,   608,  -588,   612,  2211,  1057,
    -588,  -588,  -588,  -588,  2211,  -588,  -588,  -588,  -588,  -588,
    2469,  2369,  -588,  -588,  2489,  -588,    38,    21,  -588,   483,
    -588,   483,   600,  2211,   665,  2064,   603,  -588,  -588,  -588,
    -588,  -588,   604,  -588,  -588,  -588,   684,   611,  -588,  -588,
    -588,  -588,   614,  -588,  -588,  -588,  -588,   619,  -588,  -588,
    -588,  -588,   621,   646,    39,   624,  -588,  -588,  -588,  -588,
    -588,  2211,  -588,  -588,  -588,  2211,   684,   625,   684,  -588,
    -588,  -588,   634,  -588,   641,    51,  -588,  -588,   553,   553,
    -588,  -588,  -588,   379,   635,  -588,  -588,  2211,   264,   233,
    -588,   645,   648,   379,  -588,  -588,   264,  -588,  -588
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -588,  -588,  -588,  -588,  -588,   102,  -588,  -588,  -588,  -588,
    -588,  -588,  -588,  -588,   121,  -588,   -40,   420,  -149,   478,
    -588,  -588,   -38,   192,  -588,  -588,  -588,  -588,  -588,  -588,
    -588,  -194,  -170,   508,  -588,  -588,   198,    29,   -27,  -475,
       2,   676,  -588,   271,     7,    -7,   -73,   544,     4,  -167,
    -406,   -35,  -113,   -64,  -588,  -588,  -588,   149,     3,    20,
    -588,   431,  -588,   272,  -588,  -245,  -588,   183,  -588,  -433,
    -588,  -588,   250,  -588,  -588,  -588,  -588,  -588,  -588,   -42,
     -71,    71,   -19,  -588,  -588,  -588,   -46,  -588,  -588,  -588,
    -588,  -588,   395,   -34,  -588,   500,   408,   274,   498,   410,
     -61,  -588,  -160,   -72,   -77,  -117,  -588,  -588,  -588,  -588,
    -588,  -588,  -182,  -588,  -588,  -367,   100,  -588,  -588,   466,
    -349,  -588,   244,  -588,  -588,  -417,  -588,  -588,  -588,  -588,
     268,  -307,   110,  -559,  -166,  -126,  -588,  -588,  -588,  -588,
    -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -588,  -587,
      79,  -588,    93,  -588,   490,  -588,  -264,  -588,  -588,  -588,
     398,  -215,  -588,  -588,  -588,  -588,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -408
static const yytype_int16 yytable[] =
{
      89,   101,    33,    49,    33,    23,    27,    23,    27,   124,
      24,   234,    24,   135,    37,    38,    39,    54,   127,   307,
     334,   111,   515,   293,   151,    48,   108,    56,    55,   292,
     283,   139,    33,   379,   128,    23,    27,   143,   144,   323,
      24,   532,   227,   588,   147,   103,   210,    60,    48,   228,
     152,    16,    51,    53,   123,   535,    48,    60,    60,    60,
     560,   187,   134,   332,   243,   245,   439,   654,    60,   337,
      61,    62,   513,  -104,   182,   218,    60,   295,   633,   515,
     666,   696,   324,   135,    61,    62,    16,    -2,   208,   103,
    -319,   459,   212,   713,   261,  -320,   262,     4,   234,   679,
    -321,   108,  -322,   474,   702,   475,   371,    34,   197,   196,
      48,    61,    62,   123,    48,   596,   294,   109,   667,   697,
      -3,   110,   374,   123,   496,   610,   507,    35,    36,   513,
     721,   714,   134,   293,   703,    69,   246,  -169,  -169,   634,
     284,   103,   710,    60,   135,   389,    40,    61,    62,    50,
      64,    66,    68,    63,    60,   299,   328,   283,  -104,   103,
     331,   103,   375,   542,   138,   544,   330,    65,   728,   618,
     301,  -299,    16,   243,   245,   643,  -300,   377,   147,    41,
     675,  -301,   140,  -302,   381,    57,   113,    58,   437,   114,
     115,   531,   197,   600,    67,   601,   336,   197,   568,   146,
     426,   429,   432,   435,   522,   523,    16,   209,   208,    43,
      43,   444,   212,   343,   207,   345,    42,    60,    27,   106,
     352,   114,   115,   113,    43,   355,  -160,   203,    43,   444,
     123,   450,   454,   123,   123,  -160,    16,    16,   114,   115,
     427,   430,   433,   436,   142,   246,    60,   145,   304,   196,
     103,    16,    16,   305,   135,    16,   558,   153,   114,   115,
      44,   445,   251,   384,   603,   617,   396,   154,    45,   446,
     195,   397,   339,   182,   341,   451,   213,  -160,   483,   445,
     484,  -160,   188,   446,   195,    43,   118,   446,   195,   419,
     191,   715,   716,   519,    43,   118,   599,   197,   540,   281,
      27,   240,   285,   256,   197,    54,   441,   592,   607,   589,
     248,   442,    16,   722,   154,    56,    55,   257,   723,   401,
     258,    16,   219,   259,   546,  -107,  -107,  -107,  -107,   295,
     402,  -107,   -81,  -107,  -107,  -107,   119,   255,   229,   237,
     391,   392,   230,   110,   120,   119,   260,    61,    62,  -107,
     286,   263,   264,   120,   103,   287,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   520,   235,
     236,   540,   449,   453,   527,   251,     7,   394,     9,   192,
     291,   395,   306,   333,    11,    12,    13,   329,    72,   338,
     113,    16,   708,   709,   447,   452,   320,   344,    27,   509,
      15,   235,   236,   377,   381,   464,   321,  -107,   361,   423,
     377,   381,   327,   424,   207,   193,   302,   303,   597,   135,
     521,   340,   230,   194,   195,   528,   203,   108,   536,   461,
     463,   346,   549,   549,   378,    43,   118,    16,   518,   207,
     347,   511,    27,   356,   537,   113,   512,    43,  -160,   452,
     353,   207,   360,  -267,  -267,   354,   509,  -160,    27,   357,
     358,   193,    16,   567,   123,   359,    48,    60,   251,   194,
     195,   598,    60,   380,    16,   110,   385,   548,   123,   669,
     187,   670,   390,   595,   219,   393,   119,  -347,  -347,  -347,
    -347,   405,   135,   406,   120,  -347,  -347,  -347,    44,  -160,
     648,   208,   212,  -160,   230,    54,    45,   234,   208,   212,
     650,  -347,   114,   115,   110,    56,    55,   518,   413,   718,
     511,    27,    43,   447,   447,   512,   207,   414,   614,   726,
     452,   452,   578,   620,   579,   580,   581,   582,   415,   417,
     575,   577,   621,   302,   303,   495,   131,   132,   422,    16,
     522,   523,    11,    12,    13,   147,   373,   351,   623,   219,
     508,   438,   476,   477,   425,   428,   478,   434,    60,  -103,
     156,   158,   250,   451,    61,    62,   646,   421,   123,   440,
      48,   446,   195,   443,   652,   173,   174,   175,   656,   458,
     398,   590,   591,   460,   662,   468,   473,   524,   525,   526,
     479,   480,   529,   530,   551,   -32,   554,   410,   555,   412,
     556,   564,   487,   672,   -33,   674,   563,   508,    61,    62,
     200,   201,   202,   547,   565,   569,   176,   177,   550,   570,
     178,   179,   180,   181,   373,   373,   431,   373,   573,   507,
       7,     8,     9,    10,   184,   616,   456,   574,    11,    12,
      13,   674,   624,   628,   518,   704,   613,   511,    27,   615,
     629,   638,   512,   468,    15,   645,    16,   637,   647,   642,
     653,   466,   470,    70,   655,   472,   552,   674,    71,    72,
     671,    73,   673,   678,   682,   487,   561,     7,    57,     9,
      58,   562,   687,   683,   690,    11,    12,    13,   604,    74,
     692,    17,   694,    75,    76,    77,   706,   241,   695,   698,
       7,    15,     9,   100,    78,   711,   720,    79,    11,    12,
      13,   712,    80,    81,    82,   724,   388,    83,    84,   725,
     325,   129,    85,   487,    15,   538,   386,    17,   602,   609,
     300,   412,   559,   543,   418,   487,   342,   545,   487,   411,
     487,   639,   349,    86,    87,   376,   467,   416,   587,   680,
       7,     8,     9,    10,   462,   130,   131,   132,    11,    12,
      13,   681,    11,    12,    13,   705,   572,   169,   170,   171,
     172,   173,   174,   175,    15,     0,    16,   242,  -259,   663,
      16,   707,   382,   457,     0,   640,   668,   641,     0,     0,
     487,     0,   183,   644,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,     0,  -324,  -324,  -324,  -324,  -324,     0,  -324,  -324,
    -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,  -324,  -324,  -324,  -324,  -324,  -324,    52,   241,     0,
       0,     7,     0,     9,   100,  -324,     0,     0,  -324,    11,
      12,    13,     0,  -324,  -324,  -324,     0,     0,  -324,  -324,
       0,     0,     0,  -324,     7,    15,     9,   100,    17,   539,
     131,   132,    11,    12,    13,     0,    11,    12,    13,     0,
       0,     0,  -324,   184,  -324,  -324,     0,  -324,    15,     0,
     363,     0,  -347,  -347,  -347,  -347,  -347,  -347,  -347,   431,
    -347,  -347,  -347,  -347,  -347,     0,  -347,  -347,  -347,  -347,
    -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,
    -347,     0,  -347,  -347,  -347,     0,     0,     0,     0,   431,
       0,     0,     0,  -347,     0,     0,  -347,     0,     0,     0,
       0,  -347,  -347,  -347,     0,     0,  -347,  -347,     0,     0,
       0,  -347,     0,     0,     0,     0,   699,   700,     0,     7,
       8,     9,    10,     0,     0,     0,     0,    11,    12,    13,
    -347,     0,  -347,  -347,   630,  -347,  -326,  -326,     0,     0,
       0,  -326,  -326,    15,  -326,    16,     0,     0,  -326,     0,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,     0,  -326,     0,  -326,     0,  -326,  -326,  -326,     0,
     308,     0,   309,     7,     8,     9,    10,  -326,     0,   310,
    -326,    11,    12,    13,     0,  -326,  -326,  -326,     0,     0,
    -326,  -326,     0,     0,     0,  -326,   576,    15,     0,    16,
       0,     0,     0,     7,     8,     9,    10,     0,     0,     0,
       0,    11,    12,    13,  -326,     0,  -326,  -326,   657,  -326,
    -354,  -354,     0,     0,     0,  -354,  -354,    15,  -354,    16,
       0,     0,  -354,     0,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,     0,  -354,     0,  -354,  -407,
    -354,  -354,  -354,   168,   169,   170,   171,   172,   173,   174,
     175,  -354,     0,     0,  -354,     0,     0,     0,     0,  -354,
    -354,  -354,     0,     0,  -354,  -354,     0,     0,   148,  -354,
      70,     7,     0,     9,   100,    71,    72,     0,    73,    11,
      12,    13,   171,   172,   173,   174,   175,     0,  -354,     0,
    -354,  -354,     0,  -354,     0,    15,    74,     0,    17,     0,
      75,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,    79,     0,     0,     0,     0,    80,
      81,    82,     0,     0,    83,    84,     0,     0,   481,    85,
     482,    62,     0,     0,     0,    71,    72,     0,    73,     7,
       8,     9,    10,     0,     0,     0,     0,    11,    12,    13,
      86,    87,     0,   149,     0,     0,    74,     0,    17,     0,
      75,    76,    77,    15,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,    79,     0,     0,     0,     0,    80,
      81,    82,     0,     0,    83,    84,     0,     0,   483,    85,
     484,   481,     0,   482,    62,     0,     0,     0,    71,    72,
       0,    73,     0,     0,     0,     0,     0,     0,     0,  -188,
      86,    87,     0,   485,     0,     0,     0,     0,     0,    74,
       0,    17,     0,    75,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,    79,     0,     0,
       0,     0,    80,    81,    82,     0,     0,    83,    84,     0,
       0,   483,    85,   484,   481,     0,    70,     0,     0,     0,
       0,    71,    72,     0,    73,     0,     0,     0,     0,     0,
       0,     0,  -256,    86,    87,     0,   485,     0,     0,     0,
       0,     0,    74,     0,    17,     0,    75,    76,    77,     0,
       0,     0,  -201,     0,     0,     0,     0,    78,     0,     0,
      79,     0,     0,     0,     0,    80,    81,    82,     0,     0,
      83,    84,     0,     0,  -201,    85,  -201,   481,     0,    70,
       0,     0,     0,     0,    71,    72,     0,    73,     0,   112,
       0,     0,   -28,   -28,   -28,   -28,    86,    87,     0,   485,
     -28,   -28,   -28,     0,     0,    74,     0,    17,     0,    75,
      76,    77,     0,     0,     0,   113,   -28,     0,  -160,     0,
      78,     0,     0,    79,     0,     0,     0,  -160,    80,    81,
      82,     0,     0,    83,    84,     0,     0,     0,    85,     0,
       0,   238,     0,     0,   -24,   -24,   -24,   -24,     0,     0,
     114,   115,   -24,   -24,   -24,     0,     0,     0,     0,    86,
      87,     0,   485,     0,     0,     0,     0,   113,   -24,  -160,
    -160,     0,   232,  -160,   -28,   -20,   -20,   -20,   -20,  -160,
       0,     0,     0,   -20,   -20,   -20,    70,     0,     0,     0,
       0,    71,    72,     0,    73,     0,     0,     0,   113,   -20,
       0,  -160,   114,   115,     0,     0,     0,     0,     0,     0,
    -160,     0,    74,     0,    17,     0,    75,    76,    77,     0,
       0,  -160,     0,     0,     0,  -160,   -24,    78,     0,     0,
      79,     0,     0,     0,     0,    80,    81,   216,     0,     0,
      83,    84,     0,    70,     0,    85,     0,     0,    71,    72,
       0,    73,  -160,     0,     0,     0,  -160,   -20,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,     0,    74,
     217,    17,     0,    75,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,    79,     0,     0,
       0,     0,    80,    81,    82,     0,     0,    83,    84,     0,
      70,     0,    85,     0,     0,    71,    72,   308,    73,     0,
       7,     8,     9,    10,     0,     0,   310,     0,    11,    12,
      13,     0,     0,    86,    87,     0,    74,   298,    17,     0,
      75,    76,    77,     0,    15,     0,    16,     0,     0,     0,
       0,    78,     0,     0,    79,     0,     0,     0,     0,    80,
      81,    82,     0,     0,    83,    84,     0,    70,     0,    85,
       0,     0,    71,    72,     0,    73,     0,     7,     0,     9,
     192,     0,     0,     0,     0,    11,    12,    13,     0,     0,
      86,    87,     0,    74,   319,    17,  -407,    75,    76,    77,
       0,    15,     0,    16,     0,     0,     0,     0,    78,     0,
       0,    79,     0,     0,     0,     0,    80,    81,    82,     0,
       0,    83,    84,     0,    70,     0,    85,   193,     0,    71,
      72,     0,    73,     0,     0,   194,   195,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    86,    87,     0,
      74,   335,    17,     0,    75,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,     0,
       0,     0,     0,    80,    81,    82,     0,     0,    83,    84,
       0,    70,     0,    85,     0,     0,    71,    72,   161,    73,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    86,    87,     0,    74,   383,    17,
       0,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,    79,     0,     0,     0,     0,
      80,    81,   593,     0,     0,    83,    84,     0,    70,     0,
      85,     0,     0,    71,    72,     0,    73,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,    86,    87,     0,    74,   594,    17,     0,    75,    76,
      77,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,    79,     0,     0,     0,     0,    80,    81,    82,
       0,     0,    83,    84,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,   482,   498,     8,     9,    10,
      71,    72,     0,    73,    11,    12,    13,     0,    86,    87,
       0,     0,   636,   499,   500,   501,   502,   503,   504,   505,
      15,    74,    16,    17,     0,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,    79,
       0,     0,     0,     0,    80,    81,    82,     0,     0,    83,
      84,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,   482,    62,     0,     0,     0,    71,    72,     0,    73,
       0,     0,     0,   506,     0,    86,    87,     0,   507,   499,
     500,   501,   502,   503,   504,   505,     0,    74,     0,    17,
       0,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,    79,     0,     0,     0,     0,
      80,    81,    82,     0,     0,    83,    84,    70,     0,     0,
      85,     0,    71,    72,     0,    73,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   506,
       0,    86,    87,    74,   507,    17,     0,    75,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,    79,     0,     0,     0,     0,    80,    81,    82,     0,
       0,    83,    84,     0,     0,     0,    85,    70,     7,     8,
       9,    10,    71,    72,     0,    73,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,     0,
     351,     0,    15,    74,    16,    17,     0,    75,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,    79,     0,     0,     0,     0,    80,    81,    82,     0,
       0,    83,    84,     0,    70,     7,    85,     9,   100,    71,
      72,     0,    73,    11,    12,    13,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    86,    87,    15,
      74,     0,    17,     0,    75,    76,    77,     0,    70,     0,
       0,     0,     0,    71,    72,    78,    73,     0,    79,     0,
       0,     0,     0,    80,    81,    82,     0,     0,    83,    84,
       0,     0,     0,    85,    74,     0,    17,     0,    75,    76,
      77,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,    79,     0,    86,    87,     0,    80,    81,    82,
       0,     0,    83,    84,    70,     0,     0,    85,     0,    71,
      72,     0,    73,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,     0,     0,     0,   566,     0,    86,    87,
      74,     0,    17,     0,    75,    76,    77,     0,    70,     0,
       0,     0,     0,    71,    72,    78,    73,     0,    79,     0,
       0,     0,     0,    80,    81,    82,     0,     0,    83,    84,
       0,     0,     0,    85,    74,     0,    17,     0,    75,    76,
      77,     0,    70,     0,     0,     0,     0,    71,    72,    78,
      73,     0,    79,     0,    86,    87,     0,    80,    81,    82,
       0,     0,    83,    84,     0,     0,     0,   155,    74,     0,
      17,     0,    75,    76,    77,     0,   387,     0,     0,     0,
       0,    71,    72,    78,    73,     0,    79,     0,    86,    87,
       0,    80,    81,    82,     0,     0,    83,    84,     0,     0,
       0,   157,    74,     0,    17,     0,    75,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      79,     0,    86,    87,     0,    80,    81,    82,     0,     0,
      83,    84,     0,     0,     6,    85,  -116,     7,     8,     9,
      10,     0,     0,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,     0,     0,
      14,    15,     0,    16,    17,     0,     0,   605,   159,   160,
     161,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,  -116,   611,     0,
       0,     0,     0,     0,     0,  -116,   159,   160,   161,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    18,     0,   664,   159,   160,   161,
     612,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,     0,     0,     0,     0,
       0,   159,   160,   161,   606,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    16,
       0,     0,     0,     0,     0,     0,     0,     0,   159,   160,
     161,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   350,   159,   160,
     161,   665,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   159,   160,   161,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175
};

static const yytype_int16 yycheck[] =
{
      40,    41,     3,    22,     5,     3,     3,     5,     5,    51,
       3,   124,     5,    59,    11,    12,    13,    24,    53,   213,
     235,    48,   439,   190,    85,    22,    45,    24,    24,   189,
     179,    65,    33,   297,    53,    33,    33,    75,    76,   221,
      33,     1,   119,   518,    82,    41,   110,    27,    45,   120,
      88,    30,    23,    24,    51,   461,    53,    37,    38,    39,
     493,    99,    59,   233,   137,   137,   373,   626,    48,   239,
       3,     4,   439,     1,     9,   115,    56,   194,     1,   496,
      42,    42,    10,   129,     3,     4,    30,     0,   107,    85,
       1,   398,   111,    42,   155,     1,   157,     0,   211,   658,
       1,   120,     1,   410,   691,   412,   288,     5,   105,   105,
     107,     3,     4,   110,   111,   532,   193,    81,    80,    80,
       0,    85,   288,   120,   431,   558,    86,    81,    82,   496,
     717,    80,   129,   300,   693,    33,   137,    81,    82,    62,
     180,   137,   701,   123,   190,    80,    62,     3,     4,    81,
      29,    30,    31,    86,   134,   195,   227,   306,    86,   155,
     231,   157,   288,   470,    86,   472,   230,    86,   727,   575,
     197,    82,    30,   246,   246,   608,    82,   294,   216,    62,
     655,    82,    86,    82,   301,     5,    27,     7,   370,    62,
      63,   455,   189,   542,    86,   544,   236,   194,    54,    78,
     366,   367,   368,   369,    62,    63,    30,    80,   227,     3,
       3,     4,   231,   247,     7,   249,    62,   197,   215,    62,
     258,    62,    63,    27,     3,   265,    30,   106,     3,     4,
     227,   391,   392,   230,   231,    39,    30,    30,    62,    63,
     366,   367,   368,   369,    86,   246,   226,    62,    80,   245,
     246,    30,    30,    85,   300,    30,    39,    80,    62,    63,
      54,    54,   141,   303,    42,   572,    80,    85,    62,    62,
      63,    85,   243,     9,   245,    54,    62,    81,    61,    54,
      63,    85,    80,    62,    63,     3,     4,    62,    63,   350,
      80,   708,   709,   442,     3,     4,   541,   294,   465,   178,
     297,    82,   181,    80,   301,   312,    80,   522,   553,    80,
      82,    85,    30,    80,    85,   312,   312,    80,    85,   326,
      80,    30,     1,    81,    42,     4,     5,     6,     7,   446,
     326,    10,    42,    12,    13,    14,    54,   145,    81,    81,
     311,   312,    85,    85,    62,    54,   154,     3,     4,    28,
      80,   159,   160,    62,   350,    32,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   445,    62,
      63,   538,   391,   392,   451,   254,     4,    81,     6,     7,
      80,    85,    62,   234,    12,    13,    14,    80,     9,   240,
      27,    30,   699,   700,   391,   392,    87,   248,   395,   439,
      28,    62,    63,   520,   521,   401,    81,    86,   287,    81,
     527,   528,    39,    85,     7,    54,    62,    63,    81,   465,
     447,    81,    85,    62,    63,   452,   305,   446,   463,   400,
     401,    39,   474,   475,    80,     3,     4,    30,   439,     7,
      85,   439,   439,    42,   463,    27,   439,     3,    30,   446,
      80,     7,    87,    81,    82,    80,   496,    39,   455,   267,
     268,    54,    30,   503,   461,    80,   463,   447,   347,    62,
      63,    81,   452,    87,    30,    85,    80,   474,   475,   649,
     518,   651,    80,   523,     1,    80,    54,     4,     5,     6,
       7,    39,   538,    87,    62,    12,    13,    14,    54,    81,
      81,   520,   521,    85,    85,   512,    62,   620,   527,   528,
      81,    28,    62,    63,    85,   512,   512,   518,    82,   713,
     518,   518,     3,   520,   521,   518,     7,    82,   568,   723,
     527,   528,    15,   575,    17,    18,    19,    20,   346,    82,
     511,   512,   577,    62,    63,   424,     6,     7,   356,    30,
      62,    63,    12,    13,    14,   593,   288,    86,   577,     1,
     439,    82,   413,   414,   366,   367,   417,   369,   548,    86,
      92,    93,     1,    54,     3,     4,   616,    42,   575,    87,
     577,    62,    63,    80,   624,    54,    55,    56,   628,     3,
     322,   520,   521,    81,   634,   403,    85,   448,   449,   450,
      82,    80,   453,   454,   483,    42,    42,   339,    82,   341,
      85,    81,   420,   653,    42,   655,    42,   496,     3,     4,
       5,     6,     7,   474,    81,   504,    57,    58,   479,     7,
      61,    62,    63,    64,   366,   367,   368,   369,    81,    86,
       4,     5,     6,     7,    82,    62,    10,    81,    12,    13,
      14,   691,    62,    62,   655,   695,    81,   655,   655,    81,
      16,    82,   655,   471,    28,    81,    30,    87,    42,    82,
      62,     1,   404,     3,    62,   407,   484,   717,     8,     9,
      80,    11,    17,    80,    80,   493,   494,     4,     5,     6,
       7,   499,    81,     9,    80,    12,    13,    14,   549,    29,
      81,    31,    81,    33,    34,    35,    81,     1,    62,    85,
       4,    28,     6,     7,    44,    81,    81,    47,    12,    13,
      14,    80,    52,    53,    54,    80,   306,    57,    58,    81,
     222,    55,    62,   541,    28,   464,   305,    31,   546,   556,
     196,   473,   492,   471,   349,   553,   246,   473,   556,   341,
     558,   602,   254,    83,    84,   289,    86,   347,   514,   659,
       4,     5,     6,     7,    81,     5,     6,     7,    12,    13,
      14,   661,    12,    13,    14,   696,   508,    50,    51,    52,
      53,    54,    55,    56,    28,    -1,    30,    81,    82,   640,
      30,   698,   302,   395,    -1,   603,   647,   605,    -1,    -1,
     608,    -1,     1,   611,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    81,     1,    -1,
      -1,     4,    -1,     6,     7,    44,    -1,    -1,    47,    12,
      13,    14,    -1,    52,    53,    54,    -1,    -1,    57,    58,
      -1,    -1,    -1,    62,     4,    28,     6,     7,    31,     5,
       6,     7,    12,    13,    14,    -1,    12,    13,    14,    -1,
      -1,    -1,    81,    82,    83,    84,    -1,    86,    28,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,   631,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,   661,
      -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    -1,    -1,    57,    58,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,   688,   689,    -1,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      81,    -1,    83,    84,     1,    86,     3,     4,    -1,    -1,
      -1,     8,     9,    28,    11,    30,    -1,    -1,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    31,    -1,    33,    34,    35,    -1,
       1,    -1,     3,     4,     5,     6,     7,    44,    -1,    10,
      47,    12,    13,    14,    -1,    52,    53,    54,    -1,    -1,
      57,    58,    -1,    -1,    -1,    62,    81,    28,    -1,    30,
      -1,    -1,    -1,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    81,    -1,    83,    84,     1,    86,
       3,     4,    -1,    -1,    -1,     8,     9,    28,    11,    30,
      -1,    -1,    15,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    31,    80,
      33,    34,    35,    49,    50,    51,    52,    53,    54,    55,
      56,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    -1,    -1,    57,    58,    -1,    -1,     1,    62,
       3,     4,    -1,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    52,    53,    54,    55,    56,    -1,    81,    -1,
      83,    84,    -1,    86,    -1,    28,    29,    -1,    31,    -1,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    -1,    -1,    57,    58,    -1,    -1,     1,    62,
       3,     4,    -1,    -1,    -1,     8,     9,    -1,    11,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      83,    84,    -1,    86,    -1,    -1,    29,    -1,    31,    -1,
      33,    34,    35,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    -1,    -1,    57,    58,    -1,    -1,    61,    62,
      63,     1,    -1,     3,     4,    -1,    -1,    -1,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    31,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,    -1,
      -1,    61,    62,    63,     1,    -1,     3,    -1,    -1,    -1,
      -1,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    31,    -1,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,    -1,
      57,    58,    -1,    -1,    61,    62,    63,     1,    -1,     3,
      -1,    -1,    -1,    -1,     8,     9,    -1,    11,    -1,     1,
      -1,    -1,     4,     5,     6,     7,    83,    84,    -1,    86,
      12,    13,    14,    -1,    -1,    29,    -1,    31,    -1,    33,
      34,    35,    -1,    -1,    -1,    27,    28,    -1,    30,    -1,
      44,    -1,    -1,    47,    -1,    -1,    -1,    39,    52,    53,
      54,    -1,    -1,    57,    58,    -1,    -1,    -1,    62,    -1,
      -1,     1,    -1,    -1,     4,     5,     6,     7,    -1,    -1,
      62,    63,    12,    13,    14,    -1,    -1,    -1,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    27,    28,    81,
      30,    -1,     1,    85,    86,     4,     5,     6,     7,    39,
      -1,    -1,    -1,    12,    13,    14,     3,    -1,    -1,    -1,
      -1,     8,     9,    -1,    11,    -1,    -1,    -1,    27,    28,
      -1,    30,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    29,    -1,    31,    -1,    33,    34,    35,    -1,
      -1,    81,    -1,    -1,    -1,    85,    86,    44,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,    -1,
      57,    58,    -1,     3,    -1,    62,    -1,    -1,     8,     9,
      -1,    11,    81,    -1,    -1,    -1,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    29,
      87,    31,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,    -1,
       3,    -1,    62,    -1,    -1,     8,     9,     1,    11,    -1,
       4,     5,     6,     7,    -1,    -1,    10,    -1,    12,    13,
      14,    -1,    -1,    83,    84,    -1,    29,    87,    31,    -1,
      33,    34,    35,    -1,    28,    -1,    30,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    -1,    -1,    57,    58,    -1,     3,    -1,    62,
      -1,    -1,     8,     9,    -1,    11,    -1,     4,    -1,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      83,    84,    -1,    29,    87,    31,    80,    33,    34,    35,
      -1,    28,    -1,    30,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,
      -1,    57,    58,    -1,     3,    -1,    62,    54,    -1,     8,
       9,    -1,    11,    -1,    -1,    62,    63,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    83,    84,    -1,
      29,    87,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,
      -1,     3,    -1,    62,    -1,    -1,     8,     9,    41,    11,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    83,    84,    -1,    29,    87,    31,
      -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      52,    53,    54,    -1,    -1,    57,    58,    -1,     3,    -1,
      62,    -1,    -1,     8,     9,    -1,    11,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    83,    84,    -1,    29,    87,    31,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,
      -1,    -1,    57,    58,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    -1,    83,    84,
      -1,    -1,    87,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    -1,    -1,    57,
      58,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,     8,     9,    -1,    11,
      -1,    -1,    -1,    81,    -1,    83,    84,    -1,    86,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    31,
      -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      52,    53,    54,    -1,    -1,    57,    58,     3,    -1,    -1,
      62,    -1,     8,     9,    -1,    11,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    81,
      -1,    83,    84,    29,    86,    31,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,
      -1,    57,    58,    -1,    -1,    -1,    62,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      86,    -1,    28,    29,    30,    31,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,
      -1,    57,    58,    -1,     3,     4,    62,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    83,    84,    28,
      29,    -1,    31,    -1,    33,    34,    35,    -1,     3,    -1,
      -1,    -1,    -1,     8,     9,    44,    11,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,
      -1,    -1,    -1,    62,    29,    -1,    31,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    47,    -1,    83,    84,    -1,    52,    53,    54,
      -1,    -1,    57,    58,     3,    -1,    -1,    62,    -1,     8,
       9,    -1,    11,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    81,    -1,    83,    84,
      29,    -1,    31,    -1,    33,    34,    35,    -1,     3,    -1,
      -1,    -1,    -1,     8,     9,    44,    11,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,
      -1,    -1,    -1,    62,    29,    -1,    31,    -1,    33,    34,
      35,    -1,     3,    -1,    -1,    -1,    -1,     8,     9,    44,
      11,    -1,    47,    -1,    83,    84,    -1,    52,    53,    54,
      -1,    -1,    57,    58,    -1,    -1,    -1,    62,    29,    -1,
      31,    -1,    33,    34,    35,    -1,     3,    -1,    -1,    -1,
      -1,     8,     9,    44,    11,    -1,    47,    -1,    83,    84,
      -1,    52,    53,    54,    -1,    -1,    57,    58,    -1,    -1,
      -1,    62,    29,    -1,    31,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      47,    -1,    83,    84,    -1,    52,    53,    54,    -1,    -1,
      57,    58,    -1,    -1,     1,    62,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      27,    28,    -1,    30,    31,    -1,    -1,    10,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    54,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    81,    -1,    87,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    87,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    85,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    91,     0,    92,     1,     4,     5,     6,
       7,    12,    13,    14,    27,    28,    30,    31,    81,    93,
      94,    95,   125,   128,   132,   133,   136,   146,   147,   171,
     172,   173,   174,   254,    93,    81,    82,   146,   146,   146,
      62,    62,    62,     3,    54,    62,   139,   143,   146,   170,
      81,   125,    81,   125,   133,   136,   146,     5,     7,   129,
     147,     3,     4,    86,   102,    86,   102,    86,   102,    93,
       3,     8,     9,    11,    29,    33,    34,    35,    44,    47,
      52,    53,    54,    57,    58,    62,    83,    84,   103,   104,
     106,   107,   108,   109,   110,   111,   117,   119,   212,   254,
       7,   104,   134,   136,   188,   191,    62,   192,   170,    81,
      85,   126,     1,    27,    62,    63,   100,   140,     4,    54,
      62,   138,   141,   146,   167,   168,   170,   139,   170,   129,
       5,     6,     7,   137,   146,   174,   181,   182,    86,   181,
      86,   178,    86,   110,   110,    62,   102,   110,     1,    86,
     104,   188,   110,    80,    85,    62,   107,    62,   107,    39,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    61,    62,
      63,    64,     9,     1,    82,   201,   210,   110,    80,   189,
     135,    80,     7,    54,    62,    63,   136,   146,   190,   193,
       5,     6,     7,   102,   148,   149,   150,     7,   170,    80,
     141,   167,   170,    62,   249,   250,    54,    87,   104,     1,
     120,   121,   122,   200,   218,   145,   146,   192,   168,    81,
      85,   126,     1,    96,   140,    62,    63,    81,     1,    98,
      82,     1,    81,   134,   183,   191,   254,   175,    82,   176,
       1,   102,   186,   187,   177,   111,    80,    80,    80,    81,
     111,   188,   188,   111,   111,   114,   116,   113,   112,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   102,   105,   106,   104,   102,    80,    32,   205,   206,
     207,    80,   190,   137,   192,   193,   242,   243,    87,   104,
     135,   126,    62,    63,    80,    85,    62,   119,     1,     3,
      10,   128,   132,   244,   246,   247,   248,   251,   252,    87,
      87,    81,   101,   200,    10,   121,   219,    39,   168,    80,
     141,   168,   120,   145,   249,    87,   104,   120,   145,   125,
      81,   125,   183,   181,   145,   181,    39,    85,   180,   186,
      85,    86,   110,    80,    80,   104,    42,   111,   111,    80,
      87,   102,   253,     1,   124,   194,   195,   196,   197,   198,
     199,   200,   211,   218,   222,   223,   207,   193,    80,   244,
      87,   193,   242,    87,   104,    80,   149,     3,   105,    80,
      80,   125,   125,    80,    81,    85,    80,    85,   218,   123,
     130,   133,   136,   144,    97,    39,    87,    99,   184,   185,
     218,   184,   218,    82,    82,   111,   187,    82,   180,   188,
     118,    42,   111,    81,    85,   124,   222,   223,   124,   222,
     223,   218,   222,   223,   124,   222,   223,   200,    82,   219,
      87,    80,    85,    80,     4,    54,    62,   146,   169,   170,
     190,    54,   146,   170,   190,   245,    10,   248,     3,   219,
      81,   125,    81,   125,   136,   131,     1,    86,   111,   151,
     218,   142,   218,    85,   219,   219,   145,   145,   145,    82,
      80,     1,     3,    61,    63,    86,   102,   111,   153,   154,
     155,   157,   159,   160,   115,   102,   219,   202,     4,    21,
      22,    23,    24,    25,    26,    27,    81,    86,   102,   104,
     127,   128,   132,   203,   209,   213,   234,   235,   254,   106,
     192,   126,    62,    63,   145,   145,   145,   192,   126,   145,
     145,   244,     1,   208,   213,   138,   139,   170,   131,     5,
     137,   152,   219,   151,   219,   185,    42,   145,   146,   167,
     145,   102,   111,   158,    42,    82,    85,   179,    39,   160,
     157,   111,   111,    42,    81,    81,    81,   104,    54,   102,
       7,   236,   218,    81,    81,   125,    81,   125,    15,    17,
      18,    19,    20,   214,   215,   216,   224,   210,   127,    80,
     169,   169,   249,    54,    87,   104,   213,    81,    81,   153,
     208,   208,   111,    42,   145,    10,    87,   153,   156,   155,
     157,    10,    42,    81,   104,    81,    62,   219,   138,   161,
     167,   139,   164,   170,    62,   226,   217,   228,    62,    16,
       1,   203,   221,     1,    62,   204,    87,    87,    82,   145,
     111,   111,    82,   157,   111,    81,   104,    42,    81,   162,
      81,   165,   104,    62,   221,    62,   104,     1,   225,   220,
     222,   223,   104,   145,    87,    42,    42,    80,   145,   120,
     120,    80,   104,    17,   104,   127,   233,   237,    80,   221,
     204,   220,    80,     9,   238,   239,   240,    81,   163,   166,
      80,   229,    81,   232,    81,    62,    42,    80,    85,   218,
     218,   227,   237,   221,   104,   238,    81,   240,   219,   219,
     221,    81,    80,    42,    80,   213,   213,   230,   119,   241,
      81,   237,    80,    85,    80,    81,   119,   231,   221
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 246 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ISO C forbids an empty source file");
		  finish_file ();
		;}
    break;

  case 3:
#line 251 "c-parse.y"
    {
		  /* In case there were missing closebraces,
		     get us back to the global binding level.  */
		  while (! global_bindings_p ())
		    poplevel (0, 0, 0);
		  finish_file ();
		;}
    break;

  case 4:
#line 265 "c-parse.y"
    {(yyval.ttype) = NULL_TREE; ;}
    break;

  case 6:
#line 266 "c-parse.y"
    {(yyval.ttype) = NULL_TREE; ggc_collect(); ;}
    break;

  case 10:
#line 273 "c-parse.y"
    { STRIP_NOPS ((yyvsp[(3) - (5)].ttype));
		  if ((TREE_CODE ((yyvsp[(3) - (5)].ttype)) == ADDR_EXPR
		       && TREE_CODE (TREE_OPERAND ((yyvsp[(3) - (5)].ttype), 0)) == STRING_CST)
		      || TREE_CODE ((yyvsp[(3) - (5)].ttype)) == STRING_CST)
		    assemble_asm ((yyvsp[(3) - (5)].ttype));
		  else
		    error ("argument of `asm' is not a constant string"); ;}
    break;

  case 11:
#line 281 "c-parse.y"
    { RESTORE_WARN_FLAGS ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 12:
#line 286 "c-parse.y"
    { if (pedantic)
		    error ("ISO C forbids data definition with no type or storage class");
		  else if (!flag_traditional)
		    warning ("data definition has no type or storage class"); 

		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 13:
#line 295 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 14:
#line 299 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 15:
#line 303 "c-parse.y"
    { pedwarn ("empty declaration"); ;}
    break;

  case 16:
#line 305 "c-parse.y"
    { shadow_tag ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 19:
#line 309 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ISO C does not allow extra `;' outside of a function"); ;}
    break;

  case 20:
#line 315 "c-parse.y"
    { if (! start_function (current_declspecs, (yyvsp[(3) - (3)].ttype),
					prefix_attributes, NULL_TREE))
		    YYERROR1;
		;}
    break;

  case 21:
#line 320 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 22:
#line 322 "c-parse.y"
    { DECL_SOURCE_FILE (current_function_decl) = (yyvsp[(7) - (9)].filename);
		  DECL_SOURCE_LINE (current_function_decl) = (yyvsp[(8) - (9)].lineno);
		  finish_function (0); 
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 23:
#line 329 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 24:
#line 333 "c-parse.y"
    { if (! start_function (current_declspecs, (yyvsp[(3) - (3)].ttype),
					prefix_attributes, NULL_TREE))
		    YYERROR1;
		;}
    break;

  case 25:
#line 338 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 26:
#line 340 "c-parse.y"
    { DECL_SOURCE_FILE (current_function_decl) = (yyvsp[(7) - (9)].filename);
		  DECL_SOURCE_LINE (current_function_decl) = (yyvsp[(8) - (9)].lineno);
		  finish_function (0); 
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 27:
#line 347 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 28:
#line 351 "c-parse.y"
    { if (! start_function (NULL_TREE, (yyvsp[(2) - (2)].ttype),
					prefix_attributes, NULL_TREE))
		    YYERROR1;
		;}
    break;

  case 29:
#line 356 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 30:
#line 358 "c-parse.y"
    { DECL_SOURCE_FILE (current_function_decl) = (yyvsp[(6) - (8)].filename);
		  DECL_SOURCE_LINE (current_function_decl) = (yyvsp[(7) - (8)].lineno);
		  finish_function (0); 
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 31:
#line 365 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 34:
#line 376 "c-parse.y"
    { (yyval.code) = ADDR_EXPR; ;}
    break;

  case 35:
#line 378 "c-parse.y"
    { (yyval.code) = NEGATE_EXPR; ;}
    break;

  case 36:
#line 380 "c-parse.y"
    { (yyval.code) = CONVERT_EXPR;
  if (warn_traditional && !in_system_header)
    warning ("traditional C rejects the unary plus operator");
		;}
    break;

  case 37:
#line 385 "c-parse.y"
    { (yyval.code) = PREINCREMENT_EXPR; ;}
    break;

  case 38:
#line 387 "c-parse.y"
    { (yyval.code) = PREDECREMENT_EXPR; ;}
    break;

  case 39:
#line 389 "c-parse.y"
    { (yyval.code) = BIT_NOT_EXPR; ;}
    break;

  case 40:
#line 391 "c-parse.y"
    { (yyval.code) = TRUTH_NOT_EXPR; ;}
    break;

  case 41:
#line 395 "c-parse.y"
    { (yyval.ttype) = build_compound_expr ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 42:
#line 400 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 44:
#line 406 "c-parse.y"
    { (yyval.ttype) = build_tree_list (NULL_TREE, (yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 45:
#line 408 "c-parse.y"
    { chainon ((yyvsp[(1) - (3)].ttype), build_tree_list (NULL_TREE, (yyvsp[(3) - (3)].ttype))); ;}
    break;

  case 47:
#line 414 "c-parse.y"
    { (yyval.ttype) = build_indirect_ref ((yyvsp[(2) - (2)].ttype), "unary *"); ;}
    break;

  case 48:
#line 417 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype);
		  RESTORE_WARN_FLAGS ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 49:
#line 420 "c-parse.y"
    { (yyval.ttype) = build_unary_op ((yyvsp[(1) - (2)].code), (yyvsp[(2) - (2)].ttype), 0);
		  overflow_warning ((yyval.ttype)); ;}
    break;

  case 50:
#line 424 "c-parse.y"
    { tree label = lookup_label ((yyvsp[(2) - (2)].ttype));
		  if (pedantic)
		    pedwarn ("ISO C forbids `&&'");
		  if (label == 0)
		    (yyval.ttype) = null_pointer_node;
		  else
		    {
		      TREE_USED (label) = 1;
		      (yyval.ttype) = build1 (ADDR_EXPR, ptr_type_node, label);
		      TREE_CONSTANT ((yyval.ttype)) = 1;
		    }
		;}
    break;

  case 51:
#line 452 "c-parse.y"
    { skip_evaluation--;
		  if (TREE_CODE ((yyvsp[(2) - (2)].ttype)) == COMPONENT_REF
		      && DECL_C_BIT_FIELD (TREE_OPERAND ((yyvsp[(2) - (2)].ttype), 1)))
		    error ("`sizeof' applied to a bit-field");
		  (yyval.ttype) = c_sizeof (TREE_TYPE ((yyvsp[(2) - (2)].ttype))); ;}
    break;

  case 52:
#line 458 "c-parse.y"
    { skip_evaluation--;
		  (yyval.ttype) = c_sizeof (groktypename ((yyvsp[(3) - (4)].ttype))); ;}
    break;

  case 53:
#line 461 "c-parse.y"
    { skip_evaluation--;
		  (yyval.ttype) = c_alignof_expr ((yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 54:
#line 464 "c-parse.y"
    { skip_evaluation--;
		  (yyval.ttype) = c_alignof (groktypename ((yyvsp[(3) - (4)].ttype))); ;}
    break;

  case 55:
#line 467 "c-parse.y"
    { (yyval.ttype) = build_unary_op (REALPART_EXPR, (yyvsp[(2) - (2)].ttype), 0); ;}
    break;

  case 56:
#line 469 "c-parse.y"
    { (yyval.ttype) = build_unary_op (IMAGPART_EXPR, (yyvsp[(2) - (2)].ttype), 0); ;}
    break;

  case 57:
#line 473 "c-parse.y"
    { skip_evaluation++; ;}
    break;

  case 58:
#line 477 "c-parse.y"
    { skip_evaluation++; ;}
    break;

  case 60:
#line 483 "c-parse.y"
    { tree type;
		  int SAVED_warn_strict_prototypes = warn_strict_prototypes;
		  /* This avoids warnings about unprototyped casts on
                     integers.  E.g. "#define SIG_DFL (void(*)())0".  */
		  if (TREE_CODE ((yyvsp[(4) - (4)].ttype)) == INTEGER_CST)
		    warn_strict_prototypes = 0;
		  type = groktypename ((yyvsp[(2) - (4)].ttype));
		  warn_strict_prototypes = SAVED_warn_strict_prototypes;
		  (yyval.ttype) = build_c_cast (type, (yyvsp[(4) - (4)].ttype)); ;}
    break;

  case 62:
#line 497 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 63:
#line 499 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 64:
#line 501 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 65:
#line 503 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 66:
#line 505 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 67:
#line 507 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 68:
#line 509 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 69:
#line 511 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 70:
#line 513 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 71:
#line 515 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 72:
#line 517 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 73:
#line 519 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 74:
#line 521 "c-parse.y"
    { (yyvsp[(1) - (2)].ttype) = truthvalue_conversion (default_conversion ((yyvsp[(1) - (2)].ttype)));
		  skip_evaluation += (yyvsp[(1) - (2)].ttype) == boolean_false_node; ;}
    break;

  case 75:
#line 524 "c-parse.y"
    { skip_evaluation -= (yyvsp[(1) - (4)].ttype) == boolean_false_node;
		  (yyval.ttype) = parser_build_binary_op (TRUTH_ANDIF_EXPR, (yyvsp[(1) - (4)].ttype), (yyvsp[(4) - (4)].ttype)); ;}
    break;

  case 76:
#line 527 "c-parse.y"
    { (yyvsp[(1) - (2)].ttype) = truthvalue_conversion (default_conversion ((yyvsp[(1) - (2)].ttype)));
		  skip_evaluation += (yyvsp[(1) - (2)].ttype) == boolean_true_node; ;}
    break;

  case 77:
#line 530 "c-parse.y"
    { skip_evaluation -= (yyvsp[(1) - (4)].ttype) == boolean_true_node;
		  (yyval.ttype) = parser_build_binary_op (TRUTH_ORIF_EXPR, (yyvsp[(1) - (4)].ttype), (yyvsp[(4) - (4)].ttype)); ;}
    break;

  case 78:
#line 533 "c-parse.y"
    { (yyvsp[(1) - (2)].ttype) = truthvalue_conversion (default_conversion ((yyvsp[(1) - (2)].ttype)));
		  skip_evaluation += (yyvsp[(1) - (2)].ttype) == boolean_false_node; ;}
    break;

  case 79:
#line 536 "c-parse.y"
    { skip_evaluation += (((yyvsp[(1) - (5)].ttype) == boolean_true_node)
				      - ((yyvsp[(1) - (5)].ttype) == boolean_false_node)); ;}
    break;

  case 80:
#line 539 "c-parse.y"
    { skip_evaluation -= (yyvsp[(1) - (7)].ttype) == boolean_true_node;
		  (yyval.ttype) = build_conditional_expr ((yyvsp[(1) - (7)].ttype), (yyvsp[(4) - (7)].ttype), (yyvsp[(7) - (7)].ttype)); ;}
    break;

  case 81:
#line 542 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ISO C forbids omitting the middle term of a ?: expression");
		  /* Make sure first operand is calculated only once.  */
		  (yyvsp[(2) - (2)].ttype) = save_expr ((yyvsp[(1) - (2)].ttype));
		  (yyvsp[(1) - (2)].ttype) = truthvalue_conversion (default_conversion ((yyvsp[(2) - (2)].ttype)));
		  skip_evaluation += (yyvsp[(1) - (2)].ttype) == boolean_true_node; ;}
    break;

  case 82:
#line 549 "c-parse.y"
    { skip_evaluation -= (yyvsp[(1) - (5)].ttype) == boolean_true_node;
		  (yyval.ttype) = build_conditional_expr ((yyvsp[(1) - (5)].ttype), (yyvsp[(2) - (5)].ttype), (yyvsp[(5) - (5)].ttype)); ;}
    break;

  case 83:
#line 552 "c-parse.y"
    { char class;
		  (yyval.ttype) = build_modify_expr ((yyvsp[(1) - (3)].ttype), NOP_EXPR, (yyvsp[(3) - (3)].ttype));
		  class = TREE_CODE_CLASS (TREE_CODE ((yyval.ttype)));
		  if (class == 'e' || class == '1'
		      || class == '2' || class == '<')
		    C_SET_EXP_ORIGINAL_CODE ((yyval.ttype), MODIFY_EXPR);
		;}
    break;

  case 84:
#line 560 "c-parse.y"
    { char class;
		  (yyval.ttype) = build_modify_expr ((yyvsp[(1) - (3)].ttype), (yyvsp[(2) - (3)].code), (yyvsp[(3) - (3)].ttype));
		  /* This inhibits warnings in truthvalue_conversion.  */
		  class = TREE_CODE_CLASS (TREE_CODE ((yyval.ttype)));
		  if (class == 'e' || class == '1'
		      || class == '2' || class == '<')
		    C_SET_EXP_ORIGINAL_CODE ((yyval.ttype), ERROR_MARK);
		;}
    break;

  case 85:
#line 572 "c-parse.y"
    {
		  if (yychar == YYEMPTY)
		    yychar = YYLEX;
		  (yyval.ttype) = build_external_ref ((yyvsp[(1) - (1)].ttype), yychar == '(');
		;}
    break;

  case 87:
#line 579 "c-parse.y"
    { (yyval.ttype) = combine_strings ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 88:
#line 581 "c-parse.y"
    { start_init (NULL_TREE, NULL, 0);
		  (yyvsp[(2) - (4)].ttype) = groktypename ((yyvsp[(2) - (4)].ttype));
		  really_start_incremental_init ((yyvsp[(2) - (4)].ttype)); ;}
    break;

  case 89:
#line 585 "c-parse.y"
    { const char *name;
		  tree result = pop_init_level (0);
		  tree type = (yyvsp[(2) - (7)].ttype);
		  finish_init ();

		  if (pedantic && ! flag_isoc99)
		    pedwarn ("ISO C89 forbids compound literals");
		  if (TYPE_NAME (type) != 0)
		    {
		      if (TREE_CODE (TYPE_NAME (type)) == IDENTIFIER_NODE)
			name = IDENTIFIER_POINTER (TYPE_NAME (type));
		      else
			name = IDENTIFIER_POINTER (DECL_NAME (TYPE_NAME (type)));
		    }
		  else
		    name = "";
		  (yyval.ttype) = result;
		  if (TREE_CODE (type) == ARRAY_TYPE && !COMPLETE_TYPE_P (type))
		    {
		      int failure = complete_array_type (type, (yyval.ttype), 1);
		      if (failure)
			abort ();
		    }
		;}
    break;

  case 90:
#line 610 "c-parse.y"
    { char class = TREE_CODE_CLASS (TREE_CODE ((yyvsp[(2) - (3)].ttype)));
		  if (class == 'e' || class == '1'
		      || class == '2' || class == '<')
		    C_SET_EXP_ORIGINAL_CODE ((yyvsp[(2) - (3)].ttype), ERROR_MARK);
		  (yyval.ttype) = (yyvsp[(2) - (3)].ttype); ;}
    break;

  case 91:
#line 616 "c-parse.y"
    { (yyval.ttype) = error_mark_node; ;}
    break;

  case 92:
#line 618 "c-parse.y"
    { tree saved_last_tree;

		   if (pedantic)
		     pedwarn ("ISO C forbids braced-groups within expressions");
		  pop_label_level ();

		  saved_last_tree = COMPOUND_BODY ((yyvsp[(1) - (3)].ttype));
		  RECHAIN_STMTS ((yyvsp[(1) - (3)].ttype), COMPOUND_BODY ((yyvsp[(1) - (3)].ttype)));
		  last_tree = saved_last_tree;
		  TREE_CHAIN (last_tree) = NULL_TREE;
		  if (!last_expr_type)
		    last_expr_type = void_type_node;
		  (yyval.ttype) = build1 (STMT_EXPR, last_expr_type, (yyvsp[(1) - (3)].ttype));
		  TREE_SIDE_EFFECTS ((yyval.ttype)) = 1;
		;}
    break;

  case 93:
#line 634 "c-parse.y"
    {
		  pop_label_level ();
		  last_tree = COMPOUND_BODY ((yyvsp[(1) - (3)].ttype));
		  TREE_CHAIN (last_tree) = NULL_TREE;
		  (yyval.ttype) = error_mark_node;
		;}
    break;

  case 94:
#line 641 "c-parse.y"
    { (yyval.ttype) = build_function_call ((yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 95:
#line 643 "c-parse.y"
    { (yyval.ttype) = build_va_arg ((yyvsp[(3) - (6)].ttype), groktypename ((yyvsp[(5) - (6)].ttype))); ;}
    break;

  case 96:
#line 645 "c-parse.y"
    { (yyval.ttype) = build_array_ref ((yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 97:
#line 647 "c-parse.y"
    {
		    (yyval.ttype) = build_component_ref ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype));
		;}
    break;

  case 98:
#line 651 "c-parse.y"
    {
                  tree expr = build_indirect_ref ((yyvsp[(1) - (3)].ttype), "->");

                    (yyval.ttype) = build_component_ref (expr, (yyvsp[(3) - (3)].ttype));
		;}
    break;

  case 99:
#line 657 "c-parse.y"
    { (yyval.ttype) = build_unary_op (POSTINCREMENT_EXPR, (yyvsp[(1) - (2)].ttype), 0); ;}
    break;

  case 100:
#line 659 "c-parse.y"
    { (yyval.ttype) = build_unary_op (POSTDECREMENT_EXPR, (yyvsp[(1) - (2)].ttype), 0); ;}
    break;

  case 102:
#line 666 "c-parse.y"
    {
                  static int last_lineno = 0;
                  static const char *last_input_filename = 0;
                  (yyval.ttype) = chainon ((yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype));
		  if (warn_traditional && !in_system_header
		      && (lineno != last_lineno || !last_input_filename ||
			  strcmp (last_input_filename, input_filename)))
		    {
		      warning ("traditional C rejects string concatenation");
		      last_lineno = lineno;
		      last_input_filename = input_filename;
		    }
		;}
    break;

  case 105:
#line 687 "c-parse.y"
    { c_mark_varargs ();
		  if (pedantic)
		    pedwarn ("ISO C does not permit use of `varargs.h'"); ;}
    break;

  case 106:
#line 697 "c-parse.y"
    { ;}
    break;

  case 111:
#line 713 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 112:
#line 717 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);	
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 113:
#line 721 "c-parse.y"
    { shadow_tag_warned ((yyvsp[(1) - (2)].ttype), 1);
		  pedwarn ("empty declaration"); ;}
    break;

  case 114:
#line 724 "c-parse.y"
    { pedwarn ("empty declaration"); ;}
    break;

  case 115:
#line 733 "c-parse.y"
    { ;}
    break;

  case 116:
#line 741 "c-parse.y"
    { pending_xref_error ();
		  declspec_stack = tree_cons (prefix_attributes,
					      current_declspecs,
					      declspec_stack);
		  split_specs_attrs ((yyvsp[(0) - (0)].ttype),
				     &current_declspecs, &prefix_attributes); ;}
    break;

  case 117:
#line 751 "c-parse.y"
    { prefix_attributes = chainon (prefix_attributes, (yyvsp[(0) - (0)].ttype)); ;}
    break;

  case 118:
#line 756 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 119:
#line 760 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 120:
#line 764 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 121:
#line 768 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 122:
#line 772 "c-parse.y"
    { shadow_tag ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 123:
#line 774 "c-parse.y"
    { pedwarn ("empty declaration"); ;}
    break;

  case 124:
#line 776 "c-parse.y"
    { RESTORE_WARN_FLAGS ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 125:
#line 786 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 126:
#line 788 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(3) - (3)].ttype), tree_cons (NULL_TREE, (yyvsp[(2) - (3)].ttype), (yyvsp[(1) - (3)].ttype))); ;}
    break;

  case 127:
#line 792 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 128:
#line 794 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 129:
#line 796 "c-parse.y"
    { if (extra_warnings)
		    warning ("`%s' is not at beginning of declaration",
			     IDENTIFIER_POINTER ((yyvsp[(2) - (2)].ttype)));
		  (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 130:
#line 801 "c-parse.y"
    { (yyval.ttype) = tree_cons ((yyvsp[(2) - (2)].ttype), NULL_TREE, (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 131:
#line 806 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 132:
#line 808 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(3) - (3)].ttype), tree_cons (NULL_TREE, (yyvsp[(2) - (3)].ttype), (yyvsp[(1) - (3)].ttype))); ;}
    break;

  case 133:
#line 813 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 134:
#line 815 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 135:
#line 817 "c-parse.y"
    { if (extra_warnings)
		    warning ("`%s' is not at beginning of declaration",
			     IDENTIFIER_POINTER ((yyvsp[(2) - (2)].ttype)));
		  (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 136:
#line 830 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 137:
#line 832 "c-parse.y"
    { (yyval.ttype) = tree_cons ((yyvsp[(1) - (1)].ttype), NULL_TREE, NULL_TREE); ;}
    break;

  case 138:
#line 834 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 139:
#line 836 "c-parse.y"
    { (yyval.ttype) = tree_cons ((yyvsp[(2) - (2)].ttype), NULL_TREE, (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 140:
#line 841 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (1)].ttype), NULL_TREE);
		  TREE_STATIC ((yyval.ttype)) = 1; ;}
    break;

  case 141:
#line 844 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (1)].ttype), NULL_TREE); ;}
    break;

  case 142:
#line 846 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype));
		  TREE_STATIC ((yyval.ttype)) = 1; ;}
    break;

  case 143:
#line 849 "c-parse.y"
    { if (extra_warnings && TREE_STATIC ((yyvsp[(1) - (2)].ttype)))
		    warning ("`%s' is not at beginning of declaration",
			     IDENTIFIER_POINTER ((yyvsp[(2) - (2)].ttype)));
		  (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype));
		  TREE_STATIC ((yyval.ttype)) = TREE_STATIC ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 144:
#line 863 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 145:
#line 865 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(3) - (3)].ttype), tree_cons (NULL_TREE, (yyvsp[(2) - (3)].ttype), (yyvsp[(1) - (3)].ttype))); ;}
    break;

  case 146:
#line 869 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 147:
#line 871 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 150:
#line 881 "c-parse.y"
    { /* For a typedef name, record the meaning, not the name.
		     In case of `foo foo, bar;'.  */
		  (yyval.ttype) = lookup_name ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 151:
#line 885 "c-parse.y"
    { (yyval.ttype) = TREE_TYPE ((yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 152:
#line 887 "c-parse.y"
    { (yyval.ttype) = groktypename ((yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 160:
#line 909 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 161:
#line 911 "c-parse.y"
    { if (TREE_CHAIN ((yyvsp[(3) - (4)].ttype))) (yyvsp[(3) - (4)].ttype) = combine_strings ((yyvsp[(3) - (4)].ttype));
		  (yyval.ttype) = (yyvsp[(3) - (4)].ttype);
		;}
    break;

  case 162:
#line 918 "c-parse.y"
    { (yyval.ttype) = start_decl ((yyvsp[(1) - (4)].ttype), current_declspecs, 1,
					  (yyvsp[(3) - (4)].ttype), prefix_attributes);
		  start_init ((yyval.ttype), (yyvsp[(2) - (4)].ttype), global_bindings_p ()); ;}
    break;

  case 163:
#line 923 "c-parse.y"
    { finish_init ();
		  finish_decl ((yyvsp[(5) - (6)].ttype), (yyvsp[(6) - (6)].ttype), (yyvsp[(2) - (6)].ttype)); ;}
    break;

  case 164:
#line 926 "c-parse.y"
    { tree d = start_decl ((yyvsp[(1) - (3)].ttype), current_declspecs, 0,
				       (yyvsp[(3) - (3)].ttype), prefix_attributes);
		  finish_decl (d, NULL_TREE, (yyvsp[(2) - (3)].ttype)); 
                ;}
    break;

  case 165:
#line 934 "c-parse.y"
    { (yyval.ttype) = start_decl ((yyvsp[(1) - (4)].ttype), current_declspecs, 1,
					  (yyvsp[(3) - (4)].ttype), prefix_attributes);
		  start_init ((yyval.ttype), (yyvsp[(2) - (4)].ttype), global_bindings_p ()); ;}
    break;

  case 166:
#line 939 "c-parse.y"
    { finish_init ();
		  decl_attributes ((yyvsp[(5) - (6)].ttype), (yyvsp[(3) - (6)].ttype), prefix_attributes);
		  finish_decl ((yyvsp[(5) - (6)].ttype), (yyvsp[(6) - (6)].ttype), (yyvsp[(2) - (6)].ttype)); ;}
    break;

  case 167:
#line 943 "c-parse.y"
    { tree d = start_decl ((yyvsp[(1) - (3)].ttype), current_declspecs, 0,
				       (yyvsp[(3) - (3)].ttype), prefix_attributes);
		  finish_decl (d, NULL_TREE, (yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 168:
#line 951 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 169:
#line 953 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 170:
#line 958 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 171:
#line 960 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 172:
#line 965 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(4) - (6)].ttype); ;}
    break;

  case 173:
#line 970 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 174:
#line 972 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 175:
#line 977 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 176:
#line 979 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (1)].ttype), NULL_TREE); ;}
    break;

  case 177:
#line 981 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (4)].ttype), build_tree_list (NULL_TREE, (yyvsp[(3) - (4)].ttype))); ;}
    break;

  case 178:
#line 983 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (6)].ttype), tree_cons (NULL_TREE, (yyvsp[(3) - (6)].ttype), (yyvsp[(5) - (6)].ttype))); ;}
    break;

  case 179:
#line 985 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 185:
#line 1003 "c-parse.y"
    { really_start_incremental_init (NULL_TREE); ;}
    break;

  case 186:
#line 1005 "c-parse.y"
    { (yyval.ttype) = pop_init_level (0); ;}
    break;

  case 187:
#line 1007 "c-parse.y"
    { (yyval.ttype) = error_mark_node; ;}
    break;

  case 188:
#line 1013 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ISO C forbids empty initializer braces"); ;}
    break;

  case 192:
#line 1027 "c-parse.y"
    { if (pedantic && ! flag_isoc99)
		    pedwarn ("ISO C89 forbids specifying subobject to initialize"); ;}
    break;

  case 193:
#line 1030 "c-parse.y"
    { if (pedantic)
		    pedwarn ("obsolete use of designated initializer without `='"); ;}
    break;

  case 194:
#line 1033 "c-parse.y"
    { set_init_label ((yyvsp[(1) - (2)].ttype));
		  if (pedantic)
		    pedwarn ("obsolete use of designated initializer with `:'"); ;}
    break;

  case 197:
#line 1042 "c-parse.y"
    { push_init_level (0); ;}
    break;

  case 198:
#line 1044 "c-parse.y"
    { process_init_element (pop_init_level (0)); ;}
    break;

  case 199:
#line 1046 "c-parse.y"
    { process_init_element ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 203:
#line 1057 "c-parse.y"
    { set_init_label ((yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 204:
#line 1062 "c-parse.y"
    { set_init_index ((yyvsp[(2) - (5)].ttype), (yyvsp[(4) - (5)].ttype));
		  if (pedantic)
		    pedwarn ("ISO C forbids specifying range of elements to initialize"); ;}
    break;

  case 205:
#line 1066 "c-parse.y"
    { set_init_index ((yyvsp[(2) - (3)].ttype), NULL_TREE); ;}
    break;

  case 206:
#line 1071 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ISO C forbids nested functions");

		  push_function_context ();
		  if (! start_function (current_declspecs, (yyvsp[(1) - (1)].ttype),
					prefix_attributes, NULL_TREE))
		    {
		      pop_function_context ();
		      YYERROR1;
		    }
		;}
    break;

  case 207:
#line 1083 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 208:
#line 1091 "c-parse.y"
    { tree decl = current_function_decl;
		  DECL_SOURCE_FILE (decl) = (yyvsp[(5) - (7)].filename);
		  DECL_SOURCE_LINE (decl) = (yyvsp[(6) - (7)].lineno);
		  finish_function (1);
		  pop_function_context (); 
		  add_decl_stmt (decl); ;}
    break;

  case 209:
#line 1101 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ISO C forbids nested functions");

		  push_function_context ();
		  if (! start_function (current_declspecs, (yyvsp[(1) - (1)].ttype),
					prefix_attributes, NULL_TREE))
		    {
		      pop_function_context ();
		      YYERROR1;
		    }
		;}
    break;

  case 210:
#line 1113 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 211:
#line 1121 "c-parse.y"
    { tree decl = current_function_decl;
		  DECL_SOURCE_FILE (decl) = (yyvsp[(5) - (7)].filename);
		  DECL_SOURCE_LINE (decl) = (yyvsp[(6) - (7)].lineno);
		  finish_function (1);
		  pop_function_context (); 
		  add_decl_stmt (decl); ;}
    break;

  case 214:
#line 1141 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (3)].ttype); ;}
    break;

  case 215:
#line 1143 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype), NULL_TREE); ;}
    break;

  case 216:
#line 1148 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 217:
#line 1150 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (3)].ttype), NULL_TREE); ;}
    break;

  case 218:
#line 1152 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 219:
#line 1159 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype); ;}
    break;

  case 221:
#line 1170 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype), NULL_TREE); ;}
    break;

  case 222:
#line 1175 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), NULL_TREE);
		  if (! flag_isoc99)
		    error ("`[*]' in parameter declaration only allowed in ISO C 99");
		;}
    break;

  case 223:
#line 1180 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 224:
#line 1182 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (3)].ttype), NULL_TREE); ;}
    break;

  case 225:
#line 1184 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 226:
#line 1191 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype); ;}
    break;

  case 228:
#line 1200 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype), NULL_TREE); ;}
    break;

  case 229:
#line 1205 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (3)].ttype); ;}
    break;

  case 230:
#line 1207 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 231:
#line 1209 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), NULL_TREE);
		  if (! flag_isoc99)
		    error ("`[*]' in parameter declaration only allowed in ISO C 99");
		;}
    break;

  case 232:
#line 1214 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 233:
#line 1216 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (3)].ttype), NULL_TREE); ;}
    break;

  case 234:
#line 1223 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype); ;}
    break;

  case 236:
#line 1229 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 237:
#line 1231 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype); ;}
    break;

  case 238:
#line 1236 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 239:
#line 1238 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype); ;}
    break;

  case 240:
#line 1243 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 241:
#line 1245 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype); ;}
    break;

  case 242:
#line 1250 "c-parse.y"
    { (yyval.ttype) = start_struct (RECORD_TYPE, (yyvsp[(2) - (3)].ttype));
		  /* Start scope of tag before parsing components.  */
		;}
    break;

  case 243:
#line 1254 "c-parse.y"
    { (yyval.ttype) = finish_struct ((yyvsp[(4) - (7)].ttype), (yyvsp[(5) - (7)].ttype), chainon ((yyvsp[(1) - (7)].ttype), (yyvsp[(7) - (7)].ttype))); ;}
    break;

  case 244:
#line 1256 "c-parse.y"
    { (yyval.ttype) = finish_struct (start_struct (RECORD_TYPE, NULL_TREE),
				      (yyvsp[(3) - (5)].ttype), chainon ((yyvsp[(1) - (5)].ttype), (yyvsp[(5) - (5)].ttype)));
		;}
    break;

  case 245:
#line 1260 "c-parse.y"
    { (yyval.ttype) = xref_tag (RECORD_TYPE, (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 246:
#line 1262 "c-parse.y"
    { (yyval.ttype) = start_struct (UNION_TYPE, (yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 247:
#line 1264 "c-parse.y"
    { (yyval.ttype) = finish_struct ((yyvsp[(4) - (7)].ttype), (yyvsp[(5) - (7)].ttype), chainon ((yyvsp[(1) - (7)].ttype), (yyvsp[(7) - (7)].ttype))); ;}
    break;

  case 248:
#line 1266 "c-parse.y"
    { (yyval.ttype) = finish_struct (start_struct (UNION_TYPE, NULL_TREE),
				      (yyvsp[(3) - (5)].ttype), chainon ((yyvsp[(1) - (5)].ttype), (yyvsp[(5) - (5)].ttype)));
		;}
    break;

  case 249:
#line 1270 "c-parse.y"
    { (yyval.ttype) = xref_tag (UNION_TYPE, (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 250:
#line 1272 "c-parse.y"
    { (yyval.ttype) = start_enum ((yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 251:
#line 1274 "c-parse.y"
    { (yyval.ttype) = finish_enum ((yyvsp[(4) - (8)].ttype), nreverse ((yyvsp[(5) - (8)].ttype)),
				    chainon ((yyvsp[(1) - (8)].ttype), (yyvsp[(8) - (8)].ttype))); ;}
    break;

  case 252:
#line 1277 "c-parse.y"
    { (yyval.ttype) = start_enum (NULL_TREE); ;}
    break;

  case 253:
#line 1279 "c-parse.y"
    { (yyval.ttype) = finish_enum ((yyvsp[(3) - (7)].ttype), nreverse ((yyvsp[(4) - (7)].ttype)),
				    chainon ((yyvsp[(1) - (7)].ttype), (yyvsp[(7) - (7)].ttype))); ;}
    break;

  case 254:
#line 1282 "c-parse.y"
    { (yyval.ttype) = xref_tag (ENUMERAL_TYPE, (yyvsp[(2) - (2)].ttype));
		  /* In ISO C, enumerated types can be referred to
		     only if already defined.  */
		  if (pedantic && !COMPLETE_TYPE_P ((yyval.ttype)))
		    pedwarn ("ISO C forbids forward references to `enum' types"); ;}
    break;

  case 258:
#line 1297 "c-parse.y"
    { if (pedantic && ! flag_isoc99)
		    pedwarn ("comma at end of enumerator list"); ;}
    break;

  case 259:
#line 1303 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 260:
#line 1305 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype));
		  pedwarn ("no semicolon at end of struct or union"); ;}
    break;

  case 261:
#line 1310 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 262:
#line 1312 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), (yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 263:
#line 1314 "c-parse.y"
    { if (pedantic)
		    pedwarn ("extra semicolon in struct or union specified"); ;}
    break;

  case 264:
#line 1329 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype);
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 265:
#line 1334 "c-parse.y"
    {
		  /* Support for unnamed structs or unions as members of 
		     structs or unions (which is [a] useful and [b] supports 
		     MS P-SDK).  */
		  if (pedantic)
		    pedwarn ("ISO C doesn't support unnamed structs/unions");

		  (yyval.ttype) = grokfield((yyvsp[(3) - (5)].filename), (yyvsp[(4) - (5)].lineno), NULL, current_declspecs, NULL_TREE);
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack);
		;}
    break;

  case 266:
#line 1347 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype);
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 267:
#line 1352 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ISO C forbids member declarations with no members");
		  shadow_tag((yyvsp[(1) - (1)].ttype));
		  (yyval.ttype) = NULL_TREE; ;}
    break;

  case 268:
#line 1357 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 269:
#line 1359 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype);
		  RESTORE_WARN_FLAGS ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 271:
#line 1366 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 272:
#line 1371 "c-parse.y"
    { (yyval.ttype) = grokfield ((yyvsp[(1) - (4)].filename), (yyvsp[(2) - (4)].lineno), (yyvsp[(3) - (4)].ttype), current_declspecs, NULL_TREE);
		  decl_attributes ((yyval.ttype), (yyvsp[(4) - (4)].ttype), prefix_attributes); ;}
    break;

  case 273:
#line 1375 "c-parse.y"
    { (yyval.ttype) = grokfield ((yyvsp[(1) - (6)].filename), (yyvsp[(2) - (6)].lineno), (yyvsp[(3) - (6)].ttype), current_declspecs, (yyvsp[(5) - (6)].ttype));
		  decl_attributes ((yyval.ttype), (yyvsp[(6) - (6)].ttype), prefix_attributes); ;}
    break;

  case 274:
#line 1378 "c-parse.y"
    { (yyval.ttype) = grokfield ((yyvsp[(1) - (5)].filename), (yyvsp[(2) - (5)].lineno), NULL_TREE, current_declspecs, (yyvsp[(4) - (5)].ttype));
		  decl_attributes ((yyval.ttype), (yyvsp[(5) - (5)].ttype), prefix_attributes); ;}
    break;

  case 276:
#line 1390 "c-parse.y"
    { if ((yyvsp[(1) - (3)].ttype) == error_mark_node)
		    (yyval.ttype) = (yyvsp[(1) - (3)].ttype);
		  else
		    (yyval.ttype) = chainon ((yyvsp[(3) - (3)].ttype), (yyvsp[(1) - (3)].ttype)); ;}
    break;

  case 277:
#line 1395 "c-parse.y"
    { (yyval.ttype) = error_mark_node; ;}
    break;

  case 278:
#line 1401 "c-parse.y"
    { (yyval.ttype) = build_enumerator ((yyvsp[(1) - (1)].ttype), NULL_TREE); ;}
    break;

  case 279:
#line 1403 "c-parse.y"
    { (yyval.ttype) = build_enumerator ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 280:
#line 1408 "c-parse.y"
    { pending_xref_error (); ;}
    break;

  case 281:
#line 1410 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 282:
#line 1412 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 283:
#line 1417 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 285:
#line 1423 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (1)].ttype), NULL_TREE); ;}
    break;

  case 286:
#line 1425 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 287:
#line 1430 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 288:
#line 1432 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 289:
#line 1437 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (3)].ttype); ;}
    break;

  case 290:
#line 1440 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 291:
#line 1442 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (2)].ttype), NULL_TREE); ;}
    break;

  case 292:
#line 1444 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype), NULL_TREE); ;}
    break;

  case 293:
#line 1446 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 294:
#line 1448 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (3)].ttype), NULL_TREE); ;}
    break;

  case 295:
#line 1450 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, NULL_TREE, (yyvsp[(2) - (2)].ttype), NULL_TREE); ;}
    break;

  case 296:
#line 1452 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, NULL_TREE, (yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 297:
#line 1454 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, NULL_TREE, NULL_TREE); ;}
    break;

  case 298:
#line 1458 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype); ;}
    break;

  case 301:
#line 1471 "c-parse.y"
    {
		  pedwarn ("deprecated use of label at end of compound statement");
		;}
    break;

  case 309:
#line 1488 "c-parse.y"
    { if (pedantic && !flag_isoc99)
		    pedwarn ("ISO C89 forbids mixed declarations and code"); ;}
    break;

  case 324:
#line 1518 "c-parse.y"
    { pushlevel (0);
		  clear_last_expr ();
		  add_scope_stmt (/*begin_p=*/1, /*partial_p=*/0);
		;}
    break;

  case 325:
#line 1525 "c-parse.y"
    { (yyval.ttype) = add_scope_stmt (/*begin_p=*/0, /*partial_p=*/0); ;}
    break;

  case 326:
#line 1529 "c-parse.y"
    { if (flag_isoc99)
		    {
		      (yyval.ttype) = c_begin_compound_stmt ();
		      pushlevel (0);
		      clear_last_expr ();
		      add_scope_stmt (/*begin_p=*/1, /*partial_p=*/0);
		    }
		  else
		    (yyval.ttype) = NULL_TREE;
		;}
    break;

  case 327:
#line 1545 "c-parse.y"
    { if (flag_isoc99)
		    {
		      tree scope_stmt = add_scope_stmt (/*begin_p=*/0, /*partial_p=*/0);
		      (yyval.ttype) = poplevel (kept_level_p (), 0, 0); 
		      SCOPE_STMT_BLOCK (TREE_PURPOSE (scope_stmt)) 
			= SCOPE_STMT_BLOCK (TREE_VALUE (scope_stmt))
			= (yyval.ttype);
		    }
		  else
		    (yyval.ttype) = NULL_TREE; ;}
    break;

  case 329:
#line 1562 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ISO C forbids label declarations"); ;}
    break;

  case 332:
#line 1573 "c-parse.y"
    { tree link;
		  for (link = (yyvsp[(2) - (3)].ttype); link; link = TREE_CHAIN (link))
		    {
		      tree label = shadow_label (TREE_VALUE (link));
		      C_DECLARED_LABEL_FLAG (label) = 1;
		      add_decl_stmt (label);
		    }
		;}
    break;

  case 333:
#line 1587 "c-parse.y"
    {;}
    break;

  case 335:
#line 1591 "c-parse.y"
    { compstmt_count++;
                      (yyval.ttype) = c_begin_compound_stmt (); ;}
    break;

  case 336:
#line 1595 "c-parse.y"
    { (yyval.ttype) = convert (void_type_node, integer_zero_node); ;}
    break;

  case 337:
#line 1597 "c-parse.y"
    { (yyval.ttype) = poplevel (kept_level_p (), 1, 0); 
		  SCOPE_STMT_BLOCK (TREE_PURPOSE ((yyvsp[(5) - (5)].ttype))) 
		    = SCOPE_STMT_BLOCK (TREE_VALUE ((yyvsp[(5) - (5)].ttype)))
		    = (yyval.ttype); ;}
    break;

  case 340:
#line 1610 "c-parse.y"
    { if (current_function_decl == 0)
		    {
		      error ("braced-group within expression allowed only inside a function");
		      YYERROR;
		    }
		  /* We must force a BLOCK for this level
		     so that, if it is not expanded later,
		     there is a way to turn off the entire subtree of blocks
		     that are contained in it.  */
		  keep_next_level ();
		  push_label_level ();
		  compstmt_count++;
		  (yyval.ttype) = add_stmt (build_stmt (COMPOUND_STMT, last_tree));
		;}
    break;

  case 341:
#line 1626 "c-parse.y"
    { RECHAIN_STMTS ((yyvsp[(1) - (2)].ttype), COMPOUND_BODY ((yyvsp[(1) - (2)].ttype))); 
                  (yyval.ttype) = (yyvsp[(1) - (2)].ttype); ;}
    break;

  case 342:
#line 1633 "c-parse.y"
    { c_finish_then (); ;}
    break;

  case 344:
#line 1642 "c-parse.y"
    { c_expand_start_cond (truthvalue_conversion ((yyvsp[(3) - (4)].ttype)), 
				       compstmt_count);
		  (yyval.itype) = stmt_count;
		  if_stmt_file = (yyvsp[(-2) - (4)].filename);
		  if_stmt_line = (yyvsp[(-1) - (4)].lineno); ;}
    break;

  case 345:
#line 1654 "c-parse.y"
    { stmt_count++;
		  compstmt_count++;
		  (yyval.ttype) 
		    = add_stmt (build_stmt (DO_STMT, NULL_TREE,
					    NULL_TREE));
		  /* In the event that a parse error prevents
		     parsing the complete do-statement, set the
		     condition now.  Otherwise, we can get crashes at
		     RTL-generation time.  */
		  DO_COND ((yyval.ttype)) = error_mark_node; ;}
    break;

  case 346:
#line 1665 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (4)].ttype);
		  RECHAIN_STMTS ((yyval.ttype), DO_BODY ((yyval.ttype))); ;}
    break;

  case 347:
#line 1673 "c-parse.y"
    { if (yychar == YYEMPTY)
		    yychar = YYLEX;
		  (yyval.filename) = input_filename; ;}
    break;

  case 348:
#line 1679 "c-parse.y"
    { if (yychar == YYEMPTY)
		    yychar = YYLEX;
		  (yyval.lineno) = lineno; ;}
    break;

  case 351:
#line 1692 "c-parse.y"
    { if (flag_isoc99)
		    RECHAIN_STMTS ((yyvsp[(1) - (3)].ttype), COMPOUND_BODY ((yyvsp[(1) - (3)].ttype))); ;}
    break;

  case 352:
#line 1698 "c-parse.y"
    { if ((yyvsp[(3) - (3)].ttype))
		    {
		      STMT_LINENO ((yyvsp[(3) - (3)].ttype)) = (yyvsp[(2) - (3)].lineno);
		      /* ??? We currently have no way of recording
			 the filename for a statement.  This probably
			 matters little in practice at the moment,
			 but I suspect that problems will ocurr when
			 doing inlining at the tree level.  */
		    }
		;}
    break;

  case 353:
#line 1712 "c-parse.y"
    { if ((yyvsp[(3) - (3)].ttype))
		    {
		      STMT_LINENO ((yyvsp[(3) - (3)].ttype)) = (yyvsp[(2) - (3)].lineno);
		    }
		;}
    break;

  case 354:
#line 1721 "c-parse.y"
    { c_expand_start_else ();
		  (yyvsp[(1) - (2)].itype) = stmt_count; ;}
    break;

  case 355:
#line 1724 "c-parse.y"
    { c_finish_else ();
		  c_expand_end_cond ();
		  if (extra_warnings && stmt_count == (yyvsp[(1) - (4)].itype))
		    warning ("empty body in an else-statement"); ;}
    break;

  case 356:
#line 1729 "c-parse.y"
    { c_expand_end_cond ();
		  /* This warning is here instead of in simple_if, because we
		     do not want a warning if an empty if is followed by an
		     else statement.  Increment stmt_count so we don't
		     give a second error if this is a nested `if'.  */
		  if (extra_warnings && stmt_count++ == (yyvsp[(1) - (1)].itype))
		    warning_with_file_and_line (if_stmt_file, if_stmt_line,
						"empty body in an if-statement"); ;}
    break;

  case 357:
#line 1741 "c-parse.y"
    { c_expand_end_cond (); ;}
    break;

  case 358:
#line 1743 "c-parse.y"
    { stmt_count++; ;}
    break;

  case 359:
#line 1745 "c-parse.y"
    { (yyvsp[(4) - (5)].ttype) = truthvalue_conversion ((yyvsp[(4) - (5)].ttype));
		  (yyval.ttype) 
		    = add_stmt (build_stmt (WHILE_STMT, (yyvsp[(4) - (5)].ttype), NULL_TREE)); ;}
    break;

  case 360:
#line 1749 "c-parse.y"
    { RECHAIN_STMTS ((yyvsp[(6) - (7)].ttype), WHILE_BODY ((yyvsp[(6) - (7)].ttype))); ;}
    break;

  case 361:
#line 1752 "c-parse.y"
    { DO_COND ((yyvsp[(1) - (5)].ttype)) = truthvalue_conversion ((yyvsp[(3) - (5)].ttype)); ;}
    break;

  case 362:
#line 1754 "c-parse.y"
    { ;}
    break;

  case 363:
#line 1756 "c-parse.y"
    { (yyval.ttype) = build_stmt (FOR_STMT, NULL_TREE, NULL_TREE,
					  NULL_TREE, NULL_TREE);
		  add_stmt ((yyval.ttype)); ;}
    break;

  case 364:
#line 1760 "c-parse.y"
    { stmt_count++;
		  RECHAIN_STMTS ((yyvsp[(2) - (4)].ttype), FOR_INIT_STMT ((yyvsp[(2) - (4)].ttype))); ;}
    break;

  case 365:
#line 1763 "c-parse.y"
    { if ((yyvsp[(6) - (7)].ttype)) 
		    FOR_COND ((yyvsp[(2) - (7)].ttype)) = truthvalue_conversion ((yyvsp[(6) - (7)].ttype)); ;}
    break;

  case 366:
#line 1766 "c-parse.y"
    { FOR_EXPR ((yyvsp[(2) - (10)].ttype)) = (yyvsp[(9) - (10)].ttype); ;}
    break;

  case 367:
#line 1768 "c-parse.y"
    { RECHAIN_STMTS ((yyvsp[(2) - (12)].ttype), FOR_BODY ((yyvsp[(2) - (12)].ttype))); ;}
    break;

  case 368:
#line 1770 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = c_start_case ((yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 369:
#line 1773 "c-parse.y"
    { c_finish_case (); ;}
    break;

  case 370:
#line 1778 "c-parse.y"
    { add_stmt (build_stmt (EXPR_STMT, (yyvsp[(1) - (2)].ttype))); ;}
    break;

  case 371:
#line 1780 "c-parse.y"
    { check_for_loop_decls (); ;}
    break;

  case 372:
#line 1786 "c-parse.y"
    { stmt_count++; (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 373:
#line 1788 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = c_expand_expr_stmt ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 374:
#line 1791 "c-parse.y"
    { if (flag_isoc99)
		    RECHAIN_STMTS ((yyvsp[(1) - (3)].ttype), COMPOUND_BODY ((yyvsp[(1) - (3)].ttype)));
		  (yyval.ttype) = NULL_TREE; ;}
    break;

  case 375:
#line 1795 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = add_stmt (build_break_stmt ()); ;}
    break;

  case 376:
#line 1798 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = add_stmt (build_continue_stmt ()); ;}
    break;

  case 377:
#line 1801 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = c_expand_return (NULL_TREE); ;}
    break;

  case 378:
#line 1804 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = c_expand_return ((yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 379:
#line 1807 "c-parse.y"
    { stmt_count++;
		  STRIP_NOPS ((yyvsp[(4) - (6)].ttype));
		  if ((TREE_CODE ((yyvsp[(4) - (6)].ttype)) == ADDR_EXPR
		       && TREE_CODE (TREE_OPERAND ((yyvsp[(4) - (6)].ttype), 0)) == STRING_CST)
		      || TREE_CODE ((yyvsp[(4) - (6)].ttype)) == STRING_CST)
		    {
		      if (TREE_CODE ((yyvsp[(4) - (6)].ttype)) == ADDR_EXPR)
			(yyvsp[(4) - (6)].ttype) = TREE_OPERAND ((yyvsp[(4) - (6)].ttype), 0);
		      if (TREE_CHAIN ((yyvsp[(4) - (6)].ttype)))
			(yyvsp[(4) - (6)].ttype) = combine_strings ((yyvsp[(4) - (6)].ttype));
		      (yyval.ttype) = add_stmt (build_stmt (ASM_STMT, NULL_TREE, (yyvsp[(4) - (6)].ttype),
						 NULL_TREE, NULL_TREE,
						 NULL_TREE));
		      ASM_INPUT_P ((yyval.ttype)) = 1;
		    }
		  else
		    {
		      error ("argument of `asm' is not a constant string");
		      (yyval.ttype) = NULL_TREE;
		    }
		;}
    break;

  case 380:
#line 1830 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = build_asm_stmt ((yyvsp[(2) - (8)].ttype), (yyvsp[(4) - (8)].ttype), (yyvsp[(6) - (8)].ttype), NULL_TREE, NULL_TREE); ;}
    break;

  case 381:
#line 1835 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = build_asm_stmt ((yyvsp[(2) - (10)].ttype), (yyvsp[(4) - (10)].ttype), (yyvsp[(6) - (10)].ttype), (yyvsp[(8) - (10)].ttype), NULL_TREE); ;}
    break;

  case 382:
#line 1840 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = build_asm_stmt ((yyvsp[(2) - (12)].ttype), (yyvsp[(4) - (12)].ttype), (yyvsp[(6) - (12)].ttype), (yyvsp[(8) - (12)].ttype), (yyvsp[(10) - (12)].ttype)); ;}
    break;

  case 383:
#line 1843 "c-parse.y"
    { tree decl;
		  stmt_count++;
		  decl = lookup_label ((yyvsp[(2) - (3)].ttype));
		  if (decl != 0)
		    {
		      TREE_USED (decl) = 1;
		      (yyval.ttype) = add_stmt (build_stmt (GOTO_STMT, decl));
		    }
		  else
		    (yyval.ttype) = NULL_TREE;
		;}
    break;

  case 384:
#line 1855 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ISO C forbids `goto *expr;'");
		  stmt_count++;
		  (yyvsp[(3) - (4)].ttype) = convert (ptr_type_node, (yyvsp[(3) - (4)].ttype));
		  (yyval.ttype) = add_stmt (build_stmt (GOTO_STMT, (yyvsp[(3) - (4)].ttype))); ;}
    break;

  case 385:
#line 1861 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 386:
#line 1869 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = do_case ((yyvsp[(2) - (3)].ttype), NULL_TREE); ;}
    break;

  case 387:
#line 1872 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = do_case ((yyvsp[(2) - (5)].ttype), (yyvsp[(4) - (5)].ttype)); ;}
    break;

  case 388:
#line 1875 "c-parse.y"
    { stmt_count++;
		  (yyval.ttype) = do_case (NULL_TREE, NULL_TREE); ;}
    break;

  case 389:
#line 1878 "c-parse.y"
    { tree label = define_label ((yyvsp[(2) - (5)].filename), (yyvsp[(3) - (5)].lineno), (yyvsp[(1) - (5)].ttype));
		  stmt_count++;
		  if (label)
		    {
		      decl_attributes (label, (yyvsp[(5) - (5)].ttype), NULL_TREE);
		      (yyval.ttype) = add_stmt (build_stmt (LABEL_STMT, label));
		    }
		  else
		    (yyval.ttype) = NULL_TREE;
		;}
    break;

  case 390:
#line 1894 "c-parse.y"
    { emit_line_note (input_filename, lineno);
		  (yyval.ttype) = NULL_TREE; ;}
    break;

  case 391:
#line 1897 "c-parse.y"
    { emit_line_note (input_filename, lineno); ;}
    break;

  case 392:
#line 1902 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 394:
#line 1909 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 397:
#line 1916 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 398:
#line 1921 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 399:
#line 1926 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, combine_strings ((yyvsp[(1) - (1)].ttype)), NULL_TREE); ;}
    break;

  case 400:
#line 1928 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, combine_strings ((yyvsp[(3) - (3)].ttype)), (yyvsp[(1) - (3)].ttype)); ;}
    break;

  case 401:
#line 1934 "c-parse.y"
    { pushlevel (0);
		  clear_parm_order ();
		  declare_parm_level (0); ;}
    break;

  case 402:
#line 1938 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype);
		  parmlist_tags_warning ();
		  poplevel (0, 0, 0); ;}
    break;

  case 404:
#line 1946 "c-parse.y"
    { tree parm;
		  if (pedantic)
		    pedwarn ("ISO C forbids forward parameter declarations");
		  /* Mark the forward decls as such.  */
		  for (parm = getdecls (); parm; parm = TREE_CHAIN (parm))
		    TREE_ASM_WRITTEN (parm) = 1;
		  clear_parm_order (); ;}
    break;

  case 405:
#line 1954 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(4) - (4)].ttype); ;}
    break;

  case 406:
#line 1956 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, NULL_TREE, NULL_TREE); ;}
    break;

  case 407:
#line 1962 "c-parse.y"
    { (yyval.ttype) = get_parm_info (0); ;}
    break;

  case 408:
#line 1964 "c-parse.y"
    { (yyval.ttype) = get_parm_info (0);
		  /* Gcc used to allow this as an extension.  However, it does
		     not work for all targets, and thus has been disabled.
		     Also, since func (...) and func () are indistinguishable,
		     it caused problems with the code in expand_builtin which
		     tries to verify that BUILT_IN_NEXT_ARG is being used
		     correctly.  */
		  error ("ISO C requires a named argument before `...'");
		;}
    break;

  case 409:
#line 1974 "c-parse.y"
    { (yyval.ttype) = get_parm_info (1); ;}
    break;

  case 410:
#line 1976 "c-parse.y"
    { (yyval.ttype) = get_parm_info (0); ;}
    break;

  case 411:
#line 1981 "c-parse.y"
    { push_parm_decl ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 412:
#line 1983 "c-parse.y"
    { push_parm_decl ((yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 413:
#line 1990 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype)));
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 414:
#line 1998 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype))); 
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 415:
#line 2006 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype)));
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 416:
#line 2014 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype)));
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 417:
#line 2023 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype)));
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 418:
#line 2036 "c-parse.y"
    { pushlevel (0);
		  clear_parm_order ();
		  declare_parm_level (1); ;}
    break;

  case 419:
#line 2040 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype);
		  parmlist_tags_warning ();
		  poplevel (0, 0, 0); ;}
    break;

  case 421:
#line 2048 "c-parse.y"
    { tree t;
		  for (t = (yyvsp[(1) - (2)].ttype); t; t = TREE_CHAIN (t))
		    if (TREE_VALUE (t) == NULL_TREE)
		      error ("`...' in old-style identifier list");
		  (yyval.ttype) = tree_cons (NULL_TREE, NULL_TREE, (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 422:
#line 2058 "c-parse.y"
    { (yyval.ttype) = build_tree_list (NULL_TREE, (yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 423:
#line 2060 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), build_tree_list (NULL_TREE, (yyvsp[(3) - (3)].ttype))); ;}
    break;

  case 424:
#line 2066 "c-parse.y"
    { (yyval.ttype) = build_tree_list (NULL_TREE, (yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 425:
#line 2068 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), build_tree_list (NULL_TREE, (yyvsp[(3) - (3)].ttype))); ;}
    break;

  case 426:
#line 2073 "c-parse.y"
    { (yyval.ttype) = SAVE_WARN_FLAGS();
		  pedantic = 0;
		  warn_pointer_arith = 0; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 4843 "c-p36620.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 2078 "c-parse.y"


/* yylex() is a thin wrapper around c_lex(), all it does is translate
   cpplib.h's token codes into yacc's token codes.  */

static enum cpp_ttype last_token;

/* The reserved keyword table.  */
struct resword
{
  const char *word;
  ENUM_BITFIELD(rid) rid : 16;
  unsigned int disable   : 16;
};

/* Disable mask.  Keywords are disabled if (reswords[i].disable & mask) is
   _true_.  */
#define D_TRAD	0x01	/* not in traditional C */
#define D_C89	0x02	/* not in C89 */
#define D_EXT	0x04	/* GCC extension */
#define D_EXT89	0x08	/* GCC extension incorporated in C99 */
#define D_OBJC	0x10	/* Objective C only */

static const struct resword reswords[] =
{
  { "_Bool",		RID_BOOL,	0 },
  { "_Complex",		RID_COMPLEX,	0 },
  { "__alignof",	RID_ALIGNOF,	0 },
  { "__alignof__",	RID_ALIGNOF,	0 },
  { "__asm",		RID_ASM,	0 },
  { "__asm__",		RID_ASM,	0 },
  { "__attribute",	RID_ATTRIBUTE,	0 },
  { "__attribute__",	RID_ATTRIBUTE,	0 },
  { "__bounded",	RID_BOUNDED,	0 },
  { "__bounded__",	RID_BOUNDED,	0 },
  { "__builtin_va_arg",	RID_VA_ARG,	0 },
  { "__complex",	RID_COMPLEX,	0 },
  { "__complex__",	RID_COMPLEX,	0 },
  { "__const",		RID_CONST,	0 },
  { "__const__",	RID_CONST,	0 },
  { "__extension__",	RID_EXTENSION,	0 },
  { "__imag",		RID_IMAGPART,	0 },
  { "__imag__",		RID_IMAGPART,	0 },
  { "__inline",		RID_INLINE,	0 },
  { "__inline__",	RID_INLINE,	0 },
  { "__label__",	RID_LABEL,	0 },
  { "__ptrbase",	RID_PTRBASE,	0 },
  { "__ptrbase__",	RID_PTRBASE,	0 },
  { "__ptrextent",	RID_PTREXTENT,	0 },
  { "__ptrextent__",	RID_PTREXTENT,	0 },
  { "__ptrvalue",	RID_PTRVALUE,	0 },
  { "__ptrvalue__",	RID_PTRVALUE,	0 },
  { "__real",		RID_REALPART,	0 },
  { "__real__",		RID_REALPART,	0 },
  { "__restrict",	RID_RESTRICT,	0 },
  { "__restrict__",	RID_RESTRICT,	0 },
  { "__signed",		RID_SIGNED,	0 },
  { "__signed__",	RID_SIGNED,	0 },
  { "__typeof",		RID_TYPEOF,	0 },
  { "__typeof__",	RID_TYPEOF,	0 },
  { "__unbounded",	RID_UNBOUNDED,	0 },
  { "__unbounded__",	RID_UNBOUNDED,	0 },
  { "__volatile",	RID_VOLATILE,	0 },
  { "__volatile__",	RID_VOLATILE,	0 },
  { "asm",		RID_ASM,	D_EXT },
  { "auto",		RID_AUTO,	0 },
  { "break",		RID_BREAK,	0 },
  { "case",		RID_CASE,	0 },
  { "char",		RID_CHAR,	0 },
  { "const",		RID_CONST,	D_TRAD },
  { "continue",		RID_CONTINUE,	0 },
  { "default",		RID_DEFAULT,	0 },
  { "do",		RID_DO,		0 },
  { "double",		RID_DOUBLE,	0 },
  { "else",		RID_ELSE,	0 },
  { "enum",		RID_ENUM,	0 },
  { "extern",		RID_EXTERN,	0 },
  { "float",		RID_FLOAT,	0 },
  { "for",		RID_FOR,	0 },
  { "goto",		RID_GOTO,	0 },
  { "if",		RID_IF,		0 },
  { "inline",		RID_INLINE,	D_TRAD|D_EXT89 },
  { "int",		RID_INT,	0 },
  { "long",		RID_LONG,	0 },
  { "register",		RID_REGISTER,	0 },
  { "restrict",		RID_RESTRICT,	D_TRAD|D_C89 },
  { "return",		RID_RETURN,	0 },
  { "short",		RID_SHORT,	0 },
  { "signed",		RID_SIGNED,	D_TRAD },
  { "sizeof",		RID_SIZEOF,	0 },
  { "static",		RID_STATIC,	0 },
  { "struct",		RID_STRUCT,	0 },
  { "switch",		RID_SWITCH,	0 },
  { "typedef",		RID_TYPEDEF,	0 },
  { "typeof",		RID_TYPEOF,	D_TRAD|D_EXT },
  { "union",		RID_UNION,	0 },
  { "unsigned",		RID_UNSIGNED,	0 },
  { "void",		RID_VOID,	0 },
  { "volatile",		RID_VOLATILE,	D_TRAD },
  { "while",		RID_WHILE,	0 },
};
#define N_reswords (sizeof reswords / sizeof (struct resword))

/* Table mapping from RID_* constants to yacc token numbers.
   Unfortunately we have to have entries for all the keywords in all
   three languages.  */
static const short rid_to_yy[RID_MAX] =
{
  /* RID_STATIC */	SCSPEC,
  /* RID_UNSIGNED */	TYPESPEC,
  /* RID_LONG */	TYPESPEC,
  /* RID_CONST */	TYPE_QUAL,
  /* RID_EXTERN */	SCSPEC,
  /* RID_REGISTER */	SCSPEC,
  /* RID_TYPEDEF */	SCSPEC,
  /* RID_SHORT */	TYPESPEC,
  /* RID_INLINE */	SCSPEC,
  /* RID_VOLATILE */	TYPE_QUAL,
  /* RID_SIGNED */	TYPESPEC,
  /* RID_AUTO */	SCSPEC,
  /* RID_RESTRICT */	TYPE_QUAL,

  /* C extensions */
  /* RID_BOUNDED */	TYPE_QUAL,
  /* RID_UNBOUNDED */	TYPE_QUAL,
  /* RID_COMPLEX */	TYPESPEC,

  /* C++ */
  /* RID_FRIEND */	0,
  /* RID_VIRTUAL */	0,
  /* RID_EXPLICIT */	0,
  /* RID_EXPORT */	0,
  /* RID_MUTABLE */	0,

  /* ObjC */
  /* RID_IN */		TYPE_QUAL,
  /* RID_OUT */		TYPE_QUAL,
  /* RID_INOUT */	TYPE_QUAL,
  /* RID_BYCOPY */	TYPE_QUAL,
  /* RID_BYREF */	TYPE_QUAL,
  /* RID_ONEWAY */	TYPE_QUAL,
  
  /* C */
  /* RID_INT */		TYPESPEC,
  /* RID_CHAR */	TYPESPEC,
  /* RID_FLOAT */	TYPESPEC,
  /* RID_DOUBLE */	TYPESPEC,
  /* RID_VOID */	TYPESPEC,
  /* RID_ENUM */	ENUM,
  /* RID_STRUCT */	STRUCT,
  /* RID_UNION */	UNION,
  /* RID_IF */		IF,
  /* RID_ELSE */	ELSE,
  /* RID_WHILE */	WHILE,
  /* RID_DO */		DO,
  /* RID_FOR */		FOR,
  /* RID_SWITCH */	SWITCH,
  /* RID_CASE */	CASE,
  /* RID_DEFAULT */	DEFAULT,
  /* RID_BREAK */	BREAK,
  /* RID_CONTINUE */	CONTINUE,
  /* RID_RETURN */	RETURN,
  /* RID_GOTO */	GOTO,
  /* RID_SIZEOF */	SIZEOF,

  /* C extensions */
  /* RID_ASM */		ASM_KEYWORD,
  /* RID_TYPEOF */	TYPEOF,
  /* RID_ALIGNOF */	ALIGNOF,
  /* RID_ATTRIBUTE */	ATTRIBUTE,
  /* RID_VA_ARG */	VA_ARG,
  /* RID_EXTENSION */	EXTENSION,
  /* RID_IMAGPART */	IMAGPART,
  /* RID_REALPART */	REALPART,
  /* RID_LABEL */	LABEL,
  /* RID_PTRBASE */	PTR_BASE,
  /* RID_PTREXTENT */	PTR_EXTENT,
  /* RID_PTRVALUE */	PTR_VALUE,

  /* C++ */
  /* RID_BOOL */	TYPESPEC,
  /* RID_WCHAR */	0,
  /* RID_CLASS */	0,
  /* RID_PUBLIC */	0,
  /* RID_PRIVATE */	0,
  /* RID_PROTECTED */	0,
  /* RID_TEMPLATE */	0,
  /* RID_NULL */	0,
  /* RID_CATCH */	0,
  /* RID_DELETE */	0,
  /* RID_FALSE */	0,
  /* RID_NAMESPACE */	0,
  /* RID_NEW */		0,
  /* RID_OPERATOR */	0,
  /* RID_THIS */	0,
  /* RID_THROW */	0,
  /* RID_TRUE */	0,
  /* RID_TRY */		0,
  /* RID_TYPENAME */	0,
  /* RID_TYPEID */	0,
  /* RID_USING */	0,

  /* casts */
  /* RID_CONSTCAST */	0,
  /* RID_DYNCAST */	0,
  /* RID_REINTCAST */	0,
  /* RID_STATCAST */	0,

  /* alternate spellings */
  /* RID_AND */		0,
  /* RID_AND_EQ */	0,
  /* RID_NOT */		0,
  /* RID_NOT_EQ */	0,
  /* RID_OR */		0,
  /* RID_OR_EQ */	0,
  /* RID_XOR */		0,
  /* RID_XOR_EQ */	0,
  /* RID_BITAND */	0,
  /* RID_BITOR */	0,
  /* RID_COMPL */	0,

  /* Objective C */
  /* RID_ID */			OBJECTNAME,
  /* RID_AT_ENCODE */		ENCODE,
  /* RID_AT_END */		END,
  /* RID_AT_CLASS */		CLASS,
  /* RID_AT_ALIAS */		ALIAS,
  /* RID_AT_DEFS */		DEFS,
  /* RID_AT_PRIVATE */		PRIVATE,
  /* RID_AT_PROTECTED */	PROTECTED,
  /* RID_AT_PUBLIC */		PUBLIC,
  /* RID_AT_PROTOCOL */		PROTOCOL,
  /* RID_AT_SELECTOR */		SELECTOR,
  /* RID_AT_INTERFACE */	INTERFACE,
  /* RID_AT_IMPLEMENTATION */	IMPLEMENTATION
};


static void
init_reswords ()
{
  unsigned int i;
  tree id;
  int mask = ((doing_objc_thang ? 0 : D_OBJC)
	      | (flag_isoc99 ? 0 : D_C89)
	      | (flag_traditional ? D_TRAD : 0)
	      | (flag_no_asm ? (flag_isoc99 ? D_EXT : D_EXT|D_EXT89) : 0));

  /* It is not necessary to register ridpointers as a GC root, because
     all the trees it points to are permanently interned in the
     get_identifier hash anyway.  */
  ridpointers = (tree *) xcalloc ((int) RID_MAX, sizeof (tree));
  for (i = 0; i < N_reswords; i++)
    {
      /* If a keyword is disabled, do not enter it into the table
	 and so create a canonical spelling that isn't a keyword.  */
      if (reswords[i].disable & mask)
	continue;

      id = get_identifier (reswords[i].word);
      C_RID_CODE (id) = reswords[i].rid;
      C_IS_RESERVED_WORD (id) = 1;
      ridpointers [(int) reswords[i].rid] = id;

    }
}

const char *
init_parse (filename)
     const char *filename;
{
  add_c_tree_codes ();

  /* Make identifier nodes long enough for the language-specific slots.  */
  set_identifier_size (sizeof (struct lang_identifier));

  init_reswords ();
  init_pragma ();

  return init_c_lex (filename);
}

void
finish_parse ()
{
  cpp_finish (parse_in);
  /* Call to cpp_destroy () omitted for performance reasons.  */
  errorcount += cpp_errors (parse_in);
}

#define NAME(type) cpp_type2name (type)

static void
yyerror (msgid)
     const char *msgid;
{
  const char *string = _(msgid);

  if (last_token == CPP_EOF)
    error ("%s at end of input", string);
  else if (last_token == CPP_CHAR || last_token == CPP_WCHAR)
    {
      unsigned int val = TREE_INT_CST_LOW (yylval.ttype);
      const char *ell = (last_token == CPP_CHAR) ? "" : "L";
      if (val <= UCHAR_MAX && ISGRAPH (val))
	error ("%s before %s'%c'", string, ell, val);
      else
	error ("%s before %s'\\x%x'", string, ell, val);
    }
  else if (last_token == CPP_STRING
	   || last_token == CPP_WSTRING)
    error ("%s before string constant", string);
  else if (last_token == CPP_NUMBER
	   || last_token == CPP_INT
	   || last_token == CPP_FLOAT)
    error ("%s before numeric constant", string);
  else if (last_token == CPP_NAME)
    error ("%s before \"%s\"", string, IDENTIFIER_POINTER (yylval.ttype));
  else
    error ("%s before '%s' token", string, NAME(last_token));
}

static int
yylexname ()
{
  tree decl;

  if (C_IS_RESERVED_WORD (yylval.ttype))
    {
      enum rid rid_code = C_RID_CODE (yylval.ttype);
      /* Return the canonical spelling for this keyword.  */
      yylval.ttype = ridpointers[(int) rid_code];
      return rid_to_yy[(int) rid_code];
    }

  decl = lookup_name (yylval.ttype);
  if (decl)
    {
      if (TREE_CODE (decl) == TYPE_DECL)
	return TYPENAME;
      /* A user-invisible read-only initialized variable
	 should be replaced by its value.
	 We handle only strings since that's the only case used in C.  */
      else if (TREE_CODE (decl) == VAR_DECL
	       && DECL_IGNORED_P (decl)
	       && TREE_READONLY (decl)
	       && DECL_INITIAL (decl) != 0
	       && TREE_CODE (DECL_INITIAL (decl)) == STRING_CST)
	{
	  tree stringval = DECL_INITIAL (decl);

	  /* Copy the string value so that we won't clobber anything
	     if we put something in the TREE_CHAIN of this one.  */
	  yylval.ttype = build_string (TREE_STRING_LENGTH (stringval),
				       TREE_STRING_POINTER (stringval));
	  return STRING;
	}
    }
  else if (doing_objc_thang)
    {
      tree objc_interface_decl = is_class_name (yylval.ttype);

      if (objc_interface_decl)
	{
	  yylval.ttype = objc_interface_decl;
	  return CLASSNAME;
	}
    }

  return IDENTIFIER;
}


static inline int
_yylex ()
{
 get_next:
  last_token = c_lex (&yylval.ttype);
  switch (last_token)
    {
    case CPP_EQ:					return '=';
    case CPP_NOT:					return '!';
    case CPP_GREATER:	yylval.code = GT_EXPR;		return ARITHCOMPARE;
    case CPP_LESS:	yylval.code = LT_EXPR;		return ARITHCOMPARE;
    case CPP_PLUS:	yylval.code = PLUS_EXPR;	return '+';
    case CPP_MINUS:	yylval.code = MINUS_EXPR;	return '-';
    case CPP_MULT:	yylval.code = MULT_EXPR;	return '*';
    case CPP_DIV:	yylval.code = TRUNC_DIV_EXPR;	return '/';
    case CPP_MOD:	yylval.code = TRUNC_MOD_EXPR;	return '%';
    case CPP_AND:	yylval.code = BIT_AND_EXPR;	return '&';
    case CPP_OR:	yylval.code = BIT_IOR_EXPR;	return '|';
    case CPP_XOR:	yylval.code = BIT_XOR_EXPR;	return '^';
    case CPP_RSHIFT:	yylval.code = RSHIFT_EXPR;	return RSHIFT;
    case CPP_LSHIFT:	yylval.code = LSHIFT_EXPR;	return LSHIFT;

    case CPP_COMPL:					return '~';
    case CPP_AND_AND:					return ANDAND;
    case CPP_OR_OR:					return OROR;
    case CPP_QUERY:					return '?';
    case CPP_COLON:					return ':';
    case CPP_COMMA:					return ',';
    case CPP_OPEN_PAREN:				return '(';
    case CPP_CLOSE_PAREN:				return ')';
    case CPP_EQ_EQ:	yylval.code = EQ_EXPR;		return EQCOMPARE;
    case CPP_NOT_EQ:	yylval.code = NE_EXPR;		return EQCOMPARE;
    case CPP_GREATER_EQ:yylval.code = GE_EXPR;		return ARITHCOMPARE;
    case CPP_LESS_EQ:	yylval.code = LE_EXPR;		return ARITHCOMPARE;

    case CPP_PLUS_EQ:	yylval.code = PLUS_EXPR;	return ASSIGN;
    case CPP_MINUS_EQ:	yylval.code = MINUS_EXPR;	return ASSIGN;
    case CPP_MULT_EQ:	yylval.code = MULT_EXPR;	return ASSIGN;
    case CPP_DIV_EQ:	yylval.code = TRUNC_DIV_EXPR;	return ASSIGN;
    case CPP_MOD_EQ:	yylval.code = TRUNC_MOD_EXPR;	return ASSIGN;
    case CPP_AND_EQ:	yylval.code = BIT_AND_EXPR;	return ASSIGN;
    case CPP_OR_EQ:	yylval.code = BIT_IOR_EXPR;	return ASSIGN;
    case CPP_XOR_EQ:	yylval.code = BIT_XOR_EXPR;	return ASSIGN;
    case CPP_RSHIFT_EQ:	yylval.code = RSHIFT_EXPR;	return ASSIGN;
    case CPP_LSHIFT_EQ:	yylval.code = LSHIFT_EXPR;	return ASSIGN;

    case CPP_OPEN_SQUARE:				return '[';
    case CPP_CLOSE_SQUARE:				return ']';
    case CPP_OPEN_BRACE:				return '{';
    case CPP_CLOSE_BRACE:				return '}';
    case CPP_SEMICOLON:					return ';';
    case CPP_ELLIPSIS:					return ELLIPSIS;

    case CPP_PLUS_PLUS:					return PLUSPLUS;
    case CPP_MINUS_MINUS:				return MINUSMINUS;
    case CPP_DEREF:					return POINTSAT;
    case CPP_DOT:					return '.';

    case CPP_EOF:
      if (cpp_pop_buffer (parse_in) == 0)
	return 0;
      goto get_next;

    case CPP_NAME:
      return yylexname ();

    case CPP_INT:
    case CPP_FLOAT:
    case CPP_NUMBER:
    case CPP_CHAR:
    case CPP_WCHAR:
      return CONSTANT;

    case CPP_STRING:
    case CPP_WSTRING:
      return STRING;
      
      /* This token is Objective-C specific.  It gives the next
	 token special significance.  */
    case CPP_ATSIGN:
      /* These tokens are C++ specific (and will not be generated
         in C mode, but let's be cautious).  */
    case CPP_SCOPE:
    case CPP_DEREF_STAR:
    case CPP_DOT_STAR:
    case CPP_MIN_EQ:
    case CPP_MAX_EQ:
    case CPP_MIN:
    case CPP_MAX:
      /* These tokens should not survive translation phase 4.  */
    case CPP_HASH:
    case CPP_PASTE:
      error ("syntax error at '%s' token", NAME(last_token));
      goto get_next;

    default:
      abort ();
    }
  /* NOTREACHED */
}

static int
yylex()
{
  int r;
  timevar_push (TV_LEX);
  r = _yylex();
  timevar_pop (TV_LEX);
  return r;
}

/* Sets the value of the 'yydebug' variable to VALUE.
   This is a function so we don't have to have YYDEBUG defined
   in order to build the compiler.  */

void
set_yydebug (value)
     int value;
{
#if YYDEBUG != 0
  yydebug = value;
#else
  warning ("YYDEBUG not defined.");
#endif
}

/* Function used when yydebug is set, to print a token in more detail.  */

static void
yyprint (file, yychar, yyl)
     FILE *file;
     int yychar;
     YYSTYPE yyl;
{
  tree t = yyl.ttype;

  fprintf (file, " [%s]", NAME(last_token));
  
  switch (yychar)
    {
    case IDENTIFIER:
    case TYPENAME:
    case OBJECTNAME:
    case TYPESPEC:
    case TYPE_QUAL:
    case SCSPEC:
      if (IDENTIFIER_POINTER (t))
	fprintf (file, " `%s'", IDENTIFIER_POINTER (t));
      break;

    case CONSTANT:
      fprintf (file, " %s", GET_MODE_NAME (TYPE_MODE (TREE_TYPE (t))));
      if (TREE_CODE (t) == INTEGER_CST)
	fprintf (file,
#if HOST_BITS_PER_WIDE_INT == 64
#if HOST_BITS_PER_WIDE_INT == HOST_BITS_PER_INT
		 " 0x%x%016x",
#else
#if HOST_BITS_PER_WIDE_INT == HOST_BITS_PER_LONG
		 " 0x%lx%016lx",
#else
		 " 0x%llx%016llx",
#endif
#endif
#else
#if HOST_BITS_PER_WIDE_INT != HOST_BITS_PER_INT
		 " 0x%lx%08lx",
#else
		 " 0x%x%08x",
#endif
#endif
		 TREE_INT_CST_HIGH (t), TREE_INT_CST_LOW (t));
      break;
    }
}

/* This is not the ideal place to put these, but we have to get them out
   of c-lex.c because cp/lex.c has its own versions.  */

/* Return something to represent absolute declarators containing a *.
   TARGET is the absolute declarator that the * contains.
   TYPE_QUALS is a list of modifiers such as const or volatile
   to apply to the pointer type, represented as identifiers.

   We return an INDIRECT_REF whose "contents" are TARGET
   and whose type is the modifier list.  */

tree
make_pointer_declarator (type_quals, target)
     tree type_quals, target;
{
  return build1 (INDIRECT_REF, type_quals, target);
}

