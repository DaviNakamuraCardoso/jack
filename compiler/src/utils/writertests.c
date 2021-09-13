/**
*
*
*       Generic test functions for the code writer
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <compengine/compile.h>
#include <tokenizer/reader.h>
#include <utils/tests.h>


unsigned int writer_compare(char* path, unsigned int (*tested) (CODE*), unsigned int size, ...)
{

    char input[200], output[200], compare[200], buffer[2000], *result, *expected;
    va_list va;
    FILE *source, *vm;
    CODE* c;
    TRACKER* t;

    va_start(va, size);
    TABLE* table = va_arg(va, TABLE*);
    va_end(va);

    for (int i = 0; i < size; i++)
    {
        set_filenames(path, input, output, compare, i);

        source = fopen(input, "r");
        vm = fopen(output, "w");

        c = new_code(source, NULL, vm);
        t = new_tracker();

        c->tracker = t;
        c->table = table;

        tested(c);

        c->table = NULL;
        release_code(c);
        release_tracker(t);

        result = get_file(output);
        expected = get_file(compare);

        if (strcmp(result, expected) != 0)
        {
            display_results(expected, result, i);
            return 0;
        }
        release_results(expected, result);
    }

    return 1;
}


unsigned int writer_test(char* path, char*** words, void (*tested) (CODE*, char*), ...)
{
    char filename[200], filename2[200], filename3[300], *result, *expected;
    va_list va;
    FILE* target;
    CODE* c;
    TRACKER* t;

    va_start(va, tested);
    TABLE* table = va_arg(va, TABLE*);
    va_end(va);


    for (int i = 0; words[i] != NULL; i++)
    {
        set_filenames(path, filename, filename2, filename3, i);
        c = new_code(NULL, NULL, fopen(filename2, "w"));
        t = new_tracker();

        c->tracker = t;
        c->table = table;


        for (int j = 0; words[i][j] != NULL; j++)
        {
            tested(c, words[i][j]);
        }

        release_code(c);
        release_tracker(t);

        result = get_file(filename2);
        expected = get_file(filename3);

        if (strcmp(result, expected) != 0)
        {
            display_results(expected, result, i);
            return 0;
        }

        release_results(result, expected);
    }

    return 1;
}
