//usando un solo ciclo, stampare 5 righe di 10 asterischi

#include<stdio.h>

int main()
{
	for(int i = 1; i < 51; ++i)
	{
		printf("*");
		if(i % 10 == 0) printf("\n");
	}

	return 0;
}