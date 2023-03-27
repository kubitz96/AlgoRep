//Esempio di creazione di un file di testo;

#include<stdio.h>

int main()
{
	FILE* fp;

	fp = fopen("nome_file", "w");

	fprintf(fp,"%s", "prova di scrittura");

	fclose(fp);

	return 0;
}