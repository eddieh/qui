#include "button.h"
#include "view.h"
#include "event.h"
#include "private.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QuButtonState {
    char *title;
    unsigned pressed:1;
} QuButtonState;

QuButtonState *QuButtonStateA()
{
    QuButtonState *bs = calloc(1, sizeof(QuButtonState));
    bs->title = strdup("");
    return bs;
}

#define button_state(x) ((QuButtonState *)x->state)

void button_draw_cb(QuButton *btn, QuContext *ctx)
{
    QuRect bounds, tb;
    static QuFont *bf;

    bounds = view_bounds(btn);
    if (button_state(btn)->pressed)
        draw_button_pushed(ctx, bounds);
    else
        draw_button(ctx, bounds);

    if (!bf)
        bf = QuFontButtonA();

    tb = text_bounds(ctx, bf, button_state(btn)->title);
    tb.origin.x = qu_midx(bounds) - qu_midx(tb);
    tb.origin.y = qu_midy(bounds) - qu_midy(tb);
    draw_text(ctx, bf, button_state(btn)->title, tb.origin);
}

void button_mousedown_cb(QuButton *btn, QuEvent e)
{
    button_state(btn)->pressed = 1;
    view_redraw(btn);
}

void button_mouseup_cb(QuButton *btn, QuEvent e)
{
    button_state(btn)->pressed = 0;
    view_redraw(btn);

    /* send action if loc in view */
    if (is_point_in_view(e.loc, btn))
        if (btn->actionf)
            btn->actionf(btn, e);
}

QuButton *QuButtonA()
{
    QuButton *btn = malloc(sizeof(QuButton));
    memset(btn, 0, sizeof(QuButton));
    btn->frame = QuRectZero;
    btn->bounds = QuRectZero;
    btn->children = QuListA(1);
    view_set_event_func(btn, QuEvent_MouseDown, button_mousedown_cb);
    view_set_event_func(btn, QuEvent_MouseUp, button_mouseup_cb);
    view_draw_func(btn, button_draw_cb);
    btn->state = QuButtonStateA();
    return btn;
}

void button_set_action_func(QuButton *btn,
    void (*af)(QuButton *, QuEvent))
{
    btn->actionf = af;
}

const char *button_title(QuButton *btn)
{
    return button_state(btn)->title;
}

void button_set_title(QuButton *btn, const char *title)
{
    if (button_state(btn)->title)
        free(button_state(btn)->title);

    if (title)
        button_state(btn)->title = strdup(title);
    else
        button_state(btn)->title = strdup("");
}

void button_free(QuButton *btn)
{
}
