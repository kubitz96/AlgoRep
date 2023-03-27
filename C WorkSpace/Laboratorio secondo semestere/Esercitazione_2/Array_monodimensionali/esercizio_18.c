/*calcolare le occorrenze di ogni valore all’interno di un vettore (ossia contare quante volte
appare ogni elemento di un vettore). Esempio: - Vettore: 1 2 2 5 1 5 5 1 2 2 3 1 -
Risultato: 4 4 4 3 4 3 3 4 4 4 1 4 in quanto: - ci sono 4 numeri 1, ci sono 4 numeri 2, ci
sono 4 numeri 2, ci sono 3 numeri 5, ci sono 4 numeri 1 ci sono 3 numeri 5 e così via; ogni
posizione i-esima del vettore Risultato deve contenere il conteggio di quante volte appare in
Vettore l’elemento in posizione i-esima*/

#include<stdio.h>

#define SIZE 12

int main()
{
	int A[SIZE] = {1,2,2,5,1,5,5,1,2,2,3,1};
	int B[SIZE] = {0};

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if(A[i] == A[j]) ++B[i];
		}
		printf("%d ", B[i]);
	}
	printf("\n");

	return 0;
}