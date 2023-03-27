//copiare gli elementi pari e dispari di un vettore in 2 vettori differenti

#include<stdio.h>

#define SIZE 4

int main()
{
	int A[SIZE] = {1,2,3,4};
	int pari = 0;
	int dispari = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (A[i] % 2 == 0) ++pari;
		else ++dispari;
	}

	int P[pari];
	int D[dispari];

	int p = 0;
	int d = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (A[i] % 2 == 0)
		{
			P[p] = A[i];
			++p;
		} 
		else
		{
			D[d] = A[i];
			++d;
		}
	}

	printf("Pari\n");
	for (int i = 0; i < pari; ++i)
	{
		printf("%d ", P[i]);
	}
	printf("\n");

	printf("Dispari\n");
	for (int i = 0; i < dispari; ++i)
	{
		printf("%d ", D[i]);
	}
	printf("\n");


	return 0;
}