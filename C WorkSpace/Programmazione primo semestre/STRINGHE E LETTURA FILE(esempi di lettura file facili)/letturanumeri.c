#include<stdio.h>                   //voglio scrivere un programma che legge i numeri da un file, li trascrive in un vettore e mi crea un fle di output equivalente
#include<stdlib.h>

#define MAX_FILENAME 20
#define MAX_NUMBERS 100

#define READ_FILE_ERROR 10
#define ALLOC_MEMORY_ERROR 20

int *allocVect(int dimensione);
int readFile(const char *filename, int *numcase);  //se voglio leggere una stringa leggo all'interno di un vettore di tipo char
void makeOutFile(int *vectcase, int size);
void printVect(int *vect, int size);
void gestisciErrore(int code);

int main()
{
    char filename[MAX_FILENAME];     //una striga per il nome del file, le stringhe mi conviene allocarle staticamente con il valore massimo che voglio assegnare
    int *numcase;       //vettore in cui vengono raccolti i numeri letti
    int readnums;  //corrisponde all'indice massimo dei numeri letti depositati nel numCase

    numcase = allocVect(MAX_NUMBERS);

    puts("Inserire Nome File");
    scanf("%s", filename);

    readnums = readFile(filename, numcase);


    printVect(numcase, readnums);

    //adesso devo creare un file output equivalente

    makeOutFile(numcase, readnums);

    //i vettori statici non hanno bisogno di essere freedati perche fuori dalla funzione main vengono liberati
    free(numcase);
    return 0;
}

int *allocVect(int dimensione)
{
    int *vect;

    vect = calloc(dimensione,sizeof(int));

    if(vect == NULL) gestisciErrore(ALLOC_MEMORY_ERROR);
    
    return vect;
}

void printVect(int *vect, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%4d", vect[i]);
    }
}

void gestisciErrore(int code)
{
    switch (code)
    {
    case READ_FILE_ERROR:
        fprintf(stderr, "Errore in lettura!\n");
        break;

    case ALLOC_MEMORY_ERROR:
        fprintf(stderr, "Memoria non sufficiente per l'allocazione!\n");
        break;
    
    default: exit(-1);
        break;
    }
    exit(-1);
}

int readFile(const char *filename, int *numcase)
{
    FILE *fp;
    unsigned int i;         //questa lettura mi deve tornare l'indice massimo che corrisponde al totale dei numeri letti

    fp = fopen(filename, "r");      //apertura del file

    if(fp == NULL) gestisciErrore(READ_FILE_ERROR);

    for(i = 0; !feof(fp); i++)    //finche non mi trovo alla fine del file
    {
        fscanf(fp, "%d", &numcase[i]);   //leggi un valore intero e lo assegno all'elemento del vettore numcase[i]
    }

    fclose(fp);

    return i; 
}

void makeOutFile(int *vectcase, int size)
{
    FILE *fp;
    
    fp = fopen("numeriout.txt", "w");  //se apro un file non esistenete il file viene generato

    for (size_t i = 0; i < size; i++)
    {
        fprintf(fp, "%3d", vectcase[i]);  //se devo stampare faccio senza &, se devo leggere il valore un elemento del vettore uso &
    }
    fclose(fp);
}