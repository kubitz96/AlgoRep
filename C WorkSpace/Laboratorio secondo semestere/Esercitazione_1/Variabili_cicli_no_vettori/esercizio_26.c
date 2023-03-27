//dato da tastiera un valore n, stampare n A seguite da n B (es. se l’utente immette 3, stampare AAABBB)

#include<stdio.h>

int main()
{
	int n;

	printf("Inserire valore n\n");
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		printf("A");
	}

	for (int i = 0; i < n; ++i)
	{
		printf("B");
	}

	printf("\n");

	return 0 ;
}