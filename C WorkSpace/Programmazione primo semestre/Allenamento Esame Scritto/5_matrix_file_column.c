#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MEMORY_ALLOCATION_ERROR 10
#define READ_FILE_ERROR 20
#define WRITE_FILE_ERROR 30

int **allocMatrix(int m, int  n);
void printMatrix(int **p, int m, int n);
void freeMatrix(int **p, int m);
void errorManager(int code);
int **readFile(const char *filename, int*mP, int *nP);
int checkColumn(int **p, int m, int n);
int **newMatrix(int **A, int mA, int nA, int *mB, int *nB);
int checkSame(int *p, int n);
int *allocVect(int n);
void outFile(const char *filename, int **matrix, int m, int n);

int main()
{
    int **A, **B;
    int mA, nA, mB, nB;
    char filename[FILENAME_MAX];
    char fileoutname[FILENAME_MAX];
    int check;

    puts("Inserire nome File da leggere");
    scanf("%s", filename);

    A = readFile(filename, &mA, &nA);

    puts("Matrice A letta");
    printMatrix(A, mA, nA);

    check = checkColumn(A, mA, nA);

    if(check) puts("Esistono almeno due colonne della matrice A la cui somma degli elementi e' uguale");
    else puts("Non esistono due colonne della matricmatrie A la cui somma degli elementi e' uguale");

    B = newMatrix(A, mA, nA, &mB, &nB);

    puts("Nuova matrice B da scrivere");
    printMatrix(B, mB, nB);

    puts("Inserire nome File da scrivere");
    scanf("%s", fileoutname);

    outFile(fileoutname, B, mB, nB);

    freeMatrix(A, mA);
    freeMatrix(B, mB);

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

int **allocMatrix(int m, int  n)
{
    int **p;

    p = malloc(m*sizeof(int*));

    if(p == NULL) errorManager(MEMORY_ALLOCATION_ERROR);

    for (int i = 0; i < m; i++)
    {
        p[i] = calloc(n,sizeof(int));
        if(p[i] == NULL) errorManager(MEMORY_ALLOCATION_ERROR);
    }
    
    return p;
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
    puts("");
}

void freeMatrix(int **p, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(p[i]);
    }
    free(p);
}

int **readFile(const char *filename, int*mP, int *nP)
{
    FILE *fp;
    int **T;
    int mT, nT;

    fp = fopen(filename, "r");

    if(fp == NULL) errorManager(READ_FILE_ERROR);

    fscanf(fp, "%d%d", &mT, &nT);

    T = allocMatrix(mT, nT);

    *mP = mT;
    *nP = nT;

    while (!feof(fp))
    {
        for (int i = 0; i < mT; i++)
        {
            for (int j = 0; j < nT; j++)
            {
                fscanf(fp, "%d", &T[i][j]);
            }
        }
    }

    fclose(fp);
    return T;
}

int checkColumn(int **p, int m, int n)
{
    int *colsum;
    int check;

    colsum = allocVect(n);

    for (int j = 0; j < n; j++)     //scambio gli indici per operare sulle colonne
    {
        for (int i = 0; i < m; i++)
        {
            colsum[j] += p[i][j];
        }
    }

    check = checkSame(colsum, n);

    free(colsum);

    return check;
}

int checkSame(int *p, int n)
{
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = i+1; j < n; ++j) //devo mettere i+1 invece di 1 poiche al secondo passaggio mi ritroverei p[1] = p[1] che e sempre vero
        {
            if(p[i] == p[j]) return 1;
        }
    }
    return 0;
}

int *allocVect(int n)
{
    int *p;

    p = calloc(n,sizeof(int));

    if(p == NULL) errorManager(MEMORY_ALLOCATION_ERROR);

    return p;
}

int **newMatrix(int **A, int mA, int nA, int *mB, int *nB)
{
    int **B;
    int m = 0;
    int n = nA;

    for (int i = 0; i < mA; i++)    //conto le righe da allocare
    {
        if(A[i][0] != 0) ++m;
    }
    
    B = allocMatrix(m, n);

    *mB = m;
    *nB = n;

    int index = 0;

    for (int i = 0; i < m; i++)      //ora che so le righe totali assegno i valori con un index segnato che incrementa solo se trovo la riga
    {
        if(A[i][0] == 0) continue;

        for (int j = 0; j < n; j++)
        {
            B[index][j] = A[i][j];
        }
        ++index;
    }
    return B;
}

void outFile(const char *filenameout, int **T, int m, int n)
{
    FILE *fp;
    int i, j;

    fp = fopen(filenameout, "w");
    if (fp == NULL) errorManager(WRITE_FILE_ERROR);

    fprintf(fp, "%d %d\n", m, n);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(fp, "%d ", T[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}