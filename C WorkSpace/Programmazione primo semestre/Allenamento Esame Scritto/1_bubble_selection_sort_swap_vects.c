#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MEMORY_ALLOCATION_ERROR 10

void errorManager(int code);
int *allocVect(int n);
void initRandVect(int *v, int n);
void printVect(int *v, int n);
int checkSort(int *v, int n);
void selectionSort(int *v, int n);
void bubbleSort(int *v, int n);
void swap(int *p, int *q);
int checkSame(int *v, int n);
int checkKey(int *v, int key, int n);

int main()
{
    int *a;
    int n;
    int check;
    int same = 0;
    int k;

    puts("Inserire Grandezza Vettore");
    scanf("%d", &n);

    a = allocVect(n);

    initRandVect(a, n);

    puts("Valori del Vettore");
    printVect(a, n);

    same = checkSame(a, n);

    if(same) puts("Il vettore ha almeno due elementi uguali");

    puts("Inserire Valore K");
    scanf("%d", &k);

    k = checkKey(a, k, n);

    if(k) puts("Esistono almeno due elementi consecutivi maggiori di K");
    else puts("Non esistono almeno due elementi consecutivi maggiori di K");

    check = checkSort(a, n);

    if(check == 1) puts("Il vettore e' crescente");
    else if(check == 2) puts("Il vettore e' decrescente");
    else if(check == 3) puts("Tutti gli elementi sono uguali");

    else
    {
        puts("Il vettore non e' ordinato");
        if(n == 1)
        {
            puts("Il vettore ha un unico elemento");
            exit(1);
        }

        selectionSort(a, n);
        puts("cosi e' crescente");
        printVect(a, n);

        bubbleSort(a, n);
        puts("cosi e' decrescente");
        printVect(a, n);
    }

    free(a);

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
    v = malloc(n*sizeof(int)); //calloc(n,sizeof(int));
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

int checkSort(int *v, int n)
{
    if(n == 1) return 0;

    int Incsort = 1;
    int Decsort = 1;
    int Same = 1;

    for (int i = 0; i < n-1; i++)   //fino a n - 1 perche se no confronta con elemento fuori dalla memoria e crea errori
    {
        
        if(v[i] < v[i+1]) Decsort = 0;
        if(v[i] > v[i+1]) Incsort = 0;
        if(v[i] != v[i+1]) Same = 0;
    }

    if(Same) return 3;
    if(Incsort ==  Decsort) return 0;
    if(Incsort == 1 && Decsort == 0) return 1;
    else return 2;
}

void selectionSort(int *v, int n)
{
    for (int i = 0; i < n-1; i++) //ordino elemento per elemento = quantita di selezioni
    {
        for (int j = i+1; j < n; j++)
        {
            if(v[i] > v[j]) swap(v+j, v+i); //non posso scrivere v[j] oppure v[i] perche operando sui puntatori la funzione swap si aspetta un puntatore quindi un indirizzo e non una variabile di tipo int appartenente all'array
        }                                        //avere come parametro nello swap due vettori p[] e q[] solo se alloco staticamente
    }
}

void swap(int *p, int *q)       //passaggio per riferimento
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void bubbleSort(int *v, int n)
{
    for (int i = 0; i < n-1 ; i++) // quantita di passate
    {
        for (int j = 0; j < n-1; j++)
        {
            if(v[j] < v[j+1]) swap(&v[j], &v[j+1]);    //scrivere con la & commerciali e' assolutamente equivalente a scrivere v+j e v+j+1
        }//crescente
    }
}

int checkSame(int *v, int n)
{
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            if(v[i] == v[j]) return 1;
        }
    }
    return 0;       //importante ritornare 0 perche non tutti i sistemi ritornano 0 come valore nullo
}

int checkKey(int *v, int key, int n)
{
    for (int i = 0; i < n - 1; ++i) 
    {
        if(v[i] > key && v[i + 1] > key) return 1;
    }
    return 0;
}