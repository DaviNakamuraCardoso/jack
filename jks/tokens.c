
enum tokentype {
    KEYWORD,
    NUM_LIT,
    OPERATOR,
    STR_LIT,
    VARIABLE,
};

struct token {
    // Useful metadata
    unsigned int line, character;
    enum tokentype type;

    union {
        long val; 
        char* name;
    };
};

token_t *token_create(enum tokentype type, unsigned int ln, unsigned int chr, void* val)
{
    token_t *t = malloc(sizeof(token_t));

    t->type = type;

    // Metadata
    t->line = ln;
    t->ch   = chr;

    // Actual value
    switch (type)
    {
        case NUM_LIT:
            t->val  = *(long*) val;
            break;
        default: 
            t->name = (char*) val;
            break;
    }

    return t; 
} 

