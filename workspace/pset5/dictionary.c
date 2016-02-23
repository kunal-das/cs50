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
#include <cs50.h>
#include <ctype.h>

#include "dictionary.h"

//Function definition to capture the total number of words that are loaded in the dictionary.
int wordCount(int);

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
    if(dictionary == NULL)
    {
        return false;
    }
    node root = malloc(sizeof(node));
    node current_head = root;
    char* dictionaryPath = dictionary;
    char *word = malloc(sizeof(char)*45);
    FILE *dictionary = fopen(dictionaryPath, "r");
    int wordcount = 0;
    while(fgets(word, (LENGTH +1), dictionary) != NULL)
    {
        //Iterate through each character of the word and build the TRIE branch for each word
        for(int i = 0; i < (strlen(word)/sizeof(char)); i++)
        {
            node branch;
            //check if the character retrieved from the word is an apostrophe.
            if(word[i] == '\'')
            {
               //check if children[27] is NULL or not.
               if(!checkNull(current_head->children[27]))
               {
                   // shift the current head to pointing to the child node.
                   current_head = current_head->children[27];
               }
               else
               {
                   //create a new node and make the child point to the new node.
                   branch = malloc(sizeof(node));
                   current_head->children[27] = branch;
                   //make the current head point to the new node.
                   current_head = branch;
                   //branch = NULL;
                   branch = NULL;
               }
            }
            //check if the element retrieved for the word is a character.
            else if(isalpha(word[i]))
            {
                int ch = 'a' - word[i];
                if(!checkNULL(current_head->children[ch]))
                {
                    current_head = current_head->children[ch];
                }
                else
                {
                    //create a new node and make the child point to the new node.
                    branch = malloc(sizeof(node));
                    current_head->children[ch] = branch;
                    //make the current head point to the new node.
                    current_head = branch;
                    //branch = NULL
                    branch = NULL;
                }
            }
        }    
        //Out of the for loop, meaning that we have created the node of the last character.
        //Now we mark the is_bool of the last node of the word as true.
        current_head->is_word = true;
        wordcount++;
    }//while loop ends
    
    return true; 
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

//Implementing the wordCount function.
int wordCount(int wordcount)
{
    return wordcount;
}