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

const char *err_unknown   = "Unknown character";
const char *err_cmt_close = "Unclosed comment";
const char *err_cmt_open  = "Unopened comment";

int nesting;

%}

%x COMMENT
%x LINE_COMMENT

%%

if     { ADVANCE_COLUMN; SET_INFO; return IF; }
else   { ADVANCE_COLUMN; SET_INFO; return ELSE; }
return { ADVANCE_COLUMN; SET_INFO; return RETURN; }
while  { ADVANCE_COLUMN; SET_INFO; return WHILE; }
for    { ADVANCE_COLUMN; SET_INFO; return FOR; }
int    { ADVANCE_COLUMN; SET_INFO; return INT; }
void   { ADVANCE_COLUMN; SET_INFO; return VOID; }

[a-zA-Z]+ { ADVANCE_COLUMN; SET_INFO; yylval.strval = symadd(yytext); return ID; } 
[0-9]+    { ADVANCE_COLUMN; SET_INFO; yylval.intval = atoi(yytext); return NUM; }

\>   { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_GT; return RELOP; }
\<   { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_LT; return RELOP; }
\>=  { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_GE; return RELOP; }
\<=  { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_LE; return RELOP; }
==   { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_EQ; return RELOP; }
!=   { ADVANCE_COLUMN; SET_INFO; yylval.opval = OP_NE; return RELOP; }

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

\*\/ { ADVANCE_COLUMN; SET_INFO; yylval.errval = err_cmt_open; return ERROR; }

\n { ADVANCE_LINE; }

\/\*          { ADVANCE_COLUMN; BEGIN(COMMENT); }
<COMMENT>.    { ADVANCE_COLUMN; }
<COMMENT>\n   { ADVANCE_LINE; }
<COMMENT>\/\* { ADVANCE_COLUMN; nesting += 1; }
<COMMENT>\*\/ { ADVANCE_COLUMN; if (nesting) nesting--; else BEGIN(INITIAL); }
<COMMENT><<EOF>> { ADVANCE_COLUMN; SET_INFO; yylval.errval = err_cmt_close; BEGIN(INITIAL); return ERROR; }

\/\/ { ADVANCE_COLUMN; BEGIN(LINE_COMMENT); }
<LINE_COMMENT>. { ADVANCE_COLUMN; }
<LINE_COMMENT>\n { ADVANCE_LINE; BEGIN(INITIAL); }

[^ \n\t] { ADVANCE_COLUMN; SET_INFO; yylval.errval = err_unknown; return ERROR; }
. { ADVANCE_COLUMN; }

%%

