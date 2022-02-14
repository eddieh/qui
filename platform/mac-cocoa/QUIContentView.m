#import "QUIContentView.h"
#import "context-private.h"
#import "private.h"

@interface QUIContentView () {
    QuWindow *_window;
    QuContext *_context;
    void (*_drawf)(QuContext *, QuRect);
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
        _drawf(_context, dirty);

    svcount = window_subview_count(_window);
    for (size_t i = 0; i < svcount; i++) {
        cv = window_subview_at(_window, i);
        _QuContext_set_current_view(_context, cv);
        view_draw(cv, _context, dirty);
        _QuContext_set_current_view(_context, NULL);
    }

}

- (void)setDrawFunction:(void (*)(QuContext *, QuRect))df
{
    _drawf = df;
}

@end
