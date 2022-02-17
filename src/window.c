#include "list.h"
#include "window.h"
#include "event.h"

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
    char *es = event_str(e);
    fprintf(stderr, "%s %s\n", __func__, es);
    free(es);
}
