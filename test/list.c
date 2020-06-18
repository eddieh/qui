#include <stdio.h>

#include "qui.h"

int main(int argc, char **argv)
{
    QuList *lst = list_new(1);
    list_push(lst, NULL);
    list_push(lst, NULL);
    printf("lst->count = %zu\n", list_count(lst));
    return 0;
}
