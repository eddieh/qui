#ifndef RECT_H
#define RECT_H

typedef struct QuPoint {
    float x;
    float y;
} QuPoint;

typedef struct QuVector {
    float dx;
    float dy;
} QuVector;

typedef struct QuSize {
    float width;
    float height;
} QuSize;

typedef struct QuRect {
    QuPoint origin;
    QuSize size;
} QuRect;

inline QuPoint QuPointS(float x, float y)
{
    QuPoint p;
    p.x = x;
    p.y = y;
    return p;
}

inline QuVector QuVectorS(float dx, float dy)
{
    QuVector v;
    v.dx = dx;
    v.dy = dy;
    return v;
}

inline QuSize QuSizeS(float w, float h)
{
    QuSize s;
    s.width = w;
    s.height = h;
    return s;
}

inline QuRect QuRectS(float x, float y, float w, float h)
{
    QuRect r;
    r.origin.x = x;
    r.origin.y = y;
    r.size.width = w;
    r.size.height = h;
    return r;
}

QuPoint QuPointZero;
QuVector QuVectorZero;
QuSize QuSizeZero;
QuRect QuRectZero;

char *rect_str(QuRect r);

#endif /* RECT_H */
