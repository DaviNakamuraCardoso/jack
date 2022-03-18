#ifndef __TOKENSH
#define __TOKENSH

#include "ascii.h"
#include "source.h"
#include "symbols.h"
#include "operators.h"

typedef struct token token_t;

typedef enum tokentype {
    IDENTIFIER,
    KEYWORD,
    NEWLINE,
    NUM_LIT,
    OPERATOR,
    STR_LIT,
    SYMBOL
} type_e;

enum tokentype tktype(token_t*);
void* tkvalue(token_t*);
size_t tkloc(token_t*);

token_t *get_number_token       (source_t*);
token_t *get_identifier_token   (source_t*); 
token_t *get_literal_token      (source_t*);
token_t *get_symbol_token       (source_t*, symbol_e);
token_t *get_operator_token     (source_t*, operator_e);
token_t *fnewlinet(FILE*);

#endif 
