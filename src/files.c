/*
    Files module for the Diamond City Music Player (DMus)

*/
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
void find_songs(const char* path, SONG* hash[])
{
    int i;
    DIR* dir;
    struct dirent* de;

    dir = opendir(path);
    if (dir == NULL) return;

    while ((de = readdir(dir)) != NULL)
    {
        char song_path[1500];
        sprintf(song_path, "%s/%s", path, de->d_name);

        // Recursivily searches for songs in subdirectories
        if (is_dir(de->d_name)) find_songs(song_path, tail);

        if (is_song(de->d_name)) add_queue(tail, song_path);
    }

    close(dir);

    return;
}
