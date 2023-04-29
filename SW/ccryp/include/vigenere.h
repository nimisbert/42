#ifndef VIGENERE_H
#define VIGENERE_H

#include <stdint.h>

#define VIGENERE_Nb 41
#define VIGENERE_Nk 7

uint8_t (*substitution_function)( uint8_t, uint8_t);

void E_vigenere( const uint8_t P[VIGENERE_Nb], uint8_t C[VIGENERE_Nb], uint8_t K[VIGENERE_Nk]);
void D_vigenere( const uint8_t C[VIGENERE_Nb], uint8_t P[VIGENERE_Nb], uint8_t K[VIGENERE_Nk]);

uint8_t vigenere_subBytes( uint8_t p, uint8_t k);
uint8_t vigenere_invSubBytes( uint8_t p, uint8_t k);
#endif