#include "qui.h"
void i(QuApp *a) {
  QuWindow *w = QuWindowA();
  QuButton *b = QuButtonA();
  view_set_frame(b, QuRectS(32, 32, 128, 32));
  button_set_title(b, "hello!");
  window_add_subview(w, b);
  window_show(w);
}
int main(int c, char **v) {
  return qu_main(c, v, i);
}
