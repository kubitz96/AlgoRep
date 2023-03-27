/*dato un vettore, stamparne un diagramma a barre fatto di * . esempio:
vettore: [ 3 6 4] la stampa sarà:
***
******
****
*/

#include<stdio.h>

#define SIZE 3

int main()
{
	int A[SIZE] = {3,6,4};

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < A[i]; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}