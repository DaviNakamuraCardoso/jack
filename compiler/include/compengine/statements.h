
typedef enum {
    INVALID_STATEMENT,
    LET,
    IF,
    WHILE,
    DO,
    RETURN
} STATEMENT;


void compile_statements(CODE* c);

void compile_let(CODE* c);

void compile_if(CODE* c);

void compile_while(CODE* c);

void compile_do(CODE* c);

void compile_return(CODE* c);
