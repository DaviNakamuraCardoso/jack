#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokenizer.h"

typedef enum { 
    C_ALPHA,
    C_SYMBOL,
    C_NUMBER
} ctype_t;

token_t* get_alpha(FILE*, char*);
token_t* get_symbol(FILE*, char*);
token_t* get_number(FILE*, char*);
token_t* get_token(FILE *f, char* buff);
ctype_t get_ctype(char c);
int skipblank(FILE* f);


token_t** tokenize(FILE* f)
{
    char buff[3000] = {0};
    token_t** tokens = calloc(sizeof(token_t*), 10);

    for (int i = 0;;)
    {
        if (skipblank(f)) break; 

        token_t *t = get_token(f, buff); 
        if (t) tokens[i++] = t;
        printf("%s\n", buff);
    }

    return NULL;
}


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

token_t* (*get[]) (FILE*, char*) = {
    [C_ALPHA]  = get_alpha,
    [C_SYMBOL] = get_symbol,
    [C_NUMBER] = get_number
};

token_t* get_token(FILE *f, char* buff)
{ 
    char c = fgetc(f);
    buff[0] = c;
    return get[get_ctype(c)](f, buff);
}

ctype_t get_ctype(char c)
{
    if (isdigit(c)) return C_NUMBER;
    if (isalpha(c)) return C_ALPHA;

    return C_SYMBOL;
}

token_t *get_alpha(FILE* f, char* buff)
{
    unsigned int bp = 1; 
    char c;

    do {
        c = fgetc(f);
        if (c == EOF) { bp++; break; }
        buff[bp++] = c;
    } while (isvariable(c));

    ungetc(c, f);
    buff[--bp] = '\0';

    return get_identifier_token(buff); 
}

token_t *get_number(FILE* f, char* buff)
{
    unsigned int bp = 1;
    char c;

    do {
        c = fgetc(f);
        if (c == EOF) { bp++; break; }
        buff[bp++] = c;
    } while (isdigit(c));

    ungetc(c, f); 
    buff[--bp] = '\0'; 

    return get_number_token(buff); 
}


token_t *get_symbol(FILE* f, char *buff)
{ 
    unsigned int bp = 1;
    char c;
    operator_e optype;

    do {
        c = fgetc(f);
        buff[bp++] = c;
        buff[bp] = '\0';
        if (c == EOF) break;
    } while (isoperator(buff));

    ungetc(c, f);
    buff[--bp] = '\0';

    optype = get_operator(buff);

    switch (optype)
    {
        case OP_INVALID:
            fprintf(stderr, "Invalid operator %s!\n", buff);
            return NULL;
        case STR: 
            return get_literal_token(f);
        case COM: 
            return skipic(f);
        case MULT_COM:
            return skipmc(f);
        default: 
            return get_operator_token(optype); 
    } 
} 

