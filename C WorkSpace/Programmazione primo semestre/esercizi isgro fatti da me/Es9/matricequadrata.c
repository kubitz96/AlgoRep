#include<stdio.h>
#include<stdlib.h>

int **allocMatrix(int m, int n);                //m righe n colonne
void initMatrix(int **p, int m, int n);
void printMatrix(int **p, int m, int n);
void freeMatrix(int **p, int n);
int checkSimmetry(int **p, int m, int n);

int main()
{
    int **a;
    int n;
    int sim;

    puts("Inserire singolo numero righe e colonne per matrice quadrata");
    scanf("%d", &n);

    a = allocMatrix(n, n);
    initMatrix(a, n, n);
    printMatrix(a, n, n);

    sim = checkSimmetry(a, n, n);

    if(sim) puts("la matrice e' simmetrica");
    else puts("la matrice non e' simmetrica");

    freeMatrix(a, n);
}

int **allocMatrix(int m, int n)
{
    int **p;

    p = (int **) malloc(m*sizeof(int*)); 

    if(p == NULL)
    {
        puts("Memoria non sufficiente!");
        return NULL;
    }

    for (size_t i = 0; i < m; i++)
    {
        p[i] = malloc(n*sizeof(int));
    }

    return p;
}

void initMatrix(int **p, int m, int n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            p[i][j] = i+j;               //i/(j+1) per asimmetrica;
        }
        
    }
    
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

void freeMatrix(int **p, int m)
{
    for (size_t i = 0; i < m; i++)      
    {
        free(p[i]);
    }
    free(p);
}

int checkSimmetry(int **p, int m, int n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = i+1; j < n; j++)          //ciclo di controlli superflui se j = 0(controlla sia sopra che sotto la diagonale), se j=i controlla solo gli elementi della diagonale, se faccio piu uno controlla solo quelli sopra, se -1 controlla quelli sotto
        {
            if(p[j][i] != p[i][j]) return 0; 
        }
        
    }
    return 1;
}