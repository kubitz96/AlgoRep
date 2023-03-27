//Scrivere una funzione che, data una matrice in input,
// ne restituisca la sua trasposta in place, ossia sovrascrivendo la matrice originaria data in input

#include<stdio.h>

void traspostainplace(int righe ,int colonne, int matrice[][colonne]);
void stampamatrice(int row, int col, int mat[][col]);
void swap(int *a, int *b);

int main()
{
	int m = 2;
	int n = 3;

	int A[m][n];
	int h = 0;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j,++h)
		{
			A[i][j] = h;
		}
	}

	printf("Matrice originale \n");
	stampamatrice(m,n, A);

	traspostainplace(m,n, A);

	printf("Matrice trasposta\n");

	for (int i = 0; i < n; ++i) //codice copiato da stampamatrice
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Stampa sbagliata da stampamatrice\n");


	stampamatrice(n,m, A); // se uso la funzione invece del ciclo di stampa sopra(che è identico mi stampa la matrice sbagliata anche se il codice è copiato e incollato)

	return 0;
}

void stampamatrice(int row, int col, int mat[row][col])
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void traspostainplace(int righe ,int colonne, int matrice[][colonne])
{
	for (int i = 0; i < righe; ++i)
	{
		for (int j = i+1; j < colonne; ++j)
		{
			swap(&matrice[i][j], &matrice[j][i]);
		}
	}
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}