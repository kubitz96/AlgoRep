#include<stdio.h>
#include<stdlib.h>              //LEZIONE 35 1.33
#include<time.h>

void initRandVect(int *p, int n);
void printVect(int *p, int n);
void swap (int *p, int *q);
void selectionsort(int *p, int n);
void bubblesort(int *p, int n);

int main()
{
    int *A;
    int nA;

    printf("Inserire Grandezza Vettore A: ");
    scanf("%d", &nA);

    A = malloc(nA*sizeof(int));

    srand(time(NULL));
    initRandVect(A, nA);
    printVect(A, nA);

    puts("Vettore Ordinato Crescente");
    selectionsort(A, nA);
    printVect(A, nA);

    puts("Vettore Ordinato Decrescente");
    bubblesort(A, nA);
    printVect(A, nA);

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

void swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void selectionsort(int *p, int n)
{
    for (size_t i = 0; i < n-1; i++)  //numero di passate
    {
        for (size_t j = i+1; j < n; j++)
        {
            if(p[i] > p[j]) swap(p+i,p+j);
        }
        
    }
    
}

void bubblesort(int *p, int n)
 {
     for (size_t i = 0; i < n-1; ++i)  //numero di passate
    {
        for (size_t j = n-1; j > i; --j)
        {
            if(p[j-1] < p[j]) swap(p+j,p+j-1);
        }
        
    }
 }