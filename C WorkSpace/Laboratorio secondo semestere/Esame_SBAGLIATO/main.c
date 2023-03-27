//AMERIGO SCAMARDELLA 20 GIUGNO N86004031

/*Si chiede di scrivere un programma in linguaggio C che effettui le seguenti operazioni:
Punto 1: caricare il contenuto del filein una lista semplicemente concatenata. La funzione di caricamento
dovrà chiamarsi load matches from file(...).*/

#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "prototipi.h"


int main()
{
	struct Configurazione* inizio = NULL;

	printf("LETTURA FILE!\n");
	load_matches_from_file("configurazioni.txt", &inizio);
	printf("LETTURA COMPLETATA!\n");
	printf("STAMPA DELLA LISTA ACQUISITA!\n");
	print_list(inizio);
	printf("RIMOZIONE FILE NON ADATTI DALLA LISTA!\n");
	remove_tied(&inizio, 12);
	printf("RIMOZIONE COMPLETATA!\n");
	printf("STAMPA DELLA LISTA POST-RIMOZIONE!\n");
	print_list(inizio);
	printf("SALVATAGGIO NUOVA LISTA!\n");
	write_winners_on_file("vittorie X.txt", "vittorie o.txt", inizio);
	printf("SALVATAGGIO COMPLETATO! PROGRAMMA TERMINATO\n");
	freelist(inizio);
	
	inizio = NULL;

	return 0;
}