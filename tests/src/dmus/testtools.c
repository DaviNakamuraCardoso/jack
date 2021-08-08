/**
*
*
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <tests/error.h>
#include <tests/run.h>


static unsigned int test_compile(void)
{
    return system("cd .. && make all");
}

unsigned int test_tools(void)
{
    unsigned int (*tests[]) (void) = {
        test_error,
        test_compile,
        NULL
    };

    return run(tests);
}
