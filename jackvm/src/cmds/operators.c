#include <stdio.h>
#include <cmds/operators.h>


void add(Program* p)
{
    long a = popv(p);
    long b = popv(p);
    pushv(p, a + b);
}
void sub(Program* p)
{
    long a = popv(p);
    long b = popv(p);
    pushv(p, b - a);
}
void mult(Program* p)
{
    long a = popv(p);
    long b = popv(p);
    pushv(p, a * b);
}

void divc(Program* p)
{
    long a = popv(p);
    long b = popv(p);
    pushv(p, b / a);
}
void gt(Program* p)
{
    long a = popv(p);
    long b = popv(p);
    pushv(p, b > a);
}

void lt(Program* p)
{
    long a = popv(p);
    long b = popv(p);
    pushv(p, b < a);
}

void eq(Program* p)
{
    long a = popv(p);
    long b = popv(p);
    pushv(p, a == b);
}

void not(Program* p)
{
    long a = popv(p);
    pushv(p, !a);
}

void and(Program* p)
{
    long a = popv(p);
    long b = popv(p);
    pushv(p, a && b);
}

void or(Program* p)
{
    long a = popv(p);
    long b = popv(p);
    pushv(p, a || b);
}

