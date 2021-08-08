/**
*
*
*       Test the queue
*
*/

#include <stdio.h>
#include <jukebox/queue.h>
#include <tests/run.h>


static unsigned int test_new_song(void)
{
    unsigned int status;
    SONG* s = new_song("~/Music/all/'Frank Sinatra - My Way.mp3'", 0);

    status = s == NULL;
    release_song(&s);
    return status;
}

unsigned int test_queue(void)
{
    unsigned int (*tests[]) (void) = {
        test_new_song,
        NULL
    };

    return run(tests);
}
