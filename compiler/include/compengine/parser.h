/*
*
*       XML Parser for the Davi Compiler Collection
*       (c) 2021 Davi Nakamura
*
*/

typedef struct _token {
    char* content;
    TOKEN_TYPE type;
} TOKEN;

TOKEN* new_token(char* value, TOKEN_TYPE type);

void release_token(TOKEN** tokenptr);

TOKEN* parse_token(char* xml);

TOKEN* get_next_token(FILE* xml);

void rollback(FILE* f);
