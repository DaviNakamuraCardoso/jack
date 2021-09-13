/**
*
*       Generates code for assignments
*
*/


void write_pop(CODE* c, char* varname);
void write_push(CODE* c, char* varname);
void write_intconstant(CODE* c, char* constant);
void write_stringliteral(CODE* c, char* str);
void write_keyconstant(CODE* c, char* key);
void write_poptemp(CODE* c, int n);
void write_pushtemp(CODE* c, int n);
void write_op(CODE* c, int* operators, int sp);
void write_unaryop(CODE* c, int uop); 
