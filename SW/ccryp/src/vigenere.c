#include "../include/vigenere.h"
#include "../include/polybius.h"

void E_vigenere( const uint8_t P[VIGENERE_Nb], uint8_t C[VIGENERE_Nb], uint8_t K[VIGENERE_Nk])
{
    int j = 0;
    for( int i = 0; i < VIGENERE_Nb; i++) {
        C[i] = vigenere_subBytes( P[i], K[j]);
        if( (0x41 <= P[i] && P[i] <= 0x5a) || ( 0x61 <= P[i] && P[i] <= 0x7a )) {
            if( j < VIGENERE_Nk-1 ) {
                j++;
            } else {
                j=0;
            }
        } else {
            C[i] = P[i];
        }
    } 
    return;
}

void D_vigenere( const uint8_t C[VIGENERE_Nb], uint8_t P[VIGENERE_Nb], uint8_t K[VIGENERE_Nk])
{
    int j = 0;
    for( int i = 0; i < VIGENERE_Nb; i++) {
        if( (0x41 <= C[i] && C[i] <= 0x5a) || ( 0x61 <= C[i] && C[i] <= 0x7a )) {
            P[i] = vigenere_invSubBytes( C[i], K[j]);
            if( j < VIGENERE_Nk-1 ) {
                j++;
            } else {
                j=0;
            }
        } else {
            P[i] = C[i];
        }
    } 
    return;
}

uint8_t vigenere_subBytes( uint8_t p, uint8_t k)
{
// Alphabet :
// [A ; Z]c == [0x41 ; 0x5a]x == [65 ;  90]d
// [a ; z]c == [0x61 ; 0x7a]x == [97 ; 122]d
    int pa = ( 0x40 < p && p < 0x5b ) ? 0x41 : 0x61;
    int ka = ( 0x40 < p && p < 0x5b ) ? 0x41 : 0x61;
    int r  = polybius_subBytes( p - pa, k - ka);
    if( r > 26 ) {
        return (uint8_t)( r - 26 + pa);
    } else {
        return (uint8_t)( r + pa);
    }
}

uint8_t vigenere_invSubBytes( uint8_t p, uint8_t k)
{
    int pa = (0x40 < p && p < 0x5b ) ? 0x41 : 0x61;
    int ka = (0x40 < p && p < 0x5b ) ? 0x41 : 0x61;
    int r  = polybius_invSubBytes( p - pa, k - ka);
    if( r < 0 ) {
        return (uint8_t)( r + 26 + pa);
    } else {
        return (uint8_t)( r + pa);
    }
}