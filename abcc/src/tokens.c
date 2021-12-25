#include <stdio.h>
#include <stdlib.h>
#include <tokens.h>
#include <error.h>

enum tokentype {
    KEYWORD,
    NUM_LIT,
    OPERATOR,
    SYMBOL,
    STR_LIT,
    IDENTIFIER,
};

struct token {
    // Useful metadata
    size_t position;

    enum tokentype type;

    union {
        long value; 
        char* word;
    };
};

token_t *token_create(enum tokentype type, size_t position, void* val)
{
    token_t *t = malloc(sizeof(token_t));

    t->type = type;

    // Metadata
    t->position = position;

    // Actual value
    switch (type)
    {
        case NUM_LIT:
        case SYMBOL:
        case OPERATOR:
            t->value  = (long) val;
            break;
        default: 
            t->word = (char*) val;
            break;
    }

    return t; 
} 

token_t *get_operator_token(source_t* s, operator_e type)
{
    return token_create(OPERATOR, ftell(s->f), (void*)type);
}

token_t *get_literal_token(source_t *s)
{
    unsigned int i = 0;
    token_t *t = malloc(sizeof(token_t));

    for (char c = '\0'; (c = fgetc(s->f)) != '"'; i++)
    {
        s->buff[i] = c;
        if (c == '\\')
        {
            s->buff[++i] = fgetc(s->f); 
        }
    }

    s->buff[i] = '\0';

    t->type = STR_LIT;
    t->word = strdup(s->buff);

    return t; 
}

token_t* get_number_token(source_t *s)
{ 
    return token_create(NUM_LIT, ftell(s->f), (void*)atoll(s->buff)); 
}

token_t* get_identifier_token(source_t *s) 
{
    return token_create(IDENTIFIER, ftell(s->f), (void*)s->buff);
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
            previous != '*' || next != '/';
            previous = next, next = fgetc(f)
        ) ;

    return NULL;
}

token_t* get_symbol_token(source_t *s, symbol_e type)
{
    return token_create(SYMBOL, ftell(s->f), (void*)type); 
}

