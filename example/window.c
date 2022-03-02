#include "qui.h"

void app_init_cb(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_show(win);
}

int main(int argc, char **argv)
{
    return qu_main(argc, argv, app_init_cb);
}
