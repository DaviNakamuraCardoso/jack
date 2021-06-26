/*
        Error module for the Diamond City Music Player (DMus)
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>

void error(char* msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
    return;
}
