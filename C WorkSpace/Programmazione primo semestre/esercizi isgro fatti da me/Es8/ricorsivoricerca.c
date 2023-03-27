#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arraykey(int *p, int n, int key);
void initRandVect(int *p, int n);
void printVect(int *p, int n);
int *allocVect(int *p, int n);

int main()
{
    int *a;
    int d, k;

    puts("Inserire dimensione vettore");
    scanf("%d", &d);

    a = allocVect(a, d); // se ritorno un valore lo devo sempre assegnare
    initRandVect(a, d);
    printVect(a, d);

    puts("Inserire K da trovare");
    scanf("%d", &k);

    k = arraykey(a, d, k);

    if(k == 1) puts("Valore trovato");
    else puts("Valore non trovato");

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

int arraykey(int *p, int n, int key)
{

    if(p[n] == key) return 1;                        //se ci sono piu casi devo specificare tutti i casi possibili in questo caso se trovo o non trovo il valore
    else if(p[n] == p[0] && p[0] != key) return 0;
    else return arraykey(p, n-1, key);
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