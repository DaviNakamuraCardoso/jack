/*
    Player module for the Diamond City Music Player (DMus)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jukebox/player.h>

// Perform a system call to play a song
int play(const char* song)
{
    char buff[400];
    int status;

    sprintf(buff, "play \"%s\"", song);
    status = system(buff);

    return status;
}
