#import <Cocoa/Cocoa.h>

#import "qui.h"
#import "context-private.h"
#import "QUIApplication.h"

struct QuApp {
    NSAutoreleasePool *_pool;
    NSApplication *_app;
    QUIApplicationDelegate *_delegate;
};

void _app_default_menu(QuApp *app);
void _app_default_window(QuApp *app);

QuApp *QuAppA()
{
    appref = malloc(sizeof(QuApp));
    if (!appref)
        qu_die("out of memory");

    appref->_pool = [NSAutoreleasePool new];
    appref->_app = [QUIApplication sharedApplication];
    appref->_delegate = [QUIApplicationDelegate new];
    [appref->_app setDelegate:appref->_delegate];

    return appref;
}

void app_run(QuApp *a)
{
    if (!app_has_main_menu(a))
        _app_default_menu(a);

    if (!app_has_main_window(a))
        _app_default_window(a);

    [a->_app run];
}

void app_cleanup(QuApp *a)
{
    [a->_app release];
    [a->_pool release];
}

int app_has_main_menu(QuApp *a)
{
    return !![a->_app mainMenu];
}

int app_has_main_window(QuApp *a)
{
    return !![[a->_app windows] count];
}

void _app_default_menu(QuApp *a)
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
}

void _app_default_window(QuApp *a)
{
    QuWindow *win = QuWindowA();
    window_center(win);
    window_show(win);
}
