#ifndef STRUCT_H
#define STRUCT_H

struct Configurazione
{
	struct Dati* Deposito;
	struct Configurazione* Prossimo;
};

struct Dati
{
	char configurazione[3][3];
	char vincitore;
	int punteggio;
};

#endif