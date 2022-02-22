#ifndef BUTTON_H
#define BUTTON_H

#include "event.h"
#include "view.h"

typedef struct QuViewPrivate QuButton;

QuButton *QuButtonA();

void button_set_action_func(QuButton *btn,
    void (*af)(QuButton *, QuEvent));
void button_set_title(QuButton *btn, char *title);

void button_free(QuButton *btn);

#endif /* BUTTON_H */
