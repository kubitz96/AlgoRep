//copiare la diagonale principale di una matrice in un vettore

//memorizzare le somme di ogni riga di una matrice in un vettore

#include<stdio.h>

int main()
{
	int A[3][3] = {1, 2, 3,
				   4, 1, 6,
				   7, 8, 1};
                   
    int diagonale[3] = {0};

    for (int i = 0; i < 3; ++i)
    {
    	for (int j = 0; j < 3; ++j)
    	{
    		if(i == j) diagonale[i] += A[i][j];
    	}
    }

    for (int i = 0; i < 3; ++i)
    {
    	printf("%d ", diagonale[i]);
    }
    printf("\n");

    return 0;
}