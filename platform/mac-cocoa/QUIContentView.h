#import <Cocoa/Cocoa.h>

#import "qui.h"
#import "private.h"

@interface QUIContentView : NSView
- (void)setDrawFunction:(void (*)(struct context *, struct QuRect))df;
@end
