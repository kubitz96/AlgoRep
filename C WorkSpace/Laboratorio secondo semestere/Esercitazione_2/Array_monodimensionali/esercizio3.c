/*dato un vettore ed un valore k, ricerca di k all’interno di un vettore (versione NON ottimizzata,
usare un for (o while) che scorre il vettore fino alla fine)*/

#include<stdio.h>

#define SIZE 7

int main()
{
	int A[SIZE] = {1,3,5,-2,4,0,6};
	int k;
	int idx = -1;

	printf("Inserire valore di ricerca k\n");
	scanf("%d", &k);

	for (int i = 0; i < SIZE; ++i)
	{
		if(k == A[i]) idx = i;
	}

	if(idx != -1) printf("Il valore e' stato trovato in posizione %d\n", idx);
	else printf("Il valore non e' stato trovato\n");

	return 0;
}