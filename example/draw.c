#include "qui.h"

void draw(QuContext *ctx, QuRect dirty)
{
    QuRect box = QuRectS(42, 42, 200, 100);

    fill_color(ctx, rgba(1, 0, 0, 1));
    fill_rect(ctx, box);
    stroke_color(ctx, rgba(0, 0, 0, 1));
    stroke_rect(ctx, box);
}

int app_init_cb(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_draw_func(win, draw);
    window_show(win);
    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, app_init_cb);
}
