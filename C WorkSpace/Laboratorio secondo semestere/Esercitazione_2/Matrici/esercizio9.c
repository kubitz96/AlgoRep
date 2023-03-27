/*copiare il perimetro di una matrice in un vettore*/

#include<stdio.h>

#define M 3
#define N 3

int main()
{
	int A[M][N] = {1, 2, 3,
				   4, 0, 5,
				   6, 7, 8};
	int B[(M+N-2)*2];
	int idx = 0;

	for(int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(i == 0 || i == M-1 || j == 0 || j == N-1)
			{
				B[idx] = A[i][j];
				printf("%d ", B[idx]);
				++idx;
			}
		}
	}
	printf("\n");

	return 0;
}