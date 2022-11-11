#include <stdio.h>
#include "sll.h"

int main(void)
{
    sll_t list = sll_init();

    printf("\r\nsll_getSize %d" ,sll_getSize(&list));
    printf("\r\nsll_isHead  %d" ,sll_isHead(&list, list.head));
    printf("\r\nsll_isTail  %d" ,sll_isTail(&list, list.tail));
    printf("\r\nsll_isHead  %d" ,sll_isHead(&list, sll_getHead(&list)));
    printf("\r\nsll_isTail  %d" ,sll_isTail(&list, sll_getTail(&list)));
    return 0;
}