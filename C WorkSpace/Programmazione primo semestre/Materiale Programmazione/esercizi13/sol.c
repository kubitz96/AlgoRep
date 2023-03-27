#include <stdio.h>
#include <stdlib.h>

int **readFile(const char *fileName, int *Nrows, int *Ncols);
int verificaColonne(int **M, int Nrows, int Ncols);
int **newMatrix(int **M, int NrowsM, int NcolsM, int *NrowsOut, int *NcolsOut);
void writeFile(const char *fileName, int **M, int Nrows, int Ncols);
void freeMatrix(int **M);


int main()
{
	int **A, NrowsA, NcolsA;
	int **B, NrowsB, NcolsB;
	int control;
	
	A = readFile("matriceIn.txt", &NrowsA, &NcolsA);
	control = verificaColonne(A, NrowsA, NcolsA);
	if (control) {
		printf("La matrice verifica la condizione richiesta\n");
	} else {
		printf("La matrice non verifica la condizione richiesta\n");
	}
	B = newMatrix(A, NrowsA, NcolsA, &NrowsB, &NcolsB);
	writeFile("matriceOut.txt", B, NrowsB, NcolsB);
	
	freeMatrix(A);
	freeMatrix(B);
}


#define FILE_READ_ERROR		10
#define	FILE_WRITE_ERROR	20
#define MEMORY_ALLOC_ERROR	30

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
	
	exit(-1);
}

int **allocMatrix(int Nrows, int Ncols)
{
	int **M, i;
	
	M = (int **) malloc(Nrows*sizeof(int *));
	if (M == NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	
	M[0] = (int *) malloc(Nrows*Ncols*sizeof(int));
	if (M[0] == NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	
	for (i=1; i<Nrows; i++) {
		M[i] = M[i-1] + Ncols;
	}
	
	return M;
}

void freeMatrix(int **M)
{
	free(M[0]);
	free(M);
}

int **readFile(const char *fileName, int *Nrows, int *Ncols)
{
	FILE *fp;
	int **M, nrows, ncols;
	int i, j;
	
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		gestisciErrore(FILE_READ_ERROR);
	}
	fscanf(fp, "%d%d", &nrows, &ncols);
	
	M = allocMatrix(nrows, ncols);
	
	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			fscanf(fp,"%d", M[i]+j);
		}
	}
	
	fclose(fp);
	
	*Nrows = nrows;
	*Ncols = ncols;
	
	return M;
}

void writeFile(const char *fileName, int **M, int Nrows, int Ncols)
{
	FILE *fp;
	int i, j;
	
	fp = fopen(fileName, "w");
	if (fp == NULL) {
		gestisciErrore(FILE_WRITE_ERROR);
	}
	
	fprintf(fp, "%d %d\n", Nrows, Ncols);
	for (i=0; i<Nrows; i++) {
		for (j=0; j<Ncols; j++) {
			fprintf(fp, "%d ", M[i][j]);
		}
		if (i<Nrows-1) {
			fprintf(fp,"\n");
		}
	}
	
	fclose(fp);
}


int verificaUguali(int *v, int n)
{
	int i, j;
	
	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			if (v[i] == v[j]) return 0;
		}
	}
	
	return 1;
}

int verificaColonne(int **M, int Nrows, int Ncols)
{
	int *sommeCols;
	int control;
	int i, j;
	
	sommeCols = (int *) calloc(Ncols, sizeof(int));
	if (sommeCols == NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	
	for (j=0; j<Ncols-1; j++) {
		for (i=0; i<Nrows; i++) {
			sommeCols[j] = sommeCols[j] + M[i][j];
		}
	}
	
	control = verificaUguali(sommeCols, Ncols);
	
	free(sommeCols);
	
	return control;
}


int **newMatrix(int **M, int NrowsM, int NcolsM, int *NrowsOut, int *NcolsOut)
{
	int **A;
	int nrows, ncols;
	int indexRow;
	int i, j;
	
	nrows = 0;
	for (i=0; i<NrowsM; i++) {
		if (M[i][0] != 0) {
			nrows = nrows + 1;
		}
	}
	
	ncols = NcolsM;
	
	A = allocMatrix(nrows, ncols);
	indexRow = 0;
	
	for (i=NrowsM-1; i>=0; i--) {
		if (M[i][0] != 0) {
			for (j=0; j<NcolsM; j++) {
				A[indexRow][j] = M[i][j];
			}
			indexRow = indexRow + 1;
		}
	}
	
	*NrowsOut = nrows;
	*NcolsOut = ncols;
	
	return A;
}

