#include <cstring>

extern char *NON_TERMINAL, *tINT, *tFLOAT, *tVOID, *start, *program, *unit, *func_declaration, *func_definition, *parameter_list, 
            *compound_statement, *var_declaration, *type_specifier, *declaration_list, *statements, *statement, *expression_statement, 
            *variable, *expression, *logic_expression, *rel_expression, *simple_expression, *term, *unary_expression, *factor, 
            *argument_list, *arguments;

void init_strings() {
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
};