/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#include <stdio.h>

#include "../include/sll.h"

int alloc_frame(List *frames);
int free_frame(List *frames, int frame_number);

int main(void)
{
// INIT
    const int numFrames = 5;
    List myFrames;
    list_init( &myFrames, free);
// Allocate available ("free") frames 
    for( int i = 0; i < numFrames; i++) {
       printf("Insert frame %d resulted %d\r\n", i, free_frame( &myFrames, i)); 
    }
// Retrieve available frames "become allocated to this program"
    for( int i = 0; i < numFrames; i++) {
        printf("Retrieve frame resulted %d\r\n", alloc_frame( &myFrames));
    }
// EXIT
    list_destroy( &myFrames);
    return 0;
}

int alloc_frame(List *frames)
{
    int frame_number, *data;

    if( list_size(frames) == 0) {
        return -1;
    } else {
        if( list_rem_next( frames, NULL, (void **)&data) != 0 ) {
            return -1;
        } else {
            frame_number = *data;
            free(data);
        }
    }
    return frame_number;
}

int free_frame(List *frames, int frame_number)
{
    int *data;
    if( (data = (int*)malloc(sizeof(int))) == NULL ) {
        return -1;
    }

    *data = frame_number;
    if( list_ins_next( frames, NULL, data) != 0) {
        return -1;
    }
    return 0;
}
