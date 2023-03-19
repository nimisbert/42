/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#include <stdio.h>
#include <stdint.h>
#include "set.h"

typedef struct KSet_ {
    void *cle;
    Set ens;
} KSet;

// KSet, added layer... so weird
int kset_init        ( KSet *Kens, uint8_t Kkey);   // ToTest
int kset_destroy     ( KSet *Kens);                 // ToDo

int set_char_insert  ( Set *ens, char  c);
int set_char_print   ( Set *ens);
int set_char_corresp ( const void *cle1, const void *cle2);
int set_cover        ( Set *elements, Set *sous_ens, Set *couverture); 

void main(void)
{
    Set S, C, P;
    KSet A[7];
    int8_t ret;
    set_init( &S, set_char_corresp, free);
    set_init( &C, set_char_corresp, free);
    set_init( &P, set_char_corresp, free);
    for( int i = 0; i < 7; i++) {
        ret = kset_init( &A[i], i);
    }

    

    for( int i = 0; i < 7; i++) {
        kset_destroy( &A[i]);
    }
    set_destroy( &S);
    set_destroy( &C);
    set_destroy( &P);
    return;
}

int kset_init( KSet *Kens, uint8_t Kkey)
{
    uint8_t *Kcle;
    if ( (Kcle = (uint8_t*)malloc(sizeof(uint8_t))) == NULL) {
        return -1;
    }
    *Kcle = Kkey;
    Kens->cle = (uint8_t*)Kcle; 
    set_init( &Kens->ens, set_char_corresp, free);
    return 0;
}

int kset_destroy( KSet *Kens)
{
    free( Kens->cle );
    set_destroy( &Kens->ens );
}

int set_char_insert( Set *ens, char c)
{
    char *data;
    if( (data = (char*)malloc(sizeof(char))) == NULL ) {
        return -1;
    }  
    *data = c;
    if( set_insert(ens,data) != 0 ) {
        return -1;
    }
    return 0;
}

int set_char_print( Set *ens)
{
    ListElmt *elt;
    char *donnee;
    printf("{ ");
    for( elt = list_head(ens); elt != NULL; elt = list_next(elt)) {
        printf("%s",(char*)list_data(elt));
        if( elt->suivant != NULL ) {
            printf(", ");
        } else {
            printf(" ");
        }
    }
    printf("}\r\n");
    return 0;
}

int set_cover( Set *elements, Set *sous_ens, Set *couverture)
{
// Set *elements   = S
// Set *sous_ens   = P
// Set *couverture = C
    Set intersection;
    KSet *s_ens;
    ListElmt *elt, *elt_max;
    void *donnee;
    int taille_max;
    set_init( &intersection, sous_ens->corresp, NULL);
    while( (set_size(elements) > 0) && (set_size(sous_ens) > 0) ) {
        taille_max = 0;
        for( elt = list_head(sous_ens); elt != NULL; elt = list_next(elt) ) {
            if( set_intersection( &intersection, &((KSet*)list_data(elt))->ens, elements) != 0 ) {
                return -1;
            }
            if( set_size(&intersection) > taille_max ) {
                elt_max = elt;
                taille_max = set_size(&intersection);
            }
            set_destroy(&intersection);
        }

        if( taille_max == 0 ) {
            return 1;
        }

        s_ens = (KSet *)list_data(elt_max);
        if( set_insert(couverture, s_ens) != 0) {
            return -1;
        }

        for( elt = list_head( &((KSet *)list_data(elt_max))->ens ) ; elt != NULL; elt = list_next(elt) ) {
            donnee = list_data(elt);
            if( set_remove(elements, (void**)&donnee) == 0 && elements->detruire != NULL ) {
                elements->detruire(donnee);
            }
        }

        if( set_remove(sous_ens, (void **)&s_ens) != 0 ) {
            return -1;
        }
    }

    if( set_size(elements) > 0 ) {
        return -1;
    }

    return 0;
}

int set_char_corresp( const void *cle1, const void *cle2)
{
    char *key1 = (char*)cle1, *key2 = (char*)cle2;
    return *key1 == *key2 ? 1 : 0;
}