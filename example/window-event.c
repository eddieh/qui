#include <stdio.h>
#include "qui.h"

void mouseup_cb(QuWindow *win, QuEvent e)
{
    char *es = event_str(e);
    fprintf(stderr, "%s %s\n", __func__, es);
    free(es);
}

int app_init_cb(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_set_event_func(win, QuEvent_MouseUp, mouseup_cb);
    window_show(win);
    return 1;
}

int main(int argc, char **argv)
{
    return qui_main_init(argc, argv, app_init_cb);
}
