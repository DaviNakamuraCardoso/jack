#include <stdlib.h>
#include "tree.h"

typedef enum {
    AMPERSAND,
    DASH,
    DOT,
    EQUAL,
    EXCLAMATION,
    HASH,
    LEFT_BRACE,
    LEFT_SQUARE_BRACKET,
    PERCENT,
    PIPE,
    PLUS,
    QUESTION
    RIGHT_BRACE,
    RIGHT_SQUARE_BRACKET,
    SEMICOLON,
    SLASH,
    STAR,
    ZZ_END
} operator_e;

const char operator_tokens[] = { 
    AMPERSAND,
    DASH,
    DOT,
    EQUAL,
    EXCLAMATION,
    HASH,
    LEFT_BRACE,
    LEFT_SQUARE_BRACKET,
    PERCENT,
    PIPE,
    PLUS,
    QUESTION
    RIGHT_BRACE,
    RIGHT_SQUARE_BRACKET,
    SEMICOLON,
    SLASH,
    STAR,
    ZZ_END
};

static optype_e get_opttype(char c)
{
    switch (c) {
        case '&': return AMPERSAND; 
        case '|': return PIPE;
        case '.': return DOT;
        case ',': return COMMA;
        case '*': return STAR;
        case '%': return HASH;
        case '!': return EXCLAMATION;
        case '/': return SLASH;
        case '-': return DASH;

        default: return ZZ_END;
    }
}

enum optype {
    AND,
    OR,
    NOT,
    NEG,
} optype_e;

struct tree { 
    struct tree *chars[ZZ_END];
    optype_e type; 
};

tree_t* tree_new(void)
{
    tree_t *t = malloc(sizeof(tree_t));
    t->chars = calloc(sizeof(char), ZZ_END);
    t->type = ZZ_END;

    return t;
}

void tree_destroy(tree_t* t)
{
    if (t == NULL) return;

    for (unsigned int i = 0; i < ZZ_END; i++)
    {
        if (t->chars[i] != NULL)
            tree_destroy(t->chars[i]);
    }

    free(t); 
} 

unsigned int tree_add(tree_t* t, char* symbol, optype_e type)
{
    tree_t *current = t;

    for (int i = 0; symbol[i] != '\0'; i++)
    {
        current = current->chars[get_optype(symbol[i])];
        if (current == NULL) return 1;
    } 
    current->type = type; 
    return 0; 
}

optype_e get_optype(tree_t* t, char* symbol)
{
}


