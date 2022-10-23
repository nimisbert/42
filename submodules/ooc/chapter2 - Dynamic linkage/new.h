#ifndef OOC_MEMMANG_H
#define OOC_MEMMANG_H

#include <stddef.h>
#include <stdarg.h>
#include <assert.h>
#include <stdlib.h>

// table of function pointer for type specific functions (methods?)
struct Class{
    size_t size;
    void *(*ctor)   (void *self, va_list *app);
    void *(*dtor)   (void *self);
    void *(*clone)  (const void *self);
    int   (*differ) (const void *self, const void *b);
};

void    *new  (const void *_class, ...);
void    delete(void *self);

void    *clone(const void *self);
int     differ(const void *self, const void *b);
size_t  sizeOf(const void *self);

#endif