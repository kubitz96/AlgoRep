#include<stdio.h>
#include<stdlib.h>

int **readFile(const char *filename, int *row, int*col);
void mkOutFile(int **matrix, int m, int n);
int **allocMatrix(int m, int n);
int checkMatrix(int **matrix, int m, int n);
int checkSame(int *vect, int size);
void printMatrix(int **p, int m, int n);
int **newMatrix(int **matrix, int row, int col, int *nrow, int *ncol);
void freeMatrix(int **matrix, int m);
void mkOutFile(int **matrix, int m, int n);


int main()
{
    char filename[20];
    int **matrixcase;
    int row, col;
    int check;
    int **newmat;
    int nrow, ncol;

    printf("Inserire Nome File\n");
    scanf("%s", filename);

    matrixcase = readFile(filename, &row, &col);
    puts("Prima Matrice");
    printMatrix(matrixcase, row, col);

    check = checkMatrix(matrixcase, row, col);

    if(check) puts("Esistono due colonne la cui somma di elementi e' uguale");
    else puts("Non esistono due colonne la cui somma di elementi e' uguale");

    newmat = newMatrix(matrixcase, row, col, &nrow, &ncol);

    puts("Nuova Matrice");
    printMatrix(newmat, nrow, ncol);

    mkOutFile(newmat, nrow, ncol);

    freeMatrix(matrixcase, row);
    freeMatrix(newmat, nrow);

}

int** readFile(const char *filename, int *row, int*col)
{
    int **matrix;
    FILE *fp;
    int r, c;

    fp = fopen(filename, "r");

    fscanf(fp, "%d%d", &r, &c);

    *row = r;
    *col = c;

    matrix = allocMatrix(r, c);

    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            fscanf(fp, "%d", &matrix[i][j]);
        }
            
    }

    fclose(fp);

    return matrix;
}

int **allocMatrix(int m, int n)
{
    int **matrix;

    matrix = calloc(m,sizeof(int*));

    if(matrix == NULL) puts("errore memoria");
    for (size_t i = 0; i < m; i++)
    {
        matrix[i] = calloc(n,sizeof(int));
        if(matrix[i] == NULL) puts("errore memoria");
    }
    
    
    return matrix;
}

int checkMatrix(int **matrix, int m, int n)

{
    int *sumcol;

    sumcol = malloc(n*sizeof(int)); // un vettore dove racchiudo le somme delle colonne


    for (size_t j = 0; j < n-1; j++)        //inverto la tabella per scorrere le colonne come righe quindi adesso m e indice di colonna e n indice di riga
    {
        for (size_t i = 0; i < m; i++)
        {
              sumcol[j] += matrix[i][j]; 
        }  
    }
    
    return checkSame(sumcol, n); // controllo se esistono due somme uguali
}

int checkSame(int *vect, int size)
{
    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = i+1; j < size; j++)
        {
            if(vect[i] == vect[j]) return 1;
        }
        
    }
    
    return 0;
}

void printMatrix(int **p, int m, int n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%4d", p[i][j]);
        }
        puts("");
    }
}

int **newMatrix(int **matrix, int row, int col, int *nrow, int *ncol)
{
    int **newmat;
    int newr = 0;
    int newc = col;

    for (int i = 0; i < row; i++)
    {
        if(matrix[i][0] != 0) ++newr;
    }
    

    newmat = allocMatrix(newr, newc);

    int index = 0;      //mi creo un contatore di indice apparte che incremento solo quando trovo una riga giusta

    for (int i = row-1; i >= 0; i--) //parto dall'ultima riga
    {
        if(matrix[i][0] != 0)
        {
            for (int j = 0; j < col; j++)
            {
                newmat[index][j] = matrix[i][j];
            }
            ++index;
        }
    }

    *nrow = newr;
    *ncol = newc;
    
    return newmat;
}

void freeMatrix(int **matrix, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    
    free(matrix);
}

void mkOutFile(int **matrix, int m, int n)
{
    FILE *fp;
    int i = 0;

    fp = fopen("out.txt", "w");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
             fprintf(fp, "%d ", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }
    
}