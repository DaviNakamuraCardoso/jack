/**
*
*
*       Main file for the test suite
*
*/

#include <stdio.h>
#include <dmus/tests.h>
#include <dmus/testtools.h>
#include <tests/tests.h>
#include <tests/error.h>
#include <tests/run.h>


int main(int argc, const char* args[])
{
    unsigned int status = testall();

    if (!status) printf("All tests passed.\n");

    return status;
}

static unsigned int testall(void)
{
    unsigned int (*tests[]) (void) = {
        test_tools,
        NULL
    };
    return run(tests);
}
