/**
*
*
*       Generates VM code for assigments
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <compengine/compile.h>
#include <table/parser.h>
#include <writer/writer.h>
#include <writer/assignments.h>

static void write_stack_cmd(CODE* c, char* varname, const char* cmd)
{
    char variable[200], vm[300];

    get_variable(c, varname, variable);
    sprintf(vm, "%s %s", cmd, variable);
    writevm(c, vm);
    return;
}

void write_pop(CODE* c, char* varname)
{
    write_stack_cmd(c, varname, "pop");
    return;
}

void write_push(CODE* c, char* varname)
{
    write_stack_cmd(c, varname, "push");
    return;
}

void write_intconstant(CODE* c, char* constant)
{
    char cmd[300];

    sprintf(cmd, "push constant %s", constant);
    writevm(c, cmd);
    return;
}

void write_poptemp(CODE* c, int n)
{
    char cmd[300];

    sprintf(cmd, "pop temp %i", n);
    writevm(c, cmd);
    return;
}

void write_pushtemp(CODE* c, int n)
{
    char cmd[300];
    sprintf(cmd, "push temp %i", n);
    writevm(c, cmd);
    return;
}

static void fill_new_string(CODE* c, char* str)
{
    char append[300];

    for (int i = 0; str[i] != 0; i++)
    {
        // Calling the string.appendChar method
        sprintf(append, "push constant %i", str[i]);
        writevm(c, append);
        writevm(c, "call String.appendChar 2");
    }
}

static void start_new_string(CODE* c, char* str)
{
    unsigned int len = strlen(str);
    char create[300];

    sprintf(create, "push constant %i", len);
    writevm(c, create);
    writevm(c, "call String.new 1");

}

void write_stringliteral(CODE* c, char* str)
{
    start_new_string(c, str);
    fill_new_string(c, str);
    return;
}


static void get_keyvalue(char* key, char* buffer)
{
    int val = 0;
    switch (*key)
    {
        case 't':
        {
            switch (1[key])
            {
                case 'r':
                {
                    val = 1; break;

                }
                default:
                {
                    val = 0; break;
                }
            }
        }
    }

    sprintf(buffer, "%i", val);

    return;
}


static void write_post_op(CODE* c, char* key)
{
    switch (*key)
    {
        // true
        case 't':
        {
            switch (1[key])
            {
                case 'r':
                {
                    writevm(c, "neg"); return;
                }
                default:
                {
                    return;
                }
            }
        }
    }
    return;
}

void write_op(CODE* c, int* operators, int sp)
{

    if (sp <= 0) return;

    char* vm[] = {
        NULL,
        "add",
        "sub",
        "mult",
        "div",
        "and",
        "or",
        "lt",
        "gt",
        "eq"
    };


    while (operators[--sp] != 0)
    {
        writevm(c, vm[operators[sp]]);
        if (sp <= 0) return;
    }

    return;
}

void write_unaryop(CODE* c, int uop)
{
    char* ops[] = {
        NULL,
        "not",
        "neg"

    };

    if (uop <= 0) return;

    writevm(c, ops[uop]);
    return;
}

static void get_keysegment(char* key, char* buffer)
{
    char* ret;
    switch (*key)
    {
        case 't':
        {
            switch (*(key+1))
            {
                case 'h':
                {
                    ret = "pointer"; break;
                }

                default:
                {
                    ret = "constant"; break;
                }
            }
            break;
        }
        default:
        {
            ret = "constant";
        }
    }

    strcpy(buffer, ret);
}

static void write_constant_value(CODE* c, char* segment, char* value)
{
    char cmd[300];
    sprintf(cmd, "push %s %s", segment, value);
    writevm(c, cmd);
    return;

}

void write_keyconstant(CODE* c, char* key)
{
    char segment[300], value[20];

    get_keysegment(key, segment);
    get_keyvalue(key, value);


    write_constant_value(c, segment, value);
    write_post_op(c, key);

    return;
}
