#include <stdio.h>
#include <stdlib.h>

void error(char* msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(1); 
}
