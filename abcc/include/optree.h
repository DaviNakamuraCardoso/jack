#ifndef __OPTREE_H
#define __OPTREE_H

#include "symbols.h"

typedef struct tree 
{
    struct tree* nodes[__SYM_COUNT];
    unsigned int exists:1, isoperator:1;
    union {
        unsigned int symbol;
        unsigned int operator;
    };
                 
} optree_t;

optree_t *opnew(void);
unsigned int opdestroy(optree_t *t);

unsigned int opadds(optree_t* t, const char* operator, unsigned int type); 
unsigned int opaddc(optree_t* t, char c);

optree_t* opgets(optree_t* t, char* operator);
optree_t* opgetc(optree_t* t, char c);

#endif
