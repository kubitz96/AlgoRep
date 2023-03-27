#include <stdio.h>
#include <stdlib.h>

int readFile(const char *nomeFile, float *V, int Nmax);
void printVect(float *V, int N);
int removeVals(float *V, int N, int k);
void newVect(float *V, float *W, int N, int k1, int k2);
void writeFile(const char *nomeFile, float *V, int N);

#define MAX_SIZE	1000
int main()
{
	float V[MAX_SIZE], W[MAX_SIZE];
	int N;
	int k, k1, k2;
	
	N = readFile("input.txt", V, MAX_SIZE);
	printf("I valori letti sono:\n");
	printVect(V, N);
	
	printf("Inserisci la soglia k per eliminare valori ");
	scanf("%d", &k);
	N = removeVals(V, N, k);
	printf("V dopo la rimozione dei valori\n");
	printVect(V, N);
	
	printf("Inserisci le soglie k1 e k2  ");
	scanf("%d%d", &k1, &k2);
	newVect(V, W, N, k1, k2);
	printf("Gli elementi di W:\n");
	printVect(W, N);
	writeFile("output.txt", W, N);
	
}
#undef MAX_SIZE


#define FILE_READ_ERROR		10
#define	FILE_WRITE_ERROR	20
#define MEMORY_ALLOC_ERROR	30
#define TOO_MANY_VALUES		40

void gestisciErrore(int code)
{
	if (code==FILE_READ_ERROR) {
		printf("Errore apertura file in lettura\n");
	}
	if (code==FILE_WRITE_ERROR) {
		printf("Errore apertura file in scrittura\n");
	}
	if (code==MEMORY_ALLOC_ERROR) {
		printf("Errore allocazione memoria\n");
	}
	if (code==TOO_MANY_VALUES) {
		printf("Troppi valori in input\n");
	}
	
	exit(-1);
}


int readFile(const char *nomeFile, float *V, int Nmax)
{
	FILE *fp;
	float val;
	int n=0;
	int i;
	
	fp = fopen(nomeFile, "r");
	if (fp == NULL) {
		gestisciErrore(FILE_READ_ERROR);
	}
	
	while (fscanf(fp,"%f", &val)==1 ) {
		if (n<Nmax) {
			V[n] = val;
			n = n + 1;
		} else {
			gestisciErrore(TOO_MANY_VALUES);
		}		
	}
	
	
	fclose(fp);
	
	return n;
}


void printVect(float *V, int N)
{
	int i;
	
	for (i=0; i<N; i++) {
		printf("%.2f ", V[i]);
	}
	printf("\n");
}


int removeVals(float *V, int N, int k)
{
	int *flags;
	int i, n;
	
	flags = (int *) calloc(N, sizeof(int));
	for (i=0; i<N; i++) {
		if (V[i] >=k) {
			flags[i] = 1;
		}
	}
	
	n = 0;
	for (i=0; i<N; i++) {
		if (flags[i] == 1) {
			V[n] = V[i];
			n = n+1;
		}
	}
	
	free(flags);
	
	return n;
}


void newVect(float *V, float *W, int N, int k1, int k2)
{
	int count1, count2;
	int *flags;
	int i, index1, index2, index3;
	
	flags = calloc(N, sizeof(int));
	if (flags == NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	
	count1 = count2 = 0;
	for (i=0; i<N; i++) {
		if (V[i] < k1 ) {
			count1++;
			flags[i] = 1;
		} else if ( k1 <= V[i] && V[i] <= k2) {
			count2++;
			flags[i] = 2;
		} 
	}
	
	index1 = 0; index2 = count1; index3 = count1 + count2;
	for (i=0; i<N; i++) {
		if (flags[i] == 1) {
			W[index1] = V[i];
			index1++;
		} else if (flags[i] == 2) {
			W[index2] = V[i];
			index2++;
		} else {
			W[index3] = V[i];
			index3++;
		}
	}
	
}


void writeFile(const char *nomeFile, float *V, int N)
{
	FILE *fp;
	int i;
	
	fp = fopen(nomeFile, "w");
	if (fp == NULL) {
		gestisciErrore(FILE_WRITE_ERROR);
	}
	
	for (i=0; i<N; i++) {
		fprintf(fp, "%.2f ", V[i]);
	}
	fclose(fp);
}
