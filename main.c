#include "lexer.h"
#include "parser.h"
#include "ast.h"
#include "codegen.h"

#include <stdio.h>

int main(int argc, char **argv) {
    int status = yyparse();
    if (status != 0) return status;
    printf("\n***** AST ******\n");
    ast_node_print(root, 1);

    printf("\n***** ASM *****\n");
    status = codegen(root);
    if (status != 0) return status;

    return 0;
}

