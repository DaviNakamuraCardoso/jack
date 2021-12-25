#ifndef __SYMBOLS_H
#define __SYMBOLS_H

typedef enum {
    AMPERSAND,
    COLON,
    COMMA,
    DASH,
    DOUBLE_QUOTE, 
    DOT,
    EQUAL,
    EXCLAMATION,
    HASH,
    LEFT_ANGLE,
    LEFT_BRACE,
    LEFT_PARENTHESIS, 
    LEFT_SQUARE_BRACKET,
    PERCENT,
    PIPE,
    PLUS,
    QUESTION,
    RIGHT_ANGLE,
    RIGHT_BRACE,
    RIGHT_PARENTHESIS,
    RIGHT_SQUARE_BRACKET,
    SEMICOLON,
    SINGLE_QUOTE, 
    SLASH,
    STAR,
    __SYM_COUNT,
} symbol_e;

void* sgetall(void);
unsigned int opindex(char);

#endif
