/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resizes a BMP image.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

//Function to modify the BITMAPINFOHEADER
void modifyHeader(BITMAPINFOHEADER* , int, BITMAPFILEHEADER*);

//Function to write in buffer
void bufferwrite(RGBTRIPLE , RGBTRIPLE* , int, int*);

//Function to write in the file.
void writeFile(int , RGBTRIPLE*, FILE*, int);

//Function to add padding
void addPadding(RGBTRIPLE* , int, int*);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    //remember resize factor
    int n = atoi(argv[1]); 
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    //Storing the biHeight and biWidht of the infile.
    int inbiHeight = abs(bi.biHeight);
    int inbiWidth = bi.biWidth;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    
    //Determine the padding to skip in infile.
    int inpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //change the biWidth and biHeight to resize factor
    modifyHeader(&bi, n, &bf);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines of the resized image
    int outpadding =  (4 - ((bi.biWidth * sizeof(RGBTRIPLE)) % 4)) % 4;  // outfilepadding in bytes
    //printf("outfilepadding = %d", outpadding);

    //Temporary Storage
    RGBTRIPLE triple;
    
    //Buffer size
    int buffersize = (bi.biWidth*sizeof(RGBTRIPLE))+outpadding;
    
    //Declaring buffer
    RGBTRIPLE buffer[buffersize];
        
    // iterate over infile's scanlines
    for (int i = 0; i < inbiHeight; i++)
    {
        //Declaring buffer write head
        int bufferhead = 0;
        
        // iterate over pixels in scanline
        for (int j = 0; j < inbiWidth; j++)
        {
            
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            
            //Function to write in the buffer. 
            bufferwrite(triple, buffer, n, &bufferhead);
        }
        
        //Function to add padding in the buffer
        addPadding(buffer, outpadding, &bufferhead);
        
        //Call to function that will write to the output file once for every row
        writeFile(n, buffer, outptr, buffersize);
       
        
        // skip over padding, if any
        fseek(inptr, inpadding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

//Implementing modifyHeader function
void modifyHeader(BITMAPINFOHEADER* bi, int n, BITMAPFILEHEADER* bf)
{
    bi->biWidth = bi->biWidth * n;
    bi->biHeight = bi->biHeight * n;
    int outpadding =  (4 - ((bi->biWidth * sizeof(RGBTRIPLE)) % 4)) % 4;
    bi->biSizeImage = (bi->biWidth * abs(bi->biHeight) * sizeof(RGBTRIPLE)) + (outpadding*(abs(bi->biHeight)));
    bf->bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi->biSizeImage;
}

//Implementing bufferwrite function.
void bufferwrite(RGBTRIPLE rgb, RGBTRIPLE* buffer, int n, int* bufferhead)
{
    int j = *bufferhead;    
    for(int i = 0; i < n; i++, j++)
    {
        buffer[j].rgbtBlue = rgb.rgbtBlue;
        buffer[j].rgbtGreen = rgb.rgbtGreen;
        buffer[j].rgbtRed = rgb.rgbtRed;
    }
    *bufferhead = j;
}


//Implementing writeFile fumction
void writeFile(int n, RGBTRIPLE* rgbptr, FILE* fileptr, int size)
{
    for(int i = 0; i < n; i++)
    {
    fwrite(rgbptr, size, 1, fileptr);
    }
}


//Implementing addPadding function
void addPadding(RGBTRIPLE* buffer, int padding, int* bufferhead)
{
    int j = *bufferhead;
    if(padding == 1)
    {
        buffer[j].rgbtBlue = 0x00;
    }
    else if(padding == 2)
    {
        buffer[j].rgbtBlue = 0x00;
        buffer[j].rgbtGreen = 0x00;
    }
    else if(padding == 3)
    {
        buffer[j].rgbtBlue = 0x00;
        buffer[j].rgbtGreen = 0x00;
        buffer[j].rgbtRed = 0x00;
    }
}