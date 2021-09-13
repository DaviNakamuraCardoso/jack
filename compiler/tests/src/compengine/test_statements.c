/*
*      Test for the statements module from the Davi Compiler Collection (DCC)
*      (c) 2021 Davi Nakamura Cardoso
*
*/

#include <stdio.h>
#include <tokenizer/reader.h>
#include <tokenizer/tokens.h>
#include <compengine/compile.h>
#include <compengine/statements.h>
#include <utils/tests.h>
#include <utils/comptests.h>


unsigned int test_return(void)
{
    return generic_compare("return", compile_return, 1);
}


unsigned int test_while(void)
{
    return generic_compare("while", compile_while, 1);
}

unsigned int test_compile_statements(void)
{
    return generic_compare("statements", compile_statements, 4);

}

unsigned test_if_statement(void)
{
    return generic_compare("if", compile_if, 3);
}

unsigned int test_let_statement(void)
{
    return generic_compare("let", compile_let, 1);
}

unsigned int test_do_statement(void)
{
    return generic_compare("do", compile_do, 2);
}

unsigned int test_statements(void)
{

    unsigned int (*tests[]) (void) = {
        test_while,
        test_compile_statements,
        test_if_statement,
        test_return,
        test_let_statement,
        test_do_statement
    };


    return test(tests, 6);
}
