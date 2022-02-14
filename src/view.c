#include "view.h"
#include "window.h"
#include "private.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct QuViewPrivate QuView;

QuView *QuViewA()
{
    QuView *view = malloc(sizeof(QuView));
    memset(view, 0, sizeof(QuView));
    view->frame = QuRectZero;
    view->bounds = QuRectZero;
    view->children = QuListA(1);
    return view;
}

void view_draw_func(QuView *v,
    void (*df)(QuContext *, QuRect))
{
    v->drawf = df;
}

void view_draw(QuView *v, QuContext *c, QuRect dirty)
{
    size_t svcount;
    QuView *cv;

    if (v->drawf)
        v->drawf(c, dirty);

    svcount = list_count(v->children);
    for (size_t i = 0; i < svcount; i++) {
        cv = list_at(v->children, i);
        _QuContext_set_current_view(c, cv);
        view_draw(cv, c, dirty);
        _QuContext_set_current_view(c, NULL);
    }
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

void view_add_subview(QuView *v, QuView *subview)
{
    assert(subview->window == NULL);
    assert(subview->parent == NULL);

    subview->window = v->window;
    subview->parent = v;

    list_push(v->children, subview);
}
