# include <stdio.h>
# include <cs50.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, string argv[])
{
	/*
	* check if the number of arguments is more than 2	
	*/
			
	if(argc != 2)
	{
		printf("just one key with the program name please");
		return 1;
	}

	int key = atoi(argv[1]);
	if(key > 26)
	{
		key = key % 26;
	}
	//printf("The key is : %i\n", key);
	// Getting the string from the user

	string plaintext = GetString();
	int len = strlen(plaintext);
	//char encrypt[len]; 
	char c; 

	for(int i = 0; i < len; i++)
	{
		c = plaintext[i];	
		
		if(islower(c))
		{
			c = c - 97;
			if(c + key >= 26)
			{
				c = ((c + key) % 26) + 97;
			}
			else
			{
				c = c + key + 97;	
			}
			printf("%c",c);
			//strcat(encrypt, &c);
		}
		else if(isupper(c))
		{
			c = c - 65;
			if(c + key >= 26)
			{
				c = ((c + key) % 26) + 65;
			}
			else
			{
				c = c + key + 65;	
			}
			printf("%c",c);	
			//strcat(encrypt, &c);
		}
		else
		{
			printf("%c",c);	
			//strcat(encrypt, &c);
		}

	}

	printf("\n");	
	return 0;
	
}
