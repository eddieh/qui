#import <Cocoa/Cocoa.h>

#include "qui.h"

int __app_default_init(struct app *a);
int __app_default_menu(struct app *a);
int __app_default_window(struct app *a);

struct context *context_new(CGContextRef cg, NSWindow *win, NSView *view);
