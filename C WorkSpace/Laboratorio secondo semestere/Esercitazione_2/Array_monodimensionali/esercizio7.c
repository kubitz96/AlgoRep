/*dati due vettori di uguale lunghezza, effettuarne la somma elemento per elemento e mem-
orizzazione in un terzo vettore. Esempio: dati A = 1,2,5,3, B = 2,4,1,2 allora RIS =
3,6,6,5*/

#include<stdio.h>

#define SIZE 4

int main()
{
	int A[SIZE] = {1,2,5,3};
	int B[SIZE] = {2,4,1,2};
	int RIS[SIZE] = {0};

	for (int i = 0; i < SIZE; ++i)
	{
		RIS[i] = A[i] + B[i];
		printf("%d ", RIS[i]);
	}
	printf("\n");

	return 0;
}