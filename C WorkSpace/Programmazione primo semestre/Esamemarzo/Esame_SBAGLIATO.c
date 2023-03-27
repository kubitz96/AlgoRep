#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MEMORY_ALLOCATION_ERROR 10
#define READ_FILE_ERROR 20
#define WRITE_FILE_ERROR 30

float **allocMatrix(int m, int  n);
void printMatrix(float **p, int m, int n);
void freeMatrix(float **p, int m);
void errorManager(int code);
float **readFile(const char *filename, int*mP, int *nP);
float **newMatrix(float **A, int mA, int nA);
float *allocVect(int n);
void outFile(const char *filename, float **matrix, float*med, int m, int n);
void selectionSort(float *v, int n);
void swap(float *p, float *q);
float *findMed(float **A, int mA, int nA);
void printVect(float *v, int n);


int main()
{
    float **A, *B;
    int m, n;
    char filename[FILENAME_MAX];
    char fileoutname[FILENAME_MAX];

    puts("Inserire nome File da leggere");
    scanf("%s", filename);

    A = readFile(filename, &m, &n);

    puts("Matrice A letta");
    printMatrix(A, m, n);

    B = findMed(A, m, n);

    puts("Sequenza B di mediane");
    printVect(B, m);

    puts("Inserire nome File da scrivere");
    scanf("%s", fileoutname);

    outFile(fileoutname, A, B, m, n);

    freeMatrix(A, m);
    free(B);

    return 0;

}

void errorManager(int code)
{
    switch (code)
    {
    case MEMORY_ALLOCATION_ERROR:
        fprintf(stderr, "Insufficient Memory!\n");
        break;

    case READ_FILE_ERROR:
        fprintf(stderr, "Reading File Error!\n");
        break;

    case WRITE_FILE_ERROR:
        fprintf(stderr, "Writing File Error!\n");
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
    if(p == NULL) errorManager(MEMORY_ALLOCATION_ERROR);

    for (int i = 0; i < m; i++)
    {
        p[i] = (float *)calloc(n,sizeof(float));
        if(p[i] == NULL) errorManager(MEMORY_ALLOCATION_ERROR);
    }
    
    return p;
}

void printMatrix(float **p, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.4f ", p[i][j]);
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

float **readFile(const char *filename, int*mP, int *nP)
{
    FILE *fp;
    float **T;
    int m, n;
    int i, j;

    fp = fopen(filename, "r");

    if(fp == NULL) errorManager(READ_FILE_ERROR);

    fscanf(fp, "%d%d", &m, &n);

    T = allocMatrix(m, n);

    while (!feof(fp))
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                fscanf(fp, "%f", &T[i][j]);
            }
        }
    }

    *mP = m;
    *nP = n;

    fclose(fp);
    return T;
}

float *allocVect(int n)
{
    float *p;

    p =(float *)calloc(n,sizeof(float));

    if(p == NULL) errorManager(MEMORY_ALLOCATION_ERROR);

    return p;
}

float *findMed(float **A, int mA, int nA)
{
    float *M;
    float *row;

    M = allocVect(nA);
    row = allocVect(nA);
    
    for (int i = 0; i < mA; i++)
    {
        for (int j = 0; j < nA; j++)
        {
            row[j] = A[i][j];
        }
        
        selectionSort(row, nA);
        if(nA % 2 == 0)  M[i] = (row[nA/2 + 1] + row[nA/2])/2;
    }

    free(row);

    return M;
}

void outFile(const char *filenameout, float **T, float *M, int m, int n)
{
    FILE *fp;
    int i, j;

    fp = fopen(filenameout, "w");
    if (fp == NULL) errorManager(WRITE_FILE_ERROR);

    float *row;

    row = allocVect(m);

    int index= 0;

    for (int i = 0; i < n; i++)
    {
        M[index] = row[i];
        ++index;
    }
    
    selectionSort(M, n);                //provo ad ordinare gli indici ma non riesco a far stampare la nuova matrice  //manca poco alla consegna non so se ho abbastanza tempo per pensarci

    fprintf(fp, "%d %d\n", m, n);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)                            //non ho abbastanza
        {              
            fprintf(fp, "%f ", T[index][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void selectionSort(float *v, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(v[i] > v[j]) swap(v+j, v+i);
        }
    }
}

void swap(float *p, float *q)
{
    float tmp = *p;
    *p = *q;
    *q = tmp;
}

void printVect(float *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.4f ", v[i]);
    }
    puts("");
}
