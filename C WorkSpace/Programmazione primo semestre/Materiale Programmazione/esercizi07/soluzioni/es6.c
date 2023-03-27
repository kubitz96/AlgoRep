#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void initVect(int *v, int n)
{
	int i;
	
	for (i=0; i<n; i++) {
		v[i] = rand() % 11;
	}
}


void wrtVect(int *v, int n)
{
	int i;
	
	for (i=0; i<n; i++)  {
		printf("%d ", v[i]);
	}
	printf("\n");
}


int verificaInclusione(int *A, int nA, int *B, int nB)
{
	int i, j;
	int control = 1;
	
	for (i=0; control==1 && i<nB; i++) {
		control = 0;
		for (j=0; control==0 && j<nA; j++) {
			if (B[i] == A[j]) {
				control = 1;
			}
		}
	}
	
	return control;
}


int main()
{
	int n, m;
	int *A, *B;
	int control;
	
	printf("Inserisci dimensione vettore A ");
	scanf("%d", &n);
	
	printf("Inserisci dimensione vettore B ");
	scanf("%d", &m);
	
	A = (int *) malloc(n*sizeof(int));
	if (A==NULL) {
		printf("Menoria non sufficiente\n");
		exit(-1);
	}
	
	B = (int *) malloc(m*sizeof(int));
	if (B==NULL) {
		printf("Menoria non sufficiente\n");
		exit(-1);
	}
	
	
	srand(time(NULL));
	initVect(A, n);
	initVect(B, m);
	
	control = verificaInclusione(A,n,B,m);
	
	printf("Vettore A\n");
	wrtVect(A, n);
	
	printf("Vettore B\n");
	wrtVect(B, m);
	
	if (control) {
		printf("Tutti i valori del vettore B sono in A\n");
	} else {
		printf("Non tutti i valori del vettore B sono in A\n");
	}
	
	free(A);
	free(B);
}


