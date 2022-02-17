#include "event.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *_event_type_str(int type)
{
    switch (type) {
    case QuEvent_MouseDown:
        return "MouseDown";
    case QuEvent_MouseUp:
        return "MouseUp";
    case QuEvent_KeyDown:
        return "KeyDown";
    case QuEvent_KeyUp:
        return "KeyUp";
    default:
        return "Unknown";
    }
}

const char *_event_button_str(QuEvent e)
{
    if (e.type == QuEvent_MouseDown || e.type == QuEvent_MouseUp) {
        if (e.left)
            return " button=left";
        else if (e.right)
            return " button=right";
        else
            return " button=other";
    }
    return "";
}

/* caller must free this */
char *_event_key_str(QuEvent e)
{
    char *ret;
    if (e.type == QuEvent_KeyDown || e.type == QuEvent_KeyUp) {
        /* TODO: handle control characters, np, and ws */
        asprintf(&ret, " ch=%s code=%d repeat=%d",
            e.ch, e.code, e.repeat);
        return ret;
    }
    return strdup("");
}

char *event_str(QuEvent e)
{
    char *ret, *kstr;
    kstr = _event_key_str(e);
    /* TODO: print mouse location */
    asprintf(&ret, "<event:type=%s (%d) modifiers=%s%s%s%s%s%s%s%s>",
        _event_type_str(e.type), e.type,
        e.shft ? "S" : "",
        e.ctrl ? "c" : "",
        e.opt ? "o" : "",
        e.cmd ? "C" : "",
        e.fn ? "f" : "",
        e.shft || e.ctrl || e.opt || e.cmd || e.fn ? "" : "none",
             _event_button_str(e),
             kstr);
    free(kstr);
    return ret;
}
