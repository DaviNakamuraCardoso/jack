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
    [LA] = '<',
    [LB] = '{',
    [LP] = '(',
    [LS] = '[',
    [PERCENT] = '%',
    [PIPE] = '|',
    [PLUS] = '+',
    [QUESTION] = '?',
    [RA] = '>',
    [RB] = '}',
    [RP] = ')',
    [RS] = ']',
    [SEMICOLON] = ';',
    [SINGLE_QUOTE] = 39,
    [SLASH] = '/',
    [STAR] = '*',
    [__SYM_COUNT] = '\0',
};

const symbol_e svalues[] = {
    ['&'] = AMPERSAND,
    [':'] = COLON,
    [','] = COMMA,
    ['-'] = DASH,
    ['.'] = DOT,
    ['"'] = DOUBLE_QUOTE, 
    ['='] = EQUAL,
    ['!'] = EXCLAMATION,
    ['#'] = HASH,
    ['<'] = LA,
    ['{'] = LB,
    ['('] = LP,
    ['['] = LS,
    ['%'] = PERCENT,
    ['+'] = PLUS,
    ['|'] = PIPE,
    ['>'] = RA,
    ['}'] = RB,
    [')'] = RP,
    [']'] = RS,
    [';'] = SEMICOLON,
    [39] = SINGLE_QUOTE,
    ['/'] = SLASH,
    ['*'] = STAR,

};

symbol_e opindex(char c)
{
    if (!ispunct(c)) return __SYM_COUNT; 
    symbol_e s = svalues[(unsigned int) c];
    if (s == __INVALID) return __SYM_COUNT;
   
    return s;
}

void* sgetall(void)
{
    optree_t *t = opnew();
    for (unsigned int i = __INVALID+1; i < __SYM_COUNT; i++) opaddc(t, symbols[i]);

    return t; 
}
