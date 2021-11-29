#include <stdio.h>
#include <ctype.h>
#include "ascii.h" 

typedef enum { 
    C_ALPHA,
    C_SYMBOL,
    C_NUMBER
} ctype_t;

char* (*get[]) (FILE*, char*) = {
    [C_ALPHA]  = get_alpha,
    [C_SYMBOL] = get_symbol,
    [C_NUMBER] = get_number
};

char* get_token(FILE *f, char* buff)
{ 
    char c = fgetc(f);
    return get[get_ctype(c)](f, buff);
}

ctype_t get_ctype(char c)
{
    if (isdigit(c)) return C_NUMBER;
    if (isalpha(c)) return C_ALPHA;

    return C_SYMBOL;
}

char *get_alpha(FILE* f, char* buff)
{
    unsigned int bp = 1; 
    char c;
    do {
        c = fgetc(f);
        buff[bp++] = c;
    } while (isvariable(c));

    ungetc(f, c);
    buff[--bp] = '\0';

    return buff; 
}

char *get_number(FILE* f, char* buff)
{
    unsigned int bp = 1;
    char c;
    do {
        c = fgetc(f);
        buff[bp++] = c;
    } while (isdigit(c));

    ungetc(f, c); 
    buff[--bp] = '\0'; 

    return buffer; 
}

char *get_symbol(FILE* f, char *buff)
{


    return buff; 
}



