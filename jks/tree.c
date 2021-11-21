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


struct tree { 

};

tree_t* tree_new(void)
{
    tree_t *t = malloc(sizeof(tree_t));
    for (int i = 0; i < ; i++)
    {

    }

