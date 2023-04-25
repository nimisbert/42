#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "../include/aes.h"

uint8_t clearText[4*Nb]                = "\x32\x43\xf6\xa8\x88\x5a\x30\x8d\x31\x31\x98\xa2\xe0\x37\x07\x34";
uint8_t cipherText[4*Nb]               = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
uint8_t decodedText[4*Nb]              = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
uint8_t cipherKey[4*Nk]                = "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c";
uint8_t appendixBReferenceOutput[4*Nb] = "\x39\x25\x84\x1d\x02\xdc\x09\xfb\xdc\x11\x85\x97\x19\x6a\x0b\x32";

void printHex( uint8_t *c, int l);

int main( void )
{

#if( Nk == 4 && Nb == 4 ) // B Cipher Example (for Nb == 4 and Nk == 4 )
    E_AES( clearText, cipherText, cipherKey);
    D_AES( cipherText, decodedText, cipherKey);
#endif
    printf("plainText   : "); printHex( clearText  , Nb*4); printf("\r\n");
    printf("cipherText  : "); printHex( cipherText , Nb*4); printf("\r\n");
    printf("shouldBe    : "); printHex( appendixBReferenceOutput , Nb*4); printf("\r\n");
    printf("decodedText : "); printHex( decodedText, Nb*4); printf("\r\n");

    return 0;
}

void printHex( uint8_t *c, int l)
{
    for( int i = 0; i<l; i++) {
        printf("%02x", c[i]);
    }
    return;
}