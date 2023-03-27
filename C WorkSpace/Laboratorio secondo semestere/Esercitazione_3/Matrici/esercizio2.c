//Scrivere un programma che, data una matrice ed un vettore, ne calcoli il prodotto

#include<stdio.h>

#define N 5
#define M 3

int main()
{
	int A[N] = {2,2,2,2,2};

	int B[N][M]= {1,1,1,
				  1,1,1,
				  1,1,1,
				  1,1,1,
				  1,1,1};

	int P[M] = {0};

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			P[i] += B[j][i] * A[j];
		}
		printf("%d ", P[i]);
	}

	return 0;
}