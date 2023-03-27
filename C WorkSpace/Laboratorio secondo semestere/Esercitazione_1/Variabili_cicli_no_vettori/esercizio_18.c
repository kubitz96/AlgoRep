//dato un input n, stampa di un triangolo Fatto di * iniziante con un * e terminante con n *

#include<stdio.h>

int main()
{
	int n;

	printf("Inserire valore n\n");
	scanf("%d", &n);

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}