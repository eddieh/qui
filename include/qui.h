#ifndef QUI_H
#define QUI_H

#include "app.h"
#include "color.h"
#include "context.h"
#include "list.h"
#include "rect.h"
#include "util.h"
#include "view.h"
#include "window.h"


int qui_main(int argc, char **argv);
int qui_main_init(int argc, char **argv, int (*init)(QuApp *));

#endif /* QUI_H */
