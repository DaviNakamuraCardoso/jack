#include <stdio.h>
#include <stdlib.h>
#include <stdlib/string.h>
#include <cmds/push.h>
#include <cmds/pop.h>

void std_string(Program* p, int nargs)
{
    if (nargs != 1) return;

    unsigned long maxlen = popv(p);
    long* o = newjackstr(maxlen);    
    pushv(p, o);

    return;
}

void std_len(Program* p, int nargs)
{
    long *o = popv(p);
    pushv(p, o[2]);
}

void std_appendchar(Program* p, int nargs)
{
    char c = popv(p);
    long* o = popv(p);
    char* string = o[0];

    string[o[1]++] = c; 
    pushv(p, o);

    return;
}

long *newjackstr(unsigned long maxlen)
{
    long *o = calloc(sizeof(long), 3);
    char* string;

    o[0] = calloc(sizeof(char), maxlen+1);
    string = o[0];
    string[maxlen+1] = '\0';

    // Length the user sees 
    o[1] = 0;

    // Actual length
    o[2] = maxlen; 

    return o;

}

