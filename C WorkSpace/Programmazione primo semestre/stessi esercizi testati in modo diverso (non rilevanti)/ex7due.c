//programma che controlla se un array è ordinato in modo crescente

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initRandVect(int *p, int n);
int checkSame(int *p, int n);
void printVect(int *p, int n);

int main()
{
    int *A;
    int nA;
    int same; 

    printf("Inserire Grandezza Vettore A: ");
    scanf("%d", &nA);

    A = malloc(nA*sizeof(int));

    srand(time(NULL));
    initRandVect(A, nA);
    printVect(A, nA);

    same = checkSame(A, nA);

    if(same) puts("\nIl vettore ha almeno due elementi uguali");
    else puts ("\nIl vettore non ha elementi uguali");

    return 0;
}

void initRandVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i]= 1 + rand() % 10;
    }
}

int checkSame(int *p, int n)
{
    for (size_t i = 0; i < n -1; i++) //ciclo per scorrere l'elemento da confrontare con gli altri
    {
        for (size_t j = i+1; j < n; j++) //ciclo di elementi confrontati
        {
            if(p[i] == p[j]) return 1; //vedo se due elementi sono decrescenti e ritorno false
        }
    }
    return 0;
}

void printVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%4d", p[i]);
    } 
}