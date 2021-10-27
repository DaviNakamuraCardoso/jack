#include <stdlib/array.h>
#include <stdlib.h>


void std_array(Program* p, unsigned short nargs)
{
    unsigned long length;
    long* array;

    if (nargs == 1)
    {
        length = popv(p);
        array = calloc(sizeof(long) + 1, length);
        array[0] = length;
        pushv(p, array + 1); return;
    }

    length = nargs + 1;
    array = calloc(sizeof(long), length);
    array[0] = nargs;
    
    for (int i = 0; i < nargs; i++) 
    {
        array[nargs-i] = popv(p);
    }

    pushv(p, array + 1);

    return;
}

void std_array_length(Program* p, unsigned short nargs)
{
    long* array = popv(p);
    pushv(p, array[-1]);
}

void std_array_tos(Program* p, unsigned short nargs)
{
    long* array = popv(p);
    char buff[1000], tmp[300];

    buff[0] = '[';
    buff[1] = '\0';

    for (int i = 0; i < array[-1]; i++)
    {
        sprintf(tmp, "%i", array[i]);
        strcat(buff, tmp);
        if (i != array[-1]-1) strcat(buff, ",");
    }

    strcat(buff, "]");

    pushv(p, tojackstr(buff));

}


// Creates an array full of the same elements
void std_full_array(Program* p, unsigned short nargs)
{
    long element = popv(p), length = popv(p);
    long* array = calloc(sizeof(long), length+1);
    array[0] = length;
    for (int i = 1; i < length+1; i++) { array[i] = element; }

    pushv(p, array + 1); return;
} 

void std_array_count(Program* p, unsigned short nargs)
{
    long step = popv(p), end = popv(p), start = popv(p), needle = popv(p), *array = popv(p), count = 0;

    for (int i = start; i < end; i += step)
    {
        if (array[i] == needle) count++; 
    } 
    pushv(p, count);
}

long compare(const void* a, const void* b)
{
    long na = *(long*) a, nb = *(long*)b;
    return na-nb;
}

void std_array_sort(Program* p, unsigned short nargs)
{
    long* array = popv(p);
    qsort(array, array[-1], sizeof(long), compare);
    pushv(p, 0); 
}

void std_array_dispose(Program* p, unsigned short nargs)
{
    long* array = popv(p);
    free(array-1);
    pushv(p, 0);
}
