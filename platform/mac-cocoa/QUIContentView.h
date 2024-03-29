#import <Cocoa/Cocoa.h>

#import "qui.h"

@interface QUIContentView : NSView
- initWithFrame:(NSRect)frame window:(QuWindow *)window;
- (void)setDrawFunction:(void (*)(QuWindow *, QuContext *))df;
@end
