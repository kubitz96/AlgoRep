#include<stdio.h>
#include<stdlib.h>
struct Configurazione
{
	struct Dati* Deposito;
	struct Configurazione* Prossimo;
};

struct Dati
{
	char configurazione[3][3];
	char vincitore;
	int punteggio;
};

//esempio di main struct configurazione * inizio = NULL; add_in_list(&inizio, temp)

void add_in_list(struct Configurazione ** start, struct Dati temp)	
{
	/* start == &inizio
	   *start == inizio (ricordati che inizio è un puntatore a struct non la struct stessa quindi non possiede campi)
	   QUINDI QUESTA DICITURA NON HA SENSO PERCHE IL PUNTATORE NON HA IL CAMPO PROSSIMO (sbagliato) --> *start.prossimo == inizio.prossimo
	   DICITURA GIUSTA *start->Prossimo == inizio->prossimo QUINDI SE VOGLIO L'INDIRIZZO DEL PUNTATORE PROSSIMO SCRIVO:  &((*start)->Prossimo)
		*/
	if(*start== NULL)
	{

		struct Dati * new_data = malloc(sizeof(struct Dati));
		*new_data = temp;

		
		struct Configurazione * nuovo = malloc(sizeof(struct Configurazione));
		nuovo->Deposito = new_data;
		nuovo->Prossimo = NULL;
		*start = nuovo;
		
		return;
	}

	else add_in_list(&((*start)->Prossidfdsmo), temp);

}

