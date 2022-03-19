#include <stdio.h> 
#include <ctype.h>
#include <skip.h>


/**
 *  Skips blank characters, returning 1 when the EOF is reached
 *
 */
int skipblank(FILE* f)
{
    char c;
    do {
        c = fgetc(f);
        if (c == EOF) return 1;
    } while (isspace(c));

    ungetc(c, f);

    return 0;
} 

/*
 * Skips spaces, returning 1 when newline is reached
 *
 */
int skipspace(FILE *f)
{
    char c;

    do {
        c = fgetc(f);
        if (c == EOF) return 0;
        if (c == '\n') return 1;
    } while (isspace(c));

    ungetc(c, f);

    return 0;
}


void *skipic(FILE *f)
{
    char c;

    while ((c = fgetc(f)) != '\n') ; 

    return NULL;
}

void *skipmc(FILE* f)
{
    char previous, next;

    previous = fgetc(f);

    for (
            next = fgetc(f); 
            previous != '*' || next != '/';
            previous = next, next = fgetc(f)
        ) ;

    return NULL;
}
