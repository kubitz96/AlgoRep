#include "stdio.h"
#include "stdlib.h"
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

int load_matches_from_file(char filename[64], struct Configurazione **start)
{
	FILE* fp = fopen(filename, "r");

	if(fp == NULL) errorManager(ERR_R);

	//ho bisogno di una struttura dove copiare i dati letti temporaneamente

	struct Dati tmp;

	char Config[10];	//uso un vettore di char da poi convertire in matrice per

	while(fscanf(fp,"%s", Config) == 1) 
	{	
		int h = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				tmp.configurazione[i][j] = Config[h];
				++h;
			}
		}

		tmp.vincitore = the_winner_is(tmp.configurazione, &(tmp.vincitore));
		tmp.punteggio = match_score(tmp.configurazione, &(tmp.punteggio));

										
		add_in_list(start, tmp); 						
	}

	fclose(fp);
	return 1;
}

void print_list(struct Configurazione *start)
{
	if(start != NULL)
	{
		printf("%s %c %d \n", start->Deposito->configurazione[0], start->Deposito->vincitore, start->Deposito->punteggio);
		print_match(start->Deposito);
		print_list(start->Prossimo);
	}
}

void freelist(struct Configurazione * start)
{
	if(start == NULL) printf("La lista è vuota");
	while(start != NULL)
	{
		struct Configurazione * prox = start->Prossimo;
		free(start);
		start = prox;
	}
}

void add_in_list(struct Configurazione ** start, struct Dati temp)	//soluzione ricorsiva molto comoda
{

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

	else add_in_list(&((*start)->Prossimo), temp);

}

char the_winner_is(char Conf[3][3], char *vincitore)
{
	char winner = 'P';
	
	int checkriga = 1; 	//diagonale 1 i == j//diagonale 2 i+j == N-1
	int checkcol = 1;
	int checkdia = 1;
	int checkdia2 = 1;

	for (int i = 0; i < 3 && winner == 'P'; ++i)
	{
		for (int j = 0; j < 3-1 && checkriga == 1 ; ++j)	//controllo le righe
		{

			if(Conf[i][j] != Conf[i][j+1] || Conf[i][j] == '@') checkriga = 0;
		}
		if(checkriga == 1) 
		{
			winner = Conf[i][0];
			return winner;
		}

	}

	for (int i = 0; i < 3 && winner == 'P'; ++i)
	{
		for (int j = 0; j < 3-1 && checkcol == 1; ++j)	//controllo le colonne
		{
			if(Conf[j][i] != Conf[j+1][i] || Conf[i][j] == '@') checkcol = 0;
		}

		if(checkcol == 1)
		{
			winner =Conf[0][i];
			return winner;
		};
	}

	for (int i = 0; i < 3-1 && winner == 'P' ; ++i)
	{
		int j = i;
		//controllo la diagonale 1
		
		if(Conf[i][j] != Conf[i+1][j+1] || Conf[i][j] == '@') checkdia = 0;
		
	}
	if(checkdia == 1) return Conf[0][0];

	for (int i = 0; i < 3-1 && winner == 'P'; ++i)
	{
		int j = 3-1-i;
		//controllo la diagonale 2
		
		if(Conf[i][j] != Conf[i+1][j-1] ||Conf[i][j] == '@') checkdia2 = 0;
		
	}
	if(checkdia2 == 1) return Conf[0][2];

	return winner;
}

int match_score(char Conf[3][3], int *punteggio)
{
	int score = 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if(Conf[i][j] == '@') ++score;
		}
	}

	return score;
}

void print_match(struct Dati* temp)
{
	for (int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			printf("%c ", temp->configurazione[i][j]);
		}
		printf("\n");
	}
}

void remove_tied(struct Configurazione **start, char vincitore)
{
	struct Configurazione* cursore = *start;
	struct Configurazione* precedente = NULL;

	while(cursore != NULL)
	{

		if(cursore->Deposito->vincitore == 'P')
		{
			struct Configurazione* libero = cursore;

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

int sizelist(struct Configurazione * start)
{
	int n = 0;

	struct Configurazione* cursore = start;

	while(cursore != NULL)
	{
		++n;
		cursore = cursore->Prossimo;
	}
	return n;
}

int write_winners_on_file(char filename[64], char filename2[64], struct Configurazione *start) //non passo per riferimento poiche non devo modifica la lista ma solo copiarla
{
	FILE* fp = fopen(filename, "w");

	if(fp == NULL) errorManager(ERR_W);
	fclose(fp);

	FILE* fp2 = fopen(filename2, "w");
	if(fp == NULL) errorManager(ERR_W);
	

		struct Configurazione* cursore = start;
		
		while(cursore != NULL)
		{
			if(cursore->Deposito->vincitore == 'X') fprintf(fp,"%s %c %d \n", cursore->Deposito->configurazione[0], cursore->Deposito->vincitore, start->Deposito->punteggio);
			cursore = cursore->Prossimo;
		}

		cursore = start;
		while(cursore != NULL)
		{
			if(cursore->Deposito->vincitore == 'O') fprintf(fp2,"%s %c %d \n", cursore->Deposito->configurazione[0], cursore->Deposito->vincitore, start->Deposito->punteggio);
			cursore = cursore->Prossimo;
		}

	fclose(fp2);
	
	return 1;
}