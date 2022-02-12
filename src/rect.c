#include <stdio.h>

#include "rect.h"

QuPoint QuPointZero = {
    .x = 0.0f,
    .y = 0.0f
};

QuVector QuVectorZero = {
    .dx = 0.0f,
    .dy = 0.0f
};

QuSize QuSizeZero = {
    .width = 0.0f,
    .height = 0.0f
};

QuRect QuRectZero = {
    .origin = {
        .x = 0.0f,
        .y = 0.0f
    },
    .size = {
        .width = 0.0f,
        .height = 0.0f
    }
};

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
