/**
*       Headers for the program structure
*/



#ifndef __TYPE
#include <table/types.h>
#define __TYPE
#endif

#ifndef __KIND
#include <table/kinds.h>
#define __KIND
#endif

#include <table/parser.h>

TYPE compile_type(CODE *c, char* buffer);

void compile_vardec(CODE* c);

void compile_subroutinebody(CODE* c);

void compile_parameterlist(CODE* c);

signed int compile_function_predec(CODE* c);

void compile_subroutinedec(CODE* c);

void compile_classvardec(CODE* c);

void compile_class(CODE* c);

unsigned int compile_comma(CODE* c);
