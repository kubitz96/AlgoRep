/*Si vuole realizzare un programma che simuli una cassaforte i cui dati sono contenuti in un file binario.

Tale cassaforte sarà costituita da:

una combinazione (numero intero)
un ammontare di denaro
All'utente deve essere presentato un menù in cui può scegliere se:

creare una nuova cassaforte
aprire la cassaforte
inserire denaro
prelevare denaro
visualizzare il denaro
cambiare la combinazione
chiudere la cassaforte
uscire dal programma

La creazione di una nuova cassaforte distruggerà i dati della precedente e darà la possibilità all'utente di impostare una combinazione.

Tutte le operazioni potranno essere effettuate solo se la cassaforte è aperta. Una volta chiusa la cassaforte, il file binario dovrà essere aggiornato con le nuove informazioni.*/

#include<stdio.h>
#include<stdlib.h>

#define FILENAME "cassa.bin"
#define MEMORY_ALLOCATION_ERROR 10
#define READ_FILE_ERROR 20
#define WRITE_FILE_ERROR 30
#define OPEN_FILE_ERROR 40

struct cassaforte
{
	int combinazione;
	float ammontare;
	int stato;
};

void inizializza_cassaforte(struct cassaforte* C);
void crea_cassaforte (struct cassaforte* C);
void apri_cassaforte (struct cassaforte* C, int combinazione);
void visualizza_cassaforte (struct cassaforte C);
void visualizza_ammontare (struct cassaforte C);
void deposita (struct cassaforte* C, int somma);
void preleva (struct cassaforte* C, int somma);
void chiudi_cassaforte (struct cassaforte* C);
void errorManager(int c);

int main()
{
	struct cassaforte cassa;
	inizializza_cassaforte(&cassa);

	int scelta = -1;

	while(scelta != 0)
	{
		printf("Scegli:\n");
		printf("1. crea nuova cassaforte (eventuale cassaforte già esistente sarà distrutta)\n");
		printf("2. apri cassaforte\n");
		printf("3. visualizza lo stato della cassaforte\n");
		printf("4. visualizza ammontare\n");
		printf("5. deposita somma\n");
		printf("6. preleva somma\n");
		printf("7. chiudi cassaforte\n");
		printf("0. esci (eventuali modifiche a cassaforte aperta andranno perse)\n");
		scanf("%d", &scelta);

		if(scelta == 1)
		{
			crea_cassaforte(&cassa);
		}

		else if(scelta == 2)
		{
			printf("Inserire combinazione\n");
			float combinazione;

			scanf("%f", &combinazione);
			apri_cassaforte(&cassa, combinazione);
		}

		else if(scelta == 3)
		{
			visualizza_cassaforte(cassa); //dato che non devo modificare i dati ma solo visualizzarli non ho bisogno di deferenziare
		}
		else if (scelta == 4)
		{
			visualizza_ammontare(cassa);
		}
		else if (scelta == 5)
		{
			printf("Inserire somma da depositare\n");
			float somma;

			scanf("%f", &somma);
			deposita(&cassa, somma);
		}
		else if (scelta == 6)
		{
			printf("Inserire somma da prelevare\n");
			float somma;

			scanf("%f", &somma);
			preleva(&cassa, somma);
		}
		else if(scelta == 7)
		{
			chiudi_cassaforte(&cassa); //solo in caso di chiusura quindi di output si salvano le modifiche, copiando dalla struttura di appoggio i dati relativi
		}
		else if(scelta != 0) printf("Scelta errata\n");
	}

	return 0;
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

void inizializza_cassaforte(struct cassaforte* C)
{
	C->ammontare = 0;
	C->stato = 0;
}

void crea_cassaforte (struct cassaforte* C)
{
	printf("Sceglia la combinazione\n");
	scanf("%d", &(C->combinazione));

	inizializza_cassaforte(C);

	FILE* fp = fopen(FILENAME, "wb");

	if(fp == NULL) errorManager(OPEN_FILE_ERROR);

	int scritti;

	scritti = fwrite(&(C->combinazione),sizeof(C->combinazione),1,fp);
	if(scritti < 1) errorManager(WRITE_FILE_ERROR);

	scritti = fwrite(&(C->ammontare),sizeof(C->ammontare),1,fp);
	if(scritti < 1) errorManager(WRITE_FILE_ERROR);

	scritti = fwrite(&(C->stato),sizeof(C->stato),1,fp);
	if(scritti < 1) errorManager(WRITE_FILE_ERROR);

	fclose(fp);
}

void apri_cassaforte (struct cassaforte* C, int combinazione)
{
	struct cassaforte tmp;

	if(C->stato == 1) printf("Cassaforte gia' aperta");	//il file va aperto è copiato nella struttura di appoggio in modo da non perdere i dati
	else
	{
		FILE* fp = fopen(FILENAME, "rb");

	if(fp == NULL) errorManager(OPEN_FILE_ERROR);

	int letti;

	letti = fread(&tmp,sizeof(struct cassaforte),1,fp);
	if(letti < 1) errorManager(READ_FILE_ERROR);

	if(tmp.combinazione == combinazione)	//solo se la combinazione e giusta copio quello che ho letto, e copiato in una cassaforte di appoggio;
	{
		printf("Hai aperto la cassaforte\n");
		*C = tmp;
		C->stato = 1;
	}
	else printf("Combinazione errata\n");

	fclose(fp);
	}
}

void visualizza_cassaforte (struct cassaforte C)
{
	if(C.stato == 1) printf("La cassaforte e' aperta\n");
	else if(C.stato == 0) printf("La cassaforte e' chiusa\n");
}

void visualizza_ammontare (struct cassaforte C)
{
	if(C.stato == 0) printf("La cassaforte e' chiusa\n");
	else if(C.stato == 1) printf("L'ammontare nella cassaforte e' di %.2f\n", C.ammontare);
}

void deposita (struct cassaforte* C, int somma)
{
	if(C->stato == 0) printf("La cassaforte e' chiusa\n");
	else if(C->stato == 1)
	{
		C->ammontare += somma;
	}
}

void preleva (struct cassaforte* C, int somma)
{
	if(C->stato == 0) printf("La cassaforte e' chiusa\n");
	else if(C->stato == 1)
	{
		if(somma <= C->ammontare) C->ammontare -= somma;
		else printf("Non ci sono abbastanza soldi\n");
	}
}

void chiudi_cassaforte (struct cassaforte* C)
{
	FILE* fp = fopen(FILENAME, "wb");

	if(fp == NULL) errorManager(OPEN_FILE_ERROR);

	int scritti = fwrite(C,sizeof(struct cassaforte),1,fp);

	if(scritti < 1) errorManager(WRITE_FILE_ERROR);

	fclose(fp);

	C->stato = 0;
}