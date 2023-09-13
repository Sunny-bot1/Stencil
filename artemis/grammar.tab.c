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
#line 1 "grammar.y"

	#include <cstdio>
	#include <string>
	#include <vector>
	#include "grammar.hpp"

	extern FILE *yyin;
	extern int yylineno;
	int yylex (void);
	int yyparse (void);
	void yyerror(const char *str) {
		fprintf(stderr,"error: %s at line %d\n", str, yylineno);
	}
	void grammar::set_input (FILE *in) {
	    yyin = in;
	}
	void grammar::parse () {
	    do {
	        yyparse ();
	    } while (!feof (yyin));
	}

#line 93 "grammar.tab.c"

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

#line 206 "grammar.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   954

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  390

#define YYUNDEFTOK  2
#define YYMAXUTOK   293


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
       2,     2,     2,     2,     2,     2,     2,    45,    38,     2,
      49,    50,    43,    41,    55,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
      39,    54,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    56,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    37,    52,     2,     2,     2,     2,
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
      35,    36,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    94,    97,    98,   101,   101,   105,   106,
     109,   111,   116,   117,   121,   122,   126,   127,   130,   131,
     134,   135,   138,   141,   142,   145,   148,   149,   152,   155,
     156,   159,   160,   161,   164,   165,   166,   167,   170,   172,
     174,   176,   178,   180,   182,   185,   188,   191,   197,   198,
     203,   206,   209,   212,   215,   218,   221,   224,   227,   230,
     233,   236,   239,   242,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   265,
     266,   267,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   295,   298,   300,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     328,   330,   332,   338,   342,   343,   344,   345,   346,   347,
     348,   351,   353,   355,   361,   362,   365,   366,   370,   371,
     374,   375,   378,   380,   385,   388,   390,   394,   399,   401,
     407,   408,   409,   409,   412,   414,   418,   419,   420,   421,
     422,   423
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "DATATYPE", "TRUE", "FALSE",
  "T_INT", "T_FLOAT", "T_DOUBLE", "PARAMETER", "FUNCTION", "STENCIL",
  "COEFFICIENT", "ITERATOR", "LEQ", "GEQ", "EQ", "NEQ", "PLUSEQ",
  "MINUSEQ", "MULTEQ", "DIVEQ", "ANDEQ", "OREQ", "COLON", "DDOTS",
  "COMMENT", "ALLOCIN", "COPYIN", "CONSTANT", "COPYOUT", "SHMEM",
  "NOSHMEM", "GMEM", "ITERATE", "INOUT", "'|'", "'&'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "UMINUS", "UPLUS", "'^'", "'('", "')'",
  "'{'", "'}'", "';'", "'='", "','", "']'", "'['", "$accept", "start",
  "$@1", "program", "functiondefn", "$@2", "stencildefs", "stencildef",
  "paramlist", "iterlist", "declist", "decl", "shmemlist", "shmemdecl",
  "noshmemlist", "noshmemdecl", "gmemlist", "gmemdecl", "tempdeclist",
  "tempdecl", "range", "rangelist", "coeflist", "pointstmts", "lhs", "rhs",
  "rhslist", "scalar_rhs", "scalar_rhslist", "offsetvar", "arrayaccess",
  "offsetlist", "allocinlist", "copyinlist", "constantlist", "copyoutlist",
  "arraylist", "arglist", "idlist", "stencilcalls", "$@3", "stencilcall",
  "stencilloop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   124,    38,    60,
      62,    43,    45,    42,    47,    37,   292,   293,    94,    40,
      41,   123,   125,    59,    61,    44,    93,    91
};
# endif

#define YYPACT_NINF (-220)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -220,    35,  -220,  -220,    72,  -220,    79,  -220,    99,   125,
    -220,    -6,    99,  -220,  -220,   143,    90,    73,  -220,  -220,
     161,    99,  -220,   164,   119,   177,   186,   735,    99,   182,
      39,  -220,   219,  -220,  -220,   775,    99,   220,   128,  -220,
      96,    91,   147,   185,  -220,   854,    99,   232,   244,   255,
     209,    96,    96,    96,   356,    39,  -220,   867,   411,   427,
      27,  -220,  -220,  -220,  -220,  -220,  -220,   252,    96,   239,
    -220,   382,   398,   399,    16,    39,  -220,    21,  -220,  -220,
      96,    96,   286,   356,     4,     4,    99,    96,    96,   439,
     273,    99,  -220,  -220,   414,  -220,  -220,    96,    96,  -220,
     456,   -21,    69,   122,   -17,    34,    96,    75,   868,    29,
    -220,  -220,   479,   447,    82,   448,   462,    96,  -220,    96,
    -220,  -220,   513,  -220,    22,  -220,  -220,  -220,   507,  -220,
    -220,   483,   493,   501,  -220,   562,   564,   562,  -220,  -220,
      99,   580,   552,  -220,  -220,   552,   195,   -48,   881,   884,
      99,  -220,   567,   567,   548,   189,  -220,  -220,   885,    99,
    -220,   583,   583,  -220,   569,  -220,  -220,  -220,  -220,  -220,
     189,   189,   231,  -220,   896,    99,  -220,    14,    18,   189,
     586,   724,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,  -220,  -220,   899,   578,
      55,    65,  -220,    39,   114,  -220,  -220,   803,   720,  -220,
     769,   769,   213,   213,   837,   871,   769,   769,   156,   156,
     586,   586,   586,  -220,  -220,    80,    39,   773,   601,   290,
     218,   218,   218,   218,   218,   218,   218,  -220,   189,  -220,
    -220,    80,    84,   307,   324,   218,   218,   218,   218,   218,
     218,   218,  -220,   116,    66,  -220,  -220,  -220,  -220,  -220,
     218,   218,   248,  -220,   265,   282,   299,   316,   333,   350,
     803,  -220,    80,    80,    80,    80,    80,   595,   117,   367,
     384,   401,   418,   435,   452,   469,    65,   218,   620,   741,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,  -220,  -220,  -220,  -220,  -220,  -220,
    -220,   353,   353,  -220,  -220,    84,    80,    65,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,   779,   819,   721,  -220,   781,
     781,   902,   902,   853,   887,   781,   781,   192,   192,   620,
     620,   620,  -220,    84,   785,   218,   218,   218,   218,   218,
     218,   218,  -220,   218,   218,   218,   218,   218,   218,   218,
     218,   486,   503,   520,   537,   554,   571,   588,   819,   605,
     622,   639,   656,   673,   690,   707,  -220,  -220,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     6,     5,    13,     4,     0,    15,
     159,     0,     0,    17,    12,     0,     0,   145,   158,    14,
       0,     0,    16,   147,   159,     0,     0,     0,     0,   149,
       0,    19,     0,    18,   144,     0,     0,    49,    36,    37,
       0,    45,     0,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,     0,   148,     0,     0,     0,
       0,     9,    34,    35,    44,    46,    47,    38,     0,     0,
      48,     0,     0,     0,     0,     0,     8,   151,   161,   162,
       0,     0,    39,   152,     0,     0,     0,     0,     0,   166,
       0,     0,     7,   160,     0,    40,    42,     0,     0,   157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    43,     0,     0,     0,     0,     0,     0,   167,     0,
     168,   169,     0,   150,     0,   156,    30,   155,     0,    30,
     164,     0,     0,     0,   163,    21,     0,    21,   170,   171,
       0,     0,    24,    29,   154,    24,     0,   159,     0,     0,
       0,    20,    27,    27,     0,     0,    32,    31,     0,     0,
      23,    78,    78,   165,   108,   109,   110,   111,   113,   112,
       0,     0,     0,    22,     0,     0,    26,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    25,     0,    79,
       0,     0,    11,     0,     0,    80,    10,   132,     0,   129,
     119,   121,   116,   117,   114,   115,   118,   120,   122,   123,
     124,   125,   126,   128,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,     0,   134,
     135,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,    82,    84,    85,    86,    88,    87,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
     131,   140,     0,     0,     0,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      50,   136,   137,   138,   139,   141,     0,     0,    65,    66,
      67,    68,    69,    70,    64,     0,   107,     0,   104,    94,
      96,    91,    92,    89,    90,    93,    95,    97,    98,    99,
     100,   101,   103,   142,     0,     0,     0,     0,     0,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    57,    72,    73,    74,    75,    76,    77,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -220,  -220,  -220,  -220,   665,  -220,  -220,   625,  -220,  -220,
    -220,  -220,   549,  -220,   557,  -220,   550,  -220,   590,  -220,
     -37,   -55,  -220,   558,  -188,  -140,  -220,    -4,  -220,  -173,
    -219,  -220,  -220,  -220,  -220,  -220,   596,   651,   -10,   644,
    -220,   -76,  -220
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     5,     6,    60,    61,     9,    13,
      17,    22,   142,   151,   152,   160,   161,   176,   135,   143,
      41,    42,    47,   177,   204,   262,   327,   172,   208,   263,
     242,   243,    23,    29,    37,    92,    25,   101,    11,    77,
      94,    78,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    93,    16,    50,   205,   205,   155,    99,   117,    30,
      26,    27,   227,   228,    65,    66,    67,   199,    35,    38,
      90,   199,   271,    39,    73,    73,    45,   205,   205,   113,
      73,    82,    73,   118,   114,     3,    57,    89,    58,    59,
     100,   200,    38,    95,    96,   200,    39,    14,    93,    15,
     104,   105,    91,   311,   312,   313,   314,   315,   199,   119,
     110,   111,    74,   201,    74,    87,   202,   201,   199,   121,
     206,   203,    -3,    88,   134,   203,   103,    20,    75,    75,
     131,   108,   132,   239,    75,   127,    75,   240,    40,     8,
     120,   264,   265,   266,   267,   268,   269,   343,   325,    38,
     122,    21,    10,    39,   201,   279,   280,   281,   282,   283,
     284,   285,   226,   205,   201,   287,    51,    52,   128,   115,
     288,   289,   241,   225,   114,   272,   273,   274,   275,   344,
     146,   149,    68,   230,   231,   232,   233,   234,   235,    12,
     158,   286,   317,    19,   205,    15,    18,   326,   229,   174,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,    24,   198,   180,   181,   236,    48,
      49,   244,   116,    68,    68,   207,    30,    15,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   164,    28,   165,   166,   167,   168,   169,   192,
     193,   194,    53,    54,   195,   361,   362,   363,   364,   365,
     366,   367,    36,   368,   369,   370,   371,   372,   373,   374,
     375,   254,    43,   255,   256,   257,   258,   259,   182,   183,
      31,   170,    32,    46,   270,   300,   301,   302,   171,    33,
     303,    15,    55,    58,    59,   154,   182,   183,   184,   185,
      15,    62,   188,   189,   190,   191,   192,   193,   194,    64,
     260,   195,    63,   290,   291,   292,   293,   261,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    80,    81,   195,
     290,   291,   292,   293,   196,   294,   295,   296,   297,   298,
     299,   300,   301,   302,    53,    83,   303,   290,   291,   292,
     293,   304,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    97,    98,   303,   290,   291,   292,   293,   305,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    53,   107,
     303,   290,   291,   292,   293,   306,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    53,   253,   303,   290,   291,
     292,   293,   307,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   276,   277,   303,   290,   291,   292,   293,   308,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    53,
     278,   303,   290,   291,   292,   293,   309,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   274,   275,   303,   290,
     291,   292,   293,   310,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    68,    71,   303,   290,   291,   292,   293,
     318,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      72,    84,   303,   290,   291,   292,   293,   319,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    85,    86,   303,
     290,   291,   292,   293,   320,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   106,   109,   303,   290,   291,   292,
     293,   321,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   112,   125,   303,   290,   291,   292,   293,   322,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   126,   129,
     303,   290,   291,   292,   293,   323,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   130,   133,   303,   290,   291,
     292,   293,   324,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   136,   138,   303,   290,   291,   292,   293,   376,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   139,
     140,   303,   290,   291,   292,   293,   377,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   141,   144,   303,   290,
     291,   292,   293,   378,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   147,   150,   303,   290,   291,   292,   293,
     379,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     159,   163,   303,   290,   291,   292,   293,   380,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   175,   179,   303,
     290,   291,   292,   293,   381,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   195,   225,   303,   290,   291,   292,
     293,   382,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   252,   316,   303,   290,   291,   292,   293,   383,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,     7,
     303,   290,   291,   292,   293,   384,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    76,   145,   303,   290,   291,
     292,   293,   385,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   153,   162,   303,   290,   291,   292,   293,   386,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   137,
     178,   303,   290,   291,   292,   293,   387,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   102,   148,   303,   182,
     183,   184,   185,   388,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   124,     0,   303,   290,   291,   292,   293,
     389,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     237,   352,   195,     0,   209,   238,   353,     0,   294,   295,
     296,   297,   298,   299,   300,   301,   302,     0,    34,   303,
      15,   328,   245,   246,   247,   248,   249,   250,   345,   346,
     347,   348,   349,   350,   354,   355,   356,   357,   358,   359,
     190,   191,   192,   193,   194,     0,     0,   195,   182,   183,
     184,   185,   298,   299,   300,   301,   302,   251,    44,   303,
      15,     0,     0,   351,   290,   291,   292,   293,     0,   360,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
       0,   195,   182,   183,   184,   185,   294,   295,   296,   297,
     298,   299,   300,   301,   302,     0,     0,   303,   290,   291,
     292,   293,     0,     0,     0,   187,   188,   189,   190,   191,
     192,   193,   194,     0,     0,   195,   182,   183,   184,   185,
       0,   295,   296,   297,   298,   299,   300,   301,   302,     0,
       0,   303,   290,   291,   292,   293,     0,    56,     0,    15,
     188,   189,   190,   191,   192,   193,   194,   290,   291,   195,
      70,   123,    15,    15,     0,     0,   296,   297,   298,   299,
     300,   301,   302,     0,   156,   303,    32,   157,   173,    15,
      15,   296,   297,   298,   299,   300,   301,   302,     0,   197,
     303,    15,   224,     0,    15
};

static const yytype_int16 yycheck[] =
{
      55,    77,    12,    40,   177,   178,    54,     3,    25,    57,
      20,    21,   200,   201,    51,    52,    53,     3,    28,     3,
      75,     3,   241,     7,     3,     3,    36,   200,   201,    50,
       3,    68,     3,    50,    55,     0,    46,    74,    11,    12,
      36,    27,     3,    80,    81,    27,     7,    53,   124,    55,
      87,    88,    31,   272,   273,   274,   275,   276,     3,    25,
      97,    98,    35,    49,    35,    49,    52,    49,     3,   106,
      52,    57,     0,    57,    52,    57,    86,     4,    57,    57,
     117,    91,   119,     3,    57,     3,    57,     7,    49,    10,
      56,   231,   232,   233,   234,   235,   236,   316,   286,     3,
      25,    28,     3,     7,    49,   245,   246,   247,   248,   249,
     250,   251,    57,   286,    49,    49,    25,    26,    36,    50,
     260,   261,    42,    57,    55,    41,    42,    43,    44,   317,
     140,   141,    57,    19,    20,    21,    22,    23,    24,    14,
     150,    25,    25,    53,   317,    55,     3,   287,   203,   159,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,     3,   175,   170,   171,    54,    41,
      42,   226,    50,    57,    57,   179,    57,    55,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     3,    29,     5,     6,     7,     8,     9,    43,
      44,    45,    55,    56,    48,   345,   346,   347,   348,   349,
     350,   351,    30,   353,   354,   355,   356,   357,   358,   359,
     360,     3,     3,     5,     6,     7,     8,     9,    15,    16,
      53,    42,    55,    13,   238,    43,    44,    45,    49,    53,
      48,    55,    57,    11,    12,    50,    15,    16,    17,    18,
      55,     7,    39,    40,    41,    42,    43,    44,    45,    50,
      42,    48,     7,    15,    16,    17,    18,    49,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    25,    26,    48,
      15,    16,    17,    18,    53,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    55,    56,    48,    15,    16,    17,
      18,    53,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    25,    26,    48,    15,    16,    17,    18,    53,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    55,    56,
      48,    15,    16,    17,    18,    53,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    55,    56,    48,    15,    16,
      17,    18,    53,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    55,    56,    48,    15,    16,    17,    18,    53,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    55,
      56,    48,    15,    16,    17,    18,    53,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    43,    44,    48,    15,
      16,    17,    18,    53,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    57,     3,    48,    15,    16,    17,    18,
      53,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       3,    49,    48,    15,    16,    17,    18,    53,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    49,    49,    48,
      15,    16,    17,    18,    53,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    25,    51,    48,    15,    16,    17,
      18,    53,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    25,     3,    48,    15,    16,    17,    18,    53,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    51,    51,
      48,    15,    16,    17,    18,    53,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    53,     3,    48,    15,    16,
      17,    18,    53,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    25,    50,    48,    15,    16,    17,    18,    53,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    56,
      49,    48,    15,    16,    17,    18,    53,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     4,     3,    48,    15,
      16,    17,    18,    53,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     3,    32,    48,    15,    16,    17,    18,
      53,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      33,    53,    48,    15,    16,    17,    18,    53,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    34,    49,    48,
      15,    16,    17,    18,    53,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    48,    57,    48,    15,    16,    17,
      18,    53,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    50,    57,    48,    15,    16,    17,    18,    53,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    48,     4,
      48,    15,    16,    17,    18,    53,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    60,   137,    48,    15,    16,
      17,    18,    53,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   145,   153,    48,    15,    16,    17,    18,    53,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   129,
     162,    48,    15,    16,    17,    18,    53,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    85,   141,    48,    15,
      16,    17,    18,    53,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   109,    -1,    48,    15,    16,    17,    18,
      53,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      50,    50,    48,    -1,    50,    55,    55,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    53,    48,
      55,    50,    19,    20,    21,    22,    23,    24,    19,    20,
      21,    22,    23,    24,    19,    20,    21,    22,    23,    24,
      41,    42,    43,    44,    45,    -1,    -1,    48,    15,    16,
      17,    18,    41,    42,    43,    44,    45,    54,    53,    48,
      55,    -1,    -1,    54,    15,    16,    17,    18,    -1,    54,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    48,    15,    16,    17,    18,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    48,    15,    16,
      17,    18,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    48,    15,    16,    17,    18,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    48,    15,    16,    17,    18,    -1,    53,    -1,    55,
      39,    40,    41,    42,    43,    44,    45,    15,    16,    48,
      53,    53,    55,    55,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    -1,    53,    48,    55,    53,    53,    55,
      55,    39,    40,    41,    42,    43,    44,    45,    -1,    53,
      48,    55,    53,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,    60,     0,    61,    62,    63,    62,    10,    66,
       3,    96,    14,    67,    53,    55,    96,    68,     3,    53,
       4,    28,    69,    90,     3,    94,    96,    96,    29,    91,
      57,    53,    55,    53,    53,    96,    30,    92,     3,     7,
      49,    78,    79,     3,    53,    96,    13,    80,    41,    42,
      78,    25,    26,    55,    56,    57,    53,    96,    11,    12,
      64,    65,     7,     7,    50,    78,    78,    78,    57,    79,
      53,     3,     3,     3,    35,    57,    65,    97,    99,   100,
      25,    26,    78,    56,    49,    49,    49,    49,    57,    78,
      79,    31,    93,    99,    98,    78,    78,    25,    26,     3,
      36,    95,    95,    96,    78,    78,    25,    56,    96,    51,
      78,    78,    25,    50,    55,    50,    50,    25,    50,    25,
      56,    78,    25,    53,    97,     3,    51,     3,    36,    51,
      53,    78,    78,     3,    52,    76,    25,    76,    50,    56,
      49,     4,    70,    77,     3,    70,    96,     3,    94,    96,
      32,    71,    72,    72,    50,    54,    53,    53,    96,    33,
      73,    74,    74,    53,     3,     5,     6,     7,     8,     9,
      42,    49,    85,    53,    96,    34,    75,    81,    81,    49,
      85,    85,    15,    16,    17,    18,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    48,    53,    53,    96,     3,
      27,    49,    52,    57,    82,    87,    52,    85,    86,    50,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    53,    57,    57,    82,    82,    79,
      19,    20,    21,    22,    23,    24,    54,    50,    55,     3,
       7,    42,    88,    89,    79,    19,    20,    21,    22,    23,
      24,    54,    50,    56,     3,     5,     6,     7,     8,     9,
      42,    49,    83,    87,    83,    83,    83,    83,    83,    83,
      85,    88,    41,    42,    43,    44,    55,    56,    56,    83,
      83,    83,    83,    83,    83,    83,    25,    49,    83,    83,
      15,    16,    17,    18,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    48,    53,    53,    53,    53,    53,    53,
      53,    88,    88,    88,    88,    88,    57,    25,    53,    53,
      53,    53,    53,    53,    53,    82,    83,    84,    50,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    88,    82,    19,    20,    21,    22,    23,
      24,    54,    50,    55,    19,    20,    21,    22,    23,    24,
      54,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    60,    59,    61,    61,    63,    62,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    72,    72,    73,    74,    74,    75,    76,
      76,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    87,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    95,    96,    96,
      97,    97,    98,    97,    99,    99,   100,   100,   100,   100,
     100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     0,    11,     2,     1,
      12,    12,     3,     0,     3,     0,     2,     0,     3,     3,
       2,     0,     3,     2,     0,     3,     2,     0,     3,     2,
       0,     3,     3,     5,     3,     3,     1,     1,     3,     4,
       5,     6,     5,     6,     3,     1,     3,     3,     3,     0,
       5,     5,     5,     5,     5,     5,     5,     9,     9,     9,
       9,     9,     9,     9,     6,     6,     6,     6,     6,     6,
       6,    10,    10,    10,    10,    10,    10,    10,     0,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       4,     3,     1,     4,     1,     1,     3,     3,     3,     3,
       2,     3,     4,     1,     3,     0,     3,     0,     3,     0,
       3,     0,     6,     4,     5,     3,     3,     1,     3,     1,
       2,     1,     0,     5,     5,     9,     2,     4,     4,     4,
       6,     6
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
#line 94 "grammar.y"
        {grammar::start = new startNode ();}
#line 1754 "grammar.tab.c"
    break;

  case 3:
#line 94 "grammar.y"
                                                     {}
#line 1760 "grammar.tab.c"
    break;

  case 4:
#line 97 "grammar.y"
                               {}
#line 1766 "grammar.tab.c"
    break;

  case 5:
#line 98 "grammar.y"
                       {}
#line 1772 "grammar.tab.c"
    break;

  case 6:
#line 101 "grammar.y"
               {grammar::start->create_func_defn ();}
#line 1778 "grammar.tab.c"
    break;

  case 7:
#line 101 "grammar.y"
                                                                                                                                                                   {grammar::start->increment_func_defn_count();}
#line 1784 "grammar.tab.c"
    break;

  case 8:
#line 105 "grammar.y"
                                     {}
#line 1790 "grammar.tab.c"
    break;

  case 9:
#line 106 "grammar.y"
                     {}
#line 1796 "grammar.tab.c"
    break;

  case 10:
#line 109 "grammar.y"
                                                                                                      {stencilDefn *node = new stencilDefn ((yyvsp[-1].stmtlist), (yyvsp[-8].arglist));
							grammar::start->push_stencil_defn ((yyvsp[-10].str), node);}
#line 1803 "grammar.tab.c"
    break;

  case 11:
#line 111 "grammar.y"
                                                                                                    {stencilDefn *node = new stencilDefn ((yyvsp[-1].stmtlist), (yyvsp[-8].arglist));
                            grammar::start->push_stencil_defn ((yyvsp[-10].str), node);}
#line 1810 "grammar.tab.c"
    break;

  case 12:
#line 116 "grammar.y"
                                {grammar::start->push_parameter ((yyvsp[-1].stringlist));}
#line 1816 "grammar.tab.c"
    break;

  case 13:
#line 117 "grammar.y"
          {}
#line 1822 "grammar.tab.c"
    break;

  case 14:
#line 121 "grammar.y"
                               {grammar::start->push_iterator ((yyvsp[-1].stringlist));}
#line 1828 "grammar.tab.c"
    break;

  case 15:
#line 122 "grammar.y"
          {}
#line 1834 "grammar.tab.c"
    break;

  case 17:
#line 127 "grammar.y"
          {}
#line 1840 "grammar.tab.c"
    break;

  case 18:
#line 130 "grammar.y"
                           {grammar::start->push_var_decl ((yyvsp[-1].stringlist), get_data_type ((yyvsp[-2].ival)));}
#line 1846 "grammar.tab.c"
    break;

  case 19:
#line 131 "grammar.y"
                                 {grammar::start->push_array_decl ((yyvsp[-1].arraylist), get_data_type ((yyvsp[-2].ival)));}
#line 1852 "grammar.tab.c"
    break;

  case 21:
#line 135 "grammar.y"
          {}
#line 1858 "grammar.tab.c"
    break;

  case 22:
#line 138 "grammar.y"
                             {grammar::start->push_shmem_decl ((yyvsp[-1].stringlist));}
#line 1864 "grammar.tab.c"
    break;

  case 24:
#line 142 "grammar.y"
          {}
#line 1870 "grammar.tab.c"
    break;

  case 25:
#line 145 "grammar.y"
                                 {grammar::start->push_noshmem_decl ((yyvsp[-1].stringlist));}
#line 1876 "grammar.tab.c"
    break;

  case 27:
#line 149 "grammar.y"
          {}
#line 1882 "grammar.tab.c"
    break;

  case 28:
#line 152 "grammar.y"
                           {grammar::start->push_gmem_decl ((yyvsp[-1].stringlist));}
#line 1888 "grammar.tab.c"
    break;

  case 30:
#line 156 "grammar.y"
          {}
#line 1894 "grammar.tab.c"
    break;

  case 31:
#line 159 "grammar.y"
                               {grammar::start->push_temp_var_decl ((yyvsp[-1].stringlist), get_data_type ((yyvsp[-2].ival)));}
#line 1900 "grammar.tab.c"
    break;

  case 32:
#line 160 "grammar.y"
                                 {grammar::start->push_temp_array_decl ((yyvsp[-1].arraylist), get_data_type ((yyvsp[-2].ival)));}
#line 1906 "grammar.tab.c"
    break;

  case 33:
#line 161 "grammar.y"
                                         {grammar::start->push_temp_var_init_decl (get_data_type ((yyvsp[-4].ival)), (yyvsp[-3].str), (yyvsp[-1].exprnode));}
#line 1912 "grammar.tab.c"
    break;

  case 34:
#line 164 "grammar.y"
                     {(yyval.exprnode) = new binaryNode (T_PLUS, new idNode ((yyvsp[-2].str)), new datatypeNode<int> ((yyvsp[0].ival), INT), false);}
#line 1918 "grammar.tab.c"
    break;

  case 35:
#line 165 "grammar.y"
                       {(yyval.exprnode) = new binaryNode (T_MINUS, new idNode ((yyvsp[-2].str)), new datatypeNode<int> ((yyvsp[0].ival), INT), false);}
#line 1924 "grammar.tab.c"
    break;

  case 36:
#line 166 "grammar.y"
             {(yyval.exprnode) = new idNode ((yyvsp[0].str));}
#line 1930 "grammar.tab.c"
    break;

  case 37:
#line 167 "grammar.y"
                {(yyval.exprnode) = new datatypeNode<int> ((yyvsp[0].ival), INT);}
#line 1936 "grammar.tab.c"
    break;

  case 38:
#line 170 "grammar.y"
                                {(yyvsp[-2].rangelist)->push_back (new Range (new datatypeNode<int> (0, INT), (yyvsp[0].exprnode)));
					(yyval.rangelist) = (yyvsp[-2].rangelist);}
#line 1943 "grammar.tab.c"
    break;

  case 39:
#line 172 "grammar.y"
                                 {(yyvsp[-3].rangelist)->push_back (new Range (new datatypeNode<int> (0, INT), (yyvsp[0].exprnode)));
                    (yyval.rangelist) = (yyvsp[-3].rangelist);}
#line 1950 "grammar.tab.c"
    break;

  case 40:
#line 174 "grammar.y"
                                          {(yyvsp[-4].rangelist)->push_back (new Range ((yyvsp[-2].exprnode), (yyvsp[0].exprnode)));
					(yyval.rangelist) = (yyvsp[-4].rangelist);}
#line 1957 "grammar.tab.c"
    break;

  case 41:
#line 176 "grammar.y"
                                             {(yyvsp[-5].rangelist)->push_back (new Range ((yyvsp[-2].exprnode), (yyvsp[0].exprnode)));
					(yyval.rangelist) = (yyvsp[-5].rangelist);}
#line 1964 "grammar.tab.c"
    break;

  case 42:
#line 178 "grammar.y"
                                          {(yyvsp[-4].rangelist)->push_back (new Range ((yyvsp[-2].exprnode), (yyvsp[0].exprnode)));
					(yyval.rangelist) = (yyvsp[-4].rangelist);}
#line 1971 "grammar.tab.c"
    break;

  case 43:
#line 180 "grammar.y"
                                             {(yyvsp[-5].rangelist)->push_back (new Range ((yyvsp[-2].exprnode), (yyvsp[0].exprnode)));
					(yyval.rangelist) = (yyvsp[-5].rangelist);}
#line 1978 "grammar.tab.c"
    break;

  case 44:
#line 182 "grammar.y"
                        {std::vector<Range*> *node = new std::vector<Range*> (); 
			node->push_back (new Range (new datatypeNode<int> (0, INT), (yyvsp[-1].exprnode)));
			(yyval.rangelist) = node;}
#line 1986 "grammar.tab.c"
    break;

  case 45:
#line 185 "grammar.y"
                {std::vector<Range*> *node = new std::vector<Range*> ();
			node->push_back (new Range (new datatypeNode<int> (0, INT), (yyvsp[0].exprnode)));
			(yyval.rangelist) = node;}
#line 1994 "grammar.tab.c"
    break;

  case 46:
#line 188 "grammar.y"
                            {std::vector<Range*> *node = new std::vector<Range*> ();
			node->push_back (new Range ((yyvsp[-2].exprnode), (yyvsp[0].exprnode)));
			(yyval.rangelist) = node;}
#line 2002 "grammar.tab.c"
    break;

  case 47:
#line 191 "grammar.y"
                            {std::vector<Range*> *node = new std::vector<Range*> ();
			node->push_back (new Range ((yyvsp[-2].exprnode), (yyvsp[0].exprnode)));
			(yyval.rangelist) = node;}
#line 2010 "grammar.tab.c"
    break;

  case 48:
#line 197 "grammar.y"
                                 {grammar::start->push_coefficient ((yyvsp[-1].stringlist));}
#line 2016 "grammar.tab.c"
    break;

  case 49:
#line 198 "grammar.y"
          {}
#line 2022 "grammar.tab.c"
    break;

  case 50:
#line 203 "grammar.y"
                                     {stmtNode *node = new stmtNode (ST_EQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode));
					(yyvsp[-4].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-4].stmtlist);}
#line 2030 "grammar.tab.c"
    break;

  case 51:
#line 206 "grammar.y"
                                        {stmtNode *node = new stmtNode (ST_PLUSEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode));
					(yyvsp[-4].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-4].stmtlist);}
#line 2038 "grammar.tab.c"
    break;

  case 52:
#line 209 "grammar.y"
                                         {stmtNode *node = new stmtNode (ST_MINUSEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode));
					(yyvsp[-4].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-4].stmtlist);}
#line 2046 "grammar.tab.c"
    break;

  case 53:
#line 212 "grammar.y"
                                        {stmtNode *node = new stmtNode (ST_MULTEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode));
					(yyvsp[-4].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-4].stmtlist);}
#line 2054 "grammar.tab.c"
    break;

  case 54:
#line 215 "grammar.y"
                                       {stmtNode *node = new stmtNode (ST_DIVEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode));
					(yyvsp[-4].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-4].stmtlist);}
#line 2062 "grammar.tab.c"
    break;

  case 55:
#line 218 "grammar.y"
                                       {stmtNode *node = new stmtNode (ST_ANDEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode));
					(yyvsp[-4].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-4].stmtlist);}
#line 2070 "grammar.tab.c"
    break;

  case 56:
#line 221 "grammar.y"
                                      {stmtNode *node = new stmtNode (ST_OREQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode));
					(yyvsp[-4].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-4].stmtlist);}
#line 2078 "grammar.tab.c"
    break;

  case 57:
#line 224 "grammar.y"
                                                             {stmtNode *node = new stmtNode (ST_EQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode), *((yyvsp[-6].rangelist)));
					(yyvsp[-8].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-8].stmtlist);}
#line 2086 "grammar.tab.c"
    break;

  case 58:
#line 227 "grammar.y"
                                                                {stmtNode *node = new stmtNode (ST_PLUSEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode), *((yyvsp[-6].rangelist)));
					(yyvsp[-8].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-8].stmtlist);}
#line 2094 "grammar.tab.c"
    break;

  case 59:
#line 230 "grammar.y"
                                                                 {stmtNode *node = new stmtNode (ST_MINUSEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode), *((yyvsp[-6].rangelist)));
					(yyvsp[-8].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-8].stmtlist);}
#line 2102 "grammar.tab.c"
    break;

  case 60:
#line 233 "grammar.y"
                                                                {stmtNode *node = new stmtNode (ST_MULTEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode), *((yyvsp[-6].rangelist)));
					(yyvsp[-8].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-8].stmtlist);}
#line 2110 "grammar.tab.c"
    break;

  case 61:
#line 236 "grammar.y"
                                                               {stmtNode *node = new stmtNode (ST_DIVEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode), *((yyvsp[-6].rangelist)));
					(yyvsp[-8].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-8].stmtlist);}
#line 2118 "grammar.tab.c"
    break;

  case 62:
#line 239 "grammar.y"
                                                               {stmtNode *node = new stmtNode (ST_ANDEQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode), *((yyvsp[-6].rangelist)));
					(yyvsp[-8].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-8].stmtlist);}
#line 2126 "grammar.tab.c"
    break;

  case 63:
#line 242 "grammar.y"
                                                              {stmtNode *node = new stmtNode (ST_OREQ, (yyvsp[-3].exprnode), (yyvsp[-1].exprnode), *((yyvsp[-6].rangelist)));
					(yyvsp[-8].stmtlist)->push_stmt (node);
					(yyval.stmtlist) = (yyvsp[-8].stmtlist);}
#line 2134 "grammar.tab.c"
    break;

  case 64:
#line 246 "grammar.y"
                                             {(yyval.stmtlist) = (yyvsp[-5].stmtlist);}
#line 2140 "grammar.tab.c"
    break;

  case 65:
#line 247 "grammar.y"
                                                {(yyval.stmtlist) = (yyvsp[-5].stmtlist);}
#line 2146 "grammar.tab.c"
    break;

  case 66:
#line 248 "grammar.y"
                                                 {(yyval.stmtlist) = (yyvsp[-5].stmtlist);}
#line 2152 "grammar.tab.c"
    break;

  case 67:
#line 249 "grammar.y"
                                                {(yyval.stmtlist) = (yyvsp[-5].stmtlist);}
#line 2158 "grammar.tab.c"
    break;

  case 68:
#line 250 "grammar.y"
                                               {(yyval.stmtlist) = (yyvsp[-5].stmtlist);}
#line 2164 "grammar.tab.c"
    break;

  case 69:
#line 251 "grammar.y"
                                               {(yyval.stmtlist) = (yyvsp[-5].stmtlist);}
#line 2170 "grammar.tab.c"
    break;

  case 70:
#line 252 "grammar.y"
                                              {(yyval.stmtlist) = (yyvsp[-5].stmtlist);}
#line 2176 "grammar.tab.c"
    break;

  case 71:
#line 253 "grammar.y"
                                                                     {(yyval.stmtlist) = (yyvsp[-9].stmtlist);}
#line 2182 "grammar.tab.c"
    break;

  case 72:
#line 254 "grammar.y"
                                                                        {(yyval.stmtlist) = (yyvsp[-9].stmtlist);}
#line 2188 "grammar.tab.c"
    break;

  case 73:
#line 255 "grammar.y"
                                                                         {(yyval.stmtlist) = (yyvsp[-9].stmtlist);}
#line 2194 "grammar.tab.c"
    break;

  case 74:
#line 256 "grammar.y"
                                                                        {(yyval.stmtlist) = (yyvsp[-9].stmtlist);}
#line 2200 "grammar.tab.c"
    break;

  case 75:
#line 257 "grammar.y"
                                                                       {(yyval.stmtlist) = (yyvsp[-9].stmtlist);}
#line 2206 "grammar.tab.c"
    break;

  case 76:
#line 258 "grammar.y"
                                                                       {(yyval.stmtlist) = (yyvsp[-9].stmtlist);}
#line 2212 "grammar.tab.c"
    break;

  case 77:
#line 259 "grammar.y"
                                                                      {(yyval.stmtlist) = (yyvsp[-9].stmtlist);}
#line 2218 "grammar.tab.c"
    break;

  case 78:
#line 260 "grammar.y"
          {stmtList *node = new stmtList (); 
		(yyval.stmtlist) = node;}
#line 2225 "grammar.tab.c"
    break;

  case 79:
#line 265 "grammar.y"
         {(yyval.exprnode) = new idNode ((yyvsp[0].str));}
#line 2231 "grammar.tab.c"
    break;

  case 80:
#line 266 "grammar.y"
                    {(yyval.exprnode) = (yyvsp[0].shiftvecnode);}
#line 2237 "grammar.tab.c"
    break;

  case 81:
#line 267 "grammar.y"
                      {(yyval.exprnode) = (yyvsp[-1].exprnode);}
#line 2243 "grammar.tab.c"
    break;

  case 82:
#line 271 "grammar.y"
         {(yyval.exprnode) = new idNode ((yyvsp[0].str));}
#line 2249 "grammar.tab.c"
    break;

  case 83:
#line 272 "grammar.y"
                    {(yyval.exprnode) = (yyvsp[0].shiftvecnode);}
#line 2255 "grammar.tab.c"
    break;

  case 84:
#line 273 "grammar.y"
               {(yyval.exprnode) = new datatypeNode<bool> ((yyvsp[0].ival), BOOL);}
#line 2261 "grammar.tab.c"
    break;

  case 85:
#line 274 "grammar.y"
                {(yyval.exprnode) = new datatypeNode<bool> ((yyvsp[0].ival), BOOL);}
#line 2267 "grammar.tab.c"
    break;

  case 86:
#line 275 "grammar.y"
                {(yyval.exprnode) = new datatypeNode<int> ((yyvsp[0].ival), INT);}
#line 2273 "grammar.tab.c"
    break;

  case 87:
#line 276 "grammar.y"
                   {(yyval.exprnode) = new datatypeNode<double> ((yyvsp[0].dval), DOUBLE);}
#line 2279 "grammar.tab.c"
    break;

  case 88:
#line 277 "grammar.y"
                  {(yyval.exprnode) = new datatypeNode<float> ((yyvsp[0].fval), FLOAT);}
#line 2285 "grammar.tab.c"
    break;

  case 89:
#line 278 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_OR, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2291 "grammar.tab.c"
    break;

  case 90:
#line 279 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_AND, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2297 "grammar.tab.c"
    break;

  case 91:
#line 280 "grammar.y"
                     {(yyval.exprnode) = new binaryNode (T_EQ, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2303 "grammar.tab.c"
    break;

  case 92:
#line 281 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_NEQ, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2309 "grammar.tab.c"
    break;

  case 93:
#line 282 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_LT, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2315 "grammar.tab.c"
    break;

  case 94:
#line 283 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_LEQ, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2321 "grammar.tab.c"
    break;

  case 95:
#line 284 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_GT, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2327 "grammar.tab.c"
    break;

  case 96:
#line 285 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_GEQ, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2333 "grammar.tab.c"
    break;

  case 97:
#line 286 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_PLUS, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2339 "grammar.tab.c"
    break;

  case 98:
#line 287 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_MINUS, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2345 "grammar.tab.c"
    break;

  case 99:
#line 288 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_MULT, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2351 "grammar.tab.c"
    break;

  case 100:
#line 289 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_DIV, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2357 "grammar.tab.c"
    break;

  case 101:
#line 290 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_MOD, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2363 "grammar.tab.c"
    break;

  case 102:
#line 291 "grammar.y"
                               {(yyval.exprnode) = new uminusNode ((yyvsp[0].exprnode));}
#line 2369 "grammar.tab.c"
    break;

  case 103:
#line 292 "grammar.y"
                      {(yyval.exprnode) = new binaryNode (T_EXP, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2375 "grammar.tab.c"
    break;

  case 104:
#line 293 "grammar.y"
                      {(yyvsp[-1].exprnode)->set_nested (); 
			(yyval.exprnode) = (yyvsp[-1].exprnode);}
#line 2382 "grammar.tab.c"
    break;

  case 105:
#line 295 "grammar.y"
                             {(yyval.exprnode) = new functionNode ((yyvsp[-3].str), (yyvsp[-1].exprlist));}
#line 2388 "grammar.tab.c"
    break;

  case 106:
#line 298 "grammar.y"
                          {(yyvsp[-2].exprlist)->push_back ((yyvsp[0].exprnode));
		(yyval.exprlist) = (yyvsp[-2].exprlist);}
#line 2395 "grammar.tab.c"
    break;

  case 107:
#line 300 "grammar.y"
              {std::vector<exprNode*> *node = new std::vector<exprNode*> ();
		node->push_back ((yyvsp[0].exprnode));
		(yyval.exprlist) = node;}
#line 2403 "grammar.tab.c"
    break;

  case 108:
#line 305 "grammar.y"
                {(yyval.exprnode) = new idNode ((yyvsp[0].str));}
#line 2409 "grammar.tab.c"
    break;

  case 109:
#line 306 "grammar.y"
               {(yyval.exprnode) = new datatypeNode<bool> ((yyvsp[0].ival), BOOL);}
#line 2415 "grammar.tab.c"
    break;

  case 110:
#line 307 "grammar.y"
                {(yyval.exprnode) = new datatypeNode<bool> ((yyvsp[0].ival), BOOL);}
#line 2421 "grammar.tab.c"
    break;

  case 111:
#line 308 "grammar.y"
                {(yyval.exprnode) = new datatypeNode<int> ((yyvsp[0].ival), INT);}
#line 2427 "grammar.tab.c"
    break;

  case 112:
#line 309 "grammar.y"
                   {(yyval.exprnode) = new datatypeNode<double> ((yyvsp[0].dval), DOUBLE);}
#line 2433 "grammar.tab.c"
    break;

  case 113:
#line 310 "grammar.y"
                  {(yyval.exprnode) = new datatypeNode<float> ((yyvsp[0].fval), FLOAT);}
#line 2439 "grammar.tab.c"
    break;

  case 114:
#line 311 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_OR, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2445 "grammar.tab.c"
    break;

  case 115:
#line 312 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_AND, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2451 "grammar.tab.c"
    break;

  case 116:
#line 313 "grammar.y"
                                   {(yyval.exprnode) = new binaryNode (T_EQ, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2457 "grammar.tab.c"
    break;

  case 117:
#line 314 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_NEQ, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2463 "grammar.tab.c"
    break;

  case 118:
#line 315 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_LT, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2469 "grammar.tab.c"
    break;

  case 119:
#line 316 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_LEQ, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2475 "grammar.tab.c"
    break;

  case 120:
#line 317 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_GT, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2481 "grammar.tab.c"
    break;

  case 121:
#line 318 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_GEQ, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2487 "grammar.tab.c"
    break;

  case 122:
#line 319 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_PLUS, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2493 "grammar.tab.c"
    break;

  case 123:
#line 320 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_MINUS, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2499 "grammar.tab.c"
    break;

  case 124:
#line 321 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_MULT, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2505 "grammar.tab.c"
    break;

  case 125:
#line 322 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_DIV, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2511 "grammar.tab.c"
    break;

  case 126:
#line 323 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_MOD, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2517 "grammar.tab.c"
    break;

  case 127:
#line 324 "grammar.y"
                                      {(yyval.exprnode) = new uminusNode ((yyvsp[0].exprnode));}
#line 2523 "grammar.tab.c"
    break;

  case 128:
#line 325 "grammar.y"
                                    {(yyval.exprnode) = new binaryNode (T_EXP, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2529 "grammar.tab.c"
    break;

  case 129:
#line 326 "grammar.y"
                             {(yyvsp[-1].exprnode)->set_nested (); 
			(yyval.exprnode) = (yyvsp[-1].exprnode);}
#line 2536 "grammar.tab.c"
    break;

  case 130:
#line 328 "grammar.y"
                                    {(yyval.exprnode) = new functionNode ((yyvsp[-3].str), (yyvsp[-1].exprlist));}
#line 2542 "grammar.tab.c"
    break;

  case 131:
#line 330 "grammar.y"
                                               {(yyvsp[-2].exprlist)->push_back ((yyvsp[0].exprnode));
		(yyval.exprlist) = (yyvsp[-2].exprlist);}
#line 2549 "grammar.tab.c"
    break;

  case 132:
#line 332 "grammar.y"
                     {std::vector<exprNode*> *node = new std::vector<exprNode*> ();
		node->push_back ((yyvsp[0].exprnode));
		(yyval.exprlist) = node;}
#line 2557 "grammar.tab.c"
    break;

  case 133:
#line 338 "grammar.y"
                                  {(yyvsp[-1].shiftvecnode)->set_name ((yyvsp[-3].str)); 
				(yyval.shiftvecnode) = (yyvsp[-1].shiftvecnode);}
#line 2564 "grammar.tab.c"
    break;

  case 134:
#line 342 "grammar.y"
                 {(yyval.exprnode) = new idNode ((yyvsp[0].str));}
#line 2570 "grammar.tab.c"
    break;

  case 135:
#line 343 "grammar.y"
                {(yyval.exprnode) = new datatypeNode<int> ((yyvsp[0].ival), INT);}
#line 2576 "grammar.tab.c"
    break;

  case 136:
#line 344 "grammar.y"
                                      {(yyval.exprnode) = new binaryNode (T_PLUS, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2582 "grammar.tab.c"
    break;

  case 137:
#line 345 "grammar.y"
                                      {(yyval.exprnode) = new binaryNode (T_MINUS, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2588 "grammar.tab.c"
    break;

  case 138:
#line 346 "grammar.y"
                                      {(yyval.exprnode) = new binaryNode (T_MULT, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2594 "grammar.tab.c"
    break;

  case 139:
#line 347 "grammar.y"
                                      {(yyval.exprnode) = new binaryNode (T_DIV, (yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2600 "grammar.tab.c"
    break;

  case 140:
#line 348 "grammar.y"
                                       {(yyval.exprnode) = new uminusNode ((yyvsp[0].exprnode));}
#line 2606 "grammar.tab.c"
    break;

  case 141:
#line 351 "grammar.y"
                                        {(yyvsp[-2].shiftvecnode)->push_index ((yyvsp[0].exprnode)); 
					(yyval.shiftvecnode) = (yyvsp[-2].shiftvecnode);}
#line 2613 "grammar.tab.c"
    break;

  case 142:
#line 353 "grammar.y"
                                        {(yyvsp[-3].shiftvecnode)->push_index ((yyvsp[0].exprnode)); 
					(yyval.shiftvecnode) = (yyvsp[-3].shiftvecnode);}
#line 2620 "grammar.tab.c"
    break;

  case 143:
#line 355 "grammar.y"
                      {shiftvecNode *node = new shiftvecNode ();
		node->push_index ((yyvsp[0].exprnode)); 
		(yyval.shiftvecnode) = node;}
#line 2628 "grammar.tab.c"
    break;

  case 144:
#line 361 "grammar.y"
                                 {grammar::start->push_allocin ((yyvsp[-1].stringlist));}
#line 2634 "grammar.tab.c"
    break;

  case 145:
#line 362 "grammar.y"
          {}
#line 2640 "grammar.tab.c"
    break;

  case 146:
#line 365 "grammar.y"
                               {grammar::start->push_copyin ((yyvsp[-1].stringlist));}
#line 2646 "grammar.tab.c"
    break;

  case 147:
#line 366 "grammar.y"
          {}
#line 2652 "grammar.tab.c"
    break;

  case 148:
#line 370 "grammar.y"
                                   {grammar::start->push_constant ((yyvsp[-1].stringlist));}
#line 2658 "grammar.tab.c"
    break;

  case 149:
#line 371 "grammar.y"
          {}
#line 2664 "grammar.tab.c"
    break;

  case 150:
#line 374 "grammar.y"
                                 {grammar::start->push_copyout ((yyvsp[-1].stringlist));}
#line 2670 "grammar.tab.c"
    break;

  case 151:
#line 375 "grammar.y"
          {}
#line 2676 "grammar.tab.c"
    break;

  case 152:
#line 378 "grammar.y"
                                               {(yyvsp[-5].arraylist)->push_back (new arrayDecl (std::string((yyvsp[-3].str)), *((yyvsp[-1].rangelist))));
						(yyval.arraylist) = (yyvsp[-5].arraylist);}
#line 2683 "grammar.tab.c"
    break;

  case 153:
#line 380 "grammar.y"
                               {std::vector<arrayDecl*> *node = new std::vector<arrayDecl*> ();
				node->push_back (new arrayDecl (std::string((yyvsp[-3].str)), *((yyvsp[-1].rangelist))));
				(yyval.arraylist) = node;}
#line 2691 "grammar.tab.c"
    break;

  case 154:
#line 385 "grammar.y"
                                     {(yyvsp[-4].arglist)->push_back (std::string ((yyvsp[0].str)));
			(yyvsp[-4].arglist)->push_inout (std::string ((yyvsp[0].str)));
			(yyval.arglist) = (yyvsp[-4].arglist);}
#line 2699 "grammar.tab.c"
    break;

  case 155:
#line 388 "grammar.y"
                         {(yyvsp[-2].arglist)->push_back (std::string ((yyvsp[0].str)));
			(yyval.arglist) = (yyvsp[-2].arglist);}
#line 2706 "grammar.tab.c"
    break;

  case 156:
#line 390 "grammar.y"
                         {argList * node = new argList ();
		node->push_back (std::string ((yyvsp[0].str)));
		node->push_inout (std::string ((yyvsp[0].str)));
		(yyval.arglist) = node;}
#line 2715 "grammar.tab.c"
    break;

  case 157:
#line 394 "grammar.y"
             {argList * node = new argList ();
		node->push_back (std::string ((yyvsp[0].str)));
		(yyval.arglist) = node;}
#line 2723 "grammar.tab.c"
    break;

  case 158:
#line 399 "grammar.y"
                       {(yyvsp[-2].stringlist)->push_back (std::string ((yyvsp[0].str)));
			(yyval.stringlist) = (yyvsp[-2].stringlist);}
#line 2730 "grammar.tab.c"
    break;

  case 159:
#line 401 "grammar.y"
             {std::vector<std::string> * node = new std::vector<std::string> ();
		node->push_back (std::string ((yyvsp[0].str)));
		(yyval.stringlist) = node;}
#line 2738 "grammar.tab.c"
    break;

  case 160:
#line 407 "grammar.y"
                                        {grammar::start->push_stencil_call ((yyvsp[0].stencilcall));}
#line 2744 "grammar.tab.c"
    break;

  case 161:
#line 408 "grammar.y"
                      {grammar::start->push_stencil_call ((yyvsp[0].stencilcall));}
#line 2750 "grammar.tab.c"
    break;

  case 162:
#line 409 "grammar.y"
                      {grammar::start->set_stencil_call_iterations((yyvsp[0].iterrange));}
#line 2756 "grammar.tab.c"
    break;

  case 163:
#line 409 "grammar.y"
                                                                                              {grammar::start->reset_stencil_call_iterations();}
#line 2762 "grammar.tab.c"
    break;

  case 164:
#line 412 "grammar.y"
                                    {stencilCall *node = new stencilCall (std::string((yyvsp[-4].str)), *((yyvsp[-2].stringlist)));
					(yyval.stencilcall) = node;}
#line 2769 "grammar.tab.c"
    break;

  case 165:
#line 414 "grammar.y"
                                                        {stencilCall *node = new stencilCall (std::string((yyvsp[-4].str)), *((yyvsp[-2].stringlist)), *((yyvsp[-7].rangelist)));
					(yyval.stencilcall) = node;}
#line 2776 "grammar.tab.c"
    break;

  case 166:
#line 418 "grammar.y"
                            {(yyval.iterrange) = new Range (new datatypeNode<int> (0, INT), (yyvsp[0].exprnode));}
#line 2782 "grammar.tab.c"
    break;

  case 167:
#line 419 "grammar.y"
                                {(yyval.iterrange) = new Range (new datatypeNode<int> (0, INT), (yyvsp[-1].exprnode));}
#line 2788 "grammar.tab.c"
    break;

  case 168:
#line 420 "grammar.y"
                                {(yyval.iterrange) = new Range (new datatypeNode<int> (0, INT), (yyvsp[-1].exprnode));}
#line 2794 "grammar.tab.c"
    break;

  case 169:
#line 421 "grammar.y"
                                    {(yyval.iterrange) = new Range ((yyvsp[-2].exprnode), (yyvsp[0].exprnode));}
#line 2800 "grammar.tab.c"
    break;

  case 170:
#line 422 "grammar.y"
                                            {(yyval.iterrange) = new Range ((yyvsp[-3].exprnode), (yyvsp[-1].exprnode));}
#line 2806 "grammar.tab.c"
    break;

  case 171:
#line 423 "grammar.y"
                                            {(yyval.iterrange) = new Range ((yyvsp[-3].exprnode), (yyvsp[-1].exprnode));}
#line 2812 "grammar.tab.c"
    break;


#line 2816 "grammar.tab.c"

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
#line 425 "grammar.y"

