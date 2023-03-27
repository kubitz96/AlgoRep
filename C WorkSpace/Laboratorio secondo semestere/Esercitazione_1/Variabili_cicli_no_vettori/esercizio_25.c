//stampare la media dei numeri interi tra a e b, con a e b dati dall’utente

#include<stdio.h>

int main()
{
	float somma = 0;
	int a, b, tmp;
	int cnt = 0;

	printf("Inserire numeri a e b\n");
	scanf("%d%d", &a, &b);

	if(b < a)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	for (int i = a; i <= b; ++i)
	{
		somma += i;
		++cnt;
	}

	float media = somma/cnt;

	printf("La media e' %.2f\n", media);

	return 0;
}