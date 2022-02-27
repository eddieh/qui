#ifndef PATH_H
#define PATH_H

typedef struct QuPath QuPath;

QuPath *QuPathA();

void path_move_to(QuPath *path, QuPoint pos);
void path_line_to(QuPath *path, QuPoint pos);
void path_curve_to(QuPath *path, QuPoint cp1, QuPoint cp2, QuPoint pos);
void path_arc_to(QuPath *path, QuPoint p1, QuPoint p2, float r);

void path_add(QuPath *p1, QuPath *p2);
void path_add_rect(QuPath *path, QuRect rect);
void path_add_arc(QuPath *path, QuPoint cp, float r, float sa, float ea, int c);
void path_add_ellipse(QuPath *path, QuRect rect);

void path_close(QuPath *path);
void path_free(QuPath *path);

#endif /* PATH_H */
