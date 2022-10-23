#include <myString.h>
#include <new.h>

struct String{
    const void *class;
    char *text;
    struct String *next;
    unsigned count;
};

static struct String *ring;



static void *String_clone(const void *_self)
{
    struct String *self = (void *)_self;
    self->count++;
    return self;
}