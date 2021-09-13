#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "tokens.h"

typedef struct _list {
    unsigned short *contents; 
    unsigned long elems;
    unsigned short maxsizei;
} List; 



static unsigned long LIST_SIZES[] = {
    10, 
    100, 
    1000, 
    10000, 
    100000, 
    1000000, 
    10000000,
    100000000
}; 

List* new_list(void)
{
    List *l = malloc(sizeof(List));
    l->contents = calloc(sizeof(unsigned short), LIST_SIZES[0]); 
    l->maxsizei = 0; 
    l->elems = 0; 

    return l; 

}

void increasel(List* l)
{
    
    l->contents = reallocarray(
            l->contents, 
            LIST_SIZES[++l->maxsizei], 
            sizeof(unsigned short)
            );
    return;
}


void addl(List* l, unsigned short t)
{
    inline unsigned int atmaxsize(List* l)
    {
        return l->elems == LIST_SIZES[l->maxsizei]-1;
    }

    if (atmaxsize(l)) increasel(l);

    l->contents[l->elems++] = t;

    return;
}


unsigned long listlength(List* l)
{
    return l->elems;
}

unsigned short getelement(List* l, unsigned long index)
{
    return l->contents[index];
}

unsigned short popl(List* l)
{
    if (l->elems == 0){ return 0;}
    return (unsigned short) l->contents[--(l->elems)];
}

unsigned short lastel(List* l)
{
    return l->contents[l->elems-1];
}

unsigned short lasttolast(List* l)
{
    return l->contents[l->elems-2];
}

unsigned short* lcontents(List* l)
{
    return l->contents; 
}

