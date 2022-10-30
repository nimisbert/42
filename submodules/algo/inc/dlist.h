#ifndef DLIST_H
#define DLIST_H
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
//
#define list_size(l) ((l)->size)

#define list_head(l) ((l)->head)
#define list_tail(l) ((l)->tail)

#define list_isHead(l,n) (n == (l)->head ? 1 :0)
#define list_isTail(l,n) (n == (l)->tail ? 1 :0)

#define list_data(n) ((n)->data)
#define list_next(n) ((n)->next)
#define list_prev(n) ((n)->prev)

// --- double linked list --- //

typedef struct dnode{
    void *data;
    struct dnode *next;
    struct dnode *prev;
}Dnode;

typedef struct dlist{
    int size;
    void(*clean)(void *data);
    Dnode *head;
    Dnode *tail;
}Dlist;

void dlist_init(Dlist *l, void (*clean) (void *data));
void dlist_clean(Dlist *l);

int dlist_innext(Dlist *l, Dnode *n, const void *data);
int dlist_inprev(Dlist *l, Dnode *n, const void *data);
int dlist_remove(Dlist *l, Dnode *n, void **data);

#endif