
#ifndef __JACKARRAYH
#define __JACKARRAYH

#include "../vm.h"
#include "../cmds/push.h"
#include "../cmds/pop.h"
#include "string.h"

void std_array(Program* p, unsigned short nargs);
void std_full_array(Program* p, unsigned short nargs);
void std_array_tos(Program *p, unsigned short nargs);
void std_array_count(Program* p, unsigned short nargs);
void std_array_dispose(Program* p, unsigned short nargs);
void std_array_length(Program* p, unsigned short nargs); 
void std_array_sort(Program* p, unsigned short nargs);
void std_array_print(Program *p, unsigned short nargs);


#endif
