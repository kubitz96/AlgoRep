#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arrayMin(int *p, int n);
void initRandVect(int *p, int n);
void printVect(int *p, int n);
int *allocVect(int *p, int n);

int main()
{
    int *v;
    int dim, min;

    printf("Inserire dimensione vettore v\n");
    scanf("%d", &dim);

    v = allocVect(v, dim);
    initRandVect(v, dim);
    printVect(v, dim);

    min = arrayMin(v, dim);
    printf("Min = %d", min);
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

int arrayMin(int *p, int n)
{
    int min;
    if(n==1) return p[0];
    min=arrayMin(p, n-1);
    if(p[n-1]< min) return p[n-1];
    else return min;
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