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
#include "1905084_data.h"

using namespace std;

int yyparse(void);
int yylex(void);

int line_count = 1, err_count = 0, stack_offset = 0, label_count = 0;
extern FILE *yyin;
bool function_scope = false;
SymbolInfo* scope_function = nullptr;
FILE *fp, *parseout, *errorout, *logout, *asmout, *datasegout, *procsegout;

SymbolTable* st;
ArrayList<SymbolInfo*> *var_list = nullptr, *param_list = nullptr, *arg_list = nullptr;

char  *NON_TERMINAL, *tINT, *tFLOAT, *tVOID, *start, *program, *unit, *func_declaration, *func_definition, *parameter_list, 
	  *compound_statement, *var_declaration, *type_specifier, *declaration_list, *statements, *statement, *expression_statement, 
	  *variable, *expression, *logic_expression, *rel_expression, *simple_expression, *term, *unary_expression, *factor, 
	  *argument_list, *arguments;

void yyerror(char* s) {
	fprintf(errorout, "Line# %d: Unrecognized syntax.\n", line_count);
	fprintf(logout, "Line# %d: Unrecognized syntax.\n", line_count);
};

void fprint_rule (SymbolInfo* lhs, FILE* fp) {
	fprintf(fp, "%s : ", lhs->getName());
	ArrayList<SymbolInfo*> *children = lhs->getChildren();
	if (!children) return;
	for (children->moveToStart(); children->currPos() < children->length(); children->next()) {
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
	va_list list;
	va_start (list, n);
	for (int i=0; i<n; i++) {
		SymbolInfo* x = *(va_arg(list, SymbolInfo**));
		(*parent)->addChild(x);
		if (i == 0) (*parent)->setStartLine (x->getStartLine());
		(*parent)->setEndLine (x->getEndLine());
	};
	va_end(list);
	log_rule (*parent);
};

void transfer_semantic (SymbolInfo** parent, SymbolInfo** child) {
	(*parent)->setSemanticType((*child)->getSemanticType());
	(*parent)->setStackOffset((*child)->getStackOffset());
	if ((*child)->isArray()) (*parent)->setArray();
	if ((*child)->isZero()) (*parent)->setZero();
	if ((*child)->isGlobal()) (*parent)->setGlobal();
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
	};
};

void print_code (SymbolInfo* symbol, int depth = 0) {
	if (!symbol) return;
	//for (int i=0; i<depth; i++) fprintf(asmout, "\t");

	if (symbol->getType() == NON_TERMINAL) {
		// fprint_rule (symbol, parseout);
		// fprintf(parseout, "\t<Line: %d-%d>\n", symbol->getStartLine(), symbol->getEndLine());
		if (symbol->getName() == func_definition) {
			SymbolInfo* comp_stat;
			if (symbol->getChild(3)->getName() == parameter_list) comp_stat = symbol->getChild(5);
			else comp_stat = symbol->getChild(4);

			fprintf (asmout, "%s PROC\n", symbol->getChild(1)->getName());
			if (!strcmp(symbol->getChild(1)->getName(), "main")) fprintf(asmout, "\tMOV AX, @DATA\n\tMOV DS, AX\n");
			print_code (comp_stat, depth + 1);
			fprintf (asmout, "%s ENDP\n", symbol->getChild(1)->getName());

		} else if (symbol->getName() == compound_statement) {
			if (symbol->getChild(1)->getName() == statements) {
				print_code (symbol->getChild(1), depth);
				fprintf (asmout, "\tADD SP, %d\n\tPOP BP\n", symbol->getVarDecCount() * 2);
			};	
		} else if (symbol->getName() == statements) {
			print_code (symbol->getFirstChild(), depth);
			if (symbol->getChildrenCount() > 1) print_code (symbol->getLastChild(), depth), cout << "2nd child " << endl;
		} else if (symbol->getName() == statement) {
			//fprintf(asmout, "STATEMENT! %d %d\n", symbol->getStartLine(), symbol->getEndLine());
			if (symbol->getFirstChild()->getName() == var_declaration) {
				fprintf(asmout, "\tPUSH BP\n\tMOV BP, SP\n\tSUB SP, %d\n", symbol->getFirstChild()->getVarDecCount() * 2);
			} else if (symbol->getFirstChild()->getName() == expression_statement) {
				label_count++, fprintf (asmout, "L%d:\n", label_count);
				SymbolInfo* expr_stat = symbol->getFirstChild();
				if (expr_stat->getFirstChild()->getName() == expression) print_code (expr_stat->getFirstChild());
			} else if (!strcmp(symbol->getFirstChild()->getType(), "PRINTLN")) {
				label_count++, fprintf (asmout, "L%d:\n", label_count);
				SymbolInfo* var = symbol->getChild(2)->getFirstChild();
				if (var->isGlobal()) {
					fprintf (asmout, "\tMOV AX, %s\n", var->getName());
				} else {
					fprintf (asmout, "\tMOV AX, [BP-%d]\n", var->getStackOffset());
				};
				fprintf(asmout, "\tCALL print_output\n\tCALL new_line\n");
			}
		} else if (symbol->getName() == expression) {
			//fprintf(asmout, "expression!!\n");
			if (symbol->getFirstChild()->getName() == variable) {
				print_code (symbol->getLastChild(), depth);
				SymbolInfo* var = symbol->getFirstChild()->getFirstChild();
				//fprintf(asmout, "assignment to %s\n", var->getName());
				if (var->isGlobal()) {
					fprintf (asmout, "\tMOV %s, AX\n", var->getName());
				} else {
					fprintf (asmout, "\tMOV [BP-%d], AX\n", var->getStackOffset());
				}
			} else print_code (symbol->getFirstChild(), depth);
		} else if (symbol->getName() == logic_expression) {
			if (symbol->getChildrenCount() > 1) {
			} else print_code (symbol->getFirstChild(), depth);
		} else if (symbol->getName() == rel_expression) {
							cout << "hello!!" << endl;
			if (symbol->getChildrenCount() > 1) {
			} else print_code (symbol->getFirstChild(), depth);
		} else if (symbol->getName() == simple_expression) {
			if (symbol->getFirstChild()->getName() == term) print_code (symbol->getFirstChild(), depth);
			else {

			}
		} else if (symbol->getName() == term) {
			if (symbol->getFirstChild()->getName() == unary_expression) print_code (symbol->getFirstChild(), depth);
			else {
				
			}
		} else if (symbol->getName() == unary_expression) {
			if (symbol->getFirstChild()->getName() == factor) print_code (symbol->getFirstChild(), depth);
			else {
				
			}
		} else if (symbol->getName() == factor) {
			if (!strcmp(symbol->getFirstChild()->getType(), "CONST_INT")) {
				fprintf (asmout, "\tMOV AX, %s\n", symbol->getFirstChild()->getName());
			} else if (symbol->getFirstChild()->getName() == variable) {
				fprintf (asmout, "\tMOV AX, %s\n", symbol->getFirstChild()->getFirstChild()->getName());
			} else if (symbol->getChild(1)->getName() == expression) {
				print_code (symbol->getChild(1), depth);
			} else if (!strcmp(symbol->getChild(1)->getType(), "INCOP")) {
				SymbolInfo* var = symbol->getChild(1)->getFirstChild();
				if (var->isGlobal()) fprintf (asmout, "INC %s\n", var->getName());
				else fprintf (asmout, "INC [BP-%d]\n", var->getStackOffset());
			} else if (!strcmp(symbol->getChild(1)->getType(), "DECOP")) {
				SymbolInfo* var = symbol->getChild(1)->getFirstChild();
				if (var->isGlobal()) fprintf (asmout, "DEC %s\n", var->getName());
				else fprintf (asmout, "DEC [BP-%d]\n", var->getStackOffset());
			} 

		} else {
			ArrayList<SymbolInfo*> *children = symbol->getChildren();
			if (!children) return;
			for (children->moveToStart(); children->currPos() < children->length(); children->next()) {
				SymbolInfo* x = children->getValue();
				if (!x) continue;
				print_code (x, depth);
			};
		};
	} else {
		fprintf(parseout, "%s : %s", symbol->getType(), symbol->getName());
		fprintf(parseout, "\t<Line: %d>\n", symbol->getStartLine());
	}
};


#line 273 "y.tab.c"

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
#line 203 "1905084.y"

	SymbolInfo* symbol;

#line 404 "y.tab.c"

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
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_parameter_list = 46,            /* parameter_list  */
  YYSYMBOL_compound_statement = 47,        /* compound_statement  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_var_declaration = 49,           /* var_declaration  */
  YYSYMBOL_type_specifier = 50,            /* type_specifier  */
  YYSYMBOL_declaration_list = 51,          /* declaration_list  */
  YYSYMBOL_statements = 52,                /* statements  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_expression_statement = 54,      /* expression_statement  */
  YYSYMBOL_variable = 55,                  /* variable  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_logic_expression = 57,          /* logic_expression  */
  YYSYMBOL_rel_expression = 58,            /* rel_expression  */
  YYSYMBOL_simple_expression = 59,         /* simple_expression  */
  YYSYMBOL_term = 60,                      /* term  */
  YYSYMBOL_unary_expression = 61,          /* unary_expression  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_argument_list = 63,             /* argument_list  */
  YYSYMBOL_arguments = 64                  /* arguments  */
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
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

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
       0,   217,   217,   240,   241,   244,   245,   246,   249,   254,
     261,   261,   288,   288,   298,   303,   307,   313,   321,   321,
     327,   334,   364,   365,   366,   369,   373,   378,   383,   391,
     392,   395,   396,   397,   398,   401,   402,   403,   404,   405,
     412,   413,   416,   425,   437,   438,   447,   448,   457,   458,
     465,   466,   473,   474,   488,   489,   495,   498,   499,   529,
     530,   535,   540,   541,   544,   545,   548,   552
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
  "func_declaration", "func_definition", "$@1", "$@2", "parameter_list",
  "compound_statement", "$@3", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
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
      37,   -75,   -75,   -75,    16,    37,   -75,   -75,   -75,   -75,
      -1,   -75,   -75,    27,    -4,     6,     7,    23,   -75,    10,
      -8,    24,    33,    43,   -75,    38,    34,    37,   -75,   -75,
      44,    54,   -75,   -75,    38,    45,    55,   -75,    99,   -75,
     -75,   -75,    59,    63,    66,    96,    96,    96,    96,   -75,
     -75,   -75,    35,    76,   -75,   -75,    64,    65,   -75,   -75,
      36,    74,   -75,    91,     5,   100,   -75,   -75,    96,    62,
      96,    84,    31,   -75,   -75,    92,    96,    96,    81,    93,
     -75,   -75,   -75,   -75,    96,   -75,    96,    96,    96,    96,
     101,    62,   102,   -75,   -75,   -75,   109,    94,   106,   110,
     114,   -75,   -75,   100,   125,   -75,    99,    96,    99,   -75,
      96,   -75,   111,   135,   118,   -75,   -75,   -75,    99,    99,
     -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    22,    23,    24,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    27,     0,     0,     0,     0,    21,    12,
       0,    17,     0,    25,     9,     0,    10,     0,    16,    28,
       0,    18,    13,     8,     0,    15,     0,    20,     0,    11,
      14,    26,     0,     0,     0,     0,     0,     0,     0,    40,
      60,    61,    42,     0,    33,    31,     0,     0,    29,    32,
      57,     0,    44,    46,    48,    50,    52,    56,     0,     0,
       0,     0,    57,    54,    55,     0,    65,     0,     0,    27,
      19,    30,    62,    63,     0,    41,     0,     0,     0,     0,
       0,     0,     0,    39,    59,    67,     0,    64,     0,    42,
       0,    45,    47,    51,    49,    53,     0,     0,     0,    58,
       0,    43,     0,    35,     0,    37,    66,    38,     0,     0,
      36,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   137,   -75,   -75,   -75,   -75,   -75,   -13,
     -75,    22,     4,   -75,   -75,   -52,   -58,   -46,   -42,   -74,
      57,    56,    58,   -39,   -75,   -75,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    34,    25,    20,    54,
      38,    55,    56,    14,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    96,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    72,    95,    71,    10,    81,    75,    73,    74,    10,
     101,    91,    32,     1,     2,    26,    11,     3,    87,    21,
      27,    39,     9,    88,    17,    18,    90,     9,    92,    19,
      72,    35,   100,   107,    13,    98,   116,    22,    72,    24,
      72,    72,    72,    72,     1,     2,    82,    83,     3,    15,
     105,    82,    83,    16,   113,    84,   115,    76,    23,    28,
      29,    77,    31,    33,    72,   114,   120,   121,    42,    30,
      43,    44,     1,     2,    36,    46,     3,    45,    46,    37,
      40,    68,    41,    47,    48,    69,    47,    48,    70,    31,
      80,    49,    50,    51,    49,    50,    51,    52,    78,    79,
      52,    53,    42,    85,    43,    44,     1,     2,    86,    46,
       3,    45,    46,    93,    89,    94,    99,    47,    48,    16,
      47,    48,   110,    31,   106,   108,    50,    51,    49,    50,
      51,    52,   109,   111,    52,    53,    77,   112,    87,   118,
     117,   119,    12,   102,   104,   103
};

static const yytype_int8 yycheck[] =
{
      46,    47,    76,    45,     0,    57,    48,    46,    47,     5,
      84,    69,    25,     7,     8,    23,     0,    11,    13,    15,
      28,    34,     0,    18,    28,    29,    68,     5,    70,    23,
      76,    27,    78,    91,    35,    77,   110,    30,    84,    29,
      86,    87,    88,    89,     7,     8,    15,    16,    11,    22,
      89,    15,    16,    26,   106,    19,   108,    22,    35,    35,
      27,    26,    24,    29,   110,   107,   118,   119,     3,    26,
       5,     6,     7,     8,    30,    13,    11,    12,    13,    25,
      35,    22,    27,    21,    22,    22,    21,    22,    22,    24,
      25,    29,    30,    31,    29,    30,    31,    35,    22,    35,
      35,    36,     3,    29,     5,     6,     7,     8,    17,    13,
      11,    12,    13,    29,    14,    23,    35,    21,    22,    26,
      21,    22,    28,    24,    23,    23,    30,    31,    29,    30,
      31,    35,    23,    27,    35,    36,    26,    23,    13,     4,
      29,    23,     5,    86,    88,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    11,    39,    40,    41,    42,    43,    49,
      50,     0,    41,    35,    51,    22,    26,    28,    29,    23,
      46,    50,    30,    35,    29,    45,    23,    28,    35,    27,
      26,    24,    47,    29,    44,    50,    30,    25,    48,    47,
      35,    27,     3,     5,     6,    12,    13,    21,    22,    29,
      30,    31,    35,    36,    47,    49,    50,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    22,    22,
      22,    56,    55,    61,    61,    56,    22,    26,    22,    35,
      25,    53,    15,    16,    19,    29,    17,    13,    18,    14,
      56,    54,    56,    29,    23,    57,    63,    64,    56,    35,
      55,    57,    58,    60,    59,    61,    23,    54,    23,    23,
      28,    27,    23,    53,    56,    53,    57,    29,     4,    23,
      53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      44,    43,    45,    43,    46,    46,    46,    46,    48,    47,
      47,    49,    50,    50,    50,    51,    51,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       2,     3,     1,     1,     1,     3,     6,     1,     4,     1,
       2,     1,     1,     1,     7,     5,     7,     5,     5,     3,
       1,     2,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     2,     1,     1,     4,     3,
       1,     1,     2,     2,     1,     0,     3,     1
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
#line 217 "1905084.y"
                {
		add_children_and_log (&(yyval.symbol), start, 1, &(yyvsp[0].symbol));
		print_parse_tree ((yyval.symbol));
		fprintf(asmout, ".CODE\n");
		print_code ((yyval.symbol));

		SymbolInfo *start_node = (yyvsp[0].symbol), *curr_node = nullptr;
		curr_node = start_node;

		fprintf(datasegout, ".MODEL SMALL\n");
		fprintf(datasegout, ".STACK 1000H\n");
		fprintf(datasegout, ".DATA 1000H\n");
		fprintf(datasegout, "\tCR EQU 0DH\n\tLF EQU 0AH\n\tnumber DB \"00000$\"\n");

		ArrayList<SymbolInfo*> *children = curr_node->getChildren();
		// for (param_list->moveToStart(); param_list->currPos() < param_list->length(); param_list->next()) {

		// }
		

	}
#line 1554 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 240 "1905084.y"
                       { add_children_and_log (&(yyval.symbol), program, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1560 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 241 "1905084.y"
               { add_children_and_log (&(yyval.symbol), program, 1, &(yyvsp[0].symbol)); }
#line 1566 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 244 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), unit, 1, &(yyvsp[0].symbol)); }
#line 1572 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 245 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), unit, 1, &(yyvsp[0].symbol)); }
#line 1578 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 246 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), unit, 1, &(yyvsp[0].symbol)); }
#line 1584 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 249 "1905084.y"
                                                                            { 
			transfer_semantic (&(yyvsp[-4].symbol), &(yyvsp[-5].symbol)), (yyvsp[-4].symbol)->setFunction(), (yyvsp[-4].symbol)->setParams (param_list);
			st->insert((yyvsp[-4].symbol));
			add_children_and_log (&(yyval.symbol), func_declaration, 6, &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
		}
#line 1594 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 254 "1905084.y"
                                                             { 
			transfer_semantic (&(yyvsp[-3].symbol), &(yyvsp[-4].symbol)), (yyvsp[-3].symbol)->setFunction();
			st->insert((yyvsp[-3].symbol));
			add_children_and_log (&(yyval.symbol), func_declaration, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
		}
#line 1604 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 261 "1905084.y"
                                                                 {
			transfer_semantic (&(yyvsp[-3].symbol), &(yyvsp[-4].symbol)), (yyvsp[-3].symbol)->setFunction(), (yyvsp[-3].symbol)->setParams (param_list);
			st->insert((yyvsp[-3].symbol));
			st->enterScope(); function_scope = true, scope_function = (yyvsp[-3].symbol);
			if (param_list) {
				for (param_list->moveToStart(); param_list->currPos() < param_list->length(); param_list->next()) {
					SymbolInfo* param = param_list->getValue();
					if (st->lookUpCurrentScope(param->getName())) {
						err_count++, fprintf (errorout, "Line# %d: Redefinition of parameter '%s'\n", param->getStartLine(), param->getName()); 
						break;
					};
					st->insert(param);
				};
			};
		}
#line 1624 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 275 "1905084.y"
                                     { 
			SymbolInfo* predefined = st->lookUp((yyvsp[-5].symbol)->getName());
			if (predefined) {
				if (predefined->isFunction()) {
					if (predefined->getSemanticType() != (yyvsp[-6].symbol)->getSemanticType() || predefined->getParams()->length() != param_list->length())
						err_count++, fprintf (errorout, "Line# %d: Conflicting types for '%s'\n", (yyvsp[-5].symbol)->getStartLine(), predefined->getName()); 						
				} else {
					err_count++, fprintf (errorout, "Line# %d: '%s' redeclared as different kind of symbol\n", (yyvsp[-5].symbol)->getStartLine(), predefined->getName()); 				
				};
			};
			add_children_and_log (&(yyval.symbol), func_definition, 6, &(yyvsp[-6].symbol), &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[0].symbol)); 
			scope_function = nullptr;
		}
#line 1642 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 288 "1905084.y"
                                                  {	
			transfer_semantic (&(yyvsp[-2].symbol), &(yyvsp[-3].symbol)), (yyvsp[-2].symbol)->setFunction();
			st->insert((yyvsp[-2].symbol));
			st->enterScope(); function_scope = true, scope_function = (yyvsp[-2].symbol); 
		}
#line 1652 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 292 "1905084.y"
                                     { 
			add_children_and_log (&(yyval.symbol), func_definition, 5, &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[0].symbol));
			scope_function = nullptr; 
		}
#line 1661 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 298 "1905084.y"
                                                          { 
			add_children_and_log (&(yyval.symbol), parameter_list, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			transfer_semantic (&(yyvsp[0].symbol), &(yyvsp[-1].symbol));
			param_list->append((yyvsp[0].symbol));
		}
#line 1671 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 303 "1905084.y"
                                                      { 
			add_children_and_log (&(yyval.symbol), parameter_list, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
			param_list->append((yyvsp[0].symbol));
		}
#line 1680 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 307 "1905084.y"
                                    { 
			add_children_and_log (&(yyval.symbol), parameter_list, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
			param_list = new ArrayList<SymbolInfo*>();
			transfer_semantic (&(yyvsp[0].symbol), &(yyvsp[-1].symbol));
			param_list->append((yyvsp[0].symbol));
		}
#line 1691 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 313 "1905084.y"
                                 { 
			add_children_and_log (&(yyval.symbol), parameter_list, 1, &(yyvsp[0].symbol)); 
			param_list = new ArrayList<SymbolInfo*>();
			param_list->append((yyvsp[0].symbol));
		}
#line 1701 "y.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 321 "1905084.y"
                           {if (!function_scope) st->enterScope(); else function_scope = false;}
#line 1707 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL $@3 statements RCURL  */
#line 321 "1905084.y"
                                                                                                                   { 
				add_children_and_log (&(yyval.symbol), compound_statement, 3, &(yyvsp[-3].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
				(yyval.symbol)->setVarDecCount(st->getCurrScopeVarCount());
				st->printAllScope(logout);
				st->exitScope();
			}
#line 1718 "y.tab.c"
    break;

  case 20: /* compound_statement: LCURL RCURL  */
#line 327 "1905084.y"
                                  { 
				add_children_and_log (&(yyval.symbol), compound_statement, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
				st->enterScope();
				st->exitScope();
			}
#line 1728 "y.tab.c"
    break;

  case 21: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 334 "1905084.y"
                                                            {
			add_children_and_log (&(yyval.symbol), var_declaration, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			bool global_dec = st->getCurrScopeId() == 1? true : false;
			for (var_list->moveToStart(); var_list->currPos() < var_list->length(); var_list->next()) {
				SymbolInfo* var = var_list->getValue();
				if ((yyvsp[-2].symbol)->getSemanticType() == tVOID) {
					err_count++, fprintf (errorout, "Line# %d: Variable or field '%s' declared void\n", var->getStartLine(), var->getName()); 
					break;
				};
				SymbolInfo* predefined = st->lookUpCurrentScope(var->getName());
				if (predefined) {
					if (predefined->getSemanticType() != (yyvsp[-2].symbol)->getSemanticType())
						err_count++, fprintf (errorout, "Line# %d: Conflicting types for'%s'\n", var->getStartLine(), predefined->getName()); 						
				};
				transfer_semantic (&var, &(yyvsp[-2].symbol));
				if (global_dec) {
					var->setGlobal();
					fprintf(datasegout, "\t%s DW 1 DUP (0000H)\n", var->getName());
				} else {
					stack_offset += 2;
					var->setStackOffset(stack_offset);
				};
				st->insert(var);
			};
			(yyval.symbol)->setVarDecCount(var_list->length());
			st->setCurrScopeVarCount(st->getCurrScopeVarCount() + (yyval.symbol)->getVarDecCount());
			delete var_list;
		 }
#line 1761 "y.tab.c"
    break;

  case 22: /* type_specifier: INT  */
#line 364 "1905084.y"
                      { add_children_and_log (&(yyval.symbol), type_specifier, 1, &(yyvsp[0].symbol)), (yyval.symbol)->setSemanticType((yyvsp[0].symbol)->getType()); }
#line 1767 "y.tab.c"
    break;

  case 23: /* type_specifier: FLOAT  */
#line 365 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), type_specifier, 1, &(yyvsp[0].symbol)), (yyval.symbol)->setSemanticType((yyvsp[0].symbol)->getType()); }
#line 1773 "y.tab.c"
    break;

  case 24: /* type_specifier: VOID  */
#line 366 "1905084.y"
                        { add_children_and_log (&(yyval.symbol), type_specifier, 1, &(yyvsp[0].symbol)), (yyval.symbol)->setSemanticType((yyvsp[0].symbol)->getType()); }
#line 1779 "y.tab.c"
    break;

  case 25: /* declaration_list: declaration_list COMMA ID  */
#line 369 "1905084.y"
                                             {
			add_children_and_log (&(yyval.symbol), declaration_list, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			var_list->append((yyvsp[0].symbol));
		  }
#line 1788 "y.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID LSQUARE CONST_INT RSQUARE  */
#line 373 "1905084.y"
                                                                        {
			add_children_and_log (&(yyval.symbol), declaration_list, 6, &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			(yyvsp[-3].symbol)->setArray();
			var_list->append((yyvsp[-3].symbol));
		  }
#line 1798 "y.tab.c"
    break;

  case 27: /* declaration_list: ID  */
#line 378 "1905084.y"
                       {
			add_children_and_log (&(yyval.symbol), declaration_list, 1, &(yyvsp[0].symbol));
			var_list = new ArrayList<SymbolInfo*>();
			var_list->append((yyvsp[0].symbol));
		  }
#line 1808 "y.tab.c"
    break;

  case 28: /* declaration_list: ID LSQUARE CONST_INT RSQUARE  */
#line 383 "1905084.y"
                                                 {
			add_children_and_log (&(yyval.symbol), declaration_list, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			var_list = new ArrayList<SymbolInfo*>();
			(yyvsp[-3].symbol)->setArray();
			var_list->append((yyvsp[-3].symbol));
		  }
#line 1819 "y.tab.c"
    break;

  case 29: /* statements: statement  */
#line 391 "1905084.y"
                       { add_children_and_log (&(yyval.symbol), statements, 1, &(yyvsp[0].symbol)); }
#line 1825 "y.tab.c"
    break;

  case 30: /* statements: statements statement  */
#line 392 "1905084.y"
                                  { add_children_and_log (&(yyval.symbol), statements, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1831 "y.tab.c"
    break;

  case 31: /* statement: var_declaration  */
#line 395 "1905084.y"
                            { add_children_and_log (&(yyval.symbol), statement, 1, &(yyvsp[0].symbol)); }
#line 1837 "y.tab.c"
    break;

  case 32: /* statement: expression_statement  */
#line 396 "1905084.y"
                                 { add_children_and_log (&(yyval.symbol), statement, 1, &(yyvsp[0].symbol)); }
#line 1843 "y.tab.c"
    break;

  case 33: /* statement: compound_statement  */
#line 397 "1905084.y"
                               { add_children_and_log (&(yyval.symbol), statement, 1, &(yyvsp[0].symbol)); }
#line 1849 "y.tab.c"
    break;

  case 34: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 398 "1905084.y"
                                                                                             { 
			add_children_and_log (&(yyval.symbol), statement, 7, &(yyvsp[-6].symbol), &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
	  }
#line 1857 "y.tab.c"
    break;

  case 35: /* statement: IF LPAREN expression RPAREN statement  */
#line 401 "1905084.y"
                                                                        { add_children_and_log (&(yyval.symbol), statement, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1863 "y.tab.c"
    break;

  case 36: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 402 "1905084.y"
                                                                 { add_children_and_log (&(yyval.symbol), statement, 7, &(yyvsp[-6].symbol), &(yyvsp[-5].symbol), &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1869 "y.tab.c"
    break;

  case 37: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 403 "1905084.y"
                                                     { add_children_and_log (&(yyval.symbol), statement, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1875 "y.tab.c"
    break;

  case 38: /* statement: PRINTLN LPAREN variable RPAREN SEMICOLON  */
#line 404 "1905084.y"
                                                     { add_children_and_log (&(yyval.symbol), statement, 5, &(yyvsp[-4].symbol), &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1881 "y.tab.c"
    break;

  case 39: /* statement: RETURN expression SEMICOLON  */
#line 405 "1905084.y"
                                        { 
			add_children_and_log (&(yyval.symbol), statement, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
			if (scope_function->getSemanticType() == tVOID) 
				err_count++, fprintf (errorout, "Line# %d: Return from void function\n", (yyvsp[-2].symbol)->getStartLine(), (yyvsp[-2].symbol)->getName()); 
	  }
#line 1891 "y.tab.c"
    break;

  case 40: /* expression_statement: SEMICOLON  */
#line 412 "1905084.y"
                                 { add_children_and_log (&(yyval.symbol), expression_statement, 1, &(yyvsp[0].symbol)); }
#line 1897 "y.tab.c"
    break;

  case 41: /* expression_statement: expression SEMICOLON  */
#line 413 "1905084.y"
                                                { add_children_and_log (&(yyval.symbol), expression_statement, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); }
#line 1903 "y.tab.c"
    break;

  case 42: /* variable: ID  */
#line 416 "1905084.y"
              { 
		SymbolInfo* defined = st->lookUp((yyvsp[0].symbol)->getName());
		add_children_and_log (&(yyval.symbol), variable, 1, &(yyvsp[0].symbol));
		if (defined) {
			if (!defined->isFunction()) transfer_semantic (&(yyvsp[0].symbol), &defined);
			if (defined->isArray()) err_count++, fprintf (errorout, "Line# %d: '%s' is an array\n", (yyvsp[0].symbol)->getStartLine(), (yyvsp[0].symbol)->getName());
		} else err_count++, fprintf (errorout, "Line# %d: Undeclared variable '%s'\n", (yyvsp[0].symbol)->getStartLine(), (yyvsp[0].symbol)->getName()); 
		transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); 
	 }
#line 1917 "y.tab.c"
    break;

  case 43: /* variable: ID LSQUARE expression RSQUARE  */
#line 425 "1905084.y"
                                         { 
		SymbolInfo* defined = st->lookUp((yyvsp[-3].symbol)->getName());
		add_children_and_log (&(yyval.symbol), variable, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
		if (defined) {
			if (!defined->isFunction()) (yyvsp[-3].symbol)->setSemanticType(defined->getSemanticType());
			if (!defined->isArray()) err_count++, fprintf (errorout, "Line# %d: '%s' is not an array\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName());
			if ((yyvsp[-1].symbol)->getSemanticType() != tINT) err_count++, fprintf (errorout, "Line# %d: Array subscript is not an integer\n", (yyvsp[-3].symbol)->getStartLine());
		} else err_count++, fprintf (errorout, "Line# %d: Undeclared variable '%s'\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName());
		transfer_semantic (&(yyval.symbol), &(yyvsp[-3].symbol)); 
	 }
#line 1932 "y.tab.c"
    break;

  case 44: /* expression: logic_expression  */
#line 437 "1905084.y"
                              { add_children_and_log (&(yyval.symbol), expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1938 "y.tab.c"
    break;

  case 45: /* expression: variable ASSIGNOP logic_expression  */
#line 438 "1905084.y"
                                                     { 
			if ((yyvsp[0].symbol)->getSemanticType() == tVOID) 
				err_count++, fprintf (errorout, "Line# %d: Void cannot be used in expression \n", (yyvsp[-2].symbol)->getStartLine());
			if ((yyvsp[-2].symbol)->getSemanticType() == tINT && (yyvsp[0].symbol)->getSemanticType() == tFLOAT) 
				err_count++, fprintf (errorout, "Line# %d: Warning: possible loss of data in assignment of FLOAT to INT\n", (yyvsp[-2].symbol)->getStartLine());
			add_children_and_log (&(yyval.symbol), expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-2].symbol));;
		}
#line 1950 "y.tab.c"
    break;

  case 46: /* logic_expression: rel_expression  */
#line 447 "1905084.y"
                                        { add_children_and_log (&(yyval.symbol), logic_expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1956 "y.tab.c"
    break;

  case 47: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 448 "1905084.y"
                                                         { 
			add_children_and_log (&(yyval.symbol), logic_expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
			if ((yyvsp[-2].symbol)->getSemanticType() != tINT || (yyvsp[0].symbol)->getSemanticType() != tINT)
				err_count++, fprintf (errorout, "Line# %d: Logical operator cannot be applied to non-integers\n", (yyvsp[-2].symbol)->getStartLine());
			if ((yyvsp[-2].symbol)->getSemanticType() == tVOID || (yyvsp[0].symbol)->getSemanticType() == tVOID) (yyval.symbol)->setSemanticType(tVOID);
			else (yyval.symbol)->setSemanticType(tINT);
		 }
#line 1968 "y.tab.c"
    break;

  case 48: /* rel_expression: simple_expression  */
#line 457 "1905084.y"
                                    { add_children_and_log (&(yyval.symbol), rel_expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1974 "y.tab.c"
    break;

  case 49: /* rel_expression: simple_expression RELOP simple_expression  */
#line 458 "1905084.y"
                                                                { 
			add_children_and_log (&(yyval.symbol), rel_expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)); 
			if ((yyvsp[-2].symbol)->getSemanticType() == tVOID) (yyval.symbol)->setSemanticType(tVOID);
			else (yyval.symbol)->setSemanticType(tINT);
		}
#line 1984 "y.tab.c"
    break;

  case 50: /* simple_expression: term  */
#line 465 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), simple_expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 1990 "y.tab.c"
    break;

  case 51: /* simple_expression: simple_expression ADDOP term  */
#line 466 "1905084.y"
                                                 { 
				add_children_and_log (&(yyval.symbol), simple_expression, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
				if ((yyvsp[-2].symbol)->getSemanticType() == tFLOAT && (yyvsp[0].symbol)->getSemanticType() != tVOID) transfer_semantic (&(yyval.symbol), &(yyvsp[-2].symbol));
				else transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol));
		  }
#line 2000 "y.tab.c"
    break;

  case 52: /* term: unary_expression  */
#line 473 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), term, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 2006 "y.tab.c"
    break;

  case 53: /* term: term MULOP unary_expression  */
#line 474 "1905084.y"
                                     { 
			add_children_and_log (&(yyval.symbol), term, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			if ((yyvsp[-2].symbol)->getSemanticType() == tFLOAT && (yyvsp[0].symbol)->getSemanticType() != tVOID) transfer_semantic (&(yyval.symbol), &(yyvsp[-2].symbol));
			else transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); 
			if ((!strcmp((yyvsp[-1].symbol)->getName(), "%") || !strcmp((yyvsp[-1].symbol)->getName(), "/")) && (yyvsp[0].symbol)->isZero()) 
				err_count++, fprintf (errorout, "Line# %d: Warning: division by zero\n", (yyvsp[-2].symbol)->getStartLine());
			if (!strcmp((yyvsp[-1].symbol)->getName(), "%")) {
				(yyval.symbol)->setSemanticType(tINT);
				if (((yyvsp[-2].symbol)->getSemanticType() != tINT || (yyvsp[0].symbol)->getSemanticType() != tINT)) 
					err_count++, fprintf (errorout, "Line# %d: Operands of modulus must be integers \n", (yyvsp[-2].symbol)->getStartLine());
			};
	 }
#line 2023 "y.tab.c"
    break;

  case 54: /* unary_expression: ADDOP unary_expression  */
#line 488 "1905084.y"
                                           { add_children_and_log (&(yyval.symbol), unary_expression, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 2029 "y.tab.c"
    break;

  case 55: /* unary_expression: NOT unary_expression  */
#line 489 "1905084.y"
                                        { 
			add_children_and_log (&(yyval.symbol), unary_expression, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
			if ((yyvsp[0].symbol)->getSemanticType() != tINT)
				err_count++, fprintf (errorout, "Line# %d: Not operator cannot be applied to non-integer\n", (yyvsp[-1].symbol)->getStartLine()); 
			transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol));
		 }
#line 2040 "y.tab.c"
    break;

  case 56: /* unary_expression: factor  */
#line 495 "1905084.y"
                          { add_children_and_log (&(yyval.symbol), unary_expression, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 2046 "y.tab.c"
    break;

  case 57: /* factor: variable  */
#line 498 "1905084.y"
                   { add_children_and_log (&(yyval.symbol), factor, 1, &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); }
#line 2052 "y.tab.c"
    break;

  case 58: /* factor: ID LPAREN argument_list RPAREN  */
#line 499 "1905084.y"
                                         { 
		add_children_and_log (&(yyval.symbol), factor, 4, &(yyvsp[-3].symbol), &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
		SymbolInfo* defined = st->lookUp((yyvsp[-3].symbol)->getName());
		if (defined) {
			if (defined->isFunction()) {
				transfer_semantic (&(yyvsp[-3].symbol), &defined);
				if (arg_list && arg_list->length() > 0) {
					cout << "hello ! kuttarbaccha " << (yyvsp[-3].symbol)->getName() << endl;
					ArrayList<SymbolInfo*> *dP = defined->getParams();
					for (arg_list->moveToStart(), dP->moveToStart(); 
						dP->currPos() < dP->length() && arg_list->currPos() < arg_list->length(); 
						arg_list->next(), dP->next()) {
							SymbolInfo *arg = arg_list->getValue(), *dParam = dP->getValue();
							if (arg->getSemanticType() == tINT && dParam->getSemanticType() == tFLOAT) arg->setSemanticType(tFLOAT);
							if (arg->getSemanticType() != dParam->getSemanticType() || arg->isArray() != dParam->isArray()) {
								err_count++, fprintf (errorout, "Line# %d: Type mismatch for argument %d of '%s'\n", 
													arg->getStartLine(), arg_list->currPos()+1, (yyvsp[-3].symbol)->getName());
							};
					};
					if (arg_list->length() > dP->length()) 
						err_count++, fprintf (errorout, "Line# %d: Too many arguments to function '%s'\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName());
					else if (arg_list->length() < dP->length()) 
						err_count++, fprintf (errorout, "Line# %d: Too few arguments to function '%s'\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName());	
					delete arg_list;
					arg_list = nullptr;
				};
			} else err_count++, fprintf (errorout, "Line# %d: '%s' is not a function\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName()); 
		} else err_count++, fprintf (errorout, "Line# %d: Undeclared function '%s'\n", (yyvsp[-3].symbol)->getStartLine(), (yyvsp[-3].symbol)->getName()); 
		transfer_semantic (&(yyval.symbol), &(yyvsp[-3].symbol)); 
	}
#line 2087 "y.tab.c"
    break;

  case 59: /* factor: LPAREN expression RPAREN  */
#line 529 "1905084.y"
                                   { add_children_and_log (&(yyval.symbol), factor, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-1].symbol)); }
#line 2093 "y.tab.c"
    break;

  case 60: /* factor: CONST_INT  */
#line 530 "1905084.y"
                     { 
		add_children_and_log (&(yyval.symbol), factor, 1, &(yyvsp[0].symbol));
		if (!strtol((yyvsp[0].symbol)->getName(), nullptr, 10)) (yyvsp[0].symbol)->setZero();
		transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); 
	}
#line 2103 "y.tab.c"
    break;

  case 61: /* factor: CONST_FLOAT  */
#line 535 "1905084.y"
                      { 
		add_children_and_log (&(yyval.symbol), factor, 1, &(yyvsp[0].symbol));
		if (strtof((yyvsp[0].symbol)->getName(), nullptr) == 0.0f) (yyvsp[0].symbol)->setZero();
		transfer_semantic (&(yyval.symbol), &(yyvsp[0].symbol)); 
	}
#line 2113 "y.tab.c"
    break;

  case 62: /* factor: variable INCOP  */
#line 540 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), factor, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-1].symbol)); }
#line 2119 "y.tab.c"
    break;

  case 63: /* factor: variable DECOP  */
#line 541 "1905084.y"
                         { add_children_and_log (&(yyval.symbol), factor, 2, &(yyvsp[-1].symbol), &(yyvsp[0].symbol)), transfer_semantic (&(yyval.symbol), &(yyvsp[-1].symbol)); }
#line 2125 "y.tab.c"
    break;

  case 64: /* argument_list: arguments  */
#line 544 "1905084.y"
                          { add_children_and_log (&(yyval.symbol), argument_list, 1, &(yyvsp[0].symbol)); }
#line 2131 "y.tab.c"
    break;

  case 65: /* argument_list: %empty  */
#line 545 "1905084.y"
                            { add_children_and_log (&(yyval.symbol), argument_list, 0); }
#line 2137 "y.tab.c"
    break;

  case 66: /* arguments: arguments COMMA logic_expression  */
#line 548 "1905084.y"
                                             { 
				add_children_and_log (&(yyval.symbol), arguments, 3, &(yyvsp[-2].symbol), &(yyvsp[-1].symbol), &(yyvsp[0].symbol));
				arg_list->append((yyvsp[0].symbol));
		  }
#line 2146 "y.tab.c"
    break;

  case 67: /* arguments: logic_expression  */
#line 552 "1905084.y"
                                 { 
				add_children_and_log (&(yyval.symbol), arguments, 1, &(yyvsp[0].symbol)); 
				arg_list = new ArrayList<SymbolInfo*>();
				arg_list->append((yyvsp[0].symbol));
		  }
#line 2156 "y.tab.c"
    break;


#line 2160 "y.tab.c"

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

#line 559 "1905084.y"


int main (int argc, char *argv[]) {
	fp = fopen(argv[1],"r");
	if (!fp) {
		printf("Cannot Open Input File.\n");
		exit(1);
	};
	parseout = fopen("parsetree.txt","w");
	errorout = fopen("error.txt","w");
	logout = fopen("log.txt","w");
	if (argc > 2) asmout = fopen(argv[2], "w");
	else asmout = fopen("output.asm", "w");
	datasegout = fopen(".data_seg.asm", "w");
	init_strings();
	yyin = fp;
	st = new SymbolTable(11);

	yyparse();
 	fprintf(logout, "Total Lines: %d\n", line_count);
 	fprintf(logout, "Total Errors: %d\n", err_count);
	fclose(parseout), fclose(errorout), fclose(logout);
	
	return 0;
};
