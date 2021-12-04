#include <stdio.h>
#include <ctype.h>
#include "ascii.h" 
#include "operators.h"

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

static token_t *token_operator(operator_e type)
{
    token_t *t = malloc(sizeof(token_t));
    t->type = OPERATOR;
    t->value = type;

    return t; 
}

static token_t *token_literal(FILE* f)
{
    unsigned int i = 0;
    char buff[2000]; 
    token_t *t = malloc(sizeof(token_t));

    for (char c = '\0'; (c = fgetc(f)) != '"'; i++)
        buff[i] = c;

    buff[i] = '\0';

    t->type = STR_LITERAL;
    t->word = strdup(buff);

    return buff; 
}

token_t *skip_com(FILE *f)
{
    char c;

    while ((c = fgetc(f)) != '\n') ; 

    return NULL;
}

token_t *skip_mult_com(FILE* f)
{
    char previous, next;

    previous = fgetc(f);

    for (
            next = fgetc(f); 
            previous != '/' && next != '*';
            previous = next, next = fgetc(f);
        );

    return NULL;
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

    } while ((optype = get_operator(buff)) != -1);

    ungetc(f, c);
    buff[--bp] = '\0';

    switch (optype)
    {
        case STR: 
            return token_literal(f);
        case COM: 
              return skip_com(f);
        case MULT_COM:
              return skip_mult_com(f);
        default: 
            return token_operator(buff); 
    }

}



