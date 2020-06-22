#import <Cocoa/Cocoa.h>

#import "qui.h"
#import "private.h"

#import "QUIContentView.h"

struct QuWindow {
    QuList *children;
    NSWindow *_win;
    QUIContentView *_contentView;
};

QuWindow *window_new()
{
    NSRect rect;
    NSWindowStyleMask style;
    QuWindow *win = malloc(sizeof(QuWindow));

    rect = NSMakeRect(320, 350, 480, 320);
    style = NSWindowStyleMaskTitled;
    style |= NSWindowStyleMaskClosable;

    win->_win = [[[NSWindow alloc]
        initWithContentRect:rect
        styleMask:style
        backing:NSBackingStoreBuffered
        defer:NO
    ] autorelease];

    [win->_win setBackgroundColor:[NSColor lightGrayColor]];

    win->_contentView = [[[QUIContentView alloc]
        initWithFrame:rect
    ] autorelease];

    [win->_win setContentView:win->_contentView];

    return win;
}

void window_show(QuWindow *win)
{
    [win->_win makeKeyAndOrderFront:nil];
    [win->_win makeMainWindow];
}

void window_close(QuWindow *win)
{
}

void window_draw_func(QuWindow *win,
    void (*df)(QuContext *, QuRect))
{
    [win->_contentView setDrawFunction:df];
}
