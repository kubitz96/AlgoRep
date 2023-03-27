//Ripetere l'esercizio precedente, ma simulando un reale mazzo di 52 carte, composto da 4 gruppi di 13 carte,
// ogni gruppo appartenente ad un singolo seme (fiori, quadri, cuori, picche). Ad ogni estrazione, deve essere visualizzato sia il valore della carta sia il seme.
// Tenere conto che una stessa carta non può essere estratta più di una volta.

//Consiglio: utilizzare una struct per rappresentare ogni singola Carta.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define PMAX 21
#define MAXC 52
#define MAXS 4
#define MAXN 13

struct carta
{
	int numero;
	char seme[10];
};

void componimazzo(struct carta deck[], char* seeds[], int nseeds, int numbers);
void stampamazzo(struct carta deck[], int sizedeck);
int pescacarta(struct carta deck[], int *sizedeck);

int main()
{
	char *semi[MAXS]=
	{
		"cuori",
		"fiori",
		"picche",
		"quadri"
	};

	struct carta mazzo[MAXC];

	componimazzo(mazzo, semi, MAXS, MAXN);

	//stampamazzo(mazzo, MAXC);

	//per evitare di pescare due volte la carta estraggo un indice poi con lo shift a sinistra sposto la carta elimnata in fondo al mazzo e diminuisco di 1 il numero di carte del mazzo

	int n_carte = MAXC;
	int scelta = 0;
    int punt_u = 0;

    printf("Turno dell'utente\n");

    while(scelta != 2)
    {
        printf("Punteggio attuale %d.\n", punt_u);
        printf("Scegli:\n1) Estrai una carta\n2) Fermati\n");
        scanf("%d", &scelta);
        if(scelta == 1) punt_u += pescacarta(mazzo, &n_carte);
        else if(scelta != 2) printf("Scelta non valida, ripeti!\n"); 
        if (punt_u > PMAX) scelta = 2;
    }

    if (punt_u > PMAX) printf("Hai Perso!");

    else
    {
    int punt_m = 0;
    printf("Hai terminato il turno!\nTurno della macchina\n");
     while(punt_m < punt_u)
     {
        printf("Punteggio attuale %d.\n", punt_m);
        punt_m += pescacarta(mazzo, &n_carte);
        if(punt_m > PMAX) printf("Hai vinto!\n");
        else if(punt_m >= punt_u) printf("La macchina ha vinto!\n");
     }
    }

    return 0;
}

void componimazzo(struct carta deck[], char* seeds[], int nseeds, int numbers)
{
	int idx = 0;

	for (int i = 0; i < nseeds; ++i)
	{
		for (int j = 1; j <= numbers; ++j)
		{
			strcpy(deck[idx].seme,seeds[i]);
			deck[idx].numero = j;
			++idx;
		}
	}
}

void stampamazzo(struct carta deck[], int sizedeck)
{
	for (int i = 0; i < sizedeck; ++i)
	{
		printf("%d di %s.\n", deck[i].numero, deck[i].seme);
	}
}

int pescacarta(struct carta deck[], int *sizedeck)
{
	int idx_carta;
	int punto;

    srand(time(NULL));

    idx_carta = 1 + rand() % *sizedeck;

    printf("Carta pescata: %d di %s.\n", deck[idx_carta].numero, deck[idx_carta].seme);

    punto = deck[idx_carta].numero;
    //return rand() % (b + 1 - a) + a; metodo se si vuole definire un intervallo tra il minimo a e il massimo b;

    for (int i = idx_carta; i < *sizedeck; ++i)
    {
    	deck[i] = deck[i+1]; //shift a sinistra
    }

    --(*sizedeck);

    return punto;
}