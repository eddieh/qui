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

int is_point_in_rect(QuPoint p, QuRect r)
{
    if (p.x >= qu_minx(r) && p.x <= qu_maxx(r))
        return p.y >= qu_miny(r) && p.y <= qu_maxy(r);
    return 0;
}

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
