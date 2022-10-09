#include <stdio.h>
#include <list.h>

void disp_dlist(Dlist *l);

void main(void)
{
    // --- Double linked list UT --- //
    // dlist_init
    Dlist DL;
    dlist_init(&DL,(void*)free);
    printf("%s : %s\r\n", "[dlist_init] initial size == 0", !DL.size ? "PASS":"FAIL");
    printf("%s : %s\r\n", "[dlist_init] tail == NULL", DL.tail==NULL ? "PASS":"FAIL");
    printf("%s : %s\r\n", "[dlist_init] head == NULL", DL.head==NULL ? "PASS":"FAIL");
    // dlist_innext
    printf("%s : %s\r\n", "[dlist_innext] NULL & size  0", dlist_innext(&DL, NULL, (void*)0)!=-1 ? "PASS":"FAIL");
    printf("%s : %s\r\n", "[dlist_innext] NULL & size !0", dlist_innext(&DL, NULL, (void*)0)==-1 ? "PASS":"FAIL");
    printf("%s : %s\r\n", "[dlist_innext] NULL inst NULL", dlist_innext(&DL, NULL, NULL)==-1 ? "PASS":"FAIL");
    // dlist_clean
    dlist_clean(&DL);
    printf("%s : %s\r\n", "[dlist_clean] size != 0 clean", DL.size==0 ? "PASS":"FAIL");
    // dlist_inprev
    printf("%s : %s\r\n", "[dlist_inprev] NULL & size  0", dlist_inprev(&DL, NULL, (void*)0)!=-1? "PASS":"FAIL");
    printf("%s : %s\r\n", "[dlist_inprev] NULL & size !0", dlist_inprev(&DL, NULL, (void*)0)==-1? "PASS":"FAIL");
    printf("%s : %s\r\n", "[dlist_inprev] NULL inst NULL", dlist_inprev(&DL, NULL, NULL)==-1 ? "PASS":"FAIL");
    dlist_inprev(&DL, list_head(&DL), (void*)1);
    // head and tail integrity
    printf("%s : %s\r\n", "[list_isHead] head is HEAD", list_isHead(&DL, list_head(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "[list_isTail] tail is TAIL", list_isTail(&DL, list_tail(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "[list_isHead] head not TAIL", !list_isTail(&DL, list_head(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "[list_isTail] tail not HEAD", !list_isHead(&DL, list_tail(&DL))? "PASS":"FAIL");
    // dlist_remove
    void *d0;
    printf("%s : %s\r\n", "[dlist_remove] NULL node", dlist_remove(&DL, NULL, &d0)==-1? "PASS":"FAIL");
    printf("%s : %s\r\n", "[dlist_remove] remove node", !dlist_remove(&DL, list_head(&DL), &d0)? "PASS":"FAIL");
}