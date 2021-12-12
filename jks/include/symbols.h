
typedef enum {
    AMPERSAND,
    COMMA,
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

symbol_e get_symbol_type(char c);


