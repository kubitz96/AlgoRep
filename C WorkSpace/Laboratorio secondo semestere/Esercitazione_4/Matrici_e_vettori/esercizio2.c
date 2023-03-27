//Si generalizzi l'operazione precedente al caso in cui gli insiemi A e B siano rappresentati
// da due matrici in cui ogni riga corrisponde ad un elemento dell'insieme rappresentato.

#include<stdio.h>

#define N 2
#define M 2

int main ()
{
	int A[N][M] = {1,2,
				   3,4};

	int B[N][M] = {5,6,
				   7,8};

	int PC[N*N][M*M];

	for (int i = 0,index = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j,++index)
		{
			int col = 0;

			for (int t = 0; t < M; ++t,++col)
			{
				PC[index][col] = A[i][t];
			}

			for (int t = 0; t < M; ++t,++col)
			{
				PC[index][col] = B[j][t];
			}
		}
	}

	for (int i = 0; i < N*N; ++i)
	{
		for (int j = 0; j < M*M; ++j)
		{
			printf("%d ", PC[i][j]);
		}
		printf("\n");
	}

	return 0;
}
