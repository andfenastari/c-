#include "ast.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *kind_str[K_COUNT] = {
#   define X(item) [K_##item] = #item,
    X_KIND
#   undef X
};

char *op_str[OP_COUNT] = {
#   define X(item) [OP_##item] = #item,
    X_OP
#   undef X
};

struct ast_node *ast_node_new(enum kind kind) {
    struct ast_node *node = malloc(sizeof(struct ast_node));
    node->kind = kind;
    node->first_child = NULL;
    node->last_child = NULL;
    node->next_sibling = NULL;

    return node;
}

struct ast_node *ast_node_make(enum kind kind, int n, ...) {
    struct ast_node *node = ast_node_new(kind);

    va_list children;
    va_start(children, n);

    while(n--) ast_node_append(node, va_arg(children, struct ast_node*));

    va_end(children);

    return node;
}

void ast_node_append(struct ast_node *parent, struct ast_node *child) {
    if (parent->first_child == NULL) {
        parent->first_child = child;
        parent->last_child = child;
        return;
    }

    parent->last_child->next_sibling = child;
    parent->last_child = child;
}

void ast_node_preppend(struct ast_node *parent, struct ast_node *child) {
    if (parent->first_child == NULL) {
        parent->first_child = child;
        parent->last_child = child;
        return;
    }

    child->next_sibling = parent->first_child;
    parent->first_child = child;
}

void ast_node_append_all(struct ast_node *parent, int n, ...) {
    va_list children;
    va_start(children, n);

    while (n--) {
        struct ast_node *child = va_arg(children, struct ast_node*);
        ast_node_append(parent, child);
    }

    va_end(children);
}

void ast_node_preppend_all(struct ast_node *parent, int n, ...) {
    va_list children;
    va_start(children, n);

    while (n--) {
        struct ast_node *child = va_arg(children, struct ast_node*);
        ast_node_preppend(parent, child);
    }

    va_end(children);
}
void ast_node_print(struct ast_node *node, int ident) {
    printf("%*s%s", ident, " ", kind_str[node->kind]);
    if (node->kind == K_ID) {
        printf(" = %s\n", node->strval);
    } else if (node->kind == K_NUM) {
        printf(" = %d\n", node->intval);
    } else if (
        node->kind == K_ADDOP ||
        node->kind == K_MULOP ||
        node->kind == K_RELOP ||
        node->kind == K_INCOP
    ) {
        printf(" = %s\n", op_str[node->opval]);
    } else {
        printf("\n");
    }

    struct ast_node *child = node->first_child;
    while (child != NULL) {
        ast_node_print(child, ident+1);
        child = child->next_sibling;
    }
}
