#ifndef STRUCT_H
#define STRUCT_H

struct Azienda
{
	struct Dati* Deposito;
	struct Azienda* Prossimo;
};

struct Dati
{
	char NomeAzienda[64];
	int Dipendenti;
	int Dipartimenti;
	int Sedi;
};

#endif