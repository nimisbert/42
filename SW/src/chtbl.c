#include "chtbl.h"

int chtbl_init( CHTbl *htab, 
                int  conteneurs,
                int  (*h) (const void *cle),
                int  (*corresp) (const void *cle1, const void *cle2),
                void (*detruire)(void *donnee)
               )
{
    if( (htab->table = (List *)malloc(conteneurs * sizeof(List))) == NULL) {
        return -1;
    }
    htab->conteneurs = conteneurs;
    for( int i = 0; i < htab->conteneurs; i++) {
        list_init( &htab->table[i], detruire);
    }
    htab->h = h;
    htab->corresp = corresp;
    htab->detruire = detruire;
    htab->taille = 0;
    return 0;
}

void chtbl_destroy( CHTbl *htab)
{
    for ( int i = 0; i < htab->conteneurs; i++) {
        list_destroy( &htab->table[i]);
    }
    free(htab->table);
    memset( htab, 0, sizeof(CHTbl));
    return;
}

int chtbl_insert( CHTbl *htab, const void *donnee) 
{
    void *temp;
    int conteneur, retval;
    temp = (void*)donnee;
    if ( chtbl_lookup(htab, &temp) == 0) {
        return 1;
    }
    conteneur = htab->h(donnee) % htab->conteneurs;
    if( (retval = list_ins_next(&htab->table[conteneur], NULL, donnee)) == 0 ) {
        htab->taille++;
    }
    return retval;
}

int chtbl_remove( CHTbl *htab, void **donnee)
{
    ListElmt *element, *prec;
    int conteneur = htab->h(*donnee) % htab->conteneurs;
    prec = NULL;
    for( element = list_head( &htab->table[conteneur]); element != NULL; element = list_next(element)) {
        if ( htab->corresp(*donnee, list_data(element))) {
            if ( list_rem_next( &htab->table[conteneur], prec, donnee) == 0) {
                htab->taille--;
                return 0;
            } else {
                return -1;
            }
        }
        prec = element;
    }
    return -1;
}

int chtbl_lookup( const CHTbl *htab, void **donnee)
{
    ListElmt *element;
    int conteneur;
    conteneur = htab->h(*donnee) % htab->conteneurs;
    for( element = list_head(&htab->table[conteneur]); element != NULL; element = list_next(element)) {
        if( htab->corresp(*donnee, list_data(element))) {
            *donnee = list_data(element);
            return 0;
        }
    }
    return -1;
}