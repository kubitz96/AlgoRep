#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE_GIURIA 100
#define SIZE_VOTI 11

void initRandVect(int *p, int n);
void printVect(int *p, int n);

int main()
{
    int *g;
    int *v;

    g = malloc(SIZE_GIURIA*sizeof(int));
    v = (int *)calloc(SIZE_VOTI,sizeof(int));

    initRandVect(g, SIZE_GIURIA);
    printVect(g, SIZE_GIURIA);

    for (size_t i = 0; i < SIZE_GIURIA; ++i)
    {
        ++v[g[i]];
    }

    printf("%s%13s\n", "Voti", "Frequenze");

    for (size_t i = 1; i < SIZE_VOTI; i++)
    {
        printf("%2lu%11d\n", i, v[i]);
    }
    
    
}

 void initRandVect(int *p, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        p[i]= 1 + rand() % 10;
    }
}

void printVect(int *p, int n)
{
    int j = 1;

    for (size_t i = 0; i < n; ++i)
    {
        printf("%4d", p[i]);
        if(j % 10 == 0) puts("");
        ++j;
    }
}