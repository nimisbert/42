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
int kset_init        ( KSet *Kens, uint8_t Kkey); 
int kset_destroy     ( KSet *Kens);                
int set_kset_insert  ( Set *ens, KSet *kens);

// Set of char 
int set_char_insert  ( Set *ens, char  c);
int set_char_corresp ( const void *cle1, const void *cle2);

// Cover problem
int set_problem_print( Set *S, Set *P);
int set_cover        ( Set *elements, Set *sous_ens, Set *couverture); 

void main(void)
{
// Init
    Set S, C, P;
    KSet A[7];
    int8_t ret = 0;
    set_init( &S, set_char_corresp, free);
    set_init( &C, set_char_corresp, free);
    set_init( &P, set_char_corresp, free);
    for( int i = 0; i < 7; i++) {
        ret = kset_init( &A[i], i);
    }
    for( int i = 0; i < 7; i++) {
        ret = set_kset_insert( &P, &A[i]);
        printf("Insert A%d in P ret %d\r\n",i,ret);
    }
// State exemple problem page 133
    for( char iter = 'a'; iter < 'm'; iter++) {
        set_char_insert( &S, iter);
        switch( iter ) {
            case 'a':
                set_char_insert( &A[0].ens, iter);
                set_char_insert( &A[3].ens, iter);
                break;
            case 'b':
                set_char_insert( &A[0].ens, iter);
                set_char_insert( &A[4].ens, iter);
                break;
            case 'c':
                set_char_insert( &A[0].ens, iter);
                set_char_insert( &A[5].ens, iter);
                break;
            case 'd':
                set_char_insert( &A[0].ens, iter);
                set_char_insert( &A[5].ens, iter);
                break;
            case 'e':
                set_char_insert( &A[1].ens, iter);
                set_char_insert( &A[3].ens, iter);
                break;
            case 'f':
                set_char_insert( &A[1].ens, iter);
                set_char_insert( &A[4].ens, iter);
                break;
            case 'g':
                set_char_insert( &A[1].ens, iter);
                set_char_insert( &A[4].ens, iter);
                set_char_insert( &A[5].ens, iter);
                break;
            case 'h':
                set_char_insert( &A[1].ens, iter);
                set_char_insert( &A[5].ens, iter);
                break;
            case 'i':
                set_char_insert( &A[1].ens, iter);
                break;
            case 'j':
                set_char_insert( &A[2].ens, iter);
                break;
            case 'k':
                set_char_insert( &A[2].ens, iter);
                set_char_insert( &A[5].ens, iter);
                break;
            case 'l':
                set_char_insert( &A[2].ens, iter);
                set_char_insert( &A[5].ens, iter);
                set_char_insert( &A[6].ens, iter);
                break;
            default:
                break;
        }
    }
// Display problem
    set_problem_print( &S, &P);

// Clean
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
    return 0;
}

int set_kset_insert( Set *ens, KSet *kens)
{
    if( set_insert( ens, kens) != 0) {
        return -1;
    }
    return 0;
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

int set_problem_print( Set *S, Set *P)
{
    ListElmt *elt_iter, *kset_iter;
    char *set_donnee;
    uint8_t *kset_donnee;

    printf("S (Set of elements) : \r\n");
    printf("{ ");
    for( elt_iter = list_head(S); elt_iter != NULL; elt_iter = list_next(elt_iter)) {
        printf("%s",(char*)list_data(elt_iter));
        if( elt_iter->suivant != NULL ) {
            printf(", ");
        } else {
            printf(" ");
        }
    }
    printf("}\r\n");
    printf("P (Set of sets of elements) : \r\n");
    for( kset_iter = list_head(P); kset_iter != NULL; kset_iter = list_next(kset_iter)) {
        kset_donnee = (uint8_t*)((KSet*)kset_iter->donnee)->cle;
        printf("Subset A%d : { ", *kset_donnee);
        for( elt_iter = list_head(&(((KSet*)kset_iter->donnee)->ens)); elt_iter != NULL; elt_iter = list_next( (elt_iter)) ) {
            printf("%s",(char*)list_data(elt_iter));
            if( elt_iter->suivant != NULL ) {
                printf(", ");
            } else {
                printf(" ");
            }
        }
        printf("}\r\n");
    }
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