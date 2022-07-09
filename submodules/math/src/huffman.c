#include <huffman.h>

int huffman_openBinaryFile(const char* fileName, FILE** fptr)
{
    *fptr = fopen(fileName,"rb");
    if(*fptr==NULL)
    {
        return -1;
    }
    return 0;
}

int huffman_closeBinaryFile(FILE** fptr)
{
    if(*fptr != NULL)
    {
        fclose(*fptr);
        return 0;
    }
    else
    {
        return -1;
    }
}

int huffman_getBinaryFile(FILE** fptr, unsigned char *buffer, unsigned long int size)
{
    if(*fptr==NULL)
        return -1;
    fread(buffer,size,1,*fptr);
    return 0;
}

int huffman_printBinaryFile(unsigned char *buffer, unsigned long int size)
{
    if(buffer==NULL)
        return -1;
    for(int i = 0; i<size; i+=0x10)
    {
        printf("%8x:",i);
        for(int j = 0; j<0x10; j++)
        {
            if(i+j>=size)
            {
                printf("\r\n");
                return 0;  
            }  
            printf(" %2x",buffer[i+j]); 
        }
        printf("\r\n");
    }
    return 0;
}


int huffman_getHexCount(unsigned char* buffer, unsigned long int size, unsigned long int* freqs)
{
    unsigned char temp = 0;
    for(int i = 0; i<0x10; i++)
    {
        freqs[i] = 0;
    }
    for(int i = 0; i<size; i++)
    {  
        temp = buffer[i];
        //printf("i=%d, Msb=0x%1x, Lsb=0x%1x \r\n",i,(temp&0xF0)>>4,temp&0x0F);
        freqs[temp&0x0F] = freqs[temp&0x0F]+1;
        freqs[(temp&0xF0)>>4] = freqs[(temp&0xF0)>>4]+1; 
    }
    return 0;
}

int huffman_printOccurances(unsigned long int *cntBuf)
{
    if(cntBuf==NULL)
        return -1;
    double sum = 0;
    for(int i=0; i<0x10; i++)
    {
        sum+=(double)cntBuf[i];
    }
    for(int i=0; i<0x10; i++)
    {
        printf("Occurance Hex[%x] = %lf \r\n",i,(double)cntBuf[i]);
    }
    printf("Total : %lf bits\r\n",sum*4);
    return 0;
}