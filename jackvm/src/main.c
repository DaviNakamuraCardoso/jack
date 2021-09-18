#include <stdio.h>
#include <tokenizer.h>
#include <vm.h>


int main(int argc, const char** argv)
{
    
    if (argc == 1)
    {
        fprintf(stderr, "Usage:\n $./jack <sourcefile.jack>\n or\n $./jack <path/to/sourcefolder>\n");
        return 1;
    }

    Source* s = tokenizeall(argv[1]);

    return vm(s, argc, argv); 

}
