/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 65 "c-parse.y"
{long itype; tree ttype; enum tree_code code;
	const char *filename; int lineno; int ends_in_label; }
/* Line 1529 of yacc.c.  */
#line 184 "c-parse.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

