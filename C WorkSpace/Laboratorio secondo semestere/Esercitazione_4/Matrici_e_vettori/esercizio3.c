//Scrivere una funzione che, data una matrice in input, ne restituisca la sua trasposta in una matrice di output.

#include<stdio.h>

void trasposta(int righe ,int colonne, int matrice[][colonne], int outmatrice[][righe]);
void stampamatrice(int righe, int colonne, int matrice[][colonne]);

int main()
{
	int m = 2;
	int n = 3;

	int A[m][n];

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			A[i][j] = i+j+1;
		}
	}

	stampamatrice(m,n, A);

	int B[n][m];

	trasposta(m,n, A,B);

	stampamatrice(n,m, B);

	return 0;
}

void stampamatrice(int righe, int colonne, int matrice[][colonne])
{
	for (int i = 0; i < righe; ++i)
	{
		for (int j = 0; j < colonne; ++j)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void trasposta(int righe ,int colonne, int matrice[][colonne], int outmatrice[][righe])
{
	for (int i = 0; i < colonne; ++i)
	{
		for (int j = 0; j < righe; ++j)
		{
			outmatrice[i][j] = matrice[j][i];
		}
	}
}

