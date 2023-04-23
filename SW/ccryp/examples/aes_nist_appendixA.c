#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "../include/aes.h"

uint8_t cipherKey[4*Nk] = "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c";
uint32_t expandedCipherKey[Nb*(Nr+1)];
uint32_t w[Nb*(Nr+1)];

int main( void )
{
    for( int i = 0; i< Nb*(Nr+1); i++) {
        expandedCipherKey[i] = 0x00000000;
    }
// Appendix A - Key Expansion Examples
// A.1 - Expansion of a 128-bit Cipher Key
    printf("Key : w_0 = %4x\r\n", (cipherKey[ 0] << 24) + (cipherKey[ 1] << 16) + (cipherKey[ 2] << 8) + (cipherKey[ 3] << 0));
    printf("Key : w_1 = %4x\r\n", (cipherKey[ 4] << 24) + (cipherKey[ 5] << 16) + (cipherKey[ 6] << 8) + (cipherKey[ 7] << 0));
    printf("Key : w_2 = %4x\r\n", (cipherKey[ 8] << 24) + (cipherKey[ 9] << 16) + (cipherKey[10] << 8) + (cipherKey[11] << 0));
    printf("Key : w_3 = %4x\r\n", (cipherKey[12] << 24) + (cipherKey[13] << 16) + (cipherKey[14] << 8) + (cipherKey[15] << 0));

// UT of Operations in GF(2^8)
// page 12
    printf(" gf256 Multiplication Russian Peasant Algorithm \r\n");
    printf("%02x . %02x = %02x (== %02x)\r\n", 0x57, 0x02, AES_gf256Mul(0x57, 0x02), 0xae);
    printf("%02x . %02x = %02x (== %02x)\r\n", 0x57, 0x04, AES_gf256Mul(0x57, 0x04), 0x47);
    printf("%02x . %02x = %02x (== %02x)\r\n", 0x57, 0x08, AES_gf256Mul(0x57, 0x08), 0x8e);
    printf("%02x . %02x = %02x (== %02x)\r\n", 0x57, 0x10, AES_gf256Mul(0x57, 0x10), 0x07);
    printf("%02x . %02x = %02x (== %02x)\r\n", 0x57, 0x13, AES_gf256Mul(0x57, 0x13), 0xfe);
// page 27, 28
    printf(" gf256 Exponentiation \r\n");
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 0, AES_gf256Pow(0x02, 0), 0x01);
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 1, AES_gf256Pow(0x02, 1), 0x02);
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 2, AES_gf256Pow(0x02, 2), 0x04);
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 3, AES_gf256Pow(0x02, 3), 0x08);
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 4, AES_gf256Pow(0x02, 4), 0x10);
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 5, AES_gf256Pow(0x02, 5), 0x20);
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 6, AES_gf256Pow(0x02, 6), 0x40);
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 7, AES_gf256Pow(0x02, 7), 0x80);
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 8, AES_gf256Pow(0x02, 8), 0x1b);
    printf("%02x ^(%02x) = %02x (== %02x)\r\n", 0x02, 9, AES_gf256Pow(0x02, 9), 0x36);

// 128-bit Cipher Key
    printf(" 128-bit Key Expansion result \r\n");
    int i = 0;
    uint32_t temp = 0x00000000;
    uint32_t tempBefore = 0x00000000;
    uint32_t afterRotWord = 0x00000000;
    uint32_t afterSubWord = 0x00000000;
    uint32_t rcon = 0x00000000;
    uint32_t afterXorWithRcon = 0x00000000;
    uint32_t wimNk = 0x00000000;
    while( i < Nk ) {
        w[i] = ((cipherKey[4*i  ] <<24) & 0xFF000000) + 
               ((cipherKey[4*i+1] <<16) & 0x00FF0000) + 
               ((cipherKey[4*i+2] << 8) & 0x0000FF00) + 
               ((cipherKey[4*i+3] << 0) & 0x000000FF); //
        i = i+1;
    }
    i = Nk;
    while( i < Nb * (Nr + 1)) {
        tempBefore = temp = w[i-1];
        rcon = AES_rcon( i );
        if( i % Nk == 0) {
            afterRotWord = AES_rotWord( temp );
            afterSubWord = AES_subWord( afterRotWord );
            afterXorWithRcon = afterSubWord ^ AES_rcon( i / Nk );
            temp = AES_subWord( AES_rotWord( temp )) ^ AES_rcon( i / Nk );
            
        } else if ( Nk > 6 && i % Nk == 4) {
            afterSubWord = AES_subWord( temp );
            temp = AES_subWord( temp );
            
        }
        wimNk = w[i-Nk] ;
        w[i] = w[i-Nk] ^ temp;
        printf(" %3d | %8x | %8x | %8x | %8x | %8x | %8x | %8x\r\n", i, tempBefore, afterRotWord, afterSubWord, rcon, afterXorWithRcon, wimNk, w[i]);
        i = i + 1;
    }
    

    return 0;
}