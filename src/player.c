// Player module for the Davi Music Player (DMus)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <player.h>

int play(const char* song)
{
    char buff[400];
    int status;

    sprintf(buff, "play \"%s\"", song);
    status = system(buff);

    return status;
}
