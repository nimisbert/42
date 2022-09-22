#include <library.h>

libA_t libA_ctor(void *lldriver, libA_xfer_fptr xfer)
{
    libA_t this = {
        .driver = lldriver,
        .xfer   = xfer
    };
    return this;
}

uint8_t libA_add(void *this, uint8_t d)
{
    libA_t *lib = (libA_t *)this;
    return lib->xfer(lib->driver, d+1);
}

uint8_t libA_sub(void *this, uint8_t d)
{
    libA_t *lib = (libA_t *)this;
    return lib->xfer(lib->driver, d-1);
}
