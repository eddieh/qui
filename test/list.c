#include <stdio.h>

#include "qui.h"

int main(int argc, char **argv)
{
    struct list *lst = list_new(1);
    list_push(lst, NULL);
    list_push(lst, NULL);
    printf("lst->count = %zu\n", lst->count);
    return 0;
}
