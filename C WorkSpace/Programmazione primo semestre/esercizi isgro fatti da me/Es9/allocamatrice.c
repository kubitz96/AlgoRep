#include<stdio.h>
#include<stdlib.h>

int **allocMatrix(int m, int n);                //m righe n colonne
int **allocContMatrix(int m, int n);
void initMatrix(int **p, int m, int n);
void initContMatrix(int **p, int m, int n);
void printMatrix(int **p, int m, int n);
void freeMatrix(int **p, int n);
int **callocMatrix(int m, int n);
void freeContMatrix(int **p);

int main()
{
    int **a;    //contigua
    int **b;    //non contigua
    int r, c;

    puts("Inserire numero righe e colonne");
    scanf("%d%d", &r, &c);

    a = allocContMatrix(r, c);
    initContMatrix(a, r, c);
    printMatrix(a, r, c);

    
    b = callocMatrix(r, c);
    printMatrix(b, r, c);
    
    freeContMatrix(a);
    freeMatrix(b, c);
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

int **allocContMatrix(int m, int n)
{
    int **p;

    p = malloc(m*sizeof(int*));              //MODALITA MEMORIA CONTIGUA

    if(p == NULL)
    {
        puts("Memoria non sufficiente!");
        return NULL;
    }

    p[0] = malloc(m*n*sizeof(int));

    if(p[0] == NULL)
    {
        puts("Memoria non sufficiente!");
        return NULL;
    }
    
    for (size_t i = 1; i < m; i++)
    {
        p[i] = p[i-1] + n;  //sto assegnando l'indirizzo del primo elemento di ogni riga, in questo caso e piu difficile ad accedere agli indirizzi poiche non si puo usare l' accesso a matrice(esempio matrix[3][5]) dato che l'abbiamo allocata come un singolo vettore quindi in questo modo matrix[m-1*n]
    }
    return p;
}
    

void initMatrix(int **p, int m, int n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            p[i][j] = i+j;
        }
    } 
}

void initContMatrix(int **p, int m, int n)      //metodo contiguo
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            p[i][j] = i+j;
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
    puts("");
}

void freeMatrix(int **p, int m)             //se contigua non ce bisogno del numero di righe m( righe perche il numero di riga corrisponde al nome del primo elemento di ogni vettore)
{
   // free(*p);       //OPPURE free(p[0])                      //metodo contiguo
   for (size_t i = 0; i < m; i++)           //dealloco sempre prima i vettori poi il vettore di vettori *p = p[0]
    {
        free(p[i]);
    }
    free(p);
}

void freeContMatrix(int **p)             //se contigua non ce bisogno del numero di righe m( righe perche il numero di riga corrisponde al nome del primo elemento di ogni vettore)
{
   free(p[0]);                          //metodo contiguo
    free(p);
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
        p[i] =calloc(n,sizeof(int));
    }
    return p;
}