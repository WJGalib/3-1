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
bool function_scope = false;
FILE *fp, *parseout, *errorout, *logout;

SymbolTable* st;
ArrayList<SymbolInfo*> *var_list, *param_list, *arg_list;

char  *NON_TERMINAL, *tINT, *tFLOAT, *tVOID, *start, *program, *unit, *func_declaration, *func_definition, *parameter_list, 
	  *compound_statement, *var_declaration, *type_specifier, *declaration_list, *statements, *statement, *expression_statement, 
	  *variable, *expression, *logic_expression, *rel_expression, *simple_expression, *term, *unary_expression, *factor, 
	  *argument_list, *arguments;

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

void transfer_semantic (SymbolInfo** parent, SymbolInfo** child) {
	//cout << "hello" <<endl;
	(*parent)->setSemanticType((*child)->getSemanticType());
	if ((*child)->isArray()) (*parent)->setArray();
	//cout << line_count << ": settign semantic type of " << (*parent)->getName() << " as " << (*child)->getSemanticType() << endl; 
	//fprintf(logout, "setting semantic type of %s as %s\n", (*parent)->getName(), (*child)->getSemanticType());
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

void print_error (const char* error) {
	fprintf (errorout, "Line# 20: %s", error); 
}

// void print_parse_tree (SymbolInfo** symbol, int depth = 1) {
// 	print_parse_tree (*symbol, depth);
// }


#line 180 "y.tab.c"

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
    LSQUARE = 281,                 /* LSQUARE  */
    RSQUARE = 282,                 /* RSQUARE  */
    COMMA = 283,                   /* COMMA  */
    SEMICOLON = 284,               /* SEMICOLON  */
    CONST_INT = 285,               /* CONST_INT  */
    CONST_FLOAT = 286,             /* CONST_FLOAT  */
    CONST_CHAR = 287,              /* CONST_CHAR  */
    SINGLE_LINE_STRING = 288,      /* SINGLE_LINE_STRING  */
    MULTI_LINE_STRING = 289,       /* MULTI_LINE_STRING  */
    ID = 290,                      /* ID  */
    PRINTLN = 291,                 /* PRINTLN  */
    LOWER_THAN_ELSE = 292          /* LOWER_THAN_ELSE  */
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
#define LSQUARE 281
#define RSQUARE 282
#define COMMA 283
#define SEMICOLON 284
#define CONST_INT 285
#define CONST_FLOAT 286
#define CONST_CHAR 287
#define SINGLE_LINE_STRING 288
#define MULTI_LINE_STRING 289
#define ID 290
#define PRINTLN 291
#define LOWER_THAN_ELSE 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 110 "1905084.y"

	SymbolInfo* symbol;

#line 311 "y.tab.c"

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
  YYSYMBOL_LSQUARE = 26,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 27,                   /* RSQUARE  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_CONST_INT = 30,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 31,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHAR = 32,                /* CONST_CHAR  */
  YYSYMBOL_SINGLE_LINE_STRING = 33,        /* SINGLE_LINE_STRING  */
  YYSYMBOL_MULTI_LINE_STRING = 34,         /* MULTI_LINE_STRING  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_PRINTLN = 36,                   /* PRINTLN  */
  YYSYMBOL_LOWER_THAN_ELSE = 37,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_start = 39,                     /* start  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_unit = 41,                      /* unit  */
  YYSYMBOL_func_declaration = 42,          /* func_declaration  */
  YYSYMBOL_func_definition = 43,           /* func_definition  */
  YYSYMBOL_start_func_scope = 44,          /* start_func_scope  */
  YYSYMBOL_parameter_list = 45,            /* parameter_list  */
  YYSYMBOL_compound_statement = 46,        /* compound_statement  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_var_declaration = 48,           /* var_declaration  */
  YYSYMBOL_type_specifier = 49,            /* type_specifier  */
  YYSYMBOL_declaration_list = 50,          /* declaration_list  */
  YYSYMBOL_statements = 51,                /* statements  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_expression_statement = 53,      /* expression_statement  */
  YYSYMBOL_variable = 54,                  /* variable  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_logic_expression = 56,          /* logic_expression  */
  YYSYMBOL_rel_expression = 57,            /* rel_expression  */
  YYSYMBOL_simple_expression = 58,         /* simple_expression  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_unary_expression = 60,          /* unary_expression  */
  YYSYMBOL_factor = 61,                    /* factor  */
  YYSYMBOL_argument_list = 62,             /* argument_list  */
  YYSYMBOL_arguments = 63                  /* arguments  */
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
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   131,   132,   135,   136,   137,   140,   156,
     165,   191,   202,   207,   213,   217,   224,   232,   232,   239,
     246,   267,   268,   269,   272,   276,   281,   286,   294,   295,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   309,
     310,   313,   325,   340,   345,   354,   355,   364,   365,   372,
     373,   376,   377,   384,   385,   390,   393,   394,   421,   422,
     423,   424,   425,   428,   431,   435
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
  "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LSQUARE", "RSQUARE",
  "COMMA", "SEMICOLON", "CONST_INT", "CONST_FLOAT", "CONST_CHAR",
  "SINGLE_LINE_STRING", "MULTI_LINE_STRING", "ID", "PRINTLN",
  "LOWER_THAN_ELSE", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "start_func_scope",
  "parameter_list", "compound_statement", "$@1", "var_declaration",
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

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,   -75,   -75,   -75,    11,    14,   -75,   -75,   -75,   -75,
      -3,   -75,   -75,     8,     9,     1,    30,    26,   -75,    34,
      14,    42,    48,   -75,    55,   -11,    45,   -75,    51,    57,
     -75,   -10,    14,   -75,    58,   -75,    99,   -75,   -75,    53,
     -75,    76,    77,    81,    27,    27,    27,    27,   -75,   -75,
     -75,    33,    86,   -75,   -75,    74,    65,   -75,   -75,    31,
      84,   -75,    97,     2,   101,   -75,   -75,   -75,    27,    62,
      27,    87,    37,   -75,   -75,    94,    27,    27,    83,    93,
     -75,   -75,   -75,   -75,    27,   -75,    27,    27,    27,    27,
     102,    62,   103,   -75,   -75,   -75,   104,    96,    95,   108,
     -75,   -75,   101,   119,   -75,    99,    27,    99,   -75,    27,
     -75,   107,   129,   114,   -75,   -75,   -75,    99,    99,   -75,
     -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    21,    22,    23,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    26,     0,    12,     0,     0,    20,    12,
       0,     0,    24,     9,     0,     0,    16,    27,     0,    17,
      11,     0,     0,    15,     0,    19,     0,     8,    10,    14,
      25,     0,     0,     0,     0,     0,     0,     0,    39,    59,
      60,    41,     0,    32,    30,     0,     0,    28,    31,    56,
       0,    43,    45,    47,    49,    51,    55,    13,     0,     0,
       0,     0,    56,    53,    54,     0,     0,     0,     0,    26,
      18,    29,    61,    62,     0,    40,     0,     0,     0,     0,
       0,     0,     0,    38,    58,    65,     0,    63,     0,     0,
      44,    46,    50,    48,    52,     0,     0,     0,    57,     0,
      42,     0,    34,     0,    36,    64,    37,     0,     0,    35,
      33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   133,   -75,   -75,   120,   -75,   -15,   -75,
      23,    13,   -75,   -75,   -51,   -65,   -45,   -41,   -74,    54,
      56,    59,   -38,   -75,   -75,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    20,    25,    53,    36,
      54,    55,    14,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    96,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    72,    95,    71,    91,    81,    75,    73,    74,    30,
     100,    11,    31,    10,    29,    87,    38,    32,    10,    37,
      88,     1,     2,     9,    19,     3,   106,    90,     9,    92,
      15,    72,    13,    26,    16,   115,    98,    17,    18,    72,
      45,    72,    72,    72,    72,    39,    82,    83,    46,    47,
      84,   104,    82,    83,   112,    76,   114,    49,    50,    77,
      21,    22,    51,    23,    72,   113,   119,   120,    41,    27,
      42,    43,     1,     2,    28,    45,     3,    44,    45,    29,
      33,    34,    35,    46,    47,    40,    46,    47,    67,    29,
      80,    48,    49,    50,    48,    49,    50,    51,    68,    69,
      51,    52,    41,    70,    42,    43,     1,     2,    78,    79,
       3,    44,    45,    85,    86,    89,    93,    94,    99,    16,
      46,    47,   110,    29,   109,   105,   107,   108,    48,    49,
      50,   111,    87,   117,    51,    52,   116,   118,    12,    24,
     101,     0,     0,     0,   103,     0,   102
};

static const yytype_int8 yycheck[] =
{
      45,    46,    76,    44,    69,    56,    47,    45,    46,    24,
      84,     0,    23,     0,    24,    13,    31,    28,     5,    29,
      18,     7,     8,     0,    23,    11,    91,    68,     5,    70,
      22,    76,    35,    20,    26,   109,    77,    28,    29,    84,
      13,    86,    87,    88,    89,    32,    15,    16,    21,    22,
      19,    89,    15,    16,   105,    22,   107,    30,    31,    26,
      30,    35,    35,    29,   109,   106,   117,   118,     3,    27,
       5,     6,     7,     8,    26,    13,    11,    12,    13,    24,
      35,    30,    25,    21,    22,    27,    21,    22,    35,    24,
      25,    29,    30,    31,    29,    30,    31,    35,    22,    22,
      35,    36,     3,    22,     5,     6,     7,     8,    22,    35,
      11,    12,    13,    29,    17,    14,    29,    23,    35,    26,
      21,    22,    27,    24,    28,    23,    23,    23,    29,    30,
      31,    23,    13,     4,    35,    36,    29,    23,     5,    19,
      86,    -1,    -1,    -1,    88,    -1,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    11,    39,    40,    41,    42,    43,    48,
      49,     0,    41,    35,    50,    22,    26,    28,    29,    23,
      44,    30,    35,    29,    44,    45,    49,    27,    26,    24,
      46,    23,    28,    35,    30,    25,    47,    29,    46,    49,
      27,     3,     5,     6,    12,    13,    21,    22,    29,    30,
      31,    35,    36,    46,    48,    49,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    35,    22,    22,
      22,    55,    54,    60,    60,    55,    22,    26,    22,    35,
      25,    52,    15,    16,    19,    29,    17,    13,    18,    14,
      55,    53,    55,    29,    23,    56,    62,    63,    55,    35,
      56,    57,    59,    58,    60,    23,    53,    23,    23,    28,
      27,    23,    52,    55,    52,    56,    29,     4,    23,    52,
      52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    43,    44,    45,    45,    45,    45,    47,    46,    46,
      48,    49,    49,    49,    50,    50,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     7,     5,
       7,     6,     0,     4,     3,     2,     1,     0,     4,     2,
       3,     1,     1,     1,     3,     6,     1,     4,     1,     2,
       1,     1,     1,     7,     5,     7,     5,     5,     3,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     3,     1
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
#line 125 "1905084.y"
                {
		add_children_and_log (&(yyval.symbol), start, 1, &(yyvsp[0].symbol));
		print_parse_tree ((yyval.symbol));
	}
#line 1443 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 131 "1905084.y"
                       { add_children_and_log (&(yyval.symbol), program, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1449 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 132 "1905084.y"
               { add_children_and_log (&(yyval.symbol), program, 1, &(yyvsp[0].symbol)); }
#line 1455 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 135 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), unit, 1, &(yyvsp[0].symbol)); }
#line 1461 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 136 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), unit, 1, &(yyvsp[0].symbol)); }
#line 1467 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 137 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), unit, 1, &(yyvsp[0].symbol)); }
#line 1473 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN start_func_scope parameter_list RPAREN SEMICOLON  */
#line 140 "1905084.y"
                                                                                             { 
			for (param_list->moveToStart(); param_list->currPos() < param_list->length(); param_list->next()) {
				SymbolInfo *param = param_list->getValue(), *lu = st->lookUpCurrentScope(param->getName());
				if (lu != nullptr) {
					fprintf (errorout, "Line# %d: Redefinition of parameter '%s'\n", lu->getStartLine(), param->getName()); 
					break;
				};
				st->insert(param);
			};
			transfer_semantic (&(yyvsp[-5].symbol), &(yyvsp[-6].symbol)), (yyvsp[-5].symbol)->setFunction(), (yyvsp[-5].symbol)->setParams (param_list);
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
			st->insertToParentScope((yyvsp[-5].symbol));
			//st->printAllScope(logout);
			st->exitScope();
			add_children_and_log (&(yyval.symbol), func_declaration, 6, &(yyvsp[-6].symbol), &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
		}
#line 1494 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 156 "1905084.y"
                                                             { 
			transfer_semantic (&(yyvsp[-3].symbol), &(yyvsp[-4].symbol)), (yyvsp[-3].symbol)->setFunction();
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
			st->insert((yyvsp[-3].symbol));
			//st->printAllScope(logout);
			add_children_and_log (&(yyval.symbol), func_declaration, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
		}
#line 1506 "y.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID LPAREN start_func_scope parameter_list RPAREN compound_statement  */
#line 165 "1905084.y"
                                                                                                     { 
			SymbolInfo* predefined = st->lookUp((yyvsp[-5].symbol)->getName());
			if (predefined) {
				if (predefined->isFunction()) {
					if (predefined->getSemanticType() != (yyvsp[-6].symbol)->getSemanticType() || predefined->getParams()->length() != param_list->length())
						fprintf (errorout, "Line# %d: Conflicting types for '%s'\n", (yyvsp[-5].symbol)->getStartLine(), predefined->getName()); 						
				} else {
					fprintf (errorout, "Line# %d: '%s' redeclared as different kind of symbol\n", (yyvsp[-5].symbol)->getStartLine(), predefined->getName()); 				
				};
			};
			for (param_list->moveToStart(); param_list->currPos() < param_list->length(); param_list->next()) {
				SymbolInfo* param = param_list->getValue();
				if (st->lookUpCurrentScope(param->getName())) {
					fprintf (errorout, "Line# %d: Redefinition of parameter '%s'\n", param->getStartLine(), param->getName()); 
					break;
				};
				st->insert(param);
			};
			transfer_semantic (&(yyvsp[-5].symbol), &(yyvsp[-6].symbol)), (yyvsp[-5].symbol)->setFunction(), (yyvsp[-5].symbol)->setParams (param_list);
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
			st->insertToParentScope((yyvsp[-5].symbol));
			st->printAllScope(logout);
			st->exitScope();
			function_scope = false;
			add_children_and_log (&(yyval.symbol), func_definition, 6, &(yyvsp[-6].symbol), &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
		}
#line 1537 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN RPAREN start_func_scope compound_statement  */
#line 191 "1905084.y"
                                                                                      { 
			transfer_semantic (&(yyvsp[-4].symbol), &(yyvsp[-5].symbol)), (yyvsp[-4].symbol)->setFunction();
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
			st->insertToParentScope((yyvsp[-4].symbol));
			st->printAllScope(logout);
			st->exitScope();
			function_scope = false;
			add_children_and_log (&(yyval.symbol), func_definition, 5, &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[0].symbol)); 
		}
#line 1551 "y.tab.c"
    break;

  case 12: /* start_func_scope: %empty  */
#line 202 "1905084.y"
                   {
	st->enterScope();
	function_scope = true ;
}
#line 1560 "y.tab.c"
    break;

  case 13: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 207 "1905084.y"
                                                          { 
			add_children_and_log (&(yyval.symbol), parameter_list, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			transfer_semantic (&(yyvsp[0].symbol), &(yyvsp[-1].symbol));
			 param_list->append((yyvsp[0].symbol));
			//cout << st->getCurrScopeId() << " " << $4->getName() << endl;
		}
#line 1571 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier  */
#line 213 "1905084.y"
                                                      { 
			add_children_and_log (&(yyval.symbol), parameter_list, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
			param_list->append((yyvsp[0].symbol));
		}
#line 1580 "y.tab.c"
    break;

  case 15: /* parameter_list: type_specifier ID  */
#line 217 "1905084.y"
                                    { 
			add_children_and_log (&(yyval.symbol), parameter_list, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
			param_list = new ArrayList<SymbolInfo*>();
			transfer_semantic (&(yyvsp[0].symbol), &(yyvsp[-1].symbol));
			param_list->append((yyvsp[0].symbol));
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
		}
#line 1592 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier  */
#line 224 "1905084.y"
                                 { 
			add_children_and_log (&(yyval.symbol), parameter_list, 1, &(yyvsp[0].symbol)); 
			param_list = new ArrayList<SymbolInfo*>();
			param_list->append((yyvsp[0].symbol));
		}
#line 1602 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 232 "1905084.y"
                           {if (!function_scope) st->enterScope();}
#line 1608 "y.tab.c"
    break;

  case 18: /* compound_statement: LCURL $@1 statements RCURL  */
#line 232 "1905084.y"
                                                                                      { 
				add_children_and_log (&(yyval.symbol), compound_statement, 3, &(yyvsp[-3].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
				if (!function_scope) {
					st->printAllScope(logout);
					st->exitScope();
				};
			}
#line 1620 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL RCURL  */
#line 239 "1905084.y"
                                  { 
				add_children_and_log (&(yyval.symbol), compound_statement, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
				st->enterScope();
				st->exitScope();
			}
#line 1630 "y.tab.c"
    break;

  case 20: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 246 "1905084.y"
                                                            {
			add_children_and_log (&(yyval.symbol), var_declaration, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			for (var_list->moveToStart(); var_list->currPos() < var_list->length(); var_list->next()) {
				SymbolInfo* var = var_list->getValue();
				if ((yyvsp[-2].symbol)->getSemanticType() == tVOID) {
					fprintf (errorout, "Line# %d: Variable or field '%s' decleared void\n", var->getStartLine(), var->getName()); 
					break;
				};
				SymbolInfo* predefined = st->lookUpCurrentScope(var->getName());
				if (predefined) {
					if (predefined->getSemanticType() != (yyvsp[-2].symbol)->getSemanticType())
						fprintf (errorout, "Line# %d: Conflicting types for '%s'\n", var->getStartLine(), predefined->getName()); 						
				};
				//var->setSemanticType ($1->getSemanticType());
				transfer_semantic (&var, &(yyvsp[-2].symbol));
				st->insert(var);
			};
			delete var_list;
		 }
#line 1654 "y.tab.c"
    break;

  case 21: /* type_specifier: INT  */
#line 267 "1905084.y"
                      { add_children_and_log (&(yyval.symbol), type_specifier, 1, &(yyvsp[0].symbol)), (yyval.symbol)->setSemanticType((yyvsp[0].symbol)->getType()); }
#line 1660 "y.tab.c"
    break;

  case 22: /* type_specifier: FLOAT  */
#line 268 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), type_specifier, 1, &(yyvsp[0].symbol)), (yyval.symbol)->setSemanticType((yyvsp[0].symbol)->getType()); }
#line 1666 "y.tab.c"
    break;

  case 23: /* type_specifier: VOID  */
#line 269 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), type_specifier, 1, &(yyvsp[0].symbol)), (yyval.symbol)->setSemanticType((yyvsp[0].symbol)->getType()); }
#line 1672 "y.tab.c"
    break;

  case 24: /* declaration_list: declaration_list COMMA ID  */
#line 272 "1905084.y"
                                             {
			add_children_and_log (&(yyval.symbol), declaration_list, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			var_list->append((yyvsp[0].symbol));
		  }
#line 1681 "y.tab.c"
    break;

  case 25: /* declaration_list: declaration_list COMMA ID LSQUARE CONST_INT RSQUARE  */
#line 276 "1905084.y"
                                                                        {
			add_children_and_log (&(yyval.symbol), declaration_list, 6, &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			(yyvsp[-3].symbol)->setArray();
			var_list->append((yyvsp[-3].symbol));
		  }
#line 1691 "y.tab.c"
    break;

  case 26: /* declaration_list: ID  */
#line 281 "1905084.y"
                       {
			add_children_and_log (&(yyval.symbol), declaration_list, 1, &(yyvsp[0].symbol));
			var_list = new ArrayList<SymbolInfo*>();
			var_list->append((yyvsp[0].symbol));
		  }
#line 1701 "y.tab.c"
    break;

  case 27: /* declaration_list: ID LSQUARE CONST_INT RSQUARE  */
#line 286 "1905084.y"
                                                 {
			add_children_and_log (&(yyval.symbol), declaration_list, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			var_list = new ArrayList<SymbolInfo*>();
			(yyvsp[-3].symbol)->setArray();
			var_list->append((yyvsp[-3].symbol));
		  }
#line 1712 "y.tab.c"
    break;

  case 28: /* statements: statement  */
#line 294 "1905084.y"
                       { add_children_and_log (&(yyval.symbol), statements, 1, &(yyvsp[0].symbol)); }
#line 1718 "y.tab.c"
    break;

  case 29: /* statements: statements statement  */
#line 295 "1905084.y"
                                  { add_children_and_log (&(yyval.symbol), statements, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1724 "y.tab.c"
    break;

  case 30: /* statement: var_declaration  */
#line 298 "1905084.y"
                            { add_children_and_log (&(yyval.symbol), statement, 1, &(yyvsp[0].symbol)); }
#line 1730 "y.tab.c"
    break;

  case 31: /* statement: expression_statement  */
#line 299 "1905084.y"
                                 { add_children_and_log (&(yyval.symbol), statement, 1, &(yyvsp[0].symbol)); }
#line 1736 "y.tab.c"
    break;

  case 32: /* statement: compound_statement  */
#line 300 "1905084.y"
                               { add_children_and_log (&(yyval.symbol), statement, 1, &(yyvsp[0].symbol)); }
#line 1742 "y.tab.c"
    break;

  case 33: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 301 "1905084.y"
                                                                                             { add_children_and_log (&(yyval.symbol), statement, 7, &(yyvsp[-6].symbol), &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1748 "y.tab.c"
    break;

  case 34: /* statement: IF LPAREN expression RPAREN statement  */
#line 302 "1905084.y"
                                                                        { add_children_and_log (&(yyval.symbol), statement, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1754 "y.tab.c"
    break;

  case 35: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 303 "1905084.y"
                                                                 { add_children_and_log (&(yyval.symbol), statement, 7, &(yyvsp[-6].symbol), &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1760 "y.tab.c"
    break;

  case 36: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 304 "1905084.y"
                                                     { add_children_and_log (&(yyval.symbol), statement, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1766 "y.tab.c"
    break;

  case 37: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 305 "1905084.y"
                                               { add_children_and_log (&(yyval.symbol), statement, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1772 "y.tab.c"
    break;

  case 38: /* statement: RETURN expression SEMICOLON  */
#line 306 "1905084.y"
                                        { add_children_and_log (&(yyval.symbol), statement, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1778 "y.tab.c"
    break;

  case 39: /* expression_statement: SEMICOLON  */
#line 309 "1905084.y"
                                 { add_children_and_log (&(yyval.symbol), expression_statement, 1, &(yyvsp[0].symbol)); }
#line 1784 "y.tab.c"
    break;

  case 40: /* expression_statement: expression SEMICOLON  */
#line 310 "1905084.y"
                                                { add_children_and_log (&(yyval.symbol), expression_statement, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1790 "y.tab.c"
    break;

  case 41: /* variable: ID  */
#line 313 "1905084.y"
              { 
		//fprintf(logout, "Checking if '%s' is in symbol table\n", $1->getName());
		SymbolInfo* defined = st->lookUp((yyvsp[0].symbol)->getName());
		add_children_and_log (&(yyval.symbol), variable, 1, &(yyvsp[0].symbol));
		if (defined) {
			if (!defined->isFunction()) {
				//$1->setSemanticType(defined->getSemanticType());
				transfer_semantic (&(yyvsp[0].symbol), &defined);
			};
		} else fprintf (errorout, "Line# %d: Undeclared variable '%s'\n", (yyvsp[0].symbol)->getStartLine(), (yyvsp[0].symbol)->getName()); 
		transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); 
	 }
#line 1807 "y.tab.c"
    break;

  case 42: /* variable: ID LSQUARE expression RSQUARE  */
#line 325 "1905084.y"
                                         { 
		SymbolInfo* defined = st->lookUp((yyvsp[-3].symbol)->getName());
		add_children_and_log (&(yyval.symbol), variable, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
		if (defined) {
			if (!defined->isFunction()) {
				(yyvsp[-3].symbol)->setSemanticType(defined->getSemanticType());
				//transfer_semantic (&$1, &defined);
			};
			if (!defined->isArray()) fprintf (errorout, "Line# %d: '%s' is not an array\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName());
			if ((yyvsp[-1].symbol)->getSemanticType() != tINT) fprintf (errorout, "Line# %d: Array subscript is not an integer\n", (yyvsp[-3].symbol)->getStartLine());
		} else fprintf (errorout, "Line# %d: Undeclared variable '%s'\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName());
		transfer_semantic (&(yyval.symbol), &(yyvsp[-3].symbol)); 
	 }
#line 1825 "y.tab.c"
    break;

  case 43: /* expression: logic_expression  */
#line 340 "1905084.y"
                              { 
			// if ($1->getSemanticType() == tVOID) 
			// 	fprintf (errorout, "Line# %d: Void cannot be used in expression\n", $1->getStartLine());
			add_children_and_log (&(yyval.symbol), expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol));
		}
#line 1835 "y.tab.c"
    break;

  case 44: /* expression: variable ASSIGNOP logic_expression  */
#line 345 "1905084.y"
                                                     { 
			if ((yyvsp[0].symbol)->getSemanticType() == tVOID) 
				fprintf (errorout, "Line# %d: Void cannot be used in expression\n", (yyvsp[-2].symbol)->getStartLine());
			if ((yyvsp[-2].symbol)->getSemanticType() == tINT && (yyvsp[0].symbol)->getSemanticType() == tFLOAT) 
				fprintf (errorout, "Line# %d: Warning: possible loss of data in assignment of FLOAT to INT\n", (yyvsp[-2].symbol)->getStartLine());
			add_children_and_log (&(yyval.symbol), expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-2].symbol));;
		}
#line 1847 "y.tab.c"
    break;

  case 45: /* logic_expression: rel_expression  */
#line 354 "1905084.y"
                                        { add_children_and_log (&(yyval.symbol), logic_expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1853 "y.tab.c"
    break;

  case 46: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 355 "1905084.y"
                                                         { 
			add_children_and_log (&(yyval.symbol), logic_expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
			if ((yyvsp[-2].symbol)->getSemanticType() != tINT || (yyvsp[-2].symbol)->getSemanticType() != tINT)
				fprintf (errorout, "Line# %d: Logical operator cannot be applied to non-integers\n", (yyvsp[-2].symbol)->getStartLine());
			if ((yyvsp[-2].symbol)->getSemanticType() == tVOID) (yyval.symbol)->setSemanticType(tVOID);
			else (yyval.symbol)->setSemanticType(tINT);
		 }
#line 1865 "y.tab.c"
    break;

  case 47: /* rel_expression: simple_expression  */
#line 364 "1905084.y"
                                    { add_children_and_log (&(yyval.symbol), rel_expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1871 "y.tab.c"
    break;

  case 48: /* rel_expression: simple_expression RELOP simple_expression  */
#line 365 "1905084.y"
                                                                { 
			add_children_and_log (&(yyval.symbol), rel_expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
			if ((yyvsp[-2].symbol)->getSemanticType() == tVOID) (yyval.symbol)->setSemanticType(tVOID);
			else (yyval.symbol)->setSemanticType(tINT);
		}
#line 1881 "y.tab.c"
    break;

  case 49: /* simple_expression: term  */
#line 372 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), simple_expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1887 "y.tab.c"
    break;

  case 50: /* simple_expression: simple_expression ADDOP term  */
#line 373 "1905084.y"
                                                 { add_children_and_log (&(yyval.symbol), simple_expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-2].symbol)); }
#line 1893 "y.tab.c"
    break;

  case 51: /* term: unary_expression  */
#line 376 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), term, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1899 "y.tab.c"
    break;

  case 52: /* term: term MULOP unary_expression  */
#line 377 "1905084.y"
                                     { 
			add_children_and_log (&(yyval.symbol), term, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-2].symbol)); 
			if (!strcmp((yyvsp[-1].symbol)->getName(), "%") && (yyvsp[-2].symbol)->getSemanticType() != tINT || (yyvsp[0].symbol)->getSemanticType() != tINT) 
				fprintf (errorout, "Line# %d: Operands of modulus must be integers \n", (yyvsp[-2].symbol)->getStartLine());
	 }
#line 1909 "y.tab.c"
    break;

  case 53: /* unary_expression: ADDOP unary_expression  */
#line 384 "1905084.y"
                                           { add_children_and_log (&(yyval.symbol), unary_expression, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1915 "y.tab.c"
    break;

  case 54: /* unary_expression: NOT unary_expression  */
#line 385 "1905084.y"
                                        { 
			add_children_and_log (&(yyval.symbol), unary_expression, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			fprintf (errorout, "Line# %d: Not operator cannot be applied to non-integer\n", (yyvsp[-1].symbol)->getStartLine()); 
			transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol));
		 }
#line 1925 "y.tab.c"
    break;

  case 55: /* unary_expression: factor  */
#line 390 "1905084.y"
                          { add_children_and_log (&(yyval.symbol), unary_expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1931 "y.tab.c"
    break;

  case 56: /* factor: variable  */
#line 393 "1905084.y"
                   { add_children_and_log (&(yyval.symbol), factor, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1937 "y.tab.c"
    break;

  case 57: /* factor: ID LPAREN argument_list RPAREN  */
#line 394 "1905084.y"
                                         { 
		add_children_and_log (&(yyval.symbol), factor, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
		SymbolInfo* defined = st->lookUp((yyvsp[-3].symbol)->getName());
		if (defined) {
			if (defined->isFunction()) {
				//$1->setSemanticType(defined->getSemanticType());
				transfer_semantic (&(yyvsp[-3].symbol), &defined);
				ArrayList<SymbolInfo*> *dP = defined->getParams();
				for (arg_list->moveToStart(), dP->moveToStart(); 
					dP->currPos() < dP->length() && arg_list->currPos() < arg_list->length(); 
					arg_list->next(), dP->next()) {
						SymbolInfo *arg = arg_list->getValue(), *dParam = dP->getValue();
						if (arg->getSemanticType() == tINT && dParam->getSemanticType() == tFLOAT) arg->setSemanticType(tFLOAT);
						if (arg->getSemanticType() != dParam->getSemanticType() || arg->isArray() != dParam->isArray()) {
							fprintf (errorout, "Line# %d: Type mismatch for argument %d of '%s'\n", 
												arg->getStartLine(), arg_list->currPos()+1, (yyvsp[-3].symbol)->getName());
						};
				};
				if (arg_list->length() > dP->length()) 
					fprintf (errorout, "Line# %d: Too many arguments to function '%s'\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName());
				else if (arg_list->length() < dP->length()) 
					fprintf (errorout, "Line# %d: Too few arguments to function '%s'\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName());	
				delete arg_list;
			};
		} else fprintf (errorout, "Line# %d: Undeclared function '%s'\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName()); 
		transfer_semantic (&(yyval.symbol), &(yyvsp[-3].symbol)); 
	}
#line 1969 "y.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 421 "1905084.y"
                                   { add_children_and_log (&(yyval.symbol), factor, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-1].symbol)); }
#line 1975 "y.tab.c"
    break;

  case 59: /* factor: CONST_INT  */
#line 422 "1905084.y"
                     { add_children_and_log (&(yyval.symbol), factor, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1981 "y.tab.c"
    break;

  case 60: /* factor: CONST_FLOAT  */
#line 423 "1905084.y"
                      { add_children_and_log (&(yyval.symbol), factor, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1987 "y.tab.c"
    break;

  case 61: /* factor: variable INCOP  */
#line 424 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), factor, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-1].symbol)); }
#line 1993 "y.tab.c"
    break;

  case 62: /* factor: variable DECOP  */
#line 425 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), factor, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-1].symbol)); }
#line 1999 "y.tab.c"
    break;

  case 63: /* argument_list: arguments  */
#line 428 "1905084.y"
                          { add_children_and_log (&(yyval.symbol), argument_list, 1, &(yyvsp[0].symbol)); }
#line 2005 "y.tab.c"
    break;

  case 64: /* arguments: arguments COMMA logic_expression  */
#line 431 "1905084.y"
                                             { 
				add_children_and_log (&(yyval.symbol), arguments, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
				arg_list->append((yyvsp[0].symbol));
		  }
#line 2014 "y.tab.c"
    break;

  case 65: /* arguments: logic_expression  */
#line 435 "1905084.y"
                                 { 
				add_children_and_log (&(yyval.symbol), arguments, 1, &(yyvsp[0].symbol)); 
				arg_list = new ArrayList<SymbolInfo*>();
				arg_list->append((yyvsp[0].symbol));
				//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
		  }
#line 2025 "y.tab.c"
    break;


#line 2029 "y.tab.c"

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

#line 444 "1905084.y"

int main (int argc, char *argv[]) {
	fp = fopen(argv[1],"r");
	if (!fp) {
		printf("Cannot Open Input File.\n");
		exit(1);
	};
	parseout = fopen(argv[2],"w");
	errorout = fopen(argv[3],"w");
	logout = fopen(argv[4],"w");
	
	NON_TERMINAL = new char[20], strcpy (NON_TERMINAL, "NON_TERMINAL"); 
	tINT = new char[10], strcpy (tINT, "INT"); 
	tFLOAT = new char[10], strcpy (tFLOAT, "FLOAT"); 
	tVOID = new char[10], strcpy (tVOID, "VOID"); 
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
	st = new SymbolTable(11);
	yyparse();
 	fprintf(logout, "Total Lines: %d\n", line_count);
 	fprintf(logout, "Total Errors: %d\n", err_count);
	fclose(parseout), fclose(errorout), fclose(logout);
	
	return 0;
}

