/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#include <stdio.h>
#include <stdint.h>

#include "queue.h"

int8_t queue_uint8_push( Queue *file, uint8_t number);
uint8_t queue_uint8_pop( Queue *file ); 

void main(void)
{
// Figure 6.2 page 104
    Queue ma_uint8_queue;
    queue_init( &ma_uint8_queue, free);

// 6.2.(1) 
    queue_uint8_push( &ma_uint8_queue, 5);
    queue_uint8_push( &ma_uint8_queue, 3);
    uint8_t *temp = queue_peek( &ma_uint8_queue);
    printf("peeked : %d\r\n",*temp);

// 6.2.(2) 
    queue_uint8_push( &ma_uint8_queue, 8);
    queue_uint8_push( &ma_uint8_queue, 9);
    queue_uint8_push( &ma_uint8_queue, 2);

// 6.2.(3)
    printf("pop : %d\r\n", queue_uint8_pop( &ma_uint8_queue ) );
    printf("pop : %d\r\n", queue_uint8_pop( &ma_uint8_queue ) );
    temp = queue_peek( &ma_uint8_queue);
    printf("peeked : %d\r\n",*temp);
//
    queue_destroy( &ma_uint8_queue );
    return;
}

int8_t queue_uint8_push( Queue *file, uint8_t number)
{
    uint8_t *data;
    if( (data = (uint8_t*)malloc(sizeof(uint8_t))) == NULL ) {
        return -1;
    }

    *data = number;
    if( queue_enqueue( file, data ) != 0 ) {
        return -1;
    }
    return 0;
}

uint8_t queue_uint8_pop( Queue *file) 
{
    uint8_t *data, number;
    if( queue_size( file ) == 0 ) {
        return -1;
    } else {
        if ( queue_dequeue( file, (void **)&data ) != 0 ) {
            return -1;
        } else {
            number = *data;
            free(data);
        }
    }
    return number;
}