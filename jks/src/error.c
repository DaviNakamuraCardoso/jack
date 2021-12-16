#include <stdio.h>
#include <stdlib.h>


int errorat(const char* filename, size_t target)
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
    unsigned int i;
    for (i = characters; (c = fgetc(f)) != '\n' && c != EOF; i++) line[i] = c; 
    line[i] = '\0';

    fprintf(stderr, "\033[15m\033[1m%s:%i:%i: \033[0m", filename, lines, characters);
    fprintf(stderr, "\033[31m\033[1merror:\033[0m\n");
    fprintf(stderr, "  %i |%s\n", lines, line); 

    fprintf(stderr, "  ");
    
    for (unsigned int i = lines; i > 0; i /= 10) fputc(' ', stderr);
    fputc(' ', stderr);
    fputc('|', stderr);
    for (unsigned int i = 0; i < characters - 1; i++) fputc(' ', stderr);

    fprintf(stderr, "\033[31m\033[1m^\033[0m\n");

    fclose(f);

    return 0;

}
