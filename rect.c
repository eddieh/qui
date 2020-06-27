#include <stdio.h>

#include "rect.h"

char *rect_str(QuRect r)
{
    char *ret;
    asprintf(&ret, "{{%f, %f}, {%f, %f}}",
        r.origin.x,
        r.origin.y,
        r.size.width,
        r.size.height);
    return ret;
}
