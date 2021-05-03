// Files module for the Davi Music Player (DMus)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>
#include <queue.h>
#include <files.h>


// Returnes 1 if the given string is a song
bool is_song(char* path)
{
    return (strstr(path, ".mp3") != NULL);
}

// Search for songs
bool is_dir(char* name)
{
    return (strchr(name, '.') == NULL);

}

// Searches all the songs in a given directory
void find_songs(const char* path, SONG** tail)
{
    int i;
    DIR* dir;
    char* p;
    struct dirent* de;

    printf("Opening dir in path: %s\n", path);

    dir = opendir(path);
    if (dir == NULL) return;

    printf("In path: %s\n", path);
    while ((de = readdir(dir)) != NULL)
    {
        // Gets space for a new path
        p = malloc(1000*sizeof(char));
        strcpy(p, path);
        strcat(strcat(p, "/"), de->d_name);

        if (is_dir(de->d_name))
        {
            find_songs(p, tail);
        }
        if (is_song(de->d_name))
        {

            printf("Song found: %s\n", p);
            add_queue(tail, p);

        }
        free(p);
    }

    return;
}
