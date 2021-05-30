/**
*
*       Test functions for the queue module
*       (c) 2021 Davi Nakamura Cardoso
*
*/

#include <stdio.h>
#include "../includes/queue.h"
#include "queue/tests.h"
#include "tools/run.h"

static unsigned int test_new_song(void)
{
    SONG* s = new_song("./Chicago.mp3", 0);

    return (s == NULL);
}


unsigned int test_queue(void)
{
    unsigned int (*tests[]) (void) = {
        test_new_song
    };
    return run(tests, 1);
}
