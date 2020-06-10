#include "list.h"
#include "window.h"

#include "app.h"

struct app {
    struct list *children;
};

struct app *app_new()
{
    return NULL;
}

struct app *app_new_init(int (*init)(struct app *))
{
    return NULL;
}

void app_add_window(struct app *a, struct window *win)
{
}
