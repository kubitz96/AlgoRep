#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initvectrand(int *p, int n);
int vectinvect(int *p, int *q, int nP, int nQ);
void printvect(int *p, int n);

int main()
{
    int *v;
    int *g;
    int d, e;
    int contenuto = 0;

    puts("Inserire grandezza di due vettori A e B");
    scanf("%d%d", &d, &e);

    v = malloc(d*sizeof(int));
    g = malloc(e*sizeof(int));

    srand(time(NULL));
    initvectrand(v, d);
    initvectrand(g, e);
    printvect(v, d);
    printvect(g, e);

    contenuto = vectinvect(v, g, d, e);

    if(contenuto) puts("Tutti i valori in A sono contenuti in B");
    else puts("Non tutti i valori in A sono contenuti in B");
    
}

void initvectrand(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i] = 1 + rand() % 10; // numeri da 1 a 10
    }
}

int vectinvect(int *p, int *q, int nP, int nQ) // sono incluse le ripetizioni, perche si sta chiedendo se ci sono tutti i valori
{
    int check = 1;
    for (size_t i = 0; check == 1 && i < nP; ++i)
    {
        check = 0;

        for (size_t j = 0; check == 0 && j < nQ; ++j)
        {
            if(p[i] == q[j]) check = 1;
        }
        
    }
    return check;
}

void printvect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%-4d", p[i]);
    }
    puts("");
}