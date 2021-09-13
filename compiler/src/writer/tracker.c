/**
*
*       Determines counters for labels
*       (c) 2021 Davi Nakamura Cardoso
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <writer/tracker.h>

static TRACKER* trackeralloc(void)
{
    return (TRACKER*) malloc(sizeof(TRACKER));
}

TRACKER* new_tracker(void)
{
    TRACKER* t = trackeralloc();
    t->counter = 0;

    return t;

}

void release_tracker(TRACKER* t)
{
    free(t);
    return;
}
