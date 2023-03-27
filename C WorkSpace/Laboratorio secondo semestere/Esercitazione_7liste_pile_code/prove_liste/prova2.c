/*Scrivere un programma che permetta all'utente di inserire degli interi, uno dietro l'altro, in una lista concatenata.
 Dare la possibilità all'utente di visualizzare tale lista.
*/

#include<stdio.h>
#include<stdlib.h>

struct nodo 
{
    int valore;
    struct nodo* prossimo;
};

void printlist(struct nodo * start);
void insertlist(struct nodo ** start, int val);
void freelist(struct nodo * start);

int main()
{
    int scelta = -1;
    struct nodo* inizio = NULL;

    while(scelta != 0)
    {
        printf("Scegli:\n");
        printf("1:Inserisci valore\n");
        printf("2:Stampa lista\n");
        printf("3:Cancella lista\n");
        printf("0:Esci\n");
        scanf("%d", &scelta);

        if(scelta == 1)
        {
            int val;
            printf("Inserire valore\n");
            scanf("%d", &val);
            insertlist(&inizio, val);
        }
        else if(scelta == 2)
        {
            printlist(inizio);
        }
        else if(scelta == 3)
        {
            freelist(inizio);
            inizio = NULL;
        }

        else if(scelta != 0) printf("scelta errata,ripetere");
    }

    return 0;
}

void printlist(struct nodo * start)
{
    if(start == NULL) printf("Lista vuota");

    while(start != NULL)
    {
        printf("%d ", start->valore);
        start = start->prossimo;
    }
    printf("\n");
}

void freelist(struct nodo * start)
{
    while( start != NULL)
    {
        struct nodo * prox = start->prossimo;
        free(start);
        start = prox;
    }
}

void insertlist(struct nodo** start, int val)
{
    struct nodo* nuovo;
    nuovo = malloc(sizeof(struct nodo));
    nuovo->valore = val;
    nuovo->prossimo = NULL;

    struct nodo* in_esame = *start;
    struct nodo* precedente = NULL;

    while(in_esame != NULL) //scorrere la lista finche non trovo l'ultimo elemento
    {
        precedente = in_esame;
        in_esame = in_esame->prossimo;
    }

    if(precedente == NULL) //se non ci sono precedenti allora start conterra l'indirizzo di inizio
    {
        *start = nuovo;
    }
    else //altrimenti aggiungo il nuovo nodo
        precedente->prossimo = nuovo;
}