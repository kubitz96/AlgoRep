#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MEMORY_ALLOCATION_ERROR 10
#define WRONG_DATA 5

float **allocMatrix(int m, int  n);
void initRandMatrix(float **p, int m, int n);
void printMatrix(float **p, int m, int n);
void freeMatrix(float **p, int m);
float **productMatrix(float **A, float **B, int mA, int nA, int mB, int nB, int *mC, int *nC);
void errorManager(int code);

int main()
{
    float **A, **B, **C;
    int mA, nA, mB, nB, mC, nC;

    puts("Inserire dimensioni m e n per matrice A");
    scanf("%d%d", &mA, &nA);

    A = allocMatrix(mA, nA);
    initRandMatrix(A, mA, nA);

    puts("Inserire dimensioni m e n per matrice B");
    scanf("%d%d", &mB, &nB);

    if(nA != mB) errorManager(WRONG_DATA);

    B = allocMatrix(mB, nB);
    initRandMatrix(B, mB, nB);

    puts("La Matrice A");
    printMatrix(A, mA, nA);

    puts("La Matrice B");
    printMatrix(B, mB, nB);

    C = productMatrix(A, B, mA, nA, mB, nB, &mC, &nC);

    puts("La Matrice C risultate dal prodotto tra A e B");
    printMatrix(C, mC, nC);

    freeMatrix(A, mA);
    freeMatrix(B, mB);
    freeMatrix(C, mC);

    return 0;
}

void errorManager(int code)
{
    switch (code)
    {
    case MEMORY_ALLOCATION_ERROR:
        fprintf(stderr, "Insufficient Memory!\n");
        break;

    case WRONG_DATA:
        fprintf(stderr, "Wrong Data for Matrix Product!\n");
        break;

    default: fprintf(stderr, "Unknow Error!\n");
        break;
    }

    exit(-1);
}

float **allocMatrix(int m, int  n)
{
    float **p;

    p = (float **) malloc(m*sizeof(float*));

    for (int i = 0; i < m; i++)
    {
        p[i] = (float *)calloc(n,sizeof(float));
    }
    
    return p;
}

void initRandMatrix(float **p, int m, int n)
{
    srand(time(NULL));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p[i][j] = (float)rand()/RAND_MAX;
        }
    }
}

void printMatrix(float **p, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f ", p[i][j]);
        }
        puts("");
    }
    puts("");
}

void freeMatrix(float **p, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(p[i]);
    }
    free(p);
}

float **productMatrix(float **A, float **B, int mA, int nA, int mB, int nB, int *mC, int *nC)
{
    float **C;

    C = allocMatrix(mA, nB);

    *mC = mA;
    *nC = nB;

    for (int i = 0; i < mA; i++)
    {
        for (int j = 0; j < nB; j++)
        {
            for (int h = 0; h < nA; h++) // corrisponde alle passate totali per assegnare i valori a C, h sono le colonne di A e le righe di B che sono uguali quindi posso racchiudere queste passate in unico indice
            {
                C[i][j] += A[i][h] * B[h][j];
            }
        }
    }
    return C;
}