//sommare due matrici elemento memorizzandone i valori in una terza matrice

#include<stdio.h>

#define M 3
#define N 3

int main()
{
	int A[M][N] = {1, 1, 1,
				   1, 1, 1,
				   1, 1, 1};

	int B[M][N] = {2, 2, 2,
				   2, 2, 2,
				   2, 2, 2};

	int C[M][N] = {0};

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			C[i][j] = A[i][j] + B[i][j];
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	return 0;
}