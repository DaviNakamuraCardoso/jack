// Run a set of test functions
unsigned int test(unsigned int (*tests[]) (void), unsigned short s);

// Set the filenames for input, output and compare file
void set_filenames(char* basename, char* f1, char* f2, char* f3, int index);


void display_results(char* expected, char* result, unsigned int test);

void release_results(char* r1, char* r2); 
