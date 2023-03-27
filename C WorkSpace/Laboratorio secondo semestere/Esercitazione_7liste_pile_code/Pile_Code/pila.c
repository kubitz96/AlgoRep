//Data una stringa s, verificare se la stringa è palindroma.
//Gli elementi di s potranno essere letti/scritti solo ed esclusivamente dal primo all'ultimo.
//Non possono essere utilizzate strutture di supporto diverse da Pile e/o Code.

//intendo usare una struttura di tipo PILA quindi LIFO

#include<stdio.h>

#define N_PILA 256

struct pila
{
	char stringa[N_PILA];
	int n_occupati;
};

void init_pila(struct pila* p);
int push(struct pila* p, char inserito);
int pop(struct pila*p, char *rimosso);
int is_pila_full(struct pila*p);
int is_pila_empty(struct pila*p);

int main()
{
	struct pila A;

	char stringa[N_PILA];

	int pal = 1;

	printf("Inserisci stringa\n");
	scanf("%s", stringa);

	init_pila(&A);

	for (int i = 0; stringa[i] != '\0'; ++i)
	{
		push(&A, stringa[i]);
	}

	for (int i = 0;pal && stringa[i] != '\0'; ++i)
	{
		char c;
		pop(&A,&c);
		if(c != '\0' && c != stringa[i]) pal = 0;
	}

	if(pal) printf("La stringa e' palindroma\n");
	else printf("La stringa non e' palindroma\n");

	return 0;
}

void init_pila(struct pila* p)
{
	p->n_occupati = 0;
}

int push(struct pila* p, char inserito)
{
	if(is_pila_full(p))
	{
		printf("La pila e' piena\n");
		return 0;
	}

	else
	{
		p->stringa[p->n_occupati] = inserito;
	}

	++(p->n_occupati);

	return 1;
}

int pop(struct pila*p, char *rimosso)
{
	if(is_pila_empty(p))
	{
		printf("La pila e' vuota\n");
		return 0;
	}

	else
	{
		*rimosso = p->stringa[p->n_occupati-1];
	}

	--(p->n_occupati);

	return 1;
}

int is_pila_full(struct pila*p)
{
	if(p->n_occupati >= N_PILA) return 1;
	else return 0;
}

int is_pila_empty(struct pila*p)
{
	if(p->n_occupati == 0) return 1;
	else return 0;
}