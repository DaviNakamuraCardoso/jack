/*
    Source code for the Diamond City Music Player (DMus)
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

SONG *not_played[50];
SONG *played[50];

int main(int argc, char* argv[])
{
    FILE* f;
    char* path;

     if (argc == 2) path = argv[1];
     else path = "~/Music";

     create_hash(path, not_played, played);

     loop();

     close_queue(not_played, played);

    return 0;
}


void loop(char* dir)
{
    while (1)
    {
        play_next_song();
    }
}


void play_next_song(void)
{
    SONG* s;

    s = get_random_song(not_played);
    add_next_position(s, played);

    play(s->path);
    return;
}
