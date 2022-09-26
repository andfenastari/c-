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

int main(int argc, char **argv) {
    int val;
    while ( (val = yylex()) > 0 ) printf("%d,%d: %d\n", lineno, column, val);
}
