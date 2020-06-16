#ifndef CONTEXT_H
#define CONTEXT_H

#include "color.h"
#include "rect.h"

struct context;

void fill_color(struct context *ctx, struct QuRGBA c);
void fill(struct context *ctx, struct QuRect r);

void stroke_color(struct context *ctx, struct QuRGBA c);
void stroke(struct context *ctx, struct QuRect r);

#endif /* CONTEXT_H */
