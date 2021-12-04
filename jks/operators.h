#ifndef __OPERATOR_H
#define __OPERATOR_H


typedef enum _operator {
    ADD,
    AND,
    DIV,
    EQ,
    GE
    GT,
    LE,
    LT,
    MULT,
    NE,
    NEG,
    NOT,
    OR,
    SUB,
    STR, 
    
} operator_e;

const char* operators[] = {
    [ADD] = "+", 
    [AND] = "&&",
    [DIV] = "/",
    [EQ] = "==",
    [GE] = ">=",
    [GT] = ">",
    [LE] = "<=",
    [LT] = "<",
    [MULT] = "*",
    [NE] = "!=",
    [NOT] = "!",
    [OR] = "||",
    [SUB] = "-",
    [STR] = "\"",
    [COM] = "//",
    [MULT_COM] = "/*",
};

operator_e get_operator(char* buff)
{
    for (int i = 0; i < sizeof(operators) / sizeof(char*); i++)
    {
        if (strcmp(buff, operators[i])) return i;
    }

    return -1; 
}

unsigned int isoperator(char* buff)
{
    return get_operator(buff) != -1; 
} 

#endif

