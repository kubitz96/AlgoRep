/*dato un vettore A di numeri interi, creare un secondo vettore B contenente solo i valori di A
che siano compresi tra 10 e 20*/

#include<stdio.h>

#define SIZE 6

int main()
{
	int A[SIZE] = {6, 14, 11, 27, 8, 24};
	int b = 0;

	for (int i = 0; i < SIZE; ++i)
	 {
	 	if(A[i] >= 10 && A[i] <= 20) ++b;
	 }

	 int B[b];

	 for (int i = 0, j = 0; i < SIZE; ++i)
	 {
	 	if(A[i] >= 10 && A[i] <= 20)
	 	{
	 		B[j] = A[i];
	 		++j;
	 	}
	 }


	 for (int i = 0; i < b; ++i)
	 {
	 	printf("%d ", B[i]);
	 }
	 printf("\n");

	 return 0;
}