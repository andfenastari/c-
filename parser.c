/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include "lexer.h"
#include "ast.h"
#include "parser.h"

#define SET_INFO(s, e) $$->location.start = (s).loc; $$->location.end = (e).loc

int yylex();
void yyerror(const char *s);


#line 84 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_RELOP = 10,                     /* RELOP  */
  YYSYMBOL_ADDOP = 11,                     /* ADDOP  */
  YYSYMBOL_MULOP = 12,                     /* MULOP  */
  YYSYMBOL_INCOP = 13,                     /* INCOP  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_SCOLON = 15,                    /* SCOLON  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_LPAREN = 17,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 18,                    /* RPAREN  */
  YYSYMBOL_LSBRACK = 19,                   /* LSBRACK  */
  YYSYMBOL_RSBRACK = 20,                   /* RSBRACK  */
  YYSYMBOL_LCBRACK = 21,                   /* LCBRACK  */
  YYSYMBOL_RCBRACK = 22,                   /* RCBRACK  */
  YYSYMBOL_ID = 23,                        /* ID  */
  YYSYMBOL_NUM = 24,                       /* NUM  */
  YYSYMBOL_ERROR = 25,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_program = 27,                   /* program  */
  YYSYMBOL_decl_list = 28,                 /* decl_list  */
  YYSYMBOL_decl = 29,                      /* decl  */
  YYSYMBOL_var_decl = 30,                  /* var_decl  */
  YYSYMBOL_fun_decl = 31,                  /* fun_decl  */
  YYSYMBOL_params = 32,                    /* params  */
  YYSYMBOL_param_list = 33,                /* param_list  */
  YYSYMBOL_param = 34,                     /* param  */
  YYSYMBOL_block = 35,                     /* block  */
  YYSYMBOL_stmt_list = 36,                 /* stmt_list  */
  YYSYMBOL_stmt = 37,                      /* stmt  */
  YYSYMBOL_expr = 38,                      /* expr  */
  YYSYMBOL_assign_expr = 39,               /* assign_expr  */
  YYSYMBOL_rel_expr = 40,                  /* rel_expr  */
  YYSYMBOL_sum_expr = 41,                  /* sum_expr  */
  YYSYMBOL_mul_expr = 42,                  /* mul_expr  */
  YYSYMBOL_inc_expr = 43,                  /* inc_expr  */
  YYSYMBOL_factor = 44,                    /* factor  */
  YYSYMBOL_funcall = 45,                   /* funcall  */
  YYSYMBOL_args = 46,                      /* args  */
  YYSYMBOL_arg_list = 47,                  /* arg_list  */
  YYSYMBOL_var = 48,                       /* var  */
  YYSYMBOL_return_stmt = 49,               /* return_stmt  */
  YYSYMBOL_while_stmt = 50,                /* while_stmt  */
  YYSYMBOL_for_stmt = 51,                  /* for_stmt  */
  YYSYMBOL_if_stmt = 52,                   /* if_stmt  */
  YYSYMBOL_type_spec = 53,                 /* type_spec  */
  YYSYMBOL_id = 54,                        /* id  */
  YYSYMBOL_num = 55,                       /* num  */
  YYSYMBOL_int = 56,                       /* int  */
  YYSYMBOL_void = 57,                      /* void  */
  YYSYMBOL_err = 58                        /* err  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    56,    57,    59,    60,    61,    62,    64,
      65,    66,    68,    70,    71,    73,    74,    76,    77,    78,
      80,    82,    83,    85,    86,    87,    88,    89,    90,    91,
      92,    94,    95,    97,    99,   100,   102,   103,   105,   106,
     108,   109,   110,   112,   113,   114,   115,   117,   119,   120,
     122,   123,   125,   126,   129,   130,   132,   134,   136,   137,
     139,   140,   142,   143,   144,   145,   147
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "RETURN",
  "INT", "VOID", "WHILE", "FOR", "RELOP", "ADDOP", "MULOP", "INCOP",
  "ASSIGN", "SCOLON", "COMMA", "LPAREN", "RPAREN", "LSBRACK", "RSBRACK",
  "LCBRACK", "RCBRACK", "ID", "NUM", "ERROR", "$accept", "program",
  "decl_list", "decl", "var_decl", "fun_decl", "params", "param_list",
  "param", "block", "stmt_list", "stmt", "expr", "assign_expr", "rel_expr",
  "sum_expr", "mul_expr", "inc_expr", "factor", "funcall", "args",
  "arg_list", "var", "return_stmt", "while_stmt", "for_stmt", "if_stmt",
  "type_spec", "id", "num", "int", "void", "err", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      65,  -100,  -100,  -100,     6,  -100,    65,  -100,  -100,    16,
    -100,  -100,    53,  -100,  -100,  -100,    76,  -100,  -100,    13,
    -100,    14,     7,    27,    13,  -100,    37,  -100,  -100,     8,
      43,  -100,    56,  -100,    42,    23,  -100,    52,    60,  -100,
      16,    74,  -100,    59,  -100,  -100,    80,  -100,    13,    13,
      27,  -100,    13,    13,    13,    62,    14,    82,    84,  -100,
      95,    43,  -100,  -100,    91,    92,  -100,    88,    40,  -100,
    -100,    93,  -100,    13,  -100,  -100,    94,    -1,    97,    98,
    -100,  -100,    96,    40,   101,  -100,  -100,  -100,  -100,    16,
    -100,  -100,  -100,    13,  -100,   102,    13,    13,  -100,  -100,
    -100,    90,   103,  -100,   104,   105,    79,    79,    13,   108,
    -100,   109,    79,    13,  -100,   107,    79,  -100
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    66,    64,    65,     0,     2,     0,     5,     6,     0,
      61,    60,     0,     1,     3,    62,     0,     7,     8,     0,
       9,     0,     0,     0,     0,    63,     0,    31,    32,    35,
      37,    39,    42,    45,    44,    52,    46,     0,    14,    16,
       0,    13,    19,     0,    40,    44,     0,    10,     0,     0,
       0,    41,     0,    49,     0,     0,     0,    17,     0,    43,
      34,    36,    38,    33,    51,     0,    48,     0,     0,    12,
      15,     0,    11,     0,    47,    53,     0,     0,     0,     0,
      24,    25,     0,     0,     0,    26,    27,    28,    29,     0,
      30,    18,    50,     0,    54,     0,     0,     0,    20,    21,
      23,     0,     0,    55,     0,     0,     0,     0,     0,    59,
      56,     0,     0,     0,    58,     0,     0,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,   113,  -100,    67,  -100,  -100,  -100,    70,    68,
      44,   -99,   -19,  -100,  -100,    81,    83,  -100,   -12,  -100,
    -100,    55,   -21,  -100,  -100,  -100,  -100,     3,    -8,   111,
    -100,   110,     4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    80,     8,    37,    38,    39,    81,
      82,    83,    84,    27,    28,    29,    30,    31,    32,    33,
      65,    66,    34,    85,    86,    87,    88,    89,    35,    36,
      10,    11,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,    16,    45,     9,    12,    46,    13,   109,   110,     9,
      12,    44,    23,   114,    94,     1,    24,   117,    48,    49,
       2,     3,    15,    25,    40,    42,    23,    45,    45,    45,
      24,    25,    57,    63,    64,    67,    15,    25,    62,    15,
      53,     1,    54,    76,    24,    77,     2,     3,    78,    79,
      15,    25,    47,    23,    64,    50,    52,    24,    95,    40,
      42,    68,   -22,    15,    25,    -4,     1,     7,    17,    51,
      55,     2,     3,     7,   102,    18,    56,   104,   105,    58,
       1,   101,    76,    68,    77,     2,     3,    78,    79,   111,
      19,    20,    23,    21,   115,    22,    24,   -60,    59,    72,
      68,    71,    15,    25,    19,    20,    49,    73,    75,    22,
      74,    93,   112,    91,    96,    97,   100,   103,    98,    14,
     108,   106,   107,    69,   113,   116,    70,    99,    92,    60,
       0,    41,    61,    43
};

static const yytype_int8 yycheck[] =
{
      19,     9,    23,     0,     0,    24,     0,   106,   107,     6,
       6,    23,    13,   112,    15,     1,    17,   116,    10,    11,
       6,     7,    23,    24,    21,    21,    13,    48,    49,    50,
      17,    24,    40,    52,    53,    54,    23,    24,    50,    23,
      17,     1,    19,     3,    17,     5,     6,     7,     8,     9,
      23,    24,    15,    13,    73,    12,    14,    17,    77,    56,
      56,    21,    22,    23,    24,     0,     1,     0,    15,    13,
      18,     6,     7,     6,    93,    22,    16,    96,    97,    20,
       1,    89,     3,    21,     5,     6,     7,     8,     9,   108,
      14,    15,    13,    17,   113,    19,    17,    23,    18,    15,
      21,    19,    23,    24,    14,    15,    11,    16,    20,    19,
      18,    17,     4,    20,    17,    17,    15,    15,    22,     6,
      15,    18,    18,    55,    15,    18,    56,    83,    73,    48,
      -1,    21,    49,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     6,     7,    27,    28,    29,    30,    31,    53,
      56,    57,    58,     0,    28,    23,    54,    15,    22,    14,
      15,    17,    19,    13,    17,    24,    38,    39,    40,    41,
      42,    43,    44,    45,    48,    54,    55,    32,    33,    34,
      53,    57,    58,    55,    44,    48,    38,    15,    10,    11,
      12,    13,    14,    17,    19,    18,    16,    54,    20,    18,
      41,    42,    44,    38,    38,    46,    47,    38,    21,    35,
      34,    19,    15,    16,    18,    20,     3,     5,     8,     9,
      30,    35,    36,    37,    38,    49,    50,    51,    52,    53,
      58,    20,    47,    17,    15,    38,    17,    17,    22,    36,
      15,    54,    38,    15,    38,    38,    18,    18,    15,    37,
      37,    38,     4,    15,    37,    38,    18,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    28,    28,    29,    29,    29,    29,    30,
      30,    30,    31,    32,    32,    33,    33,    34,    34,    34,
      35,    36,    36,    37,    37,    37,    37,    37,    37,    37,
      37,    38,    38,    39,    40,    40,    41,    41,    42,    42,
      43,    43,    43,    44,    44,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    51,    52,    52,
      53,    53,    54,    55,    56,    57,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     2,     2,     3,
       5,     6,     6,     1,     1,     3,     1,     2,     4,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     1,     3,     1,
       2,     2,     1,     3,     1,     1,     1,     4,     1,     0,
       3,     1,     1,     4,     2,     3,     5,     9,     7,     5,
       1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: decl_list  */
#line 54 "parser.y"
                            { root = (yyvsp[0].ast_node); }
#line 1208 "parser.c"
    break;

  case 3: /* decl_list: decl decl_list  */
#line 56 "parser.y"
                                 { (yyval.ast_node) = (yyvsp[0].ast_node); ast_node_preppend((yyval.ast_node), (yyvsp[-1].ast_node)); }
#line 1214 "parser.c"
    break;

  case 4: /* decl_list: %empty  */
#line 57 "parser.y"
                         { (yyval.ast_node) = ast_node_new(K_PROGRAM); }
#line 1220 "parser.c"
    break;

  case 9: /* var_decl: type_spec id SCOLON  */
#line 64 "parser.y"
                                      { (yyval.ast_node) = ast_node_make(K_VAR_DECL, 2, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node)); }
#line 1226 "parser.c"
    break;

  case 10: /* var_decl: type_spec id ASSIGN expr SCOLON  */
#line 65 "parser.y"
                                                  { (yyval.ast_node) = ast_node_make(K_VAR_DEFN, 3, (yyvsp[-4].ast_node), (yyvsp[-3].ast_node), (yyvsp[-1].ast_node)); }
#line 1232 "parser.c"
    break;

  case 11: /* var_decl: type_spec id LSBRACK num RSBRACK SCOLON  */
#line 66 "parser.y"
                                                          { (yyval.ast_node) = ast_node_make(K_LIST_DECL, 3, (yyvsp[-5].ast_node), (yyvsp[-4].ast_node), (yyvsp[-2].ast_node)); }
#line 1238 "parser.c"
    break;

  case 12: /* fun_decl: type_spec id LPAREN params RPAREN block  */
#line 68 "parser.y"
                                                          { (yyval.ast_node) = ast_node_make(K_FUN_DECL, 4, (yyvsp[-5].ast_node), (yyvsp[-4].ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1244 "parser.c"
    break;

  case 15: /* param_list: param_list COMMA param  */
#line 73 "parser.y"
                                         { (yyval.ast_node) = (yyvsp[-2].ast_node); ast_node_append((yyval.ast_node), (yyvsp[0].ast_node)); }
#line 1250 "parser.c"
    break;

  case 16: /* param_list: param  */
#line 74 "parser.y"
                        { (yyval.ast_node) = ast_node_make(K_PARAM_LIST, 1, (yyvsp[0].ast_node)); }
#line 1256 "parser.c"
    break;

  case 17: /* param: type_spec id  */
#line 76 "parser.y"
                               { (yyval.ast_node) = ast_node_make(K_PARAM, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node)); }
#line 1262 "parser.c"
    break;

  case 18: /* param: type_spec id LSBRACK RSBRACK  */
#line 77 "parser.y"
                                               { (yyval.ast_node) = ast_node_make(K_LIST_PARAM, 2, (yyvsp[-3].ast_node), (yyvsp[-2].ast_node)); }
#line 1268 "parser.c"
    break;

  case 20: /* block: LCBRACK stmt_list RCBRACK  */
#line 80 "parser.y"
                                            { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1274 "parser.c"
    break;

  case 21: /* stmt_list: stmt stmt_list  */
#line 82 "parser.y"
                                 { (yyval.ast_node) = (yyvsp[0].ast_node); ast_node_preppend((yyval.ast_node), (yyvsp[-1].ast_node)); }
#line 1280 "parser.c"
    break;

  case 22: /* stmt_list: %empty  */
#line 83 "parser.y"
                         { (yyval.ast_node) = ast_node_new(K_BLOCK); }
#line 1286 "parser.c"
    break;

  case 33: /* assign_expr: var ASSIGN expr  */
#line 97 "parser.y"
                                  { (yyval.ast_node) = ast_node_make(K_ASSIGN, 2, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1292 "parser.c"
    break;

  case 34: /* rel_expr: sum_expr RELOP sum_expr  */
#line 99 "parser.y"
                                          { (yyval.ast_node) = ast_node_make(K_RELOP, 2, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); (yyval.ast_node)->opval = ((yyvsp[-1].token)).opval; }
#line 1298 "parser.c"
    break;

  case 36: /* sum_expr: sum_expr ADDOP mul_expr  */
#line 102 "parser.y"
                                          { (yyval.ast_node) = ast_node_make(K_ADDOP, 2, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); (yyval.ast_node)->opval = ((yyvsp[-1].token)).opval; }
#line 1304 "parser.c"
    break;

  case 38: /* mul_expr: mul_expr MULOP factor  */
#line 105 "parser.y"
                                        { (yyval.ast_node) = ast_node_make(K_MULOP, 2, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); (yyval.ast_node)->opval = ((yyvsp[-1].token)).opval; }
#line 1310 "parser.c"
    break;

  case 40: /* inc_expr: INCOP factor  */
#line 108 "parser.y"
                               { (yyval.ast_node) = ast_node_make(K_INCOP, 1, (yyvsp[0].ast_node)); (yyval.ast_node)->opval = ((yyvsp[-1].token)).opval; }
#line 1316 "parser.c"
    break;

  case 41: /* inc_expr: factor INCOP  */
#line 109 "parser.y"
                               { (yyval.ast_node) = ast_node_make(K_INCOP, 1, (yyvsp[-1].ast_node)); (yyval.ast_node)->opval = ((yyvsp[0].token)).opval; }
#line 1322 "parser.c"
    break;

  case 43: /* factor: LPAREN expr RPAREN  */
#line 112 "parser.y"
                                     { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1328 "parser.c"
    break;

  case 47: /* funcall: id LPAREN args RPAREN  */
#line 117 "parser.y"
                                        { (yyval.ast_node) = ast_node_make(K_FUNCALL, 2, (yyvsp[-3].ast_node), (yyvsp[-1].ast_node)); }
#line 1334 "parser.c"
    break;

  case 49: /* args: %empty  */
#line 120 "parser.y"
                         { (yyval.ast_node) = ast_node_new(K_ARG_LIST); }
#line 1340 "parser.c"
    break;

  case 50: /* arg_list: expr COMMA arg_list  */
#line 122 "parser.y"
                                      { (yyval.ast_node) = (yyvsp[0].ast_node); ast_node_preppend((yyval.ast_node), (yyvsp[-2].ast_node)); }
#line 1346 "parser.c"
    break;

  case 51: /* arg_list: expr  */
#line 123 "parser.y"
                       { (yyval.ast_node) = ast_node_make(K_ARG_LIST, 1, (yyvsp[0].ast_node)); }
#line 1352 "parser.c"
    break;

  case 53: /* var: id LSBRACK expr RSBRACK  */
#line 126 "parser.y"
                                          { (yyval.ast_node) = ast_node_make(K_AREF, 2, (yyvsp[-3].ast_node), (yyvsp[-1].ast_node)); }
#line 1358 "parser.c"
    break;

  case 54: /* return_stmt: RETURN SCOLON  */
#line 129 "parser.y"
                                { (yyval.ast_node) = ast_node_new(K_RETURN); }
#line 1364 "parser.c"
    break;

  case 55: /* return_stmt: RETURN expr SCOLON  */
#line 130 "parser.y"
                                     { (yyval.ast_node) = ast_node_make(K_RETURN_EXPR, 1, (yyvsp[-1].ast_node)); }
#line 1370 "parser.c"
    break;

  case 56: /* while_stmt: WHILE LPAREN expr RPAREN stmt  */
#line 132 "parser.y"
                                                { (yyval.ast_node) = ast_node_make(K_WHILE, 2, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1376 "parser.c"
    break;

  case 57: /* for_stmt: FOR LPAREN expr SCOLON expr SCOLON expr RPAREN stmt  */
#line 134 "parser.y"
                                                                      { (yyval.ast_node) = ast_node_make(K_FOR, 4, (yyvsp[-6].ast_node), (yyvsp[-4].ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1382 "parser.c"
    break;

  case 58: /* if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt  */
#line 136 "parser.y"
                                                       { (yyval.ast_node) = ast_node_make(K_IF_ELSE, 3, (yyvsp[-4].ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1388 "parser.c"
    break;

  case 59: /* if_stmt: IF LPAREN expr RPAREN stmt  */
#line 137 "parser.y"
                                             { (yyval.ast_node) = ast_node_make(K_IF, 2, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1394 "parser.c"
    break;

  case 62: /* id: ID  */
#line 142 "parser.y"
                     { (yyval.ast_node) = ast_node_new(K_ID); (yyval.ast_node)->strval = ((yyvsp[0].token)).strval; }
#line 1400 "parser.c"
    break;

  case 63: /* num: NUM  */
#line 143 "parser.y"
                      { (yyval.ast_node) = ast_node_new(K_NUM); (yyval.ast_node)->intval = ((yyvsp[0].token)).intval; }
#line 1406 "parser.c"
    break;

  case 64: /* int: INT  */
#line 144 "parser.y"
                      { (yyval.ast_node) = ast_node_new(K_INT); }
#line 1412 "parser.c"
    break;

  case 65: /* void: VOID  */
#line 145 "parser.y"
                       { (yyval.ast_node) = ast_node_new(K_VOID); }
#line 1418 "parser.c"
    break;

  case 66: /* err: error  */
#line 147 "parser.y"
                        { (yyval.ast_node) = ast_node_new(K_ERROR); }
#line 1424 "parser.c"
    break;


#line 1428 "parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 149 "parser.y"


void yyerror(const char *error) {
    printf("ERROR: %s\n", error);
}

char *token_str(enum yytokentype token) {
    switch (token) {
        case IF: return "IF";
        case ELSE: return "ELSE";
        case RETURN: return "RETURN";
        case INT: return "INT";
        case VOID: return "VOID";
        case WHILE: return "WHILE";
        case FOR: return "FOR";
        case RELOP: return "RELOP";
        case ADDOP: return "ADDOP";
        case MULOP: return "MULOP";
        case ASSIGN: return "ASSIGN";
        case SCOLON: return "SCOLON";
        case COMMA: return "COMMA";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case LSBRACK: return "LSBRACK";
        case RSBRACK: return "RSBRACK";
        case LCBRACK: return "LCBRACK";
        case RCBRACK: return "RCBRACK";
        case ID: return "ID";
        case NUM: return "NUM";
        case ERROR: return "ERROR";
    }
}
