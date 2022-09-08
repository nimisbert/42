#include <stdio.h>
#include <list.h>

void main(void)
{

    // --- Double linked list UT --- //
    //
    Dlist DL;
    dlist_init(&DL,(void*)free);
    dlist_innext(&DL, NULL, (const void *)5);
    Dnode *dh = list_head(&DL);

    // --- linked list UT --- //
    //
    
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