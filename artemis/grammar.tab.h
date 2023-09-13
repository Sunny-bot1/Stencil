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

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
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
    ID = 258,
    DATATYPE = 259,
    TRUE = 260,
    FALSE = 261,
    T_INT = 262,
    T_FLOAT = 263,
    T_DOUBLE = 264,
    PARAMETER = 265,
    FUNCTION = 266,
    STENCIL = 267,
    COEFFICIENT = 268,
    ITERATOR = 269,
    LEQ = 270,
    GEQ = 271,
    EQ = 272,
    NEQ = 273,
    PLUSEQ = 274,
    MINUSEQ = 275,
    MULTEQ = 276,
    DIVEQ = 277,
    ANDEQ = 278,
    OREQ = 279,
    COLON = 280,
    DDOTS = 281,
    COMMENT = 282,
    ALLOCIN = 283,
    COPYIN = 284,
    CONSTANT = 285,
    COPYOUT = 286,
    SHMEM = 287,
    NOSHMEM = 288,
    GMEM = 289,
    ITERATE = 290,
    INOUT = 291,
    UMINUS = 292,
    UPLUS = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "grammar.y"

	int ival;
	double dval;
	float fval;
	bool bval;
	char *str;
	class startNode *startnode;
	class funcDefn *funcdefn;
	class stencilDefn *stencildefn;
	class stencilCall *stencilcall;
	class stmtList *stmtlist;
	class exprNode *exprnode;
	class shiftvecNode *shiftvecnode;
	class argList *arglist;
	class Range *iterrange;
	class arrayDecl *arraydecl;
	std::vector<std::string> *stringlist;
	std::vector<exprNode*> *exprlist;
	std::vector<arrayDecl*> *arraylist;
	std::vector<Range*> *rangelist;

#line 118 "grammar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
