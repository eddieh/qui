#include "qui.h"

void draw(QuWindow * win, QuContext *ctx)
{
    QuRect b1 = QuRectS(42, 42, 100, 100);
    QuRect b2 = QuRectS(142, 42, 100, 100);

    fill_color(ctx, QuRGBA_White);
    stroke_color(ctx, QuRGBA_Black);
    line_width(ctx, 4);

    QuPath *p1 = QuPathA();
    path_add_rect(p1, b1);
    path_add_rect(p1, b2);
    path_close(p1);

    fill_path(ctx, p1);
    stroke_path(ctx, p1);

    fill_color(ctx, QuRGBA_Black);
    QuPath *ps = QuPathA();
    QuPoint pm = QuPointS(qu_midx(b2), qu_midy(b2));
    path_add_arc(ps, pm, 12, 0, 2 * 3.14159, 0);
    fill_path(ctx, ps);

    QuPath *pl = QuPathA();
    QuPoint ple = QuPointS(pm.x + 100, pm.y);
    path_move_to(pl, pm);
    path_line_to(pl, ple);
    stroke_path(ctx, pl);

    QuPath *pe = QuPathA();
    path_move_to(pe, ple);
    path_line_to(pe, QuPointS(ple.x, ple.y + 12));
    path_line_to(pe, QuPointS(ple.x + 16, ple.y));
    path_line_to(pe, QuPointS(ple.x, ple.y - 12));
    path_line_to(pe, ple);
    path_close(pe);
    fill_path(ctx, pe);
}

void app_init_cb(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_draw_func(win, draw);
    window_show(win);
}

int main(int argc, char **argv)
{
    return qu_main(argc, argv, app_init_cb);
}
