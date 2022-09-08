#include <list.h>

 // --- linked list --- //

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

// --- double linked list --- //

void dlist_init(Dlist *l, void (*clean) (void *data))
{
    l->size = 0;
    l->clean = clean;
    l->tail = NULL;
    l->head = NULL;
}

void dlist_clean(Dlist *l)
{
    void *data;
    while(l->size>0)
    {
        if( (dlist_remove(l, list_head(l), (void **)&data) == 0) && (l->clean != NULL) ) //
        {
            l->clean(data);
        }
    }
    memset(l,0,sizeof(l));
}

int dlist_innext(Dlist *l, Dnode *n, const void *data)
{
    Dnode *nn; // new node 
    //
    if((n == NULL) && (list_size(l)!=0))
    {
        return -1;
    }
    if((nn = (Dnode *)malloc(sizeof(Dnode))) == NULL)
    {
        return -1;
    }
    nn->data = (void *)data;
    if(list_size(l) == 0) // empty list
    {
        nn->next = NULL;
        nn->prev = NULL;
        l->head = nn;
        l->tail = nn;
    }
    else
    {
        nn->next = n->next;
        nn->prev = n;
        if(n->next == NULL)
        {
            l->tail = nn;
        }
        else
        {
            n->next->prev = nn;
        }
        n->next = nn;
    }
    l->size++;
    return 0;
}

int dlist_inprev(Dlist *l, Dnode *n, const void *data)
{
    Dnode *nn; // new node
    //
    if((nn = (Dnode *)malloc(sizeof(Dnode))) == NULL)
    {
        return -1;
    }
    nn->data = (void *)data;

    l->size++;
    return 0;
}

int dlist_remove(Dlist *l, Dnode *n, void **data)
{
    Dnode *rn; //removed node
    if(l->size == 0)
    {
        return -1;
    }

    if(n == NULL)
    {
        return -1;
    }
    else
    {
        *data = n->data;
        rn = n;
        n->prev->next = n->next;
        if(n->next == NULL)
        {
            l->tail = n->prev;
        }

        n->next->prev = n->prev;
        if(n->prev == NULL)
        {
            l->head = n->next;
        }
        free(rn);
    }
    l->size--;
    return 0;
}