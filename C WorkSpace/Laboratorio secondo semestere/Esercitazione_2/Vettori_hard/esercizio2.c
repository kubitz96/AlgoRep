/*dato un vettore A ed un vettore
B di lunghezza ≤ alla lunghezza di A, determinare se il vettore B è un sottovettore di A (ossia se
esiste una sequenza di elementi in A uguale all’intera sequenza di elementi in B)*/

#include<stdio.h>

#define SIZE_A 5
#define SIZE_B 3

int main()
{
	int A[SIZE_A] = {6,7,1,2,3};
	int B[SIZE_B] = {1,2,3};
	int flag = 0;

	for (int i = 0; i < SIZE_A && flag == 0 && SIZE_A-i >= SIZE_B; ++i)
	{
		flag = 1;

		for (int j = 0, t = i; j < SIZE_B && flag == 1; ++j, ++t)
		{
			if(A[t] != B[j]) flag = 0;
		}
	}

	if(flag) printf("Sottovettore\n");
	else printf("No\n");

	return 0;
}