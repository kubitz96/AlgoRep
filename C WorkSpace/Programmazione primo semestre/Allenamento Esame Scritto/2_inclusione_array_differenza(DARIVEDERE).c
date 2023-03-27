#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MEMORY_ALLOCATION_ERROR 10

void errorManager(int code);
int *allocVect(int n);
void initRandVect(int *v, int n);
void printVect(int *v, int n);
int vectIncluded(int *v, int *w, int nV, int nW);
int *vectDif(int *v, int *w, int nV, int nW); //q-p

int main()
{
    int *A, *B;
    int nA, nB;
    int include;
    int *D;
    int nD;

    puts("Inserire dimensione di Vettore A ");
    scanf("%d", &nA);

    A = allocVect(nA);
    initRandVect(A, nA);

    puts("Inserire dimensione di Vettore B");
    scanf("%d", &nB);

    B = allocVect(nB);
    initRandVect(B, nB);

    puts("Vettore A");
    printVect(A, nA);

    puts("Vettore B");
    printVect(B, nB);

    include = vectIncluded(A, B, nA, nB);

    if(include) puts("Tutti gli elementi di B appaiono in A");
    else puts ("Non tutti gli elementi di B appaiono in A");

    D = vectDif(B, A, nB, nA);

    puts("Vettore D, Risultante di B-A");
    for (int i = 0; i < nB; i++)
    {
        if(D[i] == 1) printf("%d ", B[i]);
    }
    
    free(A);
    free(B);
    free(D);

    return 0;

}

void errorManager(int code)
{
    switch (code)
    {
    case MEMORY_ALLOCATION_ERROR:
        fprintf(stderr, "Insufficient Memory Space!\n");
        break;
    
    default: fprintf(stderr, "Unknow Error!\n");
        break;
    }
    exit(-1);
}

int *allocVect(int n)
{
    int *v;
    v = calloc(n,sizeof(int)); //calloc(n,sizeof(int));
    if(v == NULL) errorManager(MEMORY_ALLOCATION_ERROR);
    return v;
}

void initRandVect(int *v, int n)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        v[i] = 1 + rand() % 10;
    }
    
}

void printVect(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    puts("");
}

int vectIncluded(int *v, int *w, int nV, int nW) //vedere se tutti gli elementi di w sono in v
{
    int check = 1;

    for (int i = 0; check == 1 && i < nW; i++)  // valori di B
    {
        check = 0;
        for (int j = 0; check == 0 && j < nV; j++)  // valori in A
        {
            if(w[i] == v[j]) check = 1;
        }
        // SE CHECK RIMANE ZERO ESCO GIA DAL CICLO E RITORNO CHECK
    }
    return check;
}

int *vectDif(int *v, int *w, int nV, int nW)  //B e A invertiti (vedo se gli elementi di A appaiono in B) e se non appaiono stampo
{
    int *D;
    int check;

    D = allocVect(nW);

    for (int i = 0; i < nW; i++) // A
    {
        check = 0;

        for (int j = 0; check == 0 && j < nV; j++) // B
        {
            if(w[j] == v[i]) check = 1;  //se un elemento di B e uguale a un elemento di A segno 1
        }
        if(check == 0)  //se gli elementi sono diversi segno 0 e assegno l'elemento di B
        {
            D[i] = 1;
        }
    }
    return D;
}
