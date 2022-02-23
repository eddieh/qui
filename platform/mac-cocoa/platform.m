#import <Cocoa/Cocoa.h>

#import "qui.h"
#import "platform.h"

const int _event_type_max = 38;
int _event_type_table[45] = {
    /*  0                               */ QuEvent_Unknown,

    /*  1 NSEventTypeLeftMouseDown      */ QuEvent_MouseDown,
    /*  2 NSEventTypeLeftMouseUp        */ QuEvent_MouseUp,
    /*  3 NSEventTypeRightMouseDown     */ QuEvent_MouseDown,
    /*  4 NSEventTypeRightMouseUp       */ QuEvent_MouseUp,

    /*  5 NSEventTypeMouseMoved         */ QuEvent_Unknown,
    /*  6 NSEventTypeLeftMouseDragged   */ QuEvent_Unknown,
    /*  7 NSEventTypeRightMouseDragged  */ QuEvent_Unknown,
    /*  8 NSEventTypeMouseEntered       */ QuEvent_Unknown,
    /*  9 NSEventTypeMouseExited        */ QuEvent_Unknown,

    /* 10 NSEventTypeKeyDown            */ QuEvent_KeyDown,
    /* 11 NSEventTypeKeyUp              */ QuEvent_KeyUp,

    /* 12 NSEventTypeFlagsChanged       */ QuEvent_Unknown,
    /* 13 NSEventTypeAppKitDefined      */ QuEvent_Unknown,
    /* 14 NSEventTypeSystemDefined      */ QuEvent_Unknown,
    /* 15 NSEventTypeApplicationDefined */ QuEvent_Unknown,
    /* 16 NSEventTypePeriodic           */ QuEvent_Unknown,
    /* 17 NSEventTypeCursorUpdate       */ QuEvent_Unknown,
    /* 18 NSEventTypeRotate             */ QuEvent_Unknown,
    /* 19 NSEventTypeBeginGesture       */ QuEvent_Unknown,
    /* 20 NSEventTypeEndGesture         */ QuEvent_Unknown,
    /* 21                               */ QuEvent_Unknown,
    /* 22 NSEventTypeScrollWheel        */ QuEvent_Unknown,
    /* 23 NSEventTypeTabletPoint        */ QuEvent_Unknown,
    /* 24 NSEventTypeTabletProximity    */ QuEvent_Unknown,

    /* 25 NSEventTypeOtherMouseDown     */ QuEvent_MouseDown,
    /* 26 NSEventTypeOtherMouseUp       */ QuEvent_MouseUp,

    /* 27 NSEventTypeOtherMouseDragged  */ QuEvent_Unknown,
    /* 28                               */ QuEvent_Unknown,
    /* 29 NSEventTypeGesture            */ QuEvent_Unknown,
    /* 30 NSEventTypeMagnify            */ QuEvent_Unknown,
    /* 31 NSEventTypeSwipe              */ QuEvent_Unknown,
    /* 32 NSEventTypeSmartMagnify       */ QuEvent_Unknown,
    /* 33 NSEventTypeQuickLook          */ QuEvent_Unknown,
    /* 34 NSEventTypePressure           */ QuEvent_Unknown,
    /* 37 NSEventTypeDirectTouch        */ QuEvent_Unknown,
    /* 38 NSEventTypeChangeMode         */ QuEvent_Unknown,
};

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

CGRect QuRect_toCGRect(QuRect r)
{
    return CGRectMake(
        r.origin.x,
        r.origin.y,
        r.size.width,
        r.size.height);
}

QuRect CGRect_toQuRect(CGRect r)
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

QuEvent NSEvent_toQuEvent(NSEvent *e)
{
    QuEvent event;
    NSString *c;
    NSUInteger clen;

    memset(&event, 0, sizeof(QuEvent));

    if (e.type > _event_type_max)
        event.type = QuEvent_Unknown;
    else
        event.type = _event_type_table[e.type];

    switch (event.type) {
    case QuEvent_MouseDown:
    case QuEvent_MouseUp:
        event.loc = QuPointS(e.locationInWindow.x, e.locationInWindow.y);
        switch (e.buttonNumber) {
        case 0:
            event.left = 1;
            break;
        case 1:
            event.right = 1;
            break;
        default:
            /* NOTE: for now treat all other buttons as the same */
            event.middle = event.other = 1;
            break;
        }
        break;
    case QuEvent_KeyDown:
    case QuEvent_KeyUp:
        c = e.characters;
        clen = [c maximumLengthOfBytesUsingEncoding:NSUTF8StringEncoding];
        assert(clen < 5);       /* FIXME: perhaps just a warning about
                                 * data loss? */
        [c getCString:event.ch
            maxLength:5
            encoding:NSUTF8StringEncoding];
        event.code = e.keyCode;
        event.repeat = !!e.isARepeat;
        break;
    default:
        break;
    }

    event.shft = !!(e.modifierFlags & NSEventModifierFlagShift);
    event.ctrl = !!(e.modifierFlags & NSEventModifierFlagControl);
    /* NOTE: treat alt & opt as the same */
    event.alt = event.opt = !!(e.modifierFlags & NSEventModifierFlagOption);
    event.cmd = !!(e.modifierFlags & NSEventModifierFlagCommand);
    event.fn = !!(e.modifierFlags & NSEventModifierFlagFunction);

    return event;
}
