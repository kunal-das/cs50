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
#include <stdio.h>
#include "dictionary.h"

int wordcount = 0;
node *root = NULL;
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //Initializing the current head to the root of the TRIE.
    node *current_head = root;
    //Defining and allocating space to a variable to hold the character.
    int ch = 0;   
    for(int i = 0; word[i] != '\0'; i++)
    {
        ch = word[i];
        //check if the character retrieved is an apostrophe.
        if(ch == '\'')
        {
            //check if the 26th child denoting apostrophe is pointing to another character or not.
            if(current_head->children[26] == NULL)
            {
                return false;
            }
            else
            {
                current_head = current_head->children[26];
            }
        }
        else if(isalpha(ch))
        {
            //Checking if the character is in upper case or not.
            if(isupper(ch))
            {
                ch = tolower(ch);
            }
            //determined the index of the child according to the alphabet.
            ch = 'a' - ch;
            
            if(current_head->children[ch] == NULL)
            {
                return false;
            }
            else
            {
               current_head = current_head->children[ch]; 
            }
        }
        
    } //for loop ends and we have reached the end of the word.
    //Checking if the bool value is set for the word or not.
    if(current_head->is_word == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //check if dictionary passed is NULL or not.
    if(dictionary == NULL)
    {
        return false;
    }
    root = malloc(sizeof(node));
    node *current_head = root;
    char *word = malloc(sizeof(char)*45);
    FILE *dictionaryFile = fopen(dictionary, "r");
    //int wordcount = 0;
    while(fgets(word, (LENGTH +1), dictionaryFile) != NULL)
    {
        //Iterate through each character of the word and build the TRIE branch for each word
        for(int i = 0; word[i] != '\n'; i++)
        {
            node *branch;
            //check if the character retrieved from the word is an apostrophe.
            if(word[i] == '\'')
            {
               //check if children[27] is NULL or not.
               if(current_head->children[26] != NULL)
               {
                   // shift the current head to pointing to the child node.
                   current_head = current_head->children[26];
               }
               else
               {
                   //create a new node and make the child point to the new node.
                   branch = malloc(sizeof(node));
                   current_head->children[26] = branch;
                   //make the current head point to the new node.
                   current_head = branch;
                   //branch = NULL;
                   branch = NULL;
               }
            }
            //check if the element retrieved for the word is a character.
            else if(isalpha(word[i]))
            {
                int ch = word[i] - 'a';
                if(current_head->children[ch] != NULL)
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
        current_head = root;
    }//while loop ends
    
    return true; 
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordcount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
