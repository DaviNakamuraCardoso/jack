#include <operators.h>
#include <stdio.h>

const char* operators[__OP_COUNT] = {
    [ADD] = "+", 
    [AND] = "&&",
    [COM] = "//",
    [DIV] = "/",
    [END] = ";",
    [EQ] = "==",
    [GE] = ">=",
    [GT] = ">",
    [LE] = "<=",
    [LT] = "<",
    [MULT] = "*",
    [MULT_COM] = "/*",
    [NE] = "!=",
    [NOT] = "!",
    [OR] = "||",
    [STR] = "\"",
    [SUB] = "-", 
};

unsigned int opgetall(optree_t* t)
{
    for (int i = 0; i < __OP_COUNT; i++) opadds(t, operators[i], (operator_e)i);
    return 0; 
}

