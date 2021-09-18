#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

unsigned int iscmd(char c)
{
    switch (c)
    {
        case '.':
        case '_': 
        case '-': return 1;
        default: return isalnum(c);
    }
}

unsigned int isnullchar(char c)
{
    return (c < 32);
}

unsigned int isnumeral(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i])) return 0;
    }

    return 1; 
}

unsigned int islabel(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!iscmd(str[i])) return 0;
    
    return 1; 
}

unsigned int isdir(const char* filename)
{
    DIR* d = opendir(filename);
    unsigned int status = d != NULL;
    if (status) closedir(d);

    return status;
}


unsigned int isvmsource(char* filename)
{
    return strstr(filename, ".vm") != NULL;
}
unsigned int issym(char c)
{
    switch (c)
    {
        case '/':
        case '*': 
            return 1; 
        default: 
            return 0;
    }
}

unsigned int isvalidsym(char c, char* syms, int i)
{
    // No symbol with more than 2 characters
    if (i >= 2) return 0; 

    // For now, there is no symbol starting with a character other than '/'
    if (*syms != '/') return 0;

    // The last symbol must be either '*' or '/'
    return issym(c);
}


unsigned int iscommentstart(char* buff)
{
    if (*buff != '/') return 0; 

    return issym(*buff);
}

void skipmultlnc(FILE* stream)
{
    char c, buff[2] = {0};

    do {
        buff[0] = c;
        c = fgetc(stream);
        if (c == EOF) return;
        buff[1] = c;
        
    } while (buff[0] != '*' || buff[1] != '/'); 
    
    return;
}

unsigned int ismultlnc(char *buff)
{
    return buff[1] == '*';
}

void skipc(FILE* stream, char* buff)
{
    char c;
    if (ismultlnc(buff)) 
    {
        skipmultlnc(stream); return; 
    }

    do {
        c = fgetc(stream);
    } while (c != '\n');
    
    return;
}

void get_pathname(char* buffer, char* dirname, char* filename)
{
    strcpy(buffer, dirname); 
    strcat(buffer, filename);
}


void get_dirname(char* buffer, const char* dir) 
{
    short index = strlen(dir) - 1;
    strcpy(buffer, dir);

    if (dir[index] != '/')
    {
        buffer[index+1] = '/'; buffer[index+2] = '\0';
    }

    return;
}


