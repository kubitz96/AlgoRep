#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MEMORY_ALLOCATION_ERROR 10

void errorManager(int code);
int **allocMatrix(int m, int n);
void freeMatrix(int **p, int m);
void initMatrix(int **p, int m, int n);
void printMatrix(int **p, int m, int n);
int simmMatrix(int **p, int n);

int main()
{
    int **A;
    int mA, nA;
    int check;

    puts("Inserire quante righe e colonne della matrice");
    scanf("%d%d", &mA, &nA);

    A = allocMatrix(mA, nA);
    initMatrix(A, mA, nA);
    puts("Matrice A");
    printMatrix(A, mA, nA);

    if(mA == nA)
    {
        puts("La matrice e' quadrata");

        check = simmMatrix(A, nA);

        if(check) puts("La matrice e' simmetrica");
        else puts("La matrice non e' simmetrica");
    }

    freeMatrix(A, mA);

    return 0;
}

int **allocMatrix(int m, int n)
{
    int **p;

    p = malloc(m*sizeof(int));

    if(p == NULL) errorManager(MEMORY_ALLOCATION_ERROR);

    for (int i = 0; i < m; i++)
    {
        p[i] = malloc(n*sizeof(int));

        if(p[i] == NULL) errorManager(MEMORY_ALLOCATION_ERROR);
    }
    
    return p;
}

void freeMatrix(int **p, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(p[i]);
    }
    free(p);
}

void printMatrix(int **p, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", p[i][j]);
        }
        puts("");
    }
}

void initMatrix(int **p, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p[i][j] = i+j;
        }
    }
}

void errorManager(int code)
{
    switch (code)
    {
    case MEMORY_ALLOCATION_ERROR:
        fprintf(stderr, "Insufficient Memory Space!\n");
        break;
    
    default: fprintf(stderr, "Unknow Error!\n");
        break;
    }
    exit(-1);
}

int simmMatrix(int **p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(p[i][j] != p[j][i]) return 0;
        }
    }
    return 1;
}