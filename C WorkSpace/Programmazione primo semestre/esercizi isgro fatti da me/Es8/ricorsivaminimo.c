#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arraymin(int *p, int n);
void initRandVect(int *p, int n);
void printVect(int *p, int n);
int *allocVect(int *p, int n);

int main()
{
    int *a;
    int d, min;

    puts("Inserire dimensione vettore");
    scanf("%d", &d);

    a = allocVect(a, d); // se ritorno un valore lo devo sempre assegnare
    initRandVect(a, d);
    printVect(a, d);

   min = arraymin(a, d);

    printf("Min = %d", min);

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

int arraymin(int *p, int n)
{
    int min; // devo trovare min
    if(n==1) return p[0]; //ritorno il valore base
    //se non trovo min devo chiamare di nuovo la funzione e assegnarla a min
    min = arraymin(p, n-1);  //nella ricorsione le condizioni vanno messe dopo vanno prima chiamati tutti gli elementi, in questo caso divido il problema in sottosoluzioni

    if(p[n-1] < min) return p[n-1];  //quando ho tutte le sottosoluzione e sono arrivato al caso base posso risalire e applicare queste condizioni
    else return min; //per arrivare a questo caso devo immagginare l'ultimo passaggio da cui risalire il caso base

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

      