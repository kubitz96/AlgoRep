/*dato un vettore e date due variabili contenenti due indici di posizione,scambiare gli elementi
nelle posizioni date*/

#include<stdio.h>

int main()
{
	int A[4]= {1,2,3,4};
	int a = 1;
	int b = 3;
	int tmp;

	printf("%d %d\n", A[a], A[b]);

	tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;

	printf("%d %d\n", A[a], A[b]);

	return 0;
}