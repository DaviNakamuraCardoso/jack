

#ifndef __VMH
#define __VMH

#include <tokens.h>
typedef struct _program {
    unsigned long *stack, *tmp, pc, sp, this, that, arguments, locals;
    unsigned short *source;
    unsigned long *labels, stdcount, entry;
    long* statics;
    unsigned int done:1;
    
} Program;


void vm(Source *s); 
unsigned short next(Program* p);
#endif 
