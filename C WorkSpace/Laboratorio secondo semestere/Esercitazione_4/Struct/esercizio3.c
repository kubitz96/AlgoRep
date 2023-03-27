/*    dato un vettore di strutture Votante, ognuna delle quali contenente citta_residenza, id_partito_votato
 (numero da 0 da 3 identificante un dato partito), costruire un secondo vettore di strutture contenente,
  per ogni città, l'istogramma dei partiti in base alla città.

   In altri termini, ogni struttura contenuta nel vettore dovrà contenere a sua volta,
    oltre alla città di riferimento, un array così composto:
        l'elemento 0 dovrà contenere quante persone della rispettiva città hanno votato il partito con id 0
        l'elemento 1 dovrà contenere quante persone della rispettiva città hanno votato il partito con id 1
        l'elemento 2 dovrà contenere quante persone della rispettiva città hanno votato il partito con id 2
        l'elemento 3 dovrà contenere quante persone della rispettiva città hanno votato il partito con id 3

stamparne quindi il diagramma a barre con degli * */

#include<stdio.h>
#include<string.h>

#define MAXLEN 25
#define N 10

struct votante
{
	char citta_residenza[25];
	int id_partito_votato;
};

struct istogramma
{
	char citta[25];
	int voti_partiti[4];
};

void genera_istrogrammi(struct votante A[], int n_votanti, struct istogramma B[], int * size_b);
void stampa_istogrammi(struct istogramma A[], int size_a);
int idx_is_presente(char nome_citta[MAXLEN], struct istogramma C[], int size_c);

int main()
{
	struct votante votanti[N] = 
	{
		{.citta_residenza = "Napoli",.id_partito_votato = 0},
		{.citta_residenza = "Milano",.id_partito_votato = 1},
		{.citta_residenza = "Roma",.id_partito_votato = 0},
		{.citta_residenza = "Napoli",.id_partito_votato = 0},
		{.citta_residenza = "Milano",.id_partito_votato = 1},
		{.citta_residenza = "Roma",.id_partito_votato = 3},
		{.citta_residenza = "Roma",.id_partito_votato = 2},
		{.citta_residenza = "Milano",.id_partito_votato = 0},
		{.citta_residenza = "Napoli",.id_partito_votato = 2},
		{.citta_residenza = "Napoli",.id_partito_votato = 2}
	};

	struct istogramma istogrammi[N] = {{.voti_partiti = {0}}}; //metodo di inizializzazione di un vettore a 0 dentro la struct;

	int nB = 0; //mi serve per contare quante citta rappresentare e per la stampa degli istogrammi finali perche non so quante citta sono

	genera_istrogrammi(votanti, N, istogrammi, &nB);

	stampa_istogrammi(istogrammi, nB);

	return 0;
}

void genera_istrogrammi(struct votante A[], int n_votanti, struct istogramma B[], int * size_b)
{
	int idx;

	for (int i = 0, h = 0; i < n_votanti; ++i) //devo dividere nel vettore le varie citta, quindi ho bisogno di copiare i nomi nella struct istogramma senza duplicati
	{
            idx = idx_is_presente(A[i].citta_residenza, B, n_votanti);
		    
		    if(idx == -1)
		    {
		    	strcpy(B[h].citta,  A[i].citta_residenza); //attenzione strcpy il secondo parametro viene copiato nel primo
		    	++(*size_b);
		    	B[h].voti_partiti[A[i].id_partito_votato] += 1;
		    	++h;
		    }
		    else
		    {
		    	B[idx].voti_partiti[A[i].id_partito_votato] += 1;
		    }
	}
}

void stampa_istogrammi(struct istogramma A[], int size_a)
{
	for (int i = 0; i < size_a; ++i)
	{
		printf("%s\n------\n", A[i].citta);

		for (int j = 0; j < 4; ++j)
		{
			printf("%d| ", j);
			for (int t = 0; t < A[i].voti_partiti[j]; ++t)
			{
				printf("*");
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}

int idx_is_presente(char nome_citta[MAXLEN], struct istogramma C[], int size_c)
{
	for (int i = 0; i < size_c; ++i)
	{
		if(strcmp(nome_citta,C[i].citta) == 0) return i;
	}

	return -1;
}
