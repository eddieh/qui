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

#endif /* WINDOW_H */
