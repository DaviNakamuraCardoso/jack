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
    unsigned short findex;
    unsigned int tl;
    mtable_t* mt;

} source_t;

unsigned short opensrc(const char*); 
const char* getsrc(unsigned short);

#endif
