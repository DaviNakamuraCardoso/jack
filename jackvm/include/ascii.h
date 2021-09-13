unsigned int isnullchar(char c);
unsigned int iscmd(char c); 
int max(int a, int b); 
unsigned int isvalidsym(char c, char* syms, int i);
unsigned int isnumeral(char* str); 
unsigned int islabel(char* str); 
unsigned int isdir(const char* filename);
unsigned int isvmsource(char* filename); 
unsigned int issym(char c); 
unsigned int iscommentstart(char* buff);
void skipc(FILE* stream, char* buff); 


