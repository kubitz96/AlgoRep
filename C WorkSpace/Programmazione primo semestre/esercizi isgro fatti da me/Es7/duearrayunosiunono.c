#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initRandVect(int *p, int n);
int *trovaelementi(int *p, int nP, int *q, int nQ);
void printvect(int *p, int n);

int main()
{
    int *V, *G, *T;
    int dV, dG;

    puts("Inserire grandezza dei vettori A e B (secondo meno primo)");
    scanf("%d%d", &dV, &dG);

    V = malloc(dV*sizeof(int));
    G = malloc(dG*sizeof(int));

    srand(time(NULL));
    initRandVect(V, dV);
    initRandVect(G, dG);

    puts("VETTORE A");
    printvect(V, dV);
    puts("VETTORE B");
    printvect(G, dG);


    puts("VETTORE B - A");
    T = trovaelementi(V, dV, G, dG);

    for (size_t i = 0; i < dG; ++i)
    {
       if (T[i] == 1) printf("%4d", G[i]);
    }
    
}

int *trovaelementi(int *p, int nP, int *q, int nQ)
{
    int *T;
    int check;

    T = (int *)calloc(nQ,sizeof(int));

    for(size_t i = 0; i < nQ; ++i) //scorro il secondo vettore
    {
        check = 0;
        for (size_t j = 0; check == 0 && j < nP; ++j) // confronto con il primo
        {
            if(p[j] == q[i]) check = 1;
        }
        if(check == 0) T[i] = 1; // valore uno se sono diversi
    }

    return T;

}

void printvect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%4d", p[i]);
    }
    puts("");
}

void initRandVect(int *p, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        p[i]= 1 + rand() % 10;
    }
    
}