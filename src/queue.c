/*
    Queue module for the Diamond City Music Player (DMus)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue.h>
#include <dmus/dimensions.h>
#include <time.h>

SONG* new_song(const char* path, unsigned int played)
{
    SONG* s;

    s = malloc(sizeof(SONG));

    s->path = path;
    s->next = NULL;
    s->played = played;

    return s;
}
