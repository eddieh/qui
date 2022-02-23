#include "qui.h"
#include <stdio.h>

void btn_action_cb(QuButton *btn, QuEvent e)
{
    fprintf(stderr, "[action] %s\n", button_title(btn));
}

int app_init_cb(QuApp *app)
{
    QuWindow *win = QuWindowA();

    QuButton *btn = QuButtonA();
    view_set_frame(btn, QuRectS(32, 32, 128, 32));
    button_set_action_func(btn, btn_action_cb);
    button_set_title(btn, "Hit me!");
    window_add_subview(win, btn);

    QuButton *btn2 = QuButtonA();
    view_set_frame(btn2, QuRectS(192, 32, 128, 32));
    button_set_action_func(btn2, btn_action_cb);
    button_set_title(btn2, "Press me!");;
    window_add_subview(win, btn2);

    window_show(win);

    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, app_init_cb);
}
