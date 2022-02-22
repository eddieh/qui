#ifndef PRIVATE_H
#define PRIVATE_H

#include "list.h"
#include "window.h"

struct QuViewPrivate {
    QuWindow *window;
    QuView *parent;
    QuList *children;
    QuRect frame;
    QuRect bounds;
    void (*drawf)(QuView *, QuContext *);
    void (*actionf)(QuView *, QuEvent);
    void (*ev_table[4])(QuView *, QuEvent);
    void *state;
};

typedef struct QuViewPrivate QuViewPrivate;

#define private_view(x) ((QuViewPrivate *)x)

void _QuContext_set_current_view(QuContext *ctx, QuView *cv);

QuView *window_tracking_view(QuWindow *win);
void window_set_tracking_view(QuWindow *win, QuView *view);

#endif /* PRIVATE_H */
