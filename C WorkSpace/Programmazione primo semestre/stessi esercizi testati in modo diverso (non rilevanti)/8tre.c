#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arrayKey(int *p, int n, int k);
void initRandVect(int *p, int n);
void printVect(int *p, int n);
int *allocVect(int *p, int n);

int main()
{
    int *v;
    int dim, key;

    printf("Inserire dimensione vettore v\n");
    scanf("%d", &dim);

    v = allocVect(v, dim);
    initRandVect(v, dim);
    printVect(v, dim);

    printf("Inserire valore da trovare\n");
    scanf("%d", &key);

    key = arrayKey(v, dim, key);

    if(key) puts("Valore Trovato");
    else puts("Valore non Trovato");
   
}

void initRandVect(int *p, int n)
{
    srand(time(NULL));

    for (size_t i = 0; i < n; ++i)
    {
        p[i]= 1 + rand() % 10;
    }
}

void printVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%4d", p[i]);
    }
    puts("");
}

int arrayKey(int *p, int n, int k)
{
    if(n == 0) return 0;
    if(p[n-1] == k) return 1;
    return arrayKey(p, n-1, k);
}

int *allocVect(int *p, int n)
{
    p = malloc(n*sizeof(int));

    if(p == NULL)
    {
        puts("Memoria insufficiente");
        exit(-1);
    }
    return p;
}