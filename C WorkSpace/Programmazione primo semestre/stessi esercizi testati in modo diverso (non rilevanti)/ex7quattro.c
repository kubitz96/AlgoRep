#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initRandVect(int *p, int n);
void printVect(int *p, int n);
int checkIncDec(int *p, int n);

int main()
{
    int *a;
    int d;
    int check;
    
    printf("Inserire dimensione vettore: ");
    scanf("%d", &d);

    a = malloc(d*sizeof(int));

    srand(time(NULL));
    initRandVect(a, d);
    printVect(a, d);

    check = checkIncDec(a, d);
    if(check == -1) printf("non e' ordinato");
    else if(check) printf("e' crescente");
    else printf("e' decrescente");

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

int checkIncDec(int *p, int n)
{
    int inc = 1; //VARIABILI DI STATO
    int dec = 1;
    for (size_t i = 0; i < n - 1; i++)
    {
        if(inc && p[i] > p[i+1]) inc = 0;
        if(dec && p[i] < p[i+1]) dec = 0;
        if( inc == 0 && dec == 0) return -1;
    }
    
    if(inc == 1 && dec == 0) return 1;
    else return 0;
}