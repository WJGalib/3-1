%option noyywrap

%{

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "1905084_SymbolTable.hpp"

using namespace std;

int line_count=1;
FILE *logout, *tokenout;
SymbolTable* st = new SymbolTable(10);

char* str_upr (char* str) {
	int l = strlen(str);
	char* r = new char[l+2];
	strcpy (r, str);
	for (int i=0; i<l; i++) {
		if (r[i] >= 'a' && r[i] <= 'z') r[i] -= 32;
	};
	return r;
};

void log_token (char* token) {
	fprintf(logout,"Line# %d: TOKEN <%s> Lexeme %s found\n", line_count, token, yytext);
};

void print_and_log_token (char* token) {
	fprintf(tokenout,"<%s, %s>\n", token, yytext);
	log_token (token);
};

void print_and_log_keyword() {
	char* y = str_upr(yytext);
	fprintf(tokenout,"<%s>\n", y);
	log_token(y);
	delete y;
};

char unescape_seq (char escape_seq) {
	switch (escape_seq) {
		case 'n': return '\n';
		case 't': return '\t';
		case '\\': return '\\';
		case '\'': return '\'';
		case '\"': return '"';
		case 'a': return '\a';
		case 'f': return '\f';
		case 'r': return '\r';
		case 'b': return '\b';
		case 'v': return '\v';
		case '0': return '\0';
	};
	return 0;
};

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
ALNUM {LETTER}|{DIGIT}
EXP [eE][-+]?{DIGIT}+
NEWLINE \n
CHARACTER [^'\\']|(\\[nt\\'"afrbv0])

%%

{NEWLINE} { line_count++; }

"if"		|	
"else"		|	
"for"		|	
"while"		|
"do"		|	
"break"		|	
"int"		|	
"char"		|
"float"		|	
"double"	|	
"void"		|	
"return"	|
"switch"	|	
"case"		|	
"default"	|
"continue"	{ 	print_and_log_keyword(); }		

"+"|"-"		{ print_and_log_token("ADDOP"); }
"*"|"/"|"%"	{ print_and_log_token("MULOP"); }
"++"|"--"	{ print_and_log_token("INCOP"); }
"&&"|"||"	{ print_and_log_token("LOGICOP"); }
"&"|"|"|"^"|"<<"|">>" 		{ print_and_log_token("BITOP"); }
"<"|"<="|">"|">="|"=="|"!="	{ print_and_log_token("RELOP"); }
"="  { print_and_log_token("ASSIGNOP"); }
"!"  { print_and_log_token("NOT"); }
"("  { print_and_log_token("LPAREN"); }
")"  { print_and_log_token("RPAREN"); }
"{"  { print_and_log_token("LCURL"); st->enterScope(); }
"}"  { print_and_log_token("RCURL"); st->exitScope(); }
"["  { print_and_log_token("LSQUARE"); }
"]"  { print_and_log_token("RSQUARE"); }
","  { print_and_log_token("COMMA"); }
";"  { print_and_log_token("SEMICOLON"); }

		
{DIGIT}+ 	{ print_and_log_token("CONST_INT"); }
({DIGIT}*\.{DIGIT}+|{DIGIT}+\.){EXP}?|{DIGIT}+{EXP} 	{ print_and_log_token("CONST_FLOAT"); }

('){CHARACTER}(') {
	if (yytext[1] != '\\') {
		fprintf(tokenout,"<%s, %c>\n", "CONST_CHAR", yytext[1]);
		fprintf(logout,"Line# %d: TOKEN <CONST_CHAR> Lexeme %c found\n", line_count, yytext[1]);
	} else {
		char actual = unescape_seq(yytext[2]);
		fprintf(tokenout,"<%s, %c>\n", "CONST_CHAR", actual);
		fprintf(logout,"Line# %d: TOKEN <CONST_CHAR> Lexeme %c found\n", line_count, actual);
	};
}

({LETTER}|_)({ALNUM}|_)* {
	print_and_log_token("ID");
	char* id = new char[5]; strcpy(id, "ID");
	char* lexeme = new char[strlen(yytext)+2]; strcpy(lexeme, yytext);
	st->insert(lexeme, id);
	st->printAllScope(logout);
}


%%

int main (int argc, char** argv) {
	if (argc != 2) {
		printf("Please provide input file name and try again\n");
		return 0;
	};
	
	FILE *fin = fopen (argv[1], "r");
	if (fin == NULL){
		printf("Cannot open specified file\n");
		return 0;
	};
	
	logout = fopen("log.txt","w");
	tokenout = fopen("token.txt","w");

	yyin = fin;
	yylex();
	//st->print();
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
};
