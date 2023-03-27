/*Definire una struttura dati contenente interi avente una politica di accesso del tipo minimum first out,
 in cui il valore più piccolo contenuto è sempre il primo ad uscire. Provarla con un apposito main(...).*/

//voglio implementare una struttura di tipo coda MINIMUM FIRST OUT


//funzioni necessarie in coda: insert, read,full,empty,get

#include<stdio.h>

#define SIZE_MFO 5

struct mfo
{
	float deposito[SIZE_MFO];
	int n_occupati;
};

void init_mfo(struct mfo* c);
int is_mfo_full(struct mfo* c); 
int is_mfo_empty(struct mfo* c);
int insert_mfo(struct mfo* c, float inserito);
int read_mfo(struct mfo* c, float *letto);
int get_from_mfo(struct mfo*c, float *letto);

int main()
{
	struct mfo A;

	init_mfo(&A);

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
			insert_mfo(&A, valore);
		}

		else if(scelta == 2)
		{
			if(read_mfo(&A, &valore))
			printf("Valore letto in testa %.2f\n", valore);
		}

		else if(scelta == 3)
		{
			if(get_from_mfo(&A, &valore))
			printf("Valore letto in testa %.2f e' stato rimosso\n", valore);
		}
		else if(scelta != 0)
		{
			printf("Scelta errata, riprovare!\n");
		}
	}

	return 0;
}

void init_mfo(struct mfo* c)
{
	c->n_occupati = 0;
}

int is_mfo_full(struct mfo* c)
{
	if(c->n_occupati >= SIZE_MFO) return 1;
	else return 0;
}

int is_mfo_empty(struct mfo* c)
{
	if(c->n_occupati == 0) return 1;
	else return 0;
}

int insert_mfo(struct mfo* c, float inserito)
{
	if(is_mfo_full(c))
		{
			printf("La struttura e' piena\n");
			return 0;
		}

	//devo accertarmi in che posizione inserire il minimo, dato che ho una politica FIFO, mi assicuro che
		//il primo sia sempre il minimo

		int i;

		for (i = 0; i < c->n_occupati && inserito > c->deposito[i]; i++);

			//trovata la posizione, partendo dalla fine della strutturta+1, sposto tutti gli elementi 
			//di una posizione a destra della posizione trovata

			for(int j = c->n_occupati; j > i ;--j)	//non ce bisogno di usare un sort ogni volta
			{
				c->deposito[j] = c->deposito[j-1];
			}

			//dopo fatto cio copio l'elemento nella sua posizione corretta

			c->deposito[i] = inserito;

			//aumento la dimensione occupata della struttura

			++c->n_occupati;

			printf("Elemento inserito\n");

			return 1;	
}

int read_mfo(struct mfo* c, float *letto)
{
	if(is_mfo_empty(c))
	{
		printf("La struttura e' vuota\n");
		return 0;
	}

	*letto = c->deposito[0];

	return 1;
}

int get_from_mfo(struct mfo*c, float *letto)
{
	if(is_mfo_empty(c))
	{
		printf("La struttura e' vuota\n");
		return 0;
	}

	read_mfo(c,letto);

	for (int i = 0; i < c->n_occupati; ++i)
	{
		c->deposito[i] = c->deposito[i+1];
	}

	--c->n_occupati;

	return 1;
}