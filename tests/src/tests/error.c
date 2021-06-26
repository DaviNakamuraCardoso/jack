/**
*
*       Test the error module
*
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <tests/tests.h>
#include <tools/error.h>

static unsigned int test_basic_error(void)
{
    pid_t pid;
    int fd[2];
    char line[300], *ret;

    if (pipe(fd) == -1)
    {
        fprintf(stderr, "Could not open pipe\n");
        return 0;
    }

    pid = fork();

    if (!pid)
    {
        // Set the STDERR for the pipe output
        dup2(fd[1], 2);
        close(fd[0]);
        fprintf(stderr, "Hello");
        exit(1);
    }

    dup2(fd[0], 0);
    close(fd[1]);

    ret = fgets(line, 300, stdin);

    if (ret == NULL) return 1;


    return strcmp(line, "Hello");
}


unsigned int test_error(void)
{
    unsigned int (*tests[]) (void) = {
        test_basic_error,
        NULL
    };
    return run(tests);
}
