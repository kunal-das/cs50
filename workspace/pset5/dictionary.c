/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    node root = malloc(sizeof(node));
    node current_head = root;
    char* dictionaryPath = dictionary;
    char *word = malloc(sizeof(char)*45);
    FILE *dictionary = fopen(dictionaryPath, "r");
    while(fgets(word, (LENGTH +1), dictionary) != NULL)
    {
        //building the TRIE branch for each word
        for(int i = 0; i < (strlen(word)/sizeof(char)); i++)
        {
            if(word[i] == '\'')
            {
               //check if children[27] is NULL
               if(!checkNull(current_head->children[27]))
               {
                   // shift the current head to pointing to the child node.
               }
               else
               {
                   //create a new node and make the child point to the new node.
                   //make the current head point to the new node.
                   //branch = NULL;
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
