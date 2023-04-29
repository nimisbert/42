#include <stdio.h>
#include <string.h>

#include "../include/vigenere.h"


int main( void )
{
    uint8_t clearText[41]  = "j'adore ecouter la radio toute la journee";   
    uint8_t cipherKey[ 7]  = "musique";
    uint8_t cipherText[41];
    uint8_t decodedText[41];
    uint8_t shouldBe[41]   = "v'uvwhy ioimbul pm lslyi xaolm bu naojvuy"; //

    E_vigenere( clearText, cipherText, cipherKey);

    D_vigenere( cipherText, decodedText, cipherKey);

    printf("clearText   %s\r\n", clearText);
    printf("cipherText  %s\r\n", cipherText);
    printf("shouldbe    %s\r\n", shouldBe);
    printf("decodedText %s\r\n", decodedText);

    return 0;
}