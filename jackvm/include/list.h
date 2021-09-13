#ifndef __LISTH
#define __LISTH
typedef struct _list List; 
List* new_list(void);
void addl(List* l, unsigned short t);
unsigned short getelement(List* l, unsigned long index);
unsigned short popl(List* l); 
unsigned short lasttolast(List* l); 
unsigned long listlength(List* l); 
unsigned short* lcontents(List* l); 
unsigned short lastel(List* l); 
#endif
