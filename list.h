#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct list {
    size_t count;
    size_t size;
    void **objects;
};

struct list *list_new(size_t count);

void list_insert(struct list *lst, void *obj, size_t idx);
void *list_remove(struct list *lst, size_t idx);

void list_push(struct list *lst, void *obj);
void *list_pop(struct list *lst);

void *list_first(struct list *lst);
void *list_last(struct list *lst);

void *list_at(struct list *lst, size_t idx);

#endif /* LIST_H */
