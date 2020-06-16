#ifndef RECT_H
#define RECT_H

struct QuPoint {
    float x;
    float y;
};

struct QuVector {
    float dx;
    float dy;
};

struct QuSize {
    float width;
    float height;
};

struct QuRect {
    struct QuPoint origin;
    struct QuSize size;
};

inline struct QuPoint point(float x, float y)
{
    struct QuPoint p;
    p.x = x;
    p.y = y;
    return p;
}

inline struct QuVector vector(float dx, float dy)
{
    struct QuVector v;
    v.dx = dx;
    v.dy = dy;
    return v;
}

inline struct QuSize size(float w, float h)
{
    struct QuSize s;
    s.width = w;
    s.height = h;
    return s;
}

inline struct QuRect rect(float x, float y, float w, float h)
{
    struct QuRect r;
    r.origin.x = x;
    r.origin.y = y;
    r.size.width = w;
    r.size.height = h;
    return r;
}

#endif /* RECT_H */
