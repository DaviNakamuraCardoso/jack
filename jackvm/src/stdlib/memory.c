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
        array = calloc(sizeof(long), length);
        pushv(p, array); return;
    }

    length = nargs;
    array = calloc(sizeof(long), nargs);
    
    for (int i = 0; i < nargs; i++) 
    {
        printf("%li\n", array[nargs-i-1]); 
    }

    pushv(p, array);

    return;
}

