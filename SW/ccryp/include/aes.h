#ifndef ADVANCED_ENCRYPTION_STANDARD_H
#define ADVANCED_ENCRYPTION_STANDARD_H

#include <stdint.h>

// Parameters 
#define Nb 4
#define Nk 4
#define Nr 10

void E_AES( const uint8_t P[4*Nb], uint8_t C[4*Nb], uint8_t K[4*Nk] );

// Section 5.1.1 : SubBytes() Transformation 
void    AES_subBytes      ( uint8_t s[4][Nb]);
uint8_t AES_substitute    ( uint8_t a );

// Section 5.1.2 : ShiftRows() Transformation
void    AES_shiftRows     ( uint8_t s[4][Nb] );

// Section 5.1.3 : MixColumns Transformation
void    AES_mixColumns    ( uint8_t s[4][Nb] );
uint8_t AES_gf256Add( const uint8_t a, const uint8_t b );
uint8_t AES_gf256Mul( const uint8_t a, const uint8_t b );
uint8_t AES_gf256Pow( const uint8_t a, const uint8_t p );

// Section 5.1.4 : AddRoundKey() Transformation
void    AES_addRoundKey( uint8_t s[4][Nb], uint32_t w[Nb], int round);

// Section 5.2 : Key Expansion
void     AES_keyExpansion ( const uint8_t key[4*Nk], uint32_t w[Nb*(Nr+1)]);
uint32_t AES_subWord      ( const uint32_t w);
uint32_t AES_rotWord      ( const uint32_t w);
uint32_t AES_rcon         ( int i );

#endif