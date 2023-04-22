#include "../include/scytale.h"

void E_scytale( const uint8_t *P, uint8_t *C, int l, uint8_t K)
{
    for( int i = 0; i < K; i++) {
        for( int j = 0; j < l/K; j++) {
            C[(l/K) * i + j] = P[K * j + i];
        }
    }
    return;
}

void D_scytale( const uint8_t *C, uint8_t *P, int l, uint8_t K)
{
    for( int i = 0; i < K; i++) {
        for( int j = 0; j < l/K; j++) {
            P[K * j + i] = C[(l/K) * i + j];
        }
    }
    return;
}