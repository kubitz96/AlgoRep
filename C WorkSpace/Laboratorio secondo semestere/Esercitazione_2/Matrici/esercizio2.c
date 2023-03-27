//memorizzare le somme di ogni riga di una matrice in un vettore

#include<stdio.h>

int main()
{
	int A[3][3] = {1, 2, 3,
				   4, 5, 6,
				   7, 8, 9};
    int somma[3] = {0};

    for (int i = 0; i < 3; ++i)
    {
    	for (int j = 0; j < 3; ++j)
    	{
    		somma[i] += A[i][j];
    	}
    }for (int i = 0; i < 3; ++i)
    {
    	printf("%d ", somma[i]);
    }
    printf("\n");

    return 0;
}