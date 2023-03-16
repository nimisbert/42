/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include <string.h>
#include "sll.h"

typedef List Set;

void set_init(  Set *ens, 
                int(*corresp)(const void *cle1, const void *cle2),
                void(*detruire)(void *donnee) );

#define set_destroy list_destroy;

int set_insert( Set *ens, const void *donnee);
int set_remove( Set *ens, void **donnee);

int set_union       ( Set *ens_u, const Set *ens_1, const Set *ens_2);
int set_intersection( Set *ens_i, const Set *ens_1, const Set *ens_2);
int set_difference  ( Set *ens_d, const Set *ens_1, const Set *ens_2);

int set_is_member( const Set *ens, const void *donnee);
int set_is_subset( const Set *ens_1, const Set *ens_2);
int set_is_equal ( const Set *ens_1, const Set *ens_2);

#define set_size(ens) ((ens)->taille)

#endif