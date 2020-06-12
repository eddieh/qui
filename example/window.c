#include "qui.h"

int app_init_cb(struct app *a)
{
    struct window *win = window_new();
    window_show(win);
    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, app_init_cb);
}
