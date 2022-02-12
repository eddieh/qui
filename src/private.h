#ifndef PRIVATE_H
#define PRIVATE_H

struct QuViewPrivate {
    QuWindow *window;
    QuView *parent;
    QuList *children;
    void (*drawf)(QuContext *, QuRect);
    QuRect frame;
    QuRect bounds;
};

typedef struct QuViewPrivate QuViewPrivate;

#define private_view(x) ((QuViewPrivate *)x)

#endif /* PRIVATE_H */
