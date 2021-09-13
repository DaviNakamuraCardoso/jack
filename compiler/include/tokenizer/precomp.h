/*
*       Header files for the precomp module
*/

char* handle_whitespaces(char* text);

char* handle_inline_comments(char* text);

char* handle_multiple_line_comments(char* text);

char* clean_source(char* source); 

char* precompile(char* filename);
