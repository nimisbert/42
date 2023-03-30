/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "sll.h"

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy

int queue_enqueue( Queue *file, const void *donnee);
int queue_dequeue( Queue *file, void **donnee);

#define queue_peek(file) ((file)->tete == NULL ? NULL : (file)->tete->donnee)
#define queue_size list_size

#endif