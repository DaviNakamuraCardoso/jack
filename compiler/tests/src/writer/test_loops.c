/**
*
*
*       Test the loop writer
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/compile.h>
#include <compengine/statements.h>
#include <utils/tests.h>
#include <utils/writertests.h>
#include <writer/loops.h>


static unsigned int test_write_label(void)
{

    char buffer[] = "LABEL_0";
    char buffer2[] = "LABEL_1";
    char buffer3[] = "LABEL_2";

    char* buffers0[] = {
        buffer, NULL
    };

    char* buffers[] = {
        buffer, buffer2, NULL
    };

    char* buffers2[] = {
        buffer, buffer2, buffer3, NULL
    };

    char** words[] = {
        buffers0, buffers, buffers2, NULL
    };

    return writer_test("writer/labels", words, write_label, NULL);
}


static unsigned int test_write_ifgoto(void)
{
    char* labels[] = {
        "HELLO",
        "LABEL_1",
        NULL
    };

    char** words[] = {
        labels,
        NULL
    };

    return writer_test("writer/ifgoto", words, write_ifgoto, NULL);
}


static unsigned int test_write_goto(void)
{
    char* labels[] = {
        "open",
        "close",
        "write",
        NULL
    };

    char** words[] = {
        labels, NULL
    };

    return writer_test("writer/goto", words, write_goto, NULL);
}

static unsigned int test_if_branch(void)
{
    return writer_compare("writer/if", compile_if, 3, NULL);
}

static unsigned int test_while_loop(void)
{
    return writer_compare("writer/while", compile_while, 1, NULL);
}

unsigned int test_loops(void)
{

    unsigned int (*tests[]) (void) = {
        test_write_label,
        test_write_ifgoto,
        test_write_goto,
        test_if_branch,
        test_while_loop
    };

    return test(tests, 5);
}
