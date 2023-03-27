/*data una matrice, inserire le posizioni di tutti gli elementi negativi in due vettori,
 il primo contenente le posizioni di riga ed il secondo le posizioni di colonna*/

/*copiare il perimetro di una matrice in un vettore*/

#include<stdio.h>

#define M 3
#define N 3

int main()
{
	int A[M][N] = {-1, 2,-3,
				   4, -3, 5,
				   6, 7, -8};
	int cnt = 0;

	for(int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(A[i][j] < 0) ++cnt;
		}
	}
	
	int R[cnt];
	int C[cnt];

	int idx = 0;

	for(int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(A[i][j] < 0)
			{
				R[idx] = i;
				C[idx] = j;
				++idx;
			}
		}
	}

	for (int i = 0; i < cnt; ++i)
	{
		printf("(%d,%d) ", R[i], C[i]);
	}
	printf("\n");

	return 0;
}