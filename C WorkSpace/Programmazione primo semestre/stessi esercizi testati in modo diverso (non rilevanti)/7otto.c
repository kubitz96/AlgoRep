#include<stdio.h>
#include<stdlib.h>              //LEZIONE 35 1.33
#include<time.h>

void initRandVect(int *p, int n);
void printVect(int *p, int n);
int *vectminusvect(int *B, int nB, int *A,int nA);

int main()
{
    int *A, *B, *T;
    int N, M;

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

    T = vectminusvect(B, M, A, N);

    puts("Vettore T: ");
    for (size_t i = 0; i < M; ++i)
    {
        if(T[i] == 1)printf("%4d", B[i]);
    }
    puts("");


    free(A);
    free(B);
    free(T);

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

int *vectminusvect(int *B, int nB, int *A,int nA)
{
    int *T;
    int check;

    T = (int*)calloc(nB,sizeof(int));

    for (size_t i = 0; i < nB; i++)  // valori che stanno in B
    {
        check = 0;
        for (size_t j = 0; check == 0 && j < nA; j++)  // valori in A
        {
            if(A[j] == B[i])
            {
                check = 1; // METTO CHECK UGUALE A 1 SE VOGLIO USCIRE PRIMA DAL SECONDO CICLO E RIFACCIO IL PRIMO
            }
        }
        if(check == 0) T[i] = 1; // SE SONO PRESENTI IN B MA NON IN A T[I] VALE 1; E RITORNO AL PRIMO CICLO
    }
    return T;
}