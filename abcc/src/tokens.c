#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tokens.h>
#include <error.h>

struct token {
    // Useful metadata
    size_t position;
    unsigned short findex;

    enum tokentype type;

    union {
        long value; 
        char* word;
    };
};

enum tokentype tktype(token_t* t) { return t->type; }

size_t tkloc(token_t* t) { return t->position; }

unsigned short tkfindex(token_t* t) { return t->findex; }

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

token_t *token_create(enum tokentype type, size_t position, unsigned short findex, void* val)
{
    token_t *t = malloc(sizeof(token_t));

    t->type = type;

    // Metadata
    t->position = position;
    t->findex = findex;

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
    return token_create(OPERATOR, ftell(s->f), s->findex, (void*)type);
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
    return token_create(NUM_LIT, ftell(s->f), s->findex, (void*)atoll(s->buff)); 
}

token_t* get_identifier_token(source_t *s) 
{
    return token_create(IDENTIFIER, ftell(s->f), s->findex, (void*)strdup(s->buff));
}


token_t* get_path_literal(source_t *s)
{
    char c = fgetc(s->f);
    char buff[300] = {0};

    for (int i = 0; c != '>'; c = fgetc(s->f), i++) buff[i] = c;

    return token_create(STR_LIT, ftell(s->f), s->findex, (void*)strdup(buff));
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
    return token_create(NUM_LIT, ftell(s->f), s->findex, (void*)c);

}

token_t* get_symbol_token(source_t *s, symbol_e type)
{
    if (type == SINGLE_QUOTE) return get_char_literal(s);
    if (type == LA && s->tl) return get_path_literal(s);
    if (type == HASH) s->tl = 1;

    return token_create(SYMBOL, ftell(s->f), s->findex, (void*)type); 
}

int tkerror(token_t* t, const char* fmt, ...)
{ 
    va_list ap;

    va_start(ap, fmt);
    printf("%s,%d\n", getsrc(t->findex), t->findex);
    verrorat(getsrc(t->findex), t->position, fmt, ap);
    va_end(ap);
            
    return 0; 
}

void tkprint(token_t* t)
{ 
    switch (t->type)
    {
        case NUM_LIT:
        case SYMBOL:
        case OPERATOR:
            printf("%li\n", (long) t->value);
            break;
        default: 
            printf("%s\n", (char*) t->word);
            break;
    }
}
