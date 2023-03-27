/*Dato un heap H (di interi) rappresentato con vettore statico, scrivere una procedura che, in tempo logaritmico,
 presi in input H e un valore numerico v presente in H (con relativo indice di posizione di v nel vettore),
  rimuova v da H, mantenendo la proprietà di heap.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE	10

void initHeapArray(int array[], int n);
void printArray(int array[],int n);
void heapSort(int array[], int n);
void swap(int *a,int *b);

int main()
{
	int A[SIZE] = {0};

	initHeapArray(A,SIZE);
	printf("Array Generato: ");
	printArray(A,SIZE);
}

void initHeapArray(int array[], int n)
{
    srand(time(NULL));
	
	for (int i = 0; i < n; ++i)
	{
		array[i] =rand()%100;
	}
}

void printArray(int array[],int n)
{
	printf("%4s", "[");
	for (int i = 0; i < n; ++i)
	{
		printf("%4d", array[i]);
	}
	printf("%4s\n", "]");
}

void heapSort(int array[], int n)
{
	buildHeap(array,n);
	 for (int i = n-1; i > 1; ++i)
	 {
	 	swap(&array[0],&array[i]);
	 	heapify(array,i,0);
	 }
}

void swap(int* a, int* b)
{
	int tmp = 0;
	*a = tmp;
	*b = *a;
	*a = *b;
}

