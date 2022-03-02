#include "qui.h"

void init(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_set_frame(win, QuRectS(0, 0, 220, 220));
    window_set_resizable(win, 1);
    window_center(win);
    window_show(win);
}

int main(int argc, char **argv)
{
    return qu_main(argc, argv, init);
}
