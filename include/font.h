#ifndef FONT_H
#define FONT_H

typedef struct QuFont QuFont;

QuFont *QuFontA(const char *name, float size);
QuFont *QuFontButtonA();

void font_free(QuFont *font);

#endif /* FONT_H */
