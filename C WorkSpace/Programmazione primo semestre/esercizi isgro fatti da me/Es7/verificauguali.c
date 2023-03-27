#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initRandVect(int *p, int n);
int sameElement(int *p, int n);
void printVect(int *p, int n);

int main()
{
    int *v;
    int d;
    int uguali;

    puts("Inserire Dimensione Vettore");
    scanf("%d", &d);

    v = malloc(d*sizeof(int));

    if(v == NULL)
    {
        puts("Errore");
        exit(1);
    }

    srand(time(NULL));

    initRandVect(v, d);

    puts("Il vettore e'");
    printVect(v, d);

    uguali = sameElement(v, d);

    if(uguali) printf("ci sono %d elementi uguali", uguali);

    else puts("non ci sono elementi uguali");

    return 0;
}

void initRandVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i] = 1 + rand() % 10;
    } 
}

int sameElement(int *p, int n)
{
    int element = 1;
    for (size_t i = 0; i < n - 1; ++i) 
    {
        for (size_t j = i+1; j < n; ++j) //devo mettere i+1 invece di 1 poiche al secondo passaggio mi ritroverei p[1] = p[1] che e sempre vero
        {
            if(p[i] == p[j]) ++element;
        }
    }

    if(element == 1) --element;
    return element;
}

void printVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%-4d", p[i]);
    }
    puts("");
}