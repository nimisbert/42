#include <stdio.h>
#include "sll.h"

void print_sll_int(sll_t *list);
void print_sll_node_int(sllNode_t *node);

int main(void)
{
    sll_t list = sll_init();

    printf("\r\ninsert next %d",sll_insertNext(&list, NULL, (void*)0));
    printf("\r\nsize %d", list.size);

    printf("\r\ninsert next %d",sll_insertNext(&list, NULL, (void*)1));
    printf("\r\nsize %d", list.size);

    printf("\r\ninsert next %d",sll_insertNext(&list, NULL, (void*)2));
    printf("\r\nsize %d", list.size);

    print_sll_node_int(list.tail);

    print_sll_int(&list);

    sll_removeNext(&list, list.head);
    printf("\r\ninsert next %d",sll_insertNext(&list, list.head, (void*)1));
    printf("\r\nsize %d", list.size);

    printf("\r\ninsert next %d",sll_insertNext(&list, list.tail, (void*)-1));
    printf("\r\nsize %d", list.size);

    printf("\r\ninsert next %d",sll_insertNext(&list, list.tail, (void*)-2));
    printf("\r\nsize %d", list.size);

    printf("\r\ninsert next %d",sll_insertNext(&list, NULL, (void*)3));
    printf("\r\nsize %d", list.size);

    print_sll_int(&list);

    return 0;
}


void print_sll_node_int(sllNode_t *node)
{
    printf("\r\n [%d | %p]",node->data, node);
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