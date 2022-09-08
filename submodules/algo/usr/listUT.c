#include <stdio.h>
#include <list.h>

void main(void)
{

    List L;
    list_init(&L,(void*)free);

    list_innext(&L, NULL, (const void *)5); 

    Node *h = list_head(&L);

    list_innext(&L, h, (const void*)6);

    Node *t = list_tail(&L);

    void *removedData;

    list_rmnext(&L, h, &removedData);
    
    list_clean(&L);
    
    List L;
    list_init(&L,(void*)free);

    list_innext(&L, NULL, (const void *)5); 

    Node *h = list_head(&L);

    list_innext(&L, h, (const void*)6);

    Node *t = list_tail(&L);

    void *removedData;

    list_rmnext(&L, h, &removedData);
    
    list_clean(&L);

   

    dlist_clean(&DL);

}