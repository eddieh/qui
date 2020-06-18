#import <Cocoa/Cocoa.h>

#import "qui.h"
#import "private.h"

@interface QUIContentView : NSView
- (void)setDrawFunction:(void (*)(QuContext *, QuRect))df;
@end
