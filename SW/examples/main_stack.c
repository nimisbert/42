#include <stdio.h>
#include <stdint.h>
#include "stack.h"

int8_t stack_uint8_push( Stack *pile, uint8_t  number);
uint8_t stack_uint8_pop( Stack *pile);

void main(void)
{
// Figure 6.1 page 99
    Stack ma_uint8_pile;
// 6.1.(1) 2 elements empiles 
    stack_uint8_push( &ma_uint8_pile, 5 );
    stack_uint8_push( &ma_uint8_pile, 3 );
// 6.1.(2) empile 8, 9 et 2
    stack_uint8_push( &ma_uint8_pile, 8 );
    stack_uint8_push( &ma_uint8_pile, 9 );
    stack_uint8_push( &ma_uint8_pile, 2 );
// 6.1.(3) depile 2 et 9
    printf("Depile %d\r\n", stack_uint8_pop( &ma_uint8_pile ) );
    printf("Depile %d\r\n", stack_uint8_pop( &ma_uint8_pile ) );
    stack_destroy( &ma_uint8_pile );
    return;
}

int8_t stack_uint8_push( Stack *pile, uint8_t number)
{
    uint8_t *data;
    if( (data = (uint8_t*)malloc(sizeof(uint8_t))) == NULL ) {
        return -1;
    }
    *data = number;
    if( stack_push( pile, data) != 0 ) {
        return -1;
    }
    return 0;
}

uint8_t stack_uint8_pop( Stack *pile) 
{
    uint8_t *data, number;
    if( stack_size(pile) == 0 ) {
        return -1;
    } else {
        if( stack_pop( pile, (void **)&data ) != 0 ) {
            return -1;
        } else {
            number = *data;
            free(data);
        }
    }
    return number;
}