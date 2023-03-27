//Implementare una struttura dati con politica di accesso Pila con relative funzioni di accesso utilizzando come struttura deposito un array allocato dinamicamente.
// Tale array dovrà modificare la propria dimensione ad ogni inserimento/rimozione di un elemento

#include<stdio.h>
#include<stdlib.h>

#define N_PILA 256
#define MEMORY_ALLOCATION_ERROR 10
#define READ_FILE_ERROR 20
#define WRITE_FILE_ERROR 30
#define OPEN_FILE_ERROR 40

struct pila
{
	float *deposito;
	int n_occupati;
};

void init_pila(struct pila* p);
int push(struct pila* p, float inserito);
int pop(struct pila*p, float *rimosso);
int is_pila_full(struct pila*p);
int is_pila_empty(struct pila*p);
void errorManager(int code);
int read_pila(struct pila* p, float *letto);

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
		else if(scelta != 0)
		{
			printf("Scelta errata, riprovare!\n");
		}
	}
}

void init_pila(struct pila* p)
{
	p->n_occupati = 0;
}

int push(struct pila* p, float inserito)
{
	if(is_pila_full(p))
	{
		printf("La pila e' piena\n");
		return 0;
	}

	if(p->deposito == NULL)
		{
			p->deposito = malloc(sizeof(float));

			if(p->deposito == NULL) errorManager(MEMORY_ALLOCATION_ERROR);
		}
		else
		{
			float* tmp = realloc(p->deposito,(p->n_occupati+1)*sizeof(float)); //uso una parte di memoria temporanea per assicurarmi che non ci siano problemi senza danneggiare la struttura originale
			if(tmp == NULL) errorManager(MEMORY_ALLOCATION_ERROR);//in questo momento c->deposito non puntera a niente(neanche a NULL) poiche la realloc comprende una free del vecchio puntatore
			else p->deposito = tmp; //in questo caso non devo fare la free di tmp perche deposito punterà alla nuova area di memomria puntata da tmp , se usassi free perederei il blocco di memoria
		}

		p->deposito[p->n_occupati] = inserito;
		++p->n_occupati;

		printf("Elemento inserito\n");

	return 1;
}

int pop(struct pila*p, float *rimosso)
{
	if(is_pila_empty(p))
	{
		printf("La pila e' vuota\n");
		return 0;
	}

	if(p->n_occupati > 1)
	{
		read_pila(p,rimosso);
		float* tmp = realloc(p->deposito,(p->n_occupati-1)*sizeof(float)); 
			if(tmp == NULL) errorManager(MEMORY_ALLOCATION_ERROR);
			else p->deposito = tmp;
	}

	else
	{
		read_pila(p,rimosso);
		free(p->deposito); 
		p->deposito = NULL; //poiche la free non fa si che il puntatore poi punti a NULL
	}

	--p->n_occupati;

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

int read_pila(struct pila* p, float *letto)
{

	if(is_pila_empty(p))
	{
		printf("La struttura e' vuota\n");
		return 0;
	}

	*letto = p->deposito[p->n_occupati-1];

	return 1;
}