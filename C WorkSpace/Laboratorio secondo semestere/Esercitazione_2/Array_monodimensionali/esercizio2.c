//stampare la somma di tutti gli elementi in un vettore

#include<stdio.h>

#define SIZE 7

int main()
{
	int A[SIZE] = {1,3,5,-2,4,0,6};
	int somma = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		somma += A[i];
	}

	printf("la somma di tutti gli elementi del vettore e' %d\n", somma);

	return 0;
}