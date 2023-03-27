/*dato un vettore ed un valore k, ricerca di k all’interno di un vettore (ottimizzato, ossia il ciclo si
deve fermare quando l’elemento è stato trovato, USARE UN WHILE NON UN FOR)*/

#include<stdio.h>

#define SIZE 4

int main()
{
	int A[SIZE] = {1,2,3,5};
	int k = 2;
	int flag = 0;
	int i = 0;

	while(flag == 0 && i < SIZE)
	{
		if(k == A[i]) flag = 1;
		++i;
	}

	if(flag) printf("Trovato\n");
	else printf("No\n");

	return 0;
}