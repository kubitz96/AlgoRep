#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initRandVect(int *p, int n);
void printVect(int *p, int n);
void eratostene(int *p, int n);

int main()
{
    int *E;
    int d;
    int j = 0;

    puts("Inserire fino a che Intero calcolare numeri primi con il crivello di Eratostene");
    scanf("%d", &d);

    E = (int*)calloc(d,sizeof(int));

    eratostene(E, d);

    for (size_t i = 0; i < d; ++i)
    {
        if(E[i] == 0)
        {
            printf("%3d", i);
            ++j;
        }
        else continue;
        if(j % 5 == 0) puts("");
    }
    puts("");

}

void initRandVect(int *p, int n)
{
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

void eratostene(int *p, int n)
{
    p[0] = 1;

    for (size_t i = 2; i < n; ++i)
    {
        if(p[i] == 1) continue;

        for (size_t j = i+i; j < n; j += i)
        {
            p[j] = 1;
        }
        
    }
    
}