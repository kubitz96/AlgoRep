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


int verifica(int *v, int n) 
{
	int i, j;
	int uguali = 0;
	
	for (i=0; uguali==0 && i<n-1; i++) {
		for (j=i+1; uguali==0 && j<n; j++) {
			if (v[i] == v[j]) {
				return uguali;
			}
		}
	}
	
	return uguali;
}



int main()
{
	int n, *v;
	int uguali;
	
	printf("Inserisci dimensione vettore ");
	scanf("%d", &n);
	
	v = (int *) malloc(n*sizeof(int));
	if (v==NULL) {
		printf("Menoria non sufficiente\n");
		exit(-1);
	}
	
	srand(time(NULL));
	initVect(v, n);
	
    uguali = verifica(v, n);
	
	printf("Il vettore\n");
	wrtVect(v,n);
	if (uguali) {
		printf("continee due elementi uguali\n");
	} else {
		printf("non contiene due elementi uguali\n");
	}
	
}


