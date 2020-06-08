#include <stdlib.h>

#include "list.h"
#include "util.h"

struct list *list_new(size_t size)
{
    struct list *lst = malloc(sizeof(struct list));
    lst->count = 0;
    lst->size = size ? size * 2 : 4;
    lst->objects = calloc(lst->size, sizeof(void *));
    return lst;
}

void list_insert(struct list *lst, void *obj, size_t idx)
{
    if (idx > lst->count)
        qui_die("index %d beyond count %d of list %p", idx, lst->count, lst);

    lst->count++;
    if (lst->count > lst->size) {
        lst->size = lst->count * 2;
        lst->objects = realloc(lst->objects, sizeof(void *) * lst->size);
    }

    if (lst->count > 1)
        for (size_t i = lst->count - 1; i > idx && i > 0; i--)
            lst->objects[i] = lst->objects[i - 1];

    lst->objects[idx] = obj;
}

void *list_remove(struct list *lst, size_t idx)
{
    void *obj;

    if (idx >= lst->count)
        qui_die("index %d beyond count %d of list %p", idx, lst->count, lst);

    obj = lst->objects[idx];
    lst->count--;
    for (size_t i = idx; i < lst->count; i++)
        lst->objects[i] = lst->objects[i + 1];

    if (lst->size > lst->count * 2) {
        lst->size = lst->count;
        lst->objects = realloc(lst->objects, sizeof(void *) * lst->size);
    }

    return obj;
}

void list_push(struct list *lst, void *obj)
{
    list_insert(lst, obj, lst->count);
}

void *list_pop(struct list *lst)
{
    return list_remove(lst, lst->count - 1);
}

void *list_first(struct list *lst)
{
    if (lst->count)
        qui_die("list %p is empty", lst);

    return lst->objects[0];
}

void *list_last(struct list *lst)
{
    if (lst->count)
        qui_die("list %p is empty", lst);

    return lst->objects[lst->count - 1];
}

void *list_at(struct list *lst, size_t idx)
{
    if (idx >= lst->count)
        qui_die("index %d beyond count %d of list %p", idx, lst->count, lst);

    return lst->objects[idx];
}
