#include <stdio.h>
#include <list.h>

void disp_dlist(Dlist *l);

void main(void)
{
    // --- Double linked list UT --- //
    //
    Dlist DL;
    dlist_init(&DL,(void*)free);
    printf("%s : %s\r\n", "HEAD is NULL", list_isHead(&DL,NULL) ? "PASS":"FAIL");
    printf("%s : %s\r\n", "TAIL is NULL", list_isTail(&DL,NULL) ? "PASS":"FAIL");
    
    dlist_innext(&DL, NULL, (void*)0);
    printf("%s : %s\r\n", "HEAD not NULL", !list_isHead(&DL,NULL) ? "PASS":"FAIL");
    printf("%s : %s\r\n", "TAIL not NULL", !list_isTail(&DL,NULL) ? "PASS":"FAIL");
    printf("%s : %s\r\n", "HEAD is HEAD", list_isHead(&DL,list_head(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "TAIL is TAIL", list_isTail(&DL,list_tail(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "HEAD is TAIL", list_isTail(&DL, list_head(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "TAIL is HEAD", list_isHead(&DL, list_tail(&DL))? "PASS":"FAIL");

    //
    dlist_innext(&DL, NULL, (void*)1);
    printf("%s : %s\r\n", "HEAD not TAIL", list_isTail(&DL, list_head(&DL))? "PASS":"FAIL");
}