#ifndef __OPERATOR_H
#define __OPERATOR_H 1

#include <string.h>
#include "optree.h"

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
    __OP_COUNT, 

} operator_e;

unsigned int opgetall(optree_t*);

#endif

