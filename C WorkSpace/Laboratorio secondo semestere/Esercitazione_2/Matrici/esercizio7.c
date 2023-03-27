//data una matrice, scrivere un programma che determini qual è la colonna col maggior numero di elementi pari

#include<stdio.h>

#define M 3
#define N 3

int main()
{
	int A[M][N] = {1, 1, 2,
				   7, 2, 6,
				   2, 8, 8};
	int max = 0;
	int idx;

	for (int i = 0; i < N; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < M; ++j)
		{
			if(A[j][i] % 2 == 0) ++cnt;
		}
		if(cnt > max)
		{
			max = cnt;
			idx = i;
		} 
	}

	if(max == 0) printf("nessun pari trovato\n");
	else printf("Colonna %d ", idx);

	return 0;
}