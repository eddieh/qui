#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGColor.h>

#import "qui.h"
#import "platform.h"
#import "path-private.h"

QuPath *QuPathA()
{
    QuPath *path = calloc(1, sizeof(QuPath));
    path->_path = CGPathCreateMutable();
    return path;
}

void path_move_to(QuPath *path, QuPoint pos)
{
    CGPathMoveToPoint(path->_path, NULL, pos.x, pos.y);
}

void path_line_to(QuPath *path, QuPoint pos)
{
    CGPathAddLineToPoint(path->_path, NULL, pos.x, pos.y);
}

void path_curve_to(QuPath *path, QuPoint cp1, QuPoint cp2, QuPoint pos)
{
    CGPathAddCurveToPoint(path->_path, NULL, cp1.x, cp1.y,
        cp2.x, cp2.y, pos.x, pos.y);
}

void path_arc_to(QuPath *path, QuPoint p1, QuPoint p2, float r)
{
    CGPathAddArcToPoint(path->_path, NULL, p1.x, p1.y, p2.x, p2.y, r);
}

void path_add(QuPath *path1, QuPath *path2)
{
    CGPathAddPath(path1->_path, NULL, path2->_path);
}

void path_add_rect(QuPath *path, QuRect rect)
{
    CGPathAddRect(path->_path, NULL, QuRect_toCGRect(rect));
}

void path_add_arc(QuPath *path, QuPoint cp, float r, float sa, float ea, int c)
{
    CGPathAddArc(path->_path, NULL, cp.x, cp.y, r, sa, ea, c);
}

void path_add_ellipse(QuPath *path, QuRect rect)
{
    CGPathAddEllipseInRect(path->_path, NULL, QuRect_toCGRect(rect));
}

void path_close(QuPath *path)
{
    CGPathCloseSubpath(path->_path);
}

void path_free(QuPath *path)
{
    CGPathRelease(path->_path);
    free(path);
}
