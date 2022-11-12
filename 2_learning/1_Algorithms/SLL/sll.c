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

int sll_insertNext(sll_t *sll, sllNode_t *n, void *d)
{
    sllNode_t *nn = (sllNode_t *)malloc(sizeof(sllNode_t));
    nn->data = d;
    nn->next = NULL;
    
    if ( nn == NULL ) {
        return -1;
    }

    if( sll->size == 0 ) {
        sll->head = nn;
        sll->tail = nn;
    } else {
        if ( n == NULL ) {
            nn->next = sll->head;
            sll->head = nn;
        } else {
            if( n == sll->tail ) {
                n->next = nn;
                sll->tail = nn;
            } else {
                nn->next = n->next;
                n-> next = nn;
            }
        }
    }

    sll->size++;
    return 0;
}

int sll_removeNext(sll_t *sll, sllNode_t *n)
{
    sllNode_t *rn;

    if ( n == NULL || n->next == NULL) {
        return -1;
    }

    rn = n->next;
    n-> next = n->next->next;

    free(rn);
    sll->size--;
    return 0;
}

sllNode_t *sll_getNodeFromIndex(sll_t *sll, size_t index)
{
    for(size_t i = 0; i<index; i++){

    }

}