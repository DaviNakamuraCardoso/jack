
unsigned int writer_compare(char* path, unsigned int (*tested) (CODE*), unsigned int size, ...);
unsigned int writer_test(char* path, char*** words, void (*tested) (CODE*, char*), ...);
