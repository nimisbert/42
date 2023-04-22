#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "../include/polybius.h"

int main( void )
{
// Init 
    uint8_t clearText[13], cipherText[13], decodedText[13], key = 3;
    memset( clearText, 0, strlen(clearText)*sizeof(uint8_t));
    memset( cipherText, 0, strlen(clearText)*sizeof(uint8_t));
    memset( decodedText, 0, strlen(clearText)*sizeof(uint8_t));
    sprintf(clearText, "Hello world!");
// Encrypt & Decrypt 
    E_polybius( clearText, cipherText, strlen(clearText), key);
    D_polybius( cipherText, decodedText, strlen(clearText), key);
// Print result
    printf("Message clair : %s\r\n", clearText);   // Alice 
    printf("Message codee : %s\r\n", cipherText);  // Alice To Bob
    printf("Message decod : %s\r\n", decodedText); // Bob
    return 0;
}