
typedef enum operator {
    __INVALID,
    __ADD,
    __SUB,
    __MUL,
    __DIV,
    __AND,
    __OR,
    __LT,
    __GT,
    __EQ
} OPERATOR;

typedef enum unaryop {
    __INVALID_U, 
    __NOT,
    __NEG
} UNARYOP;

#define OPSIZE 100

void compile_expression(CODE *c);

unsigned int compile_keywordconstant(CODE* c);
unsigned int compile_term(CODE* c);
unsigned int compile_expressionlist(CODE* c);
unsigned int compile_inbraces(CODE* c);
unsigned int compile_subroutinecall(CODE* c);
unsigned int compile_arrayaccess(CODE* c);
