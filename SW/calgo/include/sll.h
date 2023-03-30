/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct ListElmt_ {
    void *donnee;
    struct ListElmt_ *suivant;
} ListElmt;

typedef struct List_ {
    int     taille;
    int     (*corresp)(const void *val1, const void *val2);
    void    (*detruire)(void *donnee);
    ListElmt *tete;
    ListElmt *queue;
} List;

void list_init      ( List *liste, void (*detruire)(void *donnnee));
void list_destroy   ( List *liste);
int  list_ins_next  ( List *liste, ListElmt *element, const void *donnee);
int  list_rem_next  ( List *liste, ListElmt *element, void **donnee);

#define list_size(liste)                ((liste)->taille)
#define list_head(liste)                ((liste)->tete)
#define list_tail(liste)                ((liste)->queue)
#define list_is_head(liste, element)    ((element) == (liste)->head ? 1 : 0)
#define list_is_tail(element)           ((element)->suivant == NULL ? 1 : 0)
#define list_data(element)              ((element)->donnee)
#define list_next(element)              ((element)->suivant)

#endif
