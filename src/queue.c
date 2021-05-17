/*
    Queue module for the Diamond City Music Player (DMus)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue.h>
#include <dmus/dimensions.h>
#include <time.h>

// Creates a song and assignes it a path
SONG* create_song(const char* path)
{
    SONG* song;
    song = malloc(sizeof(SONG));

    song->path = path;
    song->next = NULL;

    return song;
}

unsigned short hash_based_on_path(const char* path, unsigned int max_size)
{
    short s;
    unsigned int total;

    for (s = 0; path[s] != '\0'; s++)
    {
        total += path[s];
    }

    return (total % HASH_SIZE);
}

void add_queue(SONG* hash[], char* path)
{
    unsigned short index;
    SONG* new;

    index = hash_based_on_path(path);
    new = create_song(path);

    new->next = hash[index];
    hash[index] = new;

    return;
}

SONG* pop_queue(SONG* hash[], unsigned short index)
{
    SONG *first, *second;

    first = hash[index];
    if (first == NULL) return NULL;

    second = first->next;
    hash[index] = second;

    return first;
}
