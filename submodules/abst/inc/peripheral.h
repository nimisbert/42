#ifndef PERIPHERAL_STUB_H
#define PERIPHERAL_STUB_H

#include <stdint.h>

typedef struct __attribute__((__packed__)){
    uint8_t REG0; //< Representative peripheral configuration register
    uint8_t REG1; //<
    uint8_t REG2; //< Representative peripheral xchange register
}Register_t;

typedef uint8_t (*periphA_read_fptr) (void);
typedef void    (*periphA_write_fptr)(uint8_t d);

typedef struct peripheralA{
    periphA_read_fptr read;
    periphA_write_fptr write;
}peripheralA_t;

peripheralA_t peripheralA_ctor(void);

uint8_t peripheralA_read_8bit (void);
void    peripheralA_write_8bit(uint8_t d);

#endif