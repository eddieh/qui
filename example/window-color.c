#include "qui.h"

void init(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_set_background_color(win, QuRGBA_White);
    window_show(win);
}

int main(int argc, char **argv)
{
    return qu_main(argc, argv, init);
}
