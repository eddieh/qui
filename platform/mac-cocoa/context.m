#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGColor.h>

#import "qui.h"
#import "platform.h"
#import "context-private.h"
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
    QuContext *ctx = malloc(sizeof(QuContext));
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

void draw_text(QuContext *ctx, const char *text, QuPoint pos)
{
    CGContextRef cgctx;
    CFStringRef str;
    CFStringRef keys[1];
    CFTypeRef values[1];
    CFDictionaryRef attrs;
    CFAttributedStringRef styled;
    CTFontRef font;
    CTLineRef line;

    cgctx = ctx->_context;

    font = CTFontCreateUIFontForLanguage(
        kCTFontUIFontPushButton,
        0,
        NULL
    );

    keys[0] = kCTFontAttributeName;
    values[0] = font;

    attrs = CFDictionaryCreate(
        kCFAllocatorDefault,
        (const void**)keys,
        (const void**)values,
        sizeof(keys) / sizeof(keys[0]),
        &kCFTypeDictionaryKeyCallBacks,
        &kCFTypeDictionaryValueCallBacks
    );

    str = CFStringCreateWithCString(
        kCFAllocatorDefault,
        text,
        kCFStringEncodingUTF8
    );
    styled = CFAttributedStringCreate(
        kCFAllocatorDefault,
        str,
        attrs
    );
    line = CTLineCreateWithAttributedString(styled);

    CGContextSetTextPosition(cgctx, pos.x, pos.y);
    CTLineDraw(line, cgctx);

    CFRelease(line);
    CFRelease(styled);
    CFRelease(str);
    CFRelease(attrs);
    CFRelease(font);
}

void draw_button(QuContext *ctx, QuRect r)
{
    CGRect cgr;
    cgr = CGRectMake(r.origin.x, r.origin.y, r.size.width, r.size.height);
    NSDrawButton(cgr, cgr);
}

void draw_button_pushed(QuContext *ctx, QuRect r)
{
    CGRect cgr;
    cgr = CGRectMake(r.origin.x, r.origin.y, r.size.width, r.size.height);
    NSDrawGrayBezel(cgr, cgr);
}
