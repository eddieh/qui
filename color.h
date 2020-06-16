#ifndef COLOR_H
#define COLOR_H

struct QuRGBA {
    float red;
    float green;
    float blue;
    float alpha;
};

inline struct QuRGBA rgba(float r, float g, float b, float a)
{
    struct QuRGBA c;
    c.red = r;
    c.green = g;
    c.blue = b;
    c.alpha = a;
    return c;
}

#endif /* COLOR_H */
