#include <stdio.h>
#include <stdlib.h>
#include <huffman.h>

#define BIN_FILE_SIZE 0x1FBB0+0x03

int main(int argc, char* argv[])
{
    //Variables
    huffman fileInfos;
    FILE* fptr;
    int error;
    unsigned char buffer[BIN_FILE_SIZE];

    //Fonctions
    error = huffman_openBinaryFile("./ressources/Prog_JI3_300_APP.X.production.bin",&fptr);
    error = huffman_getBinaryFile(&fptr, buffer, BIN_FILE_SIZE);
    error = huffman_closeBinaryFile(&fptr);
    error = huffman_printBinaryFile(buffer, BIN_FILE_SIZE);
    error = huffman_getHexCount(buffer, BIN_FILE_SIZE, fileInfos.hexCnt);
    error = huffman_printOccurances(fileInfos.hexCnt);
    
    

    return 0;
}