#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <tokenizer.h>

typedef enum { 
    C_ALPHA,
    C_SYMBOL,
    C_NUMBER
} ctype_t;


token_t* get_alpha  (source_t* s);
token_t* get_symbol (source_t* s);
token_t* get_number (source_t* s);
token_t* get_token  (source_t* s);
ctype_t get_ctype(char c);
int skipblank(FILE* f);

token_t** tokenize(const char* filename, FILE* f)
{
    char buff[3000] = {0};
    token_t** tokens = calloc(sizeof(token_t*), 200); 
    optree_t* t = (optree_t*) sgetall();
    opgetall(t);


    source_t s = {.buff=buff, .f=f, .filename=filename, .t=t};

    for (int i = 0;;)
    {

        if (skipblank(f)) break; 
        token_t* t = get_token(&s); 

        if (t) 
        {
            tokens[i++] = t;
#ifdef TOKENIZER_TEST
            printf("|%s|\n", buff);
#endif
        }
    }

    opdestroy(s.t);

    return tokens;
}


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

token_t* (*get[]) (source_t*) = {
    [C_ALPHA]  = get_alpha,
    [C_SYMBOL] = get_symbol,
    [C_NUMBER] = get_number
};

token_t* get_token(source_t *s)
{ 
    char c = fgetc(s->f);
    s->buff[0] = c;
    return get[get_ctype(c)](s);
}

ctype_t get_ctype(char c)
{
    if (isdigit(c)) return C_NUMBER;
    if (isalpha(c)) return C_ALPHA;

    return C_SYMBOL;
}

token_t *get_alpha(source_t* s)
{
    unsigned int bp = 1; 
    char c;

    do {
        c = fgetc(s->f);
        if (c == EOF) { bp++; break; }
        s->buff[bp++] = c;
    } while (isvariable(c));

    ungetc(c, s->f);
    s->buff[--bp] = '\0';

    return get_identifier_token(s); 
}


token_t *get_number(source_t* s)
{
    unsigned int bp = 1;
    char c;

    do {
        c = fgetc(s->f);
        if (c == EOF) { bp++; break; }
        s->buff[bp++] = c;
    } while (isdigit(c));

    ungetc(c, s->f); 
    s->buff[--bp] = '\0'; 

    return get_number_token(s); 
} 

token_t *get_symbol(source_t* s)
{ 
    unsigned int bp = 1;
    char c = s->buff[0];
    optree_t *current = opgetc(s->t, c), *next = NULL;

    if (current == NULL)
    {
        errorat(s->filename, ftell(s->f), "stray '%c' in program", c);
        exit(1);
    }

    do {
        c = fgetc(s->f);
        s->buff[bp++] = c;
        s->buff[bp] = '\0';

        next = opgetc(current, c);
        if (c == EOF) break;
        if (next != NULL) current = next;

    } while (next != NULL);

    ungetc(c, s->f);
    s->buff[--bp] = '\0';

    if (!(current->isoperator)) return get_symbol_token(s, current->symbol);

    switch (current->operator)
    {
        case STR: 
            return get_literal_token(s);
        case COM: 
            return skipic(s->f);
        case MULT_COM:
            return skipmc(s->f);
        default: 
            return get_operator_token(s, current->operator); 
    } 
} 
