#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arraySum(int *p, int n);
void initRandVect(int *p, int n);
void printVect(int *p, int n);
int *allocVect(int *p, int n);

int main()
{
    int *v;
    int dim, sum;

    printf("Inserire dimensione vettore v\n");
    scanf("%d", &dim);

    v = allocVect(v, dim);
    initRandVect(v, dim);
    printVect(v, dim);

    sum = arraySum(v, dim);
    printf("Sum = %d", sum);
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

int arraySum(int *p, int n)
{

    if(n==1) return p[0];
    return p[0] + arraySum(p+1,n-1);   //sum = p[n-1] + arraySum(p, n-1);
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