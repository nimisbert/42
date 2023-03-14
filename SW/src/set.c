#include "set.h"

void set_init( Set *ens, int (*corresp)(const void *cle1, const void *cle2), void (*detruire)(void *donnee))
{
    list_init(ens, detruire);
    ens->corresp = corresp;
    return;
}

int set_insert( Set *ens, const void *donnee)
{
    if(set_is_member(ens, donnee)) {
        return 1;
    }
    return list_ins_next( ens, list_tail(ens), donnee);
}

int set_remove( Set *ens, void **donnee)
{
    ListElmt *elt, *precedent;
    precedent = NULL;
    for( elt = list_head(ens) ; elt != NULL ; elt = list_next(elt) ) {
        if( ens->corresp( *donnee, list_data(elt))) {
            precedent = elt;
        }
    }
    if( elt == NULL ) {
        return -1;
    }
    return list_rem_next( ens, precedent, donnee);
}

int set_union( Set *ens_u, const Set *ens_1, const Set *ens_2)
{
    ListElmt *elt;
    void *donnee;
    set_init( ens_u, ens_1->corresp, NULL);
    for( elt = list_head(ens_1) ; elt != NULL ; elt = list_next(elt) ) {
        donnee = list_data(elt);
    }
    if( list_ins_next( ens_u, list_tail(ens_u), donnee) != 0) {
        set_destroy(ens_u);
        return -1;
    }
    for( elt = list_head(ens_2) ; elt != NULL ; elt = list_next(elt) ) {
        if( set_is_member( ens_1, list_data(elt) ) ) {
            continue;
        } else {
            donnee = list_data(elt);
            if( list_ins_next( ens_u, list_tail(ens_u), donnee) != 0) {
                set_destroy(ens_u);
                return -1;
            }
        }
    }
    return 0;
}

int set_intersection( Set *ens_i, const Set *ens_1, const Set *ens_2) 
{
    ListElmt *elt;
    void *donnee;
    set_init( ens_i, ens_1->corresp, NULL);
    for( elt = list_head(ens_1); elt != NULL; elt = list_next(elt)) {
        if( set_is_member(ens_2, list_data(elt))) {
            donnee = list_data(elt);
            if( list_ins_next( ens_i, list_tail(ens_i), donnee) != 0) {
                set_destroy(ens_i);
                return -1;
            }
        }
    }
    return 0;
}

int set_difference( Set *ens_d, const Set *ens_1, const Set *ens_2)
{
    ListElmt *elt;
    void *donnee;
    set_init( ens_d, ens_1->corresp, NULL);
    for( elt = list_head(ens_1); elt != NULL; elt = list_next(elt)) {
        if( !set_is_member(ens_2, list_data(elt)) ) {
            donnee = list_data(elt);
            if( list_ins_next(ens_d, list_tail(ens_d), donnee) != 0) {
                set_destroy(ens_d);
                return -1;
            }
        }
    }
    return 0;
}

int set_is_member( const Set *ens, const void *donnee)
{
    ListElmt *elt;
    for( elt = list_head(ens) ; elt != NULL ; elt = list_next(elt) ) {
        if( ens->corresp(donnee, list_data(elt)) ) {
            return 1;
        }
    }
    return 0;
}

int set_is_subset( const Set *ens_1, const Set *ens_2)
{
    ListElmt *elt;
    if( set_size(ens_1) > set_size(ens_2) ) {
        return 0;
    }
    for( elt = list_head(ens_1); elt != NULL; elt = list_next(elt) ) {
        if( !set_is_member(ens_2, list_data(elt))) {
            return 0;
        }
    }
    return 1;
}

int set_is_equal( const Set *ens_1, const Set *ens_2)
{
    if( set_size(ens_1) != set_size(ens_2) ) {
        return 0;
    }
    return set_is_subset(ens_1, ens_2);
}