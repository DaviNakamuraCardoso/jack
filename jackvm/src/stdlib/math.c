#include <stdio.h>
#include <stdlib.h>
#include <stdlib/math.h>

void std_sqrt(Program* p, unsigned short nargs)
{
    long a = popv(p);
    pushv(p, sqrtl(a));
}
