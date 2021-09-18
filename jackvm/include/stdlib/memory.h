#ifndef __JACKMEMORYH
#define __JACKMEMORYH
#include "../vm.h"

void std_malloc(Program* p, unsigned short nargs);
void std_free(Program* p, unsigned short nargs); 
void std_array(Program* p, unsigned short nargs);
void std_full_array(Program* p, unsigned short nargs);
void std_array_count(Program* p, unsigned short nargs);
void std_array_dispose(Program* p, unsigned short nargs);

#endif
