/*dati due vettori X ed Y contenenti
le coordinate di una serie di punti, calcolare una matrice D contente le distanze tra questi punti*/
/*d(P 1 , P 2 ) =
sqrt(x 1 − x 2 )² + (y 1 − y 2 )²*/

#include<stdio.h>
#include<math.h>

#define SIZE 4

int main()
{
	int X[SIZE] = {1,2,3,4};
	int Y[SIZE] = {1,2,3,4};
	float M[SIZE][SIZE] = {0};

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			M[i][j] = sqrt(pow(X[i]-X[j],2)+pow(Y[i]-Y[j], 2));
			printf("%.2f ", M[i][j]);
		}
		printf("\n");
	}

	return 0;
}