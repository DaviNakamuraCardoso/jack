/**
*   Cleaner module from the compile tokenizer
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <tokenizer/reader.h>


FILE* openfile(char* filename)
{
    FILE* f;
    f = fopen(filename, "r");

    if (f == NULL) {
        printf("Given file '%s' does not exist.\n", filename);
        exit(1);
    }

    return f;
}

int file_size(char* filename)
{
    int counter;
    FILE* f;

    f = openfile(filename);

    for (counter = 0; fgetc(f) != EOF; counter++) {}

    fclose(f);

    return counter;
}


char* get_file(char* filename)
{
    int size;
    FILE* f;
    char* buff;

    f = openfile(filename);
    size = file_size(filename);

    buff = malloc((size+1)* sizeof(char));

    read(fileno(f), buff, size);

    buff[size] = '\0';
    fclose(f);

    return buff;
}
