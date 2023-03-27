#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initRandVect(int *p, int n);
void printVect(int *p, int n);
int checkKey(int *p, int key, int n);

int main()
{
    int *v;
    int d;
    int k;
    int maggiori = 0;

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

    puts("Inserire valore da controllare");
    scanf("%d", &k);

    puts("Il vettore e'");
    printVect(v, d);

    maggiori = checkKey(v, k, d);

    if(maggiori) printf("Esistono due elementi consecutivi maggiori di %d", k);
    else printf("Non esistono due elementi consecutivi maggiori di %d", k);

    return 0;  
}

void initRandVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i) 
    {
        p[i] = 1 + rand() % 10;
    } 
}

void printVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%-4d", p[i]);
    }
    puts("");
}

int checkKey(int *p, int key, int n)
{
    for (size_t i = 0; i < n - 1; ++i) 
    {
        if(p[i] > key && p[i + 1] > key) return 1;
    }
    return 0;
}