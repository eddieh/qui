#ifndef APP_H
#define APP_H

#include "window.h"

struct app;

struct app *appref;

struct app *app_new();
void app_run(struct app *a);
void app_cleanup(struct app *a);

int app_has_main_menu(struct app *a);
int app_has_main_window(struct app *a);

#endif /* APP_H */
