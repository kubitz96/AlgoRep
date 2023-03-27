/*data una matrice quadrata, dire se la diagonale principale è uguale alla diagonale secondaria*/

#include<stdio.h>

#define M 3
#define N 3

int main()
{
	int A[M][N] = {1, 2, 1,
				   4, 2, 6,
				   1, 8, 1};

	int flag = 1;
    int D[M] = {0};
    int S[M] = {0};

    for (int i = 0;flag && i < M; ++i)
    {
    	for (int j = 0; j < N; ++j)
    	{
    		if(i == j) D[i] = A[i][j];
    		if(i+j == N-1) S[i] = A[i][j];
    	}
    	if(D[i] != S[i]) flag = 0;
    }

    if(flag) printf("UGUALI\n");
    else printf("NO\n");

    return 0;
}