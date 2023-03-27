//stampare la media dei numeri interi da 1 a 10

#include<stdio.h>

int main()
{
	float somma = 0;
	int i;

	for (i = 1; i < 11; ++i)
	{
		somma += i;	
	}

	float media = somma/(i-1);
	printf("La media e' %.2f\n", media);

	return 0;
}