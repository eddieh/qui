#ifndef CONTEXT_H
#define CONTEXT_H

#include "color.h"
#include "rect.h"

typedef struct QuContext QuContext;

void fill_color(QuContext *ctx, struct QuRGBA c);
void fill(QuContext *ctx, struct QuRect r);

void stroke_color(QuContext *ctx, struct QuRGBA c);
void stroke(QuContext *ctx, struct QuRect r);

#endif /* CONTEXT_H */
