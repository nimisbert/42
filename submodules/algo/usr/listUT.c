#include <stdio.h>
#include <list.h>

void main(void)
{

    List L;
    list_init(&L,(void*)free);

    // --- Double linked list UT --- //
    //
    Dlist DL;
    dlist_init(&DL,(void*)free);
    dlist_innext(&DL, NULL, (const void *)5);
    Dnode *dh = list_head(&DL);
// --- Double linked list UT --- //
    //
    Dlist DL;
    dlist_init(&DL,(void*)free);
    dlist_innext(&DL, NULL, (const void *)5);
    Dnode *dh = list_head(&DL);
// --- Double linked list UT --- //
    //
    Dlist DL;
    dlist_init(&DL,(void*)free);
    dlist_innext(&DL, NULL, (const void *)5);
    Dnode *dh = list_head(&DL);

   

    dlist_clean(&DL);

}