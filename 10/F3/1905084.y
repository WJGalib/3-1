%{
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
ArrayList<SymbolInfo*> *var_list, *param_list;

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

%}

%union {
	SymbolInfo* symbol;
}

%token <symbol> IF ELSE FOR WHILE INT FLOAT DOUBLE CHAR VOID RETURN ADDOP MULOP INCOP DECOP LOGICOP RELOP ASSIGNOP BITOP NOT LPAREN RPAREN LCURL RCURL LSQUARE RSQUARE COMMA SEMICOLON CONST_INT CONST_FLOAT CONST_CHAR SINGLE_LINE_STRING MULTI_LINE_STRING ID PRINTLN

%type <symbol> start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement variable expression logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments 


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%

start : program {
		add_children_and_log (&$$, start, 1, &$1);
		print_parse_tree ($$);
	}
	;

program : program unit { add_children_and_log (&$$, program, 2, &$1, &$2); }
	| unit { add_children_and_log (&$$, program, 1, &$1); }
	;
	
unit : var_declaration  { add_children_and_log (&$$, unit, 1, &$1); }
     | func_declaration  { add_children_and_log (&$$, unit, 1, &$1); }
     | func_definition  { add_children_and_log (&$$, unit, 1, &$1); }
     ;
     
func_declaration : type_specifier ID LPAREN start_func_scope parameter_list RPAREN SEMICOLON { 
			for (param_list->moveToStart(); param_list->currPos() < param_list->length(); param_list->next()) {
				SymbolInfo *param = param_list->getValue(), *lu = st->lookUpCurrentScope(param->getName());
				if (lu != nullptr) {
					fprintf (errorout, "Line# %d: Redefinition of parameter '%s'\n", lu->getStartLine(), param->getName()); 
					break;
				};
				st->insert(param);
			};
			delete param_list;
			$2->setSemanticType ($1->getSemanticType()), $2->setFunction();
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
			st->insertToParentScope($2);
			//st->printAllScope(logout);
			st->exitScope();
			add_children_and_log (&$$, func_declaration, 6, &$1, &$2, &$3, &$5, &$6, &$7); 
		}
		| type_specifier ID LPAREN RPAREN SEMICOLON  { 
			$2->setSemanticType ($1->getSemanticType()), $2->setFunction();
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
			st->insert($2);
			//st->printAllScope(logout);
			add_children_and_log (&$$, func_declaration, 5, &$1, &$2, &$3, &$4, &$5); 
		}
		;
		 
func_definition : type_specifier ID LPAREN start_func_scope parameter_list RPAREN compound_statement { 
			for (param_list->moveToStart(); param_list->currPos() < param_list->length(); param_list->next()) {
				SymbolInfo* param = param_list->getValue();
				if (st->lookUpCurrentScope(param->getName())) {
					fprintf (errorout, "Line# %d: Redefinition of parameter '%s'\n", line_count, param->getName()); 
					break;
				};
				st->insert(param);
			};
			delete param_list;
			$2->setSemanticType ($1->getSemanticType()), $2->setFunction();
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
			st->insertToParentScope($2);
			st->printAllScope(logout);
			st->exitScope();
			add_children_and_log (&$$, func_definition, 6, &$1, &$2, &$3, &$5, &$6, &$7); 
		}
		| type_specifier ID LPAREN RPAREN start_func_scope compound_statement { 
			$2->setSemanticType ($1->getSemanticType()), $2->setFunction();
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
			st->insertToParentScope($2);
			st->printAllScope(logout);
			st->exitScope();
			add_children_and_log (&$$, func_definition, 5, &$1, &$2, &$3, &$4, &$6); 
		}
 		;				

start_func_scope : {
	st->enterScope();
	function_scope = true ;
}

parameter_list  : parameter_list COMMA type_specifier ID  { 
			add_children_and_log (&$$, parameter_list, 4, &$1, &$2, &$3, &$4);
			$4->setSemanticType ($3->getSemanticType());
			 param_list->append($4);
			//cout << st->getCurrScopeId() << " " << $4->getName() << endl;
		}
		| parameter_list COMMA type_specifier { 
			add_children_and_log (&$$, parameter_list, 3, &$1, &$2, &$3); 
			param_list->append($3);
		}	
 		| type_specifier ID { 
			add_children_and_log (&$$, parameter_list, 2, &$1, &$2); 
			param_list = new ArrayList<SymbolInfo*>();
			$2->setSemanticType ($1->getSemanticType());
			param_list->append($2);
			//cout << st->getCurrScopeId() << " " << $2->getName() << endl;
		}
		| type_specifier { 
			add_children_and_log (&$$, parameter_list, 1, &$1); 
			param_list = new ArrayList<SymbolInfo*>();
			param_list->append($1);
		}
 		;

 		
compound_statement : LCURL {if (!function_scope) st->enterScope();} statements RCURL  { 
				add_children_and_log (&$$, compound_statement, 3, &$1, &$3, &$4); 
				if (!function_scope) {
					st->printAllScope(logout);
					st->exitScope();
				};
				function_scope = false;
			}	
 		    | LCURL RCURL { add_children_and_log (&$$, compound_statement, 2, &$1, &$2); }
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON {
			add_children_and_log (&$$, var_declaration, 3, &$1, &$2, &$3);
			for (var_list->moveToStart(); var_list->currPos() < var_list->length(); var_list->next()) {
				SymbolInfo* var = var_list->getValue();
				var->setSemanticType ($1->getSemanticType());
				st->insert(var);
			};
			delete var_list;
		 }
 		 ;
 		 
type_specifier	: INT { add_children_and_log (&$$, type_specifier, 1, &$1), $$->setSemanticType($1->getType()); }
 		| FLOAT	{ add_children_and_log (&$$, type_specifier, 1, &$1), $$->setSemanticType($1->getType()); }
 		| VOID	{ add_children_and_log (&$$, type_specifier, 1, &$1), $$->setSemanticType($1->getType()); }
 		;
 		
declaration_list : declaration_list COMMA ID {
			add_children_and_log (&$$, declaration_list, 3, &$1, &$2, &$3);
			var_list->append($3);
		  }
 		  | declaration_list COMMA ID LSQUARE CONST_INT RSQUARE {
			add_children_and_log (&$$, declaration_list, 6, &$1, &$2, &$3, &$4, &$5, &$6);
			$3->setArray();
			var_list->append($3);
		  }
 		  | ID {
			add_children_and_log (&$$, declaration_list, 1, &$1);
			var_list = new ArrayList<SymbolInfo*>();
			var_list->append($1);
		  }
 		  | ID LSQUARE CONST_INT RSQUARE {
			add_children_and_log (&$$, declaration_list, 4, &$1, &$2, &$3, &$4);
			var_list = new ArrayList<SymbolInfo*>();
			$1->setArray();
			var_list->append($1);
		  }
 		  ;
 		  
statements : statement { add_children_and_log (&$$, statements, 1, &$1); }
	   | statements statement { add_children_and_log (&$$, statements, 2, &$1, &$2); }
	   ;
	   
statement : var_declaration { add_children_and_log (&$$, statement, 1, &$1); }
	  | expression_statement { add_children_and_log (&$$, statement, 1, &$1); }
	  | compound_statement { add_children_and_log (&$$, statement, 1, &$1); }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement { add_children_and_log (&$$, statement, 7, &$1, &$2, &$3, &$4, &$5, &$6, &$7); }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE { add_children_and_log (&$$, statement, 5, &$1, &$2, &$3, &$4, &$5); }
	  | IF LPAREN expression RPAREN statement ELSE statement { add_children_and_log (&$$, statement, 7, &$1, &$2, &$3, &$4, &$5, &$6, &$7); }
	  | WHILE LPAREN expression RPAREN statement { add_children_and_log (&$$, statement, 5, &$1, &$2, &$3, &$4, &$5); }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON { add_children_and_log (&$$, statement, 5, &$1, &$2, &$3, &$4, &$5); }
	  | RETURN expression SEMICOLON { add_children_and_log (&$$, statement, 3, &$1, &$2, &$3); }
	  ;
	  
expression_statement : SEMICOLON { add_children_and_log (&$$, expression_statement, 1, &$1); }
			| expression SEMICOLON  { add_children_and_log (&$$, expression_statement, 2, &$1, &$2); }
			;
	  
variable : ID { add_children_and_log (&$$, variable, 1, &$1); }
	 | ID LSQUARE expression RSQUARE { add_children_and_log (&$$, variable, 4, &$1, &$2, &$3, &$4); }
	 ;
	 
expression : logic_expression { add_children_and_log (&$$, expression, 1, &$1); }
	   | variable ASSIGNOP logic_expression { add_children_and_log (&$$, expression, 3, &$1, &$2, &$3); }	
	   ;
			
logic_expression : rel_expression 	{ add_children_and_log (&$$, logic_expression, 1, &$1); }
		 | rel_expression LOGICOP rel_expression { add_children_and_log (&$$, logic_expression, 3, &$1, &$2, &$3); }		
		 ;
			
rel_expression	: simple_expression { add_children_and_log (&$$, rel_expression, 1, &$1); }
		| simple_expression RELOP simple_expression	{ add_children_and_log (&$$, rel_expression, 3, &$1, &$2, &$3); }	
		;
				
simple_expression : term { add_children_and_log (&$$, simple_expression, 1, &$1); }
		  | simple_expression ADDOP term { add_children_and_log (&$$, simple_expression, 3, &$1, &$2, &$3); }	
		  ;
					
term :	unary_expression { add_children_and_log (&$$, term, 1, &$1); }
     |  term MULOP unary_expression  { add_children_and_log (&$$, term, 3, &$1, &$2, &$3); }	
     ;

unary_expression : ADDOP unary_expression  { add_children_and_log (&$$, unary_expression, 2, &$1, &$2); }
		 | NOT unary_expression { add_children_and_log (&$$, unary_expression, 2, &$1, &$2); }
		 | factor { add_children_and_log (&$$, unary_expression, 1, &$1); }
		 ;
	
factor	: variable { add_children_and_log (&$$, factor, 1, &$1); }
	| ID LPAREN argument_list RPAREN { add_children_and_log (&$$, factor, 4, &$1, &$2, &$3, &$4); }
	| LPAREN expression RPAREN { add_children_and_log (&$$, factor, 3, &$1, &$2, &$3); }	
	| CONST_INT  { add_children_and_log (&$$, factor, 1, &$1); }
	| CONST_FLOAT { add_children_and_log (&$$, factor, 1, &$1); }
	| variable INCOP { add_children_and_log (&$$, factor, 2, &$1, &$2); }
	| variable DECOP { add_children_and_log (&$$, factor, 2, &$1, &$2); }
	;
	
argument_list : arguments { add_children_and_log (&$$, argument_list, 1, &$1); }
			  ;
	
arguments : arguments COMMA logic_expression { add_children_and_log (&$$, arguments, 3, &$1, &$2, &$3); }	
	      | logic_expression { add_children_and_log (&$$, arguments, 1, &$1); }
	      ;
 

%%
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

