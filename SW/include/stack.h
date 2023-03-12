#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "sll.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy

int stack_push( Stack *pile, const void *donnee);
int stack_pop ( Stack *pile, void **donnee);

#define stack_peek(pile) ((pile)->tete == NULL ? NULL : (pile)->tete->donnee)
#define stack_size list_size

#endif