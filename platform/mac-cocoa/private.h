#import <Cocoa/Cocoa.h>

#include "qui.h"

int __app_default_init(QuApp *app);
int __app_default_menu(QuApp *app);
int __app_default_window(QuApp *app);

struct context *context_new(CGContextRef cg, NSWindow *win, NSView *view);
