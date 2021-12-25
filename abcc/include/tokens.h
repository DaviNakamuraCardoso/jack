#ifndef __TOKENSH
#define __TOKENSH

#include "source.h"
#include "symbols.h"
#include "operators.h"

typedef struct token token_t;

token_t *get_number_token       (source_t*);
token_t *get_identifier_token   (source_t*); 
token_t *get_literal_token      (source_t*);
token_t *get_symbol_token       (source_t*, symbol_e);
token_t *get_operator_token     (source_t*, operator_e);

token_t *skipic(FILE*);
token_t *skipmc(FILE*); 

#endif 
