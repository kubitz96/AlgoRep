//AMERIGO SCAMARDELLA 20 GIUGNO N86004031

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	remove_tied(&inizio);
	printf("RIMOZIONE COMPLETATA!\n");
	printf("STAMPA DELLA LISTA POST-RIMOZIONE!\n");
	print_list(inizio);
	printf("SALVATAGGIO NUOVA LISTA!\n");
	write_winners_on_file("vittorie_X.txt", "vittorie_O.txt", inizio);
	printf("SALVATAGGIO COMPLETATO! PROGRAMMA TERMINATO\n");
	freelist(inizio);
	
	inizio = NULL;

	return 0;
}