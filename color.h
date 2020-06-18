#ifndef COLOR_H
#define COLOR_H

typedef struct QuRGBA {
    float red;
    float green;
    float blue;
    float alpha;
} QuRGBA;

inline QuRGBA rgba(float r, float g, float b, float a)
{
    QuRGBA c;
    c.red = r;
    c.green = g;
    c.blue = b;
    c.alpha = a;
    return c;
}

#endif /* COLOR_H */
