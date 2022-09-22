#ifndef DRIVER_STUB_H
#define DRIVER_STUB_H

#include <stdint.h>

// --- Representative Driver for a module A --- //

typedef struct driverA driverA;

typedef uint8_t (*driverA_ll_read_fptr) (void);
typedef void    (*driverA_ll_write_fptr)(uint8_t d);

typedef struct driverA{
//Lower level instances 
    void *peripheral;
    driverA_ll_read_fptr read;
    driverA_ll_write_fptr write;
}driverA_t;

driverA_t driverA_ctor(void *ll, driverA_ll_read_fptr r, driverA_ll_write_fptr w);
uint8_t   driverA_xfer(void *this, uint8_t d);

#endif