#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_GIURIA		100
#define MAXVOTO			10
#define	MINVOTO			1


void initVectVoti(int *v, int n)
{
	int i;
	
	for (i=0; i<n; i++) {
		v[i] = rand() % (MAXVOTO-MINVOTO+1)  + MINVOTO;
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


void calcolaFrequenze(int *V, int nV, int *H)
{
	int i;
	
	for (i=0; i<nV; i++)
	{
		H[V[i]-MINVOTO] += 1;
	}
}



int main()
{
	int *V;
	int *H;

	srand(time(NULL));
	
	V = (int *) malloc(SIZE_GIURIA*sizeof(int));
	initVectVoti(V, SIZE_GIURIA);
	
	H = (int *) calloc((MAXVOTO-MINVOTO+1), sizeof(int));
	
	calcolaFrequenze(V, SIZE_GIURIA, H);
	printf("Le frequenze del vettore \n");
	wrtVect(V, SIZE_GIURIA);
	printf("sono\n");
	wrtVect(H, MAXVOTO-MINVOTO+1);
	
	free(V);
	
}


