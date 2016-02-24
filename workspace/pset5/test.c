#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include "dictionary.h"

#define LENGTH 45
int main(int argc, string argv[])
{
    if(argc !=2)
    {
        return 1;
    }
    
    char *dictionaryPath = argv[1];
    char *word = malloc(sizeof(char)*45);
    FILE *dictionary = fopen(dictionaryPath, "r");
    //fgets(word, (LENGTH+1), dictionary);
    printf("%s\n", dictionaryPath);
    //char c = '\n';
    //printf("%i\n", c);
    while(fgets(word,(LENGTH+1), dictionary) != NULL)
    {
       printf("%s%lu\n", word, (strlen(word)/sizeof(char))); 
    }
    printf("Size of node struct is : %lu\n", sizeof(node));
    return 0;
}