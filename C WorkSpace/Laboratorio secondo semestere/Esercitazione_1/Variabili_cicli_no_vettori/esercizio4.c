//Stampare i numeri pari da 1 a 10 in modo decrescente

#include<stdio.h>

int main()
{
	int x = 10;

	while(x > 0)
	{
		printf("%d ", x);

		x -= 2;
	}

	return 0;
}