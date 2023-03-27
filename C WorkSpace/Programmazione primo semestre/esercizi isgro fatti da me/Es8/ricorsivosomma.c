#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arraysum(int *p, int n);
void initRandVect(int *p, int n);
void printVect(int *p, int n);
int *allocVect(int *p, int n);

int main()
{
    int *a;
    int d, sum = 0;

    puts("Inserire dimensione vettore");
    scanf("%d", &d);

    a = allocVect(a, d); // se ritorno un valore lo devo sempre assegnare
    initRandVect(a, d);
    printVect(a, d);

   sum = arraysum(a, d);

    printf("Sum = %d", sum);

    return 0;
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

int arraysum(int *p, int n)
{
    int sum = 0; // devo trovare min
    if(n==1) return p[0]; //ritorno il valore base
    //se non trovo min devo chiamare di nuovo la funzione e assegnarla a min
    sum = arraysum(p, n-1);  //nella ricorsione le condizioni vanno messe dopo vanno prima chiamati tutti gli elementi, in questo caso divido il problema in sottosoluzioni

    return sum += p[n-1]; //per arrivare a questo caso devo immagginare l'ultimo passaggio da cui risalire il caso base

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