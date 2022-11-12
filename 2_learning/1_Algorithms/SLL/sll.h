#ifndef SLL_H
#define SLL_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct _sllNode{
    void *data;
    struct _sllNode *next;
}sllNode_t;

typedef struct _sll{
    size_t size;
    sllNode_t *head;
    sllNode_t *tail;
}sll_t;

sll_t   sll_init(void);
void    sll_clean(void);

int     sll_insertNext(sll_t *sll, sllNode_t *n, void *d);
int     sll_removeNext(sll_t *sll, sllNode_t *n);

sllNode_t *sll_getNodeFromIndex(sll_t *sll, size_t i);

#endif