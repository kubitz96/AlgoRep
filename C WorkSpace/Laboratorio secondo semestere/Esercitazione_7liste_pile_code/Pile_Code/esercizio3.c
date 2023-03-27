/*dato un numero, stamparne la codifica binaria. Non possono essere utilizzate strutture di supporto diverse da Pile e/o Code.
 
9:2=4 resto 1

4:2=2 resto 0

2:2=1 resto 0

1:2=0 resto 1 Last

1001 conviene una pila con politica LIFO*/


#include<stdio.h>

#define N_PILA 256

struct pila
{
	int binari[N_PILA];
	int n_occupati;
};

void init_pila(struct pila* p);
int push(struct pila* p, int inserito);
int pop(struct pila*p, int *rimosso);
int is_pila_full(struct pila*p);
int is_pila_empty(struct pila*p);

int main()
{
	struct pila c;

	int numero;

	printf("Inserire numero intero\n");
	scanf("%d", &numero);

	init_pila(&c);

	while(numero != 0)
	{
		push(&c, numero%2);
		numero /= 2;
	}

	int codifica;

	printf("Codifica Binaria\n");
	while(c.n_occupati != 0)
	{
		pop(&c, &codifica);
		printf("%d", codifica);
	}

	return 0;
}

void init_pila(struct pila* p)
{
	p->n_occupati = 0;
}

int push(struct pila* p, int inserito)
{
	if(is_pila_full(p))
	{
		printf("La pila e' piena\n");
		return 0;
	}

	else
	{
		p->binari[p->n_occupati] = inserito;
	}

	++(p->n_occupati);

	return 1;
}

int pop(struct pila*p, int *rimosso)
{
	if(is_pila_empty(p))
	{
		printf("La pila e' vuota\n");
		return 0;
	}

	else
	{
		*rimosso = p->binari[p->n_occupati-1];
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