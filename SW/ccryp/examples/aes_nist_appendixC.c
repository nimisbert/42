#include <stdio.h>

#include "../include/aes.h"

void display_asHex( uint8_t *b, int l);

int main( void )
{
    uint8_t PLAINTEXT[4*Nb] = "\x00\x11\x22\x33\x44\x55\x66\x77\x88\x99\xaa\xbb\xcc\xdd\xee\xff";
    
#if   Nk == 4 & Nr == 10 // C.1 Example vectors AES-128 (Nk == 4, Nr == 10)

    uint8_t KEY[4*Nk]       = "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f";
    uint8_t OUTPUT[4*Nb];
    uint8_t IOUTPUT[4*Nb];
    uint8_t SHOULDBE[4*Nb]  = "\x69\xc4\xe0\xd8\x6a\x7b\x04\x30\xd8\xcd\xb7\x80\x70\xb4\xc5\x5a";

    E_AES( PLAINTEXT, OUTPUT, KEY); // CIPHER (ENCRYPT)
    D_AES( OUTPUT, IOUTPUT, KEY);   // INVERSE CIPHER (DECRYPT)

#elif Nk == 6 & Nr == 12 // C.2 Example vectors AES-192 (Nk == 6, Nr == 12)

    uint8_t KEY[4*Nk]      = "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17";
    uint8_t OUTPUT[4*Nb];
    uint8_t IOUTPUT[4*Nb];
    uint8_t SHOULDBE[4*Nb] = "\xdd\xa9\x7c\xa4\x86\x4c\xdf\xe0\x6e\xaf\x70\xa0\xec\x0d\x71\x91";

    E_AES( PLAINTEXT, OUTPUT, KEY); // CIPHER (ENCRYPT)
    D_AES( OUTPUT, IOUTPUT, KEY);   // INVERSE CIPHER (DECRYPT)

#elif Nk == 8 & Nr == 14 // C.3 Example vectors AES-256 (Nk == 8, Nr == 14)

    uint8_t KEY[4*Nk] = "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f";
    uint8_t OUTPUT[4*Nb];
    uint8_t IOUTPUT[4*Nb];
    uint8_t SHOULDBE[4*Nb] = "\x8e\xa2\xb7\xca\x51\x67\x45\xbf\xea\xfc\x49\x90\x4b\x49\x60\x89";

    E_AES( PLAINTEXT, OUTPUT, KEY); // CIPHER (ENCRYPT)
    D_AES( OUTPUT, IOUTPUT, KEY);   // INVERSE CIPHER (DECRYPT)


#endif
    printf("PLAINTEXT  "); display_asHex( PLAINTEXT, 4*Nb);
    printf("OUTPUT     "); display_asHex( OUTPUT, 4*Nb);
    printf("REF OUTPUT "); display_asHex( SHOULDBE, 4*Nb);
    printf("IOUTPUT    "); display_asHex( IOUTPUT, 4*Nb);
}


void display_asHex( uint8_t *b, int l) 
{
    for(int i = 0; i < l; i++) {
        printf("%02x", b[i]);
    }
    printf("\r\n");
}