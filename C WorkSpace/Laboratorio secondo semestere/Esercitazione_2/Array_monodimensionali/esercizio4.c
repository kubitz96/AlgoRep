/*dato un vettore stampare UGUALI se tutti gli elementi contenuti al suo interno sono tra loro
uguali, NO se ne esiste anche soltanto uno diverso (versione NON ottimizzata, ossia attraverso
un ciclo for (o while) che scorre il vettore fino alla fine)*/

#include<stdio.h>

#define SIZE 7

int main()
{
	int A[SIZE] = {0};
	int flag = 1;

	for (int i = 0; i < SIZE-1; ++i)
	{
		if(A[i] != A[i+1]) flag = 0;
	}

	if(flag) printf("UGUALI\n");
	else printf("NO\n");

	return 0;
}