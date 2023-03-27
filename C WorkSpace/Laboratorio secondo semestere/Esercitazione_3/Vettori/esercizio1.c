//scrivere un programma che, dati due vettori, calcoli e visualizzi il vettore somma risultante

#include<stdio.h>

#define SIZE 5

int main()
{
	int v[SIZE] = {1,2,3,4,5};
	int w[SIZE] = {5,4,3,2,1};
	int somma[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		somma[i] = v[i]+w[i];
		printf("%d ", somma[i]);
	}
	printf("\n");

	return 0;
}