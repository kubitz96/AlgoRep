#include <stdio.h>
#include <stdlib.h>



int main()
{
	int i, k, n;
	int p;
	int *V;
	
	
	printf("Inserisci l'intero n ");
	scanf("%d", &n);
	V = malloc(n*sizeof(int));
	for (i=0; i<n; i++) V[i] = 1;
	
	for (p=2; p<n+2; p++) {
		if (V[p-2] == 0) continue;
		for (k=2*p; k<n+2; k+=p) {
			V[k-2] = 0;
		}
	}
	
	for (i=0; i<n; i++)
	{
		if (V[i]==1) printf("%6d", i+2);
	}
	printf("\n");
}


