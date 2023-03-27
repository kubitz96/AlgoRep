/*costruire un vettore che sia l’intersezione di 2 vettori dati (ossia mettere gli elementi comuni
tra i due vettori in un terzo vettore senza ripetizioni)*/

#include<stdio.h>

#define SIZE_A 4
#define SIZE_B 5

int main ()
{
	int A[SIZE_A] = {1,2,3,5};
	int B[SIZE_B] = {3,2,5,5};
	int SIZE_C = 0;

	for (int i = 0; i < SIZE_A; ++i)
	{
		if(A[i] == 0) continue;

		for (int j = i+1; j < SIZE_A; ++j)
		{
			if(A[j] == 0) continue;
			if(A[i] == A[j]) A[j] = 0;
		}
	}

	for (int i = 0; i < SIZE_B; ++i)
	{
		if(B[i] == 0) continue;

		for (int j = i+1; j < SIZE_B; ++j)
		{
			if(B[j] == 0) continue;
			if(B[i] == B[j]) B[j] = 0;
		}
	}

	for (int i = 0; i < SIZE_A; ++i)
	{
		for (int t = 0; t < SIZE_B; ++t)
		{
			if(B[t] == 0) continue;
			if(A[i] == B[t]) ++SIZE_C;
		}
	}

	

	int C[SIZE_C];
	int c = 0;

	for (int i = 0; i < SIZE_A; ++i)
	{
		for (int t = 0; t < SIZE_B; ++t)
		{
			if(B[t] == 0) continue;
			if(A[i] == B[t])
			{
				C[c] = A[i];
				++c;
			}
		}
	}

	for (int i = 0; i < SIZE_C; ++i)
	{
		printf("%d ", C[i]);
	}
	printf("\n");

	return 0;
}