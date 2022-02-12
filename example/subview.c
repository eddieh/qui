#include "qui.h"

QuWindow *win;
QuView *subview;

void draw(QuContext *ctx, QuRect dirty)
{
    QuRect bounds;

    bounds = view_bounds(subview);

    fill_color(ctx, rgba(1, 0, 0, 1));
    fill_rect(ctx, bounds);
    stroke_color(ctx, rgba(0, 0, 0, 1));
    stroke_rect(ctx, bounds);
}

int init(QuApp *app)
{
    win = QuWindowA();
    window_set_frame(win, QuRectS(0, 0, 320, 360));
    window_center(win);

    subview = QuViewA();
    view_set_frame(subview, QuRectS(42, 42, 200, 100));
    view_draw_func(subview, draw);
    window_add_subview(win, subview);

    window_show(win);

    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, init);
}
