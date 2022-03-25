#include <stdio.h>
#include <string.h>

char* filenames[300];

unsigned short findex = 0;

unsigned short opensrc(const char* filename)
{ 
    filenames[++findex] = strdup(filename); 
    return findex; 
}

const char* getsrc(unsigned short i) 
{
    return filenames[i];
}
