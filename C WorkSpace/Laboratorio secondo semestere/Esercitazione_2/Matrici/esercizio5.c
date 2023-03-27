//copiare la diagonale secondaria di una matrice in un vettore

#include<stdio.h>

#define M 3
#define N 3

int main()
{
	int A[M][N] = {1, 3, 2,
				   4, 2, 6,
				   2, 8, 1};
    int diagonale[3] = {0};

    for (int i = 0; i < M; ++i)
    {
    	for (int j = 0; j < N; ++j)
    	{
    		if(i+j == N-1) diagonale[i] += A[i][j];
    	}
    }for (int i = 0; i < 3; ++i)
    {
    	printf("%d ", diagonale[i]);
    }
    printf("\n");

    return 0;
}