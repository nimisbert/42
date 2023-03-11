#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>
#include <string.h>

typedef struct CListElmt_ {
    void                *donnee;
    struct CListElmt_   *suivant;
}CListElmt;

typedef struct CList_ {
    int         taille;
    int         (*corresp)(const void *val1, const void *val2);
    void        (*detruire) (void *donnee);
    CListElmt   *tete;
}CList;

void clist_init    ( CList *liste, void (*detruire)(void *donnee));
void clist_destroy ( CList *liste);
int  clist_ins_next( CList *liste, CListElmt *element, const void *donnee);
int  clist_rem_next( CList *liste, CListElmt *element, void **donnee);

#define clist_size(liste) ((liste)->taille)
#define clist_head(liste) ((liste)->tete)
#define clist_data(element) ((element)->donnee)
#define clist_next(element) ((element)->suivant)

#endif
