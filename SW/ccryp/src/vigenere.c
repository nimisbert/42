#include "../include/vigenere.h"
#include "../include/polybius.h"

void E_vigenere( uint8_t *P, uint8_t *C, int l, uint8_t *K, int nk)
{
    int j = 0;
    for( int i = 0; i < l; i++) {
        C[i] = vigenere_subBytes( P[i], K[j]);
        if( i == nk ) {
            j = 0;
        } else {
            j++;
        }
    } 
    return;
}

void D_vigenere( uint8_t *P, uint8_t *C, int l, uint8_t *K, int nk)
{
    return;
}

uint8_t vigenere_subBytes( uint8_t p, uint8_t k)
{
// [A ; Z] == [0x41 ; 0x5a]
// [a ; z] == [0x61 ; 0x7a]
    if( 0x41 <= k && k <= 0x5a ) {
        return polybius_subBytes( p, k-0x41);
    } else if ( 0x61 <= k && k <= 0x7a ) {
        return polybius_subBytes( p, k-0x61);
    } else {
        return p;       
    }
}