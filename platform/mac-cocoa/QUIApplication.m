#import "QUIApplication.h"

@implementation QUIApplication
@end

@implementation QUIApplicationDelegate

- (void)applicationWillFinishLaunching:(NSNotification *)notification
{
    // give us a menubar and display app in dock
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
}

- (void)applicationDidFinishLaunching:(NSNotification *)notification
{
    [NSApp activateIgnoringOtherApps:YES];
}

@end
