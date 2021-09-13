/**
*
*
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/compile.h>
#include <writer/writer.h>


void writevm(CODE* c, char* line)
{
    if (c->vm == NULL) return;
    fprintf(c->vm, "%s\n", line);
    return;
}

static void writevmf(CODE* c, const char* op, const char* segment, int index)
{
    char cmd[300];
    sprintf(cmd, "%s %s %i", op, segment, index);
    writevm(c, cmd);
    return;
}

void write_add(CODE* c)
{
    writevm(c, "add");
}

void write_push_that(CODE* c, unsigned int i)
{
    writevmf(c, "push", "that", i);
}

void write_pop_that(CODE* c, unsigned int i)
{
    writevmf(c, "pop", "that", i);
}

void write_push_pointer(CODE* c, unsigned int i)
{
    writevmf(c, "push", "pointer", i);
}

void write_pop_pointer(CODE* c, unsigned int i)
{
    writevmf(c, "pop", "pointer", i);
}

void write_pop_temp(CODE* c, unsigned int i)
{
    writevmf(c, "pop", "temp", i);
}

void write_push_temp(CODE* c, unsigned int i)
{
    writevmf(c, "push", "temp", i);
}

void write_push_constant(CODE* c, unsigned int value)
{
    writevmf(c, "push", "constant", value);
}

void write_not(CODE* c)
{
    writevm(c, "not"); 
}
