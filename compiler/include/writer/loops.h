/**
*
*       Header for the loop writer
*
*
*/
void write_label(CODE* c, char* buffer);
void write_ifgoto(CODE* c, char* label);
void write_goto(CODE* c, char* label);
void get_label(CODE* c, char* buffer); 
