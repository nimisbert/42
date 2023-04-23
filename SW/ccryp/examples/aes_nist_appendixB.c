#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "../include/aes.h"

uint8_t clearText[4*Nb]  = "\x32\x43\xf6\xa8\x88\x5a\x30\x8d\x31\x31\x98\xa2\xe0\x37\x07\x34";
uint8_t cipherText[4*Nb] = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
uint8_t cipherKey[4*Nk]  = "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c";


int main( void )
{
    E_AES( clearText, cipherText, cipherKey);

    printf("Input      :");
    for( int i = 0; i < 4*Nb; i++) {
        printf(" %02x", clearText[i]); 
    }

    printf("\r\nCipher Key :");
    for( int i = 0; i < 4*Nb; i++) {
        printf(" %02x", cipherKey[i]); 
    }

    printf("\r\nOutput     :");
    for( int i = 0; i < 4*Nb; i++) {
        printf(" %02x", cipherText[i]); 
    }
    printf("\r\n");

    return 0;
}