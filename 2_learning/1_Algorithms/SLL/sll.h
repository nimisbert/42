#ifndef SLL_H
#define SLL_H

#include <stdint.h>
#include <stdbool.h>

typedef struct _sll_node sllNode_t;
struct sllNode_t{
    void *data;
    sllNode_t *next;
};

typedef struct _sll{
    size_t size;
    sllNode_t *head;
    sllNode_t *tail;
}sll_t;

sll_t   sll_init(void);

size_t  sll_getSize(void *sll);

void    sll_insertNext(void *sll, void *n);

#define sll_isHead(l,n) (n == (l)->head ? 1 : 0)
#define sll_isTail(l,n) (n == (l)->tail ? 1 : 0)
#define sll_getHead(l)  ((l)->head)
#define sll_getTail(l)  ((l)->tail)

#endif