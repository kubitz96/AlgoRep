#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS        100
#define MAX_COLUMNS     100

#define READ_ERR 10
#define MEMO_ERR 20

void readFile(const char *filename, int **matrix, int *righe, int *colonne);
int **allocMatrix(int m, int n);
void printMatrix(int **matrix, int m, int n);
void outFile(int **matrix, int m, int n);
void freeMatrix(int **matrix, int  m);
void ErrorManager(int code);

int main()
{
    int **matrixcase;
    char filename[20];
    int r, c;               //variabili vuote che riempirò tramite riferimento

    printf("Inserire Nome File\n");
    scanf("%s", filename);

    matrixcase = allocMatrix(MAX_ROWS, MAX_COLUMNS);

    readFile(filename, matrixcase, &r, &c); //se voglio passare i valori per riferimento a questo due variabili ho bisogno di &

    printMatrix(matrixcase, r, c);

    outFile(matrixcase, r, c);

    freeMatrix(matrixcase, r);

    return 0;
}

void readFile(const char *filename, int ** matrix, int *righe, int* colonne)
{
    FILE *fp;
    int row, col;
    int i, j;

    fp = fopen(filename, "r");
    if(fp == NULL) ErrorManager(READ_ERR);

    fscanf(fp, "%d%d", &row, &col);
    *righe= row;                        //passaggio dei valori per riferimento
    *colonne= col;

    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            fscanf(fp, "%d", &matrix[i][j]);        //ricordati che nello scanf bisogna usare & come un normale scan per le variabili
        }
        
    }
    
    fclose(fp);
}

int **allocMatrix(int m, int n)
{
    int **matrix;
    int i;

    matrix = calloc(m,sizeof(int*));
    if(matrix == NULL) ErrorManager(MEMO_ERR);
    
        for ( i = 0; i < m; i++)
        {
            matrix[i] = calloc(n,sizeof(int));
            if(matrix[i] == NULL) ErrorManager(MEMO_ERR);
        }

        return matrix;
}

void printMatrix(int **matrix, int m, int n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
    
}

void outFile(int **matrix, int m, int n)
{
    FILE *fp;

    fp = fopen("outmatrice.txt", "w");

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            fprintf(fp, "%d ", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void freeMatrix(int **matrix, int  m)
{
    for (size_t i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void ErrorManager(int code)
{
    switch (code)
    {
    case READ_ERR:
        fprintf(stderr, "Errore di Lettura File");
        break;
    case MEMO_ERR:
        fprintf(stderr, "Memoria Insufficiente");
        break;
    }
    exit(-1);
}