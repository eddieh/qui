#ifndef CONTEXT_H
#define CONTEXT_H

#include "color.h"
#include "rect.h"

typedef struct QuContext QuContext;

void fill_color(QuContext *ctx, QuRGBA c);
void fill_rect(QuContext *ctx, QuRect r);

void stroke_color(QuContext *ctx, QuRGBA c);
void stroke_rect(QuContext *ctx, QuRect r);

void draw_text(QuContext *ctx, const char *text, QuPoint pos);

void draw_button(QuContext *ctx, QuRect r);
void draw_button_pushed(QuContext *ctx, QuRect r);

void line_width(QuContext *ctx, float w);

#endif /* CONTEXT_H */
