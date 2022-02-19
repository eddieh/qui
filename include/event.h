#ifndef QU_EVENT_H
#define QU_EVENT_H

#include "rect.h"

typedef struct QuEvent {
    int type;
    union {
        struct {
            QuPoint loc;
            unsigned left:1, middle:1, right:1,
                other:5; /* support for up to 32 buttons */
        };
        struct {
            char ch[5]; /* room for any UTF-8 value and null */
            unsigned short code;
            unsigned repeat:1;
        };
    };
    unsigned shft:1, ctrl:1, alt:1, opt:1, cmd:1, fn:1;
} QuEvent;

enum {
    QuEvent_Unknown = -1,
    QuEvent_MouseDown = 0,
    QuEvent_MouseUp = 1,
    QuEvent_KeyDown = 2,
    QuEvent_KeyUp = 3,
};

/* caller is responsible for freeing */
char *event_str(QuEvent e);

#endif /* QU_EVENT_H */
