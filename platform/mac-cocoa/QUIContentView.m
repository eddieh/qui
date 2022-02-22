#import "QUIContentView.h"
#import "context-private.h"
#import "private.h"
#import "platform.h"


@interface QUIContentView () {
    QuWindow *_window;
    QuContext *_context;
    void (*_drawf)(QuWindow *, QuContext *);
}
@end

@implementation QUIContentView

- initWithFrame:(NSRect)frame window:(QuWindow *)window
{
    if (!(self = [super initWithFrame:frame]))
        return nil;

    _window = window;

    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    CGContextRef cgctx;
    QuRect dirty;
    QuView *cv;
    size_t svcount;

    if (!_context) {
        cgctx = [[NSGraphicsContext currentContext] CGContext];
        _context = _QuContextA(
            cgctx,
            [self window],
            self);
    }

    dirty = QuRectS(dirtyRect.origin.x,
                 dirtyRect.origin.y,
                 dirtyRect.size.width,
                 dirtyRect.size.height);

    if (_drawf)
        _drawf(_window, _context);

    svcount = window_subview_count(_window);
    for (size_t i = 0; i < svcount; i++) {
        cv = window_subview_at(_window, i);
        _QuContext_set_current_view(_context, cv);
        view_draw(cv, _context);
        _QuContext_set_current_view(_context, NULL);
    }
}

- (void)setDrawFunction:(void (*)(QuWindow *, QuContext *))df
{
    _drawf = df;
}

- (BOOL)acceptsFirstResponder
{
    return YES;
}

- (void)mouseDown:(NSEvent *)e
{
    window_send_event(_window, NSEvent_toQuEvent(e));
}

- (void)rightMouseDown:(NSEvent *)e
{
    window_send_event(_window, NSEvent_toQuEvent(e));
}

- (void)otherMouseDown:(NSEvent *)e
{
    window_send_event(_window, NSEvent_toQuEvent(e));
}

- (void)mouseUp:(NSEvent *)e
{
    window_send_event(_window, NSEvent_toQuEvent(e));
}

- (void)rightMouseUp:(NSEvent *)e
{
    window_send_event(_window, NSEvent_toQuEvent(e));
}

- (void)otherMouseUp:(NSEvent *)e
{
    window_send_event(_window, NSEvent_toQuEvent(e));
}

- (void)keyDown:(NSEvent *)e
{
    window_send_event(_window, NSEvent_toQuEvent(e));
}

- (void)keyUp:(NSEvent *)e
{
    window_send_event(_window, NSEvent_toQuEvent(e));
}

@end
