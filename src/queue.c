// Queue module for the Davi Music Player (DMus)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue.h>
#include <time.h>

// Creates a song and assignes it a path
SONG* create(const char* path)
{
    SONG* s;
    s = malloc(sizeof(SONG));
    s->next = NULL;
    s->path = strdup(path);

    return s;
}

// Adds a song to the queue
void add_song(SONG** tail, SONG* new)
{
    (*tail)->next = new;
    *tail = new;

    return;
}

// Calls a song from a given queue
SONG* call_queue(SONG* head, unsigned int *q_size)
{
    SONG* current, *previous;
    unsigned int i;
    long int pos;

    srandom(clock());

    pos = random() % *q_size;
    pos = (pos == 0) ? 1 : pos;

    current = head;
    previous = NULL;
    for (i = 0; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;

    (*q_size)--;

    return (current);

}

void add_queue(SONG** tail, char* name)
{
    SONG* new;
    new = create(name);

    add_song(tail, new);

    return;
}

void release(SONG* head)
{
    return;
}
