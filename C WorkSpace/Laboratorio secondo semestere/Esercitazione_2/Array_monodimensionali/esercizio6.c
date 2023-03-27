/*dato un vettore, calcolare i valori assoluti di tutti gli elementi contenuti al suo interno e
inserirli in un altro vettore nelle posizioni corrispondenti. Esempio: dato A = -1,3,-5,-2,9
allora RIS = 1,3,5,2,9*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int main()
{
	int A[SIZE] = {-1,3,-5,-2,9};
	int RIS[SIZE] = {0};

	for (int i = 0; i < SIZE; ++i)
	{
		RIS[i] = abs(A[i]);
		printf("%d ", RIS[i]);
	}
	printf("\n");

	return 0;
}