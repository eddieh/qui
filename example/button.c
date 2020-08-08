#include "qui.h"

void draw(QuContext *ctx, QuRect dirty)
{
    draw_button(ctx, QuRectS(42, 42, 100, 24));
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
