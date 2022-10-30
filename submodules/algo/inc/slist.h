#ifndef SLIST_H
#define SLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define list_size(l) ((l)->size)

#define list_head(l) ((l)->head)
#define list_tail(l) ((l)->tail)

#define list_isHead(l,n) (n == (l)->head ? 1 :0)
#define list_isTail(l,n) (n == (l)->tail ? 1 :0)

#define list_data(n) ((n)->data)
#define list_next(n) ((n)->next)

typedef struct node{
    void *data;
    struct node *next;
}Node;

typedef struct list{
    int size;
    void(*clean)(void *data);
    Node *head;
    Node *tail;
}List;

void list_init(List *l, void (*clean) (void *data));
void list_clean(List *l);

int list_innext(List *l, Node *n, const void *data);
int list_rmnext(List *l, Node *n, void **data);

#endif