#include "qui.h"

int init(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_set_frame(win, QuRectS(0, 0, 600, 600));
    window_center(win);
    window_show(win);
    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, init);
}
