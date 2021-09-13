/**
*
*
*       Test assignment generation
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/compile.h>
#include <compengine/expressions.h>
#include <compengine/statements.h>
#include <writer/assignments.h>
#include <utils/tests.h>
#include <utils/writertests.h>

static unsigned int test_write_stack_cmd(char* cmd, void (*tested) (CODE*, char*))
{

    char path[200];

    char* vars[] = {
        "hello", "f","bing", "crosby", NULL
    };

    char** words[] = {
        vars, NULL
    };

    TABLE* t = new_table("Hello");

    add_var(t, "hello", NULL, STATIC, INT);
    add_var(t, "f", NULL, LOCAL, CHAR);
    add_var(t, "bing", NULL, FIELD, INT);
    add_var(t, "crosby", NULL, ARGUMENT, CHAR);


    sprintf(path, "writer/%s", cmd);

    return writer_test(path, words, tested, t);
}

static unsigned int test_write_pop(void)
{
    return test_write_stack_cmd("pop", write_pop);
}

static unsigned int test_write_push(void)
{
    return test_write_stack_cmd("push", write_push);
}

static unsigned int test_write_intconstant(void)
{
    char* words1[] = {"1917", "2020", "103", NULL};
    char* words2[] = {"1903", "2003", "100", NULL};
    char** words[] = {
        words1,
        words2,
        NULL
    };

    return writer_test("writer/intconstant", words, write_intconstant, NULL);
}

static unsigned int test_write_keyconstant(void)
{
    char* words1[] = {
        "null",
        "true",
        "false",
        NULL
    };

    char** words[] = {
        words1, NULL
    };

    return writer_test("writer/keyconstant", words, write_keyconstant, NULL);
}

static unsigned int test_write_stringliteral(void)
{
    char* words1[] = {
        "HI",
        NULL
    };
    char** words[] = {
        words1,
        NULL
    };

    return writer_test("writer/stringliterals", words, write_stringliteral, NULL);
}

static unsigned int test_write_expressions(void)
{
    TABLE* t = new_table("Writer");
    add_var(t, "k", NULL, ARGUMENT, INT);
    return writer_compare("writer/expressions", compile_expression, 5, t);
}

static unsigned int test_write_let(void)
{
    TABLE* t = new_table("Carry");
    add_var(t, "a", NULL, FIELD, INT);
    add_var(t, "b", "Array", ARGUMENT, CLASSNAME);
    add_var(t, "c", "Array", ARGUMENT, CLASSNAME);
    add_var(t, "d", "Array", ARGUMENT, CLASSNAME);
    return writer_compare("writer/let", compile_let, 5, t);
}


unsigned int test_assignments(void)
{
    unsigned int (*tests[]) (void) = {
        test_write_pop,
        test_write_push,
        test_write_intconstant,
        test_write_keyconstant,
        test_write_stringliteral,
        test_write_expressions,
        test_write_let
    };

    return test(tests, 7);
}
