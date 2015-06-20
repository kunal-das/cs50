# include <stdio.h>
# include <cs50.h>

void print_space(int count);

void print_hash(int count);

int main()
{
	int height;
	while(true)
	{
		printf("height: ");
		height = GetInt();
		
		if(!(height >= 0 && height <=23))
		{
			continue;	
		}
		else
			break;
		
	}

	if(height == 0)
		return 0;
	else
	{
		for(int i = 0; i < height; i++)
		{
			print_space(height-1-i);
			print_hash(i+2);
			printf("\n");
		}
		
	}
	
	return 0;		
}


void print_space(int count)
{
	char space[] = "                       ";
	printf("%.*s", count, space); 
}

void print_hash(int count)
{
	char hash[] = "########################"; 
	printf("%.*s", count, hash);
}
