#include <operators.h>
#include <stdio.h>

const char* operators[] = {
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

operator_e get_operator(char* buff)
{
    for (size_t i = 0; i < sizeof(operators) / sizeof(char*); i++)
    {
        if (strcmp(buff, operators[i]) == 0) return i;
    }

    return OP_INVALID;
}

unsigned int isoperator(char* buff)
{
    return get_operator(buff) != OP_INVALID; 
} 
