//scrivere un programma che, dati due vettori, calcoli e visualizzi il loro prodotto scalare

#include<stdio.h>

#define SIZE 5

int main()
{
	int v[SIZE] = {1,2,3,4,5};
	int w[SIZE] = {5,4,3,2,1};
	int prod[SIZE];
	int somma = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		prod[i] = v[i]*w[i];
		//printf("%d ", prod[i]); per stampare i prodotti tra le coppie dei vettori
		somma += prod[i];
	}


	printf("Risultato totale %d\n", somma);

	return 0;
}