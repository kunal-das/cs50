#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
	if((argc != 2))
	{
		printf("Dude !!...You've got to enter only one argument...no more no less.");
		return (1);	
	}
		
	
	string key = argv[1];
	/*
	* checking if the key contains any non-alpha characters
	*/
	for(int i = 0; i < strlen(key); i++)
	{
		if(!isalpha(key[i]))
		{
			printf("You just can't enter anything into my key. You thought that I wouldn't have seen it ??");
			return (1);	
		}		
	}
	
	string plaintext = GetString();
	//int plain_len = strlen(plaintext);
	//char longkey[plain_len];

	/*
	* iterating over each characters in the key
	*/
	
	for(int i = 0, j = 0; i < strlen(plaintext); i++)
	{
		char c = plaintext[i];
		if(j==strlen(key))
		{
			j=0;
		}
		char k = key[j];
		int k_val = tolower(k)-97;
		if(islower(c))
		{
			//code to change the plaintext char to encrypted char.

				
			//printf("%c %c %i lower", c, k, k_val);
			c = c  - 97;	
			if((c + k_val) >= 26)
			{
				c = ((c + k_val) % 26) + 97;
			}
			else
			{
				c = c + k_val + 97;
			}
			printf("%c", c);
			j++;
		}
		else if(isupper(c))
		{
			
			//printf("%c %c %i upper", c, k, k_val);
			c = c - 65;	
			if((c + k_val) >= 26)
			{
				c = ((c + k_val) % 26) + 65;
			}
			else
			{
				c = c + k_val + 65;
			}
			printf("%c", c);	
			j++;	
		}
		else
		{
			printf("%c", c);	
		}
				
		
	}   
	printf("\n");	
}
