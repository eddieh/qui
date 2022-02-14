#include "qui.h"

QuWindow *win;
QuView *subview, *sv1, *sv2;

void draw(QuContext *ctx, QuRect dirty)
{
    QuRect bounds;

    bounds = view_bounds(subview);

    fill_color(ctx, rgba(1, 0, 0, 1));
    fill_rect(ctx, bounds);
    stroke_color(ctx, rgba(0, 0, 0, 1));
    stroke_rect(ctx, bounds);
}

void drawsv(QuContext *ctx, QuRect dirty)
{
    QuRect bounds;

    bounds = view_bounds(sv1);

    fill_color(ctx, QuRGBA_Blue);
    fill_rect(ctx, bounds);
    stroke_color(ctx, QuRGBA_White);
    stroke_rect(ctx, bounds);
}

int init(QuApp *app)
{
    win = QuWindowA();
    window_set_frame(win, QuRectS(0, 0, 320, 360));
    window_center(win);

    subview = QuViewA();
    view_set_frame(subview, QuRectS(42, 42, 236, 276));
    view_draw_func(subview, draw);
    window_add_subview(win, subview);

    sv1 = QuViewA();
    view_set_frame(sv1, QuRectS(12, 12, 212, 24));
    view_draw_func(sv1, drawsv);
    view_add_subview(subview, sv1);

    sv2 = QuViewA();
    view_set_frame(sv2, QuRectS(12, 48, 212, 24));
    view_draw_func(sv2, drawsv);
    view_add_subview(subview, sv2);

    window_show(win);

    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, init);
}
