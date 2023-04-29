#ifndef POLYBIUS_SQUARE_H
#define POLYBIUS_SQUARE_H

#include <stdint.h>

void E_polybius( const uint8_t *P, uint8_t *C, int l, uint8_t K);
void D_polybius( const uint8_t *C, uint8_t *P, int l, uint8_t K);


int polybius_subBytes( int p, int k);
int polybius_invSubBytes( int c, int k);

#endif