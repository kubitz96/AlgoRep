//Il prodotto tra due matrici 

#include<stdio.h>

#define N 5
#define M 3
#define T 2

int main()
{
	int A[N][T] = {2,2,2,2,2,
				   2,2,2,2,2};

	int B[N][M]= {1,1,1,
				  1,1,1,
				  1,1,1,
				  1,1,1,
				  1,1,1};

	int P[M][T] = {0};

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < T; ++j)
		{
			for (int h = 0; h < N; ++h)
			{
				P[i][j] += B[h][i] * A[h][j];
			}
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}

	return 0;
} //diagonale principale i = j, secondaria i + j = n-1
