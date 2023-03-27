#ifndef STRUCT_H
#define STRUCT_H

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

#endif