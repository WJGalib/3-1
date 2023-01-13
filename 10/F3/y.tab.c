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
#line 1 "1905084.y"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include "1905084_SymbolTable.hpp"

using namespace std;

int yyparse(void);
int yylex(void);

int line_count = 1, err_count = 0;
extern FILE *yyin;
FILE *fp, *parseout, *logout;

extern SymbolTable* table;
ArrayList<SymbolInfo*> *var_list;

char  *NON_TERMINAL, *start, *program, *unit, *func_declaration, *func_definition, *parameter_list, *compound_statement, 
	  *var_declaration, *type_specifier, *declaration_list, *statements, *statement, *expression_statement, *variable, *expression, 
	  *logic_expression, *rel_expression, *simple_expression, *term, *unary_expression, *factor, *argument_list, *arguments;

void yyerror(char *s) {
	//write your code
};

// void add_children (SymbolInfo* parent, char* name, int n, ... ) {
// 	parent = new SymbolInfo (name, NON_TERMINAL);
// 	va_list list;
// 	va_start (list, n);
// 	for (int i=0; i<n; i++) parent->addChild (va_arg(list, SymbolInfo*));
// 	va_end(list);
// };

void fprint_rule (SymbolInfo* lhs, FILE* fp) {
	fprintf(fp, "%s : ", lhs->getName());
	ArrayList<SymbolInfo*> *children = lhs->getChildren();
	if (!children) return;
	for (children->moveToStart(); children->currPos() < children->length(); children->next()) {
		//insert into symbol table
		SymbolInfo* x = children->getValue();
		if (x->getType() == NON_TERMINAL) fprintf(fp, "%s ", x->getName());
		else fprintf(fp, "%s ", x->getType());
	};
}

void log_rule (SymbolInfo* lhs) {
	fprint_rule (lhs, logout);
	fprintf(logout, "\n");
};

void add_children_and_log (SymbolInfo** parent, char* name, int n, ... ) {
	*parent = new SymbolInfo (name, NON_TERMINAL);
	//cout << (*parent)->getName() << endl;
	va_list list;
	va_start (list, n);
	for (int i=0; i<n; i++) {
		SymbolInfo* x = *(va_arg(list, SymbolInfo**));
		(*parent)->addChild(x);
		//cout << "\t" << x->getType() << endl;
		if (i == 0) (*parent)->setStartLine (x->getStartLine());
		(*parent)->setEndLine (x->getEndLine());
	};
	va_end(list);
	log_rule (*parent);
};

void print_parse_tree (SymbolInfo* symbol, int depth = 0) {
	if (!symbol) return;
	for (int i=0; i<depth; i++) fprintf(parseout, " ");

	if (symbol->getType() == NON_TERMINAL) {
		fprint_rule (symbol, parseout);
		fprintf(parseout, "\t<Line: %d-%d>\n", symbol->getStartLine(), symbol->getEndLine());
		ArrayList<SymbolInfo*> *children = symbol->getChildren();
		if (!children) return;
		for (children->moveToStart(); children->currPos() < children->length(); children->next()) {
			SymbolInfo* x = children->getValue();
			if (x) print_parse_tree (children->getValue(), depth + 1);
		};
	} else {
		fprintf(parseout, "%s : %s", symbol->getType(), symbol->getName());
		fprintf(parseout, "\t<Line: %d>\n", symbol->getStartLine());
	}
};

// void print_parse_tree (SymbolInfo** symbol, int depth = 1) {
// 	print_parse_tree (*symbol, depth);
// }


#line 166 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    DOUBLE = 264,                  /* DOUBLE  */
    CHAR = 265,                    /* CHAR  */
    VOID = 266,                    /* VOID  */
    RETURN = 267,                  /* RETURN  */
    ADDOP = 268,                   /* ADDOP  */
    MULOP = 269,                   /* MULOP  */
    INCOP = 270,                   /* INCOP  */
    DECOP = 271,                   /* DECOP  */
    LOGICOP = 272,                 /* LOGICOP  */
    RELOP = 273,                   /* RELOP  */
    ASSIGNOP = 274,                /* ASSIGNOP  */
    BITOP = 275,                   /* BITOP  */
    NOT = 276,                     /* NOT  */
    LPAREN = 277,                  /* LPAREN  */
    RPAREN = 278,                  /* RPAREN  */
    LCURL = 279,                   /* LCURL  */
    RCURL = 280,                   /* RCURL  */
    LTHIRD = 281,                  /* LTHIRD  */
    RTHIRD = 282,                  /* RTHIRD  */
    COMMA = 283,                   /* COMMA  */
    SEMICOLON = 284,               /* SEMICOLON  */
    CONST_INT = 285,               /* CONST_INT  */
    CONST_FLOAT = 286,             /* CONST_FLOAT  */
    CONST_CHAR = 287,              /* CONST_CHAR  */
    SINGLE_LINE_STRING = 288,      /* SINGLE_LINE_STRING  */
    MULTI_LINE_STRING = 289,       /* MULTI_LINE_STRING  */
    ID = 290,                      /* ID  */
    PRINTLN = 291                  /* PRINTLN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define INT 262
#define FLOAT 263
#define DOUBLE 264
#define CHAR 265
#define VOID 266
#define RETURN 267
#define ADDOP 268
#define MULOP 269
#define INCOP 270
#define DECOP 271
#define LOGICOP 272
#define RELOP 273
#define ASSIGNOP 274
#define BITOP 275
#define NOT 276
#define LPAREN 277
#define RPAREN 278
#define LCURL 279
#define RCURL 280
#define LTHIRD 281
#define RTHIRD 282
#define COMMA 283
#define SEMICOLON 284
#define CONST_INT 285
#define CONST_FLOAT 286
#define CONST_CHAR 287
#define SINGLE_LINE_STRING 288
#define MULTI_LINE_STRING 289
#define ID 290
#define PRINTLN 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 96 "1905084.y"

	SymbolInfo* symbol;

#line 295 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_ADDOP = 13,                     /* ADDOP  */
  YYSYMBOL_MULOP = 14,                     /* MULOP  */
  YYSYMBOL_INCOP = 15,                     /* INCOP  */
  YYSYMBOL_DECOP = 16,                     /* DECOP  */
  YYSYMBOL_LOGICOP = 17,                   /* LOGICOP  */
  YYSYMBOL_RELOP = 18,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 19,                  /* ASSIGNOP  */
  YYSYMBOL_BITOP = 20,                     /* BITOP  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LCURL = 24,                     /* LCURL  */
  YYSYMBOL_RCURL = 25,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 26,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 27,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_CONST_INT = 30,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 31,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHAR = 32,                /* CONST_CHAR  */
  YYSYMBOL_SINGLE_LINE_STRING = 33,        /* SINGLE_LINE_STRING  */
  YYSYMBOL_MULTI_LINE_STRING = 34,         /* MULTI_LINE_STRING  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_PRINTLN = 36,                   /* PRINTLN  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_start = 38,                     /* start  */
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_unit = 40,                      /* unit  */
  YYSYMBOL_func_declaration = 41,          /* func_declaration  */
  YYSYMBOL_func_definition = 42,           /* func_definition  */
  YYSYMBOL_parameter_list = 43,            /* parameter_list  */
  YYSYMBOL_compound_statement = 44,        /* compound_statement  */
  YYSYMBOL_var_declaration = 45,           /* var_declaration  */
  YYSYMBOL_type_specifier = 46,            /* type_specifier  */
  YYSYMBOL_declaration_list = 47,          /* declaration_list  */
  YYSYMBOL_statements = 48,                /* statements  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_expression_statement = 50,      /* expression_statement  */
  YYSYMBOL_variable = 51,                  /* variable  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_logic_expression = 53,          /* logic_expression  */
  YYSYMBOL_rel_expression = 54,            /* rel_expression  */
  YYSYMBOL_simple_expression = 55,         /* simple_expression  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_unary_expression = 57,          /* unary_expression  */
  YYSYMBOL_factor = 58,                    /* factor  */
  YYSYMBOL_argument_list = 59,             /* argument_list  */
  YYSYMBOL_arguments = 60                  /* arguments  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   112,   112,   118,   119,   122,   123,   124,   127,   128,
     131,   132,   136,   137,   138,   139,   143,   144,   147,   155,
     156,   157,   160,   164,   169,   174,   182,   183,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   197,   198,   201,
     202,   205,   206,   209,   210,   213,   214,   217,   218,   221,
     222,   225,   226,   227,   230,   231,   232,   233,   234,   235,
     236,   239,   242,   243
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "INT", "FLOAT", "DOUBLE", "CHAR", "VOID", "RETURN", "ADDOP",
  "MULOP", "INCOP", "DECOP", "LOGICOP", "RELOP", "ASSIGNOP", "BITOP",
  "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "CONST_INT", "CONST_FLOAT", "CONST_CHAR",
  "SINGLE_LINE_STRING", "MULTI_LINE_STRING", "ID", "PRINTLN", "$accept",
  "start", "program", "unit", "func_declaration", "func_definition",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,   -68,   -68,   -68,    34,    42,   -68,   -68,   -68,   -68,
     -12,   -68,   -68,    16,    23,    97,    14,    19,   -68,   -13,
      -8,    28,    47,    61,    54,   -68,   -68,    -7,    42,   -68,
     -68,    50,    55,    85,    89,    51,    51,    51,    51,   -68,
     -68,   -68,   -68,    66,    92,   -68,   -68,    80,    88,   -68,
     -68,    87,    93,   -68,    99,    12,   107,   -68,   -68,   -68,
     -68,    91,   104,    51,    -3,    51,   103,    82,   -68,   -68,
     113,    51,    51,   102,   112,   -68,   -68,   -68,   -68,    51,
     -68,    51,    51,    51,    51,   -68,   -68,   116,    -3,   117,
     -68,   -68,   -68,   118,   114,   120,   125,   -68,   -68,   107,
     132,   -68,   122,    51,   122,   -68,    51,   -68,   121,   145,
     131,   -68,   -68,   -68,   122,   122,   -68,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    19,    20,    21,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    24,     0,     0,     0,     0,    18,     0,
       0,    15,     0,    22,     0,     9,    11,     0,     0,    14,
      25,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      37,    57,    58,    39,     0,    30,    28,     0,     0,    26,
      29,    54,     0,    41,    43,    45,    47,    49,    53,     8,
      10,    13,     0,     0,     0,     0,     0,    54,    51,    52,
       0,     0,     0,     0,    24,    16,    27,    59,    60,     0,
      38,     0,     0,     0,     0,    12,    23,     0,     0,     0,
      36,    56,    63,     0,    61,     0,     0,    42,    44,    48,
      46,    50,     0,     0,     0,    55,     0,    40,     0,    32,
       0,    34,    62,    35,     0,     0,    33,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   150,   -68,   -68,   -68,    -6,    36,     9,
     -68,   -68,   -46,   -59,   -36,   -32,   -67,    75,    76,    78,
     -29,   -68,   -68,   -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    20,    45,    46,    47,
      14,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    93,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    67,    76,    66,    92,    88,    70,    68,    69,    10,
      36,    24,    97,    26,    10,    27,    25,    24,    37,    38,
      28,    60,    59,    13,    21,    82,    40,    41,    42,   103,
      83,    87,    43,    89,    11,    67,     9,    61,    15,   112,
      95,     9,    16,    67,    22,    67,    67,    67,    67,     1,
       2,    17,    18,     3,    23,   101,   109,    32,   111,    33,
      34,     1,     2,    29,    36,     3,    35,    36,   116,   117,
      67,   110,    37,    38,    30,    37,    38,    63,    24,    39,
      62,    41,    42,    40,    41,    42,    43,    31,    71,    43,
      44,    32,    72,    33,    34,     1,     2,    77,    78,     3,
      35,    36,    77,    78,     1,     2,    79,    64,     3,    37,
      38,    65,    24,    75,    73,    74,    81,    40,    41,    42,
      19,    84,    80,    43,    44,    32,    85,    33,    34,     1,
       2,    86,    90,     3,    35,    36,    91,    96,    16,   102,
     104,   105,   106,    37,    38,    82,    24,   107,   108,   114,
     113,    40,    41,    42,   115,    12,    98,    43,    44,   100,
      99
};

static const yytype_int8 yycheck[] =
{
      36,    37,    48,    35,    71,    64,    38,    36,    37,     0,
      13,    24,    79,    19,     5,    23,    29,    24,    21,    22,
      28,    27,    29,    35,    15,    13,    29,    30,    31,    88,
      18,    63,    35,    65,     0,    71,     0,    28,    22,   106,
      72,     5,    26,    79,    30,    81,    82,    83,    84,     7,
       8,    28,    29,    11,    35,    84,   102,     3,   104,     5,
       6,     7,     8,    35,    13,    11,    12,    13,   114,   115,
     106,   103,    21,    22,    27,    21,    22,    22,    24,    25,
      30,    30,    31,    29,    30,    31,    35,    26,    22,    35,
      36,     3,    26,     5,     6,     7,     8,    15,    16,    11,
      12,    13,    15,    16,     7,     8,    19,    22,    11,    21,
      22,    22,    24,    25,    22,    35,    17,    29,    30,    31,
      23,    14,    29,    35,    36,     3,    35,     5,     6,     7,
       8,    27,    29,    11,    12,    13,    23,    35,    26,    23,
      23,    23,    28,    21,    22,    13,    24,    27,    23,     4,
      29,    29,    30,    31,    23,     5,    81,    35,    36,    83,
      82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    11,    38,    39,    40,    41,    42,    45,
      46,     0,    40,    35,    47,    22,    26,    28,    29,    23,
      43,    46,    30,    35,    24,    29,    44,    23,    28,    35,
      27,    26,     3,     5,     6,    12,    13,    21,    22,    25,
      29,    30,    31,    35,    36,    44,    45,    46,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    29,
      44,    46,    30,    22,    22,    22,    52,    51,    57,    57,
      52,    22,    26,    22,    35,    25,    49,    15,    16,    19,
      29,    17,    13,    18,    14,    35,    27,    52,    50,    52,
      29,    23,    53,    59,    60,    52,    35,    53,    54,    56,
      55,    57,    23,    50,    23,    23,    28,    27,    23,    49,
      52,    49,    53,    29,     4,    23,    49,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    41,    41,
      42,    42,    43,    43,    43,    43,    44,    44,    45,    46,
      46,    46,    47,    47,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    59,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     3,     2,     3,     1,
       1,     1,     3,     6,     1,     4,     1,     2,     1,     1,
       1,     7,     5,     7,     5,     5,     3,     1,     2,     1,
       4,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     1,     1,     4,     3,     1,     1,     2,
       2,     1,     3,     1
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
  case 2: /* start: program  */
#line 112 "1905084.y"
                {
		add_children_and_log (&(yyval.symbol), start, 1, &(yyvsp[0].symbol));
		print_parse_tree ((yyval.symbol));
	}
#line 1424 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 118 "1905084.y"
                       { add_children_and_log (&(yyval.symbol), program, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1430 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 119 "1905084.y"
               { add_children_and_log (&(yyval.symbol), program, 1, &(yyvsp[0].symbol)); }
#line 1436 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 122 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), unit, 1, &(yyvsp[0].symbol)); }
#line 1442 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 123 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), unit, 1, &(yyvsp[0].symbol)); }
#line 1448 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 124 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), unit, 1, &(yyvsp[0].symbol)); }
#line 1454 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 127 "1905084.y"
                                                                            { add_children_and_log (&(yyval.symbol), func_declaration, 6, &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1460 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 128 "1905084.y"
                                                             { add_children_and_log (&(yyval.symbol), func_declaration, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1466 "y.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement  */
#line 131 "1905084.y"
                                                                                    { add_children_and_log (&(yyval.symbol), func_definition, 6, &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1472 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN RPAREN compound_statement  */
#line 132 "1905084.y"
                                                                     { add_children_and_log (&(yyval.symbol), func_definition, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1478 "y.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 136 "1905084.y"
                                                          { add_children_and_log (&(yyval.symbol), parameter_list, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1484 "y.tab.c"
    break;

  case 13: /* parameter_list: parameter_list COMMA type_specifier  */
#line 137 "1905084.y"
                                                      { add_children_and_log (&(yyval.symbol), parameter_list, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1490 "y.tab.c"
    break;

  case 14: /* parameter_list: type_specifier ID  */
#line 138 "1905084.y"
                                    { add_children_and_log (&(yyval.symbol), parameter_list, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1496 "y.tab.c"
    break;

  case 15: /* parameter_list: type_specifier  */
#line 139 "1905084.y"
                                 { add_children_and_log (&(yyval.symbol), parameter_list, 1, &(yyvsp[0].symbol)); }
#line 1502 "y.tab.c"
    break;

  case 16: /* compound_statement: LCURL statements RCURL  */
#line 143 "1905084.y"
                                             { add_children_and_log (&(yyval.symbol), compound_statement, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1508 "y.tab.c"
    break;

  case 17: /* compound_statement: LCURL RCURL  */
#line 144 "1905084.y"
                                  { add_children_and_log (&(yyval.symbol), compound_statement, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1514 "y.tab.c"
    break;

  case 18: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 147 "1905084.y"
                                                            {
			add_children_and_log (&(yyval.symbol), var_declaration, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			for (var_list->moveToStart(); var_list->currPos() < var_list->length(); var_list->next()) {
				//insert into symbol table
			};
		 }
#line 1525 "y.tab.c"
    break;

  case 19: /* type_specifier: INT  */
#line 155 "1905084.y"
                      { add_children_and_log (&(yyval.symbol), type_specifier, 1, &(yyvsp[0].symbol)); }
#line 1531 "y.tab.c"
    break;

  case 20: /* type_specifier: FLOAT  */
#line 156 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), type_specifier, 1, &(yyvsp[0].symbol)); }
#line 1537 "y.tab.c"
    break;

  case 21: /* type_specifier: VOID  */
#line 157 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), type_specifier, 1, &(yyvsp[0].symbol)); }
#line 1543 "y.tab.c"
    break;

  case 22: /* declaration_list: declaration_list COMMA ID  */
#line 160 "1905084.y"
                                             {
			add_children_and_log (&(yyval.symbol), declaration_list, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			// var_list->append($3);
		  }
#line 1552 "y.tab.c"
    break;

  case 23: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 164 "1905084.y"
                                                                      {
			add_children_and_log (&(yyval.symbol), declaration_list, 6, &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			// $3->setArray();
			// var_list->append($3);
		  }
#line 1562 "y.tab.c"
    break;

  case 24: /* declaration_list: ID  */
#line 169 "1905084.y"
                       {
			add_children_and_log (&(yyval.symbol), declaration_list, 1, &(yyvsp[0].symbol));
			var_list = new ArrayList<SymbolInfo*>();
			// var_list->append($1);
		  }
#line 1572 "y.tab.c"
    break;

  case 25: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 174 "1905084.y"
                                               {
			add_children_and_log (&(yyval.symbol), declaration_list, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			var_list = new ArrayList<SymbolInfo*>();
			// $3->setArray();
			// var_list->append($1);
		  }
#line 1583 "y.tab.c"
    break;

  case 26: /* statements: statement  */
#line 182 "1905084.y"
                       { add_children_and_log (&(yyval.symbol), statements, 1, &(yyvsp[0].symbol)); }
#line 1589 "y.tab.c"
    break;

  case 27: /* statements: statements statement  */
#line 183 "1905084.y"
                                  { add_children_and_log (&(yyval.symbol), statements, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1595 "y.tab.c"
    break;

  case 28: /* statement: var_declaration  */
#line 186 "1905084.y"
                            { add_children_and_log (&(yyval.symbol), statement, 1, &(yyvsp[0].symbol)); }
#line 1601 "y.tab.c"
    break;

  case 29: /* statement: expression_statement  */
#line 187 "1905084.y"
                                 { add_children_and_log (&(yyval.symbol), statement, 1, &(yyvsp[0].symbol)); }
#line 1607 "y.tab.c"
    break;

  case 30: /* statement: compound_statement  */
#line 188 "1905084.y"
                               { add_children_and_log (&(yyval.symbol), statement, 1, &(yyvsp[0].symbol)); }
#line 1613 "y.tab.c"
    break;

  case 31: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 189 "1905084.y"
                                                                                             { add_children_and_log (&(yyval.symbol), statement, 7, &(yyvsp[-6].symbol), &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1619 "y.tab.c"
    break;

  case 32: /* statement: IF LPAREN expression RPAREN statement  */
#line 190 "1905084.y"
                                                  { add_children_and_log (&(yyval.symbol), statement, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1625 "y.tab.c"
    break;

  case 33: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 191 "1905084.y"
                                                                 { add_children_and_log (&(yyval.symbol), statement, 7, &(yyvsp[-6].symbol), &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1631 "y.tab.c"
    break;

  case 34: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 192 "1905084.y"
                                                     { add_children_and_log (&(yyval.symbol), statement, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1637 "y.tab.c"
    break;

  case 35: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 193 "1905084.y"
                                               { add_children_and_log (&(yyval.symbol), statement, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1643 "y.tab.c"
    break;

  case 36: /* statement: RETURN expression SEMICOLON  */
#line 194 "1905084.y"
                                        { add_children_and_log (&(yyval.symbol), statement, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1649 "y.tab.c"
    break;

  case 37: /* expression_statement: SEMICOLON  */
#line 197 "1905084.y"
                                 { add_children_and_log (&(yyval.symbol), expression_statement, 1, &(yyvsp[0].symbol)); }
#line 1655 "y.tab.c"
    break;

  case 38: /* expression_statement: expression SEMICOLON  */
#line 198 "1905084.y"
                                                { add_children_and_log (&(yyval.symbol), expression_statement, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1661 "y.tab.c"
    break;

  case 39: /* variable: ID  */
#line 201 "1905084.y"
              { add_children_and_log (&(yyval.symbol), variable, 1, &(yyvsp[0].symbol)); }
#line 1667 "y.tab.c"
    break;

  case 40: /* variable: ID LTHIRD expression RTHIRD  */
#line 202 "1905084.y"
                                       { add_children_and_log (&(yyval.symbol), variable, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1673 "y.tab.c"
    break;

  case 41: /* expression: logic_expression  */
#line 205 "1905084.y"
                              { add_children_and_log (&(yyval.symbol), expression, 1, &(yyvsp[0].symbol)); }
#line 1679 "y.tab.c"
    break;

  case 42: /* expression: variable ASSIGNOP logic_expression  */
#line 206 "1905084.y"
                                                { add_children_and_log (&(yyval.symbol), expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1685 "y.tab.c"
    break;

  case 43: /* logic_expression: rel_expression  */
#line 209 "1905084.y"
                                        { add_children_and_log (&(yyval.symbol), logic_expression, 1, &(yyvsp[0].symbol)); }
#line 1691 "y.tab.c"
    break;

  case 44: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 210 "1905084.y"
                                                         { add_children_and_log (&(yyval.symbol), logic_expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1697 "y.tab.c"
    break;

  case 45: /* rel_expression: simple_expression  */
#line 213 "1905084.y"
                                    { add_children_and_log (&(yyval.symbol), rel_expression, 1, &(yyvsp[0].symbol)); }
#line 1703 "y.tab.c"
    break;

  case 46: /* rel_expression: simple_expression RELOP simple_expression  */
#line 214 "1905084.y"
                                                                { add_children_and_log (&(yyval.symbol), rel_expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1709 "y.tab.c"
    break;

  case 47: /* simple_expression: term  */
#line 217 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), simple_expression, 1, &(yyvsp[0].symbol)); }
#line 1715 "y.tab.c"
    break;

  case 48: /* simple_expression: simple_expression ADDOP term  */
#line 218 "1905084.y"
                                                 { add_children_and_log (&(yyval.symbol), simple_expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1721 "y.tab.c"
    break;

  case 49: /* term: unary_expression  */
#line 221 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), term, 1, &(yyvsp[0].symbol)); }
#line 1727 "y.tab.c"
    break;

  case 50: /* term: term MULOP unary_expression  */
#line 222 "1905084.y"
                                     { add_children_and_log (&(yyval.symbol), term, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1733 "y.tab.c"
    break;

  case 51: /* unary_expression: ADDOP unary_expression  */
#line 225 "1905084.y"
                                           { add_children_and_log (&(yyval.symbol), unary_expression, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1739 "y.tab.c"
    break;

  case 52: /* unary_expression: NOT unary_expression  */
#line 226 "1905084.y"
                                        { add_children_and_log (&(yyval.symbol), unary_expression, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1745 "y.tab.c"
    break;

  case 53: /* unary_expression: factor  */
#line 227 "1905084.y"
                          { add_children_and_log (&(yyval.symbol), unary_expression, 1, &(yyvsp[0].symbol)); }
#line 1751 "y.tab.c"
    break;

  case 54: /* factor: variable  */
#line 230 "1905084.y"
                   { add_children_and_log (&(yyval.symbol), factor, 1, &(yyvsp[0].symbol)); }
#line 1757 "y.tab.c"
    break;

  case 55: /* factor: ID LPAREN argument_list RPAREN  */
#line 231 "1905084.y"
                                         { add_children_and_log (&(yyval.symbol), factor, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1763 "y.tab.c"
    break;

  case 56: /* factor: LPAREN expression RPAREN  */
#line 232 "1905084.y"
                                   { add_children_and_log (&(yyval.symbol), factor, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1769 "y.tab.c"
    break;

  case 57: /* factor: CONST_INT  */
#line 233 "1905084.y"
                     { add_children_and_log (&(yyval.symbol), factor, 1, &(yyvsp[0].symbol)); }
#line 1775 "y.tab.c"
    break;

  case 58: /* factor: CONST_FLOAT  */
#line 234 "1905084.y"
                      { add_children_and_log (&(yyval.symbol), factor, 1, &(yyvsp[0].symbol)); }
#line 1781 "y.tab.c"
    break;

  case 59: /* factor: variable INCOP  */
#line 235 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), factor, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1787 "y.tab.c"
    break;

  case 60: /* factor: variable DECOP  */
#line 236 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), factor, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1793 "y.tab.c"
    break;

  case 61: /* argument_list: arguments  */
#line 239 "1905084.y"
                          { add_children_and_log (&(yyval.symbol), argument_list, 1, &(yyvsp[0].symbol)); }
#line 1799 "y.tab.c"
    break;

  case 62: /* arguments: arguments COMMA logic_expression  */
#line 242 "1905084.y"
                                             { add_children_and_log (&(yyval.symbol), arguments, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1805 "y.tab.c"
    break;

  case 63: /* arguments: logic_expression  */
#line 243 "1905084.y"
                                 { add_children_and_log (&(yyval.symbol), arguments, 1, &(yyvsp[0].symbol)); }
#line 1811 "y.tab.c"
    break;


#line 1815 "y.tab.c"

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

#line 247 "1905084.y"

int main (int argc, char *argv[]) {
	fp = fopen(argv[1],"r");
	if (!fp) {
		printf("Cannot Open Input File.\n");
		exit(1);
	};

	parseout = fopen(argv[2],"w");
	/* fclose(fp2); */
	logout = fopen(argv[3],"w");
	/* fclose(fp3); */
	
	/* fp2= fopen(argv[2],"a");
	fp3= fopen(argv[3],"a"); */
	
	NON_TERMINAL = new char[20], strcpy (NON_TERMINAL, "NON_TERMINAL"); 
	start = new char[20], strcpy (start, "start"); 
	program = new char[20], strcpy (program, "program"); 
	unit = new char[20], strcpy (unit, "unit"); 
	func_declaration = new char[20], strcpy (func_declaration, "func_declaration"); 
	func_definition = new char[20], strcpy (func_definition, "func_definition"); 
	parameter_list = new char[20], strcpy (parameter_list, "parameter_list"); 
	compound_statement = new char[25], strcpy (compound_statement, "compound_statement"); 
	var_declaration = new char[20], strcpy (var_declaration, "var_declaration"); 
	type_specifier = new char[20], strcpy (type_specifier, "type_specifier"); 
	declaration_list = new char[20], strcpy (declaration_list, "declaration_list"); 
	statements = new char[20], strcpy (statements, "statements"); 
	statement = new char[20], strcpy (statement, "statement"); 
	expression_statement = new char[25], strcpy (expression_statement, "expression_statement"); 
	variable = new char[20], strcpy (variable, "variable"); 
	expression = new char[20], strcpy (expression, "expression"); 
	logic_expression = new char[20], strcpy (logic_expression, "logic_expression"); 
	rel_expression = new char[20], strcpy (rel_expression, "rel_expression"); 
	simple_expression = new char[20], strcpy (simple_expression, "simple_expression"); 
	term = new char[20], strcpy (term, "term"); 
	unary_expression = new char[20], strcpy (unary_expression, "unary_expression"); 
	factor = new char[20], strcpy (factor, "factor"); 
	argument_list = new char[20], strcpy (argument_list, "argument_list"); 
	arguments = new char[20], strcpy (arguments, "arguments"); 

	yyin = fp;
	yyparse();
 	fprintf(logout, "Total Lines: %d\n", line_count);
 	fprintf(logout, "Total Errors: %d\n", err_count);
	fclose(parseout), fclose(logout);
	
	return 0;
}

