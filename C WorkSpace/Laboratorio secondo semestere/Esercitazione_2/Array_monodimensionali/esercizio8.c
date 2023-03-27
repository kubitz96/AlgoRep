//dato un vettore, verificare se è ordinato in modo crescente.

#include<stdio.h>

#define SIZE 4

int main()
{
	int A[SIZE] = {1,2,3,4};
	int flag = 1;

	for (int i = 0; i < SIZE-1; ++i)
	{
		if(A[i] > A[i+1]) flag = 0;
	}

	if(flag) printf("Crescente\n");
	else printf("No\n");

	return 0;
}