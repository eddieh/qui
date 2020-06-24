#ifndef COLOR_H
#define COLOR_H

typedef struct QuRGBA {
    float red;
    float green;
    float blue;
    float alpha;
} QuRGBA;

QuRGBA QuRGBA_WindowBackground;
QuRGBA QuRGBA_ControlBackground;
QuRGBA QuRGBA_Control;
QuRGBA QuRGBA_ControlShadow;
QuRGBA QuRGBA_ControlDarkShadow;
QuRGBA QuRGBA_ControlHighlight;
QuRGBA QuRGBA_ControlLightHighlight;
QuRGBA QuRGBA_ControlText;

/* + controlBackgroundColor */
/* + controlColor */
/* + controlDarkShadowColor */
/* + controlHighlightColor */
/* + controlLightHighlightColor */
/* + controlShadowColor */
/* + controlTextColor */
/* + gridColor */
/* + scrollBarColor */
/* + selectedControlColor */
/* + selectedControlTextColor */
/* + selectedTextBackgroundColor */
/* + selectedTextColor */
/* + textBackgroundColor */
/* + textColor */

QuRGBA QuRGBA_White;

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
