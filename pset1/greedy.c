# include <stdio.h>
# include <cs50.h>
# include <math.h>


int main()
{
	float change;
	while(true)
	{
		printf("O hai! How much change is owed?\n");
		change = GetFloat();
		if(!(change >= 0))
		{
			continue;
		}
		else
			break;	
	}

	/*
		converting the dollars to cents and rounding them off.		
	*/

	int cents = (int)round(change * 100);
	
	int coin_values[] = {25, 10, 5, 1};

	int coins = 0;

	for(int i = 0; i < (sizeof(coin_values)/sizeof(int)); i++)
	{
		coins = coins + (cents/coin_values[i]);
		cents = cents - (coin_values[i] * (cents/coin_values[i]));
	} 
	printf("%d\n", coins);
	return 0;
}
