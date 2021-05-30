/**
*
*       Main Module for Unit Testing
*       (c) 2021 Davi Nakamura Cardoso
*/

#include <stdio.h>
#include "tests.h"
#include "tools/run.h"
#include "queue/tests.h"

int main(void)
{
    test();

    return 0;
}

static void test(void)
{
    unsigned int (*tests[]) (void) = {
        test_queue
    };

    if (run(tests, 1)) printf("________________ ERROR _____________\n");
}
