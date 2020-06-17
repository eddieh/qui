#include "qui.h"

void draw(QuContext *ctx, struct QuRect dirty)
{
    fill_color(ctx, rgba(1, 0, 0, 1));
    fill(ctx, rect(0, 0, 200, 100));
}

int app_init_cb(QuApp *app)
{
    struct window *win = window_new();
    window_draw_func(win, draw);
    window_show(win);
    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, app_init_cb);
}
