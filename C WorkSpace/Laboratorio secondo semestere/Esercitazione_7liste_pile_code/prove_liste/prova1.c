#include<stdio.h>
#include<stdlib.h>

#define N 3

struct nodo
{
	int valore;
	struct nodo* prossimo;
};

void printlist(struct nodo * start);
void freelist(struct nodo * start);

int main()
{
	int val[N] = {1,2,3};

	const int n = N;

	struct nodo* inizio = NULL;

	struct nodo** in_esame = &inizio; //una variabile che contiene un indirizzo di un blocco di memoria in cui è contenuto l'indirizzo della struct inizio;

	for (int i = 0; i < n; ++i)
	{
		//prima cosa alloco lo spazio che mi serve
		//scrivere *in_esame è come scrivere inizio, mentre **in_esame e come scrivere *in_esame

		*in_esame = malloc(sizeof(struct nodo)); //all'indirizzo *in_esame alloco spazio per un elemento

		(*in_esame)->valore = val[i];
		(*in_esame)->prossimo = NULL;

		//faccio puntare adesso il nostro puntatore "in_esame" al nuovo puntatore prossimo presente nella nuova struct che punta  sua volta a NULL
		in_esame = &((*in_esame)->prossimo);
	}

	printlist(inizio);

	freelist(inizio);

	

	return 0;
}

void printlist(struct nodo * start)
{
	if(start == NULL) printf("Lista vuota\n");

	while(start != NULL)
	{
		printf("%d", start->valore);
		start = start->prossimo;
	}
}

void freelist(struct nodo * start)
{
	while(start != NULL)
	{
		struct nodo* prox = start->prossimo; //copio il puntatore al struct successiva in una struct di supporto che viene liberata alla fine del while;
		free(start);
		start = prox;
	}

	start = NULL; //buona norma
}
