#import <Cocoa/Cocoa.h>

#import "qui.h"
#import "platform.h"
#import "private.h"

#import "QUIContentView.h"

struct QuWindow {
    NSWindow *_win;
    QUIContentView *_contentView;
    QuList *children;
    QuView *focused, *tracked;
    void (*ev_table[4])(QuWindow *, QuEvent);
};

QuWindow *QuWindowA()
{
    NSRect rect;
    NSWindowStyleMask style;
    NSColor *bg;
    QuWindow *win = malloc(sizeof(QuWindow));
    memset(win, 0, sizeof(QuWindow));

    rect = NSMakeRect(320, 350, 480, 320);
    style = NSWindowStyleMaskTitled;
    style |= NSWindowStyleMaskClosable;

    win->_win = [[[NSWindow alloc]
        initWithContentRect:rect
        styleMask:style
        backing:NSBackingStoreBuffered
        defer:NO
    ] autorelease];

    bg = QuRGBA_toNSColor(QuRGBA_WindowBackground);
    [win->_win setBackgroundColor:bg];

    win->_contentView = [[[QUIContentView alloc]
        initWithFrame:rect
        window:win
    ] autorelease];

    [win->_win setContentView:win->_contentView];

    win->children = QuListA(1);

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
    void (*df)(QuWindow *, QuContext *))
{
    [win->_contentView setDrawFunction:df];
}

void window_redraw(QuWindow *win)
{
    [win->_contentView setNeedsDisplay:YES];
}

QuRGBA window_background_color(QuWindow *win)
{
    NSColor *bg = [win->_win backgroundColor];
    return NSColor_toQuRGBA(bg);
}

void window_set_background_color(QuWindow *win, QuRGBA c)
{
    NSColor *bg = QuRGBA_toNSColor(c);
    [win->_win setBackgroundColor:bg];
}

QuRect window_frame(QuWindow *win)
{
    NSRect frame = [win->_win frame];
    return NSRect_toQuRect(frame);
}

void window_set_frame(QuWindow *win, QuRect frame)
{
    NSRect rect = QuRect_toNSRect(frame);
    rect = [win->_win frameRectForContentRect:rect];
    [win->_win setFrame:rect display:YES];
}


int window_resizable(QuWindow *win)
{
    return [win->_win isResizable];
}

void window_set_resizable(QuWindow *win, int resizable)
{
    NSWindowStyleMask mask;
    mask = [win->_win styleMask];
    if (resizable)
        mask |= NSWindowStyleMaskResizable;
    else
        mask &= ~(1 << NSWindowStyleMaskResizable);
    [win->_win setStyleMask:mask];
}

void window_center(QuWindow *win)
{
    [win->_win center];
}

void window_add_subview(QuWindow *win, QuView *view)
{
    QuViewPrivate *pv = private_view(view);
    assert(pv->window == NULL);
    assert(pv->parent == NULL);

    pv->window = win;
    pv->parent = NULL;

    list_push(win->children, view);
}

size_t window_subview_count(QuWindow *win)
{
    return list_count(win->children);
}

QuView *window_subview_at(QuWindow *win, size_t idx)
{
    return list_at(win->children, idx);
}

void window_set_event_func(QuWindow *win, int et,
    void (*ef)(QuWindow *, QuEvent))
{
    assert(et >= 0);
    assert(et <= 4);

    win->ev_table[et] = ef;
}

void window_remove_event_func(QuWindow *win, int et)
{
    assert(et >= 0);
    assert(et <= 4);

    win->ev_table[et] = NULL;
}

void _window_send_event(QuWindow *win, QuEvent e)
{
    assert(e.type >= 0);
    assert(e.type <= 4);

    if (win->ev_table[e.type])
        win->ev_table[e.type](win, e);
}

QuView *window_focused_view(QuWindow *win)
{
    return win->focused;
}

void window_set_focused_view(QuWindow *win, QuView *view)
{
    win->focused = view;
}

QuView *window_tracking_view(QuWindow *win)
{
    return win->tracked;
}

void window_set_tracking_view(QuWindow *win, QuView *view)
{
    win->tracked = view;
}
