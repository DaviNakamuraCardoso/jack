#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <tokenizer.h> 
#include <pp.h>
#include <string.h>
#include <errno.h>


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

token_t** ftokenize(token_t** ts, const char* filename, optree_t* t)
{
    char buff[3000] = {0}; 
    FILE* f = fopen(filename, "r");

    if (f == NULL)
    {
        fprintf(stderr, "Could not open '%s': %s\n", filename, strerror(errno));
        exit(1);
    }

    source_t s = {.buff=buff, .f=f, .filename=filename, .t=t, .tl=0};

    size_t i = 0;
    for (;;)
    { 

        if (s.tl) 
        {
            if (skipspace(f)) 
            {
                s.tl = 0; 
                i = preprocess(&s, ts+i-1) - ts+i-1;
                continue;
            }
        } else if (skipblank(f)) break; 

        token_t* tk = get_token(&s); 

        if (tk) 
        {
            ts[i++] = tk;
#ifdef TOKENIZER_TEST
            printf("|%s|\n", buff);
#endif
        }
    }


    fclose(f);

    return ts+i;
}

// To be called once
token_t** tokenize(const char* filename)
{
    token_t** ts = calloc(300, sizeof(token_t*)); 

    // Init operator tree
    optree_t* t = (optree_t*) sgetall();
    opgetall(t); 

    ftokenize(ts, filename, t);
    opdestroy(t);

    return ts;
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
    if (isvariable(c)) return C_ALPHA;

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
