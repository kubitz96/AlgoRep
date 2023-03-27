#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void initVect(int *v, int n)
{
	int i;
	
	for (i=0; i<n; i++) {
		v[i] = rand() % 101;
	}
}

int isSorted(int *v, int n)
{
	int i;
	int sorted = 1;
	
	i = 0;
	while ( i < n-1 && sorted==1) {
		if (v[i] > v[i+1]) {
			sorted = 0;
		}
		i++;
	}
	
	return sorted;
}

void wrtVect(int *v, int n)
{
	int i;
	
	for (i=0; i<n; i++)  {
		printf("%d ", v[i]);
	}
	printf("\n");
}


void   swap(int *p, int *q)
{
	int   tmp;
	
	tmp = *p;
	*p = *q;
	*q = tmp;
}

void selection_sort(int *a, int n)     /* n is the size of a */
{
   int    i, j;

   for (i = 0; i < n - 1; ++i)
      for (j = i + 1; j < n ; j++)
         if (a[j] < a[i])
            swap(a+j, a+i);
}

int main()
{
	int n, *v;
	int sorted;
	
	printf("Inserisci dimensione vettore ");
	scanf("%d", &n);
	
	v = (int *) malloc(n*sizeof(int));
	if (v==NULL) {
		printf("Menoria non sufficiente\n");
		exit(-1);
	}
	
	srand(time(NULL));
	initVect(v, n);
	
	//verifica condizione oridnato
	//selection_sort(v, n);
	
	sorted = isSorted(v, n);
	
	printf("Il vettore\n");
	wrtVect(v,n);
	if (sorted) {
		printf("e ordinato\n");
	} else {
		printf("non e ordinat\n");
	}
	
}


