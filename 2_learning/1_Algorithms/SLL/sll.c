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

int sll_insertNext(sll_t *sll, void *d)
{
    sllNode_t *nn = (sllNode_t *)malloc(sizeof(sllNode_t));
    nn->data = d;
    nn->next = NULL;
    
    if ( nn == NULL ) {
        return -1;
    }

    if ( sll->size == 0 ) {
        sll->head = nn;
        sll->tail = nn;
    } else {
        sll->tail->next = nn;
        sll->tail = nn;
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