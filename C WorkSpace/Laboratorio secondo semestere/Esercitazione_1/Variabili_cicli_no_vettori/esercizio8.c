//calcolo potenza di un numero (dati due numeri a e b, calcolare a b )

#include<stdio.h>

int main()
{
	int a, b;

	printf("Inserire base a e esponente b\n");
	scanf("%d%d", &a, &b);

	int potenza = a;

	for(int i = 2; i <= b; ++i)
	{
		potenza *= a;
	}

	printf("Il risultato della potenza e' %d\n", potenza);

	return 0;
}