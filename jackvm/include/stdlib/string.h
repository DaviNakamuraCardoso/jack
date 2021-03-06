#ifndef __JACKSTRH
#define __JACKSTRH

#include "../vm.h"

void std_string(Program* p, int nargs); 
void std_strlen(Program* p, int nargs);
void std_appendchar(Program* p, int nargs);

void cmdlineargs(Program* p, int argc, const char** argv);

// Empty Jack String
long *newjackstr(unsigned long maxlen);

// Convert to a Jack String
long *tojackstr(char* str);

#endif
