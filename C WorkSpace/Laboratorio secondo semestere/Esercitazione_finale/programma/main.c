#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "prototipi.h"

int main()
{
	struct Azienda* inizio = NULL;	//lista di appoggio

	printf("LETTURA FILE!\n");
	read_file("inputfile.txt", &inizio);
	printf("LETTURA COMPLETATA!\n");
	printf("STAMPA DELLA LISTA ACQUISITA!\n");
	print_list(inizio);
	printf("RIMOZIONE FILE NON ADATTI DALLA LISTA!\n");
	remove_from_list(&inizio, 300);
	printf("RIMOZIONE COMPLETATA!\n");
	printf("STAMPA DELLA LISTA POST-RIMOZIONE!\n");
	print_list(inizio);
	printf("SALVATAGGIO NUOVA LISTA RIORDINATA!\n");
	write_sortedon_list("outputfile.txt", inizio);
	printf("SALVATAGGIO COMPLETATO! PROGRAMMA TERMINATO\n");
	freelist(inizio);
	inizio = NULL;

	return 0;
}