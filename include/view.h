#ifndef VIEW_H
#define VIEW_H

#include "list.h"
#include "context.h"
#include "rect.h"

typedef struct QuViewPrivate QuView;

QuView *QuViewA();

void view_draw_func(QuView *v,
    void (*df)(QuContext *, QuRect));
void view_draw(QuView *v, QuContext *c, QuRect dirty);

QuPoint view_position(QuView *v);
void view_set_position(QuView *v, QuPoint pos);

QuSize view_size(QuView *v);
void view_set_size(QuView *v, QuSize s);

QuRect view_frame(QuView *v);
void view_set_frame(QuView *v, QuRect frame);

QuRect view_bounds(QuView *v);

void view_add_subview(QuView *v, QuView *subview);

#endif /* VIEW_H */
