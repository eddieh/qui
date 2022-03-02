#include "qui.h"

void draw(QuWindow *win, QuContext *ctx)
{
    QuFont *font = QuFontA("Times New Roman", 24);
    draw_text(ctx, font, "Quick and easy.", QuPointS(42, 42));
    font_free(font);
}

void app_init_cb(QuApp *app)
{
    QuWindow *win = QuWindowA();
    window_draw_func(win, draw);
    window_show(win);
}

int main(int argc, char **argv)
{
    return qu_main(argc, argv, app_init_cb);
}
