#ifndef __KEYWORDS_H
#define __KEYWORDS_H

typedef enum keyword {
    BREAK,
    CASE,
    CHAR,
    CONTINUE,
    DO,
    ELSE,
    ENUM,
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
    __KEYOWRD_COUNT,
    __NOT_KEYWORD = 0,
    
} keyword_e; 

keyword_e get_keyword(char*); 

#endif
