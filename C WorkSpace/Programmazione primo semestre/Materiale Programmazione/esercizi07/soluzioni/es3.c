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


int verificaK(int *v, int n, int k) 
{
	int i;
	int contiene = 0;
	
	i = 0;
	while (i<n-1 && contiene == 0) {
		if (v[i] > k && v[i+1] > k) {
			contiene = 1;
		}
		i++;
	}
	
	return contiene;
}



int main()
{
	int n, *v, k;
	int contiene;
	
	printf("Inserisci dimensione vettore ");
	scanf("%d", &n);
	
	v = (int *) malloc(n*sizeof(int));
	if (v==NULL) {
		printf("Menoria non sufficiente\n");
		exit(-1);
	}
	
	srand(time(NULL));
	initVect(v, n);
	
	printf("Inserisci il valore di K ");
	scanf("%d",&k);
	
    contiene = verificaK(v, n, k);
	
	printf("Il vettore\n");
	wrtVect(v,n);
	if (contiene) {
		printf("contiene due elementi consecutivi maggiri di %d\n", k);
	} else {
		printf("non contiene due elementi consecutivi maggiori di %d\n",k);
	}
	
}


