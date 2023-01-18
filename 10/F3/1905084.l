%option noyywrap

%{

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include "1905084_SymbolTable.hpp"
#include "y.tab.h"

using namespace std;

extern int line_count, err_count;
extern FILE *logout, *tokenout;
extern SymbolTable* st;
extern char *tINT, *tFLOAT, *tVOID;

// char* str_upr (char* str) {
// 	int l = strlen(str);
// 	char* r = new char[l+2];
// 	strcpy (r, str);
// 	for (int i=0; i<l; i++) {
// 		if (r[i] >= 'a' && r[i] <= 'z') r[i] -= 32;
// 	};
// 	return r;
// };

// void print_and_log_keyword() {
// 	char* y = str_upr(yytext);
// 	print_and_log_token (y);
// };


void log_token (const char* token) {
	fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n", line_count, token, yytext);
};

void log_err (const char* err) {
	fprintf(logout,"Error at line# %d: %s %s\n", line_count, err, yytext);
	err_count++;
};

void print_and_log_token (const char* token) {
	//fprintf(tokenout,"<%s, %s>\n", token, yytext);
	char* type; bool literal = false;
	if (token != tINT && token != tFLOAT && token != tVOID){ 
		type = new char[strlen(token)+2];
		strcpy (type, token);
	} else {
		type = (char*)token;
	};
	char* name = new char[strlen(yytext)+2];
	strcpy (name, yytext);
	yylval.symbol = new SymbolInfo (name, type);
	yylval.symbol->setStartLine (line_count);
	yylval.symbol->setEndLine (line_count);
	log_token (token);
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
	for (int i=0; i<strlen(yytext); i++) {
		if (yytext[i]=='\n') line_count++;
		else if (yytext[i]=='\r' && yytext[i+1]=='\n') i++, line_count++;
	};
};

char* string_action (bool multi) {
	if (multi) log_token("MULTI_LINE_STRING");
	else log_token("SINGLE_LINE_STRING");
	char* str = new char[strlen(yytext)+2];
	int srcI = 1, dstI = 0;
	while (yytext[srcI] != '\"') {
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
				srcI++, dstI++;
			};
		} else {
			str[dstI] = yytext[srcI];
			srcI++, dstI++;
		};
	};
	str[dstI] = '\0';
	// if (multi) fprintf(tokenout,"<%s, %s>\n", "MULTI_LINE_STRING", str);
	// else fprintf(tokenout,"<%s, %s>\n", "SINGLE_LINE_STRING", str);
	return str;
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
EXTRAPOINTS {EXTRAFRAC}(({EXP}|{FRACEXP}|[eE])+)?
ILLFORMED (({FRAC}|{DIGITS})({FRACEXP}|{EXP}?)+)|{FRACEXP}+|{FRAC}[eE]

NORMCHAR [^'"\\\n\r]
ESCCHAR (\\[nt\\'"afrbv0])
CCHAR {NORMCHAR}|{ESCCHAR}
CCHARPLUSDQT {CCHAR}|[\"]
CHARLIT ('){CCHARPLUSDQT}(')
MULTICHARLIT ('){CCHARPLUSDQT}{CCHARPLUSDQT}+(')
UNFINCHARLIT ('){CCHARPLUSDQT}?
EMPTYCHARLIT (')(')

CCHARPLUSSQT {CCHAR}|[']
SLSTR {CCHARPLUSSQT}*
MLSTR ({CCHARPLUSSQT}|(\\{NEWLINE}))*
SLSTRLIT (\"){SLSTR}(\")
MLSTRLIT (\"){MLSTR}(\")
UNFINSTRLIT (\")({MLSTR}|{SLSTR})

SLCMTSTR ([^\r\n]|(\\{NEWLINE})?)*
MLCMTSTR ([^*]|((\*)+[^*/]))*(\*)*
SLCMT (\/\/){SLCMTSTR}
MLCMT (\/\*){MLCMTSTR}(\*\/)
UNFINCMT (\/\*){MLCMTSTR}

IDENTIFIER ({LETTER}|_)({ALNUM}|_)*
NUMIDENTIFIER ({DIGIT}|_)({ALNUM}|_)*

%%

	//==================================== SECTION - 2 ==================================

{WHITESPACE} { /*do nothing*/}
{NEWLINE} 	 { line_count++; }

{SLCMT} 	{ log_token("SINGLE LINE COMMENT"), newline_check(); }
{MLCMT}		{ log_token("MULTI LINE COMMENT"),  newline_check(); }
{UNFINCMT} 	{ newline_check(), log_err("UNFINISHED_COMMENT"); 	 }

"if" 		{ print_and_log_token("PRINTLN");	return IF;		}	
"else"		{ print_and_log_token("ELSE"); 		return ELSE; 	}		
"for"		{ print_and_log_token("FOR"); 		return FOR; 		}	
"while"		{ print_and_log_token("WHILE"); 	return WHILE; 	}	
"int"		{ print_and_log_token(tINT); 		return INT; 		}	
"char"		{ print_and_log_token("CHAR");		return CHAR; 	}	
"float"		{ print_and_log_token(tFLOAT); 		return FLOAT; 	}	
"double"	{ print_and_log_token("DOUBLE"); 	return DOUBLE; 	}	
"void"		{ print_and_log_token(tVOID); 		return VOID; 	}	
"return"	{ print_and_log_token("RETURN");	return RETURN; 	}	
"println" 	{ print_and_log_token("PRINTLN"); 	return PRINTLN; }

"+"|"-"		{ print_and_log_token("ADDOP");   return ADDOP;  }
"*"|"/"|"%"	{ print_and_log_token("MULOP");   return MULOP;  }
"++"		{ print_and_log_token("INCOP");	  return INCOP;  }
"--"		{ print_and_log_token("DECOP");	  return DECOP;  }
"&&"|"||"	{ print_and_log_token("LOGICOP"); return LOGICOP;}
"&"|"|"|"^"|"<<"|">>" 		{ print_and_log_token("BITOP"); return BITOP; }
"<"|"<="|">"|">="|"=="|"!="	{ print_and_log_token("RELOP"); return RELOP; }
"="  { print_and_log_token("ASSIGNOP");  return ASSIGNOP; }
"!"  { print_and_log_token("NOT"); 		 return NOT;	  }
"("  { print_and_log_token("LPAREN");	 return LPAREN;   }
")"  { print_and_log_token("RPAREN");	 return RPAREN;   }
"{"  { print_and_log_token("LCURL"); 	 return LCURL; }
"}"  { print_and_log_token("RCURL"); 	 return RCURL; }
"["  { print_and_log_token("LSQUARE");   return LSQUARE;	  }
"]"  { print_and_log_token("RSQUARE");   return RSQUARE;   }
","  { print_and_log_token("COMMA");  	 return COMMA;	  }
";"  { print_and_log_token("SEMICOLON"); return SEMICOLON;}


{DIGITS}	  { print_and_log_token("CONST_INT"); yylval.symbol->setSemanticType(tINT); return CONST_INT; }
{EXTRAPOINTS} { log_err("TOO_MANY_DECIMAL_POINTS"); }
{FLOATING} 	  { print_and_log_token("CONST_FLOAT"); yylval.symbol->setSemanticType(tFLOAT); return CONST_FLOAT; }
{ILLFORMED}   { log_err("ILLFORMED_NUMBER"); }

{CHARLIT} {
	char* str = new char[2];
	if (yytext[1] != '\\') {
		//fprintf(tokenout,"<%s, %c>\n", "CONST_CHAR", yytext[1]);
		str[0] = yytext[1], str[1] = '\0';
		yylval.symbol = new SymbolInfo (str, "CONST_CHAR");
		yylval.symbol->setStartLine (line_count);
		yylval.symbol->setEndLine (line_count);
		fprintf(logout,"Line# %d: Token <CONST_CHAR> Lexeme %c found\n", line_count, yytext[1]);
	} else {
		//fprintf(tokenout,"<%s, %c>\n", "CONST_CHAR", actual);
		char actual = unescape_seq(yytext[2]);
		str[0] = actual, str[1] = '\0';
		yylval.symbol = new SymbolInfo (str, "CONST_CHAR");
		yylval.symbol->setStartLine (line_count);
		yylval.symbol->setEndLine (line_count);
		fprintf(logout,"Line# %d: Token <CONST_CHAR> Lexeme %c found\n", line_count, actual);
	};
	return CONST_CHAR;
}

{MULTICHARLIT} { log_err("MULTICHAR_CONST_CHAR");  }
{UNFINCHARLIT} { log_err("UNFINISHED_CONST_CHAR"); }
{EMPTYCHARLIT} { log_err("EMPTY_CONST_CHAR"); }

{SLSTRLIT} 		{ 
	yylval.symbol = new SymbolInfo (string_action(false), "SINGLE_LINE_STRING");
	yylval.symbol->setStartLine (line_count);
	yylval.symbol->setEndLine (line_count);
	newline_check(); 
	return SINGLE_LINE_STRING;
}
{MLSTRLIT} 		{
	yylval.symbol = new SymbolInfo (string_action(true), "MULTI_LINE_STRING");
	yylval.symbol->setStartLine (line_count);
	yylval.symbol->setEndLine (line_count);
	newline_check(); 
	return MULTI_LINE_STRING;
}
{UNFINSTRLIT} 	{ newline_check(), log_err("UNFINISHED_STRING"); }

{IDENTIFIER} {
	log_token("ID");
	char* id = new char[5]; strcpy(id, "ID");
	char* lexeme = new char[strlen(yytext)+2]; strcpy(lexeme, yytext);
	//if (st->insert(lexeme, id))	st->printAllScope(logout);
	//else fprintf(logout,"\t%s already exisits in the current ScopeTable\n", lexeme);
	yylval.symbol = new SymbolInfo (lexeme, id);
	yylval.symbol->setStartLine (line_count);
	yylval.symbol->setEndLine (line_count);
	return ID;
}

{NUMIDENTIFIER} { log_err("INVALID_ID_SUFFIX_NUM_PREFIX"); }

. { log_err("UNRECOGNIZED_CHAR"); }

%%

//==================================== SECTION - 3 ============================================

// int main (int argc, char** argv) {
// 	if (argc != 2) {
// 		printf("Please provide input file name and try again\n");
// 		return 0;
// 	};
	
// 	FILE *fin = fopen (argv[1], "r");
// 	if (fin == NULL) {
// 		printf("Cannot open specified file\n");
// 		return 0;
// 	};
	
// 	logout = fopen("1905084_log.txt","w");
// 	tokenout = fopen("1905084_token.txt","w");

// 	yyin = fin;
// 	yylex();
// 	st->printAllScope(logout);
// 	fprintf(logout, "Total lines: %d\n", line_count);
// 	fprintf(logout, "Total errors: %d\n", err_count);
// 	fclose(yyin), fclose(tokenout), fclose(logout);
// 	return 0;
// };
