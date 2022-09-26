struct symtab {
    struct symnode *start;
};

struct symnode {
    char *symbol;
    struct symnode *next;
};

char* symadd(char *symbol);
