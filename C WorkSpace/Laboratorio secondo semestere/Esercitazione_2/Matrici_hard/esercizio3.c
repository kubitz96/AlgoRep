//date due matrici M1 e M2, dire, per ogni riga di M2, se ne esiste soltanto una uguale in M1

#include<stdio.h>

#define M 3
#define N 3
#define R 2
#define C 2

int main()
{
	int M1[M][N] = {8, 9, 3,
					4, 5, 6,
					7, 8, 9};

	int M2[R][C] = {5, 6,
				    8, 9};

	int TMP[C] = {0};

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			TMP[j] = M2[i][j];
		}

		int cnt = 0;

		for (int h = 0; h < M; ++h)
    	{
    		for (int z = 0; N-z >= C &&  z < N; ++z)
    		{
    			int contenuto = 1;

    			for (int t = z, y = 0; contenuto && t < C+z; ++t, ++y)
    			{
    				if(TMP[y] != M1[h][t]) contenuto = 0;
    			}

    			if(contenuto == 1) ++cnt;
    		}
    	}
    	if(cnt == 1) printf("La riga %d di M2 e' contenuta solo una volta in M1\n", i);
	}

	return 0;
}