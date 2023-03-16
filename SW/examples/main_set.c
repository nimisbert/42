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
int Kset_init        ( KSet *Kens, uint8_t Kkey);   // ToTest
int Kset_destroy     ( KSet *Kens);                 // ToDo

int set_char_insert  ( Set *ens, char  c);
int set_char_print   ( Set *ens);
int set_char_corresp ( const void *cle1, const void *cle2);
int set_cover        ( Set *elements, Set *sous_ens, Set *couverture); 

void main(void)
{
// Probleme exemple page 133
    Set S, P, C;
    KSet A1, A2, A3, A4, A5, A6, A7;
    set_init( &S , set_char_corresp, free);
    set_init( &P , set_char_corresp, free);
    set_init( &C , set_char_corresp, free);
    Kset_init( &A1, 1);
    Kset_init( &A2, 2);
    Kset_init( &A3, 3);
    Kset_init( &A4, 4);
    Kset_init( &A5, 5);
    Kset_init( &A6, 6);
    Kset_init( &A7, 7);
    
    for ( char iter = 'a'; iter <'m'; iter++) {
        set_char_insert( &S,  iter);
        switch ( iter ) {
            case 'a':
                set_char_insert( &A1.ens, iter);
                set_char_insert( &A4.ens, iter);
                break;
            case 'b':
                set_char_insert( &A1.ens, iter);
                set_char_insert( &A5.ens, iter);
                break;
            case 'c':
                set_char_insert( &A1.ens, iter);
                set_char_insert( &A6.ens, iter);
                break;
            case 'd':
                set_char_insert( &A1.ens, iter);
                set_char_insert( &A6.ens, iter);
                break;
            case 'e':
                set_char_insert( &A2.ens, iter);
                set_char_insert( &A4.ens, iter);
                break;
            case 'f':
                set_char_insert( &A2.ens, iter);
                set_char_insert( &A5.ens, iter);
                break;
            case 'g':
                set_char_insert( &A2.ens, iter);
                set_char_insert( &A5.ens, iter);
                set_char_insert( &A6.ens, iter);
                break;
            case 'h':
                set_char_insert( &A2.ens, iter);
                set_char_insert( &A6.ens, iter);
                break;
            case 'i':
                set_char_insert( &A2.ens, iter);
                break;
            case 'j':
                set_char_insert( &A3.ens, iter);
                break;
            case 'k':
                set_char_insert( &A3.ens, iter);
                set_char_insert( &A6.ens, iter);
                break;
            case 'l':
                set_char_insert( &A3.ens, iter);
                set_char_insert( &A6.ens, iter);
                set_char_insert( &A7.ens, iter);
                break;
        }
    }

    printf("Probleme : \r\n");
    printf("S  : ");set_char_print( &S);
    printf("P  : { ");
    for( int i = 1; i < 8; i++) {
        i == 7 ? printf("A%d }\r\n",i) : printf("A%d, ",i);
    }
    printf("A1 : ");set_char_print( &A1.ens);
    printf("A2 : ");set_char_print( &A2.ens);
    printf("A3 : ");set_char_print( &A3.ens);
    printf("A4 : ");set_char_print( &A4.ens);
    printf("A5 : ");set_char_print( &A5.ens);
    printf("A6 : ");set_char_print( &A6.ens);
    printf("A7 : ");set_char_print( &A7.ens);
    printf("Solution reference :\r\n");
    printf("C  : { A1, A2, A3 }\r\n");
    printf("Solution algorithm :\r\n");
//   set_cover( &S, &P, &C);

// Clean
    set_destroy( &S);
    set_destroy( &P);
    set_destroy( &A1.ens);
    set_destroy( &A2.ens);
    set_destroy( &A3.ens);
    set_destroy( &A4.ens);
    set_destroy( &A5.ens);
    set_destroy( &A6.ens);
    set_destroy( &A7.ens);
    return;
}

int Kset_init( KSet *Kens, uint8_t Kkey)
{
    uint8_t *Kcle; *Kcle = Kkey;
    if ( (Kens->cle = (uint8_t*)malloc(sizeof(uint8_t))) == NULL) {
        return -1;
    }
    Kens->cle = (void *)Kcle;
    set_init( &Kens->ens, set_char_corresp, free);
    return 0;
}

int Kset_destroy( KSet *Kens);

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
    *key1 == *key2 ? 1 : 0;
}