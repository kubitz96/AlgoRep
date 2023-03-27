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
int **newMatrix(int **A, int mA, int nA, int *mB, int *nB);
int checkAllSame(int *p, int n);
int *allocVect(int n);
void outFile(const char *filename, int **matrix, int m, int n);
int isMagica(int **p, int n);
int sumColumn(int **p, int n);      //senza le m perche sono quadrate
int sumRow(int **p, int n);
int sumDiagonal(int **p, int n);

int main()
{
    int **A, **B;
    int mA, nA, mB, nB;
    char filename[FILENAME_MAX];
    char fileoutname[FILENAME_MAX];
    int magic;

    puts("Inserire nome File da leggere");
    scanf("%s", filename);

    A = readFile(filename, &mA, &nA);

    puts("Matrice A letta");
    printMatrix(A, mA, nA);

    if(mA == nA)
    {
        puts("La matrice e' quadrata");
        magic = isMagica(A, nA);

        if(magic) puts("la matrice e' magica");
        else puts("la matrice non e' magica");
    }
    else puts("la matrice non e' quadrata");

    puts("Inserire nome File da scrivere");
    scanf("%s", fileoutname);

    outFile(fileoutname, A, mA, nA);

    freeMatrix(A, mA);

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
    int mT, nT, i, j, val;

    fp = fopen(filename, "r");

    if(fp == NULL) errorManager(READ_FILE_ERROR);

    fscanf(fp, "%d%d", &mT, &nT);

    T = allocMatrix(mT, nT);

    *mP = mT;
    *nP = nT;

    while (!feof(fp))
    {
        fscanf(fp, "%d%d%d", &val, &i, &j);
        T[i-1][j-1] = val;          // -1 perche gli indici corrispondo a - 1 rispetto alla colonna e la riga poiche il conteggio parte da 0 nelle matrici;
    }

    fclose(fp);
    return T;
}

int sumColumn(int **p, int n)
{
    int *colsum;
    int check;
    int sum;

    colsum = allocVect(n);

    for (int j = 0; j < n; j++)     
    {
        for (int i = 0; i < n; i++)
        {
            colsum[j] += p[i][j];
        }
    }

    check = checkAllSame(colsum, n);
    if(check == 0) return 0;
    else sum = colsum[0];

    free(colsum);
    return sum;
}

int sumRow(int **p, int n)
{
    int *rowsum;
    int check;
    int sum;

    rowsum = allocVect(n);

    for (int i = 0; i < n; i++)     
    {
        for (int j = 0; j < n; j++)
        {
            rowsum[i] += p[i][j];
        }
    }

    check = checkAllSame(rowsum, n);
    if(check == 0) return 0;
    else sum = rowsum[0];

    free(rowsum);
    return sum;
}

int sumDiagonal(int **p, int n)
{
    int d1sum = 0;
    int d2sum = 0;

    for (int i = 0; i < n; i++)     
    {
        d1sum += p[i][i];
    }

    for (int i = 0, j=n-1; i < n ;i++, j--)    
    {
        d2sum += p[i][j];
    }

    if (d1sum != d2sum) return 0;

    return d1sum;
}

int isMagica(int **p, int n)
{
    int s1, s2, s3;

    s1 = sumColumn(p, n);
    s2 = sumRow(p, n);
    s3 = sumDiagonal(p, n);

    if(s1 != 0 && s1 == s2 && s2 == s3 ) return 1;

    return 0;
}

int checkAllSame(int *p, int n)
{
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = i+1; j < n; ++j) //devo mettere i+1 invece di 1 poiche al secondo passaggio mi ritroverei p[1] = p[1] che e sempre vero
        {
            if(p[i] != p[j]) return 0;
        }
    }
    return 1;
}

int *allocVect(int n)
{
    int *p;

    p = calloc(n,sizeof(int));

    if(p == NULL) errorManager(MEMORY_ALLOCATION_ERROR);

    return p;
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