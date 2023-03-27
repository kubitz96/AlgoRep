//rappresentando i due insiemi A e B attraverso due array,
//implementare una funzione che restituisca il prodotto cartesiano A×B all'interno di una matrice,
//i.e. ogni riga rappresenta un elemento del prodotto cartesiano.

#include<stdio.h>

#define N 3
#define M 2

int main()
{
	int A[N] = {1,2,3};
	int B[N] = {4,5,6};
	int PC[N*N][2];

	for (int i = 0, index = 0; i < N; ++i)
	{	
		for (int t = 0; t < N; ++t, ++index)
		{
			int col = 0;
			PC[index][col] = A[i];
			++col;
			PC[index][col] = B[t];
		}
	}

	for (int i = 0; i < N*N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			printf("%d ", PC[i][j]);
		}
		printf("\n");
	}

}