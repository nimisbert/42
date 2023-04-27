#ifndef VIGENERE_H
#define VIGENERE_H

#include <stdint.h>

void E_vigenere( uint8_t *P, uint8_t *C, int l, uint8_t *K, int nk);
void D_vigenere( uint8_t *P, uint8_t *C, int l, uint8_t *K, int nk);

uint8_t vigenere_subBytes( uint8_t b, uint8_t k);

#endif