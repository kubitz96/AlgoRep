/*verificare se un dato vettore è uguale ad una o più righe di una matrice;
se sì, stampare in quali posizioni si trovano tali righe;*/

#include<stdio.h>

#define M 3
#define N 3
#define SIZE_B 2

int main()
{
	int A[M][N] = {1, 2, 6,
				   4, 2, 6,
				   2, 6, 1};

	int B[SIZE_B] ={2,6};

    for (int i = 0; i < M; ++i)
    {
    	for (int j = 0; N-j >= SIZE_B &&  j < N; ++j)
    	{
    		int contenuto = 1;

    		for (int t = j, h = 0; contenuto && t < SIZE_B+j; ++t, ++h)
    		{
    			if(B[h] != A[i][t]) contenuto = 0;
    		}

    		if(contenuto == 1) printf("il vettore e' contenuto in riga %d \n", i);
    	}
    }
    
    return 0;
}