/*
        Error module for the Diamond City Music Player (DMus)
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>


static char* formats(char* string, va_list args)
{
    char buff[300], format[100], p[3];

    p[0] = '%';
    p[2] = '\0';

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '%')
        {
            p[1] = string[i+1];

            if (string[i] == 'v') sprintf(format, p, va_arg(args, char*));
            else sprintf(format, p, va_arg(args, int));

            buff[i] = '\0';
            strcat(buff, format);
            i += strlen(format);
            continue;
        }
        buff[i] = string[i];
    }
    va_end(args);
    return "Hello";
}

void error(char* msg)
{
    return;
}
