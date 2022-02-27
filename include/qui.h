#ifndef QUI_H
#define QUI_H

#include "app.h"
#include "button.h"
#include "color.h"
#include "context.h"
#include "event.h"
#include "font.h"
#include "list.h"
#include "path.h"
#include "rect.h"
#include "util.h"
#include "view.h"
#include "window.h"

int qui_main_init(int argc, char **argv, int (*init)(QuApp *));

#endif /* QUI_H */
