/*
*
*       A Collection of generic test functions
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tokenizer/reader.h>
#include <compengine/compile.h>

unsigned int test(unsigned int (*tests[]) (void), unsigned short size)
{
    unsigned short s;

    for (s = 0; s < size; s++)
    {
        if (!tests[s]())
        {
            printf("Failure in module test number %i\n", s);
            return 0;
        }
    }

    return 1;

}


void set_filenames(char* basename, char* f1, char* f2, char* f3, int index)
{
    sprintf(f1, "./files/%s/%i.xml", basename, index);
    sprintf(f2, "./files/%s/%i.out", basename, index);
    sprintf(f3, "./files/%s/%i.cmp", basename, index);

    return;
}

void release_results(char* r1, char* r2)
{
    free(r1);
    free(r2);
}

void display_results(char* expected, char* result, unsigned int test)
{
    printf("Error in test number %i\n", test);
    printf("Expected: %s\n", expected);
    printf("Result: %s\n", result);

    release_results(expected, result);
}
