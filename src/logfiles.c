/*
    Logfiles for the Diamond City Music Player (DMus)
*/

#include <stdio.h>
#include <stdlib.h>
#include <queue.h>
#include <files.h>
#include <logfiles.h>

#define LOGNAME "./cache/queue.csv"



void write_row(FILE* f, SONG* row)
{
    SONG* current;

    for (current = row; current != NULL; current = current->next)
    {
        fprintf(f, "%i,%s\n", current->played, current->path);
    }

    return;
}
void write_queue(FILE* f, SONG* hash[])
{
    unsigned short s;
    SONG* current;

    for (s = 0; s < HASH_SIZE; s++)
    {
        write_row(f, hash[s]);
    }

    return;
}

// Creates a new log
FILE* create_log(char* dir)
{
}


// Closes the queue
void close_queue(SONG* not_played[], SONG* played[])
{
    FILE* f;

    f = fopen(LOGNAME, "w");

    write_queue(not_played, f);
    write_queue(played, f);

    fclose(f);

}
