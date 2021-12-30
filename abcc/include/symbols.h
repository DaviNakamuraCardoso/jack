#ifndef __SYMBOLS_H
#define __SYMBOLS_H

typedef enum {
    __INVALID, 
    AMPERSAND,
    COLON,
    COMMA,
    DASH,
    DOUBLE_QUOTE, 
    DOT,
    EQUAL,
    EXCLAMATION,
    HASH,
    LA,
    LB,
    LP, 
    LS,
    PERCENT,
    PIPE,
    PLUS,
    QUESTION,
    RA,
    RB,
    RP,
    RS,
    SEMICOLON,
    SINGLE_QUOTE, 
    SLASH,
    STAR,
    __SYM_COUNT,
} symbol_e;

void* sgetall(void);
unsigned int opindex(char);

#endif
