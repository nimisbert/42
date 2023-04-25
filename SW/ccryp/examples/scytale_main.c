#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "../include/scytale.h"

int main( void )
{
// Init 
    uint8_t clearText[22], cipherText[22], decodedText[22], key = 3;
    memset( clearText, 0, strlen(clearText)*sizeof(uint8_t));
    memset( cipherText, 0, strlen(cipherText)*sizeof(uint8_t));
    memset( decodedText, 0, strlen(decodedText)*sizeof(uint8_t));
    sprintf(clearText, "MESSAGER_TRES_MESQUIN");
// Cryptage 
    E_scytale( clearText, cipherText, strlen(clearText), key);
    D_scytale( cipherText, decodedText, strlen(clearText), key);
//
    printf("Message clair : %s\r\n", clearText);    // Alice
    printf("Message codee : %s\r\n", cipherText);   // Alice To Bob
    printf("Message decod : %s\r\n", decodedText);  // Bob
    return 0;
}