#include<stdio.h>       //trovare valore minimo in un vettore tramite la ricorsione
#include<stdlib.h>
#include<time.h>

int *allocVect(int n);
void initVect(int *V, int n);
void printVect(int *V, int n);
int minRecur(int *V, int n);
int sumRecur(int *V, int n);
int findRecur(int *V, int n, int key);
int findMajor(int *V, int n, int key);

int main()
{
    int *A;
    int nA;
    int m;
    int s;
    int k;
    int check;
    int check2;

    puts("Inserire grandezza del vettore");
    scanf("%d", &nA);

    A = allocVect(nA);

    initVect(A, nA);

    puts("Vettore A");
    printVect(A, nA);
    puts("");

    m = minRecur(A, nA);
    s = sumRecur(A, nA);

    printf("minimo = %d\n", m);
    printf("somma = %d\n", s);

    puts("Inserire valore k da trovare");
    scanf("%d", &k);

    check = findRecur(A, nA, k);

    if(check) puts("TRUE");
    else puts("FALSE");

    check2 = findMajor(A, nA, k);

    if(check2) puts("tutti gli elementi del vettore sono maggiori di k");
    else puts("non tutti gli elementi del vettore sono maggiori di k");

    free(A);

    return 0;
}

int *allocVect(int n)
{
    int *V;

    V = malloc(n*sizeof(int));

    return V;
}

void initVect(int *V, int n)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        V[i] = 1 + rand() % 10;
    }
    
}

void printVect(int *V, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", V[i]);
    }
    
}

int minRecur(int *V, int n)
{
    int min;

    if(n == 1) return V[0];

    min = minRecur(V, n-1);

    if(V[n-1] < min) return V[n-1];
    else return min;
}

int sumRecur(int *V, int n)
{
    int sum = 0;
    if(n == 1) return V[0];
    return V[n-1] + sumRecur(V, n-1);
}

int findRecur(int *V, int n, int key)
{
    if(V[n-1] == key) return 1;
    if(n == 0) return 0;

    return findRecur(V, n-1, key);
}

int findMajor(int *V, int n, int key)
{
    if(key >= V[n-1]) return 0;
    if(n == 0) return 1;
    
    return findMajor(V, n-1, key);
}