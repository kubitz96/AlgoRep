#include<stdio.h>
#include<stdlib.h>

int **callocMatrix(int m, int n);                //m righe n colonne
void initMatrix(int **p, int m, int n);
void printMatrix(int **p, int m, int n);
void freeMatrix(int **p, int n);
int **productMatrix(int **p, int **q, int rp, int cp, int rq, int cq);

int main()
{
    int **a, **b, **c;
    int ra, ca, rb, cb;

    puts("Inserire Righe e Colonne di matrice A");
    scanf("%d%d", &ra, &ca);

    a = callocMatrix(ra, ca);
    initMatrix(a, ra, ca);
    printMatrix(a, ra, ca);

    puts("Inserire Righe e Colonne di matrice B");
    scanf("%d%d", &rb, &cb);

    b = callocMatrix(rb, cb);
    initMatrix(a, rb, cb);
    printMatrix(a, rb, cb);

    c = productMatrix(a, b, ra, ca, rb, cb);

    puts("Matrice C");
    printMatrix(c, ra, cb);

    freeMatrix(a, ra);
    freeMatrix(b, rb);
    freeMatrix(c, ra);
}

int **callocMatrix(int m, int n)
{
    int **p;

    p = calloc(m,sizeof(int*)); 

    if(p == NULL)
    {
        puts("Memoria non sufficiente!");
        return NULL;
    }

    for (size_t i = 0; i < m; i++)
    {
        p[i] = calloc(n,sizeof(int));
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

int **productMatrix(int **p, int **q, int rp, int cp, int rq, int cq)
{
    int **c;
    int i, j;

    if(cp != rq)
    {
        puts("Il prodotto non e' possibile tra le due matrici");
        return NULL;
    }

    c = callocMatrix(rp, cq); 

    for (i = 0; i < rp; i++)
    {
        for (j = 0; j < cq; j++)
        { 
              for (size_t h = 0; h < rq; h++)
              {
                 c[i][j] = p[i][h] * q[h][j];
              }  
        }
    }
    return c;
}