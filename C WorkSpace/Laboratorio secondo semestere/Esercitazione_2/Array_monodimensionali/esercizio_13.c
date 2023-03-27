//Dato un vettore, costruire un nuovo vettore uguale al primo rovesciato

#include<stdio.h>

int main()
{
	int A[3] = {1,2,3};
	int B[3] = {0};

	for(int i = 0, j = 2; i < 3; ++i, --j)
	{
		B[i] = A[j];
		printf("%d ", B[i]);
	}
	printf("\n");

	return 0;
}