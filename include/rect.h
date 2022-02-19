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

inline float qu_maxx(QuRect r)
{
    return r.origin.x + r.size.width;
}

inline float qu_maxy(QuRect r)
{
    return r.origin.y + r.size.height;
}

inline float qu_midx(QuRect r)
{
    return r.origin.x + r.size.width * 0.5f;
}

inline float qu_midy(QuRect r)
{
    return r.origin.y + r.size.height * 0.5f;
}

inline float qu_minx(QuRect r)
{
    return r.origin.x;
}

inline float qu_miny(QuRect r)
{
    return r.origin.y;
}

inline float qu_w(QuRect r)
{
    return r.size.width;
}

inline float qu_h(QuRect r)
{
    return r.size.height;
}

int is_point_in_rect(QuPoint p, QuRect r);

/* caller is responsible for freeing */
char *rect_str(QuRect r);

#endif /* RECT_H */
