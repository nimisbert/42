#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

// ... not finished
// very confused about at 1.10 :
// int apply (const void * set,
// int (* action) (void * object, va_list ap), ...);

// Ooc 
struct  Object  { };
void    *new    (const void *type, ...);
void    delete  (void *item);
int     differ  (const void *a, const void *b); 

// Set 
void    *add    (void *_set, const void *_element);
void    *find   (const void *_set, const void *_element);
int     contains(const void *_set, const void *_element);
void    *drop   ( void *_set, const void *_element);
unsigned count  (void *_set);

int     store   (const void *_object, FILE *fp);
int     storev  (const void *_object, va_list ap);


int main(void)
{
    static const size_t _Object = sizeof(struct Object);
    const void *Object = &_Object;

    FILE *fp = fopen("set","w+");
    assert( fp != NULL );

    void *a = new(Object);
    void *b = new(Object);

    fprintf(fp, "%p\r", a);
    fprintf(fp, "%p\r", b);



    fclose(fp);
    return 0;
}

void *new( const void *type, ...)
{
    const size_t size = *(const size_t*) type;
    void *p = calloc(1, size);
    assert(p);
    return p;
}