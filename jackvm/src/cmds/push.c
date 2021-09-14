#include <stdio.h>
#include <stdlib.h>
#include <tokens.h>
#include <cmds/push.h>


static void push_constant(Program* p);
static void push_static(Program* p);
static void push_argument(Program* p);
static void push_local(Program* p);
static void push_that(Program* p); 
static void push_this(Program* p); 
static void push_pointer(Program* p);
static void push_temp(Program* p);


void (*push_routines[]) (Program*) = {
    [CONSTANT]      =   push_constant, 
    [STATIC]        =   push_static, 
    [ARGUMENT]      =   push_argument,
    [LOCAL]         =   push_local, 
    [THIS]          =   push_this,
    [THAT]          =   push_that, 
    [POINTER]       =   push_pointer, 
    [TEMP]          =   push_temp

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



void push(Program* p)
{
    unsigned short index = next(p);
    push_routines[index](p);
//    printf(" %s ", memsegs[index]);
}


void pushv(Program* p, long value)
{
    p->stack[p->sp++] = value;
}

static void push_temp(Program* p)
{
    pushv(p, p->tmp[next(p)]);
}

static void push_that(Program* p)
{
    long* ptr = (long*) p->that;
    pushv(p,  ptr[next(p)]);
}

static void push_this(Program* p)
{
    long* ptr = (long*) p->this;
    unsigned short index = next(p);
    pushv(p, ptr[index]); 
}

static void push_local(Program* p)
{
    pushv(p, p->stack[p->locals + next(p)]);
}

static void push_static(Program* p)
{
    pushv(p, p->statics[next(p)]);
}

static void push_argument(Program* p)
{
    pushv(p, p->stack[p->arguments + next(p)]);
}

static void push_pointer(Program* p)
{
    unsigned short s = next(p);

    if (s == 0) 
    { 
        pushv(p, p->this);
    }
    else 
    {
        pushv(p, p->that);
    }

}
static void push_constant(Program* p)
{
    long l = 0; 
    for (int i = 0; i < 4; i++)
    {
        unsigned short s = next(p);
        long tl = 0;
        tl |= s;
        l |= tl << ((3-i)*16);
    }

    pushv(p, l);
}
