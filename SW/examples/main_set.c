#include <stdio.h>
#include "set.h"

typedef struct KSet_ {
    void *cle;
    Set ens;
} KSet;

int set_char_insert  ( Set *ens, char  c);
int set_char_print   ( Set *ens);
int set_char_corresp ( const void *cle1, const void *cle2);

void main(void)
{
// Probleme exemple page 133
    Set S, P, A1, A2, A3, A4, A5, A6, A7;
    set_init( &S , set_char_corresp, free);
    set_init( &P , set_char_corresp, free);
    set_init( &A1, set_char_corresp, free);
    set_init( &A2, set_char_corresp, free);
    set_init( &A3, set_char_corresp, free);
    set_init( &A4, set_char_corresp, free);
    set_init( &A5, set_char_corresp, free);
    set_init( &A6, set_char_corresp, free);
    set_init( &A7, set_char_corresp, free);
    for ( char iter = 'a'; iter <'m'; iter++) {
        set_char_insert( &S,  iter);
        switch ( iter ) {
            case 'a':
                set_char_insert( &A1, iter);
                set_char_insert( &A4, iter);
                break;
            case 'b':
                set_char_insert( &A1, iter);
                set_char_insert( &A5, iter);
                break;
            case 'c':
                set_char_insert( &A1, iter);
                set_char_insert( &A6, iter);
                break;
            case 'd':
                set_char_insert( &A1, iter);
                set_char_insert( &A6, iter);
                break;
            case 'e':
                set_char_insert( &A2, iter);
                set_char_insert( &A4, iter);
                break;
            case 'f':
                set_char_insert( &A2, iter);
                set_char_insert( &A5, iter);
                break;
            case 'g':
                set_char_insert( &A2, iter);
                set_char_insert( &A5, iter);
                set_char_insert( &A6, iter);
                break;
            case 'h':
                set_char_insert( &A2, iter);
                set_char_insert( &A6, iter);
                break;
            case 'i':
                set_char_insert( &A2, iter);
                break;
            case 'j':
                set_char_insert( &A3, iter);
                break;
            case 'k':
                set_char_insert( &A3, iter);
                set_char_insert( &A6, iter);
                break;
            case 'l':
                set_char_insert( &A3, iter);
                set_char_insert( &A6, iter);
                set_char_insert( &A7, iter);
                break;
        }
    }
    printf("Probleme : \r\n");
    printf("S  : ");set_char_print( &S);
    printf("A1 : ");set_char_print( &A1);
    printf("A2 : ");set_char_print( &A2);
    printf("A3 : ");set_char_print( &A3);
    printf("A4 : ");set_char_print( &A4);
    printf("A5 : ");set_char_print( &A5);
    printf("A6 : ");set_char_print( &A6);
    printf("A7 : ");set_char_print( &A7);
    printf("Solution reference :\r\n");
    printf("C  : { A1, A2, A3 }\r\n");
    printf("Solution algorithm :\r\n");
    //ToDo

// Clean
    set_destroy( &S);
    set_destroy( &P);
    set_destroy( &A1);
    set_destroy( &A2);
    set_destroy( &A3);
    set_destroy( &A4);
    set_destroy( &A5);
    set_destroy( &A6);
    set_destroy( &A7);
    return;
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

int set_char_print ( Set *ens)
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

int set_char_corresp( const void *cle1, const void *cle2)
{
    char *a = cle1, *b = cle2;    
    return ( *a == *b ? 1 : 0);
}