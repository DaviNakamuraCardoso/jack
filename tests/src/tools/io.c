/**
*
*
*       Useful I/O functions for the test suite
*
*/

#include <stdio.h>
#include <tools/error.h>

const char* get_file(const char* filename)
{
    FILE* file;

    file = fopen(filename, "r");

    if (file == NULL) error("Given file does not exist");

    return "Hello";

}

unsigned int compare_files(const char* f1, const char* f2)
{
    unsigned int status;
    char* a, *b;

    a = get_file(f1);
    b = get_file(f2);

    status = strcmp(a, b);

    free(a); free(b);

    return status;

}
