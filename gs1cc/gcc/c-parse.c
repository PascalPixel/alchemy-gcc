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
     END_OF_LINE = 294,
     ASSIGN = 295,
     OROR = 296,
     ANDAND = 297,
     EQCOMPARE = 298,
     ARITHCOMPARE = 299,
     RSHIFT = 300,
     LSHIFT = 301,
     MINUSMINUS = 302,
     PLUSPLUS = 303,
     UNARY = 304,
     HYPERUNARY = 305,
     POINTSAT = 306,
     INTERFACE = 307,
     IMPLEMENTATION = 308,
     END = 309,
     SELECTOR = 310,
     DEFS = 311,
     ENCODE = 312,
     CLASSNAME = 313,
     PUBLIC = 314,
     PRIVATE = 315,
     PROTECTED = 316,
     PROTOCOL = 317,
     OBJECTNAME = 318,
     CLASS = 319,
     ALIAS = 320,
     OBJC_STRING = 321
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
#define END_OF_LINE 294
#define ASSIGN 295
#define OROR 296
#define ANDAND 297
#define EQCOMPARE 298
#define ARITHCOMPARE 299
#define RSHIFT 300
#define LSHIFT 301
#define MINUSMINUS 302
#define PLUSPLUS 303
#define UNARY 304
#define HYPERUNARY 305
#define POINTSAT 306
#define INTERFACE 307
#define IMPLEMENTATION 308
#define END 309
#define SELECTOR 310
#define DEFS 311
#define ENCODE 312
#define CLASSNAME 313
#define PUBLIC 314
#define PRIVATE 315
#define PROTECTED 316
#define PROTOCOL 317
#define OBJECTNAME 318
#define CLASS 319
#define ALIAS 320
#define OBJC_STRING 321




/* Copy the first part of user declarations.  */
#line 34 "c-parse.y"

#include "config.h"
#include "system.h"
#include <setjmp.h>
#include "tree.h"
#include "input.h"
#include "c-lex.h"
#include "c-tree.h"
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

/* Cause the `yydebug' variable to be defined.  */
#define YYDEBUG 1


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
#line 65 "c-parse.y"
{long itype; tree ttype; enum tree_code code;
	const char *filename; int lineno; int ends_in_label; }
/* Line 193 of yacc.c.  */
#line 260 "c-parse.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 186 "c-parse.y"

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
extern void yyprint			PARAMS ((FILE *, int, YYSTYPE));

/* Add GC roots for variables local to this file.  */
void
c_parse_init ()
{
  ggc_add_tree_root (&declspec_stack, 1);
  ggc_add_tree_root (&current_declspecs, 1);
  ggc_add_tree_root (&prefix_attributes, 1);
}



/* Line 216 of yacc.c.  */
#line 318 "c-parse.c"

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
#define YYLAST   2508

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  159
/* YYNRULES -- Number of rules.  */
#define YYNRULES  408
/* YYNRULES -- Number of states.  */
#define YYNSTATES  706

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,     2,     2,     2,    57,    48,     2,
      63,    81,    55,    53,    86,    54,    62,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    82,
       2,    40,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    88,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,    46,    83,    84,     2,     2,     2,
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
      35,    36,    37,    38,    39,    41,    44,    45,    49,    50,
      51,    52,    58,    59,    60,    61,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     7,    10,    11,    15,    17,
      19,    25,    28,    32,    37,    42,    45,    48,    51,    54,
      56,    57,    58,    66,    71,    72,    73,    81,    86,    87,
      88,    95,    99,   101,   103,   105,   107,   109,   111,   113,
     115,   117,   119,   120,   122,   124,   128,   130,   133,   136,
     139,   142,   145,   150,   153,   158,   161,   164,   171,   173,
     175,   177,   182,   183,   191,   193,   197,   201,   205,   209,
     213,   217,   221,   225,   229,   233,   237,   241,   242,   247,
     248,   253,   254,   255,   263,   264,   270,   274,   278,   280,
     282,   284,   288,   292,   296,   300,   305,   310,   314,   318,
     321,   324,   326,   329,   330,   332,   335,   339,   341,   343,
     346,   349,   354,   359,   362,   365,   369,   371,   373,   376,
     379,   380,   381,   386,   391,   395,   399,   402,   405,   408,
     411,   415,   416,   419,   422,   425,   428,   432,   433,   436,
     439,   441,   443,   446,   449,   451,   453,   456,   459,   462,
     466,   467,   470,   472,   474,   476,   481,   486,   488,   490,
     492,   494,   498,   500,   504,   505,   510,   511,   518,   522,
     523,   530,   534,   535,   537,   539,   542,   549,   551,   555,
     556,   558,   563,   570,   575,   577,   579,   581,   583,   585,
     586,   591,   593,   594,   597,   599,   603,   607,   610,   611,
     616,   618,   619,   624,   626,   628,   630,   633,   636,   642,
     646,   647,   648,   654,   655,   656,   662,   664,   666,   670,
     674,   679,   683,   687,   691,   693,   697,   702,   707,   711,
     715,   719,   721,   725,   729,   733,   738,   743,   747,   751,
     753,   755,   758,   760,   763,   765,   768,   769,   777,   783,
     786,   787,   795,   801,   804,   805,   814,   815,   823,   826,
     827,   829,   830,   832,   834,   837,   838,   842,   845,   849,
     855,   859,   861,   863,   866,   868,   872,   877,   884,   890,
     892,   896,   898,   900,   904,   907,   910,   911,   913,   915,
     918,   919,   922,   926,   930,   933,   937,   942,   946,   949,
     953,   956,   960,   962,   964,   967,   970,   971,   973,   976,
     977,   978,   980,   982,   985,   989,   991,   994,   996,   998,
    1004,  1009,  1014,  1017,  1020,  1023,  1026,  1031,  1032,  1037,
    1038,  1039,  1043,  1048,  1052,  1054,  1056,  1058,  1060,  1063,
    1064,  1069,  1071,  1075,  1076,  1077,  1085,  1091,  1094,  1095,
    1096,  1097,  1110,  1111,  1118,  1121,  1124,  1127,  1131,  1138,
    1147,  1158,  1171,  1175,  1180,  1182,  1184,  1185,  1192,  1196,
    1202,  1205,  1209,  1210,  1212,  1213,  1215,  1216,  1218,  1220,
    1224,  1229,  1231,  1235,  1236,  1239,  1242,  1243,  1248,  1251,
    1252,  1254,  1256,  1260,  1262,  1266,  1271,  1276,  1281,  1286,
    1291,  1292,  1295,  1297,  1300,  1302,  1306,  1308,  1312
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      90,     0,    -1,    -1,    91,    -1,    -1,    92,    94,    -1,
      -1,    91,    93,    94,    -1,    96,    -1,    95,    -1,    27,
      63,   105,    81,    82,    -1,   247,    94,    -1,   127,   141,
      82,    -1,   134,   127,   141,    82,    -1,   130,   127,   140,
      82,    -1,   134,    82,    -1,   130,    82,    -1,     1,    82,
      -1,     1,    83,    -1,    82,    -1,    -1,    -1,   130,   127,
     169,    97,   121,    98,   203,    -1,   130,   127,   169,     1,
      -1,    -1,    -1,   134,   127,   172,    99,   121,   100,   203,
      -1,   134,   127,   172,     1,    -1,    -1,    -1,   127,   172,
     101,   121,   102,   203,    -1,   127,   172,     1,    -1,     3,
      -1,     4,    -1,    48,    -1,    54,    -1,    53,    -1,    59,
      -1,    58,    -1,    84,    -1,    85,    -1,   107,    -1,    -1,
     107,    -1,   113,    -1,   107,    86,   113,    -1,   119,    -1,
      55,   111,    -1,   247,   111,    -1,   104,   111,    -1,    45,
     103,    -1,   109,   108,    -1,   109,    63,   190,    81,    -1,
     110,   108,    -1,   110,    63,   190,    81,    -1,    33,   111,
      -1,    34,   111,    -1,    35,    63,   113,    86,   190,    81,
      -1,    11,    -1,    29,    -1,   108,    -1,    63,   190,    81,
     111,    -1,    -1,    63,   190,    81,    87,   112,   155,    83,
      -1,   111,    -1,   113,    53,   113,    -1,   113,    54,   113,
      -1,   113,    55,   113,    -1,   113,    56,   113,    -1,   113,
      57,   113,    -1,   113,    52,   113,    -1,   113,    51,   113,
      -1,   113,    50,   113,    -1,   113,    49,   113,    -1,   113,
      48,   113,    -1,   113,    46,   113,    -1,   113,    47,   113,
      -1,    -1,   113,    45,   114,   113,    -1,    -1,   113,    44,
     115,   113,    -1,    -1,    -1,   113,    42,   116,   105,    43,
     117,   113,    -1,    -1,   113,    42,   118,    43,   113,    -1,
     113,    40,   113,    -1,   113,    41,   113,    -1,     3,    -1,
       8,    -1,   120,    -1,    63,   105,    81,    -1,    63,     1,
      81,    -1,   206,   205,    81,    -1,   206,     1,    81,    -1,
     119,    63,   106,    81,    -1,   119,    64,   105,    88,    -1,
     119,    62,   103,    -1,   119,    65,   103,    -1,   119,    59,
      -1,   119,    58,    -1,     9,    -1,   120,     9,    -1,    -1,
     123,    -1,   123,    10,    -1,   212,   213,   124,    -1,   122,
      -1,   198,    -1,   123,   122,    -1,   122,   198,    -1,   132,
     127,   140,    82,    -1,   135,   127,   141,    82,    -1,   132,
      82,    -1,   135,    82,    -1,   212,   213,   129,    -1,   125,
      -1,   198,    -1,   126,   125,    -1,   125,   198,    -1,    -1,
      -1,   130,   127,   140,    82,    -1,   134,   127,   141,    82,
      -1,   130,   127,   163,    -1,   134,   127,   166,    -1,   130,
      82,    -1,   134,    82,    -1,   247,   129,    -1,   138,   131,
      -1,   134,   138,   131,    -1,    -1,   131,   139,    -1,   131,
       5,    -1,   131,   148,    -1,   138,   133,    -1,   135,   138,
     133,    -1,    -1,   133,   139,    -1,   133,     5,    -1,   135,
      -1,   148,    -1,   134,   135,    -1,   134,   148,    -1,     7,
      -1,     5,    -1,   135,     7,    -1,   135,     5,    -1,   138,
     137,    -1,   192,   138,   137,    -1,    -1,   137,   139,    -1,
       6,    -1,   176,    -1,     4,    -1,    28,    63,   105,    81,
      -1,    28,    63,   190,    81,    -1,     6,    -1,     7,    -1,
     176,    -1,   143,    -1,   140,    86,   143,    -1,   145,    -1,
     141,    86,   143,    -1,    -1,    27,    63,   120,    81,    -1,
      -1,   169,   142,   147,    40,   144,   153,    -1,   169,   142,
     147,    -1,    -1,   172,   142,   147,    40,   146,   153,    -1,
     172,   142,   147,    -1,    -1,   148,    -1,   149,    -1,   148,
     149,    -1,    30,    63,    63,   150,    81,    81,    -1,   151,
      -1,   150,    86,   151,    -1,    -1,   152,    -1,   152,    63,
       3,    81,    -1,   152,    63,     3,    86,   107,    81,    -1,
     152,    63,   106,    81,    -1,   103,    -1,     5,    -1,     6,
      -1,     7,    -1,   113,    -1,    -1,    87,   154,   155,    83,
      -1,     1,    -1,    -1,   156,   181,    -1,   157,    -1,   156,
      86,   157,    -1,   161,    40,   159,    -1,   162,   159,    -1,
      -1,   103,    43,   158,   159,    -1,   159,    -1,    -1,    87,
     160,   155,    83,    -1,   113,    -1,     1,    -1,   162,    -1,
     161,   162,    -1,    62,   103,    -1,    64,   113,    10,   113,
      88,    -1,    64,   113,    88,    -1,    -1,    -1,   169,   164,
     121,   165,   207,    -1,    -1,    -1,   172,   167,   121,   168,
     207,    -1,   170,    -1,   172,    -1,    63,   170,    81,    -1,
     170,    63,   242,    -1,   170,    64,   105,    88,    -1,   170,
      64,    88,    -1,    55,   193,   170,    -1,   148,   128,   170,
      -1,     4,    -1,   171,    63,   242,    -1,   171,    64,    55,
      88,    -1,   171,    64,   105,    88,    -1,   171,    64,    88,
      -1,    55,   193,   171,    -1,   148,   128,   171,    -1,     4,
      -1,   172,    63,   242,    -1,    63,   172,    81,    -1,    55,
     193,   172,    -1,   172,    64,    55,    88,    -1,   172,    64,
     105,    88,    -1,   172,    64,    88,    -1,   148,   128,   172,
      -1,     3,    -1,    13,    -1,    13,   148,    -1,    14,    -1,
      14,   148,    -1,    12,    -1,    12,   148,    -1,    -1,   173,
     103,    87,   177,   183,    83,   147,    -1,   173,    87,   183,
      83,   147,    -1,   173,   103,    -1,    -1,   174,   103,    87,
     178,   183,    83,   147,    -1,   174,    87,   183,    83,   147,
      -1,   174,   103,    -1,    -1,   175,   103,    87,   179,   188,
     182,    83,   147,    -1,    -1,   175,    87,   180,   188,   182,
      83,   147,    -1,   175,   103,    -1,    -1,    86,    -1,    -1,
      86,    -1,   184,    -1,   184,   185,    -1,    -1,   184,   185,
      82,    -1,   184,    82,    -1,   136,   127,   186,    -1,   136,
     127,   212,   213,   147,    -1,   192,   127,   186,    -1,   192,
      -1,     1,    -1,   247,   185,    -1,   187,    -1,   186,    86,
     187,    -1,   212,   213,   169,   147,    -1,   212,   213,   169,
      43,   113,   147,    -1,   212,   213,    43,   113,   147,    -1,
     189,    -1,   188,    86,   189,    -1,     1,    -1,   103,    -1,
     103,    40,   113,    -1,   136,   191,    -1,   192,   191,    -1,
      -1,   194,    -1,     7,    -1,   192,     7,    -1,    -1,   193,
       7,    -1,    63,   194,    81,    -1,    55,   193,   194,    -1,
      55,   193,    -1,   194,    63,   235,    -1,   194,    64,   105,
      88,    -1,   194,    64,    88,    -1,    63,   235,    -1,    64,
     105,    88,    -1,    64,    88,    -1,   148,   128,   194,    -1,
     196,    -1,   215,    -1,   196,   215,    -1,   196,   198,    -1,
      -1,   195,    -1,     1,    82,    -1,    -1,    -1,   201,    -1,
     202,    -1,   201,   202,    -1,    32,   246,    82,    -1,   207,
      -1,     1,   207,    -1,    87,    -1,    83,    -1,   199,   200,
     126,   197,    83,    -1,   199,   200,     1,    83,    -1,   199,
     200,   195,    83,    -1,    63,    87,    -1,   204,   205,    -1,
     209,   214,    -1,   209,     1,    -1,    15,    63,   105,    81,
      -1,    -1,    18,   211,   214,    17,    -1,    -1,    -1,   212,
     213,   217,    -1,   212,   213,   228,   214,    -1,   212,   213,
     216,    -1,   217,    -1,   228,    -1,   207,    -1,   225,    -1,
     105,    82,    -1,    -1,   208,    16,   218,   214,    -1,   208,
      -1,   208,    16,     1,    -1,    -1,    -1,    17,   219,    63,
     105,    81,   220,   214,    -1,   210,    63,   105,    81,    82,
      -1,   210,     1,    -1,    -1,    -1,    -1,    19,    63,   230,
      82,   221,   230,    82,   222,   230,    81,   223,   214,    -1,
      -1,    20,    63,   105,    81,   224,   214,    -1,    23,    82,
      -1,    24,    82,    -1,    25,    82,    -1,    25,   105,    82,
      -1,    27,   229,    63,   105,    81,    82,    -1,    27,   229,
      63,   105,    43,   231,    81,    82,    -1,    27,   229,    63,
     105,    43,   231,    43,   231,    81,    82,    -1,    27,   229,
      63,   105,    43,   231,    43,   231,    43,   234,    81,    82,
      -1,    26,   103,    82,    -1,    26,    55,   105,    82,    -1,
      82,    -1,   226,    -1,    -1,    19,    63,   119,    81,   227,
     214,    -1,    21,   113,    43,    -1,    21,   113,    10,   113,
      43,    -1,    22,    43,    -1,   103,    43,   147,    -1,    -1,
       7,    -1,    -1,   105,    -1,    -1,   232,    -1,   233,    -1,
     232,    86,   233,    -1,     9,    63,   105,    81,    -1,   120,
      -1,   234,    86,   120,    -1,    -1,   236,   237,    -1,   239,
      81,    -1,    -1,   240,    82,   238,   237,    -1,     1,    81,
      -1,    -1,    10,    -1,   240,    -1,   240,    86,    10,    -1,
     241,    -1,   240,    86,   241,    -1,   130,   127,   171,   147,
      -1,   130,   127,   172,   147,    -1,   130,   127,   191,   147,
      -1,   134,   127,   172,   147,    -1,   134,   127,   191,   147,
      -1,    -1,   243,   244,    -1,   237,    -1,   245,    81,    -1,
       3,    -1,   245,    86,     3,    -1,   103,    -1,   246,    86,
     103,    -1,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   234,   234,   238,   253,   253,   254,   254,   258,   259,
     260,   268,   273,   282,   286,   290,   292,   294,   295,   296,
     303,   308,   302,   314,   319,   324,   318,   330,   335,   340,
     334,   346,   353,   354,   357,   359,   361,   366,   368,   370,
     372,   376,   382,   383,   387,   389,   394,   395,   398,   401,
     405,   433,   439,   442,   445,   448,   450,   452,   457,   461,
     465,   466,   470,   469,   501,   502,   504,   506,   508,   510,
     512,   514,   516,   518,   520,   522,   524,   527,   526,   533,
     532,   539,   542,   538,   548,   547,   557,   565,   577,   583,
     584,   586,   592,   594,   617,   626,   628,   630,   634,   640,
     642,   648,   649,   666,   668,   669,   680,   685,   686,   687,
     688,   696,   700,   704,   707,   716,   721,   722,   723,   724,
     732,   742,   746,   750,   754,   758,   762,   764,   766,   776,
     778,   783,   784,   786,   791,   796,   798,   804,   805,   807,
     820,   822,   824,   826,   831,   834,   836,   839,   853,   855,
     860,   861,   869,   870,   871,   875,   877,   883,   884,   885,
     889,   890,   894,   895,   900,   901,   909,   908,   916,   925,
     924,   933,   942,   943,   948,   950,   955,   960,   962,   968,
     969,   971,   973,   975,   983,   984,   985,   986,   992,   994,
     993,   997,  1004,  1006,  1010,  1011,  1017,  1018,  1020,  1019,
    1022,  1027,  1026,  1030,  1032,  1036,  1037,  1041,  1046,  1048,
    1054,  1066,  1053,  1080,  1092,  1079,  1108,  1109,  1115,  1117,
    1122,  1124,  1126,  1133,  1135,  1144,  1149,  1154,  1156,  1158,
    1165,  1167,  1174,  1179,  1181,  1183,  1188,  1190,  1197,  1199,
    1203,  1205,  1210,  1212,  1217,  1219,  1225,  1224,  1230,  1234,
    1237,  1236,  1240,  1244,  1247,  1246,  1252,  1251,  1256,  1260,
    1262,  1265,  1267,  1273,  1275,  1281,  1282,  1284,  1299,  1304,
    1317,  1322,  1327,  1329,  1335,  1336,  1341,  1344,  1348,  1359,
    1360,  1365,  1371,  1373,  1378,  1380,  1386,  1387,  1391,  1393,
    1399,  1400,  1405,  1408,  1410,  1412,  1414,  1416,  1418,  1420,
    1422,  1426,  1435,  1443,  1444,  1446,  1450,  1452,  1455,  1459,
    1468,  1470,  1476,  1477,  1481,  1495,  1497,  1500,  1502,  1504,
    1508,  1512,  1519,  1536,  1542,  1546,  1550,  1565,  1564,  1577,
    1581,  1585,  1590,  1595,  1600,  1602,  1608,  1610,  1611,  1628,
    1627,  1635,  1647,  1650,  1660,  1649,  1670,  1677,  1681,  1693,
    1696,  1679,  1716,  1715,  1722,  1726,  1730,  1734,  1738,  1749,
    1756,  1763,  1770,  1781,  1787,  1791,  1797,  1796,  1848,  1854,
    1860,  1866,  1882,  1884,  1890,  1891,  1897,  1898,  1902,  1903,
    1908,  1913,  1915,  1922,  1922,  1932,  1934,  1933,  1943,  1950,
    1951,  1961,  1963,  1968,  1970,  1977,  1985,  1993,  2001,  2010,
    2024,  2024,  2034,  2035,  2045,  2047,  2053,  2055,  2060
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
  "IMAGPART", "VA_ARG", "PTR_VALUE", "PTR_BASE", "PTR_EXTENT",
  "END_OF_LINE", "'='", "ASSIGN", "'?'", "':'", "OROR", "ANDAND", "'|'",
  "'^'", "'&'", "EQCOMPARE", "ARITHCOMPARE", "RSHIFT", "LSHIFT", "'+'",
  "'-'", "'*'", "'/'", "'%'", "MINUSMINUS", "PLUSPLUS", "UNARY",
  "HYPERUNARY", "'.'", "'('", "'['", "POINTSAT", "INTERFACE",
  "IMPLEMENTATION", "END", "SELECTOR", "DEFS", "ENCODE", "CLASSNAME",
  "PUBLIC", "PRIVATE", "PROTECTED", "PROTOCOL", "OBJECTNAME", "CLASS",
  "ALIAS", "OBJC_STRING", "')'", "';'", "'}'", "'~'", "'!'", "','", "'{'",
  "']'", "$accept", "program", "extdefs", "@1", "@2", "extdef", "datadef",
  "fndef", "@3", "@4", "@5", "@6", "@7", "@8", "identifier", "unop",
  "expr", "exprlist", "nonnull_exprlist", "unary_expr", "sizeof",
  "alignof", "cast_expr", "@9", "expr_no_commas", "@10", "@11", "@12",
  "@13", "@14", "primary", "string", "old_style_parm_decls",
  "lineno_datadecl", "datadecls", "datadecl", "lineno_decl", "decls",
  "setspecs", "setattrs", "decl", "typed_declspecs", "reserved_declspecs",
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
  "component_declarator", "enumlist", "enumerator", "typename", "absdcl",
  "nonempty_type_quals", "type_quals", "absdcl1", "stmts",
  "lineno_stmt_or_labels", "xstmts", "errstmt", "pushlevel",
  "maybe_label_decls", "label_decls", "label_decl", "compstmt_or_error",
  "compstmt_start", "compstmt_nostart", "compstmt_primary_start",
  "compstmt", "simple_if", "if_prefix", "do_stmt_start", "@28",
  "save_filename", "save_lineno", "lineno_labeled_stmt",
  "lineno_stmt_or_label", "stmt_or_label", "stmt", "@29", "@30", "@31",
  "@32", "@33", "@34", "@35", "all_iter_stmt", "all_iter_stmt_simple",
  "@36", "label", "maybe_type_qual", "xexpr", "asm_operands",
  "nonnull_asm_operands", "asm_operand", "asm_clobbers", "parmlist", "@37",
  "parmlist_1", "@38", "parmlist_2", "parms", "parm",
  "parmlist_or_identifiers", "@39", "parmlist_or_identifiers_1",
  "identifiers", "identifiers_or_typenames", "extension", 0
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
      61,   295,    63,    58,   296,   297,   124,    94,    38,   298,
     299,   300,   301,    43,    45,    42,    47,    37,   302,   303,
     304,   305,    46,    40,    91,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,    41,    59,   125,   126,    33,    44,   123,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    92,    91,    93,    91,    94,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    95,    95,
      97,    98,    96,    96,    99,   100,    96,    96,   101,   102,
      96,    96,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   105,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   110,
     111,   111,   112,   111,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   114,   113,   115,
     113,   116,   117,   113,   118,   113,   113,   113,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   121,   121,   121,   122,   123,   123,   123,
     123,   124,   124,   124,   124,   125,   126,   126,   126,   126,
     127,   128,   129,   129,   129,   129,   129,   129,   129,   130,
     130,   131,   131,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   135,   135,   135,   135,   136,   136,
     137,   137,   138,   138,   138,   138,   138,   139,   139,   139,
     140,   140,   141,   141,   142,   142,   144,   143,   143,   146,
     145,   145,   147,   147,   148,   148,   149,   150,   150,   151,
     151,   151,   151,   151,   152,   152,   152,   152,   153,   154,
     153,   153,   155,   155,   156,   156,   157,   157,   158,   157,
     157,   160,   159,   159,   159,   161,   161,   162,   162,   162,
     164,   165,   163,   167,   168,   166,   169,   169,   170,   170,
     170,   170,   170,   170,   170,   171,   171,   171,   171,   171,
     171,   171,   172,   172,   172,   172,   172,   172,   172,   172,
     173,   173,   174,   174,   175,   175,   177,   176,   176,   176,
     178,   176,   176,   176,   179,   176,   180,   176,   176,   181,
     181,   182,   182,   183,   183,   184,   184,   184,   185,   185,
     185,   185,   185,   185,   186,   186,   187,   187,   187,   188,
     188,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   195,   196,   196,   196,   197,   197,   198,   199,
     200,   200,   201,   201,   202,   203,   203,   204,   205,   205,
     205,   205,   206,   207,   208,   208,   209,   211,   210,   212,
     213,   214,   214,   215,   216,   216,   217,   217,   217,   218,
     217,   217,   217,   219,   220,   217,   217,   217,   221,   222,
     223,   217,   224,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   225,   227,   226,   228,   228,
     228,   228,   229,   229,   230,   230,   231,   231,   232,   232,
     233,   234,   234,   236,   235,   237,   238,   237,   237,   239,
     239,   239,   239,   240,   240,   241,   241,   241,   241,   241,
     243,   242,   244,   244,   245,   245,   246,   246,   247
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     0,     2,     0,     3,     1,     1,
       5,     2,     3,     4,     4,     2,     2,     2,     2,     1,
       0,     0,     7,     4,     0,     0,     7,     4,     0,     0,
       6,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     3,     1,     2,     2,     2,
       2,     2,     4,     2,     4,     2,     2,     6,     1,     1,
       1,     4,     0,     7,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     4,     0,
       4,     0,     0,     7,     0,     5,     3,     3,     1,     1,
       1,     3,     3,     3,     3,     4,     4,     3,     3,     2,
       2,     1,     2,     0,     1,     2,     3,     1,     1,     2,
       2,     4,     4,     2,     2,     3,     1,     1,     2,     2,
       0,     0,     4,     4,     3,     3,     2,     2,     2,     2,
       3,     0,     2,     2,     2,     2,     3,     0,     2,     2,
       1,     1,     2,     2,     1,     1,     2,     2,     2,     3,
       0,     2,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     3,     1,     3,     0,     4,     0,     6,     3,     0,
       6,     3,     0,     1,     1,     2,     6,     1,     3,     0,
       1,     4,     6,     4,     1,     1,     1,     1,     1,     0,
       4,     1,     0,     2,     1,     3,     3,     2,     0,     4,
       1,     0,     4,     1,     1,     1,     2,     2,     5,     3,
       0,     0,     5,     0,     0,     5,     1,     1,     3,     3,
       4,     3,     3,     3,     1,     3,     4,     4,     3,     3,
       3,     1,     3,     3,     3,     4,     4,     3,     3,     1,
       1,     2,     1,     2,     1,     2,     0,     7,     5,     2,
       0,     7,     5,     2,     0,     8,     0,     7,     2,     0,
       1,     0,     1,     1,     2,     0,     3,     2,     3,     5,
       3,     1,     1,     2,     1,     3,     4,     6,     5,     1,
       3,     1,     1,     3,     2,     2,     0,     1,     1,     2,
       0,     2,     3,     3,     2,     3,     4,     3,     2,     3,
       2,     3,     1,     1,     2,     2,     0,     1,     2,     0,
       0,     1,     1,     2,     3,     1,     2,     1,     1,     5,
       4,     4,     2,     2,     2,     2,     4,     0,     4,     0,
       0,     3,     4,     3,     1,     1,     1,     1,     2,     0,
       4,     1,     3,     0,     0,     7,     5,     2,     0,     0,
       0,    12,     0,     6,     2,     2,     2,     3,     6,     8,
      10,    12,     3,     4,     1,     1,     0,     6,     3,     5,
       2,     3,     0,     1,     0,     1,     0,     1,     1,     3,
       4,     1,     3,     0,     2,     2,     0,     4,     2,     0,
       1,     1,     3,     1,     3,     4,     4,     4,     4,     4,
       0,     2,     1,     2,     1,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     6,     0,     1,     0,     0,   154,   145,   152,
     144,   244,   240,   242,     0,     0,     0,   408,    19,     5,
       9,     8,     0,   120,   120,   140,   131,   141,   174,     0,
       0,     0,   153,     0,     7,    17,    18,   245,   241,   243,
       0,     0,     0,   239,   290,     0,     0,   162,   121,     0,
      16,     0,    15,     0,   142,   131,   143,   147,   146,   129,
     175,    32,    33,   265,   249,   265,   253,   256,   258,    11,
      88,    89,   101,    58,    59,     0,     0,     0,     0,    34,
      36,    35,     0,    38,    37,     0,    39,    40,     0,     0,
      41,    60,     0,     0,    64,    44,    46,    90,     0,     0,
     288,     0,   286,   150,     0,   286,   179,     0,     0,    12,
       0,     0,    31,     0,   400,     0,     0,   172,   224,   290,
       0,     0,   160,   121,     0,   216,   217,     0,     0,   130,
     133,   157,   158,   132,   134,   159,     0,     0,   246,     0,
     250,     0,   254,    55,    56,     0,    50,    47,     0,   322,
       0,     0,    49,     0,     0,     0,    51,     0,    53,     0,
       0,    81,    79,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,    99,     0,    42,
       0,     0,   102,     0,   318,   310,     0,    48,   155,   290,
     383,     0,   121,   284,   287,   148,   156,   289,   150,   285,
     185,   186,   187,   184,     0,   177,   180,   291,   234,   233,
     163,   164,   238,     0,   232,     0,     0,   237,     0,     0,
      29,     0,   329,   108,   330,   171,   173,     0,     0,    14,
       0,     0,    23,     0,   172,   400,     0,    13,    27,     0,
     172,   272,   267,   120,   264,   120,     0,   265,   172,   265,
     281,   282,   261,   279,     0,     0,    92,    91,     0,    10,
      45,     0,     0,    86,    87,     0,     0,     0,     0,    75,
      76,    74,    73,    72,    71,    70,    65,    66,    67,    68,
      69,    97,     0,    43,     0,    98,    94,     0,     0,   311,
     312,    93,   294,     0,   298,     0,   300,     0,     0,   383,
       0,   151,   149,     0,   179,    42,     0,     0,   404,   390,
     120,   120,   402,     0,   391,   393,   401,     0,   235,   236,
     308,     0,   110,   105,   109,     0,   169,   222,   218,   161,
     223,    21,   168,   219,   221,     0,    25,   248,   329,   266,
     329,   273,     0,   252,     0,     0,   262,     0,   261,     0,
      62,    61,    52,    54,     0,     0,    80,    78,    95,    96,
     406,     0,     0,     0,   329,     0,     0,   117,   330,   303,
     313,   293,   292,   384,   299,   301,   295,   297,     0,   176,
     178,    88,     0,   165,   388,   286,   286,   385,   386,     0,
     403,     0,     0,   317,    30,   309,   315,   106,   120,   120,
     137,     0,     0,   166,   220,     0,   268,   274,   330,   270,
     330,   172,   172,   283,   280,   172,     0,     0,     0,    82,
      85,   314,     0,   320,   119,   118,   307,     0,   321,   305,
     330,   304,     0,   296,   181,     0,   183,   231,   290,   383,
     121,   172,   172,   172,   290,   121,   172,   172,     0,   392,
     394,   405,   316,   323,   113,     0,   114,     0,   137,   135,
     191,   189,   188,   170,    22,     0,    26,   329,   172,     0,
     247,   251,   257,   172,    57,   204,    88,     0,     0,   201,
       0,   203,     0,   259,   194,   200,     0,     0,     0,   407,
     319,     0,   154,     0,   343,   327,     0,     0,     0,     0,
       0,     0,     0,     0,   372,   364,     0,     0,   115,   120,
     120,   336,   341,     0,     0,   333,   334,   337,   365,   335,
       0,     0,   294,     0,   400,     0,   395,   396,   397,   294,
       0,   398,   399,   387,     0,     0,   164,   136,   139,   138,
       0,   167,   275,     0,   269,   121,   172,   255,   207,     0,
       0,   198,    63,     0,   193,     0,   206,   197,    83,     0,
       0,   329,   374,     0,     0,   370,   354,   355,   356,     0,
       0,     0,   373,     0,   172,   338,   126,     0,   127,     0,
       0,   325,   330,   324,   347,     0,   128,   182,   229,   230,
     225,     0,   228,     0,   111,   112,     0,   172,     0,   276,
       0,   209,     0,     0,   195,   196,     0,     0,     0,   375,
      46,     0,     0,     0,   368,   357,     0,   362,     0,   371,
       0,   124,   210,     0,   125,   213,   342,   329,     0,     0,
     226,   227,   190,   278,   172,     0,   202,   199,   326,     0,
     328,   366,   348,   352,     0,   363,     0,   122,     0,   123,
       0,   340,   331,   329,     0,   277,   208,   344,   329,   374,
     329,   369,   376,     0,   211,   214,   332,   346,   329,   367,
       0,   353,     0,     0,   377,   378,   358,     0,     0,   345,
     349,     0,   376,     0,     0,   212,   215,   374,     0,     0,
     359,   379,     0,   380,     0,     0,   350,   381,     0,   360,
     329,     0,     0,   351,   361,   382
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,     5,    19,    20,    21,   233,   402,
     239,   405,   116,   321,   480,    88,   150,   282,    90,    91,
      92,    93,    94,   418,    95,   268,   267,   265,   488,   266,
      96,    97,   220,   221,   222,   397,   363,   364,    22,   231,
     508,   310,    59,   398,   459,   311,    25,   102,   195,    26,
     133,   121,    46,   117,   122,   465,    47,   401,   225,   226,
      28,   204,   205,   206,   463,   540,   482,   483,   484,   603,
     485,   550,   486,   487,   621,   648,   677,   624,   650,   678,
     211,   125,   441,   126,    29,    30,    31,    32,   247,   249,
     254,   141,   554,   347,   136,   137,   244,   406,   407,   252,
     253,   104,   193,   105,   107,   194,   365,   366,   427,   223,
     185,   288,   289,   290,   394,   395,   186,    98,   396,   512,
     513,   514,   561,   582,   325,   583,   369,   515,   516,   627,
     560,   668,   659,   687,   700,   660,   517,   518,   658,   519,
     573,   611,   673,   674,   675,   698,   294,   295,   312,   448,
     313,   314,   315,   214,   215,   316,   317,   361,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -582
static const yytype_int16 yypact[] =
{
      83,    92,   104,  2356,  -582,  2356,   195,  -582,  -582,  -582,
    -582,    90,    90,    90,    84,   122,   154,  -582,  -582,  -582,
    -582,  -582,   433,   113,   775,   152,  -582,    90,  -582,    63,
      65,   119,  -582,  2356,  -582,  -582,  -582,    90,    90,    90,
    2196,  2130,   175,  -582,  -582,   433,   106,  -582,    90,  1428,
    -582,   521,  -582,   433,   152,  -582,    90,  -582,  -582,  1046,
    -582,  -582,  -582,  -582,    41,  -582,   128,  -582,   193,  -582,
    -582,  -582,  -582,  -582,  -582,  2196,  2196,   192,   383,  -582,
    -582,  -582,  2196,  -582,  -582,  1212,  -582,  -582,  2196,   187,
     197,  -582,  2229,  2262,  -582,  2425,  1454,   291,   711,  2196,
    -582,   213,   279,  -582,   263,  1043,   607,   221,   146,  -582,
     521,   433,  -582,   288,  -582,  1517,   326,    90,  -582,  -582,
     521,   132,  -582,    90,   594,   347,   368,   144,  1481,  1046,
    -582,  -582,  -582,  -582,    90,  -582,   276,   771,  -582,   286,
    -582,   390,  -582,  -582,  -582,  2196,  -582,  -582,   319,  -582,
     327,   333,  -582,   338,  2196,  1212,  -582,  1212,  -582,  2196,
    2196,   385,  -582,  -582,  2196,  2196,  2196,  2196,  2196,  2196,
    2196,  2196,  2196,  2196,  2196,  2196,  -582,  -582,   383,  2196,
    2196,   383,  -582,   345,  -582,   402,   357,  -582,  -582,  -582,
     279,  1575,    90,  -582,   377,   392,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,     8,  -582,   387,  -582,   368,  -582,
    -582,   427,   368,   449,  -582,  1526,  1613,  -582,   381,   388,
    -582,   467,    51,  -582,  -582,   442,    90,   697,   256,  -582,
     521,   521,  -582,   326,    90,  -582,  1671,  -582,  -582,   326,
      90,  -582,  -582,  -582,   405,   228,   543,  -582,    90,  -582,
    -582,   453,   408,  -582,   390,  2400,  -582,  -582,  2011,  -582,
    2425,   419,   420,  2425,  2425,  2196,   461,  2196,  2196,  2098,
    2451,  1234,  1599,   611,   589,   589,   269,   269,  -582,  -582,
    -582,  -582,   424,   197,   423,  -582,  -582,   383,   896,   402,
    -582,  -582,   530,   265,  -582,  1584,  -582,   428,   279,  -582,
    1709,  -582,   392,   426,   607,  2295,    48,   437,  -582,  -582,
    -582,  1018,  -582,   445,   179,  -582,  -582,    62,  -582,  -582,
    -582,    46,  -582,  -582,  -582,  1128,  -582,   347,  -582,  -582,
     347,  -582,   491,  -582,  -582,   444,  -582,  -582,  -582,  -582,
    -582,  -582,   456,  -582,   457,  2196,   383,   459,   408,  1453,
    -582,  -582,  -582,  -582,   505,  2196,  1734,  2441,  -582,  -582,
    -582,   185,   361,   811,   469,   475,   981,  -582,  -582,  -582,
    -582,   377,  -582,  -582,  -582,   377,  -582,  -582,   473,  -582,
    -582,    80,   481,  -582,  -582,   233,   354,  -582,  -582,   933,
    -582,   562,   479,  -582,  -582,   485,  -582,  -582,   487,   685,
    -582,   624,    46,  -582,  -582,    46,   486,  -582,  -582,   486,
    -582,    90,    90,  2425,  -582,    90,   490,   494,  1247,  -582,
    1639,  -582,   383,  -582,  -582,  -582,  -582,   496,  -582,  -582,
    -582,  -582,  1891,  -582,  -582,  2196,  -582,  -582,  -582,   354,
      90,   244,   285,    90,  -582,    90,   285,    90,  1584,  -582,
    -582,  -582,  -582,  -582,  -582,   521,  -582,   433,  -582,   959,
    -582,  -582,  2425,  -582,  -582,   624,  -582,  -582,   360,   360,
    -582,  -582,  -582,    90,  -582,  -582,   534,   383,  2196,  -582,
     538,  2425,   503,   501,  -582,  -582,   158,  1352,  2196,  -582,
    -582,  1976,   548,   533,  -582,  -582,   539,   541,  2196,   554,
     523,   535,  2163,    82,   609,  -582,   575,   546,  -582,   547,
     963,  -582,   604,  1066,    61,  -582,  -582,  -582,  -582,  -582,
    2072,   118,   209,   233,  -582,  1767,  -582,  -582,  -582,   240,
     354,  -582,  -582,  -582,   207,   220,   181,   959,  -582,  -582,
    1247,  -582,  -582,  2196,  -582,   100,    88,  -582,  -582,  2380,
    1247,  -582,  -582,  1311,  -582,  1416,  -582,  -582,  1639,  2196,
     560,  -582,  2196,  2196,  1831,  -582,  -582,  -582,  -582,   549,
    2196,   556,  -582,   567,    90,  -582,  -582,   521,  -582,   433,
    1151,  -582,  -582,  -582,  -582,  2196,  -582,  -582,   393,   393,
    -582,  1805,  -582,   552,  -582,  -582,   553,   831,  2196,  -582,
    2196,  -582,   566,  1416,  -582,  -582,   569,  2196,   637,  -582,
    1130,   574,   579,  2196,  -582,  -582,   588,  -582,  2196,  -582,
     236,  -582,   115,   259,  -582,   621,  -582,  -582,  1976,   590,
    -582,  -582,  -582,  -582,   831,  2351,  -582,  -582,  -582,   593,
    -582,  -582,  -582,  -582,  1915,  -582,    27,  -582,   326,  -582,
     326,  -582,  -582,  -582,   606,  -582,  -582,  -582,  -582,  2196,
    -582,  -582,   666,   612,  -582,  -582,  -582,  -582,  -582,  -582,
     620,  -582,   630,    33,   619,  -582,  -582,   479,   479,  -582,
    -582,  2196,   666,   628,   666,  -582,  -582,  2196,   640,    53,
    -582,  -582,   668,  -582,   449,   665,  -582,   291,   168,  -582,
    -582,   671,   449,  -582,  -582,   291
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -582,  -582,  -582,  -582,  -582,    69,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,   -25,  -582,   -40,   450,  -136,   391,
    -582,  -582,   -53,  -582,   208,  -582,  -582,  -582,  -582,  -582,
     188,  -196,  -195,   532,  -582,  -582,   398,  -582,     3,   -18,
     237,    15,   713,  -582,   313,    16,   -13,   -92,   578,    36,
    -167,  -401,   -45,  -108,   -46,  -582,  -582,  -582,    18,    60,
     -24,  -582,   482,  -582,   308,  -582,  -452,  -582,   238,  -582,
    -428,  -582,  -582,   304,  -582,  -582,  -582,  -582,  -582,  -582,
     -44,   -41,   -33,   -20,  -582,  -582,  -582,   -17,  -582,  -582,
    -582,  -582,  -582,   452,   -26,  -582,   551,   464,   325,   555,
     455,   -48,   -69,   -86,   -88,  -134,   443,  -582,  -582,  -163,
    -582,  -582,  -582,   524,  -266,  -582,   415,  -582,  -342,  -582,
    -582,  -582,  -582,  -107,  -313,  -481,   477,  -582,   199,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,   219,
    -582,  -581,   166,  -582,   165,  -582,   559,  -582,  -254,  -582,
    -582,  -582,   462,  -201,  -582,  -582,  -582,  -582,     7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -390
static const yytype_int16 yytable[] =
{
      89,   101,    49,    60,    64,    66,    68,   124,   127,   224,
      33,    54,    33,    60,    60,    60,   234,   306,    23,    24,
      23,    24,   143,   144,    60,   108,    51,    53,   301,   147,
     111,   227,    60,   128,   333,   152,   199,   151,   331,   139,
      33,   373,   135,   283,   336,   243,   187,   392,    23,    24,
     452,   245,  -104,   146,   534,   432,   293,   182,   322,   557,
      55,   323,   584,    27,   210,    27,    61,    62,    61,    62,
     662,    37,    38,    39,    34,   218,   682,   103,   670,   228,
     608,   203,    48,    -2,    56,    61,    62,   208,   596,   303,
     511,   212,     4,    27,   304,   468,   694,   469,   602,    60,
     108,   292,    69,   234,    -3,    48,   692,   261,   663,   262,
      60,   123,   135,    48,   683,   224,   251,   491,    16,   134,
      16,   103,    61,    62,   585,   367,   224,   605,   138,   383,
      16,   598,   224,   393,   695,   301,   464,   570,  -104,   466,
     284,   198,   113,   390,   246,  -164,   651,    40,   391,   511,
      63,   297,    65,   281,   243,  -164,   285,    57,   371,    58,
     245,   434,   192,   147,   375,   192,   435,    48,    60,   283,
     123,    48,   666,   103,   298,   637,   620,   669,   135,   671,
     123,   368,  -173,  -173,   329,    41,   327,   679,   109,   134,
     330,   103,   110,   103,   533,    50,   335,  -164,   555,   587,
     424,  -164,    60,   429,   154,   351,    67,   208,   113,   114,
     115,   212,    43,   437,   229,   140,   207,    42,   230,   703,
     477,   342,   478,   344,    43,   354,   237,   209,   207,   251,
     110,   408,     7,   410,     9,   197,    43,   437,   106,    16,
      11,    12,    13,    43,   114,   115,   338,   207,   340,   701,
     192,    16,   332,   246,   702,   145,    15,   368,   337,   430,
     378,   388,   360,    16,   438,   389,   343,   421,   153,   628,
      16,   422,   439,   191,    16,    27,    44,    35,    36,   203,
     142,   198,   103,   154,    45,   135,   511,   123,   438,   594,
     123,   123,   539,   230,   188,   444,   439,   191,    54,   521,
     182,   417,   595,   439,   191,   293,   110,   524,   525,    16,
    -271,  -271,   399,   385,   386,    16,   443,   447,   647,   235,
     236,   251,   230,   590,   173,   174,   175,   219,   299,   300,
    -329,  -329,  -329,  -329,   189,   685,   686,   328,  -329,  -329,
    -329,   649,   190,   191,   196,   110,   372,    55,   114,   115,
     522,   213,   192,   255,  -329,    27,   529,    43,   192,   240,
     410,   400,   260,    43,   118,   442,   446,   263,   264,   248,
     539,    56,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,    16,   103,    61,    62,   371,   375,
      16,   250,   507,    61,    62,   371,   375,   489,   131,   132,
     256,   455,   457,   543,    11,    12,    13,   506,   257,   444,
     235,   236,   535,  -103,   258,   119,    60,   439,   191,   108,
     259,    60,   523,   120,   546,   546,   286,   530,   -84,   470,
     471,   114,   115,   472,   287,   458,    43,   536,   291,   520,
     299,   300,   135,   320,   423,   440,   445,   509,   510,    27,
     305,   507,   548,   664,   113,   665,   524,   525,    72,   526,
     527,   528,   569,    16,   531,   532,   506,   187,   219,   319,
     320,  -107,  -107,  -107,  -107,   356,   357,  -107,   571,  -107,
    -107,  -107,   326,   156,   158,   593,   544,   339,    44,   588,
     589,   547,    27,   345,   346,  -107,    45,    54,   697,   445,
     352,   353,   208,   212,   355,   358,   705,   379,    27,   208,
     212,   359,   577,   579,   234,   123,   374,    48,   384,   606,
     135,    60,   609,   612,    43,   118,   387,   520,   545,   123,
     616,   403,   404,   622,   623,   509,   510,   207,   147,   411,
     412,   224,   415,   224,   241,   629,    55,     7,   419,     9,
     100,    16,  -306,   413,  -107,    11,    12,    13,   428,   625,
      16,   433,   436,   420,   599,   451,   393,   639,   184,   454,
      56,    15,   467,   473,    17,   474,   119,   -32,   646,   490,
      27,   551,   440,   440,   120,   189,   552,   553,   507,   445,
     445,   -33,   619,   190,   191,   232,   559,   565,   -20,   -20,
     -20,   -20,   562,   506,   563,   566,   -20,   -20,   -20,   462,
      61,    62,   200,   201,   202,   633,   572,   567,   574,   609,
     580,   113,   -20,   607,  -164,   460,   481,    70,   575,   576,
     618,   615,    71,    72,  -164,    73,   632,   123,   617,    48,
     631,   688,   171,   172,   173,   174,   175,   609,   113,   636,
     638,  -164,   655,    74,   640,    17,   642,    75,    76,    77,
     643,  -164,   169,   170,   171,   172,   173,   174,   175,    78,
     645,   654,    79,   462,   657,   672,  -164,    80,    81,    82,
    -164,   -20,    83,    84,   114,   115,   549,    85,   667,     7,
      57,     9,    58,   681,   676,   481,   558,    11,    12,    13,
      43,   118,   680,  -164,   207,   684,   564,  -164,    86,    87,
     690,   461,   183,    15,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,   693,  -309,  -309,  -309,  -309,  -309,    16,  -309,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,   699,   481,   696,
     610,   597,   119,   704,   324,   382,  -309,   586,   481,  -309,
     120,   481,   425,   481,  -309,  -309,  -309,   456,   129,  -309,
    -309,   537,   241,   541,  -309,     7,   302,     9,   100,     7,
       8,     9,    10,    11,    12,    13,   380,    11,    12,    13,
     556,   604,   542,  -309,   184,  -309,  -309,   341,  -309,    15,
     416,   414,    17,    15,   409,    16,   634,   426,   635,   348,
     453,   481,   219,   370,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,   644,  -116,  -116,  -116,  -116,  -116,   652,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,   431,  -116,  -116,  -116,   653,   689,   691,
       0,   450,     0,   242,  -263,     0,  -116,    52,   376,  -116,
       0,    16,     0,     0,  -116,  -116,  -116,     0,     0,  -116,
    -116,   159,   160,   161,  -116,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,     0,
       0,     0,     0,  -116,  -116,  -116,  -116,   362,  -116,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,     0,  -329,  -329,  -329,
    -329,  -329,     0,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,     0,  -329,
    -329,  -329,     0,     0,     0,     0,     0,     7,     8,     9,
      10,  -329,     0,   449,  -329,    11,    12,    13,     0,  -329,
    -329,  -329,     0,     0,  -329,  -329,     0,     0,     0,  -329,
       0,    15,     0,    16,   538,   131,   132,     7,     8,     9,
      10,    11,    12,    13,     0,    11,    12,    13,  -329,     0,
    -329,  -329,   219,  -329,  -329,  -329,     0,     0,     0,  -329,
    -329,    15,  -329,    16,     0,     0,  -329,     0,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,     0,
    -329,     0,  -329,     0,  -329,  -329,  -329,     0,     0,     0,
       0,     0,     7,     8,     9,    10,  -329,     0,     0,  -329,
      11,    12,    13,     0,  -329,  -329,  -329,     0,     0,  -329,
    -329,     0,     0,     0,  -329,   578,    15,     7,    16,     9,
     197,   130,   131,   132,     0,    11,    12,    13,    11,    12,
      13,     0,     0,  -329,  -302,  -329,  -329,   581,  -329,  -329,
    -329,    15,     0,    16,  -329,  -329,    16,  -329,     0,     0,
       0,  -329,     0,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,     0,  -329,     0,  -329,   189,  -329,
    -329,  -329,     0,     0,     0,     0,   190,   191,     0,     0,
       0,  -329,     0,     0,  -329,     0,     0,     0,     0,  -329,
    -329,  -329,     0,     0,  -329,  -329,     0,     0,     0,  -329,
       0,     0,     7,     8,     9,    10,     0,     0,     0,     0,
      11,    12,    13,     0,     0,     0,     0,     0,  -329,     0,
    -329,  -329,   626,  -329,  -339,  -339,    15,     0,     0,  -339,
    -339,     0,  -339,     0,     0,     0,  -339,     0,  -339,  -339,
    -339,  -339,  -339,  -339,  -339,  -339,  -339,  -339,  -339,     0,
    -339,     0,  -339,     0,  -339,  -339,  -339,     0,   176,   177,
       0,     0,   178,   179,   180,   181,  -339,     0,     0,  -339,
       0,     0,     0,     0,  -339,  -339,  -339,     0,     0,  -339,
    -339,   641,     0,   148,  -339,    70,     7,     0,     9,   100,
      71,    72,     0,    73,    11,    12,    13,     0,     0,     0,
       0,     0,     0,  -339,     0,  -339,  -339,     0,  -339,     0,
      15,    74,     0,    17,     0,    75,    76,    77,   475,     0,
     476,    62,     0,     0,     0,    71,    72,    78,    73,     0,
      79,     0,     0,     0,     0,    80,    81,    82,     0,     0,
      83,    84,     0,     0,     0,    85,    74,     0,    17,     0,
      75,    76,    77,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    78,     0,     0,    79,    86,    87,     0,   149,
      80,    81,    82,     0,     0,    83,    84,     0,     0,   477,
      85,   478,   475,     0,   476,    62,     0,     0,     0,    71,
      72,     0,    73,     0,     0,     0,     0,     0,     0,     0,
    -192,    86,    87,     0,   479,     0,     0,     0,     0,     0,
      74,     0,    17,     0,    75,    76,    77,     0,     0,     0,
       0,     0,     0,   475,     0,    70,    78,     0,     0,    79,
      71,    72,     0,    73,    80,    81,    82,     0,     0,    83,
      84,     0,     0,   477,    85,   478,     0,     0,     0,     0,
       0,    74,     0,    17,     0,    75,    76,    77,     0,     0,
       0,     0,  -205,     0,  -260,    86,    87,    78,   479,     0,
      79,     0,     0,     0,     0,    80,    81,    82,     0,     0,
      83,    84,     0,     0,  -205,    85,  -205,   475,     0,    70,
       0,     0,     0,     0,    71,    72,     0,    73,     0,   112,
       0,     0,   -28,   -28,   -28,   -28,    86,    87,     0,   479,
     -28,   -28,   -28,     0,     0,    74,     0,    17,     0,    75,
      76,    77,     0,     0,     0,   113,   -28,     7,  -164,     9,
     100,    78,     0,     0,    79,    11,    12,    13,  -164,    80,
      81,    82,     0,     0,    83,    84,     0,     0,     0,    85,
       0,    15,   238,     0,     0,   -24,   -24,   -24,   -24,     0,
       0,   114,   115,   -24,   -24,   -24,     0,     0,     0,     0,
      86,    87,     0,   479,     0,     0,     0,     0,   113,   -24,
    -164,  -164,   176,   177,  -164,   -28,   178,   179,   180,   181,
      70,  -164,     0,     0,     0,    71,    72,   307,    73,   308,
       7,     8,     9,    10,     0,     0,   309,     0,    11,    12,
      13,     0,     0,     0,   114,   115,    74,     0,    17,     0,
      75,    76,    77,     0,    15,     0,    16,     0,     0,     0,
       0,     0,    78,  -164,     0,    79,     0,  -164,   -24,     0,
      80,    81,   216,     0,     0,    83,    84,     0,    70,     0,
      85,     0,     0,    71,    72,   307,    73,     0,     7,     8,
       9,    10,     0,     0,   309,     0,    11,    12,    13,     0,
       0,    86,    87,     0,    74,   217,    17,  -389,    75,    76,
      77,     0,    15,     0,    16,     0,    70,     0,     0,     0,
      78,    71,    72,    79,    73,     0,     0,     0,    80,    81,
      82,     0,     0,    83,    84,     0,     0,     0,    85,     0,
       0,     0,    74,     0,    17,     0,    75,    76,    77,   168,
     169,   170,   171,   172,   173,   174,   175,     0,    78,    86,
      87,    79,     0,   296,     0,  -389,    80,    81,    82,     0,
       0,    83,    84,     0,    70,     0,    85,     0,     0,    71,
      72,   161,    73,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    86,    87,     0,
      74,   318,    17,     0,    75,    76,    77,     0,     0,     0,
       0,     0,    70,     0,     0,     0,    78,    71,    72,    79,
      73,     0,     0,     0,    80,    81,    82,     0,     0,    83,
      84,     0,     0,     0,    85,     0,     0,     0,    74,     0,
      17,     0,    75,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    86,    87,    79,     0,   334,
       0,     0,    80,    81,    82,     0,     0,    83,    84,     0,
      70,     0,    85,     0,     0,    71,    72,     0,    73,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,    86,    87,     0,    74,   377,    17,     0,
      75,    76,    77,     0,     0,     0,     0,     0,    70,     0,
       0,     0,    78,    71,    72,    79,    73,     0,     0,     0,
      80,    81,   591,     0,     0,    83,    84,     0,     0,     0,
      85,     0,     0,     0,    74,     0,    17,     0,    75,    76,
      77,   613,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    86,    87,    79,     0,   592,     0,     0,    80,    81,
      82,     0,     0,    83,    84,     0,     0,     0,    85,     0,
       0,   159,   160,   161,   614,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    86,
      87,     0,     0,   630,   476,   492,     8,     9,    10,    71,
      72,     0,    73,    11,    12,    13,   493,     0,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,    15,
      74,    16,    17,     0,    75,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,    79,
       0,     0,     0,     0,    80,    81,    82,     0,     0,    83,
      84,     0,     0,     0,    85,   159,   160,   161,   661,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   505,     0,    86,    87,     0,   393,   476,
      62,     0,     0,     0,    71,    72,     0,    73,     0,     0,
       0,   493,     0,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,    74,     0,    17,     0,    75,
      76,    77,     0,     0,    70,     0,     0,     0,     0,    71,
      72,    78,    73,     0,    79,     0,     0,     0,     0,    80,
      81,    82,     0,     0,    83,    84,     0,     0,     0,    85,
      74,     0,    17,     0,    75,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,   505,    79,
      86,    87,     0,   393,    80,    81,    82,     0,     0,    83,
      84,     0,     0,     0,    85,    70,     7,     8,     9,    10,
      71,    72,     0,    73,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,   350,     0,
      15,    74,    16,    17,     0,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      79,     0,     0,     0,     0,    80,    81,    82,     0,     0,
      83,    84,     0,    70,     7,    85,     9,   100,    71,    72,
       0,    73,    11,    12,    13,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    86,    87,    15,    74,
       0,    17,     0,    75,    76,    77,    70,     0,     0,     0,
       0,    71,    72,     0,    73,    78,     0,     0,    79,     0,
       0,     0,     0,    80,    81,    82,     0,     0,    83,    84,
       0,     0,    74,    85,    17,     0,    75,    76,    77,    70,
       0,     0,     0,     0,    71,    72,     0,    73,    78,     0,
       0,    79,     0,     0,    86,    87,    80,    81,    82,     0,
       0,    83,    84,     0,     0,    74,    85,    17,     0,    75,
      76,    77,    70,     0,     0,     0,     0,    71,    72,     0,
      73,    78,     0,     0,    79,   568,     0,    86,    87,    80,
      81,    82,     0,     0,    83,    84,     0,     0,    74,    85,
      17,     0,    75,    76,    77,    70,     0,     0,     0,     0,
      71,    72,     0,    73,    78,     0,     0,    79,     0,     0,
      86,    87,    80,    81,    82,     0,     0,    83,    84,     0,
       0,    74,   155,    17,     0,    75,    76,    77,   381,     0,
       0,     0,     0,    71,    72,     0,    73,    78,     0,     0,
      79,     0,     0,    86,    87,    80,    81,    82,     0,     0,
      83,    84,     0,     0,    74,   157,    17,     0,    75,    76,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,    79,     0,     0,    86,    87,    80,    81,
      82,     0,     0,    83,    84,     0,     0,     6,    85,  -120,
       7,     8,     9,    10,     0,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,     0,     0,    14,    15,     0,    16,    17,     0,     0,
     600,   159,   160,   161,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,     0,
       0,  -120,     0,     0,     0,     0,     0,     0,     0,  -120,
     159,   160,   161,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    18,   656,
     159,   160,   161,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,     0,
       0,     0,     0,     0,     0,   159,   160,   161,   601,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,     0,     0,     0,   349,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175
};

static const yytype_int16 yycheck[] =
{
      40,    41,    22,    27,    29,    30,    31,    51,    53,   116,
       3,    24,     5,    37,    38,    39,   124,   213,     3,     3,
       5,     5,    75,    76,    48,    45,    23,    24,   195,    82,
      48,   119,    56,    53,   235,    88,   105,    85,   233,    65,
      33,   295,    59,   179,   239,   137,    99,     1,    33,    33,
     392,   137,     1,    78,   455,   368,   190,     9,   221,   487,
      24,    10,     1,     3,   110,     5,     3,     4,     3,     4,
      43,    11,    12,    13,     5,   115,    43,    41,   659,   120,
     561,   106,    22,     0,    24,     3,     4,   107,   540,    81,
     432,   111,     0,    33,    86,   408,    43,   410,   550,   123,
     120,   189,    33,   211,     0,    45,   687,   155,    81,   157,
     134,    51,   129,    53,    81,   222,   141,   430,    30,    59,
      30,    85,     3,     4,    63,   288,   233,   555,    87,    81,
      30,    43,   239,    87,    81,   302,   402,    55,    87,   405,
     180,   105,    27,    81,   137,    30,   627,    63,    86,   491,
      87,   191,    87,   178,   246,    40,   181,     5,   292,     7,
     246,    81,   102,   216,   298,   105,    86,   107,   192,   305,
     110,   111,   653,   137,   192,   603,   577,   658,   195,   660,
     120,   288,    82,    83,   230,    63,   227,   668,    82,   129,
     231,   155,    86,   157,   448,    82,   236,    82,    40,    81,
     363,    86,   226,   366,    86,   258,    87,   227,    27,    63,
      64,   231,     3,     4,    82,    87,     7,    63,    86,   700,
      62,   247,    64,   249,     3,   265,    82,    81,     7,   254,
      86,   338,     4,   340,     6,     7,     3,     4,    63,    30,
      12,    13,    14,     3,    63,    64,   243,     7,   245,    81,
     190,    30,   234,   246,    86,    63,    28,   364,   240,   366,
     300,    82,   287,    30,    55,    86,   248,    82,    81,   582,
      30,    86,    63,    64,    30,   215,    55,    82,    83,   304,
      87,   245,   246,    86,    63,   302,   628,   227,    55,    82,
     230,   231,   459,    86,    81,    55,    63,    64,   311,   435,
       9,   349,    82,    63,    64,   439,    86,    63,    64,    30,
      82,    83,   325,   310,   311,    30,   385,   386,    82,    63,
      64,   346,    86,   524,    55,    56,    57,     1,    63,    64,
       4,     5,     6,     7,    55,   677,   678,    81,    12,    13,
      14,    82,    63,    64,    81,    86,    81,   311,    63,    64,
     438,    63,   292,   145,    28,   295,   444,     3,   298,    83,
     467,   325,   154,     3,     4,   385,   386,   159,   160,    83,
     537,   311,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    30,   349,     3,     4,   522,   523,
      30,     1,   432,     3,     4,   529,   530,   422,     6,     7,
      81,   398,   399,    43,    12,    13,    14,   432,    81,    55,
      63,    64,   457,    87,    81,    55,   440,    63,    64,   439,
      82,   445,   440,    63,   468,   469,    81,   445,    43,   411,
     412,    63,    64,   415,    32,   399,     3,   457,    81,   432,
      63,    64,   459,    82,    83,   385,   386,   432,   432,   389,
      63,   491,   477,   648,    27,   650,    63,    64,     9,   441,
     442,   443,   502,    30,   446,   447,   491,   520,     1,    88,
      82,     4,     5,     6,     7,   267,   268,    10,   503,    12,
      13,    14,    40,    92,    93,   525,   468,    82,    55,   522,
     523,   473,   432,    40,    86,    28,    63,   510,   694,   439,
      81,    81,   522,   523,    43,    81,   702,    81,   448,   529,
     530,    88,   509,   510,   622,   455,    88,   457,    81,   559,
     537,   545,   562,   563,     3,     4,    81,   520,   468,   469,
     570,    40,    88,   577,   579,   520,   520,     7,   591,    83,
      83,   648,    83,   650,     1,   585,   510,     4,    43,     6,
       7,    30,    83,   345,    87,    12,    13,    14,    83,   579,
      30,    88,    81,   355,   546,     3,    87,   607,    83,    82,
     510,    28,    86,    83,    31,    81,    55,    43,   618,    83,
     520,    43,   522,   523,    63,    55,    83,    86,   628,   529,
     530,    43,   574,    63,    64,     1,    63,    43,     4,     5,
       6,     7,    63,   628,    63,    82,    12,    13,    14,   401,
       3,     4,     5,     6,     7,   597,     7,    82,    43,   659,
      16,    27,    28,    63,    30,     1,   418,     3,    82,    82,
      63,    82,     8,     9,    40,    11,    83,   577,    82,   579,
      88,   681,    53,    54,    55,    56,    57,   687,    27,    83,
      81,    30,   634,    29,    17,    31,    82,    33,    34,    35,
      81,    40,    51,    52,    53,    54,    55,    56,    57,    45,
      82,    81,    48,   465,    81,     9,    82,    53,    54,    55,
      86,    87,    58,    59,    63,    64,   478,    63,    82,     4,
       5,     6,     7,    63,    82,   487,   488,    12,    13,    14,
       3,     4,    82,    82,     7,    86,   498,    86,    84,    85,
      82,    87,     1,    28,     3,     4,     5,     6,     7,     8,
       9,    81,    11,    12,    13,    14,    15,    30,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    82,   540,    81,
     562,   543,    55,    82,   222,   305,    45,   520,   550,    48,
      63,   553,   364,   555,    53,    54,    55,    82,    55,    58,
      59,   458,     1,   465,    63,     4,   198,     6,     7,     4,
       5,     6,     7,    12,    13,    14,   304,    12,    13,    14,
     486,   553,   467,    82,    83,    84,    85,   246,    87,    28,
     348,   346,    31,    28,   340,    30,   598,   364,   600,   254,
     395,   603,     1,   289,     3,     4,     5,     6,     7,     8,
       9,   613,    11,    12,    13,    14,    15,   628,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   366,    33,    34,    35,   628,   682,   684,
      -1,   389,    -1,    82,    83,    -1,    45,    82,   299,    48,
      -1,    30,    -1,    -1,    53,    54,    55,    -1,    -1,    58,
      59,    40,    41,    42,    63,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,     1,    87,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
       7,    45,    -1,    10,    48,    12,    13,    14,    -1,    53,
      54,    55,    -1,    -1,    58,    59,    -1,    -1,    -1,    63,
      -1,    28,    -1,    30,     5,     6,     7,     4,     5,     6,
       7,    12,    13,    14,    -1,    12,    13,    14,    82,    -1,
      84,    85,     1,    87,     3,     4,    -1,    -1,    -1,     8,
       9,    28,    11,    30,    -1,    -1,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,     4,     5,     6,     7,    45,    -1,    -1,    48,
      12,    13,    14,    -1,    53,    54,    55,    -1,    -1,    58,
      59,    -1,    -1,    -1,    63,    82,    28,     4,    30,     6,
       7,     5,     6,     7,    -1,    12,    13,    14,    12,    13,
      14,    -1,    -1,    82,    83,    84,    85,     1,    87,     3,
       4,    28,    -1,    30,     8,     9,    30,    11,    -1,    -1,
      -1,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    31,    55,    33,
      34,    35,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    58,    59,    -1,    -1,    -1,    63,
      -1,    -1,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      84,    85,     1,    87,     3,     4,    28,    -1,    -1,     8,
       9,    -1,    11,    -1,    -1,    -1,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    31,    -1,    33,    34,    35,    -1,    58,    59,
      -1,    -1,    62,    63,    64,    65,    45,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,    58,
      59,    81,    -1,     1,    63,     3,     4,    -1,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    84,    85,    -1,    87,    -1,
      28,    29,    -1,    31,    -1,    33,    34,    35,     1,    -1,
       3,     4,    -1,    -1,    -1,     8,     9,    45,    11,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,
      58,    59,    -1,    -1,    -1,    63,    29,    -1,    31,    -1,
      33,    34,    35,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    45,    -1,    -1,    48,    84,    85,    -1,    87,
      53,    54,    55,    -1,    -1,    58,    59,    -1,    -1,    62,
      63,    64,     1,    -1,     3,     4,    -1,    -1,    -1,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,    45,    -1,    -1,    48,
       8,     9,    -1,    11,    53,    54,    55,    -1,    -1,    58,
      59,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    -1,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    83,    84,    85,    45,    87,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,
      58,    59,    -1,    -1,    62,    63,    64,     1,    -1,     3,
      -1,    -1,    -1,    -1,     8,     9,    -1,    11,    -1,     1,
      -1,    -1,     4,     5,     6,     7,    84,    85,    -1,    87,
      12,    13,    14,    -1,    -1,    29,    -1,    31,    -1,    33,
      34,    35,    -1,    -1,    -1,    27,    28,     4,    30,     6,
       7,    45,    -1,    -1,    48,    12,    13,    14,    40,    53,
      54,    55,    -1,    -1,    58,    59,    -1,    -1,    -1,    63,
      -1,    28,     1,    -1,    -1,     4,     5,     6,     7,    -1,
      -1,    63,    64,    12,    13,    14,    -1,    -1,    -1,    -1,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    27,    28,
      82,    30,    58,    59,    86,    87,    62,    63,    64,    65,
       3,    40,    -1,    -1,    -1,     8,     9,     1,    11,     3,
       4,     5,     6,     7,    -1,    -1,    10,    -1,    12,    13,
      14,    -1,    -1,    -1,    63,    64,    29,    -1,    31,    -1,
      33,    34,    35,    -1,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    45,    82,    -1,    48,    -1,    86,    87,    -1,
      53,    54,    55,    -1,    -1,    58,    59,    -1,     3,    -1,
      63,    -1,    -1,     8,     9,     1,    11,    -1,     4,     5,
       6,     7,    -1,    -1,    10,    -1,    12,    13,    14,    -1,
      -1,    84,    85,    -1,    29,    88,    31,    81,    33,    34,
      35,    -1,    28,    -1,    30,    -1,     3,    -1,    -1,    -1,
      45,     8,     9,    48,    11,    -1,    -1,    -1,    53,    54,
      55,    -1,    -1,    58,    59,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    29,    -1,    31,    -1,    33,    34,    35,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    45,    84,
      85,    48,    -1,    88,    -1,    81,    53,    54,    55,    -1,
      -1,    58,    59,    -1,     3,    -1,    63,    -1,    -1,     8,
       9,    42,    11,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    84,    85,    -1,
      29,    88,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    45,     8,     9,    48,
      11,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,    58,
      59,    -1,    -1,    -1,    63,    -1,    -1,    -1,    29,    -1,
      31,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    84,    85,    48,    -1,    88,
      -1,    -1,    53,    54,    55,    -1,    -1,    58,    59,    -1,
       3,    -1,    63,    -1,    -1,     8,     9,    -1,    11,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    84,    85,    -1,    29,    88,    31,    -1,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    45,     8,     9,    48,    11,    -1,    -1,    -1,
      53,    54,    55,    -1,    -1,    58,    59,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,    34,
      35,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    84,    85,    48,    -1,    88,    -1,    -1,    53,    54,
      55,    -1,    -1,    58,    59,    -1,    -1,    -1,    63,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    84,
      85,    -1,    -1,    88,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,    58,
      59,    -1,    -1,    -1,    63,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    82,    -1,    84,    85,    -1,    87,     3,
       4,    -1,    -1,    -1,     8,     9,    -1,    11,    -1,    -1,
      -1,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    31,    -1,    33,
      34,    35,    -1,    -1,     3,    -1,    -1,    -1,    -1,     8,
       9,    45,    11,    -1,    48,    -1,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    58,    59,    -1,    -1,    -1,    63,
      29,    -1,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    82,    48,
      84,    85,    -1,    87,    53,    54,    55,    -1,    -1,    58,
      59,    -1,    -1,    -1,    63,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    87,    -1,
      28,    29,    30,    31,    -1,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,
      58,    59,    -1,     3,     4,    63,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    84,    85,    28,    29,
      -1,    31,    -1,    33,    34,    35,     3,    -1,    -1,    -1,
      -1,     8,     9,    -1,    11,    45,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    53,    54,    55,    -1,    -1,    58,    59,
      -1,    -1,    29,    63,    31,    -1,    33,    34,    35,     3,
      -1,    -1,    -1,    -1,     8,     9,    -1,    11,    45,    -1,
      -1,    48,    -1,    -1,    84,    85,    53,    54,    55,    -1,
      -1,    58,    59,    -1,    -1,    29,    63,    31,    -1,    33,
      34,    35,     3,    -1,    -1,    -1,    -1,     8,     9,    -1,
      11,    45,    -1,    -1,    48,    82,    -1,    84,    85,    53,
      54,    55,    -1,    -1,    58,    59,    -1,    -1,    29,    63,
      31,    -1,    33,    34,    35,     3,    -1,    -1,    -1,    -1,
       8,     9,    -1,    11,    45,    -1,    -1,    48,    -1,    -1,
      84,    85,    53,    54,    55,    -1,    -1,    58,    59,    -1,
      -1,    29,    63,    31,    -1,    33,    34,    35,     3,    -1,
      -1,    -1,    -1,     8,     9,    -1,    11,    45,    -1,    -1,
      48,    -1,    -1,    84,    85,    53,    54,    55,    -1,    -1,
      58,    59,    -1,    -1,    29,    63,    31,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    48,    -1,    -1,    84,    85,    53,    54,
      55,    -1,    -1,    58,    59,    -1,    -1,     1,    63,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    27,    28,    -1,    30,    31,    -1,    -1,
      10,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    82,    88,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    88,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    86,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    90,    91,    92,     0,    93,     1,     4,     5,     6,
       7,    12,    13,    14,    27,    28,    30,    31,    82,    94,
      95,    96,   127,   130,   134,   135,   138,   148,   149,   173,
     174,   175,   176,   247,    94,    82,    83,   148,   148,   148,
      63,    63,    63,     3,    55,    63,   141,   145,   148,   172,
      82,   127,    82,   127,   135,   138,   148,     5,     7,   131,
     149,     3,     4,    87,   103,    87,   103,    87,   103,    94,
       3,     8,     9,    11,    29,    33,    34,    35,    45,    48,
      53,    54,    55,    58,    59,    63,    84,    85,   104,   105,
     107,   108,   109,   110,   111,   113,   119,   120,   206,   247,
       7,   105,   136,   138,   190,   192,    63,   193,   172,    82,
      86,   128,     1,    27,    63,    64,   101,   142,     4,    55,
      63,   140,   143,   148,   169,   170,   172,   141,   172,   131,
       5,     6,     7,   139,   148,   176,   183,   184,    87,   183,
      87,   180,    87,   111,   111,    63,   103,   111,     1,    87,
     105,   190,   111,    81,    86,    63,   108,    63,   108,    40,
      41,    42,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    62,    63,
      64,    65,     9,     1,    83,   199,   205,   111,    81,    55,
      63,    64,   148,   191,   194,   137,    81,     7,   138,   191,
       5,     6,     7,   103,   150,   151,   152,     7,   172,    81,
     143,   169,   172,    63,   242,   243,    55,    88,   105,     1,
     121,   122,   123,   198,   212,   147,   148,   193,   170,    82,
      86,   128,     1,    97,   142,    63,    64,    82,     1,    99,
      83,     1,    82,   136,   185,   192,   247,   177,    83,   178,
       1,   103,   188,   189,   179,   113,    81,    81,    81,    82,
     113,   190,   190,   113,   113,   116,   118,   115,   114,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   103,   106,   107,   105,   103,    81,    32,   200,   201,
     202,    81,   193,   194,   235,   236,    88,   105,   128,    63,
      64,   139,   137,    81,    86,    63,   120,     1,     3,    10,
     130,   134,   237,   239,   240,   241,   244,   245,    88,    88,
      82,   102,   198,    10,   122,   213,    40,   170,    81,   143,
     170,   121,   147,   242,    88,   105,   121,   147,   127,    82,
     127,   185,   183,   147,   183,    40,    86,   182,   188,    86,
      87,   111,    81,    81,   105,    43,   113,   113,    81,    88,
     103,   246,     1,   125,   126,   195,   196,   198,   212,   215,
     202,   194,    81,   237,    88,   194,   235,    88,   105,    81,
     151,     3,   106,    81,    81,   127,   127,    81,    82,    86,
      81,    86,     1,    87,   203,   204,   207,   124,   132,   135,
     138,   146,    98,    40,    88,   100,   186,   187,   212,   186,
     212,    83,    83,   113,   189,    83,   182,   190,   112,    43,
     113,    82,    86,    83,   198,   125,   195,   197,    83,   198,
     212,   215,   213,    88,    81,    86,    81,     4,    55,    63,
     148,   171,   172,   191,    55,   148,   172,   191,   238,    10,
     241,     3,   207,   205,    82,   127,    82,   127,   138,   133,
       1,    87,   113,   153,   203,   144,   203,    86,   213,   213,
     147,   147,   147,    83,    81,     1,     3,    62,    64,    87,
     103,   113,   155,   156,   157,   159,   161,   162,   117,   103,
      83,   213,     4,    15,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    82,   103,   105,   129,   130,
     134,   207,   208,   209,   210,   216,   217,   225,   226,   228,
     247,   107,   193,   128,    63,    64,   147,   147,   147,   193,
     128,   147,   147,   237,   140,   141,   172,   133,     5,   139,
     154,   153,   187,    43,   147,   148,   169,   147,   103,   113,
     160,    43,    83,    86,   181,    40,   162,   159,   113,    63,
     219,   211,    63,    63,   113,    43,    82,    82,    82,   105,
      55,   103,     7,   229,    43,    82,    82,   127,    82,   127,
      16,     1,   212,   214,     1,    63,   129,    81,   171,   171,
     242,    55,    88,   105,    82,    82,   155,   113,    43,   147,
      10,    88,   155,   158,   157,   159,   105,    63,   214,   105,
     119,   230,   105,    10,    43,    82,   105,    82,    63,   147,
     140,   163,   169,   141,   166,   172,     1,   218,   213,   105,
      88,    88,    83,   147,   113,   113,    83,   159,    81,   105,
      17,    81,    82,    81,   113,    82,   105,    82,   164,    82,
     167,   214,   217,   228,    81,   147,    88,    81,   227,   221,
     224,    43,    43,    81,   121,   121,   214,    82,   220,   214,
     230,   214,     9,   231,   232,   233,    82,   165,   168,   214,
      82,    63,    43,    81,    86,   207,   207,   222,   105,   231,
      82,   233,   230,    81,    43,    81,    81,   120,   234,    82,
     223,    81,    86,   214,    82,   120
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
#line 234 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ANSI C forbids an empty source file");
		  finish_file ();
		;}
    break;

  case 3:
#line 239 "c-parse.y"
    {
		  /* In case there were missing closebraces,
		     get us back to the global binding level.  */
		  while (! global_bindings_p ())
		    poplevel (0, 0, 0);
		  finish_file ();
		;}
    break;

  case 4:
#line 253 "c-parse.y"
    {(yyval.ttype) = NULL_TREE; ;}
    break;

  case 6:
#line 254 "c-parse.y"
    {(yyval.ttype) = NULL_TREE; ggc_collect(); ;}
    break;

  case 10:
#line 261 "c-parse.y"
    { STRIP_NOPS ((yyvsp[(3) - (5)].ttype));
		  if ((TREE_CODE ((yyvsp[(3) - (5)].ttype)) == ADDR_EXPR
		       && TREE_CODE (TREE_OPERAND ((yyvsp[(3) - (5)].ttype), 0)) == STRING_CST)
		      || TREE_CODE ((yyvsp[(3) - (5)].ttype)) == STRING_CST)
		    assemble_asm ((yyvsp[(3) - (5)].ttype));
		  else
		    error ("argument of `asm' is not a constant string"); ;}
    break;

  case 11:
#line 269 "c-parse.y"
    { RESTORE_WARN_FLAGS ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 12:
#line 274 "c-parse.y"
    { if (pedantic)
		    error ("ANSI C forbids data definition with no type or storage class");
		  else if (!flag_traditional)
		    warning ("data definition has no type or storage class"); 

		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 13:
#line 283 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 14:
#line 287 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 15:
#line 291 "c-parse.y"
    { pedwarn ("empty declaration"); ;}
    break;

  case 16:
#line 293 "c-parse.y"
    { shadow_tag ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 19:
#line 297 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ANSI C does not allow extra `;' outside of a function"); ;}
    break;

  case 20:
#line 303 "c-parse.y"
    { if (! start_function (current_declspecs, (yyvsp[(3) - (3)].ttype),
					prefix_attributes, NULL_TREE))
		    YYERROR1;
		  reinit_parse_for_function (); ;}
    break;

  case 21:
#line 308 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 22:
#line 310 "c-parse.y"
    { finish_function (0); 
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 23:
#line 315 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 24:
#line 319 "c-parse.y"
    { if (! start_function (current_declspecs, (yyvsp[(3) - (3)].ttype),
					prefix_attributes, NULL_TREE))
		    YYERROR1;
		  reinit_parse_for_function (); ;}
    break;

  case 25:
#line 324 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 26:
#line 326 "c-parse.y"
    { finish_function (0); 
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 27:
#line 331 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 28:
#line 335 "c-parse.y"
    { if (! start_function (NULL_TREE, (yyvsp[(2) - (2)].ttype),
					prefix_attributes, NULL_TREE))
		    YYERROR1;
		  reinit_parse_for_function (); ;}
    break;

  case 29:
#line 340 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 30:
#line 342 "c-parse.y"
    { finish_function (0); 
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 31:
#line 347 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 34:
#line 358 "c-parse.y"
    { (yyval.code) = ADDR_EXPR; ;}
    break;

  case 35:
#line 360 "c-parse.y"
    { (yyval.code) = NEGATE_EXPR; ;}
    break;

  case 36:
#line 362 "c-parse.y"
    { (yyval.code) = CONVERT_EXPR;
  if (warn_traditional)
    warning ("traditional C rejects the unary plus operator");
		;}
    break;

  case 37:
#line 367 "c-parse.y"
    { (yyval.code) = PREINCREMENT_EXPR; ;}
    break;

  case 38:
#line 369 "c-parse.y"
    { (yyval.code) = PREDECREMENT_EXPR; ;}
    break;

  case 39:
#line 371 "c-parse.y"
    { (yyval.code) = BIT_NOT_EXPR; ;}
    break;

  case 40:
#line 373 "c-parse.y"
    { (yyval.code) = TRUTH_NOT_EXPR; ;}
    break;

  case 41:
#line 377 "c-parse.y"
    { (yyval.ttype) = build_compound_expr ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 42:
#line 382 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 44:
#line 388 "c-parse.y"
    { (yyval.ttype) = build_tree_list (NULL_TREE, (yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 45:
#line 390 "c-parse.y"
    { chainon ((yyvsp[(1) - (3)].ttype), build_tree_list (NULL_TREE, (yyvsp[(3) - (3)].ttype))); ;}
    break;

  case 47:
#line 396 "c-parse.y"
    { (yyval.ttype) = build_indirect_ref ((yyvsp[(2) - (2)].ttype), "unary *"); ;}
    break;

  case 48:
#line 399 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype);
		  RESTORE_WARN_FLAGS ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 49:
#line 402 "c-parse.y"
    { (yyval.ttype) = build_unary_op ((yyvsp[(1) - (2)].code), (yyvsp[(2) - (2)].ttype), 0);
		  overflow_warning ((yyval.ttype)); ;}
    break;

  case 50:
#line 406 "c-parse.y"
    { tree label = lookup_label ((yyvsp[(2) - (2)].ttype));
		  if (pedantic)
		    pedwarn ("ANSI C forbids `&&'");
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
#line 434 "c-parse.y"
    { skip_evaluation--;
		  if (TREE_CODE ((yyvsp[(2) - (2)].ttype)) == COMPONENT_REF
		      && DECL_C_BIT_FIELD (TREE_OPERAND ((yyvsp[(2) - (2)].ttype), 1)))
		    error ("`sizeof' applied to a bit-field");
		  (yyval.ttype) = c_sizeof (TREE_TYPE ((yyvsp[(2) - (2)].ttype))); ;}
    break;

  case 52:
#line 440 "c-parse.y"
    { skip_evaluation--;
		  (yyval.ttype) = c_sizeof (groktypename ((yyvsp[(3) - (4)].ttype))); ;}
    break;

  case 53:
#line 443 "c-parse.y"
    { skip_evaluation--;
		  (yyval.ttype) = c_alignof_expr ((yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 54:
#line 446 "c-parse.y"
    { skip_evaluation--;
		  (yyval.ttype) = c_alignof (groktypename ((yyvsp[(3) - (4)].ttype))); ;}
    break;

  case 55:
#line 449 "c-parse.y"
    { (yyval.ttype) = build_unary_op (REALPART_EXPR, (yyvsp[(2) - (2)].ttype), 0); ;}
    break;

  case 56:
#line 451 "c-parse.y"
    { (yyval.ttype) = build_unary_op (IMAGPART_EXPR, (yyvsp[(2) - (2)].ttype), 0); ;}
    break;

  case 57:
#line 453 "c-parse.y"
    { (yyval.ttype) = build_va_arg ((yyvsp[(3) - (6)].ttype), groktypename ((yyvsp[(5) - (6)].ttype))); ;}
    break;

  case 58:
#line 457 "c-parse.y"
    { skip_evaluation++; ;}
    break;

  case 59:
#line 461 "c-parse.y"
    { skip_evaluation++; ;}
    break;

  case 61:
#line 467 "c-parse.y"
    { tree type = groktypename ((yyvsp[(2) - (4)].ttype));
		  (yyval.ttype) = build_c_cast (type, (yyvsp[(4) - (4)].ttype)); ;}
    break;

  case 62:
#line 470 "c-parse.y"
    { start_init (NULL_TREE, NULL, 0);
		  (yyvsp[(2) - (4)].ttype) = groktypename ((yyvsp[(2) - (4)].ttype));
		  really_start_incremental_init ((yyvsp[(2) - (4)].ttype)); ;}
    break;

  case 63:
#line 474 "c-parse.y"
    { const char *name;
		  tree result = pop_init_level (0);
		  tree type = (yyvsp[(2) - (7)].ttype);
		  finish_init ();

		  if (pedantic && ! flag_isoc99)
		    pedwarn ("ANSI C forbids constructor expressions");
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
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 75:
#line 523 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 76:
#line 525 "c-parse.y"
    { (yyval.ttype) = parser_build_binary_op ((yyvsp[(2) - (3)].code), (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 77:
#line 527 "c-parse.y"
    { (yyvsp[(1) - (2)].ttype) = truthvalue_conversion (default_conversion ((yyvsp[(1) - (2)].ttype)));
		  skip_evaluation += (yyvsp[(1) - (2)].ttype) == boolean_false_node; ;}
    break;

  case 78:
#line 530 "c-parse.y"
    { skip_evaluation -= (yyvsp[(1) - (4)].ttype) == boolean_false_node;
		  (yyval.ttype) = parser_build_binary_op (TRUTH_ANDIF_EXPR, (yyvsp[(1) - (4)].ttype), (yyvsp[(4) - (4)].ttype)); ;}
    break;

  case 79:
#line 533 "c-parse.y"
    { (yyvsp[(1) - (2)].ttype) = truthvalue_conversion (default_conversion ((yyvsp[(1) - (2)].ttype)));
		  skip_evaluation += (yyvsp[(1) - (2)].ttype) == boolean_true_node; ;}
    break;

  case 80:
#line 536 "c-parse.y"
    { skip_evaluation -= (yyvsp[(1) - (4)].ttype) == boolean_true_node;
		  (yyval.ttype) = parser_build_binary_op (TRUTH_ORIF_EXPR, (yyvsp[(1) - (4)].ttype), (yyvsp[(4) - (4)].ttype)); ;}
    break;

  case 81:
#line 539 "c-parse.y"
    { (yyvsp[(1) - (2)].ttype) = truthvalue_conversion (default_conversion ((yyvsp[(1) - (2)].ttype)));
		  skip_evaluation += (yyvsp[(1) - (2)].ttype) == boolean_false_node; ;}
    break;

  case 82:
#line 542 "c-parse.y"
    { skip_evaluation += (((yyvsp[(1) - (5)].ttype) == boolean_true_node)
				      - ((yyvsp[(1) - (5)].ttype) == boolean_false_node)); ;}
    break;

  case 83:
#line 545 "c-parse.y"
    { skip_evaluation -= (yyvsp[(1) - (7)].ttype) == boolean_true_node;
		  (yyval.ttype) = build_conditional_expr ((yyvsp[(1) - (7)].ttype), (yyvsp[(4) - (7)].ttype), (yyvsp[(7) - (7)].ttype)); ;}
    break;

  case 84:
#line 548 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ANSI C forbids omitting the middle term of a ?: expression");
		  /* Make sure first operand is calculated only once.  */
		  (yyvsp[(2) - (2)].ttype) = save_expr ((yyvsp[(1) - (2)].ttype));
		  (yyvsp[(1) - (2)].ttype) = truthvalue_conversion (default_conversion ((yyvsp[(2) - (2)].ttype)));
		  skip_evaluation += (yyvsp[(1) - (2)].ttype) == boolean_true_node; ;}
    break;

  case 85:
#line 555 "c-parse.y"
    { skip_evaluation -= (yyvsp[(1) - (5)].ttype) == boolean_true_node;
		  (yyval.ttype) = build_conditional_expr ((yyvsp[(1) - (5)].ttype), (yyvsp[(2) - (5)].ttype), (yyvsp[(5) - (5)].ttype)); ;}
    break;

  case 86:
#line 558 "c-parse.y"
    { char class;
		  (yyval.ttype) = build_modify_expr ((yyvsp[(1) - (3)].ttype), NOP_EXPR, (yyvsp[(3) - (3)].ttype));
		  class = TREE_CODE_CLASS (TREE_CODE ((yyval.ttype)));
		  if (class == 'e' || class == '1'
		      || class == '2' || class == '<')
		    C_SET_EXP_ORIGINAL_CODE ((yyval.ttype), MODIFY_EXPR);
		;}
    break;

  case 87:
#line 566 "c-parse.y"
    { char class;
		  (yyval.ttype) = build_modify_expr ((yyvsp[(1) - (3)].ttype), (yyvsp[(2) - (3)].code), (yyvsp[(3) - (3)].ttype));
		  /* This inhibits warnings in truthvalue_conversion.  */
		  class = TREE_CODE_CLASS (TREE_CODE ((yyval.ttype)));
		  if (class == 'e' || class == '1'
		      || class == '2' || class == '<')
		    C_SET_EXP_ORIGINAL_CODE ((yyval.ttype), ERROR_MARK);
		;}
    break;

  case 88:
#line 578 "c-parse.y"
    {
		  if (yychar == YYEMPTY)
		    yychar = YYLEX;
		  (yyval.ttype) = build_external_ref ((yyvsp[(1) - (1)].ttype), yychar == '(');
		;}
    break;

  case 90:
#line 585 "c-parse.y"
    { (yyval.ttype) = combine_strings ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 91:
#line 587 "c-parse.y"
    { char class = TREE_CODE_CLASS (TREE_CODE ((yyvsp[(2) - (3)].ttype)));
		  if (class == 'e' || class == '1'
		      || class == '2' || class == '<')
		    C_SET_EXP_ORIGINAL_CODE ((yyvsp[(2) - (3)].ttype), ERROR_MARK);
		  (yyval.ttype) = (yyvsp[(2) - (3)].ttype); ;}
    break;

  case 92:
#line 593 "c-parse.y"
    { (yyval.ttype) = error_mark_node; ;}
    break;

  case 93:
#line 595 "c-parse.y"
    { tree rtl_exp;
		  if (pedantic)
		    pedwarn ("ANSI C forbids braced-groups within expressions");
		  pop_iterator_stack ();
		  pop_label_level ();
		  rtl_exp = expand_end_stmt_expr ((yyvsp[(1) - (3)].ttype));
		  /* The statements have side effects, so the group does.  */
		  TREE_SIDE_EFFECTS (rtl_exp) = 1;

		  if (TREE_CODE ((yyvsp[(2) - (3)].ttype)) == BLOCK)
		    {
		      /* Make a BIND_EXPR for the BLOCK already made.  */
		      (yyval.ttype) = build (BIND_EXPR, TREE_TYPE (rtl_exp),
				  NULL_TREE, rtl_exp, (yyvsp[(2) - (3)].ttype));
		      /* Remove the block from the tree at this point.
			 It gets put back at the proper place
			 when the BIND_EXPR is expanded.  */
		      delete_block ((yyvsp[(2) - (3)].ttype));
		    }
		  else
		    (yyval.ttype) = (yyvsp[(2) - (3)].ttype);
		;}
    break;

  case 94:
#line 618 "c-parse.y"
    {
		  /* Make sure we call expand_end_stmt_expr.  Otherwise
		     we are likely to lose sequences and crash later.  */
		  pop_iterator_stack ();
		  pop_label_level ();
		  expand_end_stmt_expr ((yyvsp[(1) - (3)].ttype));
		  (yyval.ttype) = error_mark_node;
		;}
    break;

  case 95:
#line 627 "c-parse.y"
    { (yyval.ttype) = build_function_call ((yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 96:
#line 629 "c-parse.y"
    { (yyval.ttype) = build_array_ref ((yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 97:
#line 631 "c-parse.y"
    {
		    (yyval.ttype) = build_component_ref ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype));
		;}
    break;

  case 98:
#line 635 "c-parse.y"
    {
                  tree expr = build_indirect_ref ((yyvsp[(1) - (3)].ttype), "->");

                    (yyval.ttype) = build_component_ref (expr, (yyvsp[(3) - (3)].ttype));
		;}
    break;

  case 99:
#line 641 "c-parse.y"
    { (yyval.ttype) = build_unary_op (POSTINCREMENT_EXPR, (yyvsp[(1) - (2)].ttype), 0); ;}
    break;

  case 100:
#line 643 "c-parse.y"
    { (yyval.ttype) = build_unary_op (POSTDECREMENT_EXPR, (yyvsp[(1) - (2)].ttype), 0); ;}
    break;

  case 102:
#line 650 "c-parse.y"
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
#line 671 "c-parse.y"
    { c_mark_varargs ();
		  if (pedantic)
		    pedwarn ("ANSI C does not permit use of `varargs.h'"); ;}
    break;

  case 106:
#line 681 "c-parse.y"
    { ;}
    break;

  case 111:
#line 697 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 112:
#line 701 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);	
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 113:
#line 705 "c-parse.y"
    { shadow_tag_warned ((yyvsp[(1) - (2)].ttype), 1);
		  pedwarn ("empty declaration"); ;}
    break;

  case 114:
#line 708 "c-parse.y"
    { pedwarn ("empty declaration"); ;}
    break;

  case 115:
#line 717 "c-parse.y"
    { ;}
    break;

  case 120:
#line 732 "c-parse.y"
    { pending_xref_error ();
		  declspec_stack = tree_cons (prefix_attributes,
					      current_declspecs,
					      declspec_stack);
		  split_specs_attrs ((yyvsp[(0) - (0)].ttype),
				     &current_declspecs, &prefix_attributes); ;}
    break;

  case 121:
#line 742 "c-parse.y"
    { prefix_attributes = chainon (prefix_attributes, (yyvsp[(0) - (0)].ttype)); ;}
    break;

  case 122:
#line 747 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 123:
#line 751 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 124:
#line 755 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 125:
#line 759 "c-parse.y"
    { current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 126:
#line 763 "c-parse.y"
    { shadow_tag ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 127:
#line 765 "c-parse.y"
    { pedwarn ("empty declaration"); ;}
    break;

  case 128:
#line 767 "c-parse.y"
    { RESTORE_WARN_FLAGS ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 129:
#line 777 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 130:
#line 779 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(3) - (3)].ttype), tree_cons (NULL_TREE, (yyvsp[(2) - (3)].ttype), (yyvsp[(1) - (3)].ttype))); ;}
    break;

  case 131:
#line 783 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 132:
#line 785 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 133:
#line 787 "c-parse.y"
    { if (extra_warnings)
		    warning ("`%s' is not at beginning of declaration",
			     IDENTIFIER_POINTER ((yyvsp[(2) - (2)].ttype)));
		  (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 134:
#line 792 "c-parse.y"
    { (yyval.ttype) = tree_cons ((yyvsp[(2) - (2)].ttype), NULL_TREE, (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 135:
#line 797 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 136:
#line 799 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(3) - (3)].ttype), tree_cons (NULL_TREE, (yyvsp[(2) - (3)].ttype), (yyvsp[(1) - (3)].ttype))); ;}
    break;

  case 137:
#line 804 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 138:
#line 806 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 139:
#line 808 "c-parse.y"
    { if (extra_warnings)
		    warning ("`%s' is not at beginning of declaration",
			     IDENTIFIER_POINTER ((yyvsp[(2) - (2)].ttype)));
		  (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 140:
#line 821 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 141:
#line 823 "c-parse.y"
    { (yyval.ttype) = tree_cons ((yyvsp[(1) - (1)].ttype), NULL_TREE, NULL_TREE); ;}
    break;

  case 142:
#line 825 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 143:
#line 827 "c-parse.y"
    { (yyval.ttype) = tree_cons ((yyvsp[(2) - (2)].ttype), NULL_TREE, (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 144:
#line 832 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (1)].ttype), NULL_TREE);
		  TREE_STATIC ((yyval.ttype)) = 1; ;}
    break;

  case 145:
#line 835 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (1)].ttype), NULL_TREE); ;}
    break;

  case 146:
#line 837 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype));
		  TREE_STATIC ((yyval.ttype)) = 1; ;}
    break;

  case 147:
#line 840 "c-parse.y"
    { if (extra_warnings && TREE_STATIC ((yyvsp[(1) - (2)].ttype)))
		    warning ("`%s' is not at beginning of declaration",
			     IDENTIFIER_POINTER ((yyvsp[(2) - (2)].ttype)));
		  (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype));
		  TREE_STATIC ((yyval.ttype)) = TREE_STATIC ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 148:
#line 854 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 149:
#line 856 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(3) - (3)].ttype), tree_cons (NULL_TREE, (yyvsp[(2) - (3)].ttype), (yyvsp[(1) - (3)].ttype))); ;}
    break;

  case 150:
#line 860 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 151:
#line 862 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 154:
#line 872 "c-parse.y"
    { /* For a typedef name, record the meaning, not the name.
		     In case of `foo foo, bar;'.  */
		  (yyval.ttype) = lookup_name ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 155:
#line 876 "c-parse.y"
    { (yyval.ttype) = TREE_TYPE ((yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 156:
#line 878 "c-parse.y"
    { (yyval.ttype) = groktypename ((yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 164:
#line 900 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 165:
#line 902 "c-parse.y"
    { if (TREE_CHAIN ((yyvsp[(3) - (4)].ttype))) (yyvsp[(3) - (4)].ttype) = combine_strings ((yyvsp[(3) - (4)].ttype));
		  (yyval.ttype) = (yyvsp[(3) - (4)].ttype);
		;}
    break;

  case 166:
#line 909 "c-parse.y"
    { (yyval.ttype) = start_decl ((yyvsp[(1) - (4)].ttype), current_declspecs, 1,
					  (yyvsp[(3) - (4)].ttype), prefix_attributes);
		  start_init ((yyval.ttype), (yyvsp[(2) - (4)].ttype), global_bindings_p ()); ;}
    break;

  case 167:
#line 914 "c-parse.y"
    { finish_init ();
		  finish_decl ((yyvsp[(5) - (6)].ttype), (yyvsp[(6) - (6)].ttype), (yyvsp[(2) - (6)].ttype)); ;}
    break;

  case 168:
#line 917 "c-parse.y"
    { tree d = start_decl ((yyvsp[(1) - (3)].ttype), current_declspecs, 0,
				       (yyvsp[(3) - (3)].ttype), prefix_attributes);
		  finish_decl (d, NULL_TREE, (yyvsp[(2) - (3)].ttype)); 
                ;}
    break;

  case 169:
#line 925 "c-parse.y"
    { (yyval.ttype) = start_decl ((yyvsp[(1) - (4)].ttype), current_declspecs, 1,
					  (yyvsp[(3) - (4)].ttype), prefix_attributes);
		  start_init ((yyval.ttype), (yyvsp[(2) - (4)].ttype), global_bindings_p ()); ;}
    break;

  case 170:
#line 930 "c-parse.y"
    { finish_init ();
		  decl_attributes ((yyvsp[(5) - (6)].ttype), (yyvsp[(3) - (6)].ttype), prefix_attributes);
		  finish_decl ((yyvsp[(5) - (6)].ttype), (yyvsp[(6) - (6)].ttype), (yyvsp[(2) - (6)].ttype)); ;}
    break;

  case 171:
#line 934 "c-parse.y"
    { tree d = start_decl ((yyvsp[(1) - (3)].ttype), current_declspecs, 0,
				       (yyvsp[(3) - (3)].ttype), prefix_attributes);
		  finish_decl (d, NULL_TREE, (yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 172:
#line 942 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 173:
#line 944 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 174:
#line 949 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 175:
#line 951 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 176:
#line 956 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(4) - (6)].ttype); ;}
    break;

  case 177:
#line 961 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 178:
#line 963 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 179:
#line 968 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 180:
#line 970 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (1)].ttype), NULL_TREE); ;}
    break;

  case 181:
#line 972 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (4)].ttype), build_tree_list (NULL_TREE, (yyvsp[(3) - (4)].ttype))); ;}
    break;

  case 182:
#line 974 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (6)].ttype), tree_cons (NULL_TREE, (yyvsp[(3) - (6)].ttype), (yyvsp[(5) - (6)].ttype))); ;}
    break;

  case 183:
#line 976 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 189:
#line 994 "c-parse.y"
    { really_start_incremental_init (NULL_TREE); ;}
    break;

  case 190:
#line 996 "c-parse.y"
    { (yyval.ttype) = pop_init_level (0); ;}
    break;

  case 191:
#line 998 "c-parse.y"
    { (yyval.ttype) = error_mark_node; ;}
    break;

  case 192:
#line 1004 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ANSI C forbids empty initializer braces"); ;}
    break;

  case 198:
#line 1020 "c-parse.y"
    { set_init_label ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 201:
#line 1027 "c-parse.y"
    { push_init_level (0); ;}
    break;

  case 202:
#line 1029 "c-parse.y"
    { process_init_element (pop_init_level (0)); ;}
    break;

  case 203:
#line 1031 "c-parse.y"
    { process_init_element ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 207:
#line 1042 "c-parse.y"
    { set_init_label ((yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 208:
#line 1047 "c-parse.y"
    { set_init_index ((yyvsp[(2) - (5)].ttype), (yyvsp[(4) - (5)].ttype)); ;}
    break;

  case 209:
#line 1049 "c-parse.y"
    { set_init_index ((yyvsp[(2) - (3)].ttype), NULL_TREE); ;}
    break;

  case 210:
#line 1054 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ANSI C forbids nested functions");

		  push_function_context ();
		  if (! start_function (current_declspecs, (yyvsp[(1) - (1)].ttype),
					prefix_attributes, NULL_TREE))
		    {
		      pop_function_context ();
		      YYERROR1;
		    }
		  reinit_parse_for_function (); ;}
    break;

  case 211:
#line 1066 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 212:
#line 1074 "c-parse.y"
    { finish_function (1);
		  pop_function_context (); ;}
    break;

  case 213:
#line 1080 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ANSI C forbids nested functions");

		  push_function_context ();
		  if (! start_function (current_declspecs, (yyvsp[(1) - (1)].ttype),
					prefix_attributes, NULL_TREE))
		    {
		      pop_function_context ();
		      YYERROR1;
		    }
		  reinit_parse_for_function (); ;}
    break;

  case 214:
#line 1092 "c-parse.y"
    { store_parm_decls (); ;}
    break;

  case 215:
#line 1100 "c-parse.y"
    { finish_function (1);
		  pop_function_context (); ;}
    break;

  case 218:
#line 1116 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (3)].ttype); ;}
    break;

  case 219:
#line 1118 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype), NULL_TREE); ;}
    break;

  case 220:
#line 1123 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 221:
#line 1125 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (3)].ttype), NULL_TREE); ;}
    break;

  case 222:
#line 1127 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 223:
#line 1134 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype); ;}
    break;

  case 225:
#line 1145 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype), NULL_TREE); ;}
    break;

  case 226:
#line 1150 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), NULL_TREE);
		  if (! flag_isoc99)
		    error ("`[*]' in parameter declaration only allowed in ISO C 99");
		;}
    break;

  case 227:
#line 1155 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 228:
#line 1157 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (3)].ttype), NULL_TREE); ;}
    break;

  case 229:
#line 1159 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 230:
#line 1166 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype); ;}
    break;

  case 232:
#line 1175 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype), NULL_TREE); ;}
    break;

  case 233:
#line 1180 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (3)].ttype); ;}
    break;

  case 234:
#line 1182 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 235:
#line 1184 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), NULL_TREE);
		  if (! flag_isoc99)
		    error ("`[*]' in parameter declaration only allowed in ISO C 99");
		;}
    break;

  case 236:
#line 1189 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 237:
#line 1191 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (3)].ttype), NULL_TREE); ;}
    break;

  case 238:
#line 1198 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype); ;}
    break;

  case 240:
#line 1204 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 241:
#line 1206 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype); ;}
    break;

  case 242:
#line 1211 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 243:
#line 1213 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype); ;}
    break;

  case 244:
#line 1218 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 245:
#line 1220 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype); ;}
    break;

  case 246:
#line 1225 "c-parse.y"
    { (yyval.ttype) = start_struct (RECORD_TYPE, (yyvsp[(2) - (3)].ttype));
		  /* Start scope of tag before parsing components.  */
		;}
    break;

  case 247:
#line 1229 "c-parse.y"
    { (yyval.ttype) = finish_struct ((yyvsp[(4) - (7)].ttype), (yyvsp[(5) - (7)].ttype), chainon ((yyvsp[(1) - (7)].ttype), (yyvsp[(7) - (7)].ttype))); ;}
    break;

  case 248:
#line 1231 "c-parse.y"
    { (yyval.ttype) = finish_struct (start_struct (RECORD_TYPE, NULL_TREE),
				      (yyvsp[(3) - (5)].ttype), chainon ((yyvsp[(1) - (5)].ttype), (yyvsp[(5) - (5)].ttype)));
		;}
    break;

  case 249:
#line 1235 "c-parse.y"
    { (yyval.ttype) = xref_tag (RECORD_TYPE, (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 250:
#line 1237 "c-parse.y"
    { (yyval.ttype) = start_struct (UNION_TYPE, (yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 251:
#line 1239 "c-parse.y"
    { (yyval.ttype) = finish_struct ((yyvsp[(4) - (7)].ttype), (yyvsp[(5) - (7)].ttype), chainon ((yyvsp[(1) - (7)].ttype), (yyvsp[(7) - (7)].ttype))); ;}
    break;

  case 252:
#line 1241 "c-parse.y"
    { (yyval.ttype) = finish_struct (start_struct (UNION_TYPE, NULL_TREE),
				      (yyvsp[(3) - (5)].ttype), chainon ((yyvsp[(1) - (5)].ttype), (yyvsp[(5) - (5)].ttype)));
		;}
    break;

  case 253:
#line 1245 "c-parse.y"
    { (yyval.ttype) = xref_tag (UNION_TYPE, (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 254:
#line 1247 "c-parse.y"
    { (yyval.ttype) = start_enum ((yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 255:
#line 1249 "c-parse.y"
    { (yyval.ttype) = finish_enum ((yyvsp[(4) - (8)].ttype), nreverse ((yyvsp[(5) - (8)].ttype)),
				    chainon ((yyvsp[(1) - (8)].ttype), (yyvsp[(8) - (8)].ttype))); ;}
    break;

  case 256:
#line 1252 "c-parse.y"
    { (yyval.ttype) = start_enum (NULL_TREE); ;}
    break;

  case 257:
#line 1254 "c-parse.y"
    { (yyval.ttype) = finish_enum ((yyvsp[(3) - (7)].ttype), nreverse ((yyvsp[(4) - (7)].ttype)),
				    chainon ((yyvsp[(1) - (7)].ttype), (yyvsp[(7) - (7)].ttype))); ;}
    break;

  case 258:
#line 1257 "c-parse.y"
    { (yyval.ttype) = xref_tag (ENUMERAL_TYPE, (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 262:
#line 1268 "c-parse.y"
    { if (pedantic && ! flag_isoc99)
		    pedwarn ("comma at end of enumerator list"); ;}
    break;

  case 263:
#line 1274 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(1) - (1)].ttype); ;}
    break;

  case 264:
#line 1276 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype));
		  pedwarn ("no semicolon at end of struct or union"); ;}
    break;

  case 265:
#line 1281 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 266:
#line 1283 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), (yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 267:
#line 1285 "c-parse.y"
    { if (pedantic)
		    pedwarn ("extra semicolon in struct or union specified"); ;}
    break;

  case 268:
#line 1300 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype);
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 269:
#line 1305 "c-parse.y"
    {
		  /* Support for unnamed structs or unions as members of 
		     structs or unions (which is [a] useful and [b] supports 
		     MS P-SDK).  */
		  if (pedantic)
		    pedwarn ("ANSI C doesn't support unnamed structs/unions");

		  (yyval.ttype) = grokfield((yyvsp[(3) - (5)].filename), (yyvsp[(4) - (5)].lineno), NULL, current_declspecs, NULL_TREE);
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack);
		;}
    break;

  case 270:
#line 1318 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype);
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 271:
#line 1323 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ANSI C forbids member declarations with no members");
		  shadow_tag((yyvsp[(1) - (1)].ttype));
		  (yyval.ttype) = NULL_TREE; ;}
    break;

  case 272:
#line 1328 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 273:
#line 1330 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype);
		  RESTORE_WARN_FLAGS ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 275:
#line 1337 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 276:
#line 1342 "c-parse.y"
    { (yyval.ttype) = grokfield ((yyvsp[(1) - (4)].filename), (yyvsp[(2) - (4)].lineno), (yyvsp[(3) - (4)].ttype), current_declspecs, NULL_TREE);
		  decl_attributes ((yyval.ttype), (yyvsp[(4) - (4)].ttype), prefix_attributes); ;}
    break;

  case 277:
#line 1346 "c-parse.y"
    { (yyval.ttype) = grokfield ((yyvsp[(1) - (6)].filename), (yyvsp[(2) - (6)].lineno), (yyvsp[(3) - (6)].ttype), current_declspecs, (yyvsp[(5) - (6)].ttype));
		  decl_attributes ((yyval.ttype), (yyvsp[(6) - (6)].ttype), prefix_attributes); ;}
    break;

  case 278:
#line 1349 "c-parse.y"
    { (yyval.ttype) = grokfield ((yyvsp[(1) - (5)].filename), (yyvsp[(2) - (5)].lineno), NULL_TREE, current_declspecs, (yyvsp[(4) - (5)].ttype));
		  decl_attributes ((yyval.ttype), (yyvsp[(5) - (5)].ttype), prefix_attributes); ;}
    break;

  case 280:
#line 1361 "c-parse.y"
    { if ((yyvsp[(1) - (3)].ttype) == error_mark_node)
		    (yyval.ttype) = (yyvsp[(1) - (3)].ttype);
		  else
		    (yyval.ttype) = chainon ((yyvsp[(3) - (3)].ttype), (yyvsp[(1) - (3)].ttype)); ;}
    break;

  case 281:
#line 1366 "c-parse.y"
    { (yyval.ttype) = error_mark_node; ;}
    break;

  case 282:
#line 1372 "c-parse.y"
    { (yyval.ttype) = build_enumerator ((yyvsp[(1) - (1)].ttype), NULL_TREE); ;}
    break;

  case 283:
#line 1374 "c-parse.y"
    { (yyval.ttype) = build_enumerator ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 284:
#line 1379 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 285:
#line 1381 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (2)].ttype), (yyvsp[(2) - (2)].ttype)); ;}
    break;

  case 286:
#line 1386 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 288:
#line 1392 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(1) - (1)].ttype), NULL_TREE); ;}
    break;

  case 289:
#line 1394 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 290:
#line 1399 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 291:
#line 1401 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[(2) - (2)].ttype), (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 292:
#line 1406 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (3)].ttype); ;}
    break;

  case 293:
#line 1409 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 294:
#line 1411 "c-parse.y"
    { (yyval.ttype) = make_pointer_declarator ((yyvsp[(2) - (2)].ttype), NULL_TREE); ;}
    break;

  case 295:
#line 1413 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype), NULL_TREE); ;}
    break;

  case 296:
#line 1415 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 297:
#line 1417 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[(1) - (3)].ttype), NULL_TREE); ;}
    break;

  case 298:
#line 1419 "c-parse.y"
    { (yyval.ttype) = build_nt (CALL_EXPR, NULL_TREE, (yyvsp[(2) - (2)].ttype), NULL_TREE); ;}
    break;

  case 299:
#line 1421 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, NULL_TREE, (yyvsp[(2) - (3)].ttype)); ;}
    break;

  case 300:
#line 1423 "c-parse.y"
    { (yyval.ttype) = build_nt (ARRAY_REF, NULL_TREE, NULL_TREE); ;}
    break;

  case 301:
#line 1427 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(3) - (3)].ttype); ;}
    break;

  case 302:
#line 1436 "c-parse.y"
    {
		  if (pedantic && (yyvsp[(1) - (1)].ends_in_label))
		    pedwarn ("ANSI C forbids label at end of compound statement");
		;}
    break;

  case 304:
#line 1445 "c-parse.y"
    { (yyval.ends_in_label) = (yyvsp[(2) - (2)].ends_in_label); ;}
    break;

  case 305:
#line 1447 "c-parse.y"
    { (yyval.ends_in_label) = 0; ;}
    break;

  case 309:
#line 1459 "c-parse.y"
    { emit_line_note (input_filename, lineno);
		  pushlevel (0);
		  clear_last_expr ();
		  expand_start_bindings (0);
		;}
    break;

  case 311:
#line 1471 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ANSI C forbids label declarations"); ;}
    break;

  case 314:
#line 1482 "c-parse.y"
    { tree link;
		  for (link = (yyvsp[(2) - (3)].ttype); link; link = TREE_CHAIN (link))
		    {
		      tree label = shadow_label (TREE_VALUE (link));
		      C_DECLARED_LABEL_FLAG (label) = 1;
		      declare_nonlocal_label (label);
		    }
		;}
    break;

  case 315:
#line 1496 "c-parse.y"
    {;}
    break;

  case 317:
#line 1500 "c-parse.y"
    { compstmt_count++; ;}
    break;

  case 318:
#line 1503 "c-parse.y"
    { (yyval.ttype) = convert (void_type_node, integer_zero_node); ;}
    break;

  case 319:
#line 1505 "c-parse.y"
    { emit_line_note (input_filename, lineno);
		  expand_end_bindings (getdecls (), 1, 0);
		  (yyval.ttype) = poplevel (1, 1, 0); ;}
    break;

  case 320:
#line 1509 "c-parse.y"
    { emit_line_note (input_filename, lineno);
		  expand_end_bindings (getdecls (), kept_level_p (), 0);
		  (yyval.ttype) = poplevel (kept_level_p (), 0, 0); ;}
    break;

  case 321:
#line 1513 "c-parse.y"
    { emit_line_note (input_filename, lineno);
		  expand_end_bindings (getdecls (), kept_level_p (), 0);
		  (yyval.ttype) = poplevel (kept_level_p (), 0, 0); ;}
    break;

  case 322:
#line 1520 "c-parse.y"
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
		  push_iterator_stack ();
		  push_label_level ();
		  (yyval.ttype) = expand_start_stmt_expr ();
		  compstmt_count++;
		;}
    break;

  case 323:
#line 1537 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype); ;}
    break;

  case 326:
#line 1551 "c-parse.y"
    { emit_line_note ((yyvsp[(-1) - (4)].filename), (yyvsp[(0) - (4)].lineno));
		  c_expand_start_cond (truthvalue_conversion ((yyvsp[(3) - (4)].ttype)), 0, 
				       compstmt_count);
		  (yyval.itype) = stmt_count;
		  if_stmt_file = (yyvsp[(-1) - (4)].filename);
		  if_stmt_line = (yyvsp[(0) - (4)].lineno);
		  position_after_white_space (); ;}
    break;

  case 327:
#line 1565 "c-parse.y"
    { stmt_count++;
		  compstmt_count++;
		  emit_line_note ((yyvsp[(-1) - (1)].filename), (yyvsp[(0) - (1)].lineno));
		  /* See comment in `while' alternative, above.  */
		  emit_nop ();
		  expand_start_loop_continue_elsewhere (1);
		  position_after_white_space (); ;}
    break;

  case 328:
#line 1573 "c-parse.y"
    { expand_loop_continue_here (); ;}
    break;

  case 329:
#line 1577 "c-parse.y"
    { (yyval.filename) = input_filename; ;}
    break;

  case 330:
#line 1581 "c-parse.y"
    { (yyval.lineno) = lineno; ;}
    break;

  case 331:
#line 1586 "c-parse.y"
    { ;}
    break;

  case 332:
#line 1591 "c-parse.y"
    { ;}
    break;

  case 333:
#line 1596 "c-parse.y"
    { (yyval.ends_in_label) = (yyvsp[(3) - (3)].ends_in_label); ;}
    break;

  case 334:
#line 1601 "c-parse.y"
    { (yyval.ends_in_label) = 0; ;}
    break;

  case 335:
#line 1603 "c-parse.y"
    { (yyval.ends_in_label) = 1; ;}
    break;

  case 336:
#line 1609 "c-parse.y"
    { stmt_count++; ;}
    break;

  case 338:
#line 1612 "c-parse.y"
    { stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (2)].filename), (yyvsp[(0) - (2)].lineno));
/* It appears that this should not be done--that a non-lvalue array
   shouldn't get an error if the value isn't used.
   Section 3.2.2.1 says that an array lvalue gets converted to a pointer
   if it appears as a top-level expression,
   but says nothing about non-lvalue arrays.  */
#if 0
		  /* Call default_conversion to get an error
		     on referring to a register array if pedantic.  */
		  if (TREE_CODE (TREE_TYPE ((yyvsp[(1) - (2)].ttype))) == ARRAY_TYPE
		      || TREE_CODE (TREE_TYPE ((yyvsp[(1) - (2)].ttype))) == FUNCTION_TYPE)
		    (yyvsp[(1) - (2)].ttype) = default_conversion ((yyvsp[(1) - (2)].ttype));
#endif
		  iterator_expand ((yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 339:
#line 1628 "c-parse.y"
    { c_expand_start_else ();
		  (yyvsp[(1) - (2)].itype) = stmt_count;
		  position_after_white_space (); ;}
    break;

  case 340:
#line 1632 "c-parse.y"
    { c_expand_end_cond ();
		  if (extra_warnings && stmt_count == (yyvsp[(1) - (4)].itype))
		    warning ("empty body in an else-statement"); ;}
    break;

  case 341:
#line 1636 "c-parse.y"
    { c_expand_end_cond ();
		  /* This warning is here instead of in simple_if, because we
		     do not want a warning if an empty if is followed by an
		     else statement.  Increment stmt_count so we don't
		     give a second error if this is a nested `if'.  */
		  if (extra_warnings && stmt_count++ == (yyvsp[(1) - (1)].itype))
		    warning_with_file_and_line (if_stmt_file, if_stmt_line,
						"empty body in an if-statement"); ;}
    break;

  case 342:
#line 1648 "c-parse.y"
    { c_expand_end_cond (); ;}
    break;

  case 343:
#line 1650 "c-parse.y"
    { stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (1)].filename), (yyvsp[(0) - (1)].lineno));
		  /* The emit_nop used to come before emit_line_note,
		     but that made the nop seem like part of the preceding line.
		     And that was confusing when the preceding line was
		     inside of an if statement and was not really executed.
		     I think it ought to work to put the nop after the line number.
		     We will see.  --rms, July 15, 1991.  */
		  emit_nop (); ;}
    break;

  case 344:
#line 1660 "c-parse.y"
    { /* Don't start the loop till we have succeeded
		     in parsing the end test.  This is to make sure
		     that we end every loop we start.  */
		  expand_start_loop (1);
		  emit_line_note (input_filename, lineno);
		  expand_exit_loop_if_false (NULL_PTR,
					     truthvalue_conversion ((yyvsp[(4) - (5)].ttype)));
		  position_after_white_space (); ;}
    break;

  case 345:
#line 1669 "c-parse.y"
    { expand_end_loop (); ;}
    break;

  case 346:
#line 1672 "c-parse.y"
    { emit_line_note (input_filename, lineno);
		  expand_exit_loop_if_false (NULL_PTR,
					     truthvalue_conversion ((yyvsp[(3) - (5)].ttype)));
		  expand_end_loop (); ;}
    break;

  case 347:
#line 1678 "c-parse.y"
    { expand_end_loop (); ;}
    break;

  case 348:
#line 1681 "c-parse.y"
    { stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (4)].filename), (yyvsp[(0) - (4)].lineno));
		  /* See comment in `while' alternative, above.  */
		  emit_nop ();
		  if ((yyvsp[(3) - (4)].ttype)) c_expand_expr_stmt ((yyvsp[(3) - (4)].ttype));
		  /* Next step is to call expand_start_loop_continue_elsewhere,
		     but wait till after we parse the entire for (...).
		     Otherwise, invalid input might cause us to call that
		     fn without calling expand_end_loop.  */
		;}
    break;

  case 349:
#line 1693 "c-parse.y"
    { (yyvsp[(7) - (7)].lineno) = lineno;
		  (yyval.filename) = input_filename; ;}
    break;

  case 350:
#line 1696 "c-parse.y"
    { 
		  /* Start the loop.  Doing this after parsing
		     all the expressions ensures we will end the loop.  */
		  expand_start_loop_continue_elsewhere (1);
		  /* Emit the end-test, with a line number.  */
		  emit_line_note ((yyvsp[(8) - (10)].filename), (yyvsp[(7) - (10)].lineno));
		  if ((yyvsp[(6) - (10)].ttype))
		    expand_exit_loop_if_false (NULL_PTR,
					       truthvalue_conversion ((yyvsp[(6) - (10)].ttype)));
		  (yyvsp[(7) - (10)].lineno) = lineno;
		  (yyvsp[(8) - (10)].filename) = input_filename;
		  position_after_white_space (); ;}
    break;

  case 351:
#line 1709 "c-parse.y"
    { /* Emit the increment expression, with a line number.  */
		  emit_line_note ((yyvsp[(8) - (12)].filename), (yyvsp[(7) - (12)].lineno));
		  expand_loop_continue_here ();
		  if ((yyvsp[(9) - (12)].ttype))
		    c_expand_expr_stmt ((yyvsp[(9) - (12)].ttype));
		  expand_end_loop (); ;}
    break;

  case 352:
#line 1716 "c-parse.y"
    { stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (4)].filename), (yyvsp[(0) - (4)].lineno));
		  c_expand_start_case ((yyvsp[(3) - (4)].ttype));
		  position_after_white_space (); ;}
    break;

  case 353:
#line 1721 "c-parse.y"
    { expand_end_case ((yyvsp[(3) - (6)].ttype)); ;}
    break;

  case 354:
#line 1723 "c-parse.y"
    { build_break_stmt ();
		  stmt_count++;
		  genrtl_break_stmt (); ;}
    break;

  case 355:
#line 1727 "c-parse.y"
    { build_continue_stmt ();
                  stmt_count++;
		  genrtl_continue_stmt (); ;}
    break;

  case 356:
#line 1731 "c-parse.y"
    { tree return_stmt = build_return_stmt (NULL_TREE);
                  stmt_count++;
		  genrtl_return_stmt (RETURN_EXPR(return_stmt)); ;}
    break;

  case 357:
#line 1735 "c-parse.y"
    { tree return_stmt = build_return_stmt ((yyvsp[(2) - (3)].ttype));
                  stmt_count++;
		  genrtl_return_stmt (RETURN_EXPR(return_stmt)); ;}
    break;

  case 358:
#line 1739 "c-parse.y"
    { stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (6)].filename), (yyvsp[(0) - (6)].lineno));
		  STRIP_NOPS ((yyvsp[(4) - (6)].ttype));
		  if ((TREE_CODE ((yyvsp[(4) - (6)].ttype)) == ADDR_EXPR
		       && TREE_CODE (TREE_OPERAND ((yyvsp[(4) - (6)].ttype), 0)) == STRING_CST)
		      || TREE_CODE ((yyvsp[(4) - (6)].ttype)) == STRING_CST)
		    expand_asm ((yyvsp[(4) - (6)].ttype));
		  else
		    error ("argument of `asm' is not a constant string"); ;}
    break;

  case 359:
#line 1750 "c-parse.y"
    { stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (8)].filename), (yyvsp[(0) - (8)].lineno));
		  c_expand_asm_operands ((yyvsp[(4) - (8)].ttype), (yyvsp[(6) - (8)].ttype), NULL_TREE, NULL_TREE,
					 (yyvsp[(2) - (8)].ttype) == ridpointers[(int)RID_VOLATILE],
					 input_filename, lineno); ;}
    break;

  case 360:
#line 1757 "c-parse.y"
    { stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (10)].filename), (yyvsp[(0) - (10)].lineno));
		  c_expand_asm_operands ((yyvsp[(4) - (10)].ttype), (yyvsp[(6) - (10)].ttype), (yyvsp[(8) - (10)].ttype), NULL_TREE,
					 (yyvsp[(2) - (10)].ttype) == ridpointers[(int)RID_VOLATILE],
					 input_filename, lineno); ;}
    break;

  case 361:
#line 1765 "c-parse.y"
    { stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (12)].filename), (yyvsp[(0) - (12)].lineno));
		  c_expand_asm_operands ((yyvsp[(4) - (12)].ttype), (yyvsp[(6) - (12)].ttype), (yyvsp[(8) - (12)].ttype), (yyvsp[(10) - (12)].ttype),
					 (yyvsp[(2) - (12)].ttype) == ridpointers[(int)RID_VOLATILE],
					 input_filename, lineno); ;}
    break;

  case 362:
#line 1771 "c-parse.y"
    { tree decl;
		  stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (3)].filename), (yyvsp[(0) - (3)].lineno));
		  decl = lookup_label ((yyvsp[(2) - (3)].ttype));
		  if (decl != 0)
		    {
		      TREE_USED (decl) = 1;
		      expand_goto (decl);
		    }
		;}
    break;

  case 363:
#line 1782 "c-parse.y"
    { if (pedantic)
		    pedwarn ("ANSI C forbids `goto *expr;'");
		  stmt_count++;
		  emit_line_note ((yyvsp[(-1) - (4)].filename), (yyvsp[(0) - (4)].lineno));
		  expand_computed_goto (convert (ptr_type_node, (yyvsp[(3) - (4)].ttype))); ;}
    break;

  case 366:
#line 1797 "c-parse.y"
    {
	    /* The value returned by this action is  */
	    /*      1 if everything is OK */ 
	    /*      0 in case of error or already bound iterator */

	    (yyval.itype) = 0;
	    if (TREE_CODE ((yyvsp[(3) - (4)].ttype)) != VAR_DECL)
	      error ("invalid `for (ITERATOR)' syntax");
	    else if (! ITERATOR_P ((yyvsp[(3) - (4)].ttype)))
	      error ("`%s' is not an iterator",
		     IDENTIFIER_POINTER (DECL_NAME ((yyvsp[(3) - (4)].ttype))));
	    else if (ITERATOR_BOUND_P ((yyvsp[(3) - (4)].ttype)))
	      error ("`for (%s)' inside expansion of same iterator",
		     IDENTIFIER_POINTER (DECL_NAME ((yyvsp[(3) - (4)].ttype))));
	    else
	      {
		(yyval.itype) = 1;
		iterator_for_loop_start ((yyvsp[(3) - (4)].ttype));
	      }
	  ;}
    break;

  case 367:
#line 1818 "c-parse.y"
    {
	    if ((yyvsp[(5) - (6)].itype))
	      iterator_for_loop_end ((yyvsp[(3) - (6)].ttype));
	  ;}
    break;

  case 368:
#line 1849 "c-parse.y"
    { tree case_label_tree = build_case_label ((yyvsp[(2) - (3)].ttype), NULL_TREE);
		  stmt_count++;
		  genrtl_case_label(CASE_LOW(case_label_tree), CASE_HIGH(case_label_tree));
		  position_after_white_space ();
		;}
    break;

  case 369:
#line 1855 "c-parse.y"
    { tree case_label_tree = build_case_label ((yyvsp[(2) - (5)].ttype), (yyvsp[(4) - (5)].ttype));
		  stmt_count++;
		  genrtl_case_label(CASE_LOW(case_label_tree), CASE_HIGH(case_label_tree));
		  position_after_white_space ();
		;}
    break;

  case 370:
#line 1861 "c-parse.y"
    { tree case_label_tree = build_case_label (NULL_TREE, NULL_TREE);
		  stmt_count++;
		  genrtl_case_label(CASE_LOW(case_label_tree), CASE_HIGH(case_label_tree));
		  position_after_white_space ();
		;}
    break;

  case 371:
#line 1867 "c-parse.y"
    { tree label = define_label (input_filename, lineno, (yyvsp[(1) - (3)].ttype));
		  stmt_count++;
		  emit_nop ();
		  if (label)
		    {
		      expand_label (label);
		      decl_attributes (label, (yyvsp[(3) - (3)].ttype), NULL_TREE);
		    }
		  position_after_white_space (); ;}
    break;

  case 372:
#line 1882 "c-parse.y"
    { emit_line_note (input_filename, lineno);
		  (yyval.ttype) = NULL_TREE; ;}
    break;

  case 373:
#line 1885 "c-parse.y"
    { emit_line_note (input_filename, lineno); ;}
    break;

  case 374:
#line 1890 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 376:
#line 1897 "c-parse.y"
    { (yyval.ttype) = NULL_TREE; ;}
    break;

  case 379:
#line 1904 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), (yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 380:
#line 1909 "c-parse.y"
    { (yyval.ttype) = build_tree_list ((yyvsp[(1) - (4)].ttype), (yyvsp[(3) - (4)].ttype)); ;}
    break;

  case 381:
#line 1914 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, combine_strings ((yyvsp[(1) - (1)].ttype)), NULL_TREE); ;}
    break;

  case 382:
#line 1916 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, combine_strings ((yyvsp[(3) - (3)].ttype)), (yyvsp[(1) - (3)].ttype)); ;}
    break;

  case 383:
#line 1922 "c-parse.y"
    { pushlevel (0);
		  clear_parm_order ();
		  declare_parm_level (0); ;}
    break;

  case 384:
#line 1926 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype);
		  parmlist_tags_warning ();
		  poplevel (0, 0, 0); ;}
    break;

  case 386:
#line 1934 "c-parse.y"
    { tree parm;
		  if (pedantic)
		    pedwarn ("ANSI C forbids forward parameter declarations");
		  /* Mark the forward decls as such.  */
		  for (parm = getdecls (); parm; parm = TREE_CHAIN (parm))
		    TREE_ASM_WRITTEN (parm) = 1;
		  clear_parm_order (); ;}
    break;

  case 387:
#line 1942 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(4) - (4)].ttype); ;}
    break;

  case 388:
#line 1944 "c-parse.y"
    { (yyval.ttype) = tree_cons (NULL_TREE, NULL_TREE, NULL_TREE); ;}
    break;

  case 389:
#line 1950 "c-parse.y"
    { (yyval.ttype) = get_parm_info (0); ;}
    break;

  case 390:
#line 1952 "c-parse.y"
    { (yyval.ttype) = get_parm_info (0);
		  /* Gcc used to allow this as an extension.  However, it does
		     not work for all targets, and thus has been disabled.
		     Also, since func (...) and func () are indistinguishable,
		     it caused problems with the code in expand_builtin which
		     tries to verify that BUILT_IN_NEXT_ARG is being used
		     correctly.  */
		  error ("ANSI C requires a named argument before `...'");
		;}
    break;

  case 391:
#line 1962 "c-parse.y"
    { (yyval.ttype) = get_parm_info (1); ;}
    break;

  case 392:
#line 1964 "c-parse.y"
    { (yyval.ttype) = get_parm_info (0); ;}
    break;

  case 393:
#line 1969 "c-parse.y"
    { push_parm_decl ((yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 394:
#line 1971 "c-parse.y"
    { push_parm_decl ((yyvsp[(3) - (3)].ttype)); ;}
    break;

  case 395:
#line 1978 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype)));
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 396:
#line 1986 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype))); 
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 397:
#line 1994 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype)));
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 398:
#line 2002 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype)));
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 399:
#line 2011 "c-parse.y"
    { (yyval.ttype) = build_tree_list (build_tree_list (current_declspecs,
							 (yyvsp[(3) - (4)].ttype)),
					build_tree_list (prefix_attributes,
							 (yyvsp[(4) - (4)].ttype)));
		  current_declspecs = TREE_VALUE (declspec_stack);
		  prefix_attributes = TREE_PURPOSE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack); ;}
    break;

  case 400:
#line 2024 "c-parse.y"
    { pushlevel (0);
		  clear_parm_order ();
		  declare_parm_level (1); ;}
    break;

  case 401:
#line 2028 "c-parse.y"
    { (yyval.ttype) = (yyvsp[(2) - (2)].ttype);
		  parmlist_tags_warning ();
		  poplevel (0, 0, 0); ;}
    break;

  case 403:
#line 2036 "c-parse.y"
    { tree t;
		  for (t = (yyvsp[(1) - (2)].ttype); t; t = TREE_CHAIN (t))
		    if (TREE_VALUE (t) == NULL_TREE)
		      error ("`...' in old-style identifier list");
		  (yyval.ttype) = tree_cons (NULL_TREE, NULL_TREE, (yyvsp[(1) - (2)].ttype)); ;}
    break;

  case 404:
#line 2046 "c-parse.y"
    { (yyval.ttype) = build_tree_list (NULL_TREE, (yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 405:
#line 2048 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), build_tree_list (NULL_TREE, (yyvsp[(3) - (3)].ttype))); ;}
    break;

  case 406:
#line 2054 "c-parse.y"
    { (yyval.ttype) = build_tree_list (NULL_TREE, (yyvsp[(1) - (1)].ttype)); ;}
    break;

  case 407:
#line 2056 "c-parse.y"
    { (yyval.ttype) = chainon ((yyvsp[(1) - (3)].ttype), build_tree_list (NULL_TREE, (yyvsp[(3) - (3)].ttype))); ;}
    break;

  case 408:
#line 2061 "c-parse.y"
    { (yyval.ttype) = SAVE_WARN_FLAGS();
		  pedantic = 0;
		  warn_pointer_arith = 0; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 4794 "c-parse.c"
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


#line 2066 "c-parse.y"


