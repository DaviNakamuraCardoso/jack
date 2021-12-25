#include <stdlib.h>
#include <symbols.h> 
#include <ctype.h>
#include <optree.h>

const char symbols[] = { 
    [AMPERSAND] = '&',
    [COLON] = ':',
    [COMMA] = ',',
    [DASH] = '-',
    [DOT] = '.',
    [EQUAL] = '=',
    [EXCLAMATION] = '!',
    [HASH] = '#',
    [LEFT_ANGLE] = '<',
    [LEFT_BRACE] = '{',
    [LEFT_PARENTHESIS] = '(',
    [LEFT_SQUARE_BRACKET] = '[',
    [PERCENT] = '%',
    [PIPE] = '|',
    [PLUS] = '+',
    [QUESTION] = '?',
    [RIGHT_ANGLE] = '>',
    [RIGHT_BRACE] = '}',
    [RIGHT_PARENTHESIS] = ')',
    [RIGHT_SQUARE_BRACKET] = ']',
    [SEMICOLON] = ';',
    [SLASH] = '/',
    [STAR] = '*',
    [__SYM_COUNT] = '\0',
};

symbol_e opindex(char c)
{
    if (!ispunct(c)) return __SYM_COUNT;

    switch (c) {
        case ';': return SEMICOLON;
        case '=': return EQUAL;
        case ')': return RIGHT_PARENTHESIS;
        case '(': return LEFT_PARENTHESIS;
        case '}': return RIGHT_BRACE; 
        case '{': return LEFT_BRACE; 
        case '[': return LEFT_SQUARE_BRACKET;
        case ']': return RIGHT_SQUARE_BRACKET;
        case '>': return RIGHT_ANGLE;
        case '<': return LEFT_ANGLE; 
        case '\'': return SINGLE_QUOTE; 
        case ':': return COLON; 
        case '"': return DOUBLE_QUOTE; 
        case '*': return STAR;
        case '/': return SLASH;
        case '-': return DASH;
        case '.': return DOT;
        case '+': return PLUS;
        case ',': return COMMA;
        case '%': return HASH;
        case '!': return EXCLAMATION;
        case '#': return HASH;
        case '&': return AMPERSAND; 
        case '|': return PIPE;
    }

    return __SYM_COUNT;
}

void* sgetall(void)
{
    optree_t *t = opnew();
    for (unsigned int i = 0; i < __SYM_COUNT; i++) opaddc(t, symbols[i]);

    return t; 
}
