//copiare gli elementi nelle posizioni pari e dispari di un vettore in 2 vettori differenti.
//sto considerano la posizione A[0] come PRIMA posizione quindi dispari e A[1] come SECONDA quindi pari.
#include<stdio.h>

#define SIZE 4

int main()
{
	int A[SIZE] = {1,2,3,4};
	int pari = 0;
	int dispari = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 0) ++dispari;
		else ++pari;
	}

	int P[pari];
	int D[dispari];

	int p = 0;
	int d = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 0)
		{
			D[d] = A[i];
			++d;
		} 
		else
		{
			P[p] = A[i];
			++p;
		}
	}

	printf("Posizione Pari\n");
	for (int i = 0; i < pari; ++i)
	{
		printf("%d ", P[i]);
	}
	printf("\n");

	printf("Posizione Dispari\n");
	for (int i = 0; i < dispari; ++i)
	{
		printf("%d ", D[i]);
	}
	printf("\n");


	return 0;
}