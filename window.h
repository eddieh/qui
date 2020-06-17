#ifndef WINDOW_H
#define WINDOW_H

#include "context.h"
#include "rect.h"

struct window;

struct window *window_new();

void window_show(struct window *win);
void window_close(struct window *win);

void window_draw_func(struct window *win,
    void (*df)(QuContext *ctx, struct QuRect));

#endif /* WINDOW_H */
