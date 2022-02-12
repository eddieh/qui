#include "view.h"
#include "window.h"

#include <string.h>

struct QuView {
    QuWindow *window;
    QuView *parent;
    QuList *children;
    void (*drawf)(QuContext *, QuRect);
    QuRect frame;
    QuRect bounds;
};

QuView *QuViewA()
{
    QuView *view = malloc(sizeof(QuView));
    memset(view, 0, sizeof(QuView));
    view->frame = QuRectZero;
    view->bounds = QuRectZero;
    return view;
}

void view_draw_func(QuView *v,
    void (*df)(QuContext *, QuRect))
{
    v->drawf = df;
}

void view_draw(QuView *v, QuContext *c, QuRect dirty)
{
    if (v->drawf)
        v->drawf(c, dirty);
}

QuPoint view_position(QuView *v)
{
    QuRect frame = view_frame(v);
    return QuPointS(frame.origin.x, frame.origin.y);
}

void view_set_position(QuView *v, QuPoint pos)
{
    QuRect frame = view_frame(v);
    frame.origin.x = pos.x;
    frame.origin.y = pos.y;
    view_set_frame(v, frame);
}

QuSize view_size(QuView *v)
{
    QuRect frame = view_frame(v);
    return QuSizeS(frame.size.width, frame.size.height);
}

void view_set_size(QuView *v, QuSize s)
{
    QuRect frame = view_frame(v);
    frame.size.width = s.width;
    frame.size.height = s.height;
    view_set_frame(v, frame);
}

QuRect view_frame(QuView *v)
{
    return v->frame;
}

void view_set_frame(QuView *v, QuRect frame)
{
    v->frame = frame;
    v->bounds = QuRectS(0, 0, frame.size.width, frame.size.height);
}

QuRect view_bounds(QuView *v)
{
    return v->bounds;
}
