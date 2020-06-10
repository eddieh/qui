#ifndef APP_H
#define APP_H

#include "window.h"

struct app;

struct app *appref;

struct app *app_new();
void app_run(struct app *a);
void app_cleanup(struct app *a);

void app_add_window(struct app *a, struct window *win);

#endif /* APP_H */
