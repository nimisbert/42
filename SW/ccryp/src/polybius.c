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

int polybius_subBytes( int p, int k)
{
    return ((p + k) % 26);
}

int polybius_invSubBytes( int c, int k)
{
    return ((c - k) % 26);
}