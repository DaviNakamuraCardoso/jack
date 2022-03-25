#ifndef __ERROR_H
#define __ERROR_H

#include <stdarg.h>

int errorat (const char*, size_t, const char*, ...);
int verrorat(const char*, size_t, const char*, va_list);

#endif

