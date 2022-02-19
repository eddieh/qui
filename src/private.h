#ifndef PRIVATE_H
#define PRIVATE_H

#include "list.h"

struct QuViewPrivate {
    QuWindow *window;
    QuView *parent;
    QuList *children;
    void (*drawf)(QuContext *, QuRect);
    QuRect frame;
    QuRect bounds;
    void (*ev_table[4])(QuView *, QuEvent);
};

typedef struct QuViewPrivate QuViewPrivate;

#define private_view(x) ((QuViewPrivate *)x)

void _QuContext_set_current_view(QuContext *ctx, QuView *cv);

#endif /* PRIVATE_H */
