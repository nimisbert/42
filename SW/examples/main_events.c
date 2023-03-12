#include <stdio.h>
#include <string.h>
#include "queue.h"

typedef char Event;
int receive_event           ( Queue *evts, const Event *evt );
int process_event           ( Queue *evts, int (*aiguiller)(Event *evt));
int aiguillage_print        ( Event *evt );
int aiguillage_printAddOne  ( Event *evt );

void main(void)
{
// Init 
    Queue eventQueue;
    queue_init( &eventQueue, free);
    Event A = 'A';
    Event B = 'B';

// Receive some events 
    receive_event( &eventQueue, &A);
    receive_event( &eventQueue, &B);

// Process some events
    process_event( &eventQueue, aiguillage_print);
    process_event( &eventQueue, aiguillage_printAddOne);

//
    queue_destroy( &eventQueue);
    return;
}

int receive_event( Queue *evts, const Event *evt)
{
    Event *nouv_evt;
    if( (nouv_evt = (Event*)malloc(sizeof(Event))) == NULL ) {
        return -1;
    }
    memcpy( nouv_evt, evt, sizeof(Event));

    if( queue_enqueue( evts, nouv_evt ) != 0 ) {
        return -1;
    }
    return 0;
}

int process_event( Queue *evts, int (*aiguiller)(Event *evt))
{
    Event *evt;
    if( queue_size(evts) == 0 ) {
        return -1;
    } else {
        if( queue_dequeue( evts, (void**)&evt ) != 0 ) {
            return -1;
        } else {
            aiguiller(evt);
            free(evt);
        }
    }
    return 0;
}

int aiguillage_print( Event *evt )
{
    char eventName = (char)*evt;
    printf("Fonction aiguillage event %c\r\n", eventName);
    return 0;
}

int aiguillage_printAddOne( Event *evt )
{
    char eventName = (char)*evt;
    printf("Fonction aiguillage event %c\r\n", eventName+1);
    return 0;
}