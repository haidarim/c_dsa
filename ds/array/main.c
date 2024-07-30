#include <stdio.h>
#include "array_list.h"

int main(void)
{
    LinkedList *l = createLinkedList();
    add_head(l, "1");
    add_head(l, "2");
    add_head(l, "3");
    add_head(l, "4");
    add_head(l, "5");
    add_head(l, "6");

    for (int i = 0; i < 6; i++)
    {
        printf("The current index %d is: %s\n", i, (char *)l_get(l, i));
    }

    freeList(l);
    return 0;
}
