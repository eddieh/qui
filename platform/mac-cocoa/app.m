#import <Cocoa/Cocoa.h>

#import "qui.h"
#import "private.h"

struct app {
    NSAutoreleasePool *_pool;
    NSApplication *_app;
};

struct app *app_new()
{
    appref = malloc(sizeof(struct app));
    if (!appref)
        qui_die("out of memory");

    appref->_pool = [NSAutoreleasePool new];
    appref->_app = [NSApplication sharedApplication];

    // give us a menubar and display app in dock
    [appref->_app setActivationPolicy:NSApplicationActivationPolicyRegular];

    return appref;
}

void app_run(struct app *a)
{
    // activate and run the main event loop
    [a->_app activateIgnoringOtherApps:YES];
    [a->_app run];
}

void app_cleanup(struct app *a)
{
    // cleanup
    [a->_app release];
    [a->_pool release];
}

int __app_default_init(struct app *a)
{
    if (!__app_default_menu(a))
        qui_die("failed to init default menu");

    if (!__app_default_window(a))
        qui_die("failed to init default window");

    return 1;
}

int __app_default_menu(struct app *a)
{
    NSMenu *menubar, *appMenu;
    NSMenuItem *appMenuItem, *quitMenuItem;

    menubar = [[NSMenu new] autorelease];
    appMenuItem = [[NSMenuItem new] autorelease];
    appMenu = [[NSMenu new] autorelease];
    quitMenuItem = [[NSMenuItem new] autorelease];

    [menubar addItem:appMenuItem];
    [appMenuItem setSubmenu:appMenu];
    [appMenu addItem:quitMenuItem];

    [quitMenuItem setTitle:@"Quit"];
    [quitMenuItem setAction:@selector(terminate:)];
    [quitMenuItem setKeyEquivalent:@"q"];

    [a->_app setMainMenu:menubar];

    return 1;
}

int __app_default_window(struct app *a)
{
    NSRect rect;
    NSWindowStyleMask style;
    NSWindow *win;

    rect = NSMakeRect(100, 350, 400, 400);
    style = NSWindowStyleMaskTitled;
    style |= NSWindowStyleMaskClosable;

    win = [[[NSWindow alloc]
        initWithContentRect:rect
        styleMask:style
        backing:NSBackingStoreBuffered
        defer:NO
    ] autorelease];

    [win center];
    [win makeKeyAndOrderFront:nil];

    return 1;
}
