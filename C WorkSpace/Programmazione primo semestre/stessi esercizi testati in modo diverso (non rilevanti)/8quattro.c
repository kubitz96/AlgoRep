#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arrayKeymin(int *p, int n, int k);
void initRandVect(int *p, int n);
void printVect(int *p, int n);
int *allocVect(int *p, int n);

int main()
{
    int *v;
    int dim, key, k;

    printf("Inserire dimensione vettore v\n");
    scanf("%d", &dim);

    v = allocVect(v, dim);
    initRandVect(v, dim);
    printVect(v, dim);

    printf("Inserire valore k minore di tutti gli elementi del vettore\n");
    scanf("%d", &k);

    key = arrayKeymin(v, dim, k);

    if(key) printf("%d e' minore rispetto a tutti gli elementi del vettore", k);
    else printf("%d non e' minore rispetto a tutti gli elementi del vettore", k);
   
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

int arrayKeymin(int *p, int n, int k)
{
    if(n == 1) return (k < p[0]);
    return p[0] > k && arrayKeymin(p+1, n-1, k);

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