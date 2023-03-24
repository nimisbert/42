/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>
#include <string.h>
#include "sll.h"

typedef struct CHTbl_ {
    int conteneurs;
    int  (*h)(const void *cle);
    int  (*corresp)(const void *cle1, const void *cle2);
    void (*detruire)(void *donnee);
    int  taille;
    List *table;
} CHTbl;

int chtbl_init( CHTbl *htab, 
                int  conteneurs,
                int  (*h) (const void *cle),
                int  (*corresp) (const void *cle1, const void *cle2),
                void (*detruire)(void *donnee)
               );
void chtbl_destroy( CHTbl *htab);

int chtbl_insert( CHTbl *htab, const void *donnee);
int chtbl_remove( CHTbl *htab, void **donnee);
int chtbl_lookup( const CHTbl *htab, void **donnee);

#define chtbl_size(htab) ((htab)->taille);

#endif