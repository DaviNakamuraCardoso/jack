/**
*
*       Functions writer for the Davi Compiler Collection
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/compile.h>
#include <table/parser.h>
#include <writer/writer.h>
#include <writer/assignments.h>
#include <writer/functions.h>


static void write_function_call(CODE* c, char* function_name, unsigned int nargs)
{
    char cmd[300];

    sprintf(cmd, "call %s %i", function_name, nargs);
    writevm(c, cmd);

    return;
}


// For method calls, is necessary to push the object as the first argument
unsigned int push_methodarg(CODE* c, char* classname)
{
    char identifier[300];
    unsigned int is_method;

    get_next_token_content(c, identifier);

    is_method = get_classname(c, identifier, classname);

    // Methods receive the object as first argument
    if (is_method)
    {
        write_push(c, identifier);
        return 1;
    }

    return 0;

}


void write_functioncall(CODE* c, char* classname, char* fname, unsigned int nargs)
{
    char function[700];

    sprintf(function, "%s.%s", classname, fname);

    write_function_call(c, function, nargs);
}


void init_method_args(CODE* c)
{
    c->table->kind_counter[ARGUMENT] = 1;
}

void init_constructor_segment(CODE* c)
{
    // Get the current object size
    unsigned int obj_size = get_object_size(c->table);

    // Set up the current object construction
    write_push_constant(c, obj_size);
    writevm(c, "call Memory.alloc 1");
    write_pop_pointer(c, 0);

    return;

}

void init_method_arguments(CODE* c)
{
    // Set the method "this" segment
    writevm(c, "push argument 0");
    write_pop_pointer(c, 0);
    return;
}

void write_functiondec(CODE* c, char* fname)
{
    char name[300];

    if (c->table == NULL) return;
    if (c->table->next == NULL) return;

    sprintf(name, "function %s.%s %i", c->table->next->classname, fname, c->table->kind_counter[LOCAL]);
    writevm(c, name);
}

void write_privatecall(CODE* c, char* fname, unsigned int nargs)
{
    char classtype[300];

    if (c->table == NULL) return;

    write_functioncall(c, c->table->classname, fname, ++nargs);
    return;
}
