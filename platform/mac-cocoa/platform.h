#import <Cocoa/Cocoa.h>

#include "qui.h"

NSPoint QuPoint_toNSPoint(QuPoint p);
QuPoint NSPoint_toQuPoint(NSPoint p);

CGPoint QuPoint_toCGPoint(QuPoint p);
QuPoint CGPoint_toQuPoint(CGPoint p);

NSSize QuSize_toNSSize(QuSize s);
QuSize NSSize_toQuSize(NSSize s);

CGSize QuSize_toCGSize(QuSize s);
QuSize CGSize_toQuSize(CGSize s);

CGVector QuVector_toCGVector(QuVector v);
QuVector CGVector_toQuVector(CGVector v);

NSRect QuRect_toNSRect(QuRect r);
QuRect NSRect_toQuRect(NSRect r);

CGRect QuRect_toCGRect(QuRect r);
QuRect CGRect_toQuRect(CGRect r);

NSColor *QuRGBA_toNSColor(QuRGBA c);
QuRGBA NSColor_toQuRGBA(NSColor *c);

CGColorRef QuRGBA_toCGColorRef(QuRGBA c);
QuRGBA CGColorRef_toQuRGBA(CGColorRef c);

QuEvent NSEvent_toQuEvent(NSEvent *e);
