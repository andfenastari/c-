#ifndef LEXER_H_INCLUDE
#define LEXER_H_INCLUDE

enum op {
    OP_GT,
    OP_LT,
    OP_GE,
    OP_LE,
    OP_EQ,
    OP_NE,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
};

struct YYSTYPE {
    int column, lineno;
    union {
        enum op  opval;
        int      intval;
        char    *strval;
        const char *errval;
    };
};

extern int column, next_column, lineno;

extern const char *err_unknown;
extern const char *err_cmt_close;
extern const char *err_cmt_open;

#endif