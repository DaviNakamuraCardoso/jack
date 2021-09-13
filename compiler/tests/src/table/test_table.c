/**
*
*       Test the table module for the Davi Compiler Collection (DCC)
*       (c) 2021 Davi Nakamura Cardoso
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <table/table.h>
#include <utils/tests.h>


static unsigned int test_new_table(void)
{
    unsigned int status;
    TABLE* t;

    t = new_table("Main");
    status = t != NULL;
    free(t->variables);
    free(t);
    return status;
}

static unsigned int test_new_variable(void)
{
    unsigned int status;
    __VARIABLE* v;

    v = new_variable("Hi", "Brown", STATIC, INT);
    status = v != NULL;

    free(v->name);
    free(v);

    return status;
}

static unsigned int test_release_table(void)
{
    TABLE* t = new_table("Sing");

    t->variables[0] = new_variable("dbrey", "Hello", FIELD, CLASSNAME);
    t->variables[0]->next = new_variable("gkel", "Rain", FIELD, CLASSNAME);
    t->variables[1] = new_variable("fsin", NULL, STATIC, INT);

    release_table(&t);
    return t == NULL;
}

static unsigned int test_add_hash(void)
{
    unsigned int status;

    //  Declares a variable and a table
    __VARIABLE* v = new_variable("", NULL, FIELD, INT);
    TABLE* t = new_table("Hi");

    /*
    *  According to the hash function, an empty string variable must be
    *  in position 0;
    */
    add_hash(t, v);
    status = t->variables[0] != NULL;
    release_table(&t);

    return status;
}

static unsigned int test_add_var(void)
{
    TABLE* t = new_table("HI");

    char* names[] = {
         "skeeter", NULL
    };
        KIND kinds[] = {
            FIELD, STATIC
    };
    TYPE types[] = {
            INT, BOOLEAN
    };

    char* typenames[] = {
        NULL, NULL
    };

    for (int i = 0; i < 2; i++)
    {
       add_var(t, names[i], typenames[i],  kinds[i], types[i]);
    }

    for (int i = 0; i < 2; i++)
    {
       __VARIABLE* v = search_table(t, names[i]) ;
       if (v->type != types[i] || v->kind != kinds[i])
       {
           puts("Wrong variable type");
           release_table(&t);
           return 0;
       }

    }

    release_table(&t);

    return 1;
}


static unsigned int test_search_variable(void)
{
    __VARIABLE* vars[] = {
            new_variable("steam", NULL, STATIC, INT),
            new_variable("heat", NULL, STATIC, INT),
            new_variable("radiator", NULL, STATIC, INT)
    };

    char* names[] = {
            "steam",
            "heat",
            "radiator"
    };

    TABLE* table = new_table("Heat");

    for (int i = 0; i < 3; i++)
    {
       add_hash(table, vars[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        if (search_table(table, names[i]) == NULL)
        {
            printf("Couldn't find %s in hash.\n", names[i]);
            return 0;
        }
    }

    release_table(&table);
    return 1;
}

static unsigned int test_get_typename(void)
{
    __VARIABLE* vars[] = {
        new_variable("a", NULL, LOCAL, INT),
        new_variable("tea", "Tea", STATIC, CLASSNAME),
        new_variable("has_alcohol", NULL, ARGUMENT, BOOLEAN),
        new_variable("initial", NULL, FIELD, CHAR)
    };

    char* expected[]  = {
        "int", "Tea", "boolean", "char"
    };

    char result[300];

    for (int i = 0; i < 4; i++)
    {
        get_typename(vars[i], result);

        if (strcmp(result, expected[i]) != 0)
        {
            printf("Expected: %s\n", expected[i]);
            printf("Result: %s\n", result);
            return 0;
        }

        release_variable(vars[i]);
    }

    return 1;
}


unsigned int test_table(void)
{
    unsigned int (*tests[]) (void) = {
        test_new_table,
        test_new_variable,
        test_release_table,
        test_add_hash,
        test_search_variable,
        test_get_typename
    };

    return test(tests, 6);
}
