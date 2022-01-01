#ifndef __SKIPH
#define __SKIPH

#include "tokens.h"

int skipblank(FILE*);
token_t* skipspace(FILE*);
void* skipmc(FILE*);
void* skipic(FILE*);


#endif
