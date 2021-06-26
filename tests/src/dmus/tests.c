/**
*
*
*       Main file for the test suite
*
*/

#include <stdio.h>
#include <dmus/tests.h>
#include <dmus/dimensions.h>
#include <tests/tests.h>
#include <tests/error.h>


int main(int argc, const char* args[])
{
    unsigned int status = test();

    if (!status) printf("All tests passed.\n");

    return status;
}

static unsigned int test(void)
{
    unsigned int (*tests[]) (void) = {
        test_error,
        NULL
    };

    return run(tests);
}
