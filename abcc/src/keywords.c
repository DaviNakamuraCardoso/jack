#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "keywords.h"


char* keywords[] = {
    [BREAK] = "break",
    [CASE] = "case",
    [CONTINUE] = "continue",
    [CHAR] = "char",
    [DEFAULT] = "default",
    [DO] = "do",
    [DOUBLE] = "double",
    [ELSE] = "else",
    [ENUM] = "enum",
    [FLOAT] = "float",
    [FOR] = "for",
    [GOTO] = "goto",
    [IF] = "if",
    [INLINE] = "inline",
    [INT] = "int",
    [LONG] = "long",
    [RETURN] = "return",
    [STATIC] = "static",
    [STRUCT] = "struct",
    [SWITCH] = "switch",
    [TYPEDEF] = "typedef",
    [UNSIGNED] = "unsigned",
    [UNION] = "union",
    [VOID] = "void",
    [WHILE] = "while",
    [__KEYWORD_COUNT] = "",
    [__NOT_KEYWORD] = "", 
};

keyword_e get_keyword(char* name)
{
    unsigned int start = 0, end = __KEYWORD_COUNT, middle;

    while (start < end - 1)
    {
        middle = (start + end) / 2;

        long val = strcmp(name, keywords[middle]);
        printf("Val: %li, middle: %u, start: %u, end: %u\n", val, middle, start, end);
        printf("kwd: %s\n", keywords[middle]);
        if (val < 0) 
            end = middle;
        else if (val > 0) 
            start = middle;
        else return middle; 
    }

    return __NOT_KEYWORD;
}
