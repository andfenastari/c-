#ifndef LEXER_H_INCLUDE
#define LEXER_H_INCLUDE

#define X_OP \
    X(GT)    \
    X(LT)    \
    X(GE)    \
    X(LE)    \
    X(EQ)    \
    X(NE)    \
    X(ADD)   \
    X(SUB)   \
    X(MUL)   \
    X(DIV)   \
    X(INC)   \
    X(DEC)

enum op {
#   define X(op) OP_##op,
    X_OP
#   undef X
    OP_COUNT,
};

struct location {
    int column, lineno;
};

struct token {
    struct location loc;
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