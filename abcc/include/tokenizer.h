#ifndef __TOKENIZERH
#define __TOKENIZERH

#define BUFF_MAX 1000

#include "optree.h"
#include "macrotable.h"
#include "source.h"
#include "tokens.h"
#include "skip.h"
#include "ascii.h" 
#include "operators.h"
#include "error.h"


token_t** tokenize(const char*);
token_t** ftokenize(token_t**, const char*, optree_t*, mtable_t* mt);

#endif

