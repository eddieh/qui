#import "QUIContentView.h"

@interface QUIContentView () {
    struct context *_context;
    void (*_drawf)(struct context *, struct QuRect);
}
@end

@implementation QUIContentView

- (void)drawRect:(NSRect)dirtyRect
{
    CGContextRef cgctx;
    struct QuRect dirty;

    if (!_context) {
        cgctx = [[NSGraphicsContext currentContext] CGContext];
        _context = context_new(
            cgctx,
            [self window],
            self);
    }

    dirty = rect(dirtyRect.origin.x,
                 dirtyRect.origin.y,
                 dirtyRect.size.width,
                 dirtyRect.size.height);

    if (_drawf)
        _drawf(_context, dirty);

}

- (void)setDrawFunction:(void (*)(struct context *, struct QuRect))df
{
    _drawf = df;
}

@end
