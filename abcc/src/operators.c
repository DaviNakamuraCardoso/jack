#include <operators.h>
#include <stdio.h>

const char* operators[] = {
    [AND] = "&&",
    [COM] = "//",
    [EQ] = "==",
    [GE] = ">=",
    [LE] = "<=",
    [MULT_COM] = "/*",
    [NE] = "!=",
    [OR] = "||",
    [STR] = "\"",
}; 

_Static_assert (sizeof(operators) / sizeof(char*) == __OP_COUNT, "Mismatch in operator enum and values");

unsigned int opgetall(optree_t* t)
{
    for (int i = 0; i < __OP_COUNT; i++) opadds(t, operators[i], (operator_e)i);
    return 0; 
}

