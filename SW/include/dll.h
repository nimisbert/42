#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

typedef struct DListElmt_ {
    void *donnee;
    struct DListElmt_ *precedent;
    struct DListElmt_ *suivant;
} DListElmt;

typedef struct DList_ {
    int taille;
    int (*corresp)(const void *val1, const void *val2);
    void (*detruire)(void *donnee);
    DListElmt *tete;
    DListElmt *queue;
} DList;

void dlist_init( DList *liste, void(*detruire)(void *donnee));
void dlist_destroy( DList *liste);

int dlist_ins_next( DList *liste, DListElmt *element, const void *donnee);
int dlist_ins_prev( DList *liste, DListElmt *element, const void *donnee);
int dlist_remove  ( DList *liste, DListElmt *element, void **donnee);

#define dlist_size(liste) ((liste)->taille)
#define dlist_head(liste) ((liste)->tete)
#define dlist_tail(liste) ((liste)->queue)

#define dlist_is_head(element) ((element)->tete == NULL ? 1:0)
#define dlist_is_tail(element) ((element)->queue == NULL ? 1:0)

#define dlist_data(element) ((element)->donnee)
#define dlist_next(element) ((element)->suivant)
#define dlist_prev(element) ((element)->precedent)

#endif
