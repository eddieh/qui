#include "qui.h"
#include <stdio.h>

void btn_action_cb(QuButton *btn, QuEvent e)
{
    fprintf(stderr, "[action] %s\n", button_title(btn));
}

void app_init_cb(QuApp *app)
{
    QuWindow *win = QuWindowA();
    QuButton *btn = QuButtonA();
    window_set_frame(win, QuRectS(0, 0, 192, 96));
    window_center(win);
    view_set_frame(btn, QuRectS(32, 32, 128, 32));
    button_set_action_func(btn, btn_action_cb);
    button_set_title(btn, "hello, world!");
    window_add_subview(win, btn);
    window_show(win);
}

int main(int argc, char **argv)
{
    return qu_main(argc, argv, app_init_cb);
}
