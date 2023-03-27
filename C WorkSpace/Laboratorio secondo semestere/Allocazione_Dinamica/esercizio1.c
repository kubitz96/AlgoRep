//Implementare una struttura dati con politica di accesso Coda con relative funzioni di accesso utilizzando come struttura deposito un array allocato dinamicamente.
// Tale array dovrà modificare la propria dimensione ad ogni inserimento/rimozione di un elemento.

#include<stdio.h>
#include<stdlib.h>

#define SIZE_CODA 5
#define MEMORY_ALLOCATION_ERROR 10
#define READ_FILE_ERROR 20
#define WRITE_FILE_ERROR 30
#define OPEN_FILE_ERROR 40

struct coda
{
	float *deposito;
	int n_occupati;
};

void init_coda(struct coda* c);
int is_coda_full(struct coda* c); 
int is_coda_empty(struct coda* c);
int insert_coda(struct coda* c, float inserito);
int read_coda(struct coda* c, float *letto);
int get_from_coda(struct coda*c, float *letto);
void errorManager(int code);

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
	c->deposito = NULL;
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

		if(c->deposito == NULL)
		{
			c->deposito = malloc(sizeof(float));

			if(c->deposito == NULL) errorManager(MEMORY_ALLOCATION_ERROR);
		}
		else
		{
			float* tmp = realloc(c->deposito,(c->n_occupati+1)*sizeof(float)); //uso una parte di memoria temporanea per assicurarmi che non ci siano problemi senza danneggiare la struttura originale
			if(tmp == NULL) errorManager(MEMORY_ALLOCATION_ERROR);//in questo momento c->deposito non puntera a niente(neanche a NULL) poiche la realloc comprende una free del vecchio puntatore
			else c->deposito = tmp; //in questo caso non devo fare la free di tmp perche deposito punterà alla nuova area di memomria puntata da tmp , se usassi free perederei il blocco di memoria
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

	if(c->n_occupati > 1)
	{
		read_coda(c,letto);
		float* tmp = realloc(c->deposito,(c->n_occupati-1)*sizeof(float)); 
			if(tmp == NULL) errorManager(MEMORY_ALLOCATION_ERROR);
			else 		//copio il vettore tranne il primo elemento
			{
				for (int i = 0; i < c->n_occupati; ++i)
				{
					tmp[i] = c->deposito[i+1];
				}
			}
	}

	else
	{
		read_coda(c,letto);
		free(c->deposito); 
		c->deposito = NULL; //poiche la free non fa si che il puntatore poi punti a NULL
	}

	--c->n_occupati;

	return 1;
}

void errorManager(int code)
{
    switch (code)
    {
    case MEMORY_ALLOCATION_ERROR:
        fprintf(stderr, "Insufficient Memory!\n");
        break;

    case READ_FILE_ERROR:
        fprintf(stderr, "Reading File Error!\n");
        break;

    case WRITE_FILE_ERROR:
        fprintf(stderr, "Writing File Error!\n");
        break;
    case OPEN_FILE_ERROR:
        fprintf(stderr, "Opening File Error!\n");
        break;

    default: fprintf(stderr, "Unknow Error!\n");
        break;
    }
    exit(-1);
}