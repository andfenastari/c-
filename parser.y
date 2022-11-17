%{
#include <stdio.h>
#include "lexer.h"
#include "ast.h"
#include "parser.h"

int yylex();
void yyerror(const char *s);

struct ast_node *root;

%}

%union {
    struct token    token;
    struct ast_node *ast_node;
}

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

%type <ast_node> program decl_list decl var_decl fun_decl block_decl type_spec param params param_list id num int void
%type <token> INT VOID ID NUM SCOLON LSBRACK RSBRACK

%%

program    : decl_list { root = $1; }
decl_list  : decl decl_list { $$ = $2; ast_node_preppend($$, $1); }
           | { $$ = ast_node_new(K_PROGRAM); }
decl       : var_decl { $$ = $1; }
           | fun_decl { $$ = $1; }

var_decl   : type_spec id SCOLON { $$ = ast_node_new(K_VARDECL); ast_node_append($$, $1); ast_node_append($$, $2); }
           | type_spec id LSBRACK num RSBRACK SCOLON { $$ = ast_node_new(K_VARDECL); ast_node_append($$, $1); ast_node_append($$, $2); ast_node_append($$, $4); }

fun_decl   : type_spec id LPAREN params RPAREN block_decl { $$ = ast_node_new(K_FUNDECL); ast_node_append($$, $1); ast_node_append($$, $4); ast_node_append($$, $6); }
params     : void { $$ = $1; }
           | param_list { $$ = $1; }
param_list : param_list COMMA param { $$ = $1; ast_node_append($$, $3); }
           | param { $$ = ast_node_new(K_PARAMLIST); ast_node_append($$, $1); }
param      : type_spec id { $$ = ast_node_new(K_PARAM); ast_node_append($$, $1); ast_node_append($$, $2); }
           | type_spec id LSBRACK RSBRACK { $$ = ast_node_new(K_LISTPARAM); ast_node_append($$, $1); ast_node_append($$, $2); }
block_decl : SCOLON { $$ = ast_node_new(K_PROGRAM); }

type_spec  : void | int

id         : ID { $$ = ast_node_new(K_ID); $$->strval = ($1).strval; }
num        : NUM { $$ = ast_node_new(K_NUM); $$->intval = ($1).intval; }
int        : INT { $$ = ast_node_new(K_INT); }
void       : VOID { $$ = ast_node_new(K_VOID); }

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
    int status = yyparse();
    if (status != 0) return status;
    ast_node_print(root, 1);
    /*
    int val;
    while ( (val = yylex()) > 0 ) {
        printf("%d,%d: %s", lineno+1, column, token_str(val));
        if (val == ERROR) printf(" %s", yylval.errval);
        else if (val == NUM) printf(" %d", yylval.intval);
        else if (val == ID)  printf(" %s", yylval.strval);
        printf("\n");
    }
    */
}
