//programma che controlla se un array è ordinato in modo crescente

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initRandVect(int *p, int n);
int checkInc(int *p, int n);
void printVect(int *p, int n);

int main()
{
    int *A;
    int nA;
    int inc; 

    printf("Inserire Grandezza Vettore A: ");
    scanf("%d", &nA);

    A = malloc(nA*sizeof(int));

    srand(time(NULL));
    initRandVect(A, nA);
    printVect(A, nA);

    inc = checkInc(A, nA);

    if(inc) puts("\nIl vettore è crescente");
    else puts ("\nIl vettore non e' crescente");

    return 0;
}

void initRandVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i]= 1 + rand() % 10;
    }
    
}

int checkInc(int *p, int n)
{
    for (size_t i = 0; i < n -1; i++) //ciclo per scorrere l'elemento da confrontare con gli altri
    {
        for (size_t j = i+1; j < n; j++) //ciclo di elementi confrontati
        {
            if(p[i] > p[j]) return 0; //vedo se due elementi sono decrescenti e ritorno false
        }
    }
    return 1;
}

void printVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%4d", p[i]);
    }
    
}