#ifndef SCYTALE_H
#define SCYTALE_H

#include <stdint.h>

void E_scytale( const uint8_t *P, uint8_t *C, int l, uint8_t K);
void D_scytale( const uint8_t *C, uint8_t *P, int l, uint8_t K);

#endif