#include <stdlib.h>
#include <string.h>

#include "sll.h"

void list_init( List *liste, void (*detruire)(void *donnee))
{
    liste->taille = 0;
    liste->detruire = detruire;
    liste->tete = NULL;
    liste->queue = NULL;
    return;
}
