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


unsigned int test_tools(void)
{
    unsigned int (*tests[]) (void) = {
        test_error,
        NULL
    };

    return run(tests);
}
