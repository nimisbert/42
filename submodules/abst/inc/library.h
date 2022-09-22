#ifndef LIBRARY_STUB_H
#define LIBRARY_STUB_H

#include <stdint.h>

// --- Representative Library for functionalities named A --- //

typedef uint8_t (*libA_xfer_fptr)(void *this, uint8_t d);

typedef struct libA{
//Lower level instances 
    void *driver;
    libA_xfer_fptr xfer;
//
}libA_t;

libA_t libA_ctor(void *lldriver, libA_xfer_fptr xfer);

uint8_t libA_add(void *this, uint8_t d);
uint8_t libA_sub(void *this, uint8_t d);


#endif