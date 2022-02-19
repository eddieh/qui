#ifndef VIEW_H
#define VIEW_H

#include "event.h"
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

int is_point_in_view(QuPoint p, QuView *v);
QuRect view_rect_in_window_coords(QuView *v, QuRect r);

void view_set_event_func(QuView *v, int et,
    void (*ef)(QuView *, QuEvent));
/* should remove with int or fp? */
void view_remove_event_func(QuView *v, int et);
QuView *view_hit_test(QuView *v, QuPoint p);
void view_send_event(QuView *v, QuEvent e);


#endif /* VIEW_H */
