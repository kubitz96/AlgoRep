/*Scrivere un programma che effettui una simulazione del classico gioco dell'Impiccato su una frase, così definito:

viene assegnato all'utente un numero massimo di tentativi con cui può indovinare una frase (e.g., 5)
viene presentata all'utente una serie di asterischi che indicano la struttura della frase,
i.e. da quante lettere ogni parola è composta e quante parole sono e.g. ** *** ******
indica che la frase è costituita da 3 parole rispettivamente di 2, 3 e 6 lettere.
Eventuali lettere accentate, apostrofi, segni di punteggiatura e cifre numeriche devono essere visualizzati di default,
e.g., la frase "l'orco è vicino" dovrà essere presentata come *'**** è ******
L'utente può quindi scegliere se:

fornire una lettera: scegliere una lettera (maiuscola o minuscola non deve far differenza),
se la lettera è contenuta nella frase, tutte le sue corrispondenze vengono svelate (ossia gli asterischi corrispondenti vengono tolti) altrimenti viene consumato un tentativo.
provare a dare la soluzione: l'utente può provare a digitare la frase, se la soluzione è corretta il giocatore ha vinto, altrimenti viene consumato un tentativo
Quando il numero dei tentativi raggiunge zero, l'utente ha perso ed il gioco termina.

L'insieme delle frasi possibili è contenuto in un file di testo dizionario.txt contenente una sequenza di frasi (e null'altro).
Ogni frase deve essere lunga al massimo 255 caratteri. All'inizio del gioco, il programma sceglierà casualmente una frase tra tutte le frasi disponibili*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

#define TENTATIVI 5
#define MAXLEN 200
#define MEMORY_ALLOCATION_ERROR 10
#define READ_FILE_ERROR 20
#define WRITE_FILE_ERROR 30

void memorizza_frase(char * nomeFile,char frase[], int *sizefra);
void errorManager(int c);
int random_int_in_range(int a, int b);
void mostra_frase(char frase[], int flag[], int caratteri);
void verifica_instringa(char carattere, char frase[], int flag[]);
int verifica_soluzione(char soluzione[],char frase[],int flag[]);

int main()
{
	char FRASE[MAXLEN];
	int len_fra;
	int tentativi = TENTATIVI;

	memorizza_frase("dizionario.txt",FRASE, &len_fra);

	for (int i = 0; i < len_fra; ++i)
	{
		if(isupper(FRASE[i]))FRASE[i] = tolower(FRASE[i]);
	}

	int flag[MAXLEN];

	for (int i = 0; i < len_fra; ++i)
	{
		if(FRASE[i] >= 'a' && FRASE[i] <= 'z') flag[i] = 0;
		else flag[i] = 1;
	}

	printf("Inizio gioco dell'impiccato!\n");

	int scelta = -1;

	while(scelta != 0)
	{
		mostra_frase(FRASE, flag, len_fra);
		printf("Hai %d tentativi\n", tentativi);
		printf("Scegli:\n1)Dai una lettera\n2)Dai soluzione\n0)Esci\n");
		scanf("%d", &scelta);

		if(scelta == 1)
		{
			getchar(); //lo inserisco per eliminare lo \n
			printf("inserisci lettera\n");
			char let;
			scanf("%c", &let);
			verifica_instringa(let, FRASE, flag);
			--tentativi;
		}

		else if(scelta == 2)
		{
			char soluzione[len_fra];
			printf("Inserire soluzione\n");
			getchar();
			gets(soluzione);
			if(verifica_soluzione(soluzione, FRASE, flag))
				{
					printf("Hai vinto\n");
					scelta = 0;
				}
			else printf("Soluzione errata\n");

			--tentativi;
		}

		else if(scelta != 0)
		{
			printf("scelta sbagliata, ripeti\n");

		}

		if(tentativi == 0)
			{
				printf("Hai perso\n");
				for (int i = 0; i < len_fra; ++i)
				{
					flag[i] = 1;
				}
				printf("La frase giusta era ");
				mostra_frase(FRASE, flag, len_fra);
				scelta = 0;
			}
	}

	//printf("%s\n",FRASE);

	return 0;

}

void mostra_frase(char frase[], int flag[], int caratteri)
{
	for (int i = 0; i < caratteri; ++i)
	{
		if(flag[i] == 0) printf("*");
		else printf("%c", frase[i]);
	}
	printf("\n");
}

void memorizza_frase(char * nomeFile,char frase[],int *sizefra)
{
	FILE* fp;
	int cntFrasi = 0;
	srand(time(NULL));

	fp = fopen(nomeFile, "r");

	if(fp == NULL)
	{
		errorManager(READ_FILE_ERROR);
	}

	while(!feof(fp))
	{
		if(fgets(frase,MAXLEN, fp) != NULL) ++cntFrasi; ;
	}

	int idx = random_int_in_range(0,cntFrasi-1);

	//printf("idx = %d\n", idx);

	rewind(fp);

	int cntscan = -1;

	while( cntscan != idx)
	{
		fgets(frase,MAXLEN, fp);
		++cntscan;
	}

	for (int i = 0; frase[i] != '\0'; ++i)
	{
		if(frase[i] == '\n')
		{
			frase[i] = frase[i+1]; //fgets prende anche \n quindi vai ripulito
			*sizefra = i+1;
		}
	}
	
	fclose(fp);
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

    default: fprintf(stderr, "Unknow Error!\n");
        break;
    }
    exit(-1);
}

int random_int_in_range(int a, int b)
{
    return rand() % (b + 1 - a) + a;
}

void verifica_instringa(char carattere, char frase[], int flag[])
{
	for (int i = 0; frase[i] != '\0'; ++i)
	{
		if(carattere == frase[i] && flag[i] == 0) flag[i] = 1;
	}
}

int verifica_soluzione(char soluzione[],char frase[],int flag[])
{
	if(strcmp(soluzione,frase) == 0)
	{
		for (int i = 0; frase[i] != '\0'; ++i)
		{
			flag[i] = 1;
		}
		return 1;
	} 
	else return 0;
}