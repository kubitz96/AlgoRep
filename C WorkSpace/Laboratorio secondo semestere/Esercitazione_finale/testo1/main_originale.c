/*Si realizzi un programma in linguaggio C che,
a) legga un file di testo dove per ogni riga si ha
Nome Cognome Peso Altezza
I dati vanno immagazzinati in una opportuna lista a singolo link; i dati nella lista devono contenere tutti i dati
inclusi nel file di input nello stesso ordine del file di input, o al più un ordine inverso; stampare la lista a schermo
dopo la lettura.
b) elimini dalla lista tutti record relativi a individui che pesano meno di 12 chili;; stampare la lista a schermo al
termine dell’operazione.
c) costruisca una matrice quadrata A di dimensione nxn (n è il numero di elementi presenti nella lista) dove A(i,j) è
la media fra il peso della persona i-esima e il peso della persona j-esima; stampare la matrice a schermo;
d) scriva un file dove a ognuna delle persone presenti nella lista viene associata la persona con cui massimizza la
media dei pesi. Stampare anche a schermo il contenuto del file.
L’implementazione dei punti c) e d) non deve in alcun modo modificare la lista originale.*/

#include<stdio.h>
#include<stdlib.h>
/*#include "struct.h"
#include "prototipi.h"*/
struct Persona
{
	struct Dati* Deposito;
	struct Persona* Prossimo;
};

struct Dati
{
	char Nome[64];
	char Cognome[64];
	int Peso;
	int Altezza;
};

float **allocMatrix(int m, int n);
void freeMatrix(float **p, int m);
int read_file(char filename[64], struct Persona **start);
void errorManager(int c);
void add_in_list(struct Persona ** start, struct Dati temp);
void print_list(struct Persona *start);
void remove_from_list(struct Persona **start, int soglia);
int write_sortedon_list(char filename[64], struct Persona *start, float ** matrix);
void freelist(struct Persona * start);
int sizelist(struct Persona * start);
void printMatrix(float **p, int m, int n);
float **build_matrix(struct Persona * start, float ** m, int size);
struct Persona * read_from_listat(struct Persona *start, int idx);

int main()
{
	struct Persona* inizio = NULL;	//lista di appoggio

	printf("LETTURA FILE!\n");
	read_file("inputfile.txt", &inizio);
	printf("LETTURA COMPLETATA!\n");
	printf("STAMPA DELLA LISTA ACQUISITA!\n");
	print_list(inizio);
	printf("RIMOZIONE FILE NON ADATTI DALLA LISTA!\n");
	remove_from_list(&inizio, 12);
	printf("RIMOZIONE COMPLETATA!\n");
	printf("STAMPA DELLA LISTA POST-RIMOZIONE!\n");
	print_list(inizio);
	int n = sizelist(inizio);
	float **m;
	m = allocMatrix(n,n);
	printf("COSTRUZIONE MATRICE!\n");
	m = build_matrix(inizio, m, n);
	printf("STAMPA MATRICE OTTENUTA!\n")
	/*	27.00 43.50 48.50 36.00 41.00 20.50 
		43.50 60.00 65.00 52.50 57.50 37.00 
		48.50 65.00 70.00 57.50 62.50 42.00 
		36.00 52.50 57.50 45.00 50.00 29.50 
		41.00 57.50 62.50 50.00 55.00 34.50 
		20.50 37.00 42.00 29.50 34.50 14.00  */;
	printMatrix(m,n,n);
	printf("SALVATAGGIO NUOVA LISTA!\n");
	write_sortedon_list("outputfile.txt", inizio, m);
	printf("SALVATAGGIO COMPLETATO! PROGRAMMA TERMINATO\n");
	freelist(inizio);
	freeMatrix(m, n);
	inizio = NULL;

	return 0;
}

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

int read_file(char filename[64], struct Persona **start)
{
	FILE* fp = fopen(filename, "r");

	if(fp == NULL) errorManager(ERR_R);

	//ho bisogno di una struttura dove copiare i dati letti temporaneamente

	struct Dati tmp;

	while(fscanf(fp,"%s %s %d %d", tmp.Nome, tmp.Cognome, &(tmp.Peso), &(tmp.Altezza)) == 4) //nome Persona non ce bisogno di mettere & poiche essendo un vettore di char sto gia indicando la posizione zero
	{												//creo una funzione che copi gli elementi nella lista temporanea
		add_in_list(start, tmp); 						//scrivere start e come scrive &(*start);
	}

	fclose(fp);
	return 1;
}

void add_in_list(struct Persona ** start, struct Dati temp)	//soluzione ricorsiva molto comoda
{

	if(*start== NULL)
	{
		struct Dati * new_data = malloc(sizeof(struct Dati));
		*new_data = temp;

		//printf("%s %d %d %d", new_data->NomePersona, new_data->Dipendenti, new_data->Dipartimenti, new_data->Sedi); 
		struct Persona * nuovo = malloc(sizeof(struct Persona));
		nuovo->Deposito = new_data;
		nuovo->Prossimo = NULL;
		*start = nuovo;
		
		return;
	}

	else add_in_list(&((*start)->Prossimo), temp);

}

void print_list(struct Persona *start)
{
	if(start != NULL)
	{
		printf("%s %s %d %d\n", start->Deposito->Nome, start->Deposito->Cognome, start->Deposito->Peso, start->Deposito->Altezza);
		print_list(start->Prossimo);
	}
}

void remove_from_list(struct Persona **start, int soglia)
{
	struct Persona* cursore = *start;
	struct Persona* precedente = NULL;

	while(cursore != NULL)
	{

		if(cursore->Deposito->Peso < soglia)
		{
			struct Persona* libero = cursore;

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

int sizelist(struct Persona * start)
{
	int n = 0;

	struct Persona* cursore = start;

	while(cursore != NULL)
	{
		++n;
		cursore = cursore->Prossimo;
	}
	return n;
}

int write_sortedon_list(char filename[64], struct Persona *start, float ** matrix) //non passo per riferimento poiche non devo modifica la lista ma solo copiarla
{
	FILE* fp = fopen(filename, "w");

	if(fp == NULL) errorManager(ERR_W);

	int size = sizelist(start);

	float* Massimi = calloc(size,sizeof(float));

	for (int i = 0; i < size; ++i) // un ciclo per trovarmi il nuovo massimo
	{
		Massimi[i] = matrix[i][0];
		int idx_max = 0;

		for (int j = 0; j < size-1; ++j)
		{
			if(j+1 == i) continue;
			else
			{
				if(Massimi[i] < matrix[i][j+1])
				{
					Massimi[i] = matrix[i][j+1];
					idx_max = j+1;
				}

			}
		}
		Massimi[i] = idx_max;

	}		/*cosi creo un vettore dove la posizione indica qual'è il primo elemento della nuova lista mentre
			 il contenuto indica la posizione nella lista con cui massimizza la media;*/


		for (int i = 0; i < size; ++i)
		{
			struct Persona * primo;
			struct Persona * secondo;
			int h = Massimi[i];
			primo = read_from_listat(start, i);
			secondo = read_from_listat(start, h);
			fprintf(fp,"%s %s %s %s %.1f\n", primo->Deposito->Nome,
										   primo->Deposito->Cognome,
										   secondo->Deposito->Nome,
										   secondo->Deposito->Cognome,
										    matrix[i][h]);
			printf("%s %s %s %s %.1f\n", primo->Deposito->Nome,
										   primo->Deposito->Cognome,
										   secondo->Deposito->Nome,
										   secondo->Deposito->Cognome,
										    matrix[i][h]);
		}
	


	fclose(fp);
	
	return 1;
}

void freelist(struct Persona * start)
{
	if(start == NULL) printf("La lista è vuota");
	while(start != NULL)
	{
		struct Persona * prox = start->Prossimo;
		free(start);
		start = prox;
	}
}

float **allocMatrix(int m, int n)
{
    float **p;

    p = malloc(m*sizeof(float*));

    if(p == NULL) errorManager(ERR_M);

    for (int i = 0; i < m; i++)
    {
        p[i] = calloc(n,sizeof(float));

        if(p[i] == NULL) errorManager(ERR_M);
    }
    
    return p;
}

void freeMatrix(float **p, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(p[i]);
    }
    free(p);
}

void printMatrix(float **p, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4.2f ", p[i][j]);
        }
        puts("");
    }
}

struct Persona * read_from_listat(struct Persona *start, int idx)
{
	struct Persona* cursore = start;
	struct Persona* preso;

	if(idx == 0) preso = start;

	int i = 0;
	while(cursore != NULL && i < idx)
	{
		cursore = cursore->Prossimo; //mando in avanti il cursore //il cursore se arriva fino alla fine della lista punterà a NULL quindi idx sarà fuori dalla lista
		i++;	//se arriva a idx cursore puntera alla posizione idx
	}

	if(cursore == NULL)
	{
		printf("Non e' presente un elemento in questa posizione\n");
		return NULL;
	}

	else
	{
		preso = cursore;
	}

	return preso; // ritorno il puntatore che non viene usato in questo modo viene rimosso se non usato
}

float ** build_matrix(struct Persona * start, float ** m, int size)
{
	float *P;
	P = calloc(size,sizeof(float));

	struct Persona * tmp;

	for (int i = 0; i < size; ++i)
	{	
		tmp = read_from_listat(start, i);
		P[i] = tmp->Deposito->Peso;
		printf("%4.2f ", P[i]);
	}
	puts("");


	float ** new_m;
	new_m = allocMatrix(size,size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)	//matrice di pesi senza medie
		{
			new_m[i][j] = (P[i] + P[j])/2;
		}
	}

	free(P);

	return new_m;
}