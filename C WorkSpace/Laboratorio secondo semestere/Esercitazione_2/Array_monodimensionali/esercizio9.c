/*concatenare due vettori in un terzo vettore. Esempio: dati A = 1,2,5,3, B = 2,4,1,2
allora RIS = 1,2,5,3,2,4,1,2*/


#include<stdio.h>

#define SIZE 4

int main()
{
	int A[SIZE] = {1,2,5,3};
	int B[SIZE] = {2,4,1,2};
	int RIS[SIZE+SIZE] = {0};

	for (int i = 0, j = 0; i < SIZE+SIZE; ++i)
	{
		if(i < SIZE)
		{
			RIS[i] = A[i];
			printf("%d ", RIS[i]);
		}
		else
		{
			RIS[i] = B[j];
			printf("%d ", RIS[i]);
			++j;
		}
	}

	printf("\n");

	return 0;
}