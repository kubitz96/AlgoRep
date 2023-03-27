//calcolo fattoriale di un numero (dato un numero a, calcolare a!)

#include<stdio.h>

int main()
{
	int a;
	int fattoriale = 1;

	printf("Inserire numero intero positivo\n");
	scanf("%d", &a);

	if(a < 0) printf("Non esiste\n");
	else if(a <= 1) printf("Il fattoriale e' 1\n");
	else if(a > 1)
	{
		while(a > 1)
		{
			fattoriale *= a;
			--a;
		}

		printf("Il fattoriale e' %d\n", fattoriale);
	}

	return 0;
}