#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "prototipi.h"

#define ERR_R -10
#define ERR_W -20
#define ERR_M -30

void errorManager(int c)
{
	switch(c)
	{
		case ERR_R : printf("Errore in fase di lettura!");
		exit(-1);
		break;

		case ERR_W : printf("Errore in fase di scrittura!");
		exit(-1);
		break;

		case ERR_M : printf("Errore in memoria!");
		exit(-1);
		break;
		default : printf("Errore sconosciuto!");
		exit(-1);
		break;
	}
}

int read_file(char filename[64], struct Azienda **start)
{
	FILE* fp = fopen(filename, "r");

	if(fp == NULL) errorManager(ERR_R);

	//ho bisogno di una struttura dove copiare i dati letti temporaneamente

	struct Dati tmp;

	while(fscanf(fp,"%s %d %d %d", tmp.NomeAzienda, &(tmp.Dipendenti), &(tmp.Dipartimenti), &(tmp.Sedi)) == 4) //nome azienda non ce bisogno di mettere & poiche essendo un vettore di char sto gia indicando la posizione zero
	{												//creo una funzione che copi gli elementi nella lista temporanea
		add_in_list(start, tmp); 						//scrivere start e come scrive &(*start);
	}

	fclose(fp);
	return 1;
}

void add_in_list(struct Azienda ** start, struct Dati temp)	//soluzione ricorsiva molto comoda
{

	if(*start== NULL)
	{
		struct Dati * new_data = malloc(sizeof(struct Dati));
		*new_data = temp;

		//printf("%s %d %d %d", new_data->NomeAzienda, new_data->Dipendenti, new_data->Dipartimenti, new_data->Sedi); 
		struct Azienda * nuovo = malloc(sizeof(struct Azienda));
		nuovo->Deposito = new_data;
		nuovo->Prossimo = NULL;
		*start = nuovo;
		
		return;
	}

	else add_in_list(&((*start)->Prossimo), temp);

}

void print_list(struct Azienda *start)
{
	if(start != NULL)
	{
		printf("%s %d %d %d\n", start->Deposito->NomeAzienda, start->Deposito->Dipendenti, start->Deposito->Dipartimenti, start->Deposito->Sedi);
		print_list(start->Prossimo);
	}
}

void remove_from_list(struct Azienda **start, int soglia)
{
	struct Azienda* cursore = *start;
	struct Azienda* precedente = NULL;

	while(cursore != NULL)
	{

		if(cursore->Deposito->Dipendenti < soglia)
		{
			struct Azienda* libero = cursore;

			if(precedente == NULL)
			{
				*start = libero->Prossimo;
			}
			else
			{
				precedente->Prossimo = libero->Prossimo; 
			}
			cursore = cursore-> Prossimo;	// qui il precedente rimane uguale
			free(libero);
		}
		else
		{
			precedente = cursore;
			cursore = cursore-> Prossimo;
		}
	}
}

int sizelist(struct Azienda * start)
{
	int n = 0;

	struct Azienda* cursore = start;

	while(cursore != NULL)
	{
		++n;
		cursore = cursore->Prossimo;
	}
	return n;
}

int write_sortedon_list(char filename[64], struct Azienda *start) //non passo per riferimento poiche non devo modifica la lista ma solo copiarla
{
	FILE* fp = fopen(filename, "w");

	if(fp == NULL) errorManager(ERR_W);

	int size = sizelist(start);

	int *flag = calloc(size,sizeof(int));

	for (int i = 0; i < size; ++i) // un ciclo per trovarmi il nuovo massimo
	{
		struct Azienda* cursore = start;
		struct Azienda* massimo = NULL;
		int idxmax = -1;
		int idx = 0;

		while(cursore != NULL)
		{
			if(flag[idx] == 0)
			{
				if(massimo == NULL || cursore->Deposito->Dipendenti > massimo->Deposito->Dipendenti)
				{
					massimo = cursore;
					idxmax = idx;
				}
			}
			cursore = cursore->Prossimo;
			++idx;
		}

		if(massimo != NULL)
		{
			flag[idxmax] = 1;
			fprintf(fp,"%s %d %d %d\n", massimo->Deposito->NomeAzienda, massimo->Deposito->Dipendenti, massimo->Deposito->Dipartimenti, massimo->Deposito->Sedi);
		}
	}

	fclose(fp);
	free(flag);
	return 1;
}

void freelist(struct Azienda * start)
{
	if(start == NULL) printf("La lista è vuota");
	while(start != NULL)
	{
		struct Azienda * prox = start->Prossimo;
		free(start);
		start = prox;
	}
}