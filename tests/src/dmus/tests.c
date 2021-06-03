/**
*
*
*       Main file for the test suite
*
*/

#include <stdio.h>
#include <dmus/tests.h>
#include <dmus/dimensions.h>
#include <tools/run.h>
#include <tools/test_error.h>


int main(int argc, const char* args[])
{
    return test();
}

unsigned int test(void)
{
    unsigned int (*tests[]) (void) = {
        test_error,
        NULL
    };

    return run(tests);
}
