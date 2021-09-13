/**
*       Source code for the Davi Compiler Collection (DCC)
*       (c) 2021 Davi Nakamura Cardoso
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/analyzer.h>

int main(int argc, char* argv[])
{
    if (argc != 2) return 1;
    analyze(argv[1]);
    return 0;
}
