//somma di tutti gli elementi di una matrice

#include<stdio.h>

int main()
{
	int A[3][3] = {1, 2, 3,
				   4, 5, 6,
				   7, 8, 9};
    int somma = 0;

    for (int i = 0; i < 3; ++i)
    {
    	for (int j = 0; j < 3; ++j)
    	{
    		somma += A[i][j];
    	}
    }
    printf("%d\n", somma);

    return 0;
}