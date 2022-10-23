#include <stdio.h>
#include <stddef.h>
#include <assert.h>

// Ooc 
#if ! defined MANY || MANY < 1
#define MANY 10
#endif
static int heap[MANY];
void    *new    (const void *type, ...);
void    delete  (void *item);
int     differ  (const void *a, const void *b); 
// Set 
void    *add    (void *_set, const void *_element);
void    *find   (const void *_set, const void *_element);
int     contains(const void *_set, const void *_element);
void    *drop   ( void *_set, const void *_element);

int main(void)
{
    const void *Set;
    const void *Object;

    void *s = new(Set);
    void *a = add(s, new(Object));
    void *b = add(s, new(Object));
    void *c = new(Object);

    if(contains(s, a) && contains(s, b))
        puts("ok");
    if(contains(s, c))
        puts("contains?");
    if(differ(a, add(s, a)))
        puts("differ?");
    if(contains(s, drop(s, a)))
        puts("drop?");
    delete(drop(s,b));
    delete(drop(s,c));

    return 0;
}

// Ooc

void *new ( const void *type, ...)
{
    int *p;                             // &heap[1..]
    for( p = heap+1; p<heap+MANY; ++p)  // run through heap adresses 
        if ( !*p )                      // if heap content not MANY (?)
            break;                      // break
    assert( p < heap+MANY );            // p is not out of heap address range
    *p = MANY;                          // assign MANY to p
    return p;                           // return p
}

void delete(void *_item)                        // _ArthurDent is generic pointer
{
    int *item = _item;                          // cast to int pointer because dont care about type
    if(item)                                    // if item is not NULL
    {
        assert( item>heap && item<heap+MANY);   // item within heap address range
        * item = 0;                             // recycle heap item
    }
}

int differ(const void *a, const void *b)
{
    return a != b;
}

// Set

void *add( void *_set, const void *_element)
{
    int *set = _set;                                // generic pointer, to pointer with data type of the implementation
    const int *element = _element;                  // idem
    assert( set > heap && set < heap+MANY );        // set object is within heap address range
    assert( *set == MANY );                         // object initialized by containing MANY value
    assert( element > heap && element < heap+MANY );// element object is within heap address range

    if( *element == MANY )                          // if element object content is containing MANY value 
        *(int*) element = set - heap;               // give element content an index in set ?
    else
        assert( *element == set - heap );           // element is the proper index already ?
    return (void *)element;                         // return generic pointer of element
}

void *find( const void *_set, const void *_element)
{
    const int * set = _set;
    const int * element = _element;

    assert( set>heap && set<heap+MANY );
    assert( *set == MANY );
    assert( element > heap && element<heap+MANY );
    assert( *element );

    return *element == set - heap ? (void *)element : 0; // look if contains proper index
}

int contains ( const void *_set, const void *_element)
{
    return find( _set , _element) != 0; // converts find result to int truth
}

void *drop( void *_set, const void *_element)
{
    int *element = find( _set, _element); // check if element is in set
    if(element)                           // if not null
        *element = MANY;                  // replace value index in set with MANY
    return element;                       // return element drop off the set
}
