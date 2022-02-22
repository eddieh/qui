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
    void (*df)(QuView *, QuContext *))
{
    v->drawf = df;
}

void view_draw(QuView *v, QuContext *c)
{
    size_t svcount;
    QuView *cv;

    if (v->drawf)
        v->drawf(v, c);

    svcount = list_count(v->children);
    for (size_t i = 0; i < svcount; i++) {
        cv = list_at(v->children, i);
        _QuContext_set_current_view(c, cv);
        view_draw(cv, c);
        _QuContext_set_current_view(c, NULL);
    }
}

void view_redraw(QuView *v)
{
    window_redraw(v->window);
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

int is_point_in_view(QuPoint p, QuView *v)
{
    QuRect f;
    f = view_rect_in_window_coords(v, view_bounds(v));
    return is_point_in_rect(p, f);
}

QuRect view_rect_in_window_coords(QuView *v, QuRect r)
{
    QuPoint d;
    QuViewPrivate *cv;

    d = QuPointZero;
    cv = private_view(v);
    d.x += cv->frame.origin.x;
    d.y += cv->frame.origin.y;

    while ((cv = cv->parent)) {
        d.x += cv->frame.origin.x;
        d.y += cv->frame.origin.y;
    }

    return QuRectS(r.origin.x + d.x,
        r.origin.y + d.y,
        r.size.width,
        r.size.height);
}

void view_set_event_func(QuView *v, int et,
    void (*ef)(QuView *, QuEvent))
{
    assert(et >= 0);
    assert(et <= 4);

    v->ev_table[et] = ef;
}

void view_remove_event_func(QuView *v, int et)
{
    assert(et >= 0);
    assert(et <= 4);

    v->ev_table[et] = NULL;
}

QuView *view_hit_test(QuView *v, QuPoint p)
{
    size_t svcount;
    QuView *cv, *deepest;

    deepest = v;
    svcount = list_count(v->children);
    for (size_t i = 0; i < svcount; i++) {
        cv = list_at(v->children, i);
        if (is_point_in_view(p, cv)) {
            deepest = view_hit_test(cv, p);
        }
    }

    return deepest;
}

void view_send_event(QuView *v, QuEvent e)
{
    assert(e.type >= 0);
    assert(e.type <= 4);

    if (v->ev_table[e.type])
        v->ev_table[e.type](v, e);
    else if (v->parent)
        view_send_event(v->parent, e);
    else if (v->window)
        _window_send_event(v->window, e);
}
