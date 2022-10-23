#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

// Ooc 
struct  Object  { unsigned count; struct Set *in;};
void    *new    (const void *type, ...);
void    delete  (void *item);
int     differ  (const void *a, const void *b); 

// Set 
struct  Set     { unsigned count;};
void    *add    (void *_set, const void *_element);
void    *find   (const void *_set, const void *_element);
int     contains(const void *_set, const void *_element);
void    *drop   ( void *_set, const void *_element);
unsigned count  (void *_set);

int main(void)
{
    static const size_t _Set = sizeof(struct Set);
    static const size_t _Object = sizeof(struct Object);

    const void *Set = &_Set;
    const void *Object = &_Object;

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

void *new( const void *type, ...)
{
    const size_t size = *(const size_t*) type;
    void *p = calloc(1, size);
    assert(p);
    return p;
}

void delete(void *_item)
{
    free(_item);
}

int differ(const void *a, const void *b)
{
    return a != b;
}

// Set

void *add( void *_set, const void *_element)
{
    struct Set *set = _set;                    // cast from generic to set struct
    struct Object *element = (void*) _element; // cast from generic to object struct
    assert(set);
    assert(element);

    if( !element->in )                // element 
        element->in = set;            // assign set to belong to
    else
        assert(element->in == set);   // already in set
    element->count++, set->count++;   // increment element and set count
    return element;
}

void *find( const void *_set, const void *_element)
{
    const struct Object *element = _element;
    assert(_set);
    assert(element);
    return element->in == _set ? (void*)element : 0;
}

int contains ( const void *_set, const void *_element)
{
    return find( _set , _element) != 0; 
}

void *drop( void *_set, const void *_element)
{
    struct Set *set = _set;
    struct Object *element = find(set, _element);
    if(element)
    {
        if(element->count-- == 0)
        {
            element -> in = 0;
        }
        set->count--;
    }
    return element;
}

unsigned count(void *_set)
{
    const struct Set *set = _set;
    assert(set);
    return set->count;
}