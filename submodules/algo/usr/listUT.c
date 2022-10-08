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
    printf("%s : %s\r\n", "VIABLE INSERT", dlist_innext(&DL, NULL, (void*)0)==0 ? "PASS":"FAIL");
    printf("%s : %s\r\n", "HEAD not NULL", !list_isHead(&DL,NULL) ? "PASS":"FAIL");
    printf("%s : %s\r\n", "TAIL not NULL", !list_isTail(&DL,NULL) ? "PASS":"FAIL");
    printf("%s : %s\r\n", "HEAD is HEAD", list_isHead(&DL,list_head(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "TAIL is TAIL", list_isTail(&DL,list_tail(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "HEAD is TAIL", list_isTail(&DL, list_head(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "TAIL is HEAD", list_isHead(&DL, list_tail(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "NON VIABLE INSERT",dlist_innext(&DL, NULL, (void*)1)==-1 ? "PASS":"FAIL");
    printf("%s : %s\r\n", "SECOND VIABLE INSERT", dlist_innext(&DL, list_head(&DL), (void*)1)==0 ? "PASS":"FAIL");
    printf("%s : %s\r\n", "HEAD NOT TAIL", !list_isTail(&DL, list_head(&DL))? "PASS":"FAIL");
    printf("%s : %s\r\n", "TAIL NOT HEAD", !list_isHead(&DL, list_tail(&DL))? "PASS":"FAIL");

}