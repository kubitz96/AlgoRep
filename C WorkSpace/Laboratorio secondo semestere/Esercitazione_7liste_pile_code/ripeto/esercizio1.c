/*implementare le seguenti funzioni per una lista concatenata di interi:
remove_at(...): data in input una lista concatenata ed un indice di posizione idx, 
rimuovere dalla lista l'elemento in posizione idx. Si consideri il primo elemento avente posizione 0. Tale funzione dovrà restituire:
NULL, se l'elemento in posizione idx non esiste
l'indirizzo dell'elemento rimosso dalla lista
insert_at(...): data in input una lista concatenata, un valore val ed un indice di posizione idx, inserisce l'elemento val in posizione idx.
 Si consideri il primo elemento avente posizione 0. Se idx va oltre la lunghezza effettiva della lista, l'elemento dovrà essere inserito alla fine della lista*/

#include<stdio.h>
#include<stdlib.h>

struct elemento
{
	int valore;
	struct elemento* prossimo;
};

void insert_at(struct elemento **inizio, int posizione, int intero);
struct elemento * remove_at(struct elemento **inizio, int posizione);
void delete_list(struct elemento *inizio);
void print_list(struct elemento *inizio);

int main()
{
	struct elemento* inizio = NULL;

	int scelta = -1;

	while(scelta != 0)
	{
		printf("Scegli:\n");
		printf("1:Inserisci elemento\n");
		printf("2:Rimuovi elemento\n");
		printf("3:Stampa lista\n");
		printf("4:Cancella lista\n");
		printf("0:Esci\n");
		scanf("%d", &scelta);

		if(scelta == 1)
		{
			int idx, val;
			printf("Inserire valore\n");
			scanf("%d", &val);
			printf("Inserire la posizione in cui si desidera aggiungere l'elemento alla lista\n");
			scanf("%d", &idx);
			insert_at(&inizio, idx, val);
		}
		else if(scelta == 2)
		{
			int idx;
			printf("Inserire la posizione in cui si desidera rimuovere l'elemento dalla lista\n");
			scanf("%d", &idx);
			remove_at(&inizio, idx);
		}
		else if(scelta == 3)
		{
			print_list(inizio);
		}
		else if(scelta == 4)
		{
			delete_list(inizio);
			inizio = NULL; // non dimenticare
		}
		else if(scelta != 0) printf("Scelta errata, ripetere!\n"); 
	}
	
	return 0;
}

void insert_at(struct elemento **inizio, int posizione, int intero)
{
	struct elemento* nuovo = malloc(sizeof(struct elemento));
	nuovo->valore = intero;
	nuovo->prossimo = NULL;

	struct elemento* cursore = *inizio;
	struct elemento* precedente = NULL;

	int i = 0;

	while(cursore != NULL && i < posizione)
	{
		precedente = cursore;
		cursore = cursore->prossimo;
		++i;
	}

	if(precedente == NULL)	//ci sono due casi: idx è 0 oppure la lista è vuota
	{
		 nuovo->prossimo = *inizio;
		 *inizio = nuovo;
	}
	else //precedente punta o all'ultima posizione prima di idx oppure alla fine della lista
	{
		nuovo->prossimo = precedente->prossimo; //pongo come successivo al nuovo elemento inserito il successivo dell'ultimo elemento prima della posizione idx
		precedente->prossimo = nuovo; //non uso il cursore perche potrebbe finire fuori dalla lista
	}
	printf("Elemento inserito!\n");
}

struct elemento * remove_at(struct elemento **inizio, int posizione)
{
	if(*inizio == NULL)
		{
			printf("La lista e' vuota!\n");
			return NULL;
		}
	else
	{

		struct elemento* cursore = *inizio;
		struct elemento* precedente = NULL;
		int i = 0;

		while(cursore->prossimo != NULL && i < posizione)
		{
			precedente = cursore;
			cursore = cursore->prossimo;
			++i;
		}

		if(cursore == NULL) //significa che posizione è maggiore della lunghezza della lista
		{
			printf("La posizione è vuot!\n");
			return NULL;
		}
		else
		{
			struct elemento * rimosso = cursore;
			precedente->prossimo = cursore->prossimo;
			return rimosso;
		}
	}
	printf("Elemento rimosso!\n");
}

void print_list(struct elemento *inizio)
{
	if(inizio == NULL)
		{
			printf("La lista e' vuota!\n");
		}

	while(inizio != NULL)
	{
		printf("->{%d}", inizio->valore);
		inizio = inizio->prossimo;
	}
	printf("\n");
}

void delete_list(struct elemento *inizio)
{
	while(inizio != NULL)
	{
		struct elemento * prossimo = inizio->prossimo; //per non perdere il successivo
		free(inizio);
		inizio =prossimo;
	}
	printf("Lista cancellata!\n");
}