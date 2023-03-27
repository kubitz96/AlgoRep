/*data una matrice e due interi
pos1 e pos2, scambiare le due righe nelle posizioni posizioni corrispondenti*/

#include<stdio.h>

#define M 3
#define N 3

int main()
{
	int A[M][N] = {1, 1, 1,
				   2, 2, 2,
				   3, 3, 3};
	int pos1 = 1;
	int pos2 = 0;

	int tmp;

	for (int i = 0; i < M; ++i)
	{
		tmp = A[pos1][i];
		A[pos1][i] = A[pos2][i];
		A[pos2][i] = tmp;
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}