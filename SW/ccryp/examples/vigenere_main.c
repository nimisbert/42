#include <stdio.h>
#include <string.h>

#include "../include/vigenere.h"

int main( void )
{
    uint8_t clearText[41] = "j'adore ecouter la radio toute la journee";   
    uint8_t cipherKey[ 7] = "MUSIQUE";
    uint8_t cipherText[41];

    E_vigenere( clearText, cipherText, 41, cipherKey, 7);

    printf("clearText   %s\r\n", clearText);
    printf("cipherText  %s\r\n", cipherText);

    return 0;
}