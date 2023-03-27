//Implementare una struttura dati con politica di accesso Coda con relative funzioni di accesso utilizzando come struttura una lista concatenata.

#include<stdio.h>
#include<stdlib.h>

struct nodo
{
	float valore;
	struct nodo* prossimo;
};

struct coda
{
	struct nodo * start;
};

void init_coda(struct coda* c);
int is_coda_full(struct coda* c); 
int is_coda_empty(struct coda* c);
int insert_coda(struct coda* c, float inserito);
int read_coda(struct coda* c, float *letto);
int get_from_coda(struct coda*c, float *letto);

int main()
{
	struct coda A;

	init_coda(&A);

	int scelta = -1;

	while(scelta != 0)
	{
		printf("Scegli:\n");
		printf("1.Inserisci elemento nella struttura\n");
		printf("2.Leggi elemento in testa alla struttura\n");
		printf("3.Leggi e rimuovi elemento in testa alla struttura\n");
		printf("0.Esci\n");
		scanf("%d", &scelta);

		float valore;

		if(scelta == 1)
		{
			printf("Digita valore elemento da inserire\n");
			scanf("%f", &valore);
			insert_coda(&A, valore);
		}

		else if(scelta == 2)
		{
			if(read_coda(&A, &valore))
			printf("Valore letto in testa %.2f\n", valore);
		}

		else if(scelta == 3)
		{
			if(get_from_coda(&A, &valore))
			printf("Valore letto in testa %.2f e' stato rimosso\n", valore);
		}
		else if(scelta != 0)
		{
			printf("Scelta errata, riprovare!\n");
		}
	}
	return 0;
}

void init_coda(struct coda* c)
{
	c->start = NULL;
}

int is_coda_full(struct coda* c)
{
	return 0;
}

int is_coda_empty(struct coda* c)
{
	if(c->start == NULL) return 1;
	else return 0;
}

int insert_coda(struct coda* c, float inserito)
{
	if(is_coda_full(c))
		{
			printf("La struttura e' piena\n");
			return 0;
		}

		struct nodo* nuovo;
		nuovo = malloc(sizeof(struct nodo));
		nuovo->valore = inserito;
		nuovo->prossimo = NULL;

		if(c->start == NULL) c->start = nuovo;

		else //nella coda inserisco alla fine mentre nella pila in prima posizione
		{
			struct nodo* cursore = c->start;
			while(cursore->prossimo != NULL) //se voglio che il cursore si fermi sull'ultimo elemento senza il predecessore uso cursore->prossimo se no prova2.c in liste
			{
				cursore = cursore->prossimo;
			}
			cursore->prossimo = nuovo;
		}

		printf("Elemento inserito\n");

		return 1;	
}

int read_coda(struct coda* c, float *letto)
{
	if(is_coda_empty(c))
	{
		printf("La struttura e' vuota\n");
		return 0;
	}

	*letto = c->start->valore;

	return 1;
}

int get_from_coda(struct coda*c, float *letto)
{
	if(is_coda_empty(c))
	{
		printf("La struttura e' vuota\n");
		return 0;
	}

	read_coda(c,letto);

	struct nodo* libero;
	libero = c->start;

	c->start = c->start->prossimo;

	free(libero);

	return 1;
}
