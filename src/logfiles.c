/*
    Logfiles for the Diamond City Music Player (DMus)
*/

#include <stdio.h>
#include <stdlib.h>
#include <queue.h>
#include <files.h>
#include <logfiles.h>

#define LOGNAME "./cache/queue.csv"

// Creates a new log
FILE* create_log(char* dir)
{
    FILE* f, *ret;
    SONG* tail, *head, *current;
    unsigned int counter;

    tail = create("foo");
    head = tail;

    f = fopen(LOGNAME, "w");
    find_songs(dir, &tail);

    current = head->next;

    counter = 0;
    while (current != NULL)
    {
        fprintf(f, "%i,%s\n", 0, current->path);
        current = current->next;
        counter++;
    }
    fclose(f);

    ret = fopen(LOGNAME, "r");
    return ret;

}

// Splits the result of reading a CSV line into two buffers
void fsplit(char* buffer, char* new, int* integer)
{
    char a[4];
    int i, j, k;
    unsigned int is_after;

    is_after = 0;
    for (i = 0, k = 0, j = 0; buffer[i] != '\n'; i++)
    {
        if (is_after == 1)
        {
            new[k] = buffer[i];
            k++;
        }
        else
        {
            if (buffer[i] == ',') is_after = 1;
            a[j] = buffer[i];
            j++;

        }
    }
    new[k] = '\0';
    *integer = atoi(a);
    return;
}

// Saves the played songs in a logfile
void openlog(char* dir, SONG** head, SONG** played_head, int* size)
{
    char buff[400], *b;
    unsigned int a, counter;
    FILE* f, *d;
    SONG *tail, *current, *played;


    f = fopen(LOGNAME, "r");
    if (f == NULL) f = create_log(dir);

    *head = create("0");
    *played_head = create("0");

    tail = *head;
    played = *played_head;

    counter = 0;

    while (fgets(buff, 400, f) != NULL)
    {
        char name[400];
        fsplit(buff, name, &a);


        counter++;
        if (a == 0)
        {
            add_queue(&tail, name);
        }
        else
        {
            add_queue(&played, name);
            counter--;
        }

    }
    *size = counter;
    *head = (*head)->next;
    *played_head = (*played_head)->next;

    fclose(f);

    return;

}

void close_queue(SONG* head, SONG* played)
{
    FILE* f;
    SONG* current;

    f = fopen(LOGNAME, "w");

    current = head;
    while (current != NULL)
    {
        fprintf(f, "%i,%s\n", current->called, current->path);
        current = current->next;
    }

    current = played;
    while (current != NULL)
    {
        fprintf(f, "%i,%s\n", 1, current->path);
        current = current->next;
    }
}
