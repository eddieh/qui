#ifndef QUI_H
#define QUI_H

#include "list.h"
#include "app.h"
#include "window.h"
#include "view.h"
#include "util.h"

int qui_main(int argc, char **argv);
int qui_main_init(int argc, char **argv, int (*init)(struct app *));

#endif /* QUI_H */
