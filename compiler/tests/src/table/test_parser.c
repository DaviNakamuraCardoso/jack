/**
*
*       Test the parser module for tables
*       (c) 2021 Davi Nakamura Cardoso
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <compengine/compile.h>
#include <compengine/structure.h>
#include <table/parser.h>
#include <utils/tests.h>
#include <utils/tabletests.h>

static unsigned int test_vm_code(void)
{

    return 1;
}

static unsigned int test_symbol_table(void)
{
    __VARIABLE* variable1[] = {
            new_variable("high", NULL,FIELD, INT),
            new_variable("on", NULL, FIELD, INT),
            new_variable("the", NULL, FIELD, INT),
            new_variable("list", NULL, FIELD, INT),
            NULL
    };

    __VARIABLE* variable2[] = {
            new_variable("carolina", "Queen", STATIC, CLASSNAME),
            new_variable("four", "Queen", STATIC, CLASSNAME),
            NULL
    };

    __VARIABLE** variables[] = {
            variable1, variable2
    };


    return test_symbols("table/tabletests", variables, 2, compile_classvardec);
}

static unsigned int test_local_sytable(void)
{
   __VARIABLE* vars1[] = {
           new_variable("fine", NULL, LOCAL, BOOLEAN),
           NULL
   };

   __VARIABLE** variables[] = {
           vars1
   };

   return test_symbols("table/locals", variables, 1, compile_vardec);
}

static unsigned int test_parameter_stable(void)
{
    __VARIABLE* vars1[] = {
        new_variable("a", NULL, ARGUMENT, INT),
        NULL
    };

    __VARIABLE** variables[] = {
            vars1
    };

    return test_symbols("table/parameters", variables, 1, compile_parameterlist);

}

static unsigned int test_scope_creation(void)
{
    __VARIABLE* vars1[] = {
        NULL
    };

    __VARIABLE* vars2[] = {
        NULL
    };

    __VARIABLE** variables[] = {
        vars1, vars2
    };



    return test_symbols("table/scopes", variables, 2, compile_function_predec);
}

static unsigned int test_parameterlist_scopes(void)
{
    __VARIABLE* vars1[] = {
        new_variable("a", "XSquarePlus7XPlus2MinusElevenThirds", ARGUMENT, INT),
        NULL
    };

    __VARIABLE* vars2[] = {
        new_variable("a", NULL, ARGUMENT, INT),
        new_variable("b", NULL, ARGUMENT, INT),
        new_variable("c", NULL, ARGUMENT, INT),
        NULL
    };

    __VARIABLE** vars[] = {
        vars1, vars2
    };

    return test_symbols("table/parameterlist", vars, 2, compile_parameterlist);
}


unsigned int test_tableparser(void)
{
    unsigned int (*tests[]) (void) = {
        test_vm_code,
        test_symbol_table,
        test_local_sytable,
        test_scope_creation,
        test_parameterlist_scopes
    };

    return test(tests, 5);
}
