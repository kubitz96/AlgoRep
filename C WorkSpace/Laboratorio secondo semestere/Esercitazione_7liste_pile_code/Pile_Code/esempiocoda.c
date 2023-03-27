//esempio coda

#include<stdio.h>

#define SIZE_CODA 5

struct coda
{
	float deposito[SIZE_CODA];
	int n_occupati;
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
}

void init_coda(struct coda* c)
{
	c->n_occupati = 0;
}

int is_coda_full(struct coda* c)
{
	if(c->n_occupati >= SIZE_CODA) return 1;
	else return 0;
}

int is_coda_empty(struct coda* c)
{
	if(c->n_occupati == 0) return 1;
	else return 0;
}

int insert_coda(struct coda* c, float inserito)
{
	if(is_coda_full(c))
		{
			printf("La struttura e' piena\n");
			return 0;
		}

		c->deposito[c->n_occupati] = inserito;

		++c->n_occupati;

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

	*letto = c->deposito[0];

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

	for (int i = 0; i < c->n_occupati; ++i)
	{
		c->deposito[i] = c->deposito[i+1];
	}

	--c->n_occupati;

	return 1;
}