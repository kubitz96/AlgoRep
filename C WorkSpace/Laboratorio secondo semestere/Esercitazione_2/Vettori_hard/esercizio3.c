/*dato un vettore
ed un indice di posizione idx, eliminazione dell’elemento in posizione tramite shift a sinistra*/

#include<stdio.h>

int main()
{
	int A[5] = {1,2,3,4,5};
	int idx = 3;
	int size = 5;

	A[idx] = 0;

	for (int i = idx; i < size-1; ++i)
	{
		int tmp;
		tmp = A[i];
		A[i] = A[i+1];
		A[i+1] = tmp;
	}

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}