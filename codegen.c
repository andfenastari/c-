#include "ast.h"
#include "codegen.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR(msg, ...) fprintf(stderr, msg, __VA_ARGS__)

#define push(reg)      printf("\tsub $sp, $sp, 4\n\tsw $%s, ($sp)\n", #reg)
#define pop(reg)       printf("\tlw $%s, ($sp)\n\tadd $sp, $sp, 4\n", #reg)
#define grow(n)        printf("\tadd $sp, $sp, %d\n", n)
#define jr(reg)        printf("\tjr $%s\n", #reg)
#define move(dst, src) printf("\tadd $%s, $%s, 0\n", #dst, #src)
#define named(name)    printf("%s:\n", name);
#define gen_lbl()      ++next_id
#define lbl(id)        printf(".l%d:\n", id)
#define add(dst, a, b) printf("\tadd $%s, $%s, $%s\n", #dst, #a, #b)
#define sub(dst, a, b) printf("\tsub $%s, $%s, $%s\n", #dst, #a, #b)
#define mul(dst, a, b) printf("\tmult $%s, $%s\n\tmflo $%s\n", #a, #b, #dst)
#define div(dst, a, b) printf("\tdiv $%s, $%s\n\tmflo $%s\n", #a, #b, #dst)
#define seq(dst, a, b) printf("\tseq $%s, $%s, $%s\n", #dst, #a, #b)
#define slt(dst, a, b) printf("\tslt $%s, $%s, $%s\n", #dst, #a, #b)
#define sle(dst, a, b) printf("\tsle $%s, $%s, $%s\n", #dst, #a, #b)
#define sne(dst, a, b) printf("\tsne $%s, $%s, $%s\n", #dst, #a, #b)
#define inc(dst)       printf("\tadd $%s, $%s, 1", #dst, #dst)
#define dec(dst)       printf("\tsub $%s, $%s, 1", #dst, #dst)
#define lvar(dst, off) printf("\tlw $%s, %d($fp)\n", #dst, off*4)
#define svar(src, off) printf("\tsw $%s, %d($fp)\n", #src, off*4)
#define li(dst, i)     printf("\tli $%s, %d\n", #dst, i)
#define j(id)          printf("\tj .l%d\n", id)

int next_id = 0;

struct scope_node {    
    char *name;
    int   offset;
    int   size;
    bool  is_array;
    struct scope_node *next;
};

struct scope {
    int return_label;
    struct scope_node *first;
};

static struct scope *scope_new() {
    struct scope *ret = malloc(sizeof(*ret));
    ret->first = NULL;
    ret->return_label = gen_lbl();

    return ret;
}

static struct scope_node *scope_push(struct scope *scope, char *name, int size) {
    struct scope_node *node = malloc(sizeof(*node));
    struct scope_node *next = scope->first;

    int prev_size = next?next->size:0;
    int prev_offset = next?next->offset:0;

    node->name = name;
    node->offset = prev_offset+prev_size;
    node->size = size;
    node->next = next;
    node->is_array = size > 1;

    scope->first = node;
    return node;
}

static struct scope_node *scope_lookup(struct scope *scope, char *name) {
    for (struct scope_node *node = scope->first; node != NULL; node = node->next) {
        if (node->name == name) // Valid because symbol names are interned
            return node;
    }

    ERROR("use of undeclared identifier: %s", name);
}

static void global(struct ast_node *globl);
static void fun(struct ast_node *fun);
static void preamble();
static void postamble();
static void decl(struct ast_node *d, struct scope *scope);
static struct scope_node *expr(struct ast_node *e, struct scope *scope);

int codegen(struct ast_node *root) {
    assert(root->kind == K_PROGRAM);

    for (struct ast_node *decl = root->first_child; decl != NULL; decl = decl->next_sibling) {
        if (decl->kind == K_VAR_DECL || decl->kind == K_VAR_DEFN || decl->kind == K_LIST_DECL) {
            printf(".data\n");
            global(decl);
        } else if (decl->kind == K_FUN_DECL) {
            printf(".text\n");
            fun(decl);
        } else
            assert(0);
    }
    return 0;
}

static void global(struct ast_node *globl) {
    char *name = ast_node_child(globl, 1)->strval;
    if (globl->kind == K_VAR_DEFN) ERROR("cannot define global variable: %s\n", name);

    if (globl->kind == K_VAR_DECL) {
        printf("%s: .word 0\n", name);
    } else if (globl->kind == K_LIST_DECL) {
        int size = ast_node_child(globl, 2)->intval;
        printf("%s: .space %d\n", name, size);
    }
}

static void fun(struct ast_node *fun) {
    struct scope *scope = scope_new();
    char *name = ast_node_child(fun, 1)->strval;
    
    named(name);
    preamble();

    // push arguments to stack
    struct ast_node *args = ast_node_child(fun, 2);
    if (args->kind != K_VOID) {
        assert(args->kind == K_PARAM_LIST);
        printf("# push args\n");
        for (struct ast_node *arg = args->first_child; arg != NULL; arg = arg->next_sibling) {
            char *name = ast_node_child(arg, 1)->strval;
            struct scope_node *node = scope_push(scope, name, 1);
            node->is_array = (arg->kind == K_LIST_PARAM); // Special case for list params
            printf("# argument %s (offset = %d)\n", node->name, node->offset * 4);
            push(t0);
        }
    }

    struct ast_node *body = ast_node_child(fun, 3);
    
    for (struct ast_node *stmt = body->first_child; stmt != NULL; stmt = stmt->next_sibling) {
        if (stmt->kind == K_VAR_DECL || stmt->kind == K_VAR_DEFN || stmt->kind == K_LIST_DECL) {
            decl(stmt, scope);
        } else if (stmt->kind == K_RETURN) {
            printf("# return stmt\n");
            j(scope->return_label);
        } else if (stmt->kind == K_RETURN_EXPR) {
            printf("# return expr stmt\n");
            struct scope_node *ret = expr(ast_node_child(stmt, 0), scope);
            lvar(v0, ret->offset);
            j(scope->return_label);
        }
    }

    postamble(scope);
}

static void preamble() {
    printf("# preamble\n");
    push(fp);
    push(ra);
    move(fp, sp);
}

static void postamble(struct scope *scope) {
    printf("# postamble\n");
    lbl(scope->return_label);
    move(sp, fp);
    pop(ra);
    pop(fp);

    jr(ra);
}

void decl(struct ast_node *d, struct scope *scope) {
    char *name = ast_node_child(d, 1)->strval;
    int size = (d->kind!=K_LIST_DECL)?1:ast_node_child(d, 2)->intval;
    struct scope_node *decl_node = scope_push(scope, name, size);
    printf("# decl %s (offset = %d)\n", name, decl_node->offset * 4);
    
    grow(size);
    
    if (d->kind != K_VAR_DEFN) return;

    struct scope_node *defn_node = expr(ast_node_child(d, 2), scope);

    lvar(t1, defn_node->offset);
    svar(t1, decl_node->offset);
}

struct scope_node *expr(struct ast_node *e, struct scope *scope) {
    if (e->kind == K_ID) {
        return scope_lookup(scope, e->strval);
    } else if (e->kind == K_NUM) {
        struct scope_node *tmp = scope_push(scope, NULL, 1);
        li(t1, e->intval);
        svar(t1, tmp->offset);

        return tmp;
    } else if (e->kind == K_ADDOP || e->kind == K_MULOP || e->kind == K_RELOP) {
        struct scope_node *tmp = scope_push(scope, NULL, 1);
        struct scope_node *lft = expr(ast_node_child(e, 0), scope);
        struct scope_node *rgt = expr(ast_node_child(e, 1), scope);

        lvar(t1, lft->offset);
        lvar(t2, rgt->offset);
        
        switch (e->opval) {
        case OP_ADD: add(t1, t1, t2); break;
        case OP_SUB: sub(t1, t1, t2); break;
        case OP_MUL: mul(t1, t1, t2); break;
        case OP_DIV: div(t1, t1, t2); break;
        case OP_EQ:  seq(t1, t1, t2); break;
        case OP_NE:  sne(t1, t1, t2); break;
        case OP_LT:  slt(t1, t1, t2); break;
        case OP_LE:  sle(t1, t1, t2); break;
        case OP_GT:  sle(t1, t2, t1); break;
        case OP_GE:  sle(t1, t2, t1); break;
        }

        svar(t1, tmp->offset);

        return tmp;
    } else if (e->kind == K_INCOP) {

    }
}