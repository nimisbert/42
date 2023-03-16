/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#include <stdint.h>
#include <stdio.h>
#include "../include/cll.h"

typedef struct Page_ {
    int numero;
    int reference;
} Page;

int insert_page ( CList *pages, int page_number);
int replace_page( CListElmt **courant);

int main(void) 
{
// INIT
    CList Pages;
    clist_init( &Pages, free);
    int8_t retVal;

//
    for( int i=0; i<5; i++) {
        retVal = insert_page( &Pages, i);
        printf("Insert page %d resulted in %d\r\n", i, retVal);
    }
    for( int i=0; i<5; i++) {
        retVal = replace_page( &clist_head(&Pages) );
        printf("Replace page %d resulted in %d\r\n",i,retVal);
    }
    clist_destroy( &Pages);
    return 0;
}

int insert_page( CList *pages, int page_number)
{
    Page *data;
    if( (data = (Page*)malloc(sizeof(Page))) == NULL) {
        return -1;
    }
    data->numero = page_number;
    data->reference = 0;
    if( clist_ins_next( pages, clist_head(pages), data ) != 0) {
        return -1;
    }
    return 0;
}

int replace_page( CListElmt **courant)
{
    while( ((Page *)((*courant)->donnee))->reference != 0) {
        ((Page *)(*courant)->donnee)->reference = 0;
        *courant = clist_next(*courant);
    }
    return ((Page *)(*courant)->donnee)->numero;
}

