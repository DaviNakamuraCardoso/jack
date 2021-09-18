#include <stdio.h>
#include <stdlib.h>
#include <stdlib/memory.h>
#include <cmds/push.h>
#include <cmds/pop.h>

void std_malloc(Program* p, unsigned short nargs)
{
    if (nargs == 0) return;
    long *o = calloc(sizeof(long), popv(p));
    pushv(p, o);
    return;
}

void std_free(Program* p, unsigned short nargs)
{
    if (nargs == 0) return;
    free(popv(p));
    return;
}

void std_array(Program* p, unsigned short nargs)
{
    unsigned long length;
    long* array;

    if (nargs == 1)
    {
        length = popv(p);
        array = calloc(sizeof(long) + 1, length);
        array[0] = length;
        pushv(p, array + sizeof(long)); return;
    }

    length = nargs;
    array = calloc(sizeof(long), nargs);
    
    for (int i = 0; i < nargs; i++) 
    {
        array[nargs-i-1] = popv(p);
    }

    pushv(p, array);

    return;
}

// Creates an array full of the same elements
void std_full_array(Program* p, unsigned short nargs)
{
    long element = popv(p), length = popv(p);
    long* array = calloc(sizeof(long), length+1);
    array[0] = length;
    for (int i = 1; i < length+1; i++) { array[i] = element; }

    pushv(p, array + 1); return;
} 

void std_array_count(Program* p, unsigned short nargs)
{
    long start = popv(p), step = popv(p), needle = popv(p), *array = popv(p), count = 0;

    for (int i = start; i < array[-1]; i += step)
    {
        if (array[i] == needle) count++; 
    } 
    pushv(p, count);
}

void std_array_dispose(Program* p, unsigned short nargs)
{
    long* array = popv(p);
    free(array-1);
    pushv(p, 0);
}
