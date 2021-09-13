#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib/string.h>
#include <stdlib/stdio.h>


static void printjackstr(long* obj, long *values)
{
    char* str = obj[0];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '%')
        {
            switch(str[++i]) {
                case 'd':
                case 'i':
                {
                    printf("%i", values[j++]); break;
                }
                case 's':
                {
                    char** strptr = values[j++];
                    printf((char**)strptr[0]); break;
                } 
            }
        } else if (str[i] == '\\') {
            switch (str[++i]) {
                case 'r': 
                case 'n': { putc(10, stdout); break; } 
                case 't': { putc('\t', stdout); break; }
                case '"': { putc('"', stdout); break; }
            }
        } else  {
            putc(str[i], stdout);
        }
    }

}

void std_putc(Program* p, unsigned short nargs)
{
    if (nargs == 1)
    {
        putc(popv(p), stdout);
    }
    else 
    {
        putc(popv(p), popv(p));
    }

    pushv(p, 0);

    return; 
}

void std_getstring(Program* p, unsigned short nargs)
{
    unsigned long maxlen = 32;
    long* o = popv(p), *ret = newjackstr(maxlen);    
    char* nwln, *string = (char*) ret[0];


    printjackstr(o, NULL);

    fgets(string, 32, stdin);

    nwln = strchr(string, '\n'); *nwln = '\0';

    pushv(p, ret);

    return;
}


void std_printf(Program* p, unsigned short nargs)
{
    long values[nargs-1], *strobj;

    for (int i = 0; i < nargs-1; i++)
    {
        values[nargs-2-i] = popv(p);
    }

    strobj = popv(p);

    printjackstr(strobj, values);
    

    pushv(p, 0);
}


