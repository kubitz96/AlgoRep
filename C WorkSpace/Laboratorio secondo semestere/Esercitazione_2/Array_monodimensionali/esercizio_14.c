//Dato un vettore, rovesciarlo in loco

#include<stdio.h>

#define SIZE 6

int main()
{
	int A[SIZE] = {1,2,3,4,5,6};
	int tmp;

	for(int i = 0, j = SIZE-1; i < SIZE/2; ++i, --j)
	{
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
	}

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}