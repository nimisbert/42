/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#include "queue.h"

int queue_enqueue( Queue *file, const void *donnee)
{
    return list_ins_next( file, list_tail(file), donnee);
}

int queue_dequeue( Queue *file, void **donnee)
{
    return list_rem_next( file, NULL, donnee);
}