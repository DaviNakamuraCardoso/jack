#ifndef __SOURCE_H
#define __SOURCE_H

#include "optree.h"

typedef struct source 
{
    FILE* f;
    optree_t *t; 
    char* buff;
    const char* filename; 

} source_t;


#endif
