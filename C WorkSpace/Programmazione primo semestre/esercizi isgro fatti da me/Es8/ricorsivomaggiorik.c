#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arraykeymag(int *p, int n, int key);
void initRandVect(int *p, int n);
void printVect(int *p, int n);
int *allocVect(int *p, int n);

int main()
{
    int *a;
    int d, k, check;

    puts("Inserire dimensione vettore");
    scanf("%d", &d);

    a = allocVect(a, d); // se ritorno un valore lo devo sempre assegnare
    initRandVect(a, d);
    printVect(a, d);

    puts("Inserire K da trovare");
    scanf("%d", &k);

    check = arraykeymag(a, d, k);

    if(check) printf("Tutti i valori del vettore sono maggiori di %d", k);
    else printf("Non tutti i valori del vettore sono maggiori di %d", k);
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

int arraykeymag(int *p, int n, int key)
{
    /*if( key >= p[0]) return 0;
    if (n == 0) return 1;         //true se tutti gli elementi sono maggiori di k
    return arraykeymag(p+1, n-1, key);*/ // p+1 mi sposto di un elemento da 0 a 1 e metto n-1 perche spostandomi di 1 il vettore deve essere piu piccolo di un elemento se no vado fuori array
    if(n==1) return(p[0] > key);
    else return (p[0] > key && arraykeymag(p+1, n-1, key));
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