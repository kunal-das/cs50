#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include "dictionary.h"

#define LENGTH 45

int wordcount = 0;

void incrementcount();
int printcount();

int main(void)
{
    incrementcount();
    int c = printcount();
    printf("wordcount : %i\n", c);
}

void incrementcount()
{
    for(int i = 0; i < 10; i++)
    {
        wordcount++;
    }
}

int printcount()
{
    return wordcount;
}