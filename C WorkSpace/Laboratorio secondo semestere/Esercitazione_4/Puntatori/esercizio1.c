//implementare una funzione che accetta un vettore, restituire due variabili,
// la prima contenente il numero di elementi pari presenti nel vettore e la seconda il numero di elementi dispari
// (utilizzare il passaggio di parametri tramite puntatore per restituire i risultati)

#include<stdio.h>

#define N 10

void funzionepardi(int A[], int n, int * pari, int* dispari);

int main()
{
	int V[N] = {1,2,3,4,5,6,7,8,9,10};
	int cntp;
	int cntd;

	funzionepardi(V, N, &cntp, &cntd);

	printf("%d pari, %d dispari\n", cntp, cntd);

	return 0;
}

void funzionepardi(int A[], int n, int * pari, int* dispari)
{
	for (int i = 0; i < n; ++i)
	{
		if(A[i] % 2 == 0) *pari += 1;
		else *dispari += 1;
	}
}
