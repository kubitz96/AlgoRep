//scrivere un programma che, date due matrici, calcoli e visualizzi la loro somma vettoriale

#include<stdio.h>

#define M 2
#define N 2

int main()
{
	int A[M][N] ={1,1,
				  1,1};

	int B[M][N] ={2,2,
				  2,2};
	int somma[M][N];

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			somma[i][j] = A[i][j]+ B[i][j];
			printf("%d ", somma[i][j]);
		}
		printf("\n");
	}

	return 0;
}