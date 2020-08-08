#ifndef APP_H
#define APP_H

#include "window.h"

typedef struct QuApp QuApp;

QuApp *appref;

QuApp *QuAppA();
void app_run(QuApp *app);
void app_cleanup(QuApp *app);

int app_has_main_menu(QuApp *app);
int app_has_main_window(QuApp *app);

#endif /* APP_H */
