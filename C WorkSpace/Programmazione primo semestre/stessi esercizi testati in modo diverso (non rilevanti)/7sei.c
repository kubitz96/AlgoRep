#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initRandVect(int *p, int n);
void printVect(int *p, int n);
int vectInVect(int *p, int nP, int *q,int nQ);

int main()
{
    int *A, *B;
    int N, M;
    int included;

    printf("Inserire Grandezza Vettore A: ");
    scanf("%d", &N);

    printf("Inserire Grandezza Vettore B: ");
    scanf("%d", &M);

    srand(time(NULL));

    A = malloc(N*sizeof(int));
    puts("Vettore A: ");
    initRandVect(A, N);
    printVect(A, N);

    B = malloc(M*sizeof(int));
    puts("Vettore B: ");
    initRandVect(B, M);
    printVect(B, M);

    included= vectInVect(B, M, A, N);

    if(included) puts("Tutti I Valori di B sono inclusi in A");
    else puts("Non tutti I Valori di B sono inclusi in A");

    free(A);
    free(B);

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

int vectInVect(int *p, int nP, int *q,int nQ)
{
    int check = 1;

    for (size_t i = 0; check == 1 && i < nP; i++)  // valori di B
    {
        check = 0;
        for (size_t j = 0; check == 0 && j < nQ; j++)  // valori in A
        {
            if(p[i] == q[j]) check = 1;
        }
        // SE CHECK RIMANE ZERO ESCO GIA DAL CICLO E RITORNO CHECK
    }
    return check;
    
}