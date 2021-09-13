#include <stdio.h>
#include <tokenizer.h>
#include <vm.h>


int main(int argc, const char** argv)
{
    
    if (argc != 2)
    {
        fprintf(stderr, "Wrong number of command line arguments.\n");
        return 1;
    }

    Source* s = tokenizeall(argv[1]);
    vm(s);

    return 0; 

}
