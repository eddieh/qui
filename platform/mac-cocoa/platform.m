#import <Cocoa/Cocoa.h>

#import "qui.h"
#import "platform.h"

NSRect QuRect_toNSRect(QuRect r)
{
    return NSMakeRect(
        r.origin.x,
        r.origin.y,
        r.size.width,
        r.size.height);
}

QuRect NSRect_toQuRect(NSRect r)
{
    return QuRectS(
        r.origin.x,
        r.origin.y,
        r.size.width,
        r.size.height);
}

NSColor *QuRGBA_toNSColor(QuRGBA c)
{
    return [[NSColor colorWithRed:c.red
        green:c.green
        blue:c.blue
        alpha:c.alpha
    ] autorelease];
}

QuRGBA NSColor_toQuRGBA(NSColor *c)
{
    return rgba(
        [c redComponent],
        [c greenComponent],
        [c blueComponent],
        [c alphaComponent]);
}
