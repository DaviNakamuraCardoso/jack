#include <stdio.h>
#include <stdlib.h>


static int errorat(const char* filename, size_t target)
{
    FILE *f = fopen(filename, "r");
    unsigned int lines = 0, characters = 0;
    char line[1000];

    for (size_t i = 0; i < target; i++)
    {
        char c = fgetc(f);

        line[characters++] = c;

        if (c == '\n' || c == '\r') 
        {
            characters = 0;
            lines++;
        }
    }
    
    char c;
    for (int i = 0; (c = fgetc(f)) != '\n' && c != EOF; i++) line[characters++] = c; 
    line[characters] = '\0';

    fprintf(stderr, "%s\n", line); 

    fclose(f);

    return 0;

}
