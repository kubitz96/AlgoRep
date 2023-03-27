#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initRandVect(int *p, int n);
void printVect(int *p, int n);
int checkKey(int *p, int n, int key);

int main()
 {
    int *a;
    int d;
    int k;

    printf("Inserire dimensione vettore: ");
    scanf("%d", &d);

    a = malloc(d*sizeof(int));
    
    srand(time(NULL));
    initRandVect(a, d);
    printVect(a, d);

    printf("Inserire valore K: ");
    scanf("%d", &k);

    k = checkKey(a, d, k) ? printf("Esistono due valori consecutivi maggiori di K") : printf("Non esistono due valori consecutivi maggiori di K");

    free(a);

    return 0;
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

int checkKey(int *p, int n, int key)
{
    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if(p[i] > key && p[i+1] > key) return 1;
        }
        
    }
    return 0;
}