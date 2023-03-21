#define SIZE 	10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//prototipi
void mergeSort(int array[], size_t lenght);
void sortSubArray(int array[], size_t low, size_t high); // low indice primo elemento, high indice ultimo
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right); //left e middle1 sono low e high sinistro, right e middle2 sono low e high destro;
void displayElements(int array[], size_t lenght);
void displaySubArray(int array[], size_t left, size_t right);

int main (void)
{
int array[SIZE];

	srand(time(NULL));	//iniziallizzo randomicamente l'array

	for (size_t i = 0; i < SIZE;i++)
	{
		array[i] = rand() % 90 +10; //valore randomico
	}

	puts("Unsorted Array");
	displayElements(array,SIZE);
	puts("\n");
	mergeSort(array,SIZE);
	puts("Sorted Array");
	displayElements(array,SIZE);
	puts("");
}

//definizioni di funzioni

void mergeSort(int array[], size_t lenght)		//overloading
{
	sortSubArray(array,0,lenght-1);	//funzione che effettivamente ordina l'array
}

void sortSubArray(int array[], size_t low, size_t high)
{
	if((high-low) >= 1) //se non si tratta del caso base
	{
		size_t middle1 = (low+high)/2;
		size_t middle2 = (middle1+1);

		printf("split:    ");	//passo di suddivisione
		displaySubArray(array, low, high);
		printf("\n         ");
		displaySubArray(array, low, middle1);
		printf("\n         ");
		displaySubArray(array, middle2, high);
		puts("\n");

		//chiamata ricorsiva sulle metà
		sortSubArray(array, low, middle1);
		sortSubArray(array, middle2, high);

		//fondo i due array ordinati
		merge(array, low, middle1, middle2, high);
	}
}

void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right) //fondo i due sottoarray in uno ordinato
{
	size_t leftindex = left; //indice array sinistro
	size_t rightindex = middle2; // indice array destro
	size_t combinedindex = left; //indice array temporaneo
	int temparray[SIZE];

	printf("merge:	");
	displaySubArray(array, left, middle1);
	printf("\n         ");
	displaySubArray(array, middle2, right);
	puts("\n");

	//fondo i due array finche non ne esaurisco uno
	while((leftindex <= middle1) && (rightindex <= right))
	{
		if(array[leftindex] <= array[rightindex])	//inserisco il piu piccolo dei due elementi correnti nell'array temporaneo e scorro avanti di posizione
		{
			temparray[combinedindex++] = array[leftindex++];
		}
		else
		{
			temparray[combinedindex++] = array[rightindex++];
		}
	}

	if (leftindex == middle2) // se finisce il sottoarray sinistro, copio il sottoarray destro così com'è.
	{
		while(rightindex <= right)
		{
			temparray[combinedindex++] = array[rightindex++];
		}
	}

	 else 	//se finisce il sottoarray destro copio il restante sinistro
	{
		while(leftindex <= middle1)
		{
			temparray[combinedindex++] = array[leftindex++];
		}
	}

	//ricopio il temporaneo sull'originario
	for (int i = left; i <= right; ++i)
	{
		array[i] = temparray[i];
	}

	//stampa sottoarrayfuso

	printf("         ");
	displaySubArray(array, left, right);
	puts("");
} 

void displayElements(int array[], size_t lenght) //stampa tutto l'array
{
	displaySubArray(array, 0, lenght-1);
}

void displaySubArray(int array[], size_t left, size_t right) //stampa solo un sotto array da left a right
{
	for (size_t i = 0; i < left; i++) //spazi vuoti se faccio array destro
	{
		printf("   ");
	}

	for (size_t i = left; i <= right; i++) //stampo elementi
	{
		printf(" %d", array[i]);
	}
}
