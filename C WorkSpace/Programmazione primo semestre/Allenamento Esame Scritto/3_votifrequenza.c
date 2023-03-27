#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define     SIZE_GIURIA     100
#define     SIZE_VOTI       11
#define     MIN_VOTO        1   

void initrandvoti(int *p, int n);

int main ()
{
    int *g;
    int *v;

    g= malloc(SIZE_GIURIA*sizeof(int));
    v= calloc(SIZE_VOTI,sizeof(int));

    srand(time(NULL));
    initrandvoti(g, SIZE_GIURIA);

    for (int i = 0; i < SIZE_GIURIA; ++i)
    {
        ++v[g[i]];
    }

    printf("%s%13s\n", "Voto", "Frequenza");
    for (int j = 1; j < SIZE_VOTI; ++j)
    {
        printf("%5d%13d\n", j, v[j]);
    }
    
    return 0;
}

void initrandvoti(int *p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = MIN_VOTO + rand() % SIZE_VOTI-1; // numeri da 1 a 10
    }
}