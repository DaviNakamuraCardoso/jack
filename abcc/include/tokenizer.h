#ifndef __TOKENIZERH
#define __TOKENIZERH

#define BUFF_MAX 1000

#include "source.h"
#include "tokens.h"
#include "ascii.h" 
#include "operators.h"


token_t** tokenize(const char* filename, FILE* f);

#endif

