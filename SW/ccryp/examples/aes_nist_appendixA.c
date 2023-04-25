#include <stdio.h>

#include "../include/aes.h"

void display_extendedKey( uint32_t extendedCipherKey[Nb*(Nr+1)] );


int main( void )
{
#if   Nk == 4 // A.1 Expansion of a 128-bit Cipher Key

    uint8_t cipherKey[4*Nk] = "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c";
    uint32_t extendedCipherKey[Nb*(Nr+1)];

    AES_keyExpansion( cipherKey, extendedCipherKey);
    display_extendedKey( extendedCipherKey);

#elif Nk == 6 // A.2 Expansion of a 192-bit Cipher Key

    uint8_t cipherKey[4*Nk] = "\x8e\x73\xb0\xf7\xda\x0e\x64\x52\xc8\x10\xf3\x2b\x80\x90\x79\xe5\x62\xf8\xea\xd2\x52\x2c\x6b\x7b";
    uint32_t extendedCipherKey[Nb*(Nr+1)];

    AES_keyExpansion( cipherKey, extendedCipherKey);
    display_extendedKey( extendedCipherKey);

#elif Nk == 8 // A.3 Expansion of a 256-bit Cipher Key

    uint8_t cipherKey[4*Nk] = "\x60\x3d\xeb\x10\x15\xca\x71\xbe\x2b\x73\xae\xf0\x85\x7d\x77\x81\x1f\x35\x2c\x07\x3b\x61\x08\xd7\x2d\x98\x10\xa3\x09\x14\xdf\xf4";
    uint32_t extendedCipherKey[Nb*(Nr+1)];

    AES_keyExpansion( cipherKey, extendedCipherKey);
    display_extendedKey( extendedCipherKey);
    
#endif
    return 0;
}

void display_extendedKey( uint32_t extendedCipherKey[Nb*(Nr+1)] )
{
    printf("Extended Cipher Key %d-bit :\r\n",Nk*4*8);
    for( int i = Nk; i < Nb*(Nr+1); i++) {
        if( i % Nk == 0 && i != 0) {
            printf("\r\n");
        }
        printf(" %8x", extendedCipherKey[i]);
        
    }
}