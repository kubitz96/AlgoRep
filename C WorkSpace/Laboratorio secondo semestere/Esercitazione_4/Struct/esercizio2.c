//dato un vettore di strutture contenente id_esame (int), esame (stringa),voto (int)
//stampare il nome dell'esame con voto minimo ed il nome dell'esame con voto massimo

#include<stdio.h>

#define MAXLEN 25
#define N 3

struct esame
{
	int id_esame;
	char esame[MAXLEN];
	int voto;
};

int main()
{
	struct esame V[N] =
	{
		01, "programmazione", 26,
		02, "analisi", 23,
		03, "laboratorio", 18
	};

	int min, max;

	min = max = 0;

	for (int i = 1; i < N; ++i)
	{
		if(V[i].voto > V[max].voto) max = i;
		if(V[i].voto < V[min].voto) min = i;
	}

	printf("Voto minimo in %s, voto massimo in %s\n", V[min].esame, V[max].esame);

	return 0;
}