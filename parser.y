%{
#include <stdio.h>
#include "lexer.h"
#include "ast.h"
#include "parser.h"

#define SET_INFO(s, e) $$->location.start = (s).loc; $$->location.end = (e).loc

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
%token INCOP
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

%type <ast_node> program decl_list decl var_decl fun_decl err funcall args
%type <ast_node> block type_spec param params param_list id num int void arg_list factor
%type <ast_node> stmt_list stmt expr assign_expr rel_expr var sum_expr mul_expr inc_expr
%type <ast_node> return_stmt if_stmt while_stmt for_stmt 
%type <token> INT VOID ID NUM SCOLON LSBRACK RSBRACK RELOP ADDOP MULOP INCOP

%precedence RPAREN
%precedence ELSE

%%

program         : decl_list { root = $1; }

decl_list       : decl decl_list { $$ = $2; ast_node_preppend($$, $1); }
                | %empty { $$ = ast_node_new(K_PROGRAM); }

decl            : var_decl
                | fun_decl
                | err SCOLON
                | err RCBRACK

var_decl        : type_spec id SCOLON { $$ = ast_node_make(K_VAR_DECL, 2, $1, $2); }
                | type_spec id ASSIGN expr SCOLON { $$ = ast_node_make(K_VAR_DEFN, 3, $1, $2, $4); }
                | type_spec id LSBRACK num RSBRACK SCOLON { $$ = ast_node_make(K_LIST_DECL, 3, $1, $2, $4); }

fun_decl        : type_spec id LPAREN params RPAREN block { $$ = ast_node_make(K_FUN_DECL, 4, $1, $2, $4, $6); }

params          : void
                | param_list

param_list      : param_list COMMA param { $$ = $1; ast_node_append($$, $3); }
                | param { $$ = ast_node_make(K_PARAM_LIST, 1, $1); }

param           : type_spec id { $$ = ast_node_make(K_PARAM, 2, $1, $2); }
                | type_spec id LSBRACK RSBRACK { $$ = ast_node_make(K_LIST_PARAM, 2, $1, $2); }
                | err

block           : LCBRACK stmt_list RCBRACK { $$ = $2; }

stmt_list       : stmt stmt_list { $$ = $2; ast_node_preppend($$, $1); }
                | %empty { $$ = ast_node_new(K_BLOCK); }

stmt            : expr SCOLON 
                | var_decl
                | block
                | return_stmt
                | while_stmt
                | for_stmt
                | if_stmt
                | err 

expr            : assign_expr
                | rel_expr

assign_expr     : var ASSIGN expr { $$ = ast_node_make(K_ASSIGN, 2, $1, $3); }

rel_expr        : sum_expr RELOP sum_expr { $$ = ast_node_make(K_RELOP, 2, $1, $3); $$->opval = ($2).opval; }
                | sum_expr

sum_expr        : sum_expr ADDOP mul_expr { $$ = ast_node_make(K_ADDOP, 2, $1, $3); $$->opval = ($2).opval; }
                | mul_expr

mul_expr        : mul_expr MULOP factor { $$ = ast_node_make(K_MULOP, 2, $1, $3); $$->opval = ($2).opval; }
                | inc_expr

inc_expr        : INCOP factor { $$ = ast_node_make(K_INCOP, 1, $2); $$->opval = ($1).opval; }
                | factor INCOP { $$ = ast_node_make(K_INCOP, 1, $1); $$->opval = ($2).opval; } 
                | factor

factor          : LPAREN expr RPAREN { $$ = $2; }
                | var
                | funcall
                | num

funcall         : id LPAREN args RPAREN { $$ = ast_node_make(K_FUNCALL, 2, $1, $3); }

args            : arg_list
                | %empty { $$ = ast_node_new(K_ARG_LIST); }

arg_list        : expr COMMA arg_list { $$ = $3; ast_node_preppend($$, $1); }
                | expr { $$ = ast_node_make(K_ARG_LIST, 1, $1); }

var             : id
                | id LSBRACK expr RSBRACK { $$ = ast_node_make(K_AREF, 2, $1, $3); } 


return_stmt     : RETURN SCOLON { $$ = ast_node_new(K_RETURN); }
                | RETURN expr SCOLON { $$ = ast_node_make(K_RETURN_EXPR, 1, $2); } 

while_stmt      : WHILE LPAREN expr RPAREN stmt { $$ = ast_node_make(K_WHILE, 2, $3, $5); }

for_stmt        : FOR LPAREN expr SCOLON expr SCOLON expr RPAREN stmt { $$ = ast_node_make(K_FOR, 4, $3, $5, $7, $9); }

if_stmt         : IF LPAREN expr RPAREN stmt ELSE stmt { $$ = ast_node_make(K_IF_ELSE, 3, $3, $5, $7); } 
                | IF LPAREN expr RPAREN stmt { $$ = ast_node_make(K_IF, 2, $3, $5); }

type_spec       : void
                | int

id              : ID { $$ = ast_node_new(K_ID); $$->strval = ($1).strval; }
num             : NUM { $$ = ast_node_new(K_NUM); $$->intval = ($1).intval; }
int             : INT { $$ = ast_node_new(K_INT); }
void            : VOID { $$ = ast_node_new(K_VOID); }

err             : error { $$ = ast_node_new(K_ERROR); }

%%

void yyerror(const char *error) {
    printf("ERROR: %s\n", error);
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