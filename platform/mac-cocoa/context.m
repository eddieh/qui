#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGColor.h>

#import "qui.h"
#import "platform.h"
#import "context-private.h"
#import "font-private.h"
#import "private.h"

struct QuContext {
    CGContextRef _context;
    NSWindow *_window;
    NSView *_view;
    QuView *current_view;
};

CGRect cg_rect_in_context(QuContext *ctx, QuRect r)
{
    QuRect wr;

    if (!ctx->current_view)
        return CGRectMake(r.origin.x,
            r.origin.y,
            r.size.width,
            r.size.height);

    wr = view_rect_in_window_coords(ctx->current_view, r);

    return CGRectMake(wr.origin.x,
        wr.origin.y,
        wr.size.width,
        wr.size.height);
}

QuContext *_QuContextA(CGContextRef cg, NSWindow *win, NSView *view)
{
    QuContext *ctx = calloc(1, sizeof(QuContext));
    ctx->_context = cg;
    ctx->_window = win;
    ctx->_view = view;
    return ctx;
}

void _QuContext_set_current_view(QuContext *ctx, QuView *cv)
{
    ctx->current_view = cv;
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
    cgr = cg_rect_in_context(ctx, r);
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
    cgr = cg_rect_in_context(ctx, r);
    CGContextStrokeRect(cgctx, cgr);
}

// caller must free
CFAttributedStringRef _cf_attributed_string(QuFont *font, const char *text)
{
    CFStringRef str;
    CFAttributedStringRef styled;
    str = CFStringCreateWithCString(
        kCFAllocatorDefault,
        text,
        kCFStringEncodingUTF8
    );
    styled = CFAttributedStringCreate(
        kCFAllocatorDefault,
        str,
        font->_attrs
    );
    CFRelease(str);
    return styled;
}

QuRect text_bounds(QuContext *ctx, QuFont *font, const char *text)
{
    CGContextRef cgctx;
    CFAttributedStringRef styled;
    CTLineRef line;
    CGRect bounds;

    cgctx = ctx->_context;
    styled = _cf_attributed_string(font, text);
    line = CTLineCreateWithAttributedString(styled);
    //bounds = CTLineGetImageBounds(line, cgctx);
    bounds = CTLineGetBoundsWithOptions(line, 0);

    CFRelease(line);
    CFRelease(styled);

    return CGRect_toQuRect(bounds);
}

void draw_text(QuContext *ctx, QuFont *font, const char *text, QuPoint pos)
{
    CGContextRef cgctx;
    CFAttributedStringRef styled;
    CTLineRef line;
    CGRect cgr;

    cgctx = ctx->_context;
    styled = _cf_attributed_string(font, text);
    line = CTLineCreateWithAttributedString(styled);
    cgr = cg_rect_in_context(ctx, QuRectS(pos.x, pos.y, 0, 0));
    CGContextSetTextPosition(cgctx, cgr.origin.x, cgr.origin.y);
    CTLineDraw(line, cgctx);

    CFRelease(line);
    CFRelease(styled);
}

void draw_button(QuContext *ctx, QuRect r)
{
    CGRect cgr;
    cgr = cg_rect_in_context(ctx, r);
    NSDrawButton(cgr, cgr);
}

void draw_button_pushed(QuContext *ctx, QuRect r)
{
    CGRect cgr;
    cgr = cg_rect_in_context(ctx, r);
    NSDrawGrayBezel(cgr, cgr);
}
