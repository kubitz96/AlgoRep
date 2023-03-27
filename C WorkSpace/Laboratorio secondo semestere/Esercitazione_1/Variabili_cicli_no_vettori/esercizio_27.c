//dato da tastiera due valori n ed m, stampare n A seguite da m B (es. se l’utente immette 3 e 5,
// stampare AAABBBBB)

#include<stdio.h>

int main()
{
	int m, n;

	printf("Inserire valori m e n\n");
	scanf("%d%d", &m, &n);

	for (int i = 0; i < m; ++i)
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