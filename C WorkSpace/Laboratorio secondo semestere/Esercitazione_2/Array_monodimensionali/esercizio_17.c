/*dato due vettori di numeri A e B, inserire in una variabile T il valore:
• 1, se i due vettori sono uguali (es. A= [1 4 5] e B= [1 4 5])
• 2, se sono uno il “reverse” dell’altro (es. A= [1 4 5] e B= [5 4 1])
• 3, tutti gli altri casi.*/

#include<stdio.h>

#define SIZE_A 5
#define SIZE_B 5

int main()
{
	int A[SIZE_A] = {1,2,3,4,5};
	int B[SIZE_B] = {5,4,3,2,1};
	int check = 1;

	for (int i = 0; check == 1 && i < SIZE_A; ++i)
	{
		if(A[i] != B[i]) check = 3;
	}

	for (int i = 0, j = SIZE_B-1; check != 1 && i < SIZE_A/2; ++i, --j)
	{
		if(A[i] == B[j]) check = 2;
		else check = 3;
	}

	printf("check = %d\n", check);

	return 0;
}