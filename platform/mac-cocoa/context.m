#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGColor.h>

#import "qui.h"
#import "private.h"

struct context {
    CGContextRef _context;
    NSWindow *_window;
    NSView *_view;
};

struct context *context_new(CGContextRef cg, NSWindow *win, NSView *view)
{
    struct context *ctx = malloc(sizeof(struct context));
    ctx->_context = cg;
    ctx->_window = win;
    ctx->_view = view;
    return ctx;
}

void fill_color(struct context *ctx, struct QuRGBA c)
{
    CGContextRef cgctx;
    CGColorRef cgc;

    cgctx = ctx->_context;
    cgc = CGColorCreateGenericRGB(c.red, c.green, c.blue, c.alpha);
    CGContextSetFillColorWithColor(cgctx, cgc);
}

void fill(struct context *ctx, struct QuRect r)
{
    CGContextRef cgctx;
    CGRect cgr;

    cgctx = ctx->_context;
    cgr = CGRectMake(r.origin.x, r.origin.y, r.size.width, r.size.height);
    CGContextFillRect(cgctx, cgr);
}

void stroke_color(struct context *ctx, struct QuRGBA c)
{
}

void stroke(struct context *ctx, struct QuRect r)
{
}
