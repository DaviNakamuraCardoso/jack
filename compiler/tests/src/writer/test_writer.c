/**
*
*       Test the writer module
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/compile.h>
#include <writer/writer.h>
#include <utils/tests.h>
#include <utils/writertests.h>


unsigned int test_writevm(void)
{

    char* words1[] = {
        "push constant 11",
        "pop local 2",
        "goto LABEL_2",
        NULL

    };

    char** wordlist[] = {
        words1,
        NULL
    };
    return writer_test("writer/write", wordlist, writevm, NULL);

}

unsigned int test_writer(void)
{
    unsigned int (*tests[]) (void) = {
        test_writevm
    };

    return test(tests, 1);
}
