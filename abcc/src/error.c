#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static char* egetl(FILE* f, char *line, size_t target, size_t* lines, size_t *characters); 

static int eputh(const char* filename, size_t lines, size_t characters, const char* format, va_list va); 

static int eputc(char* line, size_t lines, size_t characters);

int errorat(const char* filename, size_t target, const char* format, ...)
{
    FILE *f = fopen(filename, "r");
    size_t lines = 0, characters = 0;
    char line[1000];
    va_list ap;


    egetl(f, line, target, &lines, &characters);

    va_start(ap, format);
    eputh(filename, lines, characters, format, ap);
    va_end(ap);

    eputc(line, lines, characters);


    fclose(f);

    return 0; 
}

static char* egetl(FILE* f, char *line, size_t target, size_t* lines, size_t *characters)
{
    for (size_t i = 0; i < target; i++)
    {
        char c = fgetc(f);

        line[(*characters)++] = c;

        if (c == '\n' || c == '\r') 
        {
            *characters = 0;
            *lines = *lines + 1;
        }
    }

    char c;
    unsigned int i;

    for (i = *characters; (c = fgetc(f)) != '\n' && c != EOF; i++) line[i] = c; 
    line[i] = '\0';

    return line;
}

static int eputh(const char* filename, size_t lines, size_t characters, const char* format, va_list va)
{

    fprintf(stderr, "\033[15m\033[1m%s:%zu:%zu: \033[0m", filename, lines, characters); 
    fprintf(stderr, "\033[31m\033[1merror:\033[0m ");

    fprintf(stderr, "\033[15\033[1m"); 
    vfprintf(stderr, format, va); 
    fprintf(stderr, "\033[0m\n"); 


    return 0; 
}

static int eputc(char* line, size_t lines, size_t characters)
{
    fprintf(stderr, "  %zu |%s\n", lines, line); 

    // Align with line number
    fputc(' ', stderr); fputc(' ', stderr); 
    for (unsigned int i = lines; i > 0; i /= 10) fputc(' ', stderr);

    // Align with characters
    fputc(' ', stderr);
    fputc('|', stderr); 
    for (unsigned int i = 0; i < characters - 1; i++) fputc(' ', stderr);

    // Point to error
    fprintf(stderr, "\033[31m\033[1m^\033[0m\n");

    return 0;
}
