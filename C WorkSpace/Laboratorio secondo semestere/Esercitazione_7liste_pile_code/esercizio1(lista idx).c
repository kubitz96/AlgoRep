/*implementare le seguenti funzioni per una lista concatenata di interi:
remove_at(...): data in input una lista concatenata ed un indice di posizione idx, 
rimuovere dalla lista l'elemento in posizione idx. Si consideri il primo elemento avente posizione 0. Tale funzione dovrà restituire:
NULL, se l'elemento in posizione idx non esiste
l'indirizzo dell'elemento rimosso dalla lista
insert_at(...): data in input una lista concatenata, un valore val ed un indice di posizione idx, inserisce l'elemento val in posizione idx.
 Si consideri il primo elemento avente posizione 0. Se idx va oltre la lunghezza effettiva della lista, l'elemento dovrà essere inserito alla fine della lista*/

#include<stdio.h>
#include<stdlib.h>

struct nodo
{
	int valore;
	struct nodo* prossimo;
};

void freelist(struct nodo * start);
void printlist(struct nodo * start);
void insertlistat(struct nodo **start, int val, int idx);
struct nodo * removelistat(struct nodo **start, int idx);

int main()
{
	int scelta = -1;

	struct nodo * inizio = NULL;

	while(scelta != 0)
    {
        printf("Scegli:\n");
        printf("1:Inserisci valore\n");
        printf("2:Stampa lista\n");
        printf("3:Cancella lista\n");
        printf("4:Rimuovi dalla lista\n");
        printf("0:Esci\n");
        scanf("%d", &scelta);

        if(scelta == 1)
        {
            int val;
            int idx;
            printf("Inserire valore e indirizzo\n");
            scanf("%d%d", &val, &idx);
            insertlistat(&inizio, val, idx);
        }
        else if(scelta == 2)
        {
            printlist(inizio);
        }
        else if(scelta == 3)
        {
            freelist(inizio);
            inizio = NULL;
        }
        else if(scelta == 4)
        {
            int idx;
            printf("Inserire posizione della lista da rimuovere\n");
            scanf("%d", &idx);
            removelistat(&inizio, idx);
        }

        else if(scelta != 0) printf("scelta errata,ripetere");
    }
}

void freelist(struct nodo * start)
{
	if(start == NULL) printf("La lista è vuota");
	while(start != NULL)
	{
		struct nodo * prox = start->prossimo;
		free(start);
		start = prox;
	}
}

void printlist(struct nodo * start)
{
	if(start == NULL) printf("La lista è vuota");

	while(start != NULL)
	{
		printf("->{%d}", start->valore);
		start = start->prossimo;
	}
	printf("\n");
}

void insertlistat(struct nodo **start, int val, int idx)
{
	struct nodo * nuovo;

	nuovo = malloc(sizeof(struct nodo));
	nuovo->valore = val;
	nuovo->prossimo = NULL;

	struct nodo* cursore = *start;
	struct nodo* prede = NULL;

	int i = 0;
	while(cursore != NULL && i < idx)
	{
		prede = cursore;
		cursore = cursore->prossimo; //mando in avanti il cursore
		++i;
	}
	printf("%d\n", i);

	if(prede == NULL)
	{
		nuovo->prossimo = *start;		//quando idx è 0
		*start = nuovo;
	}
	else
	{
		nuovo->prossimo = prede->prossimo; //prede->prossimo punta alla struct in posizione idx mentre prede a quella prima
		prede->prossimo = nuovo;
	}
}

struct nodo * removelistat(struct nodo **start, int idx)
{
	struct nodo* cursore = *start;
	struct nodo* prede = NULL;
	struct nodo* rimosso;

	if(cursore == NULL)
	{
		printf("La lista e' vuota\n");
		return NULL;
	}

	int i = 0;
	while(cursore != NULL && i < idx)
	{
		prede = cursore;
		cursore = cursore->prossimo; //mando in avanti il cursore //il cursore se arriva fino alla fine della lista punterà a NULL quindi idx sarà fuori dalla lista
		i++;	//se arriva a idx cursore puntera alla posizione idx
	}

	if(cursore == NULL)
	{
		printf("Non e' presente un elemento in questa posizione\n");
		return NULL;
	}

	else
	{
		rimosso = cursore;
		prede->prossimo = cursore->prossimo;
	}

	return rimosso; // ritorno il puntatore che non viene usato in questo modo viene rimosso se non usato
}