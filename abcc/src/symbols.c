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
    [DOUBLE_QUOTE] = '"',
    [EQUAL] = '=',
    [EXCLAMATION] = '!',
    [HASH] = '#',
    [LA] = '<',
    [LB] = '{',
    [LP] = '(',
    [LS] = '[',
    [PERCENT] = '%',
    [PLUS] = '+',
    [PIPE] = '|',
    [QUESTION] = '?',
    [RA] = '>',
    [RB] = '}',
    [RP] = ')',
    [RS] = ']',
    [SEMICOLON] = ';',
    [SINGLE_QUOTE] = 39,
    [SLASH] = '/',
    [STAR] = '*',
};

_Static_assert (sizeof(symbols) / sizeof(char) == __SYM_COUNT, "Mismatch in symbol enum and representation");

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
    ['?'] = QUESTION,
    ['>'] = RA,
    ['}'] = RB,
    [')'] = RP,
    [']'] = RS,
    [';'] = SEMICOLON,
    [39] = SINGLE_QUOTE,
    ['/'] = SLASH,
    ['*'] = STAR,

};

char opvalue(unsigned int i) { return symbols[i]; }

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
