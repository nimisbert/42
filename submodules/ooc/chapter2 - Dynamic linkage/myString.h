#ifndef OOC_STRING_IMPL_H
#define OOC_STRING_IMPL_H

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

extern const void *String;

static void *String_ctor    (void *_self, va_list *app);
static void *String_dtor    (void *_self);
static void *String_clone   (const void *_self);
static int   String_differ  (const void *_self, const void *_b);

#endif