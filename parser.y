%{
#include <stdio.h>
#include "lexer.h"
#include "parser.h"

int yylex();
void yyerror(const char *s);
%}

%define api.value.type {struct YYSTYPE}

%token IF
%token ELSE
%token RETURN
%token INT
%token VOID
%token WHILE
%token FOR
%token RELOP
%token ADDOP
%token MULOP
%token ASSIGN
%token SCOLON
%token COMMA
%token LPAREN
%token RPAREN
%token LSBRACK
%token RSBRACK
%token LCBRACK
%token RCBRACK
%token ID
%token NUM
%token ERROR

%%

id: ID

%%

void yyerror(const char *error) {
    printf("ERROR: %s", error);
}

char *token_str(enum yytokentype token) {
    switch (token) {
        case IF: return "IF";
        case ELSE: return "ELSE";
        case RETURN: return "RETURN";
        case INT: return "INT";
        case VOID: return "VOID";
        case WHILE: return "WHILE";
	case FOR: return "FOR";
        case RELOP: return "RELOP";
        case ADDOP: return "ADDOP";
        case MULOP: return "MULOP";
        case ASSIGN: return "ASSIGN";
        case SCOLON: return "SCOLON";
        case COMMA: return "COMMA";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case LSBRACK: return "LSBRACK";
        case RSBRACK: return "RSBRACK";
        case LCBRACK: return "LCBRACK";
        case RCBRACK: return "RCBRACK";
        case ID: return "ID";
        case NUM: return "NUM";
        case ERROR: return "ERROR";
    }
}

int main(int argc, char **argv) {
    int val;
    while ( (val = yylex()) > 0 ) {
        printf("%d,%d: %s", lineno+1, column, token_str(val));
        if (val == ERROR) printf(" %s", yylval.errval);
        else if (val == NUM) printf(" %d", yylval.intval);
        else if (val == ID)  printf(" %s", yylval.strval);
        printf("\n");
    }
}

