/*
*
*       Test the structure parser for the Davi Compiler Collection (DCC)
*       (c) 2021 Davi Nakamura Cardoso
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/compile.h>
#include <compengine/parser.h>
#include <compengine/structure.h>
#include <utils/tests.h>
#include <utils/comptests.h>

unsigned int test_compile_type(void)
{
    return generic_compare("type", compile_type, 3);
}

unsigned int test_compile_vardec(void)
{
    return generic_compare("vardec", compile_vardec, 3);
}

unsigned int test_compile_subroutinebody(void)
{
    return generic_compare("subroutinebody", compile_subroutinebody, 4);
}

unsigned int test_compile_parameterlist(void)
{
    return generic_compare("parameterlist", compile_parameterlist, 3);
}

unsigned int test_compile_subroutinedec(void)
{
    return generic_compare("subroutinedec", compile_subroutinedec, 1);
}

unsigned int test_compile_classvardec(void)
{
    return generic_compare("classvardec", compile_classvardec, 3);
}

unsigned int test_compile_class(void)
{
    return generic_compare("class", compile_class, 5);
}

unsigned int test_structure(void)
{
    unsigned int (*tests[]) (void) = {
        test_compile_type,
        test_compile_vardec,
        test_compile_subroutinebody,
        test_compile_parameterlist,
        test_compile_subroutinedec,
        test_compile_classvardec,
        test_compile_class
    };
    return test(tests, 7);
}
