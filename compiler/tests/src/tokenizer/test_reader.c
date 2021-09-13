/**
* Test the cleaner module from the compile tokenizer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <tokenizer/reader.h>

unsigned int test_file_size(void)
{
    int size, i, out;
    char* filenames[] = {
        "files/tokenizer/01.txt",
        "files/tokenizer/02.txt"
    };

    int expected[] = {
        21,
        0
    };

    size = 2;

    for (i = 0; i < size; i++)
    {

        out = file_size(filenames[i]);
        if (out != expected[i])
        {
            printf("Error in comparison %i.\n", i);
            printf("Result: %i\n", out);
            printf("Expected: %i\n", expected[i]);
            return 0;
        }
    }


    return 1;
}

unsigned int test_get_file(void)
{
    int size, i;
    char* result;

    char* files[] = {
        "files/tokenizer/01.txt",
        "files/tokenizer/02.txt"
    };

    char* expected[] = {
        "This is a text file.\n",
        ""
    };

    size = 2;
    for (i = 0; i < size; i++)
    {
        result = get_file(files[i]);

        if (strcmp(result, expected[i]) != 0)
        {
            printf("Error reading file %i.\n", i);
            printf("Output: %s\n", result);
            printf("Expected: %s\n", expected[i]);
            free(result);
            return 0;
        }

        free(result);
    }

    return 1;
}


unsigned int test_reader(void)
{
    int i, size;

    unsigned int (*tests[]) (void) = {
        test_file_size,
        test_get_file
    };

    size = 2;

    printf("Running reader tests.\n");
    for (i = 0; i < size; i++)
    {
        if (!tests[i]())
        {
            printf("Error in test %i\n", i);
            return 0;
        }
    }

    return 1;
}
