/**
*
*       Parse variable names
*       (c) 2021 Davi Nakamura Cardoso
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <compengine/compile.h>
#include <writer/functions.h>
#include <table/parser.h>
#include <utils/error.h>

static char* get_vm_name(KIND kind)
{
    char* kinds[] = {
         "static",
         "this",
         "argument",
         "local"
    };

    return kinds[kind];
}


static void get_vm_variable(__VARIABLE* v, char* buffer)
{
    const char *name;
    buffer[0] = '\0';

    if (v == NULL) return;

    name = get_vm_name(v->kind);

    sprintf(buffer, "%s %i", name, v->index);

    return;
}

void get_variable(CODE* c, char* varname, char* buffer)
{
    __VARIABLE* v = search_table(c->table, varname);
    get_vm_variable(v, buffer);
    return;
}

void update_table(CODE* c, char* classname, KIND k, TYPE t)
{

    char varname[400];

    if (c == NULL)
    {
        return;
    }
    if (c->table == NULL)
    {
        return;
    }

    get_next_token_content(c, varname);

    add_var(c->table, varname, classname, k, t);

    return;
}

void init_method_decs(CODE* c, __F_TYPE t)
{
    if (t != METHOD) return;

    init_method_args(c);    
}

void init_subroutine_specifics(CODE* c, __F_TYPE t)
{
    switch (t)
    {
        case METHOD:
        {
            init_method_arguments(c);
            return;
        }
        case CONSTRUCTOR:
        {
            init_constructor_segment(c);
            return;
        }
    }

    return;
}



void init_scope(CODE* c)
{
    if (c->table == NULL) return;

    TABLE* table = new_table(c->table->classname);

    table->next = c->table;
    c->table = table;


    return;
}


void exit_scope(CODE* c)
{

    if (c->table == NULL) return;

    TABLE* t = c->table;

    // Prevent the code from exiting the global scope
    if (t->next == NULL) error("Trying to exit global scope");

    c->table = t->next;

    // Prevent the release_table function from destroying the outer scope
    t->next = NULL;

    release_table(&t);

    return;
}

unsigned int get_classname(CODE* c, char* varname, char* buffer)
{
    __VARIABLE* v = search_table(c->table, varname);
    char* content;
    unsigned int status = v != NULL;

    if (status)
    {
        content = v->classname;
    }
    // If no variable is found, the identifier is the classname
    else
    {
        content = varname;
    }

    sprintf(buffer, "%s", content);
    return status;

}
