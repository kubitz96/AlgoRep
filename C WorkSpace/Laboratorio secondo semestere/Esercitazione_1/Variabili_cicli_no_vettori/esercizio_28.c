//dato da tastiera un valore n, stampare n A alternate ad n B (es. se l’utente immette 3, stampare ABABAB)

#include<stdio.h>

int main()
{
	int n;

	printf("Inserire valore n\n");
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		printf("A");
		printf("B");
	}

	printf("\n");

	return 0 ;
}