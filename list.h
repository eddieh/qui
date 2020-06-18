#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct QuList QuList;

QuList *list_new(size_t count);

void list_insert(QuList *lst, void *obj, size_t idx);
void *list_remove(QuList *lst, size_t idx);

void list_push(QuList *lst, void *obj);
void *list_pop(QuList *lst);

void *list_first(QuList *lst);
void *list_last(QuList *lst);

void *list_at(QuList *lst, size_t idx);

size_t list_count(QuList *lst);

#endif /* LIST_H */
