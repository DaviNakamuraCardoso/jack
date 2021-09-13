#include "../vm.h"

#ifndef __JUMPSH
#define __JUMPSH
void label(Program* p);
void gotoc(Program* p);
void ifgoto(Program* p);
void function(Program* p);
void call(Program* p);
void returnc(Program* p);

#endif
