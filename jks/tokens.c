

enum tokentype {
    STR_LIT,
    NUM_LIT,
    VARIABLE,
    OPERATOR 
};

struct token {
    // Useful metadata
    unsigned int line, character;
    enum tokentype type;

    union {
        long lval; 
        char* lit;
        char* name;
    };
};

