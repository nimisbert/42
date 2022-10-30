#include <slist.h>

void list_init(List *l, void (*clean) (void *data))
{
    l->size  = 0;
    l->clean = clean;
    l->head  = NULL;
    l->tail  = NULL;
}

void list_clean(List *l)
{
    void *data;
    while(l->size>0)
    {
        if((list_rmnext(l,NULL,(void **)&data) == 0) && (l->clean != NULL))
        {
            l->clean(data);
        }
    }
    //pointer to block of memory, value to fill with, number of bytes to fill
    memset(l,0,sizeof(l));
}

int list_innext(List *l, Node *n, const void *data)
{
    Node *nn; //new node
    //
    if((nn = (Node *)malloc(sizeof(Node)))==NULL)
    {
        return -1;
    }
    nn->data = (void *)data;
    if(n == NULL) // insert as head
    {
        if(l->size == 0)
        {
            l->tail = nn;
        }
        nn->next = l->head;
        l->head = nn;
    }
    else
    {
        if(n->next==NULL)
        {
            l->tail = nn;
        }
        nn->next = n->next;
        n->next = nn;
    }
    l->size++;
    return 0;
}

int list_rmnext(List *l, Node *n, void **data)
{
    Node *rn; //removed node

    if(l->size == 0)
    {
        return -1;
    }

    if(n == NULL)
    {
        *data = l->head->data;
        rn = l->head;
        l->head = l->head->next;
        if(l->size == 1)
        {
            l->tail = NULL;
        }
    }
    else
    {
        if(n->next == NULL)
        {
            return -1;
        }
        *data = n->next->data;
        rn = n->next;
        n->next = n->next->next;
        if(n->next == NULL)
        {
            l->tail = n;
        }
        free(rn);
    }
    l->size--;
    return 0;
}