#ifndef WINDOW_H
#define WINDOW_H

#include "context.h"
#include "rect.h"

typedef struct QuWindow QuWindow;

QuWindow *window_new();

void window_show(QuWindow *win);
void window_close(QuWindow *win);

void window_draw_func(QuWindow *win,
    void (*df)(QuContext *ctx, QuRect));

QuRGBA window_background_color(QuWindow *win);
void window_set_background_color(QuWindow *win, QuRGBA c);

QuPoint window_position(QuWindow *win);
void window_set_position(QuWindow *win, QuPoint pos);

QuSize window_size(QuWindow *win);
void window_set_size(QuWindow *win, QuSize size);

QuRect window_frame(QuWindow *win);
void window_set_frame(QuWindow *win, QuRect frame);

int window_resizable(QuWindow *win);
void window_set_resizable(int resizable);

void window_center(QuWindow *win);

#endif /* WINDOW_H */
