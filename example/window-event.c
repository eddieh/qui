#include <stdio.h>
#include "qui.h"

void mouseup_cb(QuWindow *win, QuEvent e)
{
    char *es = event_str(e);
    fprintf(stderr, "%s %s\n", __func__, es);
    free(es);
}

void app_init_cb(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_set_event_func(win, QuEvent_MouseUp, mouseup_cb);
    window_show(win);
}

int main(int argc, char **argv)
{
    return qu_main(argc, argv, app_init_cb);
}
