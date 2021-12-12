#ifndef __TOKENSH
#define __TOKENSH

#include "symbols.h"
#include "operators.h"

typedef struct token token_t;

token_t *get_number_token(char*);
token_t *get_identifier_token(char*); 
token_t *get_literal_token(FILE*);
token_t *get_operator_token(operator_e);
token_t *skipic(FILE*);
token_t *skipmc(FILE*);


#endif 
