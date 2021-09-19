#include "../vm.h"
#include "../cmds/push.h"
#include "../cmds/pop.h"
#include "string.h"

#ifndef __JACKSTDIOH
#define __JACKSTDIOH

void std_printf(Program* p, unsigned short nargs);
void std_putc(Program* p, unsigned short nargs); 
void std_getstring(Program* p, unsigned short nargs); 
void std_open(Program* p, unsigned short nargs);
void std_close(Program* p, unsigned short nargs);
void std_file_print(Program* p, unsigned short nargs);

#endif 
