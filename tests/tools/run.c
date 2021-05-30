/**
*       Useful functions for running tests
*/

#include <stdio.h>
#include "tools/run.h"


unsigned int run(unsigned int (*tests[]) (void), unsigned int size)
{
    unsigned int i; 

    for (i = 0; i < size; i++)
    {
        if (tests[i]())
        {
            printf("Error in function %i", i);
            return 1;
        }
    }

    return 0;
}
