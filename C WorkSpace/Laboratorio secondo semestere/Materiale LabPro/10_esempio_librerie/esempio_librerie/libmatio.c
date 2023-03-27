
#include "matio.h"
#include <stdio.h>

void stampa_vett(int vett[], int n)
{
    printf("(");
    for(int i=0; i<n; i++)
        printf("%d,", vett[i]);
    printf("\b)\n");
}

void stampa_mat(int mat[][MAX_COLS], int n_r, int n_c)
{
    printf("(\n");
    for(int i = 0; i < n_r; i++)
    {
        for(int j = 0; j < n_c; j++)
            printf(" %d, ", mat[i][j]);
        printf("\b\b\n");
    }
    printf(")\n");
}

