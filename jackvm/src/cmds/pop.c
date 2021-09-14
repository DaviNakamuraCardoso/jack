#include <stdio.h>
#include <stdlib.h>
#include <tokens.h>
#include <cmds/pop.h>

static void pop_constant(Program* p); 
static void pop_static(Program* p);
static void pop_argument(Program* p);
static void pop_local(Program* p); 
static void pop_this(Program* p);
static void pop_that(Program* p);
static void pop_pointer(Program* p);
static void pop_temp(Program* p);

void (*pop_commands[]) (Program*) = {
    [CONSTANT]      = pop_constant,
    [STATIC]        = pop_static, 
    [ARGUMENT]      = pop_argument, 
    [LOCAL]         = pop_local, 
    [THIS]          = pop_this,
    [THAT]          = pop_that,
    [POINTER]       = pop_pointer, 
    [TEMP]          = pop_temp

};
static char* memsegs[] = {
    [CONSTANT]  = "constant", 
    [STATIC]    = "static",
    [ARGUMENT]  = "argument",
    [LOCAL]     = "local",
    [THIS]      = "this",
    [THAT]      = "that",
    [POINTER]   = "pointer",
    [TEMP]      = "temp"
};


void pop(Program* p)
{
   unsigned short index = next(p);
   pop_commands[index](p);
//   printf(" %s ", memsegs[index]);
}

static void pop_temp(Program* p)
{
    p->tmp[next(p)] = popv(p);
}

static void pop_this(Program *p)
{
    long* ptr = (long*) p->this;
    ptr[next(p)] = popv(p);
}

static void pop_that(Program *p)
{
    long* ptr = (long*) p->that;
    ptr[next(p)] = popv(p);
}

static void pop_static(Program* p)
{
    p->statics[next(p)] = popv(p);
}

static void pop_argument(Program* p)
{
    p->stack[p->arguments + next(p)] = popv(p);
}

static void pop_local(Program* p)
{
    p->stack[p->locals + next(p)] = popv(p);
}

static void pop_pointer(Program* p)
{
    unsigned short s = next(p);
    if (s == 0)
    {
        p->this = popv(p);
    }
    else 
    {
        p->that = popv(p);
    }
}
long popv(Program* p)
{
    return p->stack[--(p->sp)];
}



static void pop_constant(Program* p)
{
    p->pc = 0;
    fprintf(stderr, "Invalid routine: CONSTANT segment doesn't have a POP routine.\n");
    exit(1);
}


