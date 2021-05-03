/*
    Source code for the Davi Music Player (DMus)
    Released Under the MIT License
    (c) 2021 Davi Nakamura Cardoso
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <signal.h>
#include <player.h>
#include <queue.h>
#include <files.h>
#include <logfiles.h>
#include <main.h>

SONG *head = NULL;
SONG *played = NULL;

int main(int argc, char* argv[])
{
    FILE* f;

     if (argc != 2) error("Wrong number of arguments");


     loop(argv[1]);

     printf("Done executing song.\n");
     close_queue(head, played);

    return 0;
}


int catch_signal(int sig, void (*handler) (int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    return sigaction(sig, &action, NULL);
}

void kill_handler(int sig)
{
    printf("Goodbye\n");
    exit(0);
}


void loop(char* dir)
{
    char ans;
    int size, status;
    SONG *selected, *tail_played, *tail;

    selected = NULL;
    size = 0;

    openlog(dir, &head, &played, &size);
    printf("Head is %s\n", head->path);

    tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail_played = played;

    while (tail_played->next != NULL)
    {
        tail_played = tail_played->next;
    }

    system("clear");
    printf("There are %i songs in queue.\n", size);

    while (1)
    {
        selected = call_queue(head, &size);
        add_queue(&tail_played, selected->path);
        printf("Selected %s\n", selected->path);
        status = play(selected->path);

        if (status != 0)
        {
            break;
        }

        // If there are no songs in the queue, swap with the played queue
        if (size == 0)
        {
            SONG* tmp, *tmp2, *curr;

            // Swap heads
            tmp = head;
            head = played;
            played = tmp;

            // Swap tails
            tmp2 = tail;
            tail = played;
            played = tmp2;

            // Get the queue size
            while (curr != NULL)
            {
                curr = curr->next;
                size++;
            }
        }
        system("clear");
    }
     return;
}
