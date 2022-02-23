#ifndef BUTTON_H
#define BUTTON_H

#include "event.h"
#include "view.h"

typedef struct QuViewPrivate QuButton;

QuButton *QuButtonA();

void button_set_action_func(QuButton *btn,
    void (*af)(QuButton *, QuEvent));

/* makes a copy of title, caller is responsible for freeing the
 * argument if it was dynamically allocated */
void button_set_title(QuButton *btn, const char *title);

void button_free(QuButton *btn);

#endif /* BUTTON_H */
