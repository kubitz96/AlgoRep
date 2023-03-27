/*dato un vettore, eliminarne i duplicati tramite shift*/

void swap(int* a, int* b);

#include<stdio.h>

#define SIZE 5

int main()
{
	int A[SIZE] = {1,2,3,3,2};

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = i+1; j < SIZE; ++j)
		{
			if(A[i] == A[j])
			{
				A[j] = 0;
				for (int t = j; t < SIZE-1; ++t)
				{
					swap(A+t,A+t+1);
				}
			}
		}
	}

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}

void swap(int* a, int* b)
{
	int tmp;
		tmp = *a;
		*a = *b;
		*b = tmp;
}