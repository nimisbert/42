#include "../include/polybius.h"

void E_polybius( const uint8_t *P, uint8_t *C, int l, uint8_t K)
{
    for( int i = 0; i < l; i++) {
        C[i] = P[i] + K % 26;
    }
    return;
}

void D_polybius( const uint8_t *C, uint8_t *P, int l, uint8_t K)
{
    for( int i = 0; i < l; i++) {
        P[i] = C[i] - K % 26;
    }
    return;
}