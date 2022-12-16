%option noyywrap

%{

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "1905084_SymbolTable.hpp"

using namespace std;

int line_count = 1, err_count = 0;
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

void log_token (const char* token) {
	fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n", line_count, token, yytext);
};

void log_err (const char* err) {
	fprintf(logout,"Error at line# %d: %s %s\n", line_count, err, yytext);
	err_count++;
};

void print_and_log_token (const char* token) {
	fprintf(tokenout,"<%s, %s>\n", token, yytext);
	log_token (token);
};

void print_and_log_keyword() {
	char* y = str_upr(yytext);
	print_and_log_token (y);
	delete y;
};

char unescape_seq (char escape_seq) {
	switch (escape_seq) {
		case 'n' : return '\n';
		case 't' : return '\t';
		case '\\': return '\\';
		case '\'': return '\'';
		case '\"': return '\"';
		case 'a' : return '\a';
		case 'f' : return '\f';
		case 'r' : return '\r';
		case 'b' : return '\b';
		case 'v' : return '\v';
		case '0' : return '\0';
	};
	return 0;
};

void newline_check() {
	for (int i=0; i<strlen(yytext); i++) 
		if (yytext[i]=='\n') line_count++;
		else if (yytext[i]=='\r' && yytext[i+1]=='\n') i++, line_count++;
};

void string_action (bool multi) {
	if (multi) log_token("MULTI LINE STRING");
	else log_token("SINGLE LINE STRING");
	char* str = new char[strlen(yytext)+2];
	int srcI = 1, dstI = 0;
	//for (int i=0; i<strlen(yytext); i++) cout << yytext[i] << " " << (int)(yytext[i]) << endl;
	//cout << endl;
	while (yytext[srcI] != '\"') {
		//if (yytext[srcI] == 13) srcI++;
		if (yytext[srcI] == '\\') {
			srcI++;
			if (yytext[srcI] == ' ' || yytext[srcI] == '\t') {
				while (yytext[srcI] != '\n' && yytext[srcI] != '\r') srcI++;
			} else if (yytext[srcI] == '\n') {
				srcI++;
			} else if (yytext[srcI] == '\r') {
				srcI += 2;
			} else {
				str[dstI] = unescape_seq(yytext[srcI]);
				//cout << str[dstI] << " " << (int)(str[dstI]) << " >>>> " << dstI << endl;
				srcI++, dstI++;
			};
		} else {
			str[dstI] = yytext[srcI];
			//cout << str[dstI] << " " << (int)(str[dstI]) << " >>>> " << dstI << endl;
			srcI++, dstI++;
		};
	};
	//cout << __LINE__ <<  " " << dstI << endl;
	str[dstI] = '\0';
	if (multi) fprintf(tokenout,"<%s, %s>\n", "MULTI LINE STRING", str);
	else fprintf(tokenout,"<%s, %s>\n", "SINGLE LINE STRING", str);
	delete str;
};

%}

WSCHAR [ \t\f\r\v]
WHITESPACE {WSCHAR}+ 
LETTER [a-zA-Z]
DIGIT [0-9]
ALNUM {LETTER}|{DIGIT}
NEWLINE (\r)?\n

DIGITS {DIGIT}+

FRAC ({DIGIT}*(\.){DIGITS})|({DIGITS}(\.))
EXTRAFRAC {DIGIT}*(\.){DIGITS}(\.)({DIGITS}|(\.))*

EXP [eE][-+]?{DIGITS}
FRACEXP [eE][-+]?({FRAC}|{EXTRAFRAC})
FLOATING ({FRAC}{EXP}?)|({DIGITS}{EXP})
ILLFORMED ({EXTRAFRAC}{EXP}?)|({FRAC}{FRACEXP}?)|({EXTRAFRAC}{FRACEXP}?)|({DIGITS}{FRACEXP})

CHARACTER [^'"\\\n\r]|(\\[nt\\'"afrbv0])
CHARLIT (')({CHARACTER}|[\"])(')
MULTICHARLIT (')({CHARACTER}|[\"])({CHARACTER}|[\"])+(')
UNFINCHARLIT (')({CHARACTER}|[\"])*
EMPTYCHARLIT (\'\')

SLSTR ({CHARACTER}|['])*
MLSTR ({CHARACTER}|[']|(\\{WHITESPACE}?{NEWLINE}))*
SLSTRLIT (\"){SLSTR}(\")
MLSTRLIT (\"){MLSTR}(\")
UNFINSTRLIT (\")({MLSTR}|{SLSTR})

SLCMTSTR ([^\r\n])*
MLCMTSTR ([^\r\n]|(\\{WHITESPACE}?{NEWLINE}))*
SLCMT \/\/({SLCMTSTR}|{MLCMTSTR})
MLCMT (\/\*)([^*]|((\*)+[^/*]))*(\*)+(\/)
UNFINCMT (\/\*)([^*]|((\*)+[^/*]))*(\*)*

%%

	//==================================== SECTION - 2 ==================================

{WHITESPACE} { /*do nothing*/}
{NEWLINE} 	 { line_count++; }

{SLCMT} 	{ log_token("SINGLE LINE COMMENT"), newline_check(); }
{MLCMT}		{ log_token("MULTI LINE COMMENT"), newline_check(); }
{UNFINCMT} 	{ newline_check(), log_err("UNFINISHED_COMMENT"); }

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
"continue"	{ print_and_log_keyword(); }		

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


{DIGITS} 	{ print_and_log_token("CONST_INT"); }
{EXTRAFRAC} { log_err("TOO_MANY_DECIMAL_POINTS"); }
{FLOATING} 	{ print_and_log_token("CONST_FLOAT"); }
{ILLFORMED} { log_err("ILLFORMED_NUMBER"); }

{CHARLIT} {
	if (yytext[1] != '\\') {
		fprintf(tokenout,"<%s, %c>\n", "CONST_CHAR", yytext[1]);
		fprintf(logout,"Line# %d: Token <CONST_CHAR> Lexeme %c found\n", line_count, yytext[1]);
	} else {
		char actual = unescape_seq(yytext[2]);
		fprintf(tokenout,"<%s, %c>\n", "CONST_CHAR", actual);
		fprintf(logout,"Line# %d: Token <CONST_CHAR> Lexeme %c found\n", line_count, actual);
	};
}

{MULTICHARLIT} { log_err("MULTICHAR_CONST_CHAR"); }
{UNFINCHARLIT} { log_err("UNFINISHED_CONST_CHAR"); }
{EMPTYCHARLIT} { log_err("EMPTY_CONST_CHAR"); }

{SLSTRLIT} 		{ string_action(false), newline_check(); }
{MLSTRLIT} 		{ string_action(true), newline_check(); }
{UNFINSTRLIT} 	{ newline_check(), log_err("UNFINISHED_STRING"); }

({LETTER}|_)({ALNUM}|_)* {
	print_and_log_token("ID");
	char* id = new char[5]; strcpy(id, "ID");
	char* lexeme = new char[strlen(yytext)+2]; strcpy(lexeme, yytext);
	if (st->insert(lexeme, id))	st->printAllScope(logout);
	else fprintf(logout,"\t%s already exisits in the current ScopeTable\n", lexeme);
}

({DIGIT}|_)({ALNUM}|_)* { log_err("INVALID_ID_SUFFIX_NUM_PREFIX"); }

. { log_err("UNRECOGNIZED_CHAR"); }

%%

//==================================== SECTION - 3 ============================================

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
	
	logout = fopen("1905084_log.txt","w");
	tokenout = fopen("1905084_token.txt","w");

	yyin = fin;
	yylex();
	st->printAllScope(logout);
	fprintf(logout, "Total lines: %d\n", line_count);
	fprintf(logout, "Total errors: %d\n", err_count);
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
};
