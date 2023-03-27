#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "prototipi.h"

int main()
{
	struct Persona* inizio = NULL;	//lista di appoggio

	printf("LETTURA FILE!\n");
	read_file("inputfile.txt", &inizio);
	printf("LETTURA COMPLETATA!\n");
	printf("STAMPA DELLA LISTA ACQUISITA!\n");
	print_list(inizio);
	printf("RIMOZIONE FILE NON ADATTI DALLA LISTA!\n");
	remove_from_list(&inizio, 12);
	printf("RIMOZIONE COMPLETATA!\n");
	printf("STAMPA DELLA LISTA POST-RIMOZIONE!\n");
	print_list(inizio);
	int n = sizelist(inizio);
	float **m;
	m = allocMatrix(n,n);
	printf("COSTRUZIONE MATRICE!\n");
	m = build_matrix(inizio, m, n);
	printf("STAMPA MATRICE OTTENUTA!\n");
	printMatrix(m,n,n);
	printf("SALVATAGGIO NUOVA LISTA!\n");
	write_sortedon_list("outputfile.txt", inizio, m);
	printf("SALVATAGGIO COMPLETATO! PROGRAMMA TERMINATO\n");
	freelist(inizio);
	freeMatrix(m, n);
	inizio = NULL;

	return 0;
}