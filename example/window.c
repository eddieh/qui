#include "qui.h"

int app_init_cb(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_show(win);
    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, app_init_cb);
}
