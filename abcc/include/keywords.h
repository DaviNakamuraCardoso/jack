#ifndef __KEYWORDS_H
#define __KEYWORDS_H

typedef enum keyword {
    __NOT_KEYWORD = 0,
    BREAK,
    CASE,
    CHAR,
    CONTINUE,
    DEFAULT,
    DO,
    DOUBLE,
    ELSE,
    ENUM,
    FLOAT,
    FOR,
    GOTO,
    IF,
    INLINE,
    INT,
    LONG,
    RETURN,
    STATIC,
    STRUCT,
    SWITCH,
    TYPEDEF,
    UNION,
    UNSIGNED,
    VOID,
    WHILE,
    __KEYWORD_COUNT,
    
} keyword_e; 

keyword_e get_keyword(char*); 

#endif
