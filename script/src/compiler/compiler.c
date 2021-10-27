#include <stdio.h>
#include <stdlib.h>

unsigned int compile(FILE* f)
{
    char c = fgetc(f);
    fputc(c, stdout);
    return 0;
}
