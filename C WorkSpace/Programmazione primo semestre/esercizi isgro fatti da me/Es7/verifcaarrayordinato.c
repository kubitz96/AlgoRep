#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initvectrand(int *p, int n); //quando dichiaro un puntatore come parametro, quando chiamo la funzione gli devo passare l'indirizzo in cui deve modifcare il valore
void printvect(int *p, int n);
int issorted(int *p, int n);
void bubblesort(int *p, int n);
void swap(int *p, int *q);

int main()
{
    int *v;
    int dim;

    puts("Inserire Dimensione Vettore");
    scanf("%d", &dim);

    v = malloc(dim*sizeof(int));  //alloco memoria sufficiente per il vettore
    if( v == NULL)
    {
        puts("memoria insufficiente");
        exit(1);
    }

    srand(time(NULL));
    initvectrand(v, dim);    //scrivere v dato che e stato dichiarato come puntatore v in realta e gia per se un indirizzo ,cosi passo l'intero vettore

    int sorted = issorted(v, dim);

    puts("Il vettore");
    printvect(v, dim);
    if(sorted) puts("e' ordinato in modo crescente");
    else 
    {
        puts("non e' ordinato in modo crescente");
        bubblesort(v,dim);
        puts("cosi lo e'");
        printvect(v,dim);
    }

    return 0;

}

void initvectrand(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i] = 1 + rand() % 100; // numeri da 1 a 100
    }
}

void printvect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%-4d", p[i]);
    }
    puts("");
}

int issorted(int *p, int n)
{
    int sorted = 1;
    for (size_t i = 0; i < n; ++i)
    {
        if(p[i] <= p[i+1]) sorted = 1;
        else return sorted = 0;
    }
}

void swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void bubblesort(int *p, int n)
{
    for (int j = 0; j < n; ++j)
    {
        for (size_t i = 0; i < n - 1; ++i)
        {
           if (p[i] > p[i + 1])   //l'indirizzo di p[i] = p+i
           {
             swap(p+i, p+i+1);  //nello swap per rendere effettiva la modifica devo passare gli indirizzi, altrimenti non avrei messo un puntatore come parametro posso anche scrivere &p[i] e &p[]
           }
           
        }
        
    }
    
}