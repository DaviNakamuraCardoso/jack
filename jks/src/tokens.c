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


token_t *get_operator_token(FILE* f, operator_e type)
{
    return token_create(OPERATOR, ftell(f), (void*)type);
}

token_t *get_literal_token(FILE* f, char* buff)
{
    unsigned int i = 0;
    token_t *t = malloc(sizeof(token_t));

    for (char c = '\0'; (c = fgetc(f)) != '"'; i++)
        buff[i] = c;

    buff[i] = '\0';

    t->type = STR_LIT;
    t->word = strdup(buff);

    return t; 
}

token_t* get_number_token(FILE* f, char* buff)
{ 
    return token_create(NUM_LIT, ftell(f), (void*)atoll(buff)); 
}

token_t* get_identifier_token(FILE* f, char* buff) 
{
    return token_create(IDENTIFIER, ftell(f), (void*)buff);
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

token_t* get_symbol_token(FILE* f, char *c)
{
    symbol_e type = get_symbol_type(*c);

    if (type == ZZ_END)
    {
        size_t location = ftell(f);
        fclose(f);
        
        errorat("file.jks", location);
        exit(1);
    }

    return token_create(SYMBOL, ftell(f), (void*)type); 
}

