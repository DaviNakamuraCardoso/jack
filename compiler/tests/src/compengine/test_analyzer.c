/**
*
*       Test suite for the Analyzer module
*       (c) 2021 Davi Nakamura Cardoso
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/compile.h>
#include <compengine/parser.h>
#include <compengine/analyzer.h>
#include <utils/tests.h>
#include <utils/comptests.h>

unsigned int test_compile_process(void)
{
    // return analyzer_test("analyzer", compile, 2);
    return 1;
}

// Quick hack that allows me to reuse the "analyzer_test" function
void nothing(char* path)
{
    return;
}

unsigned int test_analyze(void)
{
    analyze("./files/compengine/analyze/");
    return analyzer_test("analyze", nothing, 2);
}

unsigned int test_analyzer(void)
{
    unsigned int (*tests[]) (void) = {
        test_compile_process,
        test_analyze
    };
    return test(tests, 2);
}
