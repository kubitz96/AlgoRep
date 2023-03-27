/*ricerca di un elemento all’interno di una matrice e memorizzazione
della posizione in una variabile pos*/

#include<stdio.h>

#define M 3
#define N 3

int main()
{
	int A[M][N] = {1, 2, 3,
				   4, 5, 6,
				   7, 8, 9};
    int k = 9;
    int pos;

    for (int i = 1; i < M; ++i)
    {
    	for (int j = 1; j < N; ++j)
    	{
    		if(k == A[i][j]);
    		pos = N*i+j+1; //maxcolonne*indiceriga + indicecolonna;
    	}
    }
    printf("%d\n", pos);

    return 0;
}