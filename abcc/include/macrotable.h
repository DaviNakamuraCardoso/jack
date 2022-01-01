#ifndef __MACROTABLE_H
#define __MACROTABLE_H

typedef struct mtable mtable_t;

mtable_t*   mtnew(void);
size_t      mtset(mtable_t*, char*, size_t);
size_t      mtget(mtable_t*, char*);


#endif
