//una matrice di parole char parole[massimo numero di parole][lunghezza di ogni stringa] esempio: **char ,alloco dinamicante char per il MAXP per sizeof(*char) e poi MAXL per sizeof char

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LETTERS        36
#define MAX_WORDS          100

int readfile(const char *filename, char **list, int *words);
void printList(char **list, int words);

int main()
{
    char ** list;
    int parole;
    char filename[20];

    list =(char **)calloc(MAX_WORDS,sizeof(char *));
    for (size_t i = 0; i < MAX_WORDS ; i++)
    {
        list[i] =(char *) calloc(MAX_LETTERS,sizeof(char));
    }
    
    puts("Inserire Nome file");
    scanf("%s", filename);

    parole = readfile(filename, list, &parole);

    printList(list, parole);
    
}

int readfile(const char *filename, char **list, int *words)
{
    FILE *fp;
    int i = 0;

    fp = fopen(filename, "r");

    while(!feof(fp))
    {
        fscanf(fp, "%s", list[i]); // non metto la & commerciale con la stringa perche char *list è gia un indirizzo
        i++;
    }

    fclose(fp);

    return i;
}

void printList(char **list, int words)
{
    for (size_t i = 0; i < words; i++)
    {
        printf("%s\n", list[i]);
    }
    
}

