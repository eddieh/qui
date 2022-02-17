#ifndef WINDOW_H
#define WINDOW_H

#include "context.h"
#include "rect.h"
#include "view.h"
#include "event.h"

typedef struct QuWindow QuWindow;

QuWindow *QuWindowA();

void window_show(QuWindow *win);
void window_close(QuWindow *win);

void window_draw_func(QuWindow *win,
    void (*df)(QuContext *, QuRect));

QuRGBA window_background_color(QuWindow *win);
void window_set_background_color(QuWindow *win, QuRGBA c);

QuPoint window_position(QuWindow *win);
void window_set_position(QuWindow *win, QuPoint pos);

QuSize window_size(QuWindow *win);
void window_set_size(QuWindow *win, QuSize s);

QuRect window_frame(QuWindow *win);
void window_set_frame(QuWindow *win, QuRect frame);

int window_resizable(QuWindow *win);
void window_set_resizable(QuWindow *win, int resizable);

void window_center(QuWindow *win);

void window_add_subview(QuWindow *win, QuView *view);
size_t window_subview_count(QuWindow *win);
QuView *window_subview_at(QuWindow *win, size_t idx);

void window_send_event(QuWindow *win, QuEvent e);

#endif /* WINDOW_H */
