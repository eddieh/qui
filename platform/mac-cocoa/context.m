#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGColor.h>

#import "qui.h"
#import "private.h"

struct QuContext {
    CGContextRef _context;
    NSWindow *_window;
    NSView *_view;
};

QuContext *context_new(CGContextRef cg, NSWindow *win, NSView *view)
{
    QuContext *ctx = malloc(sizeof(QuContext));
    ctx->_context = cg;
    ctx->_window = win;
    ctx->_view = view;
    return ctx;
}

void fill_color(QuContext *ctx, QuRGBA c)
{
    CGContextRef cgctx;
    CGColorRef cgc;

    cgctx = ctx->_context;
    cgc = CGColorCreateGenericRGB(c.red, c.green, c.blue, c.alpha);
    CGContextSetFillColorWithColor(cgctx, cgc);
    CGColorRelease(cgc);
}

void fill_rect(QuContext *ctx, QuRect r)
{
    CGContextRef cgctx;
    CGRect cgr;

    cgctx = ctx->_context;
    cgr = CGRectMake(r.origin.x, r.origin.y, r.size.width, r.size.height);
    CGContextFillRect(cgctx, cgr);
}

void stroke_color(QuContext *ctx, QuRGBA c)
{
    CGContextRef cgctx;
    CGColorRef cgc;

    cgctx = ctx->_context;
    cgc = CGColorCreateGenericRGB(c.red, c.green, c.blue, c.alpha);
    CGContextSetStrokeColorWithColor(cgctx, cgc);
    CGColorRelease(cgc);
}

void stroke_rect(QuContext *ctx, QuRect r)
{
    CGContextRef cgctx;
    CGRect cgr;

    cgctx = ctx->_context;
    cgr = CGRectMake(r.origin.x, r.origin.y, r.size.width, r.size.height);
    CGContextStrokeRect(cgctx, cgr);
}
