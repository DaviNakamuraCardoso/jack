#include <stdio.h>
#include <stdlib.h>
#include <compiler/compiler.h>

int main(int argc, const char** argv)
{
    FILE* stream = stdin;

    if (argc >= 2) stream = fopen(argv[1], "r");

    compile(stream);

    return 0;

}
