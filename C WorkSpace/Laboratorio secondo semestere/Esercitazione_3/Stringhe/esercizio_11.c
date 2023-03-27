/*data una stringa S ed un vettore di interi V,
inserire in V il numero di occorrenze di ogni carattere di S esempio: S= [ p i p p o \0 ] allora V= [ 3 1 3 3 1 ]*/

#include<stdio.h>

#define SIZE 6

int main()
{
	char S[SIZE] = "pippo";
	int V[SIZE-1] = {0};

	for (int i = 0; i < SIZE-1; ++i)
	{
		for (int j = 0; j < SIZE-1; ++j)
		{
			if(S[i] == S[j]) ++ V[i];
		}
	}

	for (int i = 0; i < SIZE-1; ++i)
	{
		printf("%d ", V[i]);
	}
	printf("\n");

	return 0;
}