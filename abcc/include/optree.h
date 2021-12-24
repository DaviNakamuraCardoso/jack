#ifndef __OPTREE_H
#define __OPTREE_H

typedef struct tree 
{
    optree_t *nodes[SYMBOL_MAX];
    unsigned int exists:1, isoperator:1;
    unsigned int value;
} optree_t;

optree_t *opnew(const char* operators[], size_t length);
unsigned int opdestroy(optree_t *t);

unsigned int opadds(optree_t* t, char* operator, unsigned int type); 

optree_t* opget(optree_t* t, char* operator);

#endif
