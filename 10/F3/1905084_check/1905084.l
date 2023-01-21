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
extern FILE *logout, *tokenout, *errorout;
extern SymbolTable* st;
extern char *tINT, *tFLOAT, *tVOID;

void log_token (const char* token) {
	fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n", line_count, token, yytext);
};

void log_err (const char* err) {
	fprintf(errorout,"Error at line# %d: %s %s\n", line_count, err, yytext);
	err_count++;
};

void return_and_log_token (const char* token) {
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

"if" 		{ return_and_log_token("IF");		return IF;		}	
"else"		{ return_and_log_token("ELSE"); 	return ELSE; 	}		
"for"		{ return_and_log_token("FOR"); 		return FOR; 	}	
"while"		{ return_and_log_token("WHILE"); 	return WHILE; 	}	
"int"		{ return_and_log_token(tINT); 		return INT; 	}	
"char"		{ return_and_log_token("CHAR");		return CHAR; 	}	
"float"		{ return_and_log_token(tFLOAT); 	return FLOAT; 	}	
"double"	{ return_and_log_token("DOUBLE"); 	return DOUBLE; 	}	
"void"		{ return_and_log_token(tVOID); 		return VOID; 	}	
"return"	{ return_and_log_token("RETURN");	return RETURN; 	}	
"println" 	{ return_and_log_token("PRINTLN"); 	return PRINTLN; }

"+"|"-"		{ return_and_log_token("ADDOP");	return ADDOP;  }
"*"|"/"|"%"	{ return_and_log_token("MULOP"); 	return MULOP;  }
"++"		{ return_and_log_token("INCOP");	return INCOP;  }
"--"		{ return_and_log_token("DECOP");	return DECOP;  }
"&&"|"||"	{ return_and_log_token("LOGICOP");	return LOGICOP;}
"&"|"|"|"^"|"<<"|">>" 		{ return_and_log_token("BITOP"); return BITOP; }
"<"|"<="|">"|">="|"=="|"!="	{ return_and_log_token("RELOP"); return RELOP; }
"="  { return_and_log_token("ASSIGNOP"); return ASSIGNOP; }
"!"  { return_and_log_token("NOT"); 	 return NOT;	  }
"("  { return_and_log_token("LPAREN");	 return LPAREN;   }
")"  { return_and_log_token("RPAREN");	 return RPAREN;   }
"{"  { return_and_log_token("LCURL"); 	 return LCURL; 	  }
"}"  { return_and_log_token("RCURL"); 	 return RCURL; 	  }
"["  { return_and_log_token("LSQUARE");  return LSQUARE;  }
"]"  { return_and_log_token("RSQUARE");  return RSQUARE;  }
","  { return_and_log_token("COMMA");  	 return COMMA;	  }
";"  { return_and_log_token("SEMICOLON");return SEMICOLON;}


{DIGITS}	  { return_and_log_token("CONST_INT"); yylval.symbol->setSemanticType(tINT); return CONST_INT; }
{EXTRAPOINTS} { log_err("TOO_MANY_DECIMAL_POINTS"); }
{FLOATING} 	  { return_and_log_token("CONST_FLOAT"); yylval.symbol->setSemanticType(tFLOAT); return CONST_FLOAT; }
{ILLFORMED}   { log_err("ILLFORMED_NUMBER"); }

{CHARLIT} {
	char* str = new char[2];
	if (yytext[1] != '\\') {
		str[0] = yytext[1], str[1] = '\0';
		yylval.symbol = new SymbolInfo (str, "CONST_CHAR");
		yylval.symbol->setStartLine (line_count);
		yylval.symbol->setEndLine (line_count);
		fprintf(logout,"Line# %d: Token <CONST_CHAR> Lexeme %c found\n", line_count, yytext[1]);
	} else {
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
	yylval.symbol = new SymbolInfo (lexeme, id);
	yylval.symbol->setStartLine (line_count);
	yylval.symbol->setEndLine (line_count);
	return ID;
}

{NUMIDENTIFIER} { log_err("INVALID_ID_SUFFIX_NUM_PREFIX"); }

. { log_err("UNRECOGNIZED_CHAR"); }

%%
