/**
*
*           Test the writer module for the Compiler
*           (c) 2021 Davi Nakamura Cardoso
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <writer/tracker.h>
#include <utils/tests.h>


static unsigned int test_tracker_creation(void)
{
    unsigned int status;
    TRACKER* t = new_tracker();

    status = t != NULL;
    free(t);

    return status;

}

unsigned int test_tracker(void)
{
    unsigned int (*tests[]) (void) = {
        test_tracker_creation
    };

    return test(tests, 1);
}
