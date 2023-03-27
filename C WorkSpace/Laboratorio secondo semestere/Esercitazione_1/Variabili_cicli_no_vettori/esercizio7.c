/*dato un input n, stampa di una striscia di n “#” (es. se l’utente immette 5, vorrò veder
stampato #####)*/

#include<stdio.h>

int main()
{
	int n;

	printf("Inserire valore intero n\n");
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		printf("#");
	}
	printf("\n");

	return 0;
}