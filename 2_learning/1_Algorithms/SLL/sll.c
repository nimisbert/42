#include "sll.h"

sll_t sll_init(void)
{
    sll_t l = {
        .size = 0, 
        .tail = NULL,
        .head = NULL
    };
    return l;
}

size_t sll_getSize(void *sll)
{
    sll_t l = *(sll_t*)sll;
    return l.size;
}

void sll_insertNext(void *sll, void *n)
{
    sll_t l = *(sll_t*)sll;
    if(l.size == 0)
    {
    }
}