
typedef enum {
    AMPERSAND,
    DASH,
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
    SLASH,
    STAR,
    ZZ_END
} symbol_e;

const char symbols[] = { 
    [AMPERSAND] = '&',
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
    [ZZ_END] = '\0',
};

operator_e get_symbol(char c)
{
    switch (c) {
        case '&': return AMPERSAND; 
        case '|': return PIPE;
        case '.': return DOT;
        case ',': return COMMA;
        case '*': return STAR;
        case '%': return HASH;
        case '!': return EXCLAMATION;
        case '/': return SLASH;
        case '-': return DASH;
        case '#': return HASH;
        case '(': return RIGHT_PARENTHESIS;
        case ')': return LEFT_PARENTHESIS;
        case '[': return LEFT_SQUARE_BRACKET;
        case ']': return RIGHT_SQUARE_BRACKET; 
        case '{': return RIGHT_BRACES; 
        case '}': return LEFT_BRACES; 

        default: return ZZ_END;
    }
}

