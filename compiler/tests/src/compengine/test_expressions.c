/**
*
*       Test the expression parsing module
*       (c) 2021 Davi Nakamura Cardoso
*/

#include <stdio.h>
#include <stdlib.h>
#include <tokenizer/reader.h>
#include <tokenizer/tokens.h>
#include <compengine/compile.h>
#include <compengine/expressions.h>
#include <utils/tests.h>
#include <utils/comptests.h>

static unsigned int test_compile_expressions(void)
{
    return generic_compare("expression", compile_expression, 8);
}


static unsigned int test_compile_keywordconstant(void)
{
    return generic_compare("keywordconstant", compile_keywordconstant, 3);
}

static unsigned int test_compile_unaryop(void)
{
    return generic_compare("unaryop", compile_unaryop, 3);
}

static unsigned int test_compile_op(void)
{
    return generic_compare("op", compile_op, 3);
}

static unsigned int test_compile_expressionlist(void)
{
    return generic_compare("expressionlist", compile_expressionlist, 3);
}

static unsigned int test_compile_inbraces(void)
{
    return generic_compare("inbraces", compile_inbraces, 2);
}

static unsigned int test_compile_subroutinecall(void)
{
    return generic_compare("subroutinecall", compile_subroutinecall, 1);
}

static unsigned int test_compile_arrayaccess(void)
{
    return generic_compare("arrayaccess", compile_arrayaccess, 2);
}

unsigned int test_expressions(void)
{
    unsigned int (*tests[]) (void) = {
        test_compile_expressions,
        test_compile_keywordconstant,
        test_compile_unaryop,
        test_compile_op,
        test_compile_expressionlist,
        test_compile_inbraces,
        test_compile_arrayaccess

    };

    return test(tests, 7);
}
