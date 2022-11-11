#include <stdio.h>
#include "sll.h"

void print_sll_int(sll_t *list);

int main(void)
{
    sll_t list = sll_init();

    printf("\r\ninsert next %d",sll_insertNext(&list, (void*)0));
    printf("\r\nsize %d", list.size);

    printf("\r\ninsert next %d",sll_insertNext(&list, (void*)1));
    printf("\r\nsize %d", list.size);

    printf("\r\ninsert next %d",sll_insertNext(&list, (void*)2));
    printf("\r\nsize %d", list.size);

    print_sll_int(&list);

    sll_removeNext(&list, list.head);

    print_sll_int(&list);

    return 0;
}

void print_sll_int(sll_t *list)
{
    sllNode_t *node = list->head;
    printf("\r\nList display as integers :");
    if(node != NULL){
        do{
            printf("\r\n [%d | %p] ->", node->data, node);
            node = node->next;
        }while( node->next != NULL );
        printf("\r\n [%d | %p] -> \r\n NULL", node->data, node);
    }
}