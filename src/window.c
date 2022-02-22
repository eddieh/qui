#include "list.h"
#include "window.h"
#include "event.h"
#include "private.h"

#include <stdio.h>
#include <stdlib.h>

QuPoint window_position(QuWindow *win)
{
    QuRect frame = window_frame(win);
    return QuPointS(frame.origin.x, frame.origin.y);
}

void window_set_position(QuWindow *win, QuPoint pos)
{
    QuRect frame = window_frame(win);
    frame.origin.x = pos.x;
    frame.origin.y = pos.y;
    window_set_frame(win, frame);
}

QuSize window_size(QuWindow *win)
{
    QuRect frame = window_frame(win);
    return QuSizeS(frame.size.width, frame.size.height);
}

void window_set_size(QuWindow *win, QuSize s)
{
    QuRect frame = window_frame(win);
    frame.size.width = s.width;
    frame.size.height = s.height;
    window_set_frame(win, frame);
}

void window_send_event(QuWindow *win, QuEvent e)
{
    QuView *target = NULL;
    /* char *es = event_str(e); */
    /* fprintf(stderr, "%s %s\n", __func__, es); */
    /* free(es); */

    switch (e.type) {
    case QuEvent_MouseDown:
        target = window_hit_test(win, e.loc);
        window_set_tracking_view(win, target);
        break;
    case QuEvent_MouseUp:
        target = window_tracking_view(win);
        window_set_tracking_view(win, NULL);
        break;
    case QuEvent_KeyDown:
    case QuEvent_KeyUp:
        target = window_focused_view(win);
        break;
    }

    if (target)
        view_send_event(target, e);
    else
        _window_send_event(win, e);
}

QuView *window_hit_test(QuWindow *win, QuPoint p)
{
    QuView *cv, *deepest;
    size_t svcount;

    cv = NULL;
    deepest = NULL;

    svcount = window_subview_count(win);
    for (size_t i = 0; i < svcount; i++) {
        cv = window_subview_at(win, i);
        if (is_point_in_view(p, cv)) {
            deepest = view_hit_test(cv, p);
        }
    }

    return deepest;
}
