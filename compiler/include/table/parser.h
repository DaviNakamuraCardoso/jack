/**
*
*       Header for the table parser
*
*/


// Get a variable in VM Code
static char* get_vm_name(KIND kind);
void get_variable(CODE* c, char* varname, char* buffer);

//

unsigned int get_classname(CODE* c, char* varname, char* buffer);





// Starts and finishes a scope
void init_subroutine_specifics(CODE* c, __F_TYPE t);
void init_scope(CODE* c);
void update_table(CODE* c, char* classname, KIND k, TYPE t);
void exit_scope(CODE* c);
void init_method_decs(CODE* c, __F_TYPE t); 
