#include<stdio.h>
#include<stdlib.h>

#define     SIZE    100

void initvect(int *p, int n);
void printvect(int *p, int n);
void eratostene(int *p, int n);

int main()
{
    int *v;

    v =(int*)calloc(SIZE,sizeof(int));

    puts("Crivello");
    eratostene(v, SIZE);

}

void initvect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i] = i+1;
    }
}

void printvect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%5d", p[i]);
        if((p[i] % 5) == 0) puts("");
    }
    
}

void eratostene(int *p, int n)
{
    p[0] = 1;           // sto operando sugli indirizzi e non sui contenuti degli array
    p[1] = 0;

    for(int j = 2; j < n; ++j) //ciclo che scala gli indici
    {
        if(p[j] == 1) continue;

        for(int k = j + j; k < n; k += j) //ciclo che associa agli indici da eliminare il valore 1 da escludere e 0 quelli rimasti
        {
            p[k] = 1; // metto uno a quelli da escludere
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if(p[i] == 0)
        {
            printf("%4d", i);
            ++cnt;
            if((cnt % 5) == 0) puts("");
        }
    }
    
}