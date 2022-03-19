#ifndef __SOURCE_H
#define __SOURCE_H

#include "optree.h"
#include "macrotable.h"

typedef struct source 
{
    FILE* f;
    optree_t *t; 
    char* buff;
    const char* filename; 
    unsigned int tl;
    mtable_t* mt;

} source_t;


#endif
