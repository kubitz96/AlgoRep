//Implementare una struttura dati con politica di accesso Pila con relative funzioni di accesso utilizzando come struttura una lista concatenata.

#include<stdio.h>
#include<stdlib.h>

struct nodo
{
	float valore;
	struct nodo* prossimo;
};

struct pila
{
	struct nodo* start;
};

void init_pila(struct pila* p);
int push(struct pila* p, float inserito);
int pop(struct pila*p, float *rimosso);
int read_pila(struct pila *p,float *letto);
int is_pila_full(struct pila*p);
int is_pila_empty(struct pila*p);
int read_pila(struct pila *p,float *letto);
void print_pila(struct pila *p);

int main()
{
	struct pila A;

	init_pila(&A);

	int scelta = -1;

	while(scelta != 0)
	{
		printf("Scegli:\n");
		printf("1.Inserisci elemento nella struttura\n");
		printf("2.Leggi elemento in testa alla struttura\n");
		printf("3.Leggi e rimuovi elemento in testa alla struttura\n");
		printf("4.Stampa pila\n");
		printf("0.Esci\n");
		scanf("%d", &scelta);

		float valore;

		if(scelta == 1)
		{
			printf("Digita valore elemento da inserire\n");
			scanf("%f", &valore);
			push(&A, valore);
		}

		else if(scelta == 2)
		{
			if(read_pila(&A, &valore))
			printf("Valore letto in testa %.2f\n", valore);
		}

		else if(scelta == 3)
		{
			if(pop(&A, &valore))
			printf("Valore letto in testa %.2f e' stato rimosso\n", valore);
		}
		else if(scelta == 4)
		{
			print_pila(&A);
		}
		else if(scelta != 0)
		{
			printf("Scelta errata, riprovare!\n");
		}
	}
	
	return 0;
}

int is_pila_full(struct pila*p)
{
	return 0;
}

int is_pila_empty(struct pila*p)
{
	if(p->start == NULL) return 1;
	else return 0;
}

void init_pila(struct pila* p)
{
	p->start = NULL;
}

int push(struct pila* p, float inserito)
{
	if(is_pila_full(p))
		{
			printf("La struttura e' piena\n");
			return 0;
		}

		struct nodo* nuovo;
		nuovo = malloc(sizeof(struct nodo));
		nuovo->valore = inserito;
		nuovo->prossimo = NULL;

		if(p->start == NULL) p->start = nuovo;

		else
		{
			nuovo->prossimo = p->start;
			p->start = nuovo;
		}

		printf("Elemento inserito\n");

		return 1;
}

int pop(struct pila*p, float *rimosso)
{
	if(is_pila_empty(p))
		{
			printf("La struttura e' vuota\n");
			return 0;
		}

		read_pila(p,rimosso);

		struct nodo * libero;
		libero = p->start;

		p->start = p->start->prossimo;

		free(libero);

		return 1;
}

int read_pila(struct pila *p,float *letto)
{
	if(is_pila_empty(p))
		{
			printf("La struttura e' vuota\n");
			return 0;
		}

		*letto = p->start->valore;
		return 1;
}

void print_pila(struct pila *p)
{
	if(is_pila_empty(p))
		{
			printf("La struttura e' vuota\n");
		}
		else
		{
			struct nodo* cursore = p->start;

			while(cursore != NULL)
			{
				printf("%.2f ", cursore->valore);
				cursore = cursore->prossimo;
			}
			printf("\n");
		}
}
