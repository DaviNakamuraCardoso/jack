/*
    Queue module for the Diamond City Music Player (DMus)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jukebox/queue.h>
#include <dmus/dimensions.h>
#include <time.h>

SONG* new_song(const char* path, unsigned int played)
{
    SONG* s = (SONG*) malloc(sizeof(SONG));

    s->path = strdup(path);
    s->next = NULL;
    s->played = played;

    return s;
}

SONG** new_queue(const char* path)
{
    SONG** q = (SONG**) calloc(sizeof(SONG*), HASH_SIZE);
    // fill(q);
    return q;
}

void release_song(SONG** s)
{
    free((*s)->path);
    free(*s);
    *s = NULL;
    return;
}

void release_queue(SONG** queue)
{
    for (unsigned int i = 0; i < HASH_SIZE; i++)
    {
        SONG *current, *next;
        current = queue[i];
        for (next = current->next; current != NULL; current = next)
        {
            next = current->next;
            release_song(&current);
        }
    }
    return;
}
