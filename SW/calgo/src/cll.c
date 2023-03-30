/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#include "cll.h"

void clist_init( CList *liste, void (*detruire)( void *donnee))
{
    liste->taille = 0;
    liste->detruire = detruire;
    liste->tete = NULL;
    return;
}

void clist_destroy( CList *liste) 
 {
    void *donnee;
    while( clist_size(liste) > 0 ) {
        if( (clist_rem_next( liste, liste->tete, (void**)&donnee) == 0) && (liste->detruire != NULL) ) {
            liste->detruire(donnee);
        }
    }
    memset(liste, 0, sizeof(CList));
    return;    
}

int clist_ins_next( CList *liste, CListElmt *element, const void *donnee)
{
    CListElmt *nouv_element;
    if((nouv_element = (CListElmt *)malloc(sizeof(CListElmt))) == NULL ) {
        return -1;
    }
    nouv_element->donnee = (void*)donnee;
    
    if( clist_size(liste) == 0 ) {
        nouv_element->suivant = nouv_element;
        liste->tete = nouv_element;
    } else {
        nouv_element->suivant = element->suivant;
        element->suivant = nouv_element;
    }
    liste->taille++;
    return 0;
}

int clist_rem_next( CList *liste, CListElmt *element, void **donnee) 
{
    CListElmt *ancien_element;
    if( clist_size(liste) == 0) {
        return -1;
    }
    *donnee = element->suivant->donnee;

    if( element->suivant == element) {
        ancien_element = element->suivant;
        liste->tete = NULL;
    } else {
        ancien_element = element->suivant;
        element->suivant = element->suivant->suivant;
    }
    
    free(ancien_element);
    liste->taille--;
    return 0;
}
