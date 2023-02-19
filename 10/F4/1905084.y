%{

#include "1905084_code_generator.h"

using namespace std;

int yyparse(void);
int yylex(void);

int line_count = 1, err_count = 0, stack_offset = 0, label_count = 0;
extern FILE *yyin;
bool function_scope = false;
SymbolInfo* scope_function = nullptr;
FILE *fp, *parseout, *errorout, *logout, *asmout, *procsegout;

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
};

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
		fprintf(asmout, ".CODE\n");
		fprint_code ($$);

		// SymbolInfo *start_node = $1, *curr_node = nullptr;
		// curr_node = start_node;
		// ArrayList<SymbolInfo*> *children = curr_node->getChildren();
		// for (param_list->moveToStart(); param_list->currPos() < param_list->length(); param_list->next()) {

		// }
		

	}
	;

program : program unit { add_children_and_log (&$$, program, 2, &$1, &$2); }
	| unit { add_children_and_log (&$$, program, 1, &$1); }
	;
	
unit : var_declaration  { add_children_and_log (&$$, unit, 1, &$1); }
     | func_declaration  { add_children_and_log (&$$, unit, 1, &$1); }
     | func_definition  { add_children_and_log (&$$, unit, 1, &$1); }
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON { 
			transfer_semantic (&$2, &$1), $2->setFunction(), $2->setParams (param_list);
			st->insert($2);
			add_children_and_log (&$$, func_declaration, 6, &$1, &$2, &$3, &$4, &$5, &$6); 
		}
		| type_specifier ID LPAREN RPAREN SEMICOLON  { 
			transfer_semantic (&$2, &$1), $2->setFunction();
			st->insert($2);
			add_children_and_log (&$$, func_declaration, 5, &$1, &$2, &$3, &$4, &$5); 
		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
			transfer_semantic (&$2, &$1), $2->setFunction(), $2->setParams (param_list);
			st->insert($2);
			st->enterScope(); function_scope = true, scope_function = $2;
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
		} compound_statement { 
			SymbolInfo* predefined = st->lookUp($2->getName());
			if (predefined) {
				if (predefined->isFunction()) {
					if (predefined->getSemanticType() != $1->getSemanticType() || predefined->getParams()->length() != param_list->length())
						err_count++, fprintf (errorout, "Line# %d: Conflicting types for '%s'\n", $2->getStartLine(), predefined->getName()); 						
				} else {
					err_count++, fprintf (errorout, "Line# %d: '%s' redeclared as different kind of symbol\n", $2->getStartLine(), predefined->getName()); 				
				};
			};
			add_children_and_log (&$$, func_definition, 6, &$1, &$2, &$3, &$4, &$5, &$7); 
			scope_function = nullptr;
		}
		| type_specifier ID LPAREN RPAREN {	
			transfer_semantic (&$2, &$1), $2->setFunction();
			st->insert($2);
			st->enterScope(); function_scope = true, scope_function = $2; 
		} compound_statement { 
			add_children_and_log (&$$, func_definition, 5, &$1, &$2, &$3, &$4, &$6);
			scope_function = nullptr; 
		}
 		;				

parameter_list  : parameter_list COMMA type_specifier ID  { 
			add_children_and_log (&$$, parameter_list, 4, &$1, &$2, &$3, &$4);
			transfer_semantic (&$4, &$3);
			param_list->append($4);
		}
		| parameter_list COMMA type_specifier { 
			add_children_and_log (&$$, parameter_list, 3, &$1, &$2, &$3); 
			param_list->append($3);
		}	
 		| type_specifier ID { 
			add_children_and_log (&$$, parameter_list, 2, &$1, &$2); 
			param_list = new ArrayList<SymbolInfo*>();
			transfer_semantic (&$2, &$1);
			param_list->append($2);
		}
		| type_specifier { 
			add_children_and_log (&$$, parameter_list, 1, &$1); 
			param_list = new ArrayList<SymbolInfo*>();
			param_list->append($1);
		}
 		;

 		
compound_statement : LCURL {if (!function_scope) st->enterScope(); else function_scope = false;} statements RCURL  { 
				add_children_and_log (&$$, compound_statement, 3, &$1, &$3, &$4); 
				$$->setVarDecCount(st->getCurrScopeVarCount());
				st->printAllScope(logout);
				st->exitScope();
			}	
 		    | LCURL RCURL { 
				add_children_and_log (&$$, compound_statement, 2, &$1, &$2); 
				st->enterScope();
				st->exitScope();
			}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON {
			add_children_and_log (&$$, var_declaration, 3, &$1, &$2, &$3);
			bool global_dec = st->getCurrScopeId() == 1? true : false;
			for (var_list->moveToStart(); var_list->currPos() < var_list->length(); var_list->next()) {
				SymbolInfo* var = var_list->getValue();
				if ($1->getSemanticType() == tVOID) {
					err_count++, fprintf (errorout, "Line# %d: Variable or field '%s' declared void\n", var->getStartLine(), var->getName()); 
					break;
				};
				SymbolInfo* predefined = st->lookUpCurrentScope(var->getName());
				if (predefined) {
					if (predefined->getSemanticType() != $1->getSemanticType())
						err_count++, fprintf (errorout, "Line# %d: Conflicting types for'%s'\n", var->getStartLine(), predefined->getName()); 						
				};
				transfer_semantic (&var, &$1);
				if (global_dec) {
					var->setGlobal();
					fprintf(asmout, "\t%s DW 1 DUP (0000H)\n", var->getName());
				} else {
					stack_offset += 2;
					var->setStackOffset(stack_offset);
				};
				st->insert(var);
			};
			$$->setVarDecCount(var_list->length());
			st->setCurrScopeVarCount(st->getCurrScopeVarCount() + $$->getVarDecCount());
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
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement { 
			add_children_and_log (&$$, statement, 7, &$1, &$2, &$3, &$4, &$5, &$6, &$7); 
	  }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE { add_children_and_log (&$$, statement, 5, &$1, &$2, &$3, &$4, &$5); }
	  | IF LPAREN expression RPAREN statement ELSE statement { add_children_and_log (&$$, statement, 7, &$1, &$2, &$3, &$4, &$5, &$6, &$7); }
	  | WHILE LPAREN expression RPAREN statement { add_children_and_log (&$$, statement, 5, &$1, &$2, &$3, &$4, &$5); }
	  | PRINTLN LPAREN variable RPAREN SEMICOLON { add_children_and_log (&$$, statement, 5, &$1, &$2, &$3, &$4, &$5); }
	  | RETURN expression SEMICOLON { 
			add_children_and_log (&$$, statement, 3, &$1, &$2, &$3); 
			if (scope_function->getSemanticType() == tVOID) 
				err_count++, fprintf (errorout, "Line# %d: Return from void function\n", $1->getStartLine(), $1->getName()); 
	  }
	  ;
	  
expression_statement : SEMICOLON { add_children_and_log (&$$, expression_statement, 1, &$1); }
			| expression SEMICOLON  { add_children_and_log (&$$, expression_statement, 2, &$1, &$2); }
			;
	  
variable : ID { 
		SymbolInfo* defined = st->lookUp($1->getName());
		add_children_and_log (&$$, variable, 1, &$1);
		if (defined) {
			if (!defined->isFunction()) transfer_semantic (&$1, &defined);
			if (defined->isArray()) err_count++, fprintf (errorout, "Line# %d: '%s' is an array\n", $1->getStartLine(), $1->getName());
		} else err_count++, fprintf (errorout, "Line# %d: Undeclared variable '%s'\n", $1->getStartLine(), $1->getName()); 
		transfer_semantic (&$$, &$1); 
	 }
	 | ID LSQUARE expression RSQUARE { 
		SymbolInfo* defined = st->lookUp($1->getName());
		add_children_and_log (&$$, variable, 4, &$1, &$2, &$3, &$4);
		if (defined) {
			if (!defined->isFunction()) $1->setSemanticType(defined->getSemanticType());
			if (!defined->isArray()) err_count++, fprintf (errorout, "Line# %d: '%s' is not an array\n", $1->getStartLine(), $1->getName());
			if ($3->getSemanticType() != tINT) err_count++, fprintf (errorout, "Line# %d: Array subscript is not an integer\n", $1->getStartLine());
		} else err_count++, fprintf (errorout, "Line# %d: Undeclared variable '%s'\n", $1->getStartLine(), $1->getName());
		transfer_semantic (&$$, &$1); 
	 }
	 ;
	 
expression : logic_expression { add_children_and_log (&$$, expression, 1, &$1), transfer_semantic (&$$, &$1); }
		| variable ASSIGNOP logic_expression { 
			if ($3->getSemanticType() == tVOID) 
				err_count++, fprintf (errorout, "Line# %d: Void cannot be used in expression \n", $1->getStartLine());
			if ($1->getSemanticType() == tINT && $3->getSemanticType() == tFLOAT) 
				err_count++, fprintf (errorout, "Line# %d: Warning: possible loss of data in assignment of FLOAT to INT\n", $1->getStartLine());
			add_children_and_log (&$$, expression, 3, &$1, &$2, &$3), transfer_semantic (&$$, &$1);;
		}	
		;
			
logic_expression : rel_expression 	{ add_children_and_log (&$$, logic_expression, 1, &$1), transfer_semantic (&$$, &$1); }
		 | rel_expression LOGICOP rel_expression { 
			add_children_and_log (&$$, logic_expression, 3, &$1, &$2, &$3); 
			if ($1->getSemanticType() != tINT || $3->getSemanticType() != tINT)
				err_count++, fprintf (errorout, "Line# %d: Logical operator cannot be applied to non-integers\n", $1->getStartLine());
			if ($1->getSemanticType() == tVOID || $3->getSemanticType() == tVOID) $$->setSemanticType(tVOID);
			else $$->setSemanticType(tINT);
		 }		
		 ;
			
rel_expression	: simple_expression { add_children_and_log (&$$, rel_expression, 1, &$1), transfer_semantic (&$$, &$1); }
		| simple_expression RELOP simple_expression	{ 
			add_children_and_log (&$$, rel_expression, 3, &$1, &$2, &$3); 
			if ($1->getSemanticType() == tVOID) $$->setSemanticType(tVOID);
			else $$->setSemanticType(tINT);
		}	
		;
				
simple_expression : term { add_children_and_log (&$$, simple_expression, 1, &$1), transfer_semantic (&$$, &$1); }
		  | simple_expression ADDOP term { 
				add_children_and_log (&$$, simple_expression, 3, &$1, &$2, &$3);
				if ($1->getSemanticType() == tFLOAT && $3->getSemanticType() != tVOID) transfer_semantic (&$$, &$1);
				else transfer_semantic (&$$, &$3);
		  }	
		  ;
					
term :	unary_expression { add_children_and_log (&$$, term, 1, &$1), transfer_semantic (&$$, &$1); }
     |  term MULOP unary_expression  { 
			add_children_and_log (&$$, term, 3, &$1, &$2, &$3);
			if ($1->getSemanticType() == tFLOAT && $3->getSemanticType() != tVOID) transfer_semantic (&$$, &$1);
			else transfer_semantic (&$$, &$3); 
			if ((!strcmp($2->getName(), "%") || !strcmp($2->getName(), "/")) && $3->isZero()) 
				err_count++, fprintf (errorout, "Line# %d: Warning: division by zero\n", $1->getStartLine());
			if (!strcmp($2->getName(), "%")) {
				$$->setSemanticType(tINT);
				if (($1->getSemanticType() != tINT || $3->getSemanticType() != tINT)) 
					err_count++, fprintf (errorout, "Line# %d: Operands of modulus must be integers \n", $1->getStartLine());
			};
	 }	
     ;

unary_expression : ADDOP unary_expression  { add_children_and_log (&$$, unary_expression, 2, &$1, &$2), transfer_semantic (&$$, &$2); }
		 | NOT unary_expression { 
			add_children_and_log (&$$, unary_expression, 2, &$1, &$2);
			if ($2->getSemanticType() != tINT)
				err_count++, fprintf (errorout, "Line# %d: Not operator cannot be applied to non-integer\n", $1->getStartLine()); 
			transfer_semantic (&$$, &$2);
		 }
		 | factor { add_children_and_log (&$$, unary_expression, 1, &$1), transfer_semantic (&$$, &$1); }
		 ;
	
factor	: variable { add_children_and_log (&$$, factor, 1, &$1), transfer_semantic (&$$, &$1); }
	| ID LPAREN argument_list RPAREN { 
		add_children_and_log (&$$, factor, 4, &$1, &$2, &$3, &$4);
		SymbolInfo* defined = st->lookUp($1->getName());
		if (defined) {
			if (defined->isFunction()) {
				transfer_semantic (&$1, &defined);
				if (arg_list && arg_list->length() > 0) {
					cout << "hello ! kuttarbaccha " << $1->getName() << endl;
					ArrayList<SymbolInfo*> *dP = defined->getParams();
					for (arg_list->moveToStart(), dP->moveToStart(); 
						dP->currPos() < dP->length() && arg_list->currPos() < arg_list->length(); 
						arg_list->next(), dP->next()) {
							SymbolInfo *arg = arg_list->getValue(), *dParam = dP->getValue();
							if (arg->getSemanticType() == tINT && dParam->getSemanticType() == tFLOAT) arg->setSemanticType(tFLOAT);
							if (arg->getSemanticType() != dParam->getSemanticType() || arg->isArray() != dParam->isArray()) {
								err_count++, fprintf (errorout, "Line# %d: Type mismatch for argument %d of '%s'\n", 
													arg->getStartLine(), arg_list->currPos()+1, $1->getName());
							};
					};
					if (arg_list->length() > dP->length()) 
						err_count++, fprintf (errorout, "Line# %d: Too many arguments to function '%s'\n", $1->getStartLine(), $1->getName());
					else if (arg_list->length() < dP->length()) 
						err_count++, fprintf (errorout, "Line# %d: Too few arguments to function '%s'\n", $1->getStartLine(), $1->getName());	
					delete arg_list;
					arg_list = nullptr;
				};
			} else err_count++, fprintf (errorout, "Line# %d: '%s' is not a function\n", $1->getStartLine(), $1->getName()); 
		} else err_count++, fprintf (errorout, "Line# %d: Undeclared function '%s'\n", $1->getStartLine(), $1->getName()); 
		transfer_semantic (&$$, &$1); 
	}
	| LPAREN expression RPAREN { add_children_and_log (&$$, factor, 3, &$1, &$2, &$3), transfer_semantic (&$$, &$2); }	
	| CONST_INT  { 
		add_children_and_log (&$$, factor, 1, &$1);
		if (!strtol($1->getName(), nullptr, 10)) $1->setZero();
		transfer_semantic (&$$, &$1); 
	}
	| CONST_FLOAT { 
		add_children_and_log (&$$, factor, 1, &$1);
		if (strtof($1->getName(), nullptr) == 0.0f) $1->setZero();
		transfer_semantic (&$$, &$1); 
	}
	| variable INCOP { add_children_and_log (&$$, factor, 2, &$1, &$2), transfer_semantic (&$$, &$1); }
	| variable DECOP { add_children_and_log (&$$, factor, 2, &$1, &$2), transfer_semantic (&$$, &$1); }
	;
	
argument_list : arguments { add_children_and_log (&$$, argument_list, 1, &$1); }
			  | { add_children_and_log (&$$, argument_list, 0); }
			  ;
	
arguments : arguments COMMA logic_expression { 
				add_children_and_log (&$$, arguments, 3, &$1, &$2, &$3);
				arg_list->append($3);
		  }	
	      | logic_expression { 
				add_children_and_log (&$$, arguments, 1, &$1); 
				arg_list = new ArrayList<SymbolInfo*>();
				arg_list->append($1);
		  }
	      ;

%%

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
	/* datasegout = fopen(".data_seg.asm", "w"); */
	init_strings();
	yyin = fp;
	st = new SymbolTable(11);

	write_pre_code_seg();
	yyparse();
	write_predefined_procs();

 	fprintf(logout, "Total Lines: %d\n", line_count);
 	fprintf(logout, "Total Errors: %d\n", err_count);
	fclose(parseout), fclose(errorout), fclose(logout);
	
	return 0;
};