#ifndef PATH_H
#define PATH_H

typedef struct QuPath QuPath;

QuPath *QuPathA();

void path_move_to(QuPath *path, QuPos pos);
void path_line_to(QuPath *path, QuPos pos);

void path_fill(QuPath *path);
void path_stroke(QuPath *path);

//void path_begin(QuPath *path);
void path_close(QuPath *path);

#endif /* PATH_H */
