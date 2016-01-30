# include <stdio.h>
# include <cs50.h>
# include <ctype.h>
# include <string.h>

int main()
{
	string name = GetString();
	char * token = strtok(name, " ");
	while(token != NULL)
	{
		printf("%c", toupper(token[0]));
		token = strtok(NULL, " ");
	}	
	printf("\n");
	return 0;
}
