#ifndef AST_H_INCLUDE
#define AST_H_INCLUDE

#define X_KIND     \
    X(PROGRAM)   \
    X(VARDECL)   \
    X(FUNDECL)   \
    X(PARAMLIST) \
    X(PARAM)     \
    X(LISTPARAM) \
    X(ID)        \
    X(NUM)       \
    X(INT)       \
    X(VOID)      

enum kind {
#   define X(item) K_##item,
    X_KIND
#   undef X
    K_COUNT,

/*
    K_PROGRAM,
    K_VARDECL,
    K_FUNDECL,
    K_PARAMLIST,
    K_PARAM,
    K_LISTPARAM,
    K_ID,
    K_NUM,
    K_INT,
    K_VOID,

    K_COUNT,
*/
};

struct ast_node {
    enum kind kind;

    struct ast_node *first_child;
    struct ast_node *last_child;

    struct ast_node *next_sibling;

    union {
        int  intval;
        char *strval;
    };
};

extern char *kind_str[K_COUNT];

struct ast_node *ast_node_new(enum kind node_kind);
void             ast_node_append(struct ast_node *parent, struct ast_node *child);
void             ast_node_preppend(struct ast_node *parend, struct ast_node *child);
void             ast_node_print(struct ast_node *node, int ident);

#endif