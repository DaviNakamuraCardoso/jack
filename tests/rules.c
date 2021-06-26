/**
*
*
*       Automates the makefile process
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "rules.h"

#define SOURCE "../"

typedef struct dirent DE;

int main(unsigned int argc, const char** argv)
{

}

static void get_sources(char* path)
{
    DE* dirent;
    DIR* dir;

    dir = opendir(path);

    while ((dirent = readdir(dir)) != NULL)
    {
        if (is_directory(dirent))
        {
            get_sources(strcat(path, dirent->d_name));
        }
        
    }

    closedir(path);
}
