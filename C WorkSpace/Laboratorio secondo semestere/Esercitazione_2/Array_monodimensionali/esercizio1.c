/*determinare il minimo (massimo) presente in un vettore e stamparne a video sia valore che
la posizione in cui si trova. Esempio: dato A = 1,3,5,-2,4,0,6 allora stampa il minimo è
-2 e la posizione in cui si trova è 3*/

#include<stdio.h>

#define SIZE 7

int main()
{
	int A[SIZE] = {1,3,5,-2,4,0,6};
	int min = A[0];
	int idx = 0;

	for (int i = 1; i < SIZE; ++i)
	{
		if(min > A[i])
		{
			min = A[i];
			idx = i;
		}
	}

	printf("Il minimo del vettore e' %d e la posizione in cui si trova e' %d\n", min, idx);

	return 0;
}