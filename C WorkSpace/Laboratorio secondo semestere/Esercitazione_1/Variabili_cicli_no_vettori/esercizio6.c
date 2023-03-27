//usando un solo ciclo, stampare i numeri pari da 1 a 50 andando a capo ogni 5

#include<stdio.h>

int main()
{
	int x = 2;

	for(int i = 1; x < 51; x += 2)
	{
		printf("%3d", x);
		if(i % 5 == 0)
		{
			printf("\n");
			i = 0;
		}
		++i;
	}

	return 0;
}