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


