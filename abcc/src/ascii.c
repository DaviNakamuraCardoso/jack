#include <ascii.h>

unsigned int isvariable(char c)
{
    return isalnum(c) || c == '_';
}
