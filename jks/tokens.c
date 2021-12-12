#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

enum tokentype {
    KEYWORD,
    NUM_LIT,
    OPERATOR,
    STR_LIT,
    VARIABLE,
};

struct token {
    // Useful metadata
    unsigned int line, character;
    enum tokentype type;

    union {
        long value; 
        char* word;
    };
};

token_t *token_create(enum tokentype type, unsigned int ln, unsigned int chr, void* val)
{
    token_t *t = malloc(sizeof(token_t));

    t->type = type;

    // Metadata
    t->line = ln;
    t->character   = chr;

    // Actual value
    switch (type)
    {
        case NUM_LIT:
            t->value  = *(long*) val;
            break;
        default: 
            t->word = (char*) val;
            break;
    }

    return t; 
} 


token_t *get_operator_token(operator_e type)
{
    token_t *t = malloc(sizeof(token_t));
    t->type = OPERATOR;
    t->value = type;

    return t; 
}

token_t *get_literal_token(FILE* f)
{
    unsigned int i = 0;
    char buff[2000]; 
    token_t *t = malloc(sizeof(token_t));

    for (char c = '\0'; (c = fgetc(f)) != '"'; i++)
        buff[i] = c;

    buff[i] = '\0';

    t->type = STR_LIT;
    t->word = strdup(buff);

    return t; 
}

token_t* get_number_token(char* buff)
{ 
    return token_create(NUM_LIT, 0, 0, (void*)atoll(buff)); 
}

token_t* get_identifier_token(char* buff) 
{
    return token_create(VARIABLE, 0, 0, (void*)buff);
}

token_t *skipic(FILE *f)
{
    char c;

    while ((c = fgetc(f)) != '\n') ; 

    return NULL;
}

token_t *skipmc(FILE* f)
{
    char previous, next;

    previous = fgetc(f);

    for (
            next = fgetc(f); 
            previous != '*' && next != '/';
            previous = next, next = fgetc(f)
        );

    return NULL;
}

