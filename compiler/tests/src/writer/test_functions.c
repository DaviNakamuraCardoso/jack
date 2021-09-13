/**
*
*
*       Test the functions writer
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/compile.h>
#include <compengine/expressions.h>
#include <compengine/statements.h>
#include <compengine/structure.h>
#include <utils/tests.h>
#include <utils/writertests.h>


static unsigned int test_write_call(void)
{
    TABLE* t = new_table("Main");
    add_var(t, "a", "Paddle", LOCAL, CLASSNAME);
    add_var(t, "this", "Ball", ARGUMENT, CLASSNAME);

    return writer_compare("writer/call", compile_subroutinecall, 4, t);
}

static unsigned int test_do_calls(void)
{
    TABLE* t = new_table("Point");
    add_var(t, "this", "Point", ARGUMENT, CLASSNAME);
    add_var(t, "other", "Point", ARGUMENT, CLASSNAME);

    return writer_compare("writer/do", compile_do, 2, t);
}

static unsigned int test_write_fdec(void)
{
    TABLE* t = new_table("Point");
    add_var(t, "x", NULL, FIELD, INT);
    add_var(t, "y", NULL, FIELD, INT);

    return writer_compare("writer/constructors", compile_subroutinedec, 2, t);
}

static unsigned int test_write_methodec(void)
{

    TABLE* t = new_table("Point");
    add_var(t, "this", "Point", ARGUMENT, CLASSNAME);

    return writer_compare("writer/methods", compile_subroutinedec, 3, t);
}

static unsigned int test_write_functiondec(void)
{
    TABLE* t = new_table("StandardIO");

    return writer_compare("writer/functions", compile_subroutinedec, 1, t);

}


unsigned int test_functions(void)
{
    unsigned int (*tests[]) (void) = {
        test_write_call,
        test_do_calls,
        test_write_fdec,
        test_write_methodec,
        test_write_functiondec
    };

    return test(tests, 5);
}
