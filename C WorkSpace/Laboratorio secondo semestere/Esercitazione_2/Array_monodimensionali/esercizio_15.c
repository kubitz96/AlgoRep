/*dato un vettore A di numeri interi, creare un secondo vettore B contenente:
• 1, se il valore nella rispettiva posizione è multiplo di 3 o maggiore di 100,
• 2, altrimenti*/

#include<stdio.h>

#define SIZE 6

int main()
{
	int A[SIZE] = {6, 34, 111, 27, 8, 224};
	int B[SIZE] = {0};

	for (int i = 0; i < SIZE; ++i)
	 {
	 	if(A[i] % 3 == 0 || A[i] > 100) B[i] = 1;
	 	else B[i] = 2; 
	 }

	 for (int i = 0; i < SIZE; ++i)
	 {
	 	printf("%d ", B[i]);
	 }
	 printf("\n");

	 return 0;
}