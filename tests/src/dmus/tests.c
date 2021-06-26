/**
*
*
*       Main file for the test suite
*
*/

#include <stdio.h>
#include <dmus/tests.h>
#include <tests/tests.h>
#include <tests/error.h>


int main(int argc, const char* args[])
{
    unsigned int status = testall();

    if (!status) printf("All tests passed.\n");

    return status;
}

static unsigned int testall(void)
{
    return 0;
}
