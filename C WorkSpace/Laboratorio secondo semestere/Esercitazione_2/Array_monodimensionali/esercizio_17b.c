/*dato un vettore X , calcolare la somma S di ogni numero elevato alla rispettiva posizione.
Esempio: X = [3 5 2 7] allora S=3^1+5^2+2^3+7^4*/

#include<stdio.h>
#include<math.h>

#define SIZE 4

int main()
{
	int X[SIZE] = {3,5,2,7};
	int S = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		S += pow(X[i], i+1);
	}

	printf("%d \n", S);

	return 0;
}