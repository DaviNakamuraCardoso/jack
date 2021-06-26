/**
*
*
*       Tools to run tests
*
*/
#include <stdio.h>

unsigned int run(unsigned int (*tests[]) (void))
{
    unsigned int i;

    for (i = 0; tests[i] != NULL; i++)
    {
        if (tests[i]())
        {
            printf("Error in test %i\n", i);
            return 1;
        }

    }

    return 0;
}
