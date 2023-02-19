#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include "1905084_SymbolTable.hpp"
#include "1905084_data.h"


extern char *NON_TERMINAL, *tINT, *tFLOAT, *tVOID, *start, *program, *unit, *func_declaration, *func_definition, *parameter_list, 
            *compound_statement, *var_declaration, *type_specifier, *declaration_list, *statements, *statement, *expression_statement, 
            *variable, *expression, *logic_expression, *rel_expression, *simple_expression, *term, *unary_expression, *factor, 
            *argument_list, *arguments;

extern FILE *asmout, *parseout;

extern SymbolInfo* scope_function;
extern int line_count, err_count, stack_offset, label_count;

bool gen_if_cond = false, gen_for_cond = false, gen_while_cond = false;

int traversal_line = 0;


void fprint_var_name_code (SymbolInfo* var) {
	if (var->isGlobal()) fprintf(asmout, "%s", var->getName());
	else fprintf(asmout, "[BP-%d]", var->getStackOffset());
};

void fprint_label (int label = ++label_count) {
    fprintf (asmout, "L%d:\t\t;line-%d\n", label, traversal_line);
};

int new_label() {
	label_count++;
	return label_count;
};

void fprint_code (SymbolInfo* node, bool force_bool = false) {
	traversal_line = node->getStartLine();
	if (!node) return;
	//for (int i=0; i<depth; i++) fprintf(asmout, "\t");
	if (node->getType() == NON_TERMINAL) {
		// fprint_rule (node, parseout);
		// fprintf(parseout, "\t<Line: %d-%d>\n", node->getStartLine(), node->getEndLine());
		if (node->getName() == func_definition) {
			SymbolInfo* comp_stat;
			if (node->getChild(3)->getName() == parameter_list) comp_stat = node->getChild(5);
			else comp_stat = node->getChild(4);

			fprintf (asmout, "%s PROC\n", node->getChild(1)->getName());
			if (!strcmp(node->getChild(1)->getName(), "main")) fprintf(asmout, "\tMOV AX, @DATA\n\tMOV DS, AX\n");
			fprint_code (comp_stat);
            if (!strcmp(node->getChild(1)->getName(), "main")) fprintf(asmout, "\tMOV AX, 4CH\n\tINT 21H\n");
			fprintf (asmout, "%s ENDP\n", node->getChild(1)->getName());

		} else if (node->getName() == compound_statement) {
			if (node->getChild(1)->getName() == statements) {
				fprint_code (node->getChild(1));
                // fprint_new_label();
				fprintf (asmout, "\n\tADD SP, %d\n\tPOP BP\n", node->getVarDecCount() * 2);
			};	
		} else if (node->getName() == statements) {
			node->setNextLabel(new_label());    // P -> S {S.next = newlabel()}
			if (node->getChildrenCount() == 1) {
				node->getFirstChild()->setNextLabel(node->getNextLabel());
				fprint_code (node->getFirstChild());					//S.code()
				//fprint_label(node->getFirstChild()->getNextLabel());	//label(S.next)
			} else if (node->getChildrenCount() > 1) {
				node->getFirstChild()->setNextLabel(new_label());			//S1.next = newlabel()
				node->getChild(1)->setNextLabel(node->getNextLabel());	//S2.next = S.next
				fprint_code (node->getFirstChild());					//S1.code()
				fprint_label(node->getFirstChild()->getNextLabel());	//label(S1.next)
				fprint_code (node->getLastChild());					//S2.code()
			};
		} else if (node->getName() == statement) {
			// cout << "found if" << endl;
			//fprintf(asmout, "STATEMENT! %d %d\n", node->getStartLine(), node->getEndLine());
			if (node->getFirstChild()->getName() == var_declaration) {
				fprintf(asmout, "\tPUSH BP\n\tMOV BP, SP\n\tSUB SP, %d\n", node->getFirstChild()->getVarDecCount() * 2);
			} else if (node->getFirstChild()->getName() == compound_statement) {
                if (node->getFirstChild()->getChild(1)->getName() == statements) 
					fprint_code (node->getFirstChild()->getChild(1));
            } else if (node->getFirstChild()->getName() == expression_statement) {
				fprint_code (node->getFirstChild());
			} else if (!strcmp(node->getFirstChild()->getType(), "PRINTLN")) {
				node->getFirstChild()->setNextLabel(new_label());	
				//fprint_label(node->getFirstChild()->getNextLabel());
				SymbolInfo* var = node->getChild(2)->getFirstChild();
				fprintf (asmout, "\tMOV AX, ");
				fprint_var_name_code (var);
				fprintf(asmout, "\n\tCALL print_output\n\tCALL new_line\n");
			} else if (!strcmp(node->getFirstChild()->getType(), "IF") && node->getChildrenCount() == 5) {
                gen_if_cond = true;
				node->getChild(2)->setTrueLabel(new_label());
				cout << node->getChild(2)->getTrueLabel() << endl;
				node->getLastChild()->setNextLabel(node->getNextLabel());
				node->getChild(2)->setFalseLabel(node->getLastChild()->getNextLabel());
                fprint_code (node->getChild(2), true);
                fprint_label(node->getChild(2)->getTrueLabel());
                //cout << node->getLastChild()->getFirstChild()->getName() << endl;
				cout << node->getChild(2)->getTrueLabel() << endl;
                fprint_code (node->getLastChild());
                gen_if_cond = false;
            } else if (!strcmp(node->getFirstChild()->getType(), "IF") && node->getChildrenCount() > 5) {
                gen_if_cond = true;
                // if (!else_label && !strcmp(node->getLastChild()->getFirstChild()->getType(), "IF")) {
                //     int if_depth = 0;
                //     SymbolInfo* else_then = node;
                //     while (else_then->getChildren() && !strcmp(else_then->getFirstChild()->getType(), "IF")) {
                //         if_depth++;
                //         else_then = else_then->getLastChild();
                //     };
                //     cout << "if depth: " << if_depth << endl;
                //     else_label = label_count + if_depth*2 + 3;
                // };
				node->getChild(2)->setTrueLabel(new_label());
				node->getChild(2)->setFalseLabel(new_label());
				node->getLastChild()->setNextLabel(node->getNextLabel());
				node->getChild(4)->setNextLabel(node->getLastChild()->getNextLabel());
                fprint_code (node->getChild(2), true);
                fprint_label (node->getChild(2)->getTrueLabel());
				fprint_code (node->getChild(4));
                //cout << node->getLastChild()->getFirstChild()->getName() << endl;
                // if (else_label) fprintf (asmout, "\tJMP L%d\n", else_label);
                // else  fprintf (asmout, "\tJMP L%d\n", label_count+2);
				fprintf (asmout, "\tJMP L%d\n", node->getNextLabel());
				fprint_label (node->getChild(2)->getFalseLabel());
                fprint_code (node->getLastChild());
                gen_if_cond = false;
                // if (else_label == label_count + 3) else_label = 0;
            } else if (!strcmp(node->getFirstChild()->getType(), "FOR")) {
                gen_for_cond = true;
            
				node->getChild(2)->setNextLabel(new_label());							//S1.next = newlabel()
				node->getChild(3)->setTrueLabel(new_label());							//B.true = newlabel()
				node->getChild(3)->setFalseLabel(node->getNextLabel());					//B.false = S.next
				node->getChild(4)->setNextLabel(node->getChild(2)->getNextLabel()); 	//S2.next = S1.next
				node->getChild(6)->setNextLabel(new_label());							//S3.next = newlabel()

				fprint_code (node->getChild(2)); cout << node->getChild(3)->getTrueLabel() << endl;
				fprint_label(node->getChild(2)->getNextLabel()), fprint_code (node->getChild(3), true);
				fprint_label(node->getChild(3)->getTrueLabel()), fprint_code (node->getChild(6));
				fprint_label(node->getChild(6)->getNextLabel()), fprint_code (node->getChild(4));
				fprintf (asmout, "\tJMP L%d\n", node->getChild(2)->getNextLabel());
                // fprintf (asmout, "\tPOP AX\n");
                // fprint_new_label();
                // fprint_code (node->getChild(4));
                // fprintf (asmout, "\tJMP L%d\n", label_count-1);
                // fprint_code (node->getChild(6));
                // fprintf (asmout, "\tJMP L%d\n", label_count-1);
                gen_for_cond = false;
            } else if (!strcmp(node->getFirstChild()->getType(), "WHILE")) {
                gen_while_cond = true;
                int begin = new_label();
				node->getChild(2)->setTrueLabel(new_label());
				node->getChild(2)->setFalseLabel(node->getNextLabel());
				node->getChild(4)->setNextLabel(begin);
				fprint_label(begin);
				cout << "printing while cond...." << endl;
                fprint_code (node->getChild(2), true);
				fprint_label(node->getChild(2)->getTrueLabel());
                fprint_code (node->getChild(4));
                fprintf (asmout, "\tJMP L%d\n", begin);
                gen_while_cond = false;
            };
        } else if (node->getName() == expression_statement) {
				//fprint_new_label();
				if (node->getFirstChild()->getName() == expression) {
					node->getFirstChild()->setTrueLabel (node->getTrueLabel());
					node->getFirstChild()->setFalseLabel(node->getFalseLabel());
					node->getFirstChild()->setNextLabel (node->getNextLabel());
					fprint_code (node->getFirstChild(), force_bool);
				};		
		} else if (node->getName() == expression) {
			//fprintf(asmout, "expression!!\n");	
			cout << "force_bool: " << force_bool << endl;
			if (node->getFirstChild()->getName() == variable) {
				fprint_code (node->getLastChild());
				SymbolInfo* var = node->getFirstChild()->getFirstChild();
				//fprintf(asmout, "assignment to %s\n", var->getName());
				fprintf (asmout, "\tMOV ");
				fprint_var_name_code (var);
				fprintf(asmout, ", AX\n", var->getName());
			} else {
				node->getFirstChild()->setTrueLabel (node->getTrueLabel());
				node->getFirstChild()->setFalseLabel(node->getFalseLabel());
				node->getFirstChild()->setNextLabel (node->getNextLabel());
				fprint_code (node->getFirstChild(), force_bool);
			};
		} else if (node->getName() == logic_expression) {
			if (!node->getTrueLabel()) node->setTrueLabel(new_label());
			if (!node->getFalseLabel()) node->setFalseLabel(new_label());
			if (!node->getNextLabel()) node->setNextLabel(new_label());
			if (node->getChildrenCount() > 1) {
                //int l0, l1, l2, l3, l4;
                if (!strcmp(node->getChild(1)->getName(), "||")) {
                    //l0 = label_count + 2, l1 = label_count + 1, l2 = label_count + 2, l3 = label_count + 3, l4 = label_count + 4;
					node->getChild(0)->setTrueLabel (node->getTrueLabel());
					node->getChild(0)->setFalseLabel (new_label());
					node->getChild(2)->setTrueLabel (node->getTrueLabel());
					node->getChild(2)->setFalseLabel (node->getFalseLabel());
					fprint_code (node->getChild(0), true);
					fprint_label(node->getChild(0)->getFalseLabel());
					fprint_code (node->getChild(2), true);
					//fprintf (asmout, "\tCMP AX, 0\n\tJNE L%d\n\tJMP L%d\n", l2, l3);
				} else if (!strcmp(node->getChild(1)->getName(), "&&")) {
                    //l0 = label_count + 1, l1 = label_count + 4, l2 = label_count + 2, l3 = label_count + 3, l4 = label_count + 4;
					node->getChild(0)->setTrueLabel (new_label());
					node->getChild(0)->setFalseLabel (node->getFalseLabel());
					node->getChild(2)->setTrueLabel (node->getTrueLabel());
					node->getChild(2)->setFalseLabel (node->getFalseLabel());
					fprint_code (node->getChild(0), true);
					//fprintf (asmout, "\tCMP AX, 0\n\tJNE L%d\n\tJMP L%d\n", l0, l1);
					fprint_label(node->getChild(0)->getTrueLabel());
					fprint_code (node->getChild(2), true);
					//fprintf (asmout, "\tCMP AX, 0\n\tJNE L%d\n\tJMP L%d\n", l2, l3);
				};
                if (!gen_if_cond && !gen_for_cond && !gen_while_cond) {
                    fprint_label(node->getTrueLabel());
                    fprintf (asmout, "\tMOV AX, 1\n\tJMP L%d\n", node->getNextLabel());
                    fprint_label(node->getFalseLabel());
                    fprintf (asmout, "\tMOV AX, 0\n");
                    fprint_label(node->getNextLabel());
                };
			} else {
				node->getFirstChild()->setTrueLabel (node->getTrueLabel());
				node->getFirstChild()->setFalseLabel(node->getFalseLabel());
				node->getFirstChild()->setNextLabel (node->getNextLabel());
				fprint_code (node->getFirstChild(), force_bool);
			};
		} else if (node->getName() == rel_expression) {
			if (node->getChildrenCount() > 1) {
				cout << node->getTrueLabel() << endl;
				if (!node->getTrueLabel()) node->setTrueLabel(new_label());
				if (!node->getFalseLabel()) node->setFalseLabel(new_label());
				if (!node->getNextLabel()) node->setNextLabel(new_label());
                fprint_code (node->getChild(2));
                fprintf (asmout, "\tMOV DX, AX\n");
				fprint_code (node->getFirstChild());
                fprintf (asmout, "\tCMP AX, DX\n\t");
                if (!strcmp(node->getChild(1)->getName(), "<")) fprintf(asmout, "JL");
                else if (!strcmp(node->getChild(1)->getName(), "<=")) fprintf(asmout, "JLE");
                else if (!strcmp(node->getChild(1)->getName(), ">")) fprintf(asmout, "JG");
                else if (!strcmp(node->getChild(1)->getName(), ">=")) fprintf(asmout, "JGE");
                else if (!strcmp(node->getChild(1)->getName(), "==")) fprintf(asmout, "JE");
                else if (!strcmp(node->getChild(1)->getName(), "!=")) fprintf(asmout, "JNE");
                // if (gen_for_cond) fprintf (asmout, " L%d\n\tJMP L%d\n", label_count+2, label_count+3);
                // else if (gen_while_cond) fprintf (asmout, " L%d\n\tJMP L%d\n", label_count+1, label_count+3);
                // else if (gen_if_cond) fprintf (asmout, " L%d\n\tJMP L%d\n", label_count+1, label_count+2);
				cout << node->getTrueLabel() << endl;
				fprintf (asmout, " L%d\n\tJMP L%d\n", node->getTrueLabel(), node->getFalseLabel());
                if (!gen_if_cond && !gen_for_cond && !gen_while_cond) {
                    fprint_label(node->getTrueLabel());
                    fprintf (asmout, "\tMOV AX, 1\n\tJMP L%d\n", node->getNextLabel());
                    fprint_label(node->getFalseLabel());
                    fprintf (asmout, "\tMOV AX, 0\n");
                    fprint_label(node->getNextLabel());
                };
			} else {
				node->getFirstChild()->setTrueLabel (node->getTrueLabel());
				node->getFirstChild()->setFalseLabel(node->getFalseLabel());
				node->getFirstChild()->setNextLabel (node->getNextLabel());
				if (force_bool) {
					if (!node->getTrueLabel()) node->setTrueLabel(new_label());
					if (!node->getFalseLabel()) node->setFalseLabel(new_label());
					if (!node->getNextLabel()) node->setNextLabel(new_label());
				};	
				fprint_code (node->getFirstChild());
				if (force_bool) {
					fprintf (asmout, "\tCMP AX, 0\n\tJNE L%d\n\tJMP L%d\n", node->getTrueLabel(), node->getFalseLabel());
				};	
			};
		} else if (node->getName() == simple_expression) {
			if (node->getFirstChild()->getName() == term) fprint_code (node->getFirstChild());
			else {
				fprint_code (node->getChild(0));
				fprintf (asmout, "\tMOV BX, AX\n");
				fprint_code (node->getChild(2));
                //fprintf (asmout, "\tMOV BX, AX\n");
				if (!strcmp(node->getChild(1)->getName(), "+")) fprintf (asmout, "\tADD AX, BX\n");
				else if (!strcmp(node->getChild(1)->getName(), "-")) fprintf (asmout, "\tSUB BX, AX\n\tPUSH BX\n\tPOP AX\n");
				//fprintf (asmout, "AX, DX\n");
			};
		} else if (node->getName() == term) {
			if (node->getFirstChild()->getName() == unary_expression) fprint_code (node->getFirstChild());
			else {
				fprint_code (node->getChild(0));
				fprintf (asmout, "\tMOV CX, AX\n");
				fprint_code (node->getChild(2));
				if (!strcmp(node->getChild(1)->getName(), "*")) fprintf (asmout, "\tMUL CX\n");
				else {
                    fprintf (asmout, "\tCWD\n\tPUSH AX\n\tPUSH CX\n\tPOP AX\n\tPOP CX\n");
					fprintf (asmout, "\tDIV CX\n");
					if (!strcmp(node->getChild(1)->getName(), "%")) fprintf (asmout, "\tPUSH DX\n\tPOP AX\n");
				};
			}
		} else if (node->getName() == unary_expression) {
			if (node->getFirstChild()->getName() == factor) fprint_code (node->getFirstChild());
			else if (!strcmp(node->getFirstChild()->getType(), "ADDOP")) {
				fprint_code (node->getChild(1));
				if (!strcmp(node->getFirstChild()->getName(), "-")) 
					fprintf (asmout, "\tNEG AX\n");
			}
		} else if (node->getName() == factor) {
			if (!strcmp(node->getFirstChild()->getType(), "CONST_INT")) {
				fprintf (asmout, "\tMOV AX, %s\n", node->getFirstChild()->getName());
			} else if (node->getFirstChild()->getName() == variable && node->getChildrenCount() == 1) {
				fprintf (asmout, "\tMOV AX, ");
				fprint_var_name_code (node->getFirstChild()->getFirstChild());
				fprintf (asmout, "\n");
			} else if (node->getChild(1)->getName() == expression) {
                fprintf(asmout, "\tPUSH BX\n\tPUSH CX\n");
				fprint_code (node->getChild(1));
                fprintf(asmout, "\tPOP CX\n\tPOP BX\n");
			} else if (!strcmp(node->getChild(1)->getType(), "INCOP")) {
				SymbolInfo* var = node->getChild(0)->getFirstChild();
                // fprintf (asmout, "\tPUSH AX\n\tMOV AX, ");
                // fprint_var_name_code (var);
				fprintf (asmout, "\tMOV AX, ");
                fprint_var_name_code (var);
				fprintf (asmout, "\n\tPUSH AX\n");
                fprintf (asmout, "\tINC AX\n\tMOV ");
                fprint_var_name_code (var);
                fprintf (asmout, ", AX\n\tPOP AX\n");
			} else if (!strcmp(node->getChild(1)->getType(), "DECOP")) {
				SymbolInfo* var = node->getChild(0)->getFirstChild();
                fprintf (asmout, "\tMOV AX, ");
                fprint_var_name_code (var);
				fprintf (asmout, "\n\tPUSH AX\n");
                fprintf (asmout, "\tDEC AX\n\tMOV ");
                fprint_var_name_code (var);
                fprintf (asmout, ", AX\n\tPOP AX\n");
			} 

		} else {
			ArrayList<SymbolInfo*> *children = node->getChildren();
			if (!children) return;
			for (children->moveToStart(); children->currPos() < children->length(); children->next()) {
				SymbolInfo* x = children->getValue();
				if (!x) continue;
				fprint_code (x);
			};
		};
	} else {
		fprintf(parseout, "%s : %s", node->getType(), node->getName());
		fprintf(parseout, "\t<Line: %d>\n", node->getStartLine());
	}
};
