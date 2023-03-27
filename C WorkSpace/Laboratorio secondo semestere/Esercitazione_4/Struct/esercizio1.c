//dato un vettore di strutture contenente cognome e età,
//calcolare l'età media di tutte e sole le persone con più di 30 anni e il cui cognome inizi con la lettera 'B'

#include<stdio.h>

#define MAXLEN 25
#define N 5

struct persona
{
	char cognome[MAXLEN];
	int eta;
};

int main()
{
	int cnt = 0;
	int somma = 0;
	int media;

	struct persona V[N] =
	{
		"Biagio", 20,
		"Antonio", 36,
		"bartolo", 25,
		"betta", 15,
		"Carlo", 66
	};

	for (int i = 0; i < N; ++i)
	{
		if(V[i].cognome[0] == 'b' || V[i].cognome[0] == 'B')
		{
			somma +=V[i].eta;
			++cnt;
		}
	}
	media = somma/cnt;

	printf("La media e' %d\n", media);

	return 0;
}