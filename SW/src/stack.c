#include "stack.h"

int stack_push( Stack *pile, const void *donnee)
{
    return list_ins_next( pile, NULL, donnee);
}

int stack_pop( Stack *pile, void **donnee)
{
    return list_rem_next( pile, NULL, donnee);
}