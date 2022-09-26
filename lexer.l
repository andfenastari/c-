%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "symtab.h"

#define ADVANCE_COLUMN column = next_column; next_column += yyleng
#define ADVANCE_LINE   lineno += 1; column = next_column = 0
#define SET_INFO       yylval.column = column; yylval.lineno = lineno

int column, next_column, lineno;

%}

%x COMMENT

%%

if     { ADVANCE_COLUMN; SET_INFO; return IF; }
else   { ADVANCE_COLUMN; SET_INFO; return ELSE; }
return { ADVANCE_COLUMN; SET_INFO; return RETURN; }
while  { ADVANCE_COLUMN; SET_INFO; return WHILE; }
int    { ADVANCE_COLUMN; SET_INFO; return INT; }
void   { ADVANCE_COLUMN; SET_INFO; return VOID; }

[a-zA-Z]+ { ADVANCE_COLUMN; SET_INFO; yylval.strval = symadd(yytext); return ID; } 
[0-9]+    { ADVANCE_COLUMN; SET_INFO; yylval.intval = atoi(yytext); return NUM; }

\>   { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_GT; return RELOP; }
\<   { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_LT; return RELOP; }
\>=  { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_GE; return RELOP; }
\<=  { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_LE; return RELOP; }

\+  { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_ADD; return ADDOP; }
-   { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_SUB; return ADDOP; }

\*  { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_MUL; return MULOP; }
\/  { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_DIV; return MULOP; }

=   { ADVANCE_COLUMN; SET_INFO; return ASSIGN; }
\;  { ADVANCE_COLUMN; SET_INFO; return SCOLON; }
,   { ADVANCE_COLUMN; SET_INFO; return COMMA; }

\( { ADVANCE_COLUMN; SET_INFO; return LPAREN; }
\) { ADVANCE_COLUMN; SET_INFO; return RPAREN; }
\{ { ADVANCE_COLUMN; SET_INFO; return RCBRACK; }
\} { ADVANCE_COLUMN; SET_INFO; return LCBRACK; }
\[ { ADVANCE_COLUMN; SET_INFO; return LSBRACK; }
\] { ADVANCE_COLUMN; SET_INFO; return RSBRACK; }

\n { ADVANCE_LINE; }

\/\*          { ADVANCE_COLUMN; BEGIN(COMMENT); }
<COMMENT>.    { ADVANCE_COLUMN; }
<COMMENT>\n   { ADVANCE_LINE; }
<COMMENT>\*\/ { ADVANCE_COLUMN; BEGIN(INITIAL); }

[^ \n\t] { ADVANCE_COLUMN; SET_INFO; return ERROR; }
. ;

%%

