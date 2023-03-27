#include<stdio.h>
#include<stdlib.h>

struct dati
{
	char nome[60];
	int dipendenti;
	int dipartimenti;
	int sedi;
};

struct elemento
{
	struct dati *deposito;
	struct elemento * prossimo;
};

int main()
{
	struct elemento* inizio = NULL;

	inizio = malloc(sizeof(struct elemento));

	inizio->deposito->dipendenti = 3;

	printf("%d", inizio->deposito->dipendenti);
}