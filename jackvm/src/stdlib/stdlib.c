#include <stdio.h>
#include <stdlib.h>
#include <stdlib/stdlib.h>
#include <time.h>

void std_clock(Program* p, unsigned short nargs)
{
    if (nargs > 0) 
    {
        for (int i = 0; i < nargs; i++) popv(p);
    }
    pushv(p, clock());
    return;
}

void std_clockspersec(Program* p, unsigned short nargs)
{
    pushv(p, CLOCKS_PER_SEC);
}
