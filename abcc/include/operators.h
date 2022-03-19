#ifndef __OPERATOR_H
#define __OPERATOR_H 1

#include <string.h>
#include "optree.h"

typedef enum _operator {
    AND, 
    COM,
    EQ,
    GE,
    LE,
    MULT_COM,
    NE,
    OR,
    STR, 
    __OP_COUNT, 

} operator_e;

unsigned int opgetall(optree_t*);

#endif

