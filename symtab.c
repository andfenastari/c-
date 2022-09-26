#include <string.h>
#include <stdlib.h>
#include "symtab.h"

struct symtab symtab;

static char *symfind(char *symbol) {
    struct symnode *node = symtab.start;

    while (node != NULL) {
        if (strcmp(symbol, node->symbol) == 0)
            return node->symbol;
        node = node->next;
    }

    return NULL;
}

static char *syminsert(char *symbol) {
    struct symnode *node = malloc(sizeof *node);
    node->symbol = strdup(symbol);
    node->next = symtab.start;
    symtab.start = node;

    return node->symbol;
}

char *symadd(char *symbol) {
    char *ret = symfind(symbol);
    if (ret != NULL) return ret;
    return syminsert(symbol);
}
