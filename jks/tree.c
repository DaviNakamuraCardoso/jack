#include <stdlib.h>
#include "tree.h"

enum operators {
    AMPERCENT,
    PIPE,
    STAR,
    SLASH,
    DASH,
    HASH,
    EXCLAMATION,
    PERCENT,
    DOT,
    SEMICOLON,
    RIGHT_SQUARE_BRACKET,
    LEFT_SQUARE_BRACKET,
    PLUS,
    EQUAL,
    RIGHT_BRACE,
    LEFT_BRACE,
    QUESTION
};

struct tree { 
    char tokens[
};

tree_t* tree_new(void)
{
    tree_t *t = malloc(sizeof(tree_t));

