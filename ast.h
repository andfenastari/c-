#ifndef AST_H_INCLUDE
#define AST_H_INCLUDE

#include "lexer.h"

#define X_KIND         \
    X(PROGRAM)         \
    X(ERROR)           \
    X(BLOCK)           \
    X(VAR_DECL)        \
    X(LIST_DECL)       \
    X(FUN_DECL)        \
    X(IF)              \
    X(IF_ELSE)         \
    X(WHILE)           \
    X(FOR)             \
    X(RETURN)          \
    X(RETURN_EXPR)     \
    X(FUNCALL)         \
    X(ASSIGN)          \
    X(VAR)             \
    X(AREF)            \
    X(REL)             \
    X(SUM)             \
    X(MULT)            \
    X(PARAM_LIST)      \
    X(PARAM)           \
    X(LIST_PARAM)      \
    X(ARG_LIST)        \
                       \
    X(ID)              \
    X(NUM)             \
    X(INT)             \
    X(VOID)            \
    X(RELOP)           \
    X(ADDOP)           \
    X(MULOP)     

enum kind {
#   define X(item) K_##item,
    X_KIND
#   undef X
    K_COUNT,
};

struct ast_node {
    enum kind kind;

    struct ast_node *first_child;
    struct ast_node *last_child;

    struct ast_node *next_sibling;

    union {
        int     intval;
        char    *strval;
        enum op opval;
    };
};

extern char *kind_str[K_COUNT];

struct ast_node *ast_node_new(enum kind node_kind);
void             ast_node_append(struct ast_node *parent, struct ast_node *child);
void             ast_node_preppend(struct ast_node *parend, struct ast_node *child);
void             ast_node_print(struct ast_node *node, int ident);

#endif