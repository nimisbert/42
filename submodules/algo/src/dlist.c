#include <dlist.h>

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
        l->head = nn;
        l->head->prev = NULL;
        l->head->next = NULL;
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
    if((n == NULL) && (list_size(l)!=0))
    {
        return -1;
    }
    if((nn = (Dnode *)malloc(sizeof(Dnode))) == NULL)
    {
        return -1;
    }
    nn->data = (void *)data;
    if(list_size(l) == 0)
    {
        l->head = nn;
        l->head->prev = NULL;
        l->head->next = NULL;
        l->tail = nn;
    }
    else
    {
        nn->next = n;
        nn->prev = n->prev;
        if(n->prev == NULL)
        {
            l->head = nn;
        }
        else
        {
            n->prev->next = nn;
        }
        n->prev = nn;
    }
    l->size++;
    return 0;
}

int dlist_remove(Dlist *l, Dnode *n, void **data)
{
    Dnode *rn; //removed node
    if((l->size == 0)||(n==NULL))
    {
        return -1;
    }
    else
    {
        rn = n;
        *data = n->data;
 
        if(n == l->head)
        {
            l->head = n->next;
            if(l->head == NULL)
            {
                l->tail = NULL;
            }
            else
            {
                n->next->prev = NULL;
            }
        }
        else
        {
            n->prev->next = n->next;

            if(n->next == NULL)
            {
                l->tail = n->prev;
            }
            else
            {
                n->next->prev = n->prev;
            }
        }
    }
    free(n);
    l->size--;
    return 0;
}