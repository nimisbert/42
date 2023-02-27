#include <stdlib.h>
#include <string.h>

#include "sll.h"

void list_init( List *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    return;
}
