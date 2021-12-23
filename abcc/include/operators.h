#ifndef __OPERATOR_H
#define __OPERATOR_H 1

#include <string.h>

typedef enum _operator {
    ADD,
    AND,
    COM,
    DIV,
    END,
    EQ,
    GE,
    GT,
    LE,
    LT,
    MULT,
    MULT_COM,
    NE,
    NOT,
    OR,
    STR, 
    SUB,
    OP_INVALID, 

} operator_e;

operator_e get_operator(char* buff); 
unsigned int isoperator(char* buff); 

#endif

