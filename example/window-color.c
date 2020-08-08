#include "qui.h"

int init(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_set_background_color(win, QuRGBA_White);
    window_show(win);
    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, init);
}
