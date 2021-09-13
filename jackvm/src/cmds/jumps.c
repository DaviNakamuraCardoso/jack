#include <stdio.h>
#include <cmds/jumps.h>
#include <cmds/pop.h>
#include <cmds/push.h>


void label(Program* p)
{
    next(p);
    return;
}

void function(Program* p)
{
    fprintf(stderr, "Missing return statement in function\n");
    return;
}
void gotoc(Program* p)
{
    unsigned short i = next(p);
    
    if (i >= p->stdcount)
    {
        p->pc = p->labels[i];
    }

    return;
}

void ifgoto(Program* p)
{
    long b = popv(p);

    if (b != 0)
        gotoc(p);
    else 
        next(p);
    
    return;
}

void call(Program* p)
{
    unsigned short index = next(p), nargs = next(p), zeros;


    if (index < p->stdcount)
    {
        void (*f) (Program*, unsigned short) = (void (*) (Program*, unsigned short)) p->labels[index];
        f(p, nargs); return; 
    }

    pushv(p, p->pc);
    pushv(p, p->locals);
    pushv(p, p->arguments);
    pushv(p, p->this);
    pushv(p, p->that);

    p->arguments = (p->sp - 5) - (nargs);
    p->locals = p->sp;

    p->pc = p->labels[index];

    zeros = next(p);
    for (int i = 0; i < zeros; i++)
    {
        pushv(p, 0); 
    }

}

void returnc(Program* p)
{
    unsigned long endframe = p->locals, 
                  retaddr = p->stack[endframe - 5];

    if (endframe == 0)
    {
        p->done = 1;
        return;
    }
    p->stack[p->arguments] = popv(p);
    p->sp = p->arguments+1; 
    p->that = p->stack[endframe-1];
    p->this = p->stack[endframe-2];
    p->arguments = p->stack[endframe-3];
    p->locals = p->stack[endframe-4];

    p->pc = retaddr;

    return;
}
