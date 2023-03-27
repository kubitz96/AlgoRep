/*dato un vettore, calcolare e stampare i valori assoluti di tutti gli elementi contenuti al suo
interno*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 7

int main()
{
	int A[SIZE] = {-1,-3,-5,-2,-4,-1,-6};

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d ", abs(A[i]));
	}
	printf("\n");

	return 0;
}