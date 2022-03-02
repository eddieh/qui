#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

void qu_die(const char *fmt, ...)
{
    va_list args;
    static char buffer[512];

    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    fprintf(stderr, "[fatal] %s\n", buffer);
    exit(1);
}
