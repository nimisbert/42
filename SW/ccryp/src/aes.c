#include "../include/aes.h"

void E_AES( const uint8_t P[4*Nb], uint8_t C[4*Nb], uint8_t K[4*Nk] )
{
// Init
    uint8_t state[4][Nb];
    uint32_t w[Nb*(Nr+1)];
    AES_keyExpansion( K, w);

//
    for( int i = 0; i < 4; i++) {
        for( int j = 0; j < Nb; j++) {
            state[i][j] = P[i*4 + j];
        }
    }

    AES_addRoundKey( state, w, 0);

    for( int round = 1; round < Nr; round++) {
        AES_subBytes( state );
        AES_shiftRows( state );
        AES_mixColumns( state );
        AES_addRoundKey( state, w, round);
    }

    AES_subBytes( state );
    AES_shiftRows( state );
    AES_addRoundKey( state, w, Nr);

// Output 
    for( int i = 0; i<4; i++) {
        for( int j = 0; j<Nb; j++) {
            C[i*4 +j] = state[i][j];
        }
    }
    return;
}

// Section 5.1.1 : SubBytes() Transformation
// S-BOX (page 16 fig.7)
//              0x  X   Y
const uint8_t SBOX[16][16] = {
//       0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f   // 0xXY
    { 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76}, // 0
    { 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0}, // 1
    { 0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15}, // 2
    { 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75}, // 3
    { 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84}, // 4
    { 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf}, // 5 
    { 0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8}, // 6
    { 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2}, // 7
    { 0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73}, // 8 
    { 0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb}, // 9
    { 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79}, // a
    { 0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08}, // b
    { 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a}, // c
    { 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e}, // d
    { 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf}, // e
    { 0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}  // f
};

void AES_subBytes( uint8_t s[4][Nb])
{
    for( int r = 0; r < 4; r++) {
        for ( int c = 0; c < Nb; c++) {
            s[r][c] = AES_substitute( s[r][c] );
        }
    }
    return;
}

uint8_t AES_substitute( uint8_t a )
{
    return SBOX[ (a >> 4) & 0x0F ][ a & 0x0F ];   
}

// Section 5.1.2 : ShiftRows() Transformation
void AES_shiftRows( uint8_t s[4][Nb] )
{
    uint8_t t[4][Nb];
    for( int r = 0; r < 4; r++) {
        for( int c = 0; c < Nb; c++) {
            t[r][c] = s[r][c];
        }
    }
    for( int r = 0; r < 4; r++) {
        for( int c = 0; c < Nb; c++) {
            s[r][c] = s[r][(c+r)%Nb];
        }
    }
    return;
}

// Section 5.1.3 : MixColumns Transformation
void AES_mixColumns( uint8_t s[4][Nb] )
{
    uint8_t t[4][Nb];
    for( int i = 0; i < 4; i++) {
        for( int j = 0; j < Nb; j++) {
            t[i][j] = s[i][j];
        }
    }
    for( int c = 0; c < Nb; c++) {
        s[0][c] = AES_gf256Mul( t[0][c] , 0x02 ) ^ AES_gf256Mul( t[1][c] , 0x03 ) ^ t[2][c] ^ t[3][c];
        s[1][c] = t[0][c] ^ AES_gf256Mul( t[1][c] , 0x02 ) ^ AES_gf256Mul( t[2][c] , 0x03 ) ^ t[3][c];
        s[2][c] = t[0][c] ^ t[1][c] ^ AES_gf256Mul( t[2][c] , 0x02 ) ^ AES_gf256Mul( t[3][c] , 0x03 );
        s[3][c] = AES_gf256Mul( t[0][c] , 0x03 ) ^ t[1][c] ^ t[2][c] ^ AES_gf256Mul( t[3][c] , 0x02 );
    }
    return;
}

uint8_t AES_gf256Add( const uint8_t a, const uint8_t b )
{
    return a ^ b;
}

uint8_t AES_gf256Mul( const uint8_t a, const uint8_t b ) 
{
    uint16_t p = 0x00;
    const uint16_t at = a, bt = b;
    for( int bit = 7; bit >= 0; bit--) {
        if( bt & (1<<bit) ) {
            p = p ^ (at << bit);
        }
    }
    uint8_t  irr  = 0x1b;
    uint16_t high = 0x0100;
    for( int bit = 7; bit >= 0; bit--) {
        if( p & ( high << bit )) {
            p = p ^ (irr << bit);
        }
    }
    return (uint8_t)p;
} 

uint8_t AES_gf256Pow( const uint8_t a, const uint8_t p)
{
    uint8_t e = a;
    if( p <= 0) {
        e = 0x01;
    } else if (p > 0) {
        for( int i = 1; i<p; i++) {
            e = AES_gf256Mul( e, a);
        }
    }
    return e;
}

// Section 5.1.4 : AddRoundKey() Transformation
void AES_addRoundKey( uint8_t s[4][Nb], uint32_t w[Nb], int round)
{
    for( int c = 0; c<Nb; c++) {
        s[0][c] = s[0][c] ^ (0xFF000000 & (w[round*Nb+c] << 0));
        s[1][c] = s[1][c] ^ (0x00FF0000 & (w[round*Nb+c] << 8));
        s[2][c] = s[2][c] ^ (0x0000FF00 & (w[round*Nb+c] <<16));
        s[3][c] = s[3][c] ^ (0x000000FF & (w[round*Nb+c] <<24));
    }
    return;
}

// Section 5.2 : Key Expansion
void AES_keyExpansion( const uint8_t key[4*Nk], uint32_t w[Nb*(Nr+1)])
{
    int i = 0;
    uint32_t temp = 0x00000000;
    while( i < Nk ) {
        w[i] = ((key[4*i  ] <<24) & 0xFF000000) + 
               ((key[4*i+1] <<16) & 0x00FF0000) + 
               ((key[4*i+2] << 8) & 0x0000FF00) + 
               ((key[4*i+3] << 0) & 0x000000FF); 
        i = i+1;
    }
    i = Nk;
    while( i < Nb * (Nr + 1)) {
        if( i % Nk == 0) {
            temp = AES_subWord( AES_rotWord( temp )) ^ AES_rcon( i / Nk ); 
        } else if ( Nk > 6 && i % Nk == 4) {
            temp = AES_subWord( temp );    
        }
        w[i] = w[i-Nk] ^ temp;
        i = i + 1;
    }
    return;
}

uint32_t AES_subWord( uint32_t w )
{
    uint8_t t[4];
    for( int i = 0; i<4; i++) {
        t[i] = AES_substitute((w >> (8*i)) & 0x000000FF);
    }
    return (t[3] << 24) + (t[2] << 16) + (t[1] << 8) + (t[0] << 0);
}

uint32_t AES_rotWord( uint32_t w )
{
    uint8_t a[4];
    a[0] = (w >> 24) & 0xff;
    a[1] = (w >> 16) & 0xff;
    a[2] = (w >>  8) & 0xff;
    a[3] = (w >>  0) & 0xff;
    return (a[1] << 24) + (a[2] << 16) + (a[3] << 8) + (a[0] << 0);
}

uint32_t AES_rcon( int i )
{
    return 0xFF000000 & (AES_gf256Pow( 0x02, i-1 ) << 24 );
}