/*
*   Test suite for the Davi Compiler Collection (DCC)
*   (c) 2021 Davi Nakamura Cardoso
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tests.h>


int main(void)
{
    char buff[200];
    int test_num, i;

    printf("Starting tests...\n");

    unsigned int (*tests[]) (void) = {
        test_compilation,
        test_precomp,
        test_reader,
        test_memory_leaks,
        test_tokens,
        test_cleaner,
        test_parser,
        test_compparser,
        test_compile,
        test_statements,
        test_expressions,
        test_structure,
        test_analyzer,
        test_table,
        test_tableparser,
        test_loops,
        test_tracker,
        test_writer,
        test_assignments,
        test_functions
    };

    test_num = 20;

    for (i = 0; i < test_num; i++)
    {
        printf("Testing %i..\n", i);
        if (!tests[i]())
        {
            printf("Fail on test %i\n", i);
            return 1;
        }
    }

    printf("All tests passed.\n");


    return 0;
}

unsigned int test_compilation(void)
{
    char buff[200], *program_name;
    int status;

    program_name = "dcc";

    sprintf(buff, "cd .. && make \"%s\"", program_name);

    status = system(buff);

    return (status == 0);
}

unsigned int test_memory_leaks(void)
{
    int status;
    char buff[200], *program_name;
    program_name = "./dcc";

    sprintf(buff, "cd .. && valgrind \"%s\" example", program_name);

    status = system(buff);

    return (status == 0);
}
