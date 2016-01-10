/*
*   File to print the contents of BITMAPFILEHEADER.
*/

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    //checks proper usage of file
    if(argc != 2)
    {
        printf("Usage: ./bitmapfileheader filename");
        return 1;
    }
    
    //storing the name of the file
    char * file = argv[1];
    
    //opening the file
    FILE* fileptr = fopen(file, "r");
    if(fileptr == NULL)
    {
        printf("Error : Could not open %s.\n", file);
        return 2;
    }
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, fileptr);
    fread(&bi, sizeof(BITMAPFILEHEADER), 1, fileptr);
    printf("%d\n",bf.bfSize);
    printf("%d\n",bi.biSize);
    printf("%d\n",bi.biSizeImage);
    printf("%lu\n", sizeof(bf));
    printf("%lu\n", sizeof(bi));
    printf("%d\n", bi.biWidth);
    printf("%d\n", bi.biHeight);
}
