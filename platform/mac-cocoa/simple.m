#import <Cocoa/Cocoa.h>

int main(int argc, char **argv)
{
    NSRect rect;
    NSWindowStyleMask style;
    NSAutoreleasePool *pool;
    NSApplication *app;
    NSMenu *menubar, *appMenu;
    NSMenuItem *appMenuItem, *quitMenuItem;
    NSWindow *win;

    style = NSWindowStyleMaskTitled;
    style |= NSWindowStyleMaskClosable;
    rect = NSMakeRect(100, 350, 400, 400);

    pool = [NSAutoreleasePool new];
    app = [NSApplication sharedApplication];

    // give us a menubar and display app in dock
    [app setActivationPolicy:NSApplicationActivationPolicyRegular];

    // build a basic menubar
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

    [app setMainMenu:menubar];

    // make a window
    win = [[[NSWindow alloc]
        initWithContentRect:rect
        styleMask:style
        backing:NSBackingStoreBuffered
        defer:NO
    ] autorelease];

    // run the app and bring it to the front
    [win center];
    [win makeKeyAndOrderFront:nil];
    [app activateIgnoringOtherApps:YES];
    [app run];

    // cleanup
    [app release];
    [pool release];

    return 0;
}
