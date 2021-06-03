/**
*
*
*   Useful I/O functions for the test suite
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
