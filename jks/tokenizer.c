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


