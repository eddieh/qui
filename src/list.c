#include <stdlib.h>

#include "list.h"
#include "util.h"

struct QuList {
    size_t count;
    size_t size;
    void **objects;
};

QuList *QuListA(size_t size)
{
    QuList *lst = malloc(sizeof(QuList));
    lst->count = 0;
    lst->size = size ? size * 2 : 4;
    lst->objects = calloc(lst->size, sizeof(void *));
    return lst;
}

void list_insert(QuList *lst, void *obj, size_t idx)
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

void *list_remove(QuList *lst, size_t idx)
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

void list_push(QuList *lst, void *obj)
{
    list_insert(lst, obj, lst->count);
}

void *list_pop(QuList *lst)
{
    return list_remove(lst, lst->count - 1);
}

void *list_first(QuList *lst)
{
    if (lst->count)
        qui_die("list %p is empty", lst);

    return lst->objects[0];
}

void *list_last(QuList *lst)
{
    if (lst->count)
        qui_die("list %p is empty", lst);

    return lst->objects[lst->count - 1];
}

void *list_at(QuList *lst, size_t idx)
{
    if (idx >= lst->count)
        qui_die("index %d beyond count %d of list %p", idx, lst->count, lst);

    return lst->objects[idx];
}

size_t list_count(QuList *lst)
{
    return lst->count;
}
