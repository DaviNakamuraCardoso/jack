/** Header for the tokenizer module **/

#define MAX_ASCII 177

typedef enum {

    IMPLEMENTED_SYMBOL,
    KEYWORD,
    STRING_LITERAL,
    NUMBER_CONSTANT,
    VARIABLE,
    INVALID

} TOKEN_TYPE;

typedef struct _symbol
{
    unsigned int exists:1;
    struct _symbol *next[MAX_ASCII];
    TOKEN_TYPE type;
} SYMBOL;

SYMBOL* new_symbol(void);

void release_symbol(SYMBOL** root);

void add_symbol(SYMBOL* root, char* key, TOKEN_TYPE type);

unsigned int search_symbol(SYMBOL* root, char* key);

TOKEN_TYPE get_token_type(SYMBOL* root, char* key);

unsigned int search_one_char(SYMBOL* root, char* key);

void add_syntax(SYMBOL* root); 
void add_symbols(SYMBOL* root);
