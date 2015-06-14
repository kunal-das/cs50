# include <stdio.h>
# include <cs50.h>
# include <ctype.h>

int main()
{
	printf("Enter a string");
	string str = GetString();
	if(islower(str[0]))
	{
		printf("is lower");	
	}	
	return 0;
}
