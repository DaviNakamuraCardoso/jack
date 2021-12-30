#include <ascii.h>

unsigned int isvariable(char c)
{
    return isalnum(c) || c == '_';
}

char chars[] = {
    ['0'] = 0, 
    ['a'] = '\a',
    ['n'] = '\n',
    ['r'] = '\r',
    ['t'] = '\t',
    ['b'] = '\b',
    ['\\'] = '\\',

};

char getesc(char c)
{
    return chars[(unsigned int) c];
}


