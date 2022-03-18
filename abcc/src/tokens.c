#include <stdio.h>
#include <stdlib.h>
#include <tokens.h>
#include <error.h>

struct token {
    // Useful metadata
    size_t position;

    enum tokentype type;

    union {
        long value; 
        char* word;
    };
};

inline enum tokentype tktype(token_t* t) { return t->type; }

inline size_t tkloc(token_t* t) { return t->position; }

void* tkvalue(token_t* t)
{
    switch (tktype(t))
    {
        case NUM_LIT:
        case SYMBOL:
        case OPERATOR:
            return (void*) t->value;
        default: 
            return (void*) t->word;
    } 
}

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


token_t* get_char_literal(source_t *s)
{
    long c = fgetc(s->f), next = fgetc(s->f);

    if (next == '\'') goto end; // gotos, oh no

    if (c == '\\')
    {
        c = getesc(next);
        next = fgetc(s->f);
        if (next == '\'') goto end;
    } 

    errorat(s->filename, ftell(s->f), "multi-character character constant");
    exit(1);

end:
#ifdef TOKENIZER_TEST
    s->buff[0] = c;
    s->buff[1] = '\0';
#endif
    return token_create(NUM_LIT, ftell(s->f), (void*)c);

}

token_t* fnewlinet(FILE *f)
{
    return token_create(NEWLINE, ftell(f), NULL);
}

token_t* get_symbol_token(source_t *s, symbol_e type)
{
    if (type == SINGLE_QUOTE) return get_char_literal(s);
    if (type == HASH) s->tl = 1;

    return token_create(SYMBOL, ftell(s->f), (void*)type); 
}

