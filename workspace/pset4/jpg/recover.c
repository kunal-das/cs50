/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

//Function to check block for JPEG start pattern
int checkjpgpattern(BYTE*);

//Function to create title of file
int createfiletitle(char*, int);

int main(int argc, char* argv[])
{
    
    //opening file
    FILE* inptr = fopen("card.raw", "r");
    if(inptr == NULL)
    {
        printf("could not open file.\n");
        return 2;
    }
    
    int filexists = 0;
    BYTE buffer[512];
    FILE* currentfile = NULL;
    char title[7];
    int filenumber = 0;
    
    while(fread(&buffer, sizeof(BYTE), 512, inptr) == 512)
    {
        //call function to check beginning of jpeg
        if(checkjpgpattern(buffer))
        {
            //check if a file is open 
            if(filexists)
            {
                //close current file and create new and write
                fclose(currentfile);
                // todo : use sprintf to create new file
                filenumber = createfiletitle(title, filenumber);
                currentfile = fopen(title, "a");
                filexists = 1;
                fwrite(&buffer, sizeof(BYTE), 512, currentfile);
            }
            else
            {
                //create new file and write
                // todo : use sprintf to create new file
                filenumber = createfiletitle(title, filenumber);
                currentfile = fopen(title, "a");
                filexists = 1;
                fwrite(&buffer, sizeof(BYTE), 512, currentfile);
            }
        }
        else   //block is not jpeg beginning but can be part of jpeg file
        {
            //check if a file is open
            if(filexists)
            {
                //write block in current file
                fwrite(&buffer, sizeof(BYTE), 512, currentfile);
            }
            else
            {
                //discard block
                continue;
            }
        }
    }
    return 0;
}

//Implementing checkjpgpattern
int checkjpgpattern(BYTE* buffer)
{
    if((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] == 0xe0) || (buffer[3] == 0xe1)))
    {
        return 1;
    }
    return 0;
}

//Implementing createfiletitle function
int createfiletitle(char* title, int fileNumber)
{
    sprintf(title, "%.3d.jpg", fileNumber);
    return (fileNumber+1);
}