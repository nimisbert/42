#include <myString.h>
#include <new.h>

struct String{
    const void *class;
    char *text;
    struct String *next;
    unsigned count;
};
static struct String *ring;

static void *Atom_ctor(void *_self, va_list *app)
{
    if(ring)
    {
        struct 
    }
}

static void *Atom_dtor(void *_self)
{
}

static void *Atom_clone(const void *_self)
{
    struct String *self = (void*)_self;
    self->count++;
    return self;
}

static int Atom_differ(const void *_self, const void *_b)
{
}