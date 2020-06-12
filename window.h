#ifndef WINDOW_H
#define WINDOW_H

#include "list.h"

struct window;

struct window *window_new();

void window_show(struct window *win);
void window_close(struct window *win);

#endif /* WINDOW_H */
