#include <stdio.h>
#include <stdlib.h>

int **matrix_alloc(int n, int m);

void free_matrix(int **a, int n);

void init_matrix(int **a, int n, int m);

void print_matrix(int **a, int n, int m);


int main()
{
    int **matrix;
    int r, c;

    printf("Righe e colonne \n");
    scanf("%d %d", &r, &c);

    matrix = matrix_alloc(r, c);

    init_matrix(matrix, r, c);

    print_matrix(matrix, r, c);

}

int **matrix_alloc(int n, int m)    // ALLOCAZIONE MATRICE
{
    int i;
    int **p;

    p = (int **) calloc(n, sizeof(int *));
    for (i=0; i<n; i++)
        p[i] = (int *) calloc(m, sizeof(int ));
    return **p;
}

void free_matrix(int **a, int n)
{
    for (int i = 0; i < n; i++){
        free(a[i]);
        free(a);
    }
}


void init_matrix(int **a, int n, int m)
{
    int i, j; // contatori

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++){
            printf("Inserisci elemento [%d][%d]: ", i, j);
            scanf ("%d ", &a[i][j]);
        }
}

void print_matrix(int **a, int n, int m)
{
    int i, j;

    for (i=0; i < m; i++) {
        for (j=0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}