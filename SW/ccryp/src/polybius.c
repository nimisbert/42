#include "../include/polybius.h"

void E_polybius( const uint8_t *P, uint8_t *C, int l, uint8_t K)
{
    for( int i = 0; i < l; i++) {
        C[i] = polybius_subBytes( P[i], K);
    }
    return;
}

void D_polybius( const uint8_t *C, uint8_t *P, int l, uint8_t K)
{
    for( int i = 0; i < l; i++) {
        P[i] = polybius_invSubBytes( C[i], K);
    }
    return;
}

uint8_t polybius_subBytes( uint8_t p, uint8_t k)
{
    return (p + k) % 26;
}

uint8_t polybius_invSubBytes( uint8_t c, uint8_t k)
{
    return (c - k) % 26;
}